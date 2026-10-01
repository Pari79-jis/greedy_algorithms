# greedy_algorithms
Fractional Knapsack in C++

A simple C++ implementation of the Fractional Knapsack greedy algorithm. Each item has a name, value, and weight. Unlike 0/1 Knapsack, items can be divided, so the solution may take a fraction of an item.
How the algorithm works

    Calculate each item's value per unit of weight: value / weight.
    Sort items from highest to lowest value per unit of weight.
    Take each item whole while it fits.
    If the next item does not fit, take the fraction that fills the remaining capacity.

Build and run

Save the C++ source as fractional_knapsack.cpp beside this README.
g++ -std=c++17 -Wall -Wextra -pedantic fractional_knapsack.cpp -o fractional_knapsack
./fractional_knapsack
Input format

Enter:

    The number of items.
    The knapsack capacity.
    For each item, its name, value, and weight, in that order.

Item names must be a single word. The program assumes item weights are positive and values and capacity are nonnegative.
Sample input
3
50
A
60
10
B
100
20
C
120
30
Sample output
Enter the number of items:
Enter the capacity of the knapsack:
Enter the name for item 1:
Enter the value for item 1:
Enter the weight for item 1:
Enter the name for item 2:
Enter the value for item 2:
Enter the weight for item 2:
Enter the name for item 3:
Enter the value for item 3:
Enter the weight for item 3:
Maximum value in knapsack: 240.00

For this example, the algorithm takes items A and B fully, then takes 20 of C's 30 weight units.
Complexity

    Time: O(n log n) for sorting, followed by an O(n) scan.
    Space: O(n) to store the items.
# Activity Selection Problem (C++)

A C++ implementation of the classic **Activity Selection Problem** using a **Greedy Algorithm** approach. 

This program determines the maximum number of mutually compatible activities that can be performed by a single resource (e.g., a room or hall) given their start and finish times.

## 📌 Features
- **Custom Activity Input:** Allows custom activity names (supports spaces, numbers, and special characters).
- **Greedy Strategy:** Sorts activities by finish time (O(N \log N)) to maximize available time for subsequent tasks.
- **Direct Output Sequence:** Formats and prints the selected sequence as a clean chain (`Activity A -> Activity B`).
- **Duplicate & Edge Case Safe:** Gracefully filters out overlapping duplicate times using `std::sort` / `std::stable_sort`.

## 🛠️️ How It Works
1. **Sort:** Activities are ordered in ascending order based on their **finish time**.
2. **Select First:** The activity that finishes earliest is selected first.
3. **Iterate & Filter:** For each remaining activity, if its `start` time is greater than or equal to the `finish` time of the last selected activity (`last_finish_time <= current.start`), it is added to the optimal sequence.

## 🚀 Complexity Analysis
- **Time Complexity:** O(N \log N) due to sorting $N$ activities.
- **Space Complexity:** O(N) for storing N activities in a vector.

## 💻 Sample Input & Output

### Input
```text
4
Lab 1
1
4
Room 101
3
5
Hall A
0
6
Lab 2B
5
7
