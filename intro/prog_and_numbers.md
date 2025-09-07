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
ios::sync_with_stdio(0);
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
long long x = 123456789123456789LL;
```
The suffix usually denotes the type.

A common mistake is to still use *int* somewhere while meaning to use *long long*.

```c++
int a = 123456789;
long long b = a * a;
cout << b << "\n"; \\ -1757895751
```

As a is an integer, a * a is also an integer. B will overflow before
truncating! Either change a to *long long* or the expression to:
```c++
long long b = (long long) a * a;
```

Some contest systems or compilers provide a 128 bit type called *__int128_t*.

*Modular Arithmetic* is done using the % operator.
We denote by x mod m the remainder when x is divided by m.
17 mod 5 = 2 because 17 = (3 * 5) + 2.

Sometimes the answer to a problem is a very large number but it is enough to output it "modulo m", which implies the remainder when the answer is divided by m. (e.g modulo 10^9 + 7")
The idea is that even if the actual answer is huge, it suffices to use a smaller type.

Properties (remainder can be taken before the operation):
- (a+b)modm = (amodm + bmodm)modm
- (a-b)modm = (amodm - bmodm)modm
- (ab)modm = (amodm.bmodm)modm

So take remainder after every op and number never becomes too large. Proof is trivial

For example, in n! mod m:

```c++
long long x = 1;
for (int i = 2; i <= n; i++) {
    x = (x*i)%m;
}
cout << x % m << "\n";
```
If there are subtractions in the code and the remainder may become negative, C++ and other LL languages take the remainder to be either zero or negative.
To make sure there are no negative remainders, calculate the remainder as usual and add m if the result is negative.
```c++
x = x % m;
if (x < 0) x += m;
```

*Floating point numbers* are usually represented by the 64-bit *double* and in g++, the 80-bit *double*. The extra bits make it more accurate.

The required precision is given in the problem statement.
You can print the required decimal places by:

```c++
printf("%.9f", x);
```

This prints value of x with 9 decimal places.

Floating point imprecision becomes clear when some numbers cannot be represented accurately as floats, and there are rounding errors.

```c++
double x = 0.3 * 3 + 0.1;
printf("%.20f\n", x); // 0.99999...99988898
```

The correct value should be 1!

For this and similar reasons, it's risky to compare floating point nums with ==, as it is possible that the values should be equal but are not due to precision errors.

Better way to compare is to assume that two numbers are equal if thedifference between them is less than e (epsilon) where e is a small number.

In practice this can be done as follows: (epsilon being 10e-9)
```c++
if (abs(a-b) < 1e-9) {
    // a and b are equal
}
```

While they are inaccurate, integers up to 2^53 at most can still be represented accurately via a *double*.

## Shortening Code

Shortening code is ideal as programs should be written as fast as possible. Aliases are defined for shorter names for dtypes and other parts of code.

### Type Names

*typedef* is used to give a shorter name to a dtype.

```c++
typedef long long ll;
ll a = 123456789;
```

Now we can type *ll* instead of long long.
Can be also used with the STL, or more complex types.

```c++
typedef vector<int> vi;
typedef pair<int, int> pi;
```

*Macros* can also be used. Combining those with type names above:

```c++
#define F first
#define S second
#define PB push_back
#define MP make_pair

v.PB(MP(y1,x1));
v.PB(MP(y2, x2));
int d = v[i].F + v[i].S;
```

Macro can also have parameters which makes us possible to shorten loops and some other structures.

```c++
#define REP(i,a,b) for (int i = a; i <= b; i++)
REP (i, 1, n) {
    search(i);
}
```

Macro causes bugs that are a little difficult to detect.
The given macro does not always work as expected:

```c++
#define SQ(a) a * a
cout << SQ(3 + 3) << "\n";
```

simplifies to:

```c++
cout << 3 + 3 * 3 * 3 << "\n"; // 15
```

A better version would be:

```c++
#define SQ(a) (a) * (a)
cout << SQ(3+3) << "\n";
// corresponds to:
cout << (3+3)*(3+3) << "\n"; // 36
```
