//
// Created by eagle on 3/13/2019.
//

#ifndef UNTITLED1_BOARD_H
#define UNTITLED1_BOARD_H
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <random>
#include <ctime>
#include <vector>


using namespace std;

class board
{
public:
    int row;
    int col;
    char **m;
    char **m1;
    map<char,int> ship;
    vector<vector <int>> saved;
    int mode;
    int cx;
    int cy;


    board(int a, int b){
        row = a;
        col = b;

        m = new char*[row];
        for (int i =0; i<row;i++){
            m[i] = new char[col];
        }

        for (int i =0; i < row;i++){
            for (int j =0; j <col;j++){
                m[i][j] ='*';
            }
        }
        m1 = new char*[row];
        for (int i =0; i<row;i++){
            m1[i] = new char[col];
        }

        for (int i =0; i < row;i++){
            for (int j =0; j <col;j++){
                m1[i][j] ='*';
            }
        }
    }
    void show (){
        cout<<"  ";
        for(int i =0; i<col;i++){
            cout<<i<<' ';
        }
        cout<<endl;
        for (int i =0; i < row;i++){
            cout<<i<<' ';
            for (int j =0; j <col;j++){
                cout<<m[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    void show1 (string name){
        cout<<name<<"'s Firing Board"<<endl;
        cout<<"  ";
        for(int i =0; i<col;i++){
            cout<<i<<' ';
        }
        cout<<endl;
        for (int i =0; i < row;i++){
            cout<<i<<' ';
            for (int j =0; j <col;j++){
                cout<<m1[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;

    }

    void showthis2 (board& board,string name){
        cout<<name<<"'s Firing Board"<<endl;
        cout<<"  ";
        for(int i =0; i<col;i++){
            cout<<i<<' ';
        }
        cout<<endl;
        for (int i =0; i < row;i++){
            cout<<i<<' ';
            for (int j =0; j <col;j++){
                cout<<board.m1[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;

    }
    void showthis1 (board& board){
        cout<<"  ";
        for(int i =0; i<col;i++){
            cout<<i<<' ';
        }
        cout<<endl;
        for (int i =0; i < row;i++){
            cout<<i<<' ';
            for (int j =0; j <col;j++){
                cout<<board.m[i][j]<<' ';
            }
            cout<<endl;
        }
    }


    bool check(int x,int y,int size,char choice){
        if (choice =='h'){
            for (int i =0; i<size;i++){
                if (m[x][y+i] == '*'){

                }
                else{
                    return false;
                }
            }
            return true;
        }
        else {
            for (int i =0; i<size;i++){
                if (m[x+i][y] == '*'){

                }
                else{
                    return false;
                }
            }
            return true;
        }

    }
    void play (int size,char name,string playername,map<char,int> ships){
        int x,y;
        char choice =' ';
        cout<<playername<<", do you want to place "<<name<<" horizontally or vertically?"<<endl;
        cout<<"Enter h for horizontal or v for vertical"<<endl;
        cout<<"Your choice: ";
        cin>>choice;
        cout<<playername <<", enter the row and column you want to place "<<name<<", which is "
            <<ships[name]<<" long, at with a space in between row and col:";
        cin>>x;
        cin>>y;
        if (choice == 'h'){
            if ((y+size) <= col && check(x,y,size,choice) ){
                for (int i =0;i<size;i++){
                    m[x][y+i] = name;
                }
                show();
            }
            else {
                show();
                play(size,name,playername,ships);
            }

        }
        else if (choice == 'v'){
            if ((x+size) <= row && check(x,y,size,choice) ){
                for (int i =0;i<size;i++){
                    m[x+i][y] = name;
                }
                show();
            }
            else {
                show();
                play(size,name,playername,ships);
            }
        }

    }
    void Aiplay(map<char,int> ships,char name,string playername,mt19937& random){
        uniform_int_distribution<> lol(0,1);
        int v = lol(random);
        if(v == 0){
            uniform_int_distribution<> rowh(0,row-1);
            int x = rowh(random);
            uniform_int_distribution<> colh(0,col-ships[name]);
            int y = colh(random);
            if (check(x,y,ships[name],'h')){
                for (int i =0;i<ships[name];i++){
                    m[x][y+i] = name;
                }
                cout<<playername<<"'s Board"<<endl;
                show();
                cout<<endl;
            }
            else{
                Aiplay(ships,name,playername,random);
            }
        }
        else if(v ==1){
            uniform_int_distribution<> rowv(0,row-ships[name]);
            int x = rowv(random);
            uniform_int_distribution<> colv(0,col-1);
            int y = colv(random);
            if (check(x,y,ships[name],'v')){
                for (int i =0;i<ships[name];i++){
                    m[x+i][y] = name;
                }
                cout<<playername<<"'s Board"<<endl;
                show();
                cout<<endl;
            }
            else{
                Aiplay(ships,name,playername,random);
            }
        }
    }
    void setship (map<char,int> ships){
        ship =ships;
    }

    vector<vector <int>> store (board& board){
        int count = 0;
        for (int i =0; i < row; i++){
            for (int j =0; j <col; j++){
                if (board.m[i][j] != '*'){
                    count+=1;
                }
            }
        }

        vector<vector <int>> answer(count);

        int count1 = 0;
        for (int i =0; i < row; i++){
            for (int j =0; j <col; j++){
                if (board.m[i][j] != '*'){
                    answer[count1] ={i,j};
                    count1 +=1;
                }
            }
        }
        return answer;
    }
    vector<vector<int>> flist(){
        vector<vector <int>>answer(row*col);
        int count =0;
        for (int i=0;i<row;i++){
            for(int j=0; j<col;j++){
                answer[count] ={i,j};
                count +=1;
            }
        }
        return answer;
    }
    void match (board& first, board& second, string player1name, string player2name){
        static vector<vector <int>> answer = store(first);
        static vector<vector <int>> answer1 = store(second);
        while (true) {
            fight(first,second, player1name,player2name,answer1);
            if (answer1.size() == 0){
                cout<<player1name<<" won the game!"<<endl;
                break;
            }
            showthis2(second,player2name);
            cout<<player2name<<" 's Placement Board"<<endl;
            showthis1(second);
            fight(second,first, player2name,player1name,answer);
            if (answer.size() == 0){
                cout<<player2name<<" won the game!"<<endl;
                break;
            }
            showthis2(first,player1name);
            cout<<player1name<<" 's Placement Board"<<endl;
            showthis1(first);
       }

    }
    void fight(board& first,board& second, string player1name,string player2name, vector<vector <int>>& answer){

        int x,y;
        cout<<player1name<<", where would you like to fire?"<<endl;
        cout<<"Enter your attack coordinate in the form row col:";
        cin >>x;
        cin >>y;
        if (first.m1[x][y] == '*'){
            first.m1[x][y] = 'O';
            if(second.m[x][y] != '*'){
                for (int i=0;i<answer.size();i++){
                    if(answer[i][0]==x && answer[i][1] ==y){
                        answer.erase(answer.begin()+i);
                    }
                }
                char waste = second.m[x][y];
                second.ship[second.m[x][y]] -=1;
                first.m1[x][y] = 'X';
                second.m[x][y] = 'X';
                showthis2(first,player1name);
                cout<<player1name<<"'s Placement Board"<<endl;
                showthis1(first);
                cout<<player1name<<" hit "<<player2name<<"'s "<<waste<<"!"<<endl;
                if (second.ship[waste] == 0){
                    cout<<player1name<<" destroyed "<<player2name<< "'s "<<waste<<"!"<<endl;
                }
                cout<<endl;
            }
            else{
                second.m[x][y] = 'O';
                showthis2(first,player1name);
                cout<<player1name<<"'s Placement Board"<<endl;
                showthis1(first);
                cout<<"Missed."<<endl;
                cout<<endl;
            }
        }
        else {
            showthis2(first,player1name);
            cout<<player1name<<"'s Placement Board"<<endl;
            showthis1(first);
            fight(first,second,player1name,player2name,answer);
        }
    }
    void match2 (board& first, board& second, string player1name, string player2name,mt19937& random,int choice,int choice1){
        static vector<vector <int>> answer = store(first);
        static vector<vector <int>> answer1 = store(second);
        static vector<vector <int>> firelist = flist();
        static vector<vector <int>> firelist1 = flist();
        first.mode =0;
        second.mode =0;
        first.cx =0;
        first.cy=0;
        second.cx =0;
        second.cy =0;
        while (true) {


            if (choice == 3){
                fight2(first,second,player1name,player2name,answer1,firelist,random);
            }
            else {
                fight1(first,second, player1name,player2name,answer1,firelist,random,choice);
            }
            if (answer1.size() == 0){
                cout<<endl;
                cout<<player1name<<" won the game!"<<endl;
                break;
            }
            /*
            showthis2(second,player2name);
            cout<<player1name<<" 's Placement Board"<<endl;
            showthis1(first);
            */
            if (choice1 == 3){
                fight2(second,first,player2name,player1name,answer,firelist1,random);
            }
            else {
                fight1(second,first, player2name,player1name,answer,firelist1,random,choice1);
            }
            if (answer.size() == 0){
                cout<<endl;
                cout<<player2name<<" won the game!"<<endl;
                break;
            }
            /*
            showthis2(first,player1name);
            cout<<player2name<<" 's Placement Board"<<endl;
            showthis1(second);
            */
        }

    }

    void match1 (board& first, board& second, string player1name, string player2name,mt19937& random,int choice){
        static vector<vector <int>> answer = store(first);
        static vector<vector <int>> answer1 = store(second);
        static vector<vector <int>> firelist = flist();
        first.mode =0;
        second.mode =0;
        second.cx =0;
        second.cy =0;
        while (true) {
            fight(first,second, player1name,player2name,answer1);
            if (answer1.size() == 0){
                cout<<player1name<<" won the game!"<<endl;
                break;
            }
            /*
            showthis2(second,player2name);
            cout<<player2name<<" 's Placement Board"<<endl;
            showthis1(second);
            */
            if (choice == 3){
                fight2(second,first,player2name,player1name,answer,firelist,random);
            }
            else {
                fight1(second,first, player2name,player1name,answer,firelist,random,choice);
            }
            if (answer.size() == 0){
                cout<<endl;
                cout<<player2name<<" won the game!"<<endl;
                break;
            }

            showthis2(first,player1name);
            cout<<player1name<<" 's Placement Board"<<endl;
            showthis1(first);

        }

    }
    void fight2(board& first,board& second, string player1name,string player2name, vector<vector <int>>& answer,vector<vector <int>>& firelist,mt19937& random){
        if (first.mode == 0) {
            //cout<<firelist.size();
            uniform_int_distribution<> wow(0, firelist.size() - 1);
            int position = wow(random);
            first.cx = firelist[position][0];
            first.cy = firelist[position][1];

            if (first.m1[first.cx][first.cy] == '*'){
                firelist.erase(firelist.begin() + position);
                first.m1[first.cx][first.cy] = 'O';
                if(second.m[first.cx][first.cy] != '*'){
                    for (int i=0;i<answer.size();i++){
                        if(answer[i][0]==first.cx && answer[i][1] ==first.cy){
                            answer.erase(answer.begin()+i);
                        }
                    }
                    char waste = second.m[first.cx][first.cy];
                    first.mode = 1;
                    second.ship[second.m[first.cx][first.cy]] -=1;
                    first.m1[first.cx][first.cy] = 'X';
                    second.m[first.cx][first.cy] = 'X';
                    showthis2(first,player1name);
                    cout<<player1name<<"'s Placement Board"<<endl;
                    showthis1(first);
                    cout<<player1name<<" hit "<<player2name<<"'s "<<waste<<"!"<<endl;
                    if (second.ship[waste] == 0){
                        cout<<player1name<<" destroyed "<<player2name<< "'s "<<waste<<"!"<<endl;
                    }
                    cout<<endl;
                }
                else{
                    second.m[first.cx][first.cy] = 'O';
                    showthis2(first,player1name);
                    cout<<player1name<<"'s Placement Board"<<endl;
                    showthis1(first);
                    cout<<"Missed."<<endl;
                    cout<<endl;
                }
            }
            else {
                showthis2(first,player1name);
                cout<<player1name<<"'s Placement Board"<<endl;
                showthis1(first);
                fight2(first,second,player1name,player2name,answer,firelist,random);
            }
        }
        else if (first.mode ==1){
            if ((first.cy-1)<0){
                first.mode =2;
                fight2(first,second,player1name,player2name,answer,firelist,random);
            }
            else {
                int x = first.cx;
                int y = first.cy-1;
                if (first.m1[x][y] == '*'){
                    first.m1[x][y] = 'O';
                    for (int i =0;i<firelist.size();i++){
                        if (firelist[i][0] == x && firelist[i][1] == y){
                            firelist.erase(firelist.begin()+i);
                        }
                    }
                    if(second.m[x][y] != '*'){
                        //cout<<x<<endl;
                        //cout<<y<<endl;
                        for (int i=0;i<answer.size();i++){
                            if(answer[i][0]==x && answer[i][1] ==y){
                                answer.erase(answer.begin()+i);
                                //cout<<answer.size()<<endl;
                            }
                        }
                        cout<<firelist.size();
                        char waste = second.m[x][y];
                        first.mode =2;
                        first.saved.push_back({x,y});
                        second.ship[second.m[x][y]] -=1;
                        first.m1[x][y] = 'X';
                        second.m[x][y] = 'X';
                        showthis2(first,player1name);
                        cout<<player1name<<"'s Placement Board"<<endl;
                        showthis1(first);
                        cout<<player1name<<" hit "<<player2name<<"'s "<<waste<<"!"<<endl;
                        //fight2(first,second,player1name,player2name,answer,firelist,saved,random,1,x,y);
                        if (second.ship[waste] == 0){
                            cout<<player1name<<" destroyed "<<player2name<< "'s "<<waste<<"!"<<endl;
                        }
                        cout<<endl;
                    }
                    else{
                        second.m[x][y] = 'O';
                        first.mode =2;
                        showthis2(first,player1name);
                        cout<<player1name<<"'s Placement Board"<<endl;
                        showthis1(first);
                        cout<<"Missed."<<endl;
                        cout<<endl;
                    }
                }
                else {
                    first.mode = 2;
                    /*
                    showthis2(first,player1name);
                    cout<<player1name<<"'s Placement Board"<<endl;
                    showthis1(first);
                    */
                    fight2(first,second,player1name,player2name,answer,firelist,random);
                }
            }
        }
        else if (first.mode ==2){
            if((first.cx-1)<0){
                first.mode = 3;
                fight2(first,second,player1name,player2name,answer,firelist,random);
            }
            else {
                int x = first.cx-1;
                int y = first.cy;
                if (first.m1[x][y] == '*'){
                    for (int i =0;i<firelist.size();i++){
                        if (firelist[i][0] == x && firelist[i][1] == y){
                            firelist.erase(firelist.begin()+i);
                        }
                    }
                    first.m1[x][y] = 'O';
                    if(second.m[x][y] != '*'){
                        for (int i=0;i<answer.size();i++){
                            if(answer[i][0]==x && answer[i][1] ==y){
                                answer.erase(answer.begin()+i);
                                //cout<<answer.size()<<endl;
                            }
                        }
                        //cout<<firelist.size();
                        char waste = second.m[x][y];
                        first.mode =3;
                        first.saved.push_back({x,y});
                        second.ship[second.m[x][y]] -=1;
                        first.m1[x][y] = 'X';
                        second.m[x][y] = 'X';
                        showthis2(first,player1name);
                        cout<<player1name<<"'s Placement Board"<<endl;
                        showthis1(first);
                        cout<<player1name<<" hit "<<player2name<<"'s "<<waste<<"!"<<endl;
                        //fight2(first,second,player1name,player2name,answer,firelist,saved,random,1,x,y);
                        if (second.ship[waste] == 0){
                            cout<<player1name<<" destroyed "<<player2name<< "'s "<<waste<<"!"<<endl;
                        }
                        cout<<endl;
                    }
                    else{
                        first.mode =3;
                        second.m[x][y] = 'O';
                        showthis2(first,player1name);
                        cout<<player1name<<"'s Placement Board"<<endl;
                        showthis1(first);
                        cout<<"Missed."<<endl;
                        cout<<endl;
                    }
                }
                else {
                    first.mode = 3;
                    /*
                    showthis2(first,player1name);
                    cout<<player1name<<"'s Placement Board"<<endl;
                    showthis1(first);
                    */
                    fight2(first,second,player1name,player2name,answer,firelist,random);
                }

            }
        }
        else if (first.mode ==3){
            if ((first.cy+1)>=col){
                first.mode = 4;
                fight2(first,second,player1name,player2name,answer,firelist,random);
            }
            else {
                int x = first.cx;
                int y = first.cy+1;
                if (first.m1[x][y] == '*'){
                    first.m1[x][y] = 'O';
                    for (int i =0;i<firelist.size();i++){
                        if (firelist[i][0] == x && firelist[i][1] == y){
                            firelist.erase(firelist.begin()+i);
                        }
                    }
                    if(second.m[x][y] != '*'){
                        for (int i=0;i<answer.size();i++){
                            if(answer[i][0]==x && answer[i][1] ==y){
                                answer.erase(answer.begin()+i);
                                //cout<<answer.size()<<endl;
                            }
                        }
                        //cout<<firelist.size();
                        char waste = second.m[x][y];
                        first.mode =4;
                        first.saved.push_back({x,y});
                        second.ship[second.m[x][y]] -=1;
                        first.m1[x][y] = 'X';
                        second.m[x][y] = 'X';
                        showthis2(first,player1name);
                        cout<<player1name<<"'s Placement Board"<<endl;
                        showthis1(first);
                        cout<<player1name<<" hit "<<player2name<<"'s "<<waste<<"!"<<endl;
                        //fight2(first,second,player1name,player2name,answer,firelist,saved,random,1,x,y);
                        if (second.ship[waste] == 0){
                            cout<<player1name<<" destroyed "<<player2name<< "'s "<<waste<<"!"<<endl;
                        }
                        cout<<endl;
                    }
                    else{
                        first.mode =4;
                        //second.m[x][y] = 'O';
                        second.m[x][y] = 'O';
                        showthis2(first,player1name);
                        cout<<player1name<<"'s Placement Board"<<endl;
                        showthis1(first);
                        cout<<"Missed."<<endl;
                        cout<<endl;
                    }
                }
                else {
                    first.mode = 4;
                    /*
                    showthis2(first,player1name);
                    cout<<player1name<<"'s Placement Board"<<endl;
                    showthis1(first);
                    */
                    fight2(first,second,player1name,player2name,answer,firelist,random);
                }

            }
        }
        else if (first.mode ==4){
            if ((first.cx+1)>=row){
                first.mode = 5;
                fight2(first,second,player1name,player2name,answer,firelist,random);
            }
            else{
                int x =first.cx+1;
                int y =first.cy;
                if (first.m1[x][y] == '*'){
                    first.m1[x][y] = 'O';
                    for (int i =0;i<firelist.size();i++){
                        if (firelist[i][0] == x && firelist[i][1] == y){
                            firelist.erase(firelist.begin()+i);
                        }
                    }
                    if(second.m[x][y] != '*'){
                        for (int i=0;i<answer.size();i++){
                            if(answer[i][0]==x && answer[i][1] ==y){
                                answer.erase(answer.begin()+i);
                                    //cout<<answer.size()<<endl;
                            }
                        }
                        //cout<<firelist.size();
                        char waste = second.m[x][y];
                        first.mode = 5;
                        first.saved.push_back({x,y});
                        second.ship[second.m[x][y]] -=1;
                        first.m1[x][y] = 'X';
                        second.m[x][y] = 'X';
                        showthis2(first,player1name);
                        cout<<player1name<<"'s Placement Board"<<endl;
                        showthis1(first);
                        cout<<player1name<<" hit "<<player2name<<"'s "<<waste<<"!"<<endl;
                        //fight2(first,second,player1name,player2name,answer,firelist,saved,random,1,x,y);
                        if (second.ship[waste] == 0){
                            cout<<player1name<<" destroyed "<<player2name<< "'s "<<waste<<"!"<<endl;
                        }
                        cout<<endl;
                    }
                    else{
                        first.mode =5;
                        second.m[x][y] = 'O';
                        showthis2(first,player1name);
                        cout<<player1name<<"'s Placement Board"<<endl;
                        showthis1(first);
                        cout<<"Missed."<<endl;
                        cout<<endl;
                    }
                }
                else {
                    first.mode = 5;
                    /*
                    showthis2(first,player1name);
                    cout<<player1name<<"'s Placement Board"<<endl;
                    showthis1(first);
                    */
                    fight2(first,second,player1name,player2name,answer,firelist,random);
                }
            }
        }
        else if (first.mode ==5){
            if (first.saved.size() == 0){
                first.mode = 0;
                fight2(first,second,player1name,player2name,answer,firelist,random);
            }
            else {
                first.cx = first.saved[0][0];
                first.cy = first.saved[0][1];
                first.saved.erase(first.saved.begin());
                first.mode = 1;
                fight2(first,second,player1name,player2name,answer,firelist,random);
            }
        }
    }

    void fight1(board& first,board& second, string player1name,string player2name, vector<vector <int>>& answer,vector<vector <int>>& firelist,mt19937& random,int choice){
        int x,y;
        if (choice == 2){
            uniform_int_distribution<> wow(0,firelist.size()-1);
            int position = wow(random);
            x = firelist[position][0];
            y = firelist[position][1];
            firelist.erase(firelist.begin()+position);
        }
        else if (choice ==1){
            x = answer[0][0];
            y = answer[0][1];
        }
        if (first.m1[x][y] == '*'){
            first.m1[x][y] = 'O';
            if(second.m[x][y] != '*'){
                for (int i=0;i<answer.size();i++){
                    if(answer[i][0]==x && answer[i][1] ==y){
                        answer.erase(answer.begin()+i);
                    }
                }
                char waste = second.m[x][y];
                second.ship[second.m[x][y]] -=1;
                first.m1[x][y] = 'X';
                second.m[x][y] = 'X';
                showthis2(first,player1name);
                cout<<player1name<<"'s Placement Board"<<endl;
                showthis1(first);
                cout<<player1name<<" hit "<<player2name<<"'s "<<waste<<"!"<<endl;
                if (second.ship[waste] == 0){
                    cout<<player1name<<" destroyed "<<player2name<< "'s "<<waste<<"!"<<endl;
                }
                cout<<endl;
            }
            else{
                second.m[x][y] = 'O';

                showthis2(first,player1name);
                cout<<player1name<<"'s Placement Board"<<endl;
                showthis1(first);
                cout<<"Missed."<<endl;
                cout<<endl;
            }
        }
        else {
            showthis2(first,player1name);
            cout<<player1name<<"'s Placement Board"<<endl;
            showthis1(first);
            fight1(first,second,player1name,player2name,answer,firelist,random,choice);
        }
    }


};

#endif //UNTITLED1_BOARD_H
