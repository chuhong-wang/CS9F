#ifndef INVENTORY_H
#define INVENTORY_H


#include <vector>
#include <string>

#include <algorithm>
#include <iostream>

using namespace std;

struct donated_item
{
    // constructors 
    donated_item() = default; 
    donated_item(string s, int n):itemName(s), amount(n) {}

    // data members 
    string itemName;
    int amount; 
};

class Inventory
{
public:
    Inventory() = default;

    void Update(const string &item, const int &amount);

    void ListByName() ;

    void ListByQuantity();

private:
    // data member 
    vector<donated_item> items; 
};


#endif