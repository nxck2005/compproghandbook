#include <bits/stdc++.h>
using namespace std;

int coins[] = {1, 3, 4};

int solve(int x) {
	vector<int> values(x + 1, 0);
	for (int i = 1; i <= x; i++) {
      		
