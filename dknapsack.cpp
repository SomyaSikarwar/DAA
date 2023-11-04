#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weight[], int profit[], int n) {
    int i, w;
    int Knapsack[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                Knapsack[i][w] = 0;
            else if (weight[i - 1] <= w)
                Knapsack[i][w] = max(Knapsack[i - 1][w], Knapsack[i - 1][w - weight[i - 1]] + profit[i - 1]);
            else
                Knapsack[i][w] = Knapsack[i - 1][w];
        }
    }

    cout << "\nMatrix:\n";
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            cout << " " << Knapsack[i][w];
        }
        cout << endl;
    }
    
     return Knapsack[n][capacity];

}
int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;
    int weight[n], profit[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter profit of item" << i + 1 << ": ";
        cin >> profit[i];
        cout << "Enter weight of item" << i + 1 << ": ";
        cin >> weight[i];
    }
    cout << "\nValue: " << knapsack(capacity, weight, profit, n) << endl;


   
}
