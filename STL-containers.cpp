/*
================================= STL CONTAINER DEMOS ===================================

C++ STL provides many powerful containers. This file demonstrates usage of:
- array
- vector
- deque
- list
- forward_list
- stack
- queue
- set
- unordered_set
- map
- unordered_map

Each block below is self-contained. Uncomment the relevant section in `main()` to test.

==========================================================================================
*/

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

/* ARRAY */
void arrayExample() {
    // std::array wraps a fixed-size raw array with STL-friendly API
    array<int, 5> arr = {1, 2, 3, 4, 5};
    array<int, 5> other = {10, 20, 30, 40, 50};

    cout << "Array: ";
    for (int i : arr) cout << i << " ";
    cout << "\nSize: " << arr.size()
         << ", First: " << arr.front()
         << ", Last: " << arr.back()
         << ", Element @2 via at(): " << arr.at(2) << endl;

    arr.fill(7); // overwrite every element
    cout << "After fill(7): ";
    for (int i : arr) cout << i << " ";
    cout << "\nRaw pointer via data(): " << arr.data() << endl;

    arr.swap(other); // exchanges contents element-by-element
    cout << "After swap with other: ";
    for (int i : arr) cout << i << " ";
    cout << endl;
}

/* VECTOR */
void vectorExample() {
    // Dynamic array grows automatically and offers random-access iterators
    vector<int> v = {10, 20, 30};
    v.reserve(10);                 // pre-allocate to avoid reallocation
    v.emplace_back(40);            // construct element in-place
    v.insert(v.begin() + 1, 15);   // insert at arbitrary position
    v.erase(v.begin() + 3);        // erase by iterator
    v.pop_back();                  // remove last element

    cout << "Vector: ";
    for (int i : v) cout << i << " ";
    cout << "\nSize: " << v.size()
         << ", Capacity: " << v.capacity()
         << ", Front: " << v.front()
         << ", Back: " << v.back() << endl;

    sort(v.begin(), v.end());      // algorithms interoperate well with vectors
    cout << "Sorted vector: ";
    for (int i : v) cout << i << " ";
    cout << endl;

    auto it = find(v.begin(), v.end(), 20);
    if (it != v.end()) {
        cout << "Found 20 at index " << distance(v.begin(), it) << endl;
    }

    v.shrink_to_fit();
    cout << "Capacity after shrink_to_fit(): " << v.capacity() << endl;
}

/* DEQUE */
void dequeExample() {
    // Double-ended queue supports fast pushes/pops at both ends
    deque<int> dq = {2, 4, 6};
    dq.push_front(1);
    dq.push_back(8);
    dq.emplace_front(0);
    dq.emplace_back(10);
    dq.pop_front();
    dq.pop_back();

    cout << "Deque: ";
    for (int i : dq) cout << i << " ";
    cout << "\nFront: " << dq.front()
         << ", Back: " << dq.back()
         << ", Random access dq[1]: " << dq[1]
         << ", dq.at(2): " << dq.at(2) << endl;
}

/* LIST -> Doubly Linked List */
void listExample() {
    // Doubly-linked list optimized for frequent mid-list insertions/removals
    list<int> l = {10, 20, 30};
    l.push_front(5);
    l.push_back(35);

    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 17);
    l.remove(20);
    l.emplace_back(40);

    list<int> other = {3, 8};
    l.splice(l.begin(), other); // move nodes without copying
    l.sort();                   // requires bidirectional iterators
    l.unique();                 // remove consecutive duplicates
    l.reverse();                // reverse in O(n)

    cout << "List (reversed, unique, sorted before reversing): ";
    for (int i : l) cout << i << " ";
    cout << "\nSize: " << l.size() << endl;
}

/* FORWARD_LIST -> Singly Linked List */
void forwardListExample() {
    // Singly-linked list keeps memory overhead minimal
    forward_list<int> fl = {10, 20, 30};
    fl.push_front(5);

    auto before_begin_it = fl.before_begin(); // iterator preceding first element
    fl.insert_after(before_begin_it, 1);
    auto it = fl.begin();
    advance(it, 3);
    fl.emplace_after(it, 25);
    fl.remove(20);

    forward_list<int> other = {7, 11, 2};
    fl.merge(other); // requires both lists sorted; merges nodes
    fl.sort();       // only container with member sort due to single links

    cout << "Forward List (sorted & merged): ";
    for (int i : fl) cout << i << " ";
    cout << "\nIs other empty after merge? " << boolalpha << other.empty() << noboolalpha << endl;
}

/* STACK */
void stackExample() {
    // Container adaptor that exposes LIFO interface
    stack<int, vector<int>> st;
    st.emplace(1);
    st.emplace(2);
    st.emplace(3);
    cout << "Top of stack: " << st.top() << ", Size: " << st.size() << endl;

    stack<int, vector<int>> other;
    other.push(99);
    st.swap(other);
    cout << "After swap, top: " << st.top() << ", Other top: " << other.top() << endl;
}

/* QUEUE */
void queueExample() {
    // FIFO adaptor; deque is default underlying container
    queue<int, deque<int>> q;
    q.emplace(10); q.emplace(20); q.emplace(30);
    cout << "Front of queue: " << q.front() << ", Back: " << q.back()
         << ", Size: " << q.size() << endl;

    q.pop();
    cout << "After pop, front: " << q.front() << endl;

    queue<int, deque<int>> other;
    other.push(100);
    q.swap(other);
    cout << "After swap, front: " << q.front() << ", Other front: " << other.front() << endl;
}

/* SET -> implemented as Binary Search Trees */
void setExample() {
    // Sorted container with unique keys, backed by balanced tree
    set<int> s = {5, 2, 9, 1, 5};
    s.insert(3);
    s.emplace(7);

    cout << "Set: ";
    for (int i : s) cout << i << " ";
    cout << "\nCount of 5: " << s.count(5) << endl;

    auto lb = s.lower_bound(4); // first element >= 4
    auto ub = s.upper_bound(7); // first strictly > 7
    cout << "Lower bound of 4: " << (lb != s.end() ? to_string(*lb) : "none") << endl;
    cout << "Upper bound of 7: " << (ub != s.end() ? to_string(*ub) : "none") << endl;

    auto it = s.find(2);
    if (it != s.end()) s.erase(it);
    cout << "After erase(2): ";
    for (int i : s) cout << i << " ";
    cout << endl;
}

/* UNORDERED_SET */
void unorderedSetExample() {
    // Hash table offering average O(1) search/insert/erase
    unordered_set<int> us = {5, 2, 9, 1, 5};
    us.insert(3);
    us.emplace(7);

    cout << "Unordered Set: ";
    for (int i : us) cout << i << " ";
    cout << "\nBuckets: " << us.bucket_count()
         << ", Load factor: " << us.load_factor() << endl;

    auto it = us.find(9);
    if (it != us.end()) {
        cout << "Found 9 in bucket " << us.bucket(*it) << endl;
    }

    us.erase(1);
    us.max_load_factor(2.0f); // control threshold before rehash
    us.rehash(16);            // force bucket count
    cout << "After erase(1) + rehash(16): buckets = " << us.bucket_count() << endl;
}

/* MAP */
void mapExample() {
    // Ordered dictionary storing key/value pairs
    map<string, int> m;
    m["apple"] = 5;
    m["banana"] = 2;
    m.insert({"cherry", 7});

    auto [it, inserted] = m.emplace("date", 9);
    cout << "Inserted date? " << boolalpha << inserted << noboolalpha << endl;
    if (!inserted) {
        it->second += 1;
    }

    m.erase("banana");

    cout << "Map (ordered by key):\n";
    for (const auto& [key, value] : m) {
        cout << key << ": " << value << endl;
    }

    auto findIt = m.find("apple");
    if (findIt != m.end()) {
        cout << "Apple count = " << findIt->second << endl;
    }
}

/* UNORDERED_MAP */
void unorderedMapExample() {
    // Hash map with no ordering guarantees but fast average access
    unordered_map<string, int> um;
    um["dog"] = 3;
    um["cat"] = 1;
    um.reserve(8);
    um.insert(make_pair("bird", 8));
    um.insert(make_pair("elephant", 0));
    um.emplace("ant", 4);

    cout << "Unordered Map:\n";
    for (const auto& [animal, count] : um) {
        cout << animal << ": " << count << endl;
    }

    um.erase("elephant");
    cout << "Load factor: " << um.load_factor()
         << ", Bucket count: " << um.bucket_count() << endl;

    auto it = um.find("dog");
    if (it != um.end()) {
        cout << "Dog bucket: " << um.bucket(it->first) << endl;
    }

    unordered_map<string, int> extras;
    extras["fox"] = 2;
    um.merge(extras);
    cout << "After merge, contains fox? " << (um.count("fox") ? "yes" : "no")
         << ", Extras empty? " << boolalpha << extras.empty() << noboolalpha << endl;
}

/* MAIN */
int main() {

    // arrayExample();
    // vectorExample();
    // dequeExample();
    // listExample();
    // forwardListExample();
    // stackExample();
    // queueExample();
    // setExample();
    // unorderedSetExample();
    // mapExample();
    // unorderedMapExample();

    return 0;
}
