#include <iostream>
#include <string.h>
#define SZ 2

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

void multiply(long long F[][SZ], long long M[][SZ], long long m)
{
    long long x = ((F[0][0] % m * 1LL * M[0][0] % m) % m + (F[0][1] % m * 1LL * M[1][0] % m) % m) % m;
    long long y = ((F[0][0] % m * 1LL * M[0][1] % m) % m + (F[0][1] % m * 1LL * M[1][1] % m) % m) % m;
    long long z = ((F[1][0] % m * 1LL * M[0][0] % m) % m + (F[1][1] % m * 1LL * M[1][0] % m) % m) % m;
    long long w = ((F[1][0] % m * 1LL * M[0][1] % m) % m + (F[1][1] % m * 1LL * M[1][1] % m) % m) % m;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void print(long long F[][SZ])
{
    for (int i = 0; i < SZ; ++i)
    {
        for (int j = 0; j < SZ; ++j)
        {
            std::cout << F[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

long long power(long long F[][SZ], long long n, long long m)
{
    long long M[SZ][SZ];
    memset(M, 0LL, sizeof(M));
    M[0][0] = 1LL;
    M[0][1] = 1LL;
    M[1][0] = 1LL;
    while (n > 0)
    {
        if (n % 2)
        {
            multiply(M, F, m);
        }
        multiply(F, F, m);
        // print(M);
        n /= 2;
    }
    return M[0][0] % m;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    long long F[SZ][SZ];
    memset(F, 0LL, sizeof(F));
    if (n <= 1)
        return n % m;

    F[0][0] = 1LL;
    F[0][1] = 1LL;
    F[1][0] = 1LL;
    return power(F, n - 2, m);
}

int main()
{

    long long n, m;
    std::cin >> n >> m;

    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
