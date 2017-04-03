//Simple terminal notes recorder. Made by Tyson LaFollette.

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

/*This is a change to test git functionality*/
/*This function returns the date and time followed by a newline character.*/
string timestamp()
{
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	string dt = ctime(&now);

	return dt;
}

void getAndWrite(bool should_append){
	string entry;
	cout << "Log entry: ";
		getline(cin, entry);
		if (!should_append) {entry = timestamp() + entry;}
		fstream fout;
		fout.open("log.txt", fstream::out | fstream::app);
		fout << entry << "\n\n";
		fout.close();
		cout << "Entry logged. See log.txt";
}

/*Catches next single paragraph user input. Inserts timestamp at beginning, then outputs to log.txt.*/
int main(int argc, char *argv[])
{
	string argument;
	if (argc == 1) {//no command line parameters given.
		 getAndWrite(false);
	} else if (argc == 2){//possibly has a parameter.
		argument = argv[1];
		//check for help parameter
		if (argument == "/?" || argument == "-?" || argument == "--?" || argument == "/h" || argument == "-h"
            || argument == "--h" || argument == "/help" || argument == "-help" || argument == "--help"){
			cout << "Writes a single paragraph to a log file, timestamped with the current date and time." << endl << endl;
			cout << "Log [/A] [/?]" << endl << endl;
			cout << "/a\tAppends entry to log.txt without timestamp." << endl << endl;
			cout << "/?\tShows this help document." << endl << endl;
			return 0;
		}
		//If /a is used as argument, appends entry to previous, without a timestamp.
		else if (argument == "/a"){
			getAndWrite(true);
		}
	} else {
		cout << "Error: Too many parameters. Type --help for help.";
		return 1;
	}
	return 0;
}
