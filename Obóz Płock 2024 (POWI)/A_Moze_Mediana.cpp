#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int drogi[1002][1002], n, maks_mediana;
int dynamik[1002][1002];

bool czy_mediana(int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dynamik[i][j] = max(dynamik[i - 1][j], dynamik[i][j - 1]) + (drogi[i][j] >= m);
        }
    }
    return dynamik[n][n] > n - 1;
}

int bin_sirch(int pocz, int kon)
{
    int srod;
    while (pocz + 1 < kon)
    {
        srod = (pocz + kon) / 2;
        if (czy_mediana(srod))
            pocz = srod;

        else
            kon = srod - 1;
    }
    if (czy_mediana(kon)) return kon;
    return pocz;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int up = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> drogi[i][j];
            up = max(up, drogi[i][j]);
        }
    }
    cout << bin_sirch(1, up);
    return 0;
}