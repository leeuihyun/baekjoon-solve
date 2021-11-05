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
int arr[9];
void solve(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[cur] = i;
		solve(cur + 1);
	}
}

int main() {
	cin >> n >> m;
	solve(0);
	return 0;
}