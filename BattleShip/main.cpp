#include <iostream>
#include <fstream>
#include "board.h"
#include <map>
#include<vector>
#include <bits/stdc++.h>
#include <ctime>
#include <random>
#include <cstdlib>


using namespace std;
int main(int argc, const char* argv[]) {
    /*
    vector<int> woww;
    woww.push_back(5);
    */

    ifstream fp (argv[1]);

    int seed;
    if (argv[2]){
        seed = atoi(argv[2]);
    }

    else{
        seed = time(nullptr);
    }

    mt19937 random(seed);

    int row,col,num;
    fp >>row;
    fp >>col;
    fp >>num;


    map<char,int> ships;
    char names[num];
    char shipname = ' ';
    int length = 0;
    for (int i =0; i <num; i++){
        fp>>shipname;
        fp>>length;
        ships[shipname] = length;
        names[i] = shipname;
    }
    int n = sizeof(names)/sizeof(names[0]);
    sort(names,names+n);
    board first(row,col);
    first.setship(ships);
    board second(row,col);
    second.setship(ships);

    cout<<"What type of game do you want to play?"<<endl;
    cout<<"1. Human vs Human"<<endl;
    cout<<"2. Human vs AI"<<endl;
    cout<<"3. AI vs AI"<<endl;
    cout<<"Your choice: ";
    int a = 0;
    string player1name =" ";
    string player2name =" ";
    cin >>a;
    if (a == 1){
        cout<<"Player 1 please enter your name: ";
        cin >>player1name;
        first.show();
        for (int i =0;i <num;i++){
            char tempship = names[i];

            first.play(ships[tempship],tempship,player1name,ships);
        }
        cout<<"Player 2 please enter your name: ";
        cin >>player2name;
        second.show();
        for (int i =0;i <num;i++){
            char tempship = names[i];
            second.play(ships[tempship],tempship,player2name,ships);
        }
        first.show1(player1name);
        cout<<player1name<<"'s Placement Board"<<endl;
        first.show();
        first.match(first,second,player1name,player2name);
    }

    else if (a ==2){

        cout<<"Player 1 please enter your name: ";
        cin >>player1name;
        first.show();
        for (int i =0;i <num;i++){
            char tempship = names[i];

            first.play(ships[tempship],tempship,player1name,ships);
        }
        cout<<"What AI do you want?"<<endl<<"1. Cheating AI"<<endl<<"2. Random AI"<<endl<<"3. Hunt Destroy AI"<<endl;
        cout<<"Your choice:";
        int Aichoice;
        cin>>Aichoice;
        player2name ="AI 1";
        for (int i =0;i <num;i++){
            char tempship = names[i];

            second.Aiplay(ships,tempship,player2name,random);
        }
        first.show1(player1name);
        cout<<player1name<<"'s Placement Board"<<endl;
        first.show();
        first.match1(first,second,player1name,player2name,random,Aichoice);
    }
    else if (a ==3){
        cout<<"What AI do you want?"<<endl<<"1. Cheating AI"<<endl<<"2. Random AI"<<endl<<"3. Hunt Destroy AI"<<endl;
        cout<<"Your choice:";
        player1name ="AI 1";
        player2name="AI 2";
        int Aichoice;
        cin>>Aichoice;
        for (int i =0;i <num;i++){
            char tempship = names[i];

            first.Aiplay(ships,tempship,player1name,random);
        }
        cout<<"What AI do you want?"<<endl<<"1. Cheating AI"<<endl<<"2. Random AI"<<endl<<"3. Hunt Destroy AI"<<endl;
        cout<<"Your choice:";
        int Aichoice1;
        cin>>Aichoice1;
        //cout<<player1name<<"'s Board";
        //first.show();
        for (int i =0;i <num;i++){
            char tempship = names[i];

            second.Aiplay(ships,tempship,player2name,random);
        }
        //cout<<player2name<<"'s Board";
        //second.show();
        first.match2(first,second,player1name,player2name,random,Aichoice,Aichoice1);


    }




    return 0;
}