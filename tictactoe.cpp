#include<iostream>
using namespace std;
char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void printboard(){
    int i,j,k=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<" "<<board[i][j];
            if(j<2){
                cout<<" |";
            }
        }
        if(i<2){
        cout<<"\n"<<"---+---+---\n";
        k++;
        }
    }
    cout<<endl;
}

bool checkwin(char player){
    int i;
    for(i=0;i<3;i++){
        if((board[i][0]==player && board[i][1]==player && board[i][2]==player) || (board[0][i]==player && board[1][i]==player && board[2][i]==player)){
            return true;
        }
    }
    return ((board[0][0]==player && board[1][1]==player && board[2][2]==player) || (board[0][2]==player && board[1][1]==player && board[2][0]==player));    
}

bool isboardfull(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

void resetboard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]==' ';
        }
    }
}

int main()
{
    char player = 'X';
    int move;
    int again;
    do{
        resetboard();
        player='X';
        while(!isboardfull()){
            printboard();
            cout<<"Player "<<player<<" enter your move(1-9): ";cin>>move;
            int row = (move-1)/3;
            int col = (move-1)%3;
            if(move<1 || move>9 || board[row][col] != ' '){
                cout<<"Invalid move. Enter a valid move.\n";
                continue;
            }
            board[row][col]=player;
            if(checkwin(player)){
                printboard();
                cout<<"Player "<<player<<" wins!!\n";
                break;
            }
            if(isboardfull()){
                printboard();
                cout<<"Its a draw!!";
                break;

            }
            player =(player == 'X')? 'O' : 'X';
        }
        cout<<"Do you want to play again? (y/n): ";
        cin>>again;
    }while(again=='y' || again=='Y');
    return 0;
}