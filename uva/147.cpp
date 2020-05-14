#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 10;
int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
string s;
long long dp[MAX];
void run() {
	int len_coins = sizeof(coins) / sizeof(coins[0]);
	dp[0] = 1;
	for(int i = 0; i < len_coins; ++i) {
		int coin = coins[i];
		for(int j = 0; j < MAX - coin; j += 5) {
			dp[j + coin] += dp[j];
		}
	}
}
int main() {
	run();
	while( cin >> s ) {
		if(s == "0.00") break;
		string temp = "";
		for(char i : s) if(i != '.') temp += i;
		int d = stoi(temp);
		cout << right << setw(6) << s << setw(17) << dp[d] << endl;
	}
	return 0;
}
