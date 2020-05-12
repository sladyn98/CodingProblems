#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
void solve() {
	int num;
    cin >> num;
	int quotient = 1;
	int multiplier = 1;
	vector<int> solution;
	while(quotient != 0) {
		quotient = num/10;
		int remainder = num%10;
		num = quotient;
		if(remainder * multiplier !=0 ) {
			solution.push_back(remainder * multiplier);
		}
		multiplier = multiplier * 10;
	}
    cout << solution.size() << endl;
	for (auto it = solution.begin(); it != solution.end(); it++) 
        cout << *it << " "; 
	cout<< endl;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin >> t;
	while(t--)
		solve();
}