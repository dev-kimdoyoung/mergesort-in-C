#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	vector<int> a;
	vector<int> b;
	
	int m, n, input;
	
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> input;		
		a.push_back(input);
	}
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> input;		
		b.push_back(input);
	}
	
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> ans;
	while(p2 < m && p3 < n) {
		if(a[p2] < b[p3]) {
			p2++;
		} else if(a[p2] > b[p3]) {
			p3++;
		} else {
			ans.push_back(a[p2]);
			p2++;
		}
	}
	
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}

