// https://www.spoj.com/problems/EDIST/
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
const int N = 1e6 + 7;
string a, b;
int memo[2000][2000];

int edit_distance(int i, int j) {
  if (i == a.size() && j == b.size())
    return 0;
  if (i == a.size())
    return b.size() - j;
  if (j == b.size())
    return a.size() - i;

  if (memo[i][j] != -1)
    return memo[i][j];
  int ans = -1;
  if (a[i] != b[j])
    ans = 1 + min(min(edit_distance(i + 1, j), edit_distance(i, j + 1)),
                  edit_distance(i + 1, j + 1));
  else {
    ans = edit_distance(i + 1, j + 1);
  }
  return memo[i][j] = ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    memset(memo, -1, sizeof(memo));
    cout << edit_distance(0, 0) << endl;
  }
  return 0;
}