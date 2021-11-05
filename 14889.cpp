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

int answer = 200000;
int n;
int arr[21][21];
bool visited[21];

void solve(int cur, int cnt) {
	if (cnt == n / 2) {
		int start = 0;
		int link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i] && visited[j]) start += arr[i][j];
				if (!visited[i] && !visited[j]) link += arr[i][j];
			}
		}
		answer = min(answer, abs(start - link));
		return;
	}
	for (int i = cur; i <= n; i++) {
		visited[i] = true;
		solve(i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(1, 0);
	cout << answer;
	return 0;
}