#include<iostream>
#include<algorithm>

#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
using namespace std;

int n, m;
int answer;
vector <int> v;

void solve(int cur, int sum) {
	if (cur == n) return;
	if (v[cur] + sum == m)answer += 1;
	solve(cur + 1, sum);
	solve(cur + 1, sum + v[cur]);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	solve(0, 0);
	cout << answer;

	return 0;
}