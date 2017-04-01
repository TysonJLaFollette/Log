//Simple terminal notes recorder. Made by Tyson LaFollette.

#define _CRT_SECURE_NO_DEPRECATE
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

/*Catches next single paragraph user input. Inserts timestamp at beginning, then outputs to log.txt.*/
int main(int argc, char *argv[])
{
	string entry;
	string argument;
	if (argc > 1){
		argument = argv[1];
		if (argument == "/?" || argument == "-?" || argument == "/h" || argument == "--h" || argument == "--help"){
			cout << "Writes a single paragraph to a log file, timestamped with the current date and time." << endl << endl;
			cout << "Log [/A] [/?]" << endl << endl;
			cout << "/A\tAppends entry to log.txt without timestamp." << endl << endl;
			cout << "/?\tShows this help document." << endl << endl;
			cout << "More cool and minimalist stuff at www.tysonlafollette.com\n";
		}
		//If /a is used as argument, appends entry to previous, without a timestamp.
		else if (argument == "/a"){
			cout << "Log entry: ";
			getline(cin, entry);
			fstream fout;
			fout.open("log.txt", fstream::out | fstream::app);
			fout << entry << "\n\n";
			fout.close();
			cout << "Entry logged. See log.txt";
		}
	}
	else
	{
		cout << "Log entry: ";
		getline(cin, entry);
		entry = timestamp() + entry;
		fstream fout;
		fout.open("log.txt", fstream::out | fstream::app);
		fout << entry << "\n\n";
		fout.close();
		cout << "Entry logged. See log.txt";
	}
	return 0;
}
