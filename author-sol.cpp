#include <bits/stdc++.h>

using namespace std;

//int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
//int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};

//int dx[4] = {-1, -1, 1, 1};
//int dy[4] = {-1, 1, -1, 1};

struct Point {
	int coord;
	int weight;
	int index;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<Point> a(m);
		for (int i = 0; i < m; i++) {
			cin >> a[i].coord >> a[i].weight;
			a[i].index = i + 1;
		}
		sort(a.begin(), a.end(), [](const Point& a, const Point& b) {
			return a.weight < b.weight;
		});
		int sum = 0;
		for (int i = 0; i < m; i++) {
			if (i < 2 * n) {
				sum += a[i].weight;
			} else {
				a.pop_back();
			}
		}
		sort(a.begin(), a.end(), [](const Point& a, const Point& b) {
			return a.coord < b.coord;
		});
		cout << sum << '\n';
		for (int i = 0; i < n; i++) {
			cout << a[i].index << " " << a[2 * n - i - 1].index << '\n';
		}
	}
	return 0;
}
