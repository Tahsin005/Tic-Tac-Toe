#include<bits/stdc++.h>
using namespace std;

char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn ='x';
int r,c;
int draw=0;
void display(){
    cout<<"T I C  T A C  T O E"<<endl;
    cout<<"\tPlayer 1 [x]"<<'\n'<<"\tPlayer 2 [o]"<<endl;

    cout<<"\t\t   |   |   "<<endl;
    cout<<"\t\t "<<a[0][0]<<" | "<<a[0][1]<<" | "<<a[0][2]   <<endl;
    cout<<"\t\t___|___|___"<<endl;
    cout<<"\t\t   |   |   "<<endl;
    cout<<"\t\t "<<a[1][0]<<" | "<<a[1][1]<<" | "<<a[1][2]   <<endl;
    cout<<"\t\t___|___|___"<<endl;
    cout<<"\t\t   |   |   "<<endl;
    cout<<"\t\t "<<a[2][0]<<" | "<<a[2][1]<<" | "<<a[2][2]   <<endl;
    cout<<"\t\t   |   |   "<<endl;
}
void player_input(){
    char in;
    if(turn=='x'){
        cout<<"Player 1[x]'s turn"<<endl;
        cin>>in;
    }
    else if(turn=='o'){
        cout<<"Player 2[o]'s turn"<<endl;
        cin>>in;
    }

    switch(in){
        case '1': 
            r=0,c=0;
            break;
        case '2': 
            r=0,c=1;
            break;
        case '3': 
            r=0,c=2;
            break;
        case '4': 
            r=1,c=0;
            break;
        case '5': 
            r=1,c=1;
            break;
        case '6': 
            r=1,c=2;
            break;
        case '7': 
            r=2,c=0;
            break;
        case '8': 
            r=2,c=1;
            break;
        case '9': 
            r=2,c=2;
            break;
        default:
            cout<<"Invalid Choice"<<endl;
            break;
    }
    if(turn=='x' && a[r][c] != 'x' && a[r][c] != 'o'){
        a[r][c]='x';
        turn='o';
    }
    else if(turn=='o' && a[r][c] != 'x' && a[r][c] != 'o'){
        a[r][c]='o';
        turn='x';
    }
    else{
        cout<<"BOX IS FILLED- try AGAIN"<<endl;
        player_input();
    }
}
int puzzle_check(){
    // if row or column is filled or not
    for(int i=0;i<3;i++){
        if((a[0][i] == a[1][i] && a[0][i] == a[2][i]) || (a[i][0] == a[i][1] && a[i][0] == a[i][2])){
            return 0;
        }
    }
    // if primary diagonal / seconcdary diagonal filled or not
    if((a[0][0] == a[1][1] && a[0][0] == a[2][2]) || (a[0][2] == a[1][1] && a[0][2] == a[2][0])){
        return 0;
    }
    // if all box are filled or not
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j] != 'x' && a[i][j] != 'o'){
                return 1;
            }
        }
    }
    // any of the above is not true then it is a DRAW
    draw=1;
    return 0;
}
int main(){
    while(puzzle_check()){
        display();
        player_input();
    }
    if(turn == 'x' && draw==0){
        cout<<"Player 2[0] wins"<<endl;
    }
    else if(turn == 'o' && draw==0){
        cout<<"Player 1[x] wins"<<endl;
    }
    else{
        cout<<"Draw"<<endl;
    }
    return 0;
}