#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "inventory.h"

// non-member functions of Inventory class 
bool compareName (donated_item &d1, donated_item &d2)  { return d1.itemName < d2.itemName; }

// definition of member functions of Inventory class 

void Inventory::Update(const string &item, const int &amount) {
    bool found = false; 
    for (auto &v:items) {
        if (v.itemName == item){
            v.amount += amount; 
            found = true; 
        }
    }
    if (!found) {items.push_back(donated_item(item, amount)); }
};

void Inventory::ListByName() {
    if (!items.empty()){
        // sort(items.cbegin(), items.cend(), [](donated_item &d1, donated_item &d2)->bool {return d1.itemName<d2.itemName;}); 
        sort(items.begin(), items.end(),compareName); 
        for (const auto &v:items) { cout <<v.itemName <<": " << v.amount <<endl; }
    }
    else {cerr<<"empty inventory"<<endl; }
}

void Inventory::ListByQuantity(){
    if (!items.empty()){
        sort(items.begin(), items.end(), []( donated_item &d1,  donated_item &d2)->bool {return d1.amount<d2.amount;}); 
        for (const auto &v:items) { cout <<v.itemName <<": " << v.amount <<endl;  }
    }
    else {cerr<<"empty inventory"<<endl; }
}

