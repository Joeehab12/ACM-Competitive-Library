#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> days;
	for(int i = 0;i<n;i++){
		int a;
		cin >> a;
		days.push_back(a);
	}
	int remaining = 0;
	int candies = k;
	int ans = 0;
	// bool flag = false;
	for (int i = 0; i < days.size(); i++) {
		if (days[i] < 8) {
			candies -= days[i];
			int r = 8 - days[i];
			if (remaining >= r) {
				candies -= r;
				remaining -= r;
			}
			else {
				candies -= remaining;
				remaining = 0;
			}
		}
		else {
			candies -= 8;
			int l = days[i] - 8;
			remaining += l;
		}
		ans++;

		if  (candies <= 0) {
			cout << ans << endl;
			return 0;
		}


		// if (days[i] >=8 || remaining >=8){
		// 	candies-=8;
		// 	remaining += days[i]-8;
		// 	ans++;
		// }
		// else if (remaining <8){
		// 	candies-=days[i] + remaining;
		// 	ans++;
		// }
		// else{
		// 	candies-=days[i];
		// 	ans++;
		// }
		// if (candies <= 0){
		// 	if (ans<days.size() || candies<k){
		// 		cout << -1;
		// 		return 0;
		// 	}
		// 	flag = true;
		// 	break;
		// }
	}

	cout << -1 << endl;
}
