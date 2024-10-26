// https://www.spoj.com/problems/WACHOVIA/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Función para resolver el problema de la mochila
int knapsack(int K, const vector<pair<int, int>> &bags) {
  int M = bags.size();
  vector<int> dp(K + 1, 0); // Vector de DP para almacenar los valores máximos

  // Proceso de programación dinámica
  for (int i = 0; i < M; ++i) {
    int weight = bags[i].first;
    int value = bags[i].second;

    // Recorremos la capacidad desde K hacia atrás para evitar el reuso de la
    // misma bolsa
    for (int j = K; j >= weight; --j) {
      dp[j] = max(dp[j], dp[j - weight] + value);
    }
  }

  return dp[K]; // El valor máximo que podemos robar con capacidad K
}

int dp[51][1001]; // Matriz de DP para almacenar los valores máximos
int knapsackMatrix(int capacity, const vector<pair<int, int>> &bags) {
  int n = bags.size();
  // Inicializar matriz de DP
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 0;
  }

  for (int j = 0; j <= capacity; ++j) {
    dp[0][j] = 0;
  }

  // Proceso de programación dinámica
  for (int i = 1; i <= n; ++i) {
    int weight = bags[i - 1].first;
    int value = bags[i - 1].second;
    for (int j = 1; j <= capacity; ++j) {
      dp[i][j] = dp[i - 1][j]; // No tomar la bolsa
      if (j >= weight) {
        // Tomar la bolsa si se puede
        dp[i][j] = max(dp[i][j], dp[i - 1][j - weight] + value);
      }
    }
  }

  return dp[n][capacity]; // El valor máximo que podemos robar con capacidad K
}

int main() {
  int N; // Número de instancias
  cin >> N;

  while (N--) {
    int K, M; // K: Capacidad máxima, M: Número de bolsas
    cin >> K >> M;

    vector<pair<int, int>> bags(M); // Vector para almacenar las bolsas

    for (int i = 0; i < M; ++i) {
      int A, B; // A: Peso, B: Valor
      cin >> A >> B;
      bags[i] = {A, B};
    }

    // Llamada a la función knapsack para resolver la instancia
    // int max_value = knapsack(K, bags);
    int max_value = knapsackMatrix(K, bags);
    cout << "Hey stupid robber, you can get " << max_value << "." << endl;
  }

  return 0;
}
