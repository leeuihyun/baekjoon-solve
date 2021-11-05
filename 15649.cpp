#include<iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include<math.h>
#include<vector>
#include<malloc.h>
#include<deque>
#include<stack>
#include<queue>
#include <sstream>
#include <functional>
#include <map>
#include <list>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
using namespace std;

int n, m;
int v[10];
bool visited[10] = { false, };

void solve(int cur) {
	if (cur == m) {
		for (int i = 0; i < cur; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i])continue;
		visited[i] = true;
		v[cur] = i;
		solve(cur + 1);
		visited[i] = false;
	}
}
int main() {
	cin >> n >> m;
	solve(0);
	return 0;
}