#include "CLLNode.h"
#include <iostream>
using namespace std;

int main()
{
    const int N = 8;
    const int K = 2;

    CLLNode* list = 0;
    // CLLNode* list = new CLLNode(N);
    for (int j = N; j > 0; j--)
    {
        CLLNode* newGuy = new CLLNode(j);
        list = list->insert(newGuy); 
    }
    list->print();

    while (!list->lengthIsOne())
    {
        for (int j = 0; j < K; j++)
        {
            list = list->next();
        }
        list = list->remove(); 
        list->print();
    }
    cout << "Only one person remains: ";
    list->print();

    return 0;
}
