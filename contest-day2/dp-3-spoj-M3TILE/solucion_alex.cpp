// https://www.spoj.com/problems/M3TILE/
#include <iostream>
using namespace std;

int main() {
  int ans[31] = {1, 0, 3};
  for (int n = 3; n <= 30; ++n) {
    if (n % 2 == 1) {
      ans[n] = 0;
    } else {
      ans[n] = 4 * ans[n - 2] - ans[n - 4];
    }
  }

  int q;
  while (true) {
    cin >> q;
    if (q == -1) {
      break;
    } else {
      cout << ans[q] << endl;
    }
  }
  return 0;
}