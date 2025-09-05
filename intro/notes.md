# Competitive Programming

Involves:
1. Design of algorithms
2. Implementing them

Theoretical knowledge is required to invent or implement an efficient algorithm.

## Programming Languages

C++, Python and Java most popular.

Most problems are set so using a specific language is not an unfair advantage, but some languages are better for some questions!

### C++ Code Template
```c++
#include <bits/stdc++.h>
using namespace std;

int main()
    // solution
}
```

Compile using:

```bash
g++ -std=c++11 -O2 -Wall test.cpp -o test
```

Standard streams are used for reading input and writing output.
So, cin and cout in C++.

Input:
```c++
int a, b;
string x;
cin >> a >> b >> x;
```
Assumes spaces between each element in the input.

Output:

```c++
int a = 123, b = 456;
string x = "monkey";
cout << a << " " << b << " " << x << "\n";
```

newline works faster than endl because endl almost always causes a stream flush.

Input and output can be a bottleneck, add these to make input and output more efficient:

```c++
ios:sync_with_stdio(0);
cin.tie(0);
```

C-based scanf and printf are more convoluted but a little faster.

```c++
int a, b;
scanf("%d %d", &a, &b);
printf("%d %d\n", a, b);
```

To read a whole line:

```c++
string s;
getline(cin, s);
```
gets a line from standard in, into a string.

If amount of data is unknown,

```c++
while (cin >> x) {
    // code
}
```
Loop reads elements from input one after another until there is no more data available.

When files are used for input and output, write code as usual, but add these lines to the beginning. They "route" the standard streams.

```c++
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

### Working with numbers

*Integer (int)* is the most common type.

* 32 bit type
* -2e31 to 2e31 - 1, about -2.10e9 to 2.10e9
* If this is not enough, use *long*

* Long: 64 bit type
* -2e63 to 2e63 - 1, about -9.10e18 to 9.10e18

This defines a *long long*:
```c++
long long x = 123456789123456789
