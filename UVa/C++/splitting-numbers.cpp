#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        if (n == 0){
            break;
        }
        string binary = bitset<31>(n).to_string();
        string check;
        vector<int> indices;
        for (int i = 30;i>=0;i--){
            if (binary[i] == '1'){
                indices.push_back(i);
                check.append(1,binary[i]);
            }
        }

        string a = "0000000000000000000000000000000";
        string b = "0000000000000000000000000000000";
        for (int i = 0;i<check.size();i++){
            if (i % 2 == 0){
                a[indices[i]] = check[i];
            }
            else{
                b[indices[i]] = check[i];
            }
        }

        
        int first = strtol(a.c_str(), nullptr, 2);
        int second = strtol(b.c_str(), nullptr, 2);
        cout << first <<  ' ' << second << endl;
    }
}
