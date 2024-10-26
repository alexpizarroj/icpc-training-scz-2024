// https://www.spoj.com/problems/LKS/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int K, N;
  // Leer K (capacidad máxima) y N (número de ítems)
  cin >> K >> N;

  vector<int> values(N);
  vector<int> weights(N);

  // Leer los valores y los pesos de los ítems
  for (int i = 0; i < N; ++i) {
    cin >> values[i] >> weights[i];
  }

  // Programación dinámica para resolver el problema
  /*
  // Crear una tabla para almacenar los valores máximos
  //vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));

  for (int i = 1; i <= N; ++i) {
      for (int w = 1; w <= K; ++w) {
          // Si el peso del ítem actual es menor o igual a w, evaluamos si
  tomarlo o no if (weights[i - 1] <= w) { dp[i][w] = max(dp[i - 1][w], dp[i -
  1][w - weights[i - 1]] + values[i - 1]); } else { dp[i][w] = dp[i - 1][w];  //
  Si no cabe, no lo tomamos
          }
      }
  }

  // El valor máximo estará en dp[N][K]
  cout << dp[N][K] << endl;
  */

  int n = values.size();
  int capacity = K;
  vector<int> dp(capacity + 1, 0); // Inicializamos el arreglo dp con ceros

  for (int i = 0; i < n; i++) {
    for (int j = capacity; j >= weights[i]; j--) {
      dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
    }
  }

  cout << dp[capacity] << endl;

  return 0;
}
