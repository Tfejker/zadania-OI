#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k, begin, end;
    string garden;
    char previous_flower = 'N';
    cin >> n >> garden >> k;
    int counter_N = 0, counter_R = 0, disorder = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> begin >> end;
        begin--, end--;
        disorder = 0;
        counter_N = 0, counter_R = 0;
        while (garden[end] == 'R')
            end--;
        for (int j = end; j >= begin; j--)
        {
            if (previous_flower == garden[j] && garden[j] == 'N')
                counter_N++;
            if (previous_flower == garden[j] && garden[j] == 'R')
                counter_R++;
            if (previous_flower != garden[j] && garden[j] == 'R')
                previous_flower = 'R', counter_R++;
            if (previous_flower != garden[j] && garden[j] == 'N')
            {
                disorder += (counter_N * counter_R);
                counter_N, counter_R = 0;
                previous_flower = 'N';
                counter_N++;
            }
        }
        if (previous_flower == 'R')
            disorder += (counter_N * counter_R);
        cout << disorder << endl;
    }
    return 0;
}