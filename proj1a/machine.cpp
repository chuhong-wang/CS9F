// TODO: Your code here
#include <iostream>
using std::cin, std::cout, std::endl; 

int main(){
    int tot=0, subTot=0, prev, curr;
    if (cin>>prev){
        subTot += prev; 
        tot += prev; 
        while (cin>>curr){
            if (prev==0) {
                cout<<subTot<<endl; 
                subTot = 0;
                prev = curr; 
            }
            subTot += curr; 
            tot += curr; 
            prev = curr; 
        }
        cout<<tot<<endl; 
    }
    return 0; 
}