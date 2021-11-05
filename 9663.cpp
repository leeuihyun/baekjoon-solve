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

int n;

int board[16];
int answer = 0;

bool what(int number) {
	for (int i = 0; i < number; i++) {
		if (board[i] == board[number] || number - i == abs(board[number] - board[i]))
			return false;
	}
	return true;
}

void solve(int cur) {
	if (cur == n) {
		answer += 1;
		return;
	}
	for (int i = 0; i < n; i++) {
		board[cur] = i;
		if (what(cur)) {
			solve(cur + 1);
		}
		else
			board[cur] = 0;
	}
}

int main() {
	cin >> n;
	solve(0);
	cout << answer;
	return 0;
}