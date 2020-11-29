#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
umap<int, int> m;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		m[y]++;
	}
	int ans = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		int tmp = it->second;
		while (tmp > 0) {
			ans += tmp / 2;
			tmp--;
		}
	}
	cout << ans << endl;
	return 0;
}
