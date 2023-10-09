#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Function Prototypes

void InterpretCommands(istream&);

void InterpretUpdate(istream&);

void InterpretList(istream&);

void InterpretBatch(istream&);

void InterpretQuit(istream&);
/**
 * Driver Function
 */
int main()
{
    InterpretCommands(cin);
    return 0;
}
