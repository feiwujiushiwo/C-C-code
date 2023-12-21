#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>& distances) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    distances[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj_list[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int dataset = 1;
    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        vector<vector<int>> adj_list(n + 1);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        cout << dataset << endl;
        dataset++;

        for (int i = 1; i <= n; ++i) {
            vector<bool> visited(n + 1, false);
            vector<int> distances(n + 1, -1);
            bfs(i, adj_list, visited, distances);

            int count = 0;
            for (int j = 1; j <= n; ++j) {
                if (distances[j] <= 6 && distances[j] != -1) {
                    count++;
                }
            }

            double percentage = (static_cast<double>(count) / n) * 100;
            cout << fixed << setprecision(2) << i << ": " << percentage << "%" << endl;
        }
    }

    return 0;
}
