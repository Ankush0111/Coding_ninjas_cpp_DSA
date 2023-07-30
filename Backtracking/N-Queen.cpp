/*You are given 'N', and for a given 'N x N' chessboard. Find a configuration of 'N' queens such that no queen can attack any other queen on the chess board.


A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to return all such configurations.


Note:
If no such configuration is present return an empty array, it will be represented as 'No Configuration' in the output.
For Example:
For a chessboard of size 4*4
The configurations are 
alt text

Input Format:
The first line of input contains an integer, that denotes the value of N.     
Output Format :
In the output, every board configuration is printed in a new line. 

Every configuration will have 'N*N' board elements printed row wise and are separated by space. 

The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. 
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
Explanation:
The first and second configuration are shown in the image above in example.
Sample Input 2:
3
Sample Output 2 :
'No Configuration'
Constraints :
1 <= N <= 10
Time Limit: 1 second
*/



#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solutions;
int board[11][11];

bool isPossible(int n,int row,int col){

// Same Column
  for(int i=row-1;i>=0;i--){
    if(board[i][col] == 1){
      return false;
    }
  }
//Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
    if(board[i][j] ==1){
      return false;
    }
  }

  // Upper Right Diagonal

  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
    if(board[i][j] == 1){
      return false;
    }
  }

  return true;
}
void nQueenHelper(int n,int row){
  if(row==n){
    // We have reached some solution.
    // Print the board matrix
    // return
  vector<int> temp;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        // cout << board[i][j] << " ";
        temp.push_back(board[i][j]);
      }
    }
    // cout<<endl;
    solutions.push_back(temp);
    return;

  }

  // Place at all possible positions and move to smaller problem
  for(int j=0;j<n;j++){

    if(isPossible(n,row,j)){
      board[row][j] = 1;
      nQueenHelper(n,row+1);
      board[row][j] = 0;
    }
  }
}
vector<vector<int>>  nQueens(int n){

  memset(board,0,11*11*sizeof(int));

  nQueenHelper(n,0);
  return solutions;

}
