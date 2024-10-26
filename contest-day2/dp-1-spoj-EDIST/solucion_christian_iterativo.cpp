// https://www.spoj.com/problems/EDIST/
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
const int N = 1e6 + 7;
string a, b;

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0)
          dp[i][j] = j;
        else if (j == 0)
          dp[i][j] = i;
        else if (a[i - 1] == b[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
      }
    }
    cout << dp[n][m];
  }
  return 0;
}