// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const pair<int, int> DIRECTIONS[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solver {
public:
  int n;
  vector<string> g;

  Solver(int n, const vector<string> &g) : n(n), g(g) {}

  int solve() {
    int ans = 0;
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        if (g[x][y] == '.')
          continue;
        if (belongsToAliveShip(x, y))
          ans += 1;
      }
    }

    return ans;
  }

  bool belongsToAliveShip(int x, int y) {
    bool alive = g[x][y] == 'x';
    g[x][y] = '.';

    for (auto &[dx, dy] : DIRECTIONS) {
      int x2 = x + dx, y2 = y + dy;
      if (x2 < 0 || x2 >= n)
        continue;
      if (y2 < 0 || y2 >= n)
        continue;
      if (g[x2][y2] == '.')
        continue;

      alive = alive | belongsToAliveShip(x2, y2);
    }

    return alive;
  }
};

int main() {
  iostream::sync_with_stdio(false);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; ++tc) {
    int n;
    cin >> n;

    vector<string> g;
    for (int i = 0; i < n; ++i) {
      string row;
      cin >> row;
      g.push_back(row);
    }

    Solver solver(n, g);
    int ans = solver.solve();
    cout << "Case " << tc << ": " << ans << endl;
  }

  return 0;
}
