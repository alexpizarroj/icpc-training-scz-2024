// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1246
#include <algorithm>
#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

class Solver {
public:
  int n;
  vector<vi> g;
  vector<bool> visited;
  vi toposort;

  Solver(int n, const vector<vi> &graph) : n(n), g(graph), visited(n, false) {}

  void solve() {
    for (int u = 0; u < n; ++u) {
      if (!visited[u]) {
        dfs(u);
      }
    }
    reverse(toposort.begin(), toposort.end());

    for (int i = 0; i < n; ++i) {
      cout << (i > 0 ? " " : "") << toposort[i];
    }
    cout << endl;
  }

  void dfs(int u) {
    visited[u] = true;

    for (auto &v : g[u]) {
      if (!visited[v]) {
        dfs(v);
      }
    }

    toposort.push_back(u + 1);
  }
};

int main() {
  iostream::sync_with_stdio(false);

  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    vector<vi> g(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      g[a - 1].push_back(b - 1);
    }

    Solver solver(n, g);
    solver.solve();
  }

  return 0;
}
