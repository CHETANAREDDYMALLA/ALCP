#include<bits/stdc++.h>
using namespace std;
int rows,cols;
vector<vector<char>> board;
vector<vector<bool>> visited;
bool search(string &word,int r,int c,int index){
    if(index== (int)word.size()) return true;
    if(r<0|| r>=rows|| c<0|| c>=cols) return false;
    if(board[r][c]!= word[index]|| visited[r][c]) return false;
    visited[r][c]=true;
    bool found=search(word,r+1,c,index+1)|| search(word,r-1,c,index+1)||search(word,r,c+1,index+1)||search(word,r,c-1,index+1);
    visited[r][c]=false;
    return found;
}
bool exist(string &word){
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            if(search(word,r,c,0)) return true;
        }
    }
    return false;
}
int main(){
    cout<<"enter number of rows and columns:";
    cin>>rows>>cols;
    board.assign(rows,vector<char>(cols));
    visited.assign(rows,vector<bool>(cols,false));
    cout<<"enter the board row by row:\n";
    for(int r=0;r<rows;r++){
        string rowstr;
        cin>> rowstr;
        for(int c=0;c<cols;c++){
            board[r][c]=rowstr[c];
        }
    }
    string word;
    cout<<"enter the word to search:";
    cin>> word;
    cout<<(exist(word)?"word exists on the board.":"word does not exist on the board.")<<endl;
    return 0;
}
