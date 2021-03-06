/*
    [BOJ] 13549 숨바꼭질3
    https://www.acmicpc.net/problem/13549
 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;

int visit[100001];
queue<pair<int, int>> q;
int ans = 1e9;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	pair<int, int> temp;

	cin >> N >> K;

	q.push(make_pair(N, 0));
	visit[N] = 1;

	while (!q.empty()) {
		temp = q.front();			//first: N second: cnt
		q.pop();

		if (temp.first == K) {
			ans = min(ans, temp.second);
			break;
		}
		if (((temp.first * 2) < 100001) && (!visit[temp.first * 2])) {
			//cout <<"temp.first *2: " <<temp.first *2 << "\n";
			visit[temp.first * 2] = 1;
			q.push(make_pair(temp.first * 2, temp.second));
		}
		if (((temp.first - 1) >= 0) && (!visit[temp.first - 1])) {
			//cout <<"temp.first - 1: " <<temp.first - 1<<"\n";
			visit[temp.first - 1] = 1;
			q.push(make_pair(temp.first - 1, temp.second + 1));
		}
		if (((temp.first + 1) < 100001) && (!visit[temp.first + 1])) {
			//cout <<"temp.first + 1: " <<temp.first + 1 << "\n";
			visit[temp.first + 1] = 1;
			q.push(make_pair(temp.first + 1, temp.second + 1));
		}
	
	}

	cout << ans;
	return 0;
}
