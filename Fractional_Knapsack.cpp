#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item {
    string name;
    double value;
    double weight;
};

int main() {
    int n;
    cout << "Enter the number of items:\n";
    cin >> n;

    double capacity;
    cout << "Enter the capacity of the knapsack:\n";
    cin >> capacity;

    vector<Item> items;

    for (int i = 0; i < n; ++i) {
        Item current;

        cout << "Enter the name for item " << i + 1 << ":\n";
        cin >> current.name;

        cout << "Enter the value for item " << i + 1 << ":\n";
        cin >> current.value;

        cout << "Enter the weight for item " << i + 1 << ":\n";
        cin >> current.weight;

        items.push_back(current);
    }

    sort(items.begin(), items.end(),
         [](const Item& left, const Item& right) {
             return left.value / left.weight >
                    right.value / right.weight;
         });

    double remainingCapacity = capacity;
    double totalValue = 0.0;

    for (const Item& item : items) {
        if (item.weight <= remainingCapacity) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            double fraction = remainingCapacity / item.weight;
            totalValue += fraction * item.value;
            remainingCapacity = 0.0;
            break;
        }
    }

    cout << fixed << setprecision(2)
         << "Maximum value in knapsack: " << totalValue << '\n';

    return 0;
}