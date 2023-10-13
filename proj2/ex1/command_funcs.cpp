#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
/**
 * this function check the validity of input commands. 
 */
// Function Prototypes

void InterpretCommands(istream&);

void InterpretUpdate(istream&);

void InterpretList(istream&);

void InterpretBatch(istream&);

void InterpretQuit(istream&);

void InterpretCommands(istream& cmds)
{
    string line, lineInWord;
    // TODO: Declare other variables here.

    while (getline(cmds, line)) // TODO: Get a line. // DONE 
    {
        istringstream lineIn(line);

        if (!(lineIn>>lineInWord)) // TODO: Get the line's first word. // DONE
        {
            cerr<<"no input is provided"<<endl; // TODO: Do something if there weren't any words. // DONE
        }
        else if (lineInWord == "update")
        {
            InterpretUpdate(lineIn);
        }
        else if (lineInWord == "list")
        {
            InterpretList(lineIn);
        }
        else if (lineInWord == "batch")
        {
            InterpretBatch(lineIn);
        }
        else if (lineInWord == "quit")
        {
            InterpretQuit(lineIn);
        }
        else
        {
            cerr << "Unrecognizable command word." << endl;
        }
    }
}

// For one of the commands update or list, merely echo the command and its arguments. 
void InterpretUpdate(istream& is){
    string word, temp; 
    int number; 
    if (is>>word>>number){
        if (!(is>>temp)) cout<<"update "<<word<<" "<<number<<endl; 
        else cerr<<"too many arguments"<<endl; 
    }
    else cerr<<"invalid arguments"<<endl; 
}
void InterpretList(istream& is){
    string word, temp;
    if (is>>word){
        if (!(is>>temp)) cout<<"list "<<word<<endl; 
        else cerr<<"too many arguments"<<endl; 
    }
    else cerr<<"invalid arguments"<<endl; 
}

// For the batch command, do the following: read, recognize, and process commands from the specified file, 
// then (assuming that a quit command has not been read) resume reading commands from cin.
void InterpretBatch(istream& is){
    string filename, temp; 
    if (is>>filename) {
        if (!(is>>temp)) {
            ifstream fin(filename); 
            InterpretCommands(fin); 
        }
        else cerr<<"too many arguments"<<endl; 
    }
    else cerr<<"invalid arguments"<<endl;

}

// For the quit command, terminate the program using the one-argument exit function declared in <cstdlib>.
void InterpretQuit(istream& is){
    string temp; 
    if (!(is>>temp)) exit(0); 
    else cerr<<"too many arguments"<<endl; 
}
