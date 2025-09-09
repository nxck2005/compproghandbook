# Dynamic Programming
The goat :)

Combines *correctness* of __complete search__ and *efficiency* of __greedy algs_.

Can be applied if problem can be divided into overlapping subproblems that can be solved independently.

Two main uses:
- Finding optimal solution: Find a solution that is as large or small as possible
- Counting total number of possible solns.

## Coin Problem

Given a set of coin values:
```
coins = {c1, c2, .... ck}
```
and a target sum of money *n*, form the sum n using as few coins as possible.

From greedy algs, we can pick out the largest possible coin, but fails on general cases.

Brute force goes through all possibilities but well, is brute force.

DP is efficient as it trades off some time complexity for space complexity, and__memoizes__ important computations i.e. caches it for further use if needed.

Based on a recursive function, goes through all possibilities how to form the sum just like a brute force algorithm, but with memoization.

### Recursive formulation

The idea is to formulate the problem recursively so that the soln to the problem can be calculated from solutions to smaller subprobs.

Problem that can be recursed on: __What is the smallest number of coins required to form a sum *x*?__

Let ```solve(x)``` denote min number of coins required for a sum ```x```. The values of the function depend on the values of coins, and so do the base cases.

If ```coins = {1,3,4}```, the first values would be:

```c++
solve(0) = 0;
solve(1) = 1;
solve(2) = 2;
solve(3) = 3;
solve(4) = 1;
...
```

```solve(10) = 3```, because at least 3 coins are needed to form the sum 10. The optimal solution is 3 + 3 + 4 = 10.

The essential property of solve: its values can be recursively calculated from smaller values, ___ by focusing on the first coin we choose for the sum! ___

If first is 1:
- Remaining problem to recurse on: sum = x - 1 so 9, hence form 9 now, with given coins. Which is a subproblem!

Choose the minimum over all of the 3 possible pathways for coins here.
Hence, minimum of (if 1 was chosen), (if 3 was chosen), (if 4 was chosen).

```c++
solve(x) = min(solve(x-1) + 1, solve(x-3) + 1, solve(x-4) + 1);
// + 1 because as we chose a coin, thats +1 to the coin count
```

Well, every recursive problem has a base case, here being:
```c++
solve(0) = 0;
```
as no coins are needed to form 0.

Example:
```c++
solve(10) = solve(7) + 1 = solve(4) + 2 = solve(0) + 3 = 3
```
General recursive function: *given in book*

Go through coins.cpp

