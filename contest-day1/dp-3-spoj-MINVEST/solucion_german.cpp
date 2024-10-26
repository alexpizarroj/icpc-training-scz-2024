// https://www.spoj.com/problems/MINVEST/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Función que resuelve el problema de la mochila sin límites
int KnapsackUnlimited(int capacity, vector<int> &weights, vector<int> &values,
                      int n) {
  // dp[i] almacenará el valor máximo para una capacidad de i
  vector<int> dp(capacity + 1, 0);

  // Llenamos el arreglo dp de abajo hacia arriba
  for (int j = 0; j < n; ++j) {
    for (int i = weights[j]; i <= capacity; ++i) {
      dp[i] = max(dp[i], dp[i - weights[j]] + values[j]);
    }
  }

  // El valor máximo para la capacidad `capacity` está en dp[capacity]
  return dp[capacity];
}

int main() {
  int N;
  cin >> N; // Número de casos de prueba

  while (N--) {
    int initialCapital, years;
    cin >> initialCapital >> years;

    int d; // Número de bonos disponibles
    cin >> d;

    const int RATIO = 1000;
    vector<int> values(d);  // valores de los intereses anuales de los bonos
    vector<int> weights(d); // valores de los bonos

    // Leer los valores y los intereses de los bonos
    for (int i = 0; i < d; ++i) {
      cin >> weights[i] >> values[i];
      weights[i] = weights[i] / RATIO;
    }

    // Simulamos el proceso de inversión para cada año
    for (int i = 0; i < years; ++i) {
      int maxValue =
          KnapsackUnlimited(initialCapital / RATIO, weights, values, d);
      initialCapital += maxValue; // Sumamos el interés obtenido al capital
    }

    // Mostrar el capital final después de todos los años
    cout << initialCapital << endl;
  }

  return 0;
}

/*
// TIME LIMIT EXCEEDED
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Función que resuelve el problema de la mochila sin límites
int KnapsackUnlimited(int capacity, vector<int>& weights, vector<int>& values,
int n) {
    // dp[i] almacenará el valor máximo para una capacidad de i
    vector<int> dp(capacity + 1, 0);

    // Llenamos el arreglo dp de abajo hacia arriba
    for (int j = 0; j < n; ++j) {
        for (int i = weights[j]; i <= capacity; ++i) {
            dp[i] = max(dp[i], dp[i - weights[j]] + values[j]);
        }
    }

    // El valor máximo para la capacidad `capacity` está en dp[capacity]
    return dp[capacity];
}

int main() {
    int N;
    cin >> N;  // Número de casos de prueba

    while (N--) {
        int initialCapital, years;
        cin >> initialCapital >> years;

        int d;  // Número de bonos disponibles
        cin >> d;

        vector<int> values(d);   // valores de los intereses anuales de los
bonos vector<int> weights(d);  // valores de los bonos

        // Leer los valores y los intereses de los bonos
        for (int i = 0; i < d; ++i) {
            cin >> weights[i] >> values[i];
        }

        // Simulamos el proceso de inversión para cada año
        for (int i = 0; i < years; ++i) {
            int maxValue = KnapsackUnlimited(initialCapital, weights, values,
d); initialCapital += maxValue;  // Sumamos el interés obtenido al capital
        }

        // Mostrar el capital final después de todos los años
        cout << initialCapital << endl;
    }

    return 0;
}
*/