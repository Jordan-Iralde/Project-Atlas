#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    // Code to measure
    for (int i = 0; i < 1000000; i++);

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << "Execution Time: "
        << duration.count()
        << " microseconds";
}