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
