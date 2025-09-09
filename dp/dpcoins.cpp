#include <bits/stdc++.h>
using namespace std;

int coins[] = {1, 3, 4};

int solve(int x, vector<bool>& ready, vector<int>& value) {
	if (x < 0) return INT_MAX;
	if (x == 0) return 0;
	if (ready[x]) return value[x];
	int best = INT_MAX;
	for (auto coin : coins) {
      		int res = solve(x - coin, ready, value);
		if (res != INT_MAX) best = min(best, res + 1);
	}
	value[x] = best;
	ready[x] = true;
	return best;
}

int main() {
	int x = 10;
	vector<int> value(x+1, 0);
	vector<bool> ready(x+1, false);
	ready[0] = true;
	value[0] = 0;
	int res = solve(x, ready, value);
	cout << res << endl;
	return 0;
}

