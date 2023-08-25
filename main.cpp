#include <iostream>
#include <iomanip> //Used for one line smh my head
#include "Scrambles.hpp"
#include "fileIO.hpp"

using namespace std;

float inputtedTime;

bool shouldSave(int argc, const char *argv[]){
	if (argc != 3){
		return false;
	}else{
		return (argv[2][0] == '-' && argv[2][1] == 's');
	}
}

bool shouldContinue(int argc, const char *argv[]){
	if (argc != 3){
		return false;
	}else{
		return (argv[2][0] == 'c' || shouldSave(argc, argv)); 
	}
}

bool shouldPrompt(int argc, const char *argv[]){
	if (argc != 3){
		return false;
	}else{
		return !(argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 'n' && argv[2][3] == 'o' && argv[2][4] == '_' && argv[2][5] == 'p' && argv[2][6] == 'r' && argv[2][7] == 'o'&& argv[2][8] == 'm' && argv[2][9] == 'p' && argv[2][10] == 't'); 
	}
}

int main(int argc, char const *argv[])
{

	if (argc == 1)
	{
		cerr<<"You fogor commands lul.";
		return 1;
	}

	const bool prompt = shouldPrompt(argc, argv);
    const bool save = shouldSave(argc, argv);
    const bool cont = shouldContinue(argc, argv);

	srand(static_cast<unsigned>(time(NULL)));

	do
	{
		string currentScramble;
		// Get scramble
		switch (*argv[1])
		{
		case '2':
			currentScramble = Two_By_Two();
			break;

		case '3':
			currentScramble = Three_By_Three();
			break;

		case '4':
			currentScramble = Four_By_Four();
			break;

		case '5':
			currentScramble = Five_By_Five();
			break;
	
		case '6':
			currentScramble = Six_By_Six();
			break;

		case '7':
			currentScramble = Seven_By_Seven();
			break;

		case 'S':
			currentScramble = Skewb();
			break;

		case 'P':
			currentScramble = Pyraminx();
			break;

		case 'M':
			currentScramble = Megaminx();
			break;

		case 'K':
			currentScramble = Clock();
			break;
		
		default:
			cerr<<"Command: \""<<*argv[1]<<"\" Not understood.";
			exit(EXIT_FAILURE);
		}
		cout<<currentScramble;

		if(prompt){
			// Prompting
			char correct = 'n';
			string penalty = "n";
			string comment;

			do{
			cout<<"\nEnter your time: ";
			cin>>inputtedTime;
			cout<<"\nYou entered in "<<fixed<<setprecision(2)/*The line I imported a whole thing for smh my head.*/<<inputtedTime<<"\nIs this correct? (Y/N)\n";
			cin>>correct;
			} while(correct != 'Y' && correct != 'y');

			do
			{
				cout<<"Enter an penalty (OK/+2/DNF)\n";
				cin>>penalty;
			} while (penalty != "OK" && penalty != "ok" && penalty != "+2" && penalty != "DNF" && penalty != "dnf" );

			// cout<<"Enter in a comment (or don't you can leave blank)\n";
			// cin>>comment;
			if (save){
				cout<<"Enter in a comment\n";
				cin.ignore();
				getline(cin, comment); // PLS HELP

				save_to_file(argv[2], currentScramble, inputtedTime, penalty, comment);
				}
		} 
	}while(cont);

	return 0;
}