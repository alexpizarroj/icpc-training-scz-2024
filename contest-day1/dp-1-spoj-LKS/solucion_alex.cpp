// https://www.spoj.com/problems/LKS/
#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

class Solver {
public:
  int n;
  const vi &value, &weight;

  Solver(const vi &value, const vi &weight)
      : value(value), weight(weight), n(value.size()) {}

  int solve(int capacity) {
    vi dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
      for (int w = capacity; w >= weight[i]; w--) {
        dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
      }
    }

    return dp[capacity];
  }
};

int main() {
  iostream::sync_with_stdio(false);

  int k, n;
  cin >> k >> n;

  vi value(n), weight(n);
  for (int i = 0; i < n; ++i) {
    cin >> value[i] >> weight[i];
  }

  Solver solver(value, weight);
  int ans = solver.solve(k);
  cout << ans << endl;

  return 0;
}
