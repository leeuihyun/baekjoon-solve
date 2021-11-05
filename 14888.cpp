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

int min_number = 1000000001;
int max_number = -1000000001;

int cases;
int arr[12];
int sign[4]; //plus,minus,mul,div
int answer;

void solve(int cur) {
	if (cur == cases - 1) {
		max_number = max(max_number, answer);
		min_number = min(min_number, answer);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (cur == 0) {
			answer = arr[0];
			//solve(cur + 1);
		}
		if (sign[i]) {
			int tmp = answer;
			if (i == 0) {
				answer += arr[cur + 1];
			}
			else if (i == 1) {
				answer -= arr[cur + 1];
			}
			else if (i == 2) {
				answer *= arr[cur + 1];
			}
			else {
				answer /= arr[cur + 1];
			}
			sign[i] -= 1;
			solve(cur + 1);
			sign[i] += 1;
			answer = tmp;
		}


	}
}


int main() {
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++)
		cin >> sign[i];
	solve(0);
	cout << max_number << "\n";
	cout << min_number << "\n";
	return 0;
}