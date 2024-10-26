// https://www.spoj.com/problems/MINVEST/
#include <iostream>
#include <unordered_map>
#include <vector>
#define vi vector<int>
using namespace std;

class Solver {
public:
  int startingAmount, years, n;
  const vi &cost, &value;
  unordered_map<int, int> memo;

  Solver(int startingAmount, int years, const vi &cost, const vi &value)
      : startingAmount(startingAmount), years(years), cost(cost), value(value),
        n(cost.size()) {}

  int solve() {
    int capital = startingAmount;
    for (int year = 1; year <= years; ++year) {
      int earnings = dp(capital);
      capital += earnings;
    }
    return capital;
  }

  int dp(int cap) {
    if (cap == 0)
      return 0;

    auto it = memo.find(cap);
    if (it != memo.end())
      return it->second;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (cap >= cost[i]) {
        int opt = dp(cap - cost[i]) + value[i];
        ans = max(ans, opt);
      }
    }

    return memo[cap] = ans;
  }
};

int main() {
  int t;
  cin >> t;

  while (t--) {
    int startingAmount, years;
    cin >> startingAmount >> years;

    int numAvailableBonds;
    cin >> numAvailableBonds;

    vi cost(numAvailableBonds), value(numAvailableBonds);
    for (int i = 0; i < numAvailableBonds; ++i) {
      cin >> cost[i] >> value[i];
    }

    Solver solver(startingAmount, years, cost, value);
    int ans = solver.solve();
    cout << ans << "\n";
  }

  return 0;
}