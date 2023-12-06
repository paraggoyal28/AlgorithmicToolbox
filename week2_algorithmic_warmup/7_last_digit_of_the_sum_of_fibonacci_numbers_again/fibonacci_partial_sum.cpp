#include <iostream>
#include <vector>
#include <string.h>
#define mod 10
#define SZ 2
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

void multiply(long long M[][SZ], long long F[][SZ])
{
    long long x = ((M[0][0] % mod * 1LL * F[0][0] % mod) % mod + (M[0][1] % mod * 1LL * F[1][0] % mod) % mod) % mod;
    long long y = ((M[0][0] % mod * 1LL * F[0][1] % mod) % mod + (M[0][1] % mod * 1LL * F[1][1] % mod) % mod) % mod;
    long long z = ((M[1][0] % mod * 1LL * F[0][0] % mod) % mod + (M[1][1] % mod * 1LL * F[1][0] % mod) % mod) % mod;
    long long w = ((M[1][0] % mod * 1LL * F[0][1] % mod) % mod + (M[1][1] % mod * 1LL * F[1][1] % mod) % mod) % mod;
    M[0][0] = x;
    M[0][1] = y;
    M[1][0] = z;
    M[1][1] = w;
}

int power(long long F[][SZ], long long n)
{
    long long M[SZ][SZ];
    memset(M, 0, sizeof(M));
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            multiply(M, F);
        }
        multiply(F, F);
        n /= 2;
    }

    return (M[0][0] - 1 + mod) % 10;
}

int fibonacci_sum_fast(long long n)
{
    if (n <= 1)
    {
        return n;
    }
    long long F[SZ][SZ];
    memset(F, 0, sizeof(F));
    F[0][0] = 1;
    F[0][1] = 1;
    F[1][0] = 1;

    return power(F, n);
}

int get_fibonacci_partial_sum_fast(long long from, long long to)
{
    if (from == 0)
        return fibonacci_sum_fast(to) % mod;
    return (fibonacci_sum_fast(to) % mod - fibonacci_sum_fast(from - 1) % mod + mod) % mod;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
