#include <bits/stdc++.h>
using namespace std;

int coins[] = {3, 4, 5, 30};
int solve(int x) {
	if (x < 0) return INT_MAX;
	if (x == 0) return 0;
	int best = INT_MAX;
	for (auto coin : coins) {
		int res = solve(x - coin);
		if (res != INT_MAX)
		best = min(best, solve(x - coin) + 1);
	}
	return best;
}
int main() {
	int x = 2;
	int result = 0;
	result = solve(x);
	cout << result << "\n";
	return 0;
}
