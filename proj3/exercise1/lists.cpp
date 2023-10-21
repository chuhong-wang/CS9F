#include "lists.h"
#include <iostream>
#include <cassert>
using namespace std;

/**
 * Delete the node and all nodes accessible through it.
 * Precondition: this != 0.
 */
ListNode::~ListNode()
{
    // this version is buggy
    cout << "Deleting node with value " << myValue << endl;
    // for (ListNode* p = this; p; p = p->rest())
    // {
    //     delete p;
    // }
    
    ListNode* p = this;
    // while(p->rest()){
    //     auto q=p; 
    //     p = p->rest();
    //     q->myNext = 0;
    //     delete q;
    // }

    if (myNext!=0) delete myNext;
}

/**
 * Print the list.
 */
void ListNode::print() const
{
    for (const ListNode* list = this; list; list = list->rest())
    {
        cout << list->first() << " ";
    }
    cout << endl;
}
