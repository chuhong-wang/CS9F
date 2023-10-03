// TODO: Your code here
#include <iostream>
#include "positions.h"
#include <math.h>
using std::cerr, std::endl, std::cout, std::cin; 

// Reinitialize this position.
void Position::SetAbsolutePosition(float r, float thetaInRadians){
    myRadius = r; 
    myAngleInRadians = thetaInRadians; 
}

// Change this position, incrementing the radius by rChange and
// incrementing the angle by angularDistChange/myRadius.
// angularDistChange is expressed in meters.
// One of the two arguments must be 0.
// Negative radius values represent movement toward the statue.
// Positive distance changes represent counterclockwise motion;
// negative values are clockwise.
void Position::IncrementPosition(float rChange, float angularDistChange){
    if (rChange&&angularDistChange) cerr<<"illegal input"<<endl; 
    if (angularDistChange==0) {
        myRadius += rChange; 
        if (myRadius<1) myRadius =1;
    }
    if (rChange==0) myAngleInRadians += angularDistChange/myRadius; 
}

// Print this position.
void Position::Print() const{
    cout<<"current r= "<<myRadius<<" current angle= "<<myAngleInRadians<<endl; 
}

// Return true if someone at this position can see someone or
// something at the argument position (i.e. the statue does
// not block one's view), and return false otherwise.
// The argument position must be at the statue.

// The cat sees the mouse if
// (cat radius) * cos (cat angle - mouse angle) >= 1.0 (angles in radian)
bool Position::Sees(Position pos) const{
    decltype(myRadius) d = myRadius*cos(myAngleInRadians - pos.myAngleInRadians); 
    if (d>=1) return true; 
    else return false; 
}

// Return true if this position is at the base of the statue,
// i.e. its radius is 1, and return false otherwise.
bool Position::IsAtStatue() const{
    if (myRadius==1) return true; 
    else return false; 
}

// Return true if this position is between the first argument
// position and the second.  Precondition: the counterclockwise
// difference between the first and second argument positions
// is less than pi radians, and the radii of all the positions
// are the same.

// An angle B is between angles A and C in the following circumstances:
// `cos (B - A) > cos (C - A)`, and `cos (C - B) > cos (C - A)`

// B - this.angle
// A - pos1.angle
// C - pos2.angle 
bool Position::IsBetween(Position pos1, Position pos2) const{
    bool con1 = (cos(myAngleInRadians - pos1.myAngleInRadians) > cos(pos2.myAngleInRadians - pos1.myAngleInRadians)); 
    bool con2 = (cos(pos2.myAngleInRadians - myAngleInRadians) > cos(pos2.myAngleInRadians - pos1.myAngleInRadians)); 
    // cout << con1 << " " <<con2 << endl; 
    if (con1&&con2) return true; 
    else return false; 
}
