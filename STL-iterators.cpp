/*
================================= STL ITERATOR DEMOS ===================================

This file focuses on iterator types, utilities, and adapters that every C++
programmer should know when working with the STL. Covered topics:
- Raw, const, reverse, and iterator category constraints
- Iterator utility helpers: advance, next, prev, distance
- Iterator adapters: inserters, stream iterators
- Demonstrating how iterator choices impact algorithms

Uncomment the desired demo inside `main()` to experiment.

==========================================================================================
*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

/* ITERATOR BASICS */
void iteratorBasics() {
    vector<int> data = {10, 20, 30, 40, 50};

    cout << "Mutable traversal via iterators: ";
    for (auto it = data.begin(); it != data.end(); ++it) {
        *it += 1;
        cout << *it << " ";
    }
    cout << endl;

    cout << "Const traversal prevents mutation: ";
    for (auto cit = data.cbegin(); cit != data.cend(); ++cit) {
        cout << *cit << " ";
    }
    cout << endl;

    cout << "Reverse traversal: ";
    for (auto rit = data.rbegin(); rit != data.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    array<int, 4> arr = {1, 2, 3, 4};
    auto first = arr.begin();
    auto last = arr.end();
    cout << "Distance on random-access iterators = " << distance(first, last) << endl;

    forward_list<int> fl = {1, 2, 3, 4};
    // forward_list iterators are single-pass, so distance is still valid but advance is linear.
    auto flIt = fl.begin();
    advance(flIt, 3);
    cout << "Advance on forward_list lands at: " << *flIt << endl;
}

/* ITERATOR UTILITIES */
void iteratorUtilities() {
    vector<int> nums = {5, 10, 15, 20, 25, 30};
    auto it = nums.begin();

    advance(it, 3); // move iterator forward N steps
    cout << "Value after advance(it, 3): " << *it << endl;

    auto prevIt = prev(it, 2);
    auto nextIt = next(it);
    cout << "prev(it, 2) -> " << *prevIt << ", next(it) -> " << *nextIt << endl;

    auto middle = nums.begin();
    advance(middle, nums.size() / 2);
    cout << "Middle element via iterator arithmetic: " << *middle << endl;

    cout << "distance(begin, end) = " << distance(nums.begin(), nums.end()) << endl;
}

/* ITERATOR ADAPTERS */
void iteratorAdapters() {
    vector<int> values = {1, 2, 3};

    // Inserters bridge algorithms with containers lacking push_back
    list<int> lst = {10, 20};
    copy(values.begin(), values.end(), back_inserter(lst));
    cout << "After back_inserter copy into list: ";
    for (int n : lst) cout << n << " ";
    cout << endl;

    vector<int> doubled;
    transform(values.begin(), values.end(),
              front_inserter(doubled), [](int x) { return x * 2; });
    cout << "front_inserter on vector (prepends via insert): ";
    for (int n : doubled) cout << n << " ";
    cout << endl;

    // Stream iterators treat IO streams as containers
    istringstream iss("4 8 15 16 23 42");
    vector<int> streamData;
    copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter(streamData));
    cout << "Data read via istream_iterator: ";
    copy(streamData.begin(), streamData.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Move iterator forwards and backwards using iterator traits
    auto beginIt = streamData.begin();
    auto endIt = streamData.end();
    if (beginIt != endIt) {
        advance(endIt, -1); // works for random-access iterators
        cout << "Last element via manual advance: " << *endIt << endl;
    }
}

int main() {
    // iteratorBasics();
    // iteratorUtilities();
    // iteratorAdapters();

    return 0;
}

