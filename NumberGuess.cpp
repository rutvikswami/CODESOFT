#include<iostream>
using namespace std;
int main()
{
    cout<<"Number Guessing Game"<<endl;
    int range,value,guess,count=0;
    cout<<"Enter the range: ";
    cin>>range;
    value = rand()%range;
    for(;;)
    {
        count++;
        cout<<"Guess "<<count<<": ";
        cin>>guess;
        if(guess==value){
            cout<<"You guessed correctly, Congrats!!\n";
            cout<<"Number of tries: "<<count;
            break;
        }
        else if(guess>value){
            cout<<"You guessed too high try again"<<endl;

        }
        else{
            cout<<"you guessed too low try again"<<endl;
        }
    }
    return 0;
}