#include <iostream>
#include <cstring>
#define ll long long int
using std::cout;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    return current % 10;
}

ll fib(ll f[], ll n)
{
    // 0th and 1st number of
    // the series are 0 and 1
    f[0] = 0;
    f[1] = 1;
 
    // Add the previous 2 numbers 
    // in the series and store 
    // last digit of result
    for (ll i = 2; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 10;
 
    return f[n];
}

int get_fibonacci_last_digit_fast(int n) {
	ll f[60] = {0};
	fib(f, 60);
	return f[n%60];
}

int main() {
    int n;
    std::cin >> n;
 //   int c = get_fibonacci_last_digit_naive(n);
  	int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
