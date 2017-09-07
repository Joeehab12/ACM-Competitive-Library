#include <bits/stdc++.h>
using namespace std;
vector<string> rotate90(vector<string> &vec,int n){
    vector<string> rotated(n,"");
    int rotated_i=0,rotated_j=0;
    for(int i = 0;i<n;i++){
        for (int j = n-1;j>=0;j--){
            rotated[rotated_i].push_back(vec[j][i]);
            rotated_j++;
        }
        rotated_i++;
    }
    return rotated;
}

int check(int i,int j,vector<string> &big,vector<string> &small){
    int count0=0,count90=0,count180=0,count270 = 0;
    int res0=0,res90=0,res180=0,res270 = 0;
    int indexi=0,indexj=0;

    bool valid = 1;
    vector<pair<int, int> > v;
    for (int k = i;k<small.size()+i;k++){
        for (int m = j;m<small.size() +j;m++){
            if(big[k][m] == small[indexi][indexj]){
                v.push_back(make_pair(k, m));
                count0++;
            }
            indexj++;
        }
        indexj=0;
        indexi++;
    }
    if (count0 == small.size()*small.size()){
        // for (int i = 0; i < v.size(); i++)
        // cout << v[i].first << " " << v[i].second << endl;
        // // cout << i << " " << j << " " << big[i][j] << " " << small[0][0] << endl;
        res0++;
    }
    indexi = 0;
     return res0;
}

int check90(int i,int j,vector<string> &big,vector<string> &rotated90){
    int count0=0,count90=0,count180=0,count270 = 0;
    int res0=0,res90=0,res180=0,res270 = 0;
    int indexi=0,indexj=0;
    for (int k = i;k<rotated90.size()+i;k++){
        for (int m = j;m<rotated90.size()+j;m++){
            if (big[k][m] == rotated90[indexi][indexj]){
                count90++;

            }
            indexj++;
        }
        indexj=0;
        indexi++;
    }
    if (count90 == rotated90.size()*rotated90.size()){
        res90++;
    }
    indexi = 0;
    return res90;
}

int check180(int i,int j,vector<string> &big,vector<string> &rotated180){
    int count0=0,count90=0,count180=0,count270 = 0;
    int res0=0,res90=0,res180=0,res270 = 0;
    int indexi=0,indexj=0;
    for (int k = i;k<rotated180.size()+i;k++){
        for (int m = j;m<rotated180.size()+j;m++){
            if (big[k][m] == rotated180[indexi][indexj]){
                count180++;

            }
            indexj++;
        }
        indexj=0;
        indexi++;
    }
    if (count180 == rotated180.size()*rotated180.size()){
        res180++;
    }
    indexi = 0;
    return res180;
}

int check270(int i,int j,vector<string> &big,vector<string> &rotated270){
    int indexi=0,indexj=0;
    int count0=0,count90=0,count180=0,count270 = 0;
    int res0=0,res90=0,res180=0,res270 = 0;
    for (int k = i;k<rotated270.size()+i;k++){
        for (int m = j;m<rotated270.size()+j;m++){

            if (big[k][m] == rotated270[indexi][indexj]){
                count270++;

            }
            indexj++;
        }
        indexj=0;
        indexi++;
    }
    if (count270 == rotated270.size()*rotated270.size()){
        res270++;
    }
    indexi = 0;
    return res270;
}




int main(){
    int a,b;
    while (cin >> a >> b){
        if ( a == 0 && b == 0){
            break;
        }
        vector<string> big;
        vector<string> small;
        for (int i = 0;i<a;i++){
            string s;
            cin >> s;
            big.push_back(s);
        }

        for (int i = 0;i<b;i++){
            string st;
            cin >> st;
            small.push_back(st);
        }
        vector<string> rotated90,rotated180,rotated270;
        rotated90 = rotate90(small,b);
        rotated180 = rotate90(rotated90,b);
        rotated270 = rotate90(rotated180,b);

        int res0=0,res90=0,res180=0,res270=0;
        for (int i = 0;i<=a-b;i++){
            for (int j = 0; j<=a-b;j++){

                res0+= check(i,j,big,small);
                res90+= check90(i,j,big,rotated90);
                res180+= check180(i,j,big,rotated180);
                res270+= check270(i,j,big,rotated270);
            }
        }
        cout << res0 << ' ' << res90 << ' ' << res180 << ' ' << res270 << endl;

    }
}
