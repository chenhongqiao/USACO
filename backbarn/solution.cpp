#include <bits/stdc++.h>
using namespace std;
int r, c, k;
char g[10][10];
bool v[10][10];
int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y, int dep) {
	if (dep >=  k) {
		return;
	}
	if (x == 0 && y == c - 1) {
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int kx = x + dx[i];
		int ky = y + dy[i];
		if (kx >= 0 && kx < r && ky >= 0 && ky < c &&
		    g[kx][ky] != 'T' && !v[kx][ky]) {
			v[kx][ky] = true;
			dfs(kx, ky, dep + 1);
			v[kx][ky] = false;
		}
	}
}
int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> g[i][j];
		}
	}
	v[r-1][0]=true;
	dfs(r - 1, 0, 0);
	cout << ans << endl;
	return 0;
}
