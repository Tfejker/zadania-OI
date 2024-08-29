#include <iostream>
#include <algorithm>
#include <map>

std::map<long long, bool> is_ball_excluded; // int -> bool

long long balls[200001];

int main()
{
    std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i)
        std::cin >> balls[i];

    std::sort(balls, balls + n);
    int n_balls = 0;
    for (int i = 0; i < n; i++)
    {
        if (!is_ball_excluded[balls[i]]) // i -> balls[i]
        {
            std::cout << is_ball_excluded[balls[i]] << " " << "taking ball: " << balls[i] << std::endl;
            n_balls++;
            is_ball_excluded[balls[i] * k] = true; // i -> balls[i]
        }
    }
    std::cout << n_balls << std::endl;
    return 0;
}