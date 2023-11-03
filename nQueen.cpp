#include <iostream>
using namespace std;

bool isSafe(int **arr,int x,int y,int n){
    int row = x;
    int col = y;
    
    //checking rows and columns
    for(col =0 ; col < n ;col++){
        
         if(arr[x][col] == 1){
             return false;
         }
         
         if(arr[col][y] == 1){
             return false;
         }
         
    }
    
    //Left diagonal
     row = x;
     col = y;
    
    while(row >=0 && col >=0){
        
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row = x;
     col = y;
    while(row < n && col < n){
        
        if(arr[row][col]==1){
            return false;
        }
        
        row++;
        col++;
    }
    
    //Right Diagonal
    row = x;
     col = y;
     while(row >=0 && col < n){
        
        if(arr[row][col]==1){
            return false;
        }
        
        row--;
        col++;
    }
    row = x;
     col = y;
     while(row < n && col >=0){
        
        if(arr[row][col]==1){
            return false;
        }
        
        row++;
        col--;
    }

    return true;
    
}

bool nQueen(int **board,int row,int n){
    if( row >= n){
        return true;
    }
    
    for(int col = 0; col< n ;col++){
        if(isSafe(board,row,col,n)){
            board[row][col] = 1;
            
            if(nQueen(board , row + 1 ,n)){
                return true;
        }
            board[row][col] = 0;
    }
}
return false;
}

int main(){
    int n;
    cout<<"Enter  size of the board ";
    cin>>n;
    
    int **board = new int*[n];
    
    for(int i=0 ; i<n ; i++ ){
        board[i] = new int [n];
        for(int j=0 ; j< n ; j++){
            board[i][j] = 0;
        } 
    }
    
    nQueen(board , 0 ,n);
    
     for(int i=0 ; i<n ; i++ ){
         cout<<"\n";
        for(int j=0 ; j< n ; j++){
            cout<<board[i][j] <<"\t";
        } 
    }
    return 0; 
}        
