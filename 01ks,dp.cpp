#include <iostream>
using namespace std;

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]]+values[i - 1] );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    int values[n];
    int weights[n];

    cout << "Enter the values of items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << "Enter the weights of items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int maxVal = knapsack(capacity, weights, values, n);
    cout << "Maximum value that can be obtained: " << maxVal << endl;

    return 0;
}

//o(n*w)