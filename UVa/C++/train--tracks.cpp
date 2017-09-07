#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  //cin.ignore();
  n++;
  while(n--){
    string s;

    getline(cin,s);

    stringstream ss(s);
    string token;

    while(ss >> token){
      cout << token << ' ';
    }
  }
  return 0;
}
