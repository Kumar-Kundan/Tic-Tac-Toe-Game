#include<iostream>
using namespace std;

class TicTacToe{
    char matrix[3][3];
    int x,y;
    public:
    //initializing the matrix with space
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
    void getPlayerMove(string player,char ch){
        int move;
        cout<<player<<" to move: "<<endl;
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
            getPlayerMove(player,ch);
        }
        else{
            matrix[x][y]=ch;
        }
    }

    //checking for winner
    char check(){
        //checking for rows
        static int count=0;
        count++;
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
        if(count>=9){
            showMatrix();
            cout<<"Match drawn!!!"<<endl;
            exit(0);
        }
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
    }
};

class GameDriver{
    public:
    void forOnePlayer(){
        TicTacToe startGame;
        char done;
        do{
            startGame.showMatrix();
            //user move
            startGame.getPlayerMove("Your",'X');
            done=startGame.check();

            if(done!=' ')   //winner found
               break;

            //computer move
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
    void forTwoPlayer(string player1="Player 1", string player2="Player 2"){
        TicTacToe startGame;
        char done;
        do{
            startGame.showMatrix();
            //player 2 move
            startGame.getPlayerMove(player1,'X');
            done=startGame.check();

            if(done!=' ')   //winner found
               break;

            startGame.showMatrix();
            //player 2 move
            startGame.getPlayerMove(player2,'O');
            done=startGame.check();

            if(done!=' ')  //winner found
                break;     
        }while(true);

        //checking for who is winner
        if(done=='X'){
            cout<<player1<<" is winner!!!"<<endl;
        }
        else{
            cout<<player2<<" is winner!!!"<<endl;
        }
        startGame.showMatrix();
        cout<<"Thank you!!"<<endl;
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
            char choice;
            cout<<"do you want to enter your name(y|Y)"<<endl;
            cin>>choice;

            GameDriver obj1;
            //user has unique names
            if(choice=='y' || choice=='Y'){
                string player1,player2;
                cout<<"Enter your names:"<<endl;
                cin>>player1>>player2;
                //calling forTwoPlayer() function with their names
                obj1.forTwoPlayer(player1,player2);
            }
            else{
                //calling forTwoPlayer() function with no names
                obj1.forTwoPlayer();
            }
            exit(0);
        default:
            cout<<"Invalid choice, try again."<<endl;
        }
    }while(true);
    return 0;
}
