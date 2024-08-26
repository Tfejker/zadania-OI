#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;



class Graph {
public:
    Graph(int size) {
        graph.resize(size + 1);
        distances.resize(size + 1, LLONG_MAX);
    }

    void addEdge(int a, int b, int c) {
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    long long dijkstra(int start, int end) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> queue;
        fill(distances.begin(), distances.end(), LLONG_MAX);
        distances[start] = 0;
        queue.push(make_pair(0, start));

        while (!queue.empty()) {
            int node = queue.top().second;
            long long current_distance = queue.top().first;
            queue.pop();

            if (current_distance > distances[node])
                continue;

            for (const std::pair<int, int>& neighbor : graph[node]) {
                int neighbor_node = neighbor.first;
                long long weight = neighbor.second;
                long long new_distance = distances[node] + weight;

                if (new_distance < distances[neighbor_node]) {
                    distances[neighbor_node] = new_distance;
                    queue.push(make_pair(new_distance, neighbor_node));
                }
            }
        }

        return distances[end];
    }

private:
    vector<vector<pair<int, int>>> graph;
    vector<long long> distances;
};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    bool is_neg_infty = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < 0) is_neg_infty = true;
        graph.addEdge(a, b, c);
    }

    if (is_neg_infty) cout << "-oo" << endl;
    else {

    int start_node = 1; // Assuming the source node is 1
    long long shortest_distance = graph.dijkstra(start_node, n);

    if (shortest_distance == LLONG_MAX)
        cout << "NIE" << endl;
    else
        cout << shortest_distance << endl;
    }

    return 0;
}