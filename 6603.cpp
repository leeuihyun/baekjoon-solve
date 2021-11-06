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

int number;
int result[6];
bool visited[50];

vector <int> v;

void solve(int cur, int idx) {
	if (cur == 6) {
		for (int i = 0; i < 6; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < number; i++) {
		if (visited[v[i]])continue;
		result[cur] = v[i];
		visited[v[i]] = true;
		solve(cur + 1, i + 1);
		visited[v[i]] = false;
	}
}
int main() {
	while (1) {
		cin >> number;
		if (number == 0) break;
		for (int i = 0; i < number; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		int len = v.size();
		solve(0, 0);
		cout << "\n";
		v.erase(v.begin(), v.end());
	}
	return 0;
}