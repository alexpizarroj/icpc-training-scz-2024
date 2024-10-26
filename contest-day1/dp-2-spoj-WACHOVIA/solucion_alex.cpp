// https://www.spoj.com/problems/WACHOVIA/
#include <cstring>
#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

const int UNSET = -1;
const int MAX_K = 1000;
const int MAX_M = 50;

class Solver {
public:
  int k, m;
  const vi &weight;
  const vi &value;
  int memo[MAX_M + 1][MAX_K + 1];

  Solver(int k, int m, const vi &weight, const vi &value)
      : k(k), m(m), weight(weight), value(value) {
    memset(memo, UNSET, sizeof(memo));
  }

  int solve() { return dp(m, k); }

  int dp(int n, int cap) {
    if (n == 0)
      return 0;

    int ans = memo[n][cap];
    if (ans == UNSET) {
      int optDontTake = dp(n - 1, cap);

      int idx = n - 1;
      if (cap >= weight[idx]) {
        int optTake = value[idx] + dp(n - 1, cap - weight[idx]);
        ans = max(optTake, optDontTake);
      } else {
        ans = optDontTake;
      }

      memo[n][cap] = ans;
    }

    return ans;
  }
};

int main() {
  iostream::sync_with_stdio(false);

  int n;
  cin >> n;

  while (n--) {
    int k, m;
    cin >> k >> m;

    vi weight(m), value(m);
    for (int i = 0; i < m; ++i) {
      cin >> weight[i] >> value[i];
    }

    Solver solver(k, m, weight, value);
    int ans = solver.solve();
    cout << "Hey stupid robber, you can get " << ans << ".\n";
  }

  return 0;
}
