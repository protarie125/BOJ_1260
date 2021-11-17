#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

using Nbd = map<int, vector<int>>;

vector<bool> visited;
void dfs(Nbd& nbd, int V) {
    cout << V << ' ';
    visited[V - 1] = true;

    for (const auto& x : nbd[V])
    {
        if (!visited[x - 1])
            dfs(nbd, x);
    }
}

void bfs(Nbd& nbd, int N, int V) {
    queue<int> q{};

    q.push(V);
    visited[V - 1] = true;

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        cout << f << ' ';

        for (auto x : nbd[f])
        {
            if (!visited[x - 1]) {
                q.push(x);
                visited[x - 1] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    Nbd nbd{};
    for (int i = 1; i <= N; ++i)
    {
        nbd.insert({ i, vector<int>{} });
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;

        nbd[a].push_back(b);
        nbd[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(nbd[i].begin(), nbd[i].end());
    }

    visited = vector<bool>(N, false);
    dfs(nbd, V);
    cout << '\n';

    visited = vector<bool>(N, false);
    bfs(nbd, N, V);

    return 0;
}