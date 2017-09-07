#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    locale loc;
    vector <string> dictionary;
    while(str!= "#"){
        dictionary.push_back(str);
        cin >> str;
    }
    vector<string> temp;
    temp = dictionary;
    for (int i = 0;i<dictionary.size();i++){
        transform(temp[i].begin(),temp[i].end(),temp[i].begin(),::tolower);
        sort(temp[i].begin(),temp[i].end());
    }
    vector<bool> ananagram(dictionary.size(),true);
    for (int i = 0;i<dictionary.size();i++){
        for(int j=i+1;j<dictionary.size();j++){
            if (temp[i] == temp[j]){
                ananagram[i]=false;
                ananagram[j]=false;
            }
        }
    }
    vector<string> answer;
    for (int i = 0;i<dictionary.size();i++){
        if (ananagram[i]){
            answer.push_back(dictionary[i]);
        }
    }
    sort(answer.begin(),answer.end());
    for (int i = 0;i<answer.size();i++){
        cout << answer[i] << endl;
    }
}
