#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans = 0;
	int h, w; cin >> h >> w;
	vector visit(h, vector<bool>(w));
	vector<string> v(h);
	for (int i = 0; i < h; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (v[i][j] == '.') {
				if (visit[i][j]) continue;
				auto dfs = [&](auto dfs, int i, int j) -> bool {
					bool ok = (0 < i && i < h - 1 && 0 < j && j < w - 1);
					visit[i][j] = true;
					for (int k = 0; k < 4; k++) {
						int ni = i + di[k], nj = j + dj[k];
						if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
						if (v[ni][nj] == '#') continue;
						if (visit[ni][nj] == true) continue;
						ok &= dfs(dfs, ni, nj);
					}
					return ok;
				};
				if (dfs(dfs, i, j)) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}