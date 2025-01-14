# CLI_Timer ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) <br>![Download Count](https://img.shields.io/github/downloads/1Codealot/CLI_Timer/total)

This is a Rubik's cube training timer (some what similar to cstimer) used in the command line. 

# Building
Download / clone this repo then do `cd CLI_Timer` then run `./build.py` and specify things (Docs for build.py are in it's file.)

# Commands

### Implemented
##### NxN cube types
`2`
`3`
`4`
`5`
`6`
`7`

##### Side event cube types

`S` <br>
skewb <br>
`M` <br>
megaminx <br>
`P` <br>
pyraminx <br>
`C` <br>
clock.
<br>

<hr>

`c`
continuous means that after entering a time (which currently does nothing) it'll produce a new scramble of the same type. (If `c` is not inputted it'll only do one scramble and exit after a time is inputted)

<hr>

`-s{sessionName}`
This will either:
* create a new session if "session_name" does not exist.
* open a session if "session_name" does exist
It will always be continuous so `c` isn't needed
<br>
On windows, the session files will save to %appdata%\CLI_Timer_Sessions.<br>
On Linux it saves to /home/your_username/.config/CLI_Timer_Sessions<br>
On MacOs it saves to /Users/your_username/Library/Application Support/CLI_Timer_Sessions<br>


<hr>

`--no_prompt`
This will not prompt you to enter in your time.
If you do `CLI_Timer 2 -sSession --no_prompt` it will say "You can't save without prompting therefore it will prompt". I'm sure you can figure out why from the message.

<hr>

`--count{number}`
This will generate {number} amount of scrambles and then quit.<br>
Example: `CLI_Timer 7 --count5 -s7x7_average`
<br>
###### Note: `c` argument is impiled.
<hr>

### Other commands 

`help`
This outputs a help message.

`--version` 
Outputs the current version.
<hr>

### Example commands
`CLI_Timer.exe 3` This will generate a single scramble for a 3x3 <br>
`CLI_Timer.exe 5 c` This will continually generate scrambles for a 5x5. This will NOT save to a file. <br>
`CLI_Timer.exe M -sMegaminx_Session` This will continually generate scrambles for megaminx. This will save to a file called Megaminx_Session.CLI_T_S.

###### NOTE: as of now, the commands no longer need to be in any order (i hope)

# Entering in times
You can enter in times in the format of HH:MM:SS.DD or the regex `(((\d)?\d(:)?)?(\d\d(:)?))?((\d){1,2}(\.)?)?(\d){1,2}`
###### NOTE: May be wrong as I'm not great at regex.

<br>

# To be implemented

`Q` <br>
square one (Don't tell anyone i might be working on it 🤫) 