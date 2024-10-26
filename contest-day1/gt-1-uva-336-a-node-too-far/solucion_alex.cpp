// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=272
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#define vi vector<int>
using namespace std;

class Solver {
public:
  unordered_map<int, vi> g;

  Solver(const unordered_map<int, vi> &graph) : g(graph) {}

  int solve(int s, int ttl) {
    queue<int> q;
    q.push(s);

    unordered_map<int, int> dist;
    dist[s] = 0;

    int numReachableNodes = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      int nextDist = dist[u] + 1;
      if (nextDist > ttl)
        continue;

      for (int v : g[u]) {
        if (dist.find(v) != dist.end())
          continue;

        dist[v] = nextDist;
        q.push(v);
        numReachableNodes += 1;
      }
    }

    return g.size() - numReachableNodes - 1;
  }
};

int main() {
  iostream::sync_with_stdio(false);

  int caseNo = 1;
  while (true) {
    int nc;
    cin >> nc;
    if (nc == 0)
      break;

    unordered_map<int, vi> g;
    for (int i = 0; i < nc; ++i) {
      int a, b;
      cin >> a >> b;

      g[a].push_back(b);
      g[b].push_back(a);
    }

    Solver solver(g);

    int s, ttl;
    while (true) {
      cin >> s >> ttl;
      if (s == 0 && ttl == 0)
        break;

      int ans = solver.solve(s, ttl);
      cout << "Case " << caseNo++ << ": " << ans
           << " nodes not reachable from node " << s << " with TTL = " << ttl
           << "." << endl;
    }
  }

  return 0;
}
