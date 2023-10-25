#include <string>
#include <filesystem>
#include <fstream>
#include <iomanip>

const std::string getPath()
{
#ifdef _WIN32
    std::string appDataPath = std::getenv("%%APPDATA%");
    std::string targetDir = appDataPath + "\\CLI_Timer_Sessions\\";
    std::filesystem::create_directory(targetDir);

#elif __APPLE__
    std::string appDataPath = std::getenv("HOME");
    std::string targetDir = appDataPath + "/Library/Application Support/CLI_Timer_Sessions/";
    std::filesystem::create_directory(targetDir);

#elif __linux__
    std::string appDataPath = std::getenv("HOME");
    std::string targetDir = appDataPath + "/.config/CLI_Timer_Sessions/";
    std::filesystem::create_directory(targetDir);

#else
    return "./CLI_Timer_Sessions/";

#endif
    return targetDir;
}

std::string changeExtensionAndAddPath(std::string fileName)
{
    std::string finalFileName;
    for (int i = 2; i < fileName.length(); i++)
    { // Starts at index 2 because of -s.
        if (fileName[i] == '.')
        {
            break;
        }
        else
        {
            finalFileName += fileName[i];
        }
    }
    return getPath() + finalFileName + ".CLI_T_S"; // CLI_T_S means CLI Timer Session.
}

void save_to_file(std::string sessionName, std::string& scramble, float time, std::string& penalty, std::string& comment) {
    std::ofstream fileToSaveTo(sessionName);

    if (penalty == "DNF" || penalty == "dnf"){
        fileToSaveTo<<scramble<<"§DNF("<<std::fixed<<std::setprecision(2)<<time<<")§"<<comment<<std::endl;
    }
    else if (penalty == "+2")
    {
        fileToSaveTo<<scramble<<"§"<<std::fixed<<std::setprecision(2)<<(time+2)<<"+§"<<comment<<std::endl;
    }
    else
    {
        fileToSaveTo<<scramble<<"§"<<std::fixed<<std::setprecision(2)<<time<<"§"<<comment<<std::endl;
    }

    fileToSaveTo.close();

}