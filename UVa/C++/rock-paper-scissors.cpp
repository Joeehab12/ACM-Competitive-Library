#include <bits/stdc++.h>
using namespace std;

bool isValid(int i,int j,int r,int c){
    if (i<=r-1 && j <=c-1 && i>=0 && j>=0){
      return true;
    }
    else{
      return false;
    }
}
bool isWinner(char first,char second){
  if (first == 'P' && second == 'S'){
    return false;
  }
  else if (first == 'S' && second == 'P'){
    return true;
  }
  else if (first == 'S' && second == 'R'){
    return false;
  }
  else if (first == 'P' && second == 'R'){
    return true;
  }
  else if (first == 'R' && second == 'S'){
    return true;
  }
  else {
    return false;
  }
}
int main(){

  int t;
  cin >> t;
  while(t--){
    int r,c,n;
    cin >> r >> c >> n;
    vector<string> grid;
    vector<string> newgrid;
    for(int i = 0;i<r;i++){
      string s;
      cin >> s;
      grid.push_back(s);
    }
    newgrid = grid;
    for (int k = 0;k<n;k++){
      for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
          if (isValid(i,j+1,r,c)){
            if(isWinner(grid[i][j],grid[i][j+1])){
              newgrid[i][j+1]=grid[i][j];
            }
          }
          if (isValid(i,j-1,r,c)){
            if(isWinner(grid[i][j],grid[i][j-1])){
              newgrid[i][j-1]=grid[i][j];
            }
          }
          if (isValid(i+1,j,r,c)){
            if(isWinner(grid[i][j],grid[i+1][j])){
              newgrid[i+1][j]=grid[i][j];
            }
          }
          if (isValid(i-1,j,r,c)){
            if(isWinner(grid[i][j],grid[i-1][j])){
              newgrid[i-1][j]=grid[i][j];
            }
          }
        }
      }
      grid = newgrid;
    }

    for (int i = 0;i<r;i++){
      cout << newgrid[i] << endl;
    }
    if (t > 0)
      cout << endl;
  }

}
