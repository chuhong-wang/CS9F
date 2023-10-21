#include "amoebas.h"
#include <iostream>

using namespace std;

// An amoeba is born, named s
Amoeba::Amoeba(string s)
{
    myName = s;
    myParent = 0;
    myOlderSibling = 0;
    myOldestChild = 0;
    myYoungestChild = 0;
}

// Access functions
string Amoeba::Name()
{
    return myName;
}

Amoeba* Amoeba::Parent()
{
    return myParent;
}

void Amoeba::AddChild(Amoeba* newChild)
{
    // make child point to parent
    newChild->myParent = this;

    // check for parent having other children
    Amoeba* otherSibling = myYoungestChild;
    if (!otherSibling)
    {
        // the new amoeba is an only child
        myYoungestChild = newChild;   // make the parent's child
        myOldestChild = newChild;     // ptrs point to the new one
        newChild->myOlderSibling = 0; // no older sibling
    }
    else
    {
        // there are other kids; make this one the youngest
        myYoungestChild = newChild;              // no younger siblings,
        newChild->myOlderSibling = otherSibling; // but new kid now
    }                                            // has older siblings.
}

void PrintChildren(Amoeba* curr)
{
    if (curr->myYoungestChild!=0){
        Amoeba* youngest = curr->myYoungestChild; 
        while (youngest->myOlderSibling!=0){
            cout<<youngest->Name()<<" "; 
            youngest = youngest->myOlderSibling; 
        }
        cout<<youngest->Name()<<endl; 
    }
}
void PrintGrandchildren(Amoeba* curr)
{
    if (curr->myYoungestChild!=0){
        cout<<"grandchildren are:"<<endl;
        Amoeba* youngest = curr->myYoungestChild; 
        // cout<<youngest->Name(); 
        while (youngest->myOlderSibling!=0){
            PrintChildren(youngest); 
            youngest = youngest->myOlderSibling; 
        }
        PrintChildren(youngest);
    }

}


void Amoeba::PrintDescendants(string tabs){
    if (myYoungestChild!=0){
        Amoeba* youngest = myYoungestChild;
        while (youngest->myOlderSibling!=0){
            cout<<tabs<<youngest->Name()<<endl; 
            youngest->PrintDescendants(tabs+"\t"); 
            youngest = youngest->myOlderSibling;
        }
        cout<<tabs<<youngest->Name()<<endl; 
        youngest->PrintDescendants(tabs+"\t"); 
        youngest = youngest->myOlderSibling;
    }
}