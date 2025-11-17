/*
========================== STL FUNCTORS & UTILITIES DEMOS ===============================

This file demonstrates callable utilities frequently paired with STL containers
and algorithms:
- Custom functors (function objects) with state
- Standard function objects (std::plus, std::less, etc.)
- Lambdas, std::function, std::bind/bind_front
- std::invoke and std::reference_wrapper helpers

Each section is self-contained. Uncomment calls in `main()` to explore.

==========================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <numeric>

using namespace std;

/* Custom functor with state */
struct Multiplier {
    explicit Multiplier(int factor) : factor_(factor) {}
    int operator()(int value) const { return value * factor_; }
private:
    int factor_;
};

void functorBasics() {
    vector<int> values = {1, 2, 3, 4};
    Multiplier timesThree(3);
    transform(values.begin(), values.end(), values.begin(), timesThree);

    cout << "Multiplier functor applied: ";
    for (int v : values) cout << v << " ";
    cout << endl;
}

/* Standard function objects and comparators */
void standardFunctors() {
    vector<int> data = {5, 1, 4, 2, 3};

    sort(data.begin(), data.end(), greater<int>()); // descending sort
    cout << "std::greater sort: ";
    for (int v : data) cout << v << " ";
    cout << endl;

    map<string, int, less<>> wordCounts;
    wordCounts["apple"] = 2;
    wordCounts["banana"] = 5;
    wordCounts["orange"] = 3;

    cout << "Map with transparent comparator (less<>):" << endl;
    for (const auto& [word, count] : wordCounts) {
        cout << word << " -> " << count << endl;
    }
}

/* Lambdas, std::function, and std::bind */
int sumThree(int a, int b, int c) { return a + b + c; }

void callableWrappers() {
    auto lambda = [](int x, int y) { return x * y; };
    cout << "Lambda product 4*6 = " << lambda(4, 6) << endl;

    std::function<int(int, int)> fun = lambda;
    cout << "std::function storing lambda: " << fun(3, 7) << endl;

    auto bound = bind(sumThree, placeholders::_1, 10, placeholders::_2);
    cout << "std::bind with placeholders -> " << bound(5, 15) << endl;

#if __cpp_lib_bind_front
    auto boundFront = bind_front(sumThree, 100);
    cout << "bind_front fixing first param -> " << boundFront(1, 2) << endl;
#else
    auto boundFront = bind(sumThree, 100, placeholders::_1, placeholders::_2);
    cout << "bind emulating bind_front -> " << boundFront(1, 2) << endl;
#endif
}

/* std::invoke and reference_wrapper */
struct Accumulator {
    void add(int value) { total += value; }
    int total = 0;
};

void invokeAndReferences() {
    Accumulator acc;
    vector<int> numbers = {1, 2, 3, 4, 5};

    for_each(numbers.begin(), numbers.end(),
             [&](int n) { std::invoke(&Accumulator::add, &acc, n); });

    cout << "std::invoke member function sum -> " << acc.total << endl;

    vector<reference_wrapper<int>> refs;
    for (int& n : numbers) refs.push_back(n);
    for (int& ref : refs) ref *= 2;

    cout << "Values after modifying via reference_wrapper: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
}

int main() {
    // functorBasics();
    // standardFunctors();
    // callableWrappers();
    // invokeAndReferences();

    return 0;
}

