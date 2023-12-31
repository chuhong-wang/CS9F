#include <iostream>
#include "amoebas.h"

using namespace std;

int main()
{
    Amoeba* me = new Amoeba(string("me"));
    Amoeba* parent = new Amoeba(string("mom/dad"));
    Amoeba* grandparent = new Amoeba(string("Amos McCoy"));
    Amoeba* brother = new Amoeba(string("Fred"));
    Amoeba* sister = new Amoeba(string("Wilma"));
    Amoeba* child1 = new Amoeba(string("Mike"));
    Amoeba* child2 = new Amoeba(string("Homer"));
    Amoeba* child3 = new Amoeba(string("Marge"));
    Amoeba* grandchild11 = new Amoeba(string("Bart"));
    Amoeba* grandchild12 = new Amoeba(string("Lisa"));
    Amoeba* grandchild31 = new Amoeba(string("Bill"));
    Amoeba* grandchild32 = new Amoeba(string("Hilary"));

    // This will seem a bit backward, since we have an "add child"
    // instead of an "add parent".

    // First do Mike's kids.
    child1->AddChild(grandchild11);
    child1->AddChild(grandchild12);

    // Next do Marge's kids.
    child3->AddChild(grandchild31);
    child3->AddChild(grandchild32);

    // Now add Mike, Homer, and Marge to me.
    me->AddChild(child1);
    me->AddChild(child2);
    me->AddChild(child3);

    // Now add me to my parent.
    parent->AddChild(me);

    // Now add my brother and sister.
    parent->AddChild(brother);
    parent->AddChild(sister);

    grandparent->AddChild(parent); 

    // Print my name and my parent's name.
    cout << "Hi, my name is " << me->Name() << endl;
    cout << "Meet my parent " << me->Parent()->Name() << endl;
    cout << "Meet my grandparent " << me->Parent()->Parent()->Name() << endl;

    cout<<"print children of `parent`:" <<endl; 
    PrintChildren(parent); 
    PrintGrandchildren(parent); 

    cout<<"print descendants of `grandparent`:" <<endl; 
    grandparent->PrintDescendants(""); 


}
