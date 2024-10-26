// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1446
#include <iostream>
#include <queue>
#include <vector>
#define vi vector<int>
using namespace std;

const int UNSET = -1;

class Solver {
public:
  int n;
  vector<vi> g;
  vi color;

  Solver(const vector<vi> &g) : n(g.size()), g(g), color(n, UNSET) {}

  int solve() {
    int ans = 0;
    for (int u = 0; u < n; ++u) {
      if (color[u] == UNSET) {
        ans += countMaxBipartiteGroupSize(u);
      }
    }
    return ans;
  }

  int countMaxBipartiteGroupSize(int s) {
    queue<int> q;
    q.push(s);

    int size[2] = {1, 0};
    color[s] = 0;

    bool isBipartite = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto &v : g[u]) {
        if (color[v] == UNSET) {
          color[v] = 1 - color[u];
          ++size[color[v]];
          q.push(v);
        } else if (color[u] == color[v]) {
          isBipartite = false;
        }
      }
    }

    return isBipartite ? max(size[0], size[1]) : 0;
  }
};

int main() {
  iostream::sync_with_stdio(false);

  int m;
  cin >> m;

  while (m--) {
    int n;
    cin >> n;

    vector<vi> g(n);
    for (int i = 0; i < n; ++i) {
      int p;
      cin >> p;

      for (int j = 0; j < p; ++j) {
        int i2;
        cin >> i2;
        --i2;

        g[i].push_back(i2);
        g[i2].push_back(i);
      }
    }

    Solver solver(g);
    int ans = solver.solve();
    cout << ans << endl;
  }

  return 0;
}
