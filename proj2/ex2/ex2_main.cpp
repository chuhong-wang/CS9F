#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> 

#include "inventory.h"

using namespace std;

// Function Prototypes

void InterpretCommands(istream&, Inventory&);
void InterpretUpdate(istream&, Inventory&);
void InterpretList(istream&, Inventory&);
void InterpretBatch(istream&, Inventory&);
void InterpretQuit(istream&);

/**
 * Driver Function
 */
int main()
{
    Inventory inventory;
    // InterpretUpdate(cin, inventory); 
    InterpretCommands(cin, inventory);

    // // test functions and class
    // inventory.Update("orange", 5); 
    // inventory.Update("banana", 2); 
    // inventory.Update("apple", 6); 
    // inventory.ListByName(); 
    // inventory.ListByQuantity(); 

    return 0;
}
