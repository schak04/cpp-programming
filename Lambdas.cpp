/*
================================= C++ LAMBDA DEMOS ===================================

This file showcases practical lambda usage patterns in C++:
- Basic lambda syntax (captures, return types)
- Capturing by value vs reference
- Mutable lambdas and generalized captures
- Lambdas in algorithms
- Lambdas with std::function, std::bind, and higher-order utilities
- Generic lambdas (C++14+) and constexpr lambdas (C++17+)
- Immediately Invoked Lambda Expressions (IILE) for quick scope work

Uncomment individual demo invocations in `main()` to see behavior.

========================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <numeric>
#include <string>

using namespace std;

/* BASIC LAMBDA SYNTAX */
void basicLambda() {
    auto adder = [](int a, int b) { return a + b; };
    cout << "Lambda sum 3 + 5 = " << adder(3, 5) << endl;

    // Explicit return type
    auto divide = [](double a, double b) -> double {
        if (b == 0.0) throw invalid_argument("division by zero");
        return a / b;
    };
    cout << "Lambda divide 10 / 2 = " << divide(10, 2) << endl;
}

/* CAPTURE MODES */
void captureModes() {
    int x = 10;
    int y = 20;

    auto captureByValue = [x, y]() { return x + y; };
    cout << "Capture by value x+y = " << captureByValue() << endl;

    auto captureByReference = [&x, &y]() {
        x += 1;
        y += 2;
    };
    captureByReference();
    cout << "After capture-by-ref, x = " << x << ", y = " << y << endl;

    // Default capture (by value) but mutate a copy with mutable specifier
    auto mutableCapture = [x]() mutable {
        x *= 2;
        return x;
    };
    cout << "Mutable lambda (local copy doubled) = " << mutableCapture()
         << ", original x still " << x << endl;

    // Initialized capture (C++14)
    auto initialized = [sum = x + y]() {
        cout << "Initialized capture sum = " << sum << endl;
    };
    initialized();
}

/* LAMBDAS + ALGORITHMS */
void lambdasWithAlgorithms() {
    vector<int> data = {4, 2, 6, 1, 3, 5};

    sort(data.begin(), data.end(), [](int a, int b) { return a > b; });
    cout << "Sort descending with lambda comparator: ";
    for (int v : data) cout << v << " ";
    cout << endl;

    auto oddsEnd = remove_if(data.begin(), data.end(),
                             [](int value) { return value % 2 == 0; });
    data.erase(oddsEnd, data.end());
    cout << "After removing even numbers: ";
    for (int v : data) cout << v << " ";
    cout << endl;

    int total = 0;
    for_each(data.begin(), data.end(), [&total](int value) {
        total += value;
    });
    cout << "Sum via lambda capture: " << total << endl;
}

/* GENERIC + CONSTEXPR LAMBDAS */
void genericLambdas() {
    auto genericAdder = [](auto a, auto b) { return a + b; };
    cout << "genericAdder(2, 3) = " << genericAdder(2, 3) << endl;
    cout << "genericAdder(string) = "
         << genericAdder(string("Hello "), string("World")) << endl;

#if __cpp_constexpr >= 201304
    constexpr auto square = [](auto value) constexpr { return value * value; };
    static_assert(square(4) == 16);
    cout << "constexpr lambda square(5) = " << square(5) << endl;
#endif
}

/* HIGHER-ORDER AND BIND */
void higherOrderLambdas() {
    auto makeMultiplier = [](int factor) {
        return [factor](int value) { return factor * value; };
    };

    auto timesFour = makeMultiplier(4);
    cout << "Higher-order lambda timesFour(7) = " << timesFour(7) << endl;

    auto curried = [](auto f) {
        return [f](auto x) {
            return [=](auto y) { return f(x, y); };
        };
    };
    auto add = [](int a, int b) { return a + b; };
    cout << "Curried lambda add(3)(4) = " << curried(add)(3)(4) << endl;

    auto binder = bind(add, placeholders::_1, 100);
    cout << "std::bind with lambda -> " << binder(23) << endl;
}

/* IMMEDIATELY INVOKED LAMBDAS */
void immediateLambda() {
    int result = []() {
        int temp = 5;
        temp *= 10;
        return temp;
    }();
    cout << "IILE result = " << result << endl;
}

int main() {
    // basicLambda();
    // captureModes();
    // lambdasWithAlgorithms();
    // genericLambdas();
    // higherOrderLambdas();
    // immediateLambda();

    return 0;
}

