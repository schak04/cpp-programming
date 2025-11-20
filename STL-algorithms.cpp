/*
================================= STL ALGORITHM DEMOS ===================================

This file highlights essential algorithm families provided by the STL:
- Non-modifying algorithms (find, count, all_of, minmax_element)
- Modifying algorithms (transform, remove_if, rotate)
- Sorting and partitioning (sort, stable_sort, nth_element, partition)
- Numeric algorithms (accumulate, partial_sum, iota, adjacent_difference)
- Set algorithms (set_union, set_intersection) on sorted ranges

Uncomment functions in `main()` to observe results.

==========================================================================================
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <set>

using namespace std;

/* NON-MODIFYING ALGORITHMS */
void nonModifyingAlgorithms() {
    vector<int> data = {3, 6, 9, 12, 15, 18};

    /* std::boolalpha is a C++ I/O manipulator that controls the formatting of boolean values in
    input and output streams. By default, boolean values are displayed as integers (1 for true and 0 for false).
    When std::boolalpha is used, boolean values are displayed as their textual representations: "true" and "false". */
    cout << boolalpha; 
    cout << "all_of multiples of 3? "
         << all_of(data.begin(), data.end(), [](int x) { return x % 3 == 0; }) << endl;
    cout << "any_of > 15? "
         << any_of(data.begin(), data.end(), [](int x) { return x > 15; }) << endl;
    cout << "none_of negative? "
         << none_of(data.begin(), data.end(), [](int x) { return x < 0; }) << endl;

    auto found = find_if(data.begin(), data.end(), [](int x) { return x % 4 == 0; });
    cout << "First element divisible by 4: "
         << (found != data.end() ? to_string(*found) : string("not found")) << endl;

    cout << "Count of numbers > 10: "
         << count_if(data.begin(), data.end(), [](int x) { return x > 10; }) << endl;

    auto [minIt, maxIt] = minmax_element(data.begin(), data.end());
    cout << "minmax_element => min: " << *minIt << ", max: " << *maxIt << endl;
    cout << noboolalpha;
}

/* MODIFYING ALGORITHMS */
void modifyingAlgorithms() {
    vector<int> data = {1, 2, 3, 4, 5, 6};

    transform(data.begin(), data.end(), data.begin(),
              [](int x) { return x * x; });
    cout << "After transform(square): ";
    for (int value : data) cout << value << " ";
    cout << endl;

    auto newEnd = remove_if(data.begin(), data.end(),
                            [](int x) { return x % 2 == 0; });
    data.erase(newEnd, data.end());
    cout << "After remove_if (drop even squares): ";
    for (int value : data) cout << value << " ";
    cout << endl;

    rotate(data.begin(), data.begin() + 1, data.end());
    cout << "After rotate left by 1: ";
    for (int value : data) cout << value << " ";
    cout << endl;
}

/* SORTING AND PARTITIONING */
void sortingAndPartitioning() {
    vector<int> values = {9, 1, 8, 2, 7, 3, 6, 4, 5};

    vector<int> sorted = values;
    sort(sorted.begin(), sorted.end());
    cout << "std::sort ascending: ";
    for (int v : sorted) cout << v << " ";
    cout << endl;

    vector<int> stable = values;
    stable_sort(stable.begin(), stable.end(), [](int a, int b) {
        return (a % 2) < (b % 2); // group by parity, preserve order
    });
    cout << "stable_sort by parity: ";
    for (int v : stable) cout << v << " ";
    cout << endl;

    vector<int> partial = values;
    partial_sort(partial.begin(), partial.begin() + 3, partial.end());
    cout << "partial_sort first 3 smallest: ";
    for (int v : partial) cout << v << " ";
    cout << endl;

    vector<int> nth = values;
    auto nthPos = nth.begin() + nth.size() / 2;
    nth_element(nth.begin(), nthPos, nth.end());
    cout << "nth_element median candidate: " << *nthPos << endl;

    vector<int> partitioned = values;
    partition(partitioned.begin(), partitioned.end(), [](int x) { return x % 2 == 0; });
    cout << "partition by even: ";
    for (int v : partitioned) cout << v << " ";
    cout << endl;
}

/* NUMERIC ALGORITHMS */
void numericAlgorithms() {
    vector<int> numbers(5);
    iota(numbers.begin(), numbers.end(), 1);
    cout << "iota -> ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "accumulate sum: " << sum << endl;

    vector<int> partial(numbers.size());
    partial_sum(numbers.begin(), numbers.end(), partial.begin());
    cout << "partial_sum -> ";
    for (int n : partial) cout << n << " ";
    cout << endl;

    vector<int> adjDiff(numbers.size());
    adjacent_difference(numbers.begin(), numbers.end(), adjDiff.begin());
    cout << "adjacent_difference -> ";
    for (int n : adjDiff) cout << n << " ";
    cout << endl;

    vector<int> weights = {2, 2, 2, 2, 2};
    int dot = inner_product(numbers.begin(), numbers.end(), weights.begin(), 0);
    cout << "inner_product with weights -> " << dot << endl;
}

/* SET ALGORITHMS */
void setAlgorithms() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 6, 7};

    vector<int> output;
    output.resize(A.size() + B.size());

    auto unionEnd = set_union(A.begin(), A.end(), B.begin(), B.end(), output.begin());
    cout << "set_union -> ";
    copy(output.begin(), unionEnd, ostream_iterator<int>(cout, " "));
    cout << endl;

    auto interEnd = set_intersection(A.begin(), A.end(), B.begin(), B.end(), output.begin());
    cout << "set_intersection -> ";
    copy(output.begin(), interEnd, ostream_iterator<int>(cout, " "));
    cout << endl;

    auto diffEnd = set_difference(A.begin(), A.end(), B.begin(), B.end(), output.begin());
    cout << "set_difference (A-B) -> ";
    copy(output.begin(), diffEnd, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    // nonModifyingAlgorithms();
    // modifyingAlgorithms();
    // sortingAndPartitioning();
    // numericAlgorithms();
    // setAlgorithms();

    return 0;
}

