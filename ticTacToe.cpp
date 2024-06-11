#include<iostream>
using namespace std;

class TicTacToe{
    char matrix[3][3];
    int x,y;
    public:
    //initializing the matrix
    TicTacToe(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                matrix[i][j]=' ';
            }
        }
    }

    //displaying the matrix
    void showMatrix(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<" "<<matrix[i][j]<<" ";

                if(j!=2)
                  cout<<"|";
            }
            cout<<endl;
            if(i!=2){
                cout<<"---|---|---"<<endl;
            }
        }
    }

    //Getting the player turn
    void getPlayerMove(){
        int move;
        cout<<"Enter your position from 1 to 9 (row-wise counting)"<<endl;
        cin>>move;

        switch(move){
        case 1:
        case 2:
        case 3:
            x=0,y=move-3*0-1;
            break;
        case 4:
        case 5:
        case 6:
            x=1,y=move-3*1-1;
            break;
        case 7:
        case 8:
        case 9:
            x=2,y=move-3*2-1;
            break;
        case 0:
            exit(0);
        default:  //invalid case
            x=-1;
        }
        //checking for valid move or not
        if(x==-1 || matrix[x][y]!=' '){
            cout<<"Invalid move, try again."<<endl;
            getPlayerMove();
        }
        else{
            matrix[x][y]='X';
        }
    }

    //checking for winner
    char check(){
        //checking for rows
        for(int i=0;i<3;++i){
            if(matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2])
               return matrix[i][0];
        }
        //checking for columns
        for(int i=0;i<3;++i){
            if(matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i])
               return matrix[0][i];
        }
        //checking for diagonals
        if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
            return matrix[0][0];

        if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
            return matrix[0][2];
        //no winner
        return ' ';
    }
    //getting computer turn
    void getComputerMove(){
        int i,j;
        //wherever empty position is found
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(matrix[i][j]==' '){
                    matrix[i][j]='O';
                    return;
                }
            }
        }
        //when all positions are filled
        if(i*j==9){
            cout<<"Match drawn!!!"<<endl;
            exit(0);
        }
    }
};

class GameDriver{
    public:
    void forOnePlayer(){
        TicTacToe startGame;
        char done;
        do{
            startGame.showMatrix();
            startGame.getPlayerMove();
            done=startGame.check();

            if(done!=' ')   //winner found
               break;

            startGame.getComputerMove();
            done=startGame.check();

            if(done!=' ')  //winner found
                break;     
        }while(true);

        //checking for who is winner
        if(done=='X'){
            cout<<"You are winner!!!"<<endl;
        }
        else{
            cout<<"I am winner!!!"<<endl;
        }
        startGame.showMatrix();
        cout<<"Thank you!!"<<endl;
    }
    //for two players
    void forTwoPlayer(){
        ;
    }
};
int main(){
    char choice;
    do{
        cout<<"Press number for given option:"<<endl;
        cout<<"  1.For one player"<<endl;
        cout<<"  2.For two player"<<endl;
        cout<<"  0.exit(anytime of the game)"<<endl;
        cin >>choice;

        switch (choice)
        {
        case '0':
            exit(0);
        //for one player
        case '1': 
            GameDriver obj;
            obj.forOnePlayer();
            exit(0);
        case '2':
            cout<<"IN WORK...."<<endl;
            break;
        default:
            cout<<"Invalid choice, try again."<<endl;
        }
    }while(true);
    return 0;
}