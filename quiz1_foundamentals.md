## 1. 
> Explain what function overloading is, and how it's useful.

Answer: Function overloading is that we can define multiple functions with the same name but different argument types. 
It's useful as being more flexible. 

## 2. 
> Write an input statement that reads values from cin into variables cmd and arg, and a single output statement that prints those values, labeled appropriately, on two separate lines.

Answer: 
```
cin>>cmd>>arg; 
cout<<"cmd = "<<cmd<<endl; 
cout<<"arg = "<<arg<<endl; 
```

## 3. 
> Rewrite the following code segment as a switch statement.

```
if (n == 1) {
    total = total + 2;
} else if (n == 2) {
    total = total + 27;
} else if (n == 3) {
    total = total + 314;
} else {
    total = total - 6;
}
```
Answer: 
```
switch(n){
    case 1:
        total += 2; 
    case 2:
        total += 27;
    case 3:
        total += 314;
    default:
        total -= 6;
}
```
## 4. 
> What value does n contain after the following code is executed?

```
n = 0;
for (int k = 1; k < 5; k = k + 2) {
    n++;
}
```
Answer: `n=2`
## 5. Fill in the blank in the definition of the function InRange given below. InRange should return true if its integer argument is between 4 and 27, inclusive.
```
bool InRange(int n) {
    return _________________________________ ;
}
```
Answer: 
## 6. Complete the heading for function F so that, on return from the call to F in main, the variable n1 contains the value 3 and the variable n2 contains the value 7.
```
void F( _________________________________ ) {
    k1++;
    k2 = k2 + 2;
}

int main() {
    int n1 = 3, n2 = 5;
    F(n2, n1);
}
```

## 7. List the contents of the `fractions.h` file for a Fraction class whose member functions include a constructor, Numerator and Denominator access function, and a Sum function that returns the result of adding the value stored in the Fraction object to the argument value. Assume that the private data for a fraction consists of two integers called myNumer and myDenom.

## 8. Define the Sum function that would appear in the fractions.cpp file for the Fraction class described in question 7.


