#include<iostream>
using namespace std;
int main()
{
    float a,b,c;
    //a is first number and b is second number
    //c is the output
    char op;
    //op is the operator
    cout<<"Enter the first no.: ";cin>>a;
    cout<<"Enter the operator(+,-,*,/,%,^): ";cin>>op;
    cout<<"Enter the second no.: ";cin>>b;
    switch(op){
        case '+': c=a+b;
                  break;
        case '-': c=a-b;
                  break;
        case '*': c=a*b;
                  break;
        case '/': c=a/b;
                  break;
    }
    cout<<"The output is: "<<c;
    return 0;
}