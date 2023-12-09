#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code
    stops.push_back(dist);
    int len = stops.size();
    int canReach = tank;
    int stop = 0;
    int refills = 0;
    while (stop < len)
    {
        while (stop < len && stops[stop] <= canReach)
        {
            stop += 1;
        }
        if (stop == 0 || stops[stop - 1] + tank < stops[stop])
        {
            return -1;
        }
        if (stop == len)
        {
            return refills;
        }
        canReach = stops[stop - 1] + tank;
        refills += 1;
    }

    return refills;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
