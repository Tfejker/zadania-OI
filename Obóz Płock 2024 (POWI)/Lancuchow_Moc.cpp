#include <iostream>

int color_rel_count[1000002];

int main()
{
    std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int chain[1000002], required_number[1000002], required_color[1000002];
    int n, m, c, i, nneeded, nexcess = 0, npretty = 0;
    std::cin >> n >> m;
    nneeded = m;

    for (i = 0; i < m; ++i)
        std::cin >> required_number[i];
    for (i = 0; i < m; ++i)
    {
        std::cin >> c;
        color_rel_count[c] = -required_number[i];
    }
    for (i = 0; i < n; ++i)
        std::cin >> chain[i];

    int beg = 0, end = 0;
    while (end < n)
    {
        if (color_rel_count[chain[end]]++ == 0)
            ++nexcess;
        if (color_rel_count[chain[end++]] == 0)
            --nneeded;
        while (nexcess > 0)
        {
            if (color_rel_count[chain[beg]]-- == 0)
                ++nneeded;
            if (color_rel_count[chain[beg++]] == 0)
                --nexcess;
        }
        if (nneeded == 0)
            ++npretty;
    }
    std::cout << npretty << std::endl;
    return 0;
}