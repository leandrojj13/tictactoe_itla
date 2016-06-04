#include <iostream>
#include "Game.h"
#include<stdlib.h>

#define clean system("cls");
using namespace std;

string initialOption;
char positionBoard [9] = {'1','2','3','4','5','6','7','8','9'};
string positionMove;
string winner;
string decision;
int jugada =0;
struct infoPlayers{
    string name;
    int victorias;
    int perdidas;
    char site;
    bool turno;
}player1, player2;

void welcome(bool verificator){
    clean;
    cout << "\n\n\t\t\t\t\t\tWelcome to VMeta Tic Tac Toe" << "\n\n\n\t\t\t\t\t\t";
    if(verificator){
        cout << "     Choose an opcion: "<<" \n\n\n\t\t\t\t\t 1. Play now! \n\t\t\t\t\t 2. Help \n\n\n \t\t\t\t\t"<< "Option for start: ";
    }else{
        cout << "     Choose an opcion: "<<" \n\n\n\t\t\t\t\t 1. Play now! \n\t\t\t\t\t 2. Help \n\n\n \t\t\t\t\t"<< "Please choose a correct, Option for start: ";
    }
    cin  >> initialOption;
    players();
}


void firstTurn(string choose){
    if(choose == "1")
            player1.turno = true;
    else if(choose == "2")
            player2.turno = true;
    else if (choose == "3"){
        short randomNumber = rand() % 2;
            switch(randomNumber){
            case 1: player1.turno = true; break;
            case 0: player2.turno = true; break;
        }
    }
}
void players(){
    if(initialOption == "1"){
        playersInitial();
    }else if(initialOption == "2"){
        string b;
        clean;
        cout << "\n\n\t\t\t\t\t\tHelp" << "\n\n\n\t\t\t\t\t\t" <<endl;
        cout << "\n Pasos : \n\n 1. Into the names of the rivals! \n 2. Choose who start! \n 3.Play the game! \n\n Option: 1. Return \n Answer: ";

        cin >> b;

        if(b == "1"){
            init();
        }else{
            players();
        }
    }
    else{
        welcome(false);
    }
}
void playersInitial(){
    string election = "2";
    clean;
    cout << "\n\n\n\t\t\t\t\t\tSelect your side:" << "\n\n\tFirst player's name (x): ";
    cin >> player1.name;
    cout << "\n\n\tSecond player's name (0): ";
    cin >> player2.name;

    player1.site = 'x';
    player2.site = '0';

    clean;
    do{
        if(election  < "1" || election > "3"){
            clean;
        }
        cout << "\n\n\n\n\n\t\t\t\t\t   Who will be the first to play?"<< " \n\n\n\t\t\t\t\t 1. "<< player1.name <<"\n\t\t\t\t\t 2. "<<  player2.name <<"\n\t\t\t\t\t 3. Random";

        if(election  < "1" || election > "3"){
            cout<<"\n\n\n \t\t\t"<< "Invalid Option Choose Again: ";
        }else{
            cout<<"\n\n\n \t\t\t"<< "Will be: ";
        }
        cin >> election;
    }while(election  < "1" || election > "3");

    firstTurn(election);

}


string name;
char siteP;

void playerNow( bool verificar){
    playArea();

    if(!verificar){
         if(player1.turno){
            name =  player1.name;
            siteP = player1.site;
            player1.turno =false;
            player2.turno = true;
        }else{
            name =  player2.name;
            siteP = player2.site;
            player1.turno =true;
            player2.turno = false;
        }
        cout << "\n\n\t'" << name <<"' is your turn ("<< siteP << ") , choose the position of your move: ";
        cin  >> positionMove;
    }else{
        cout << "\tYou need to choose a correct position!" << endl;
        cout << "\n\n\t'" << name <<"' is your turn ("<< siteP << ") , choose the position of your move: ";
        cin  >> positionMove;
        verificar = false;
    }
    verificador(siteP);
}

void verificador(char siteP2){
    if(positionMove <= "a" || positionMove <= "z" || positionMove <= "A" || positionMove <= "Z"){
        int a = atoi(positionMove.c_str());
        if(a > 0 && a < 10){

            switch(positionBoard [a-1]){
                case 'x':
                case '0':
                    playerNow(true);
                    break;
                default:
                    positionBoard [a-1] = siteP2;
                    break;
            }
        }else{
            playerNow(true);
        }
    }else{
        playerNow(true);
    }
}

void playArea(){
    clean;
    cout << "\n\n\n\t\t\t\t\t\t      TIC TAC TOE\n\n\n "<<endl;
    int y =0;
    for(int i =0; i < 8; i++){
         if((i+1)%3 == 0){
            cout << "\t\t\t\t\t\t------ ------ ------"<<endl;
         }else{
             if(i == 1 || i ==4 || i == 7){

                cout << "\t\t\t\t\t\t   "<< positionBoard[y] <<"  |   "<< positionBoard[y+1] <<"  |   "<< positionBoard[y+2] <<"  "<<endl;
                y+=3;
             }
             else
                cout << "\t\t\t\t\t\t      |      |"<<endl;
         }
    }
    cout<<"\n\n\t\t\t\t\t\t\t\t\t" <<" ["<< player1.site<<"] "<< player1.name << " (" << player1.victorias << ") ";
    cout<< "    vs    "<<" ["<< player2.site<<"] "<< player2.name << " (" << player2.victorias << ") " << endl;
}
void finalGame(int positionNumber){

    if(positionBoard[positionNumber] == player1.site){
        winner = player1.name;
        player1.victorias++;
    }
    else{
        winner= player2.name;
        player2.victorias++;
    }
}
void reintentar(bool verificator =false){
    if(!verificator){
        cout << "\n\n\n Congratulations " <<"'"<< winner <<"' has won :) \n\n\n Try again? \n\n 1. Yes \n 2. No \n\n Choose: ";
    }else{
        cout << "\n\n\n Empate intentalo nuevamente ganado :) \n\n\n Try again? \n\n 1. Yes \n 2. No \n\n Choose: ";
    }
    cin  >> decision;
    if(decision == "1"){
        positionBoard [0] = '1';
        positionBoard [1] = '2';
        positionBoard [2] = '3';
        positionBoard [3] = '4';
        positionBoard [4] = '5';
        positionBoard [5] = '6';
        positionBoard [6] = '7';
        positionBoard [7] = '8';
        positionBoard [8] = '9';
    }else{
        init();
    }
}
bool ganar(){
    jugada++;
    for (int i =0; i < 9; i+=3){
        if(positionBoard[i] == positionBoard[i+1] && positionBoard[i+2] == positionBoard[i+1]){
            finalGame(i);
            playArea();
            reintentar(false);
            jugada = 0;
            return true;
        }
    }
    for (int i =0; i < 9; i++){
        if(positionBoard[i] == positionBoard[i+3] && positionBoard[i+6] == positionBoard[i+3]){
            finalGame(i);
            playArea();
            reintentar(false);
            jugada = 0;
            return true;
        }
    }

    if(positionBoard[0] == positionBoard[4] && positionBoard[4] == positionBoard[8]){
         finalGame(0);
         playArea();
         reintentar(false);
         jugada = 0;
         return true;
    }

    if(positionBoard[2] == positionBoard[4] && positionBoard[6] == positionBoard[4]){
         finalGame(2);
         playArea();
         reintentar(false);
         jugada = 0;
         return true;
    }

    if(jugada == 9){
        playArea();
        reintentar(true);
    }
    return false;
}

void init () {
    initialOption = "";
    positionBoard [0] = '1';
    positionBoard [1] = '2';
    positionBoard [2] = '3';
    positionBoard [3] = '4';
    positionBoard [4] = '5';
    positionBoard [5] = '6';
    positionBoard [6] = '7';
    positionBoard [7] = '8';
    positionBoard [8] = '9';
    positionMove = "";
    winner = "";
    decision = "1";
    player1.victorias = 0;
    player2.victorias = 0;
    jugada = 0;

    name = "";
    siteP = 'x';
    welcome(true);
    while (!ganar() || decision == "1"){
        playerNow(false);
    }
    cout <<"\n\n\n\n" << endl;
    system("pause");
}
