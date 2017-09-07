#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        if (n == 0){
            break;
        }
        vector<int> waveform;
        for (int i = 0;i<n;i++){
            int k;
            cin >> k;
            waveform.push_back(k);
        }
        vector<int>::iterator it;
        it = waveform.begin();
        int first = waveform[0];
        waveform.insert(it,waveform[waveform.size()-1]);
        waveform.push_back(first);
        int peaks = 0;
        for (int i = 0;i<waveform.size()-2;i++){
            if (waveform[i]<waveform[i+1] && waveform[i+2] < waveform[i+1] ){
                peaks++;
            }
            else if (waveform[i]>waveform[i+1] && waveform [i+2] > waveform[i+1]){
                peaks++;
            }
        }
        cout << peaks << endl;
    }
    return 0;
}
