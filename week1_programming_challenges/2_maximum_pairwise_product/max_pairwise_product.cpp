#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = std::max(max_product,
                                   numbers[first] * 1LL * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();
    int maxIndex1 = -1, maxIndex2 = -1;
    for (int i = 0; i < n; ++i)
    {
        if (maxIndex1 == -1 || (numbers[i] > numbers[maxIndex1]))
        {
            maxIndex1 = i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (i != maxIndex1 && (maxIndex2 == -1 || numbers[i] > numbers[maxIndex2]))
        {
            maxIndex2 = i;
        }
    }

    return (numbers[maxIndex1] * 1LL * numbers[maxIndex2]);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
