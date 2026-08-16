#include <chrono>
#include <iostream>
#include <thread>
using namespace std;
using namespace std::chrono;

int main()
{
    time_point<steady_clock> start = steady_clock::now();

    // Simulate some work
    this_thread::sleep_for(seconds(2));

    time_point<steady_clock> end = steady_clock::now();

    auto elapsed = duration_cast<milliseconds>(end - start);

    cout << "Elapsed Time: "
        << elapsed.count() << " ms";

    return 0;
}