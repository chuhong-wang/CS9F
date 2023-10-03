#include "positions.h"
#include <iostream>
#include <cmath>
using namespace std;
using std::cin, std::cout, std::endl; 

/**
 * You define the GetPositions function.
 * It should read legal cat and mouse positions from the user
 * and return the position values in its two arguments.
 */
void GetPositions(Position &cat, Position &mouse)
{
    // TODO: Your code here
    float r1, angle1;
    cout <<"enter cat position by its radius and angle" << endl;  
    cin>>r1>>angle1; 
    cat.SetAbsolutePosition(r1, angle1/180.0*M_PI); 

    float angle2;
    cout <<"enter mouse position by its angle" << endl;  
    cin>>angle2; 
    mouse.SetAbsolutePosition(1, angle2/180.0*M_PI); 

    
}

/**
 * You define the RunChase function.
 * Given initialized cat and mouse positions,
 * it should simulate the cat chasing the mouse, printing the
 * result of each movement of cat and mouse.  Either the cat will
 * catch the mouse, or 30 time units will go by and the cat will
 * give up.
 */
void RunChase(Position &cat, Position &mouse)
{
    // TODO: Your code here
    int count = 0, limit = 30;
    bool caught = false;
    while(count!=limit){
        // cout <<"cat:"; 
        // cat.Print();
        // cout <<"mouse:"; 
        // mouse.Print(); 
        
        // senario 1. cat hasn't reached the base of the statue 
        if (!cat.IsAtStatue()){
            if(cat.Sees(mouse)) {cat.IncrementPosition(-1, 0); }
            else {cat.IncrementPosition(0, 1.25);}
            mouse.IncrementPosition(0, 1); 
        }
        //senario 2. cat reached the base of the statue 
        else {
            Position cat_before = cat; 
            // Position mouse_before = mouse; 
            cat.IncrementPosition(0, 1.25);
            // if (mouse.IsBetween(cat_before, cat) && mouse_before.IsBetween(cat_before, cat)) {
            if (mouse.IsBetween(cat_before, cat)) {
                cout << "caught at time "<< count << endl; 
                caught = true; 
                break; 
            }
            mouse.IncrementPosition(0, 1); 
        }
        ++count; 
    }
    if (!caught) cout << "cat tired"<< endl; 
}

int main()
{
    Position cat, mouse;
    GetPositions(cat, mouse);
    RunChase(cat, mouse);

    return 0;
}
