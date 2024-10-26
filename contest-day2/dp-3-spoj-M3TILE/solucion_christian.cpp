// https://www.spoj.com/problems/M3TILE/
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
  int dp[31];
  dp[0] = 1;
  dp[1] = 0;
  dp[2] = 3;
  dp[3] = 0;
  for (int i = 4; i < 31; i++) {
    dp[i] = dp[i - 2] * 4 - dp[i - 4];
  }

  int n;
  while (1) {
    cin >> n;
    if (n == -1)
      break;
    cout << dp[n] << endl;
  }
  return 0;
}