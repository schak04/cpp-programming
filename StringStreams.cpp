/*
String Streams:
    std::stringstream is a C++ stream class from the <sstream> header that lets you treat
    strings like streams (similar to cin/cout but working on strings instead of console I/O).
    So instead of reading from or writing to the keyboard/screen, you're reading from or writing to a std::string.
    It is especially useful for parsing strings, converting between data types, and formatting string content.
*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/* 1. What is std::stringstream?
   std::stringstream allows reading and writing to a string
   using stream operators (<< and >>), similar to cin/cout.
   Header: #include <sstream>
*/
void basicExample() {
    /* Basic Example */
    stringstream ss;
    ss << "Hello " << 123 << " world";
    cout << ss.str() << "
";  // Output: Hello 123 world
}

/* 2. Extracting values (parsing) from a string */
void extractValues() {
    string s = "25 50 75";
    stringstream ss(s);

    int a, b, c;
    ss >> a >> b >> c;

    cout << a << " " << b << " " << c << "
";
}

/* 3. Splitting a string by spaces using stringstream */
void splitString() {
    string s = "apple mango banana";
    stringstream ss(s);
    string word;

    while (ss >> word) {
        cout << word << "
";
    }
}

/* 4. Converting numbers to strings using stringstream */
void numberToString() {
    int x = 100;
    stringstream ss;
    ss << x;
    string s = ss.str();
    cout << s << "
";
    /* Note: std::to_string(x) is easier. */
}

/* 5. Converting strings to numbers using stringstream */
void stringToNumber() {
    string s = "123";
    int x;
    stringstream(s) >> x;
    cout << x << "
";
    /* Note: stoi(s) is simpler. */
}

/* 6. Clearing a stringstream */
void clearStringstream() {
    stringstream ss;
    ss << "Test";

    ss.str("");   /* clears buffer */
    ss.clear();    /* clears flags */
}

/* 7. Using istringstream (input) and ostringstream (output) */
void isoExamples() {
    /* istringstream example */
    istringstream iss("10 20 30");
    int a, b, c;
    iss >> a >> b >> c;
    cout << a << " " << b << " " << c << "
";

    /* ostringstream example */
    ostringstream oss;
    oss << "Result: " << 42;
    cout << oss.str() << "
";
}

/* 8. Parsing CSV-style comma-separated values */
void parseCSV() {
    string s = "10,20,30,40";
    stringstream ss(s);
    string token;

    while (getline(ss, token, ',')) {
        cout << token << "
";
    }
}

/* 9. Building a formatted string */
void formattedSentence() {
    stringstream ss;
    string name = "Sapto";
    int age = 21;

    ss << "Name: " << name << ", Age: " << age;
    cout << ss.str() << "
";
}

/* 10. Converting vector<int> to a string */
void vectorToString() {
    vector<int> v = {1, 2, 3, 4};
    stringstream ss;

    for (int x : v) ss << x << " ";

    cout << ss.str() << "
";
}

int main() {
    basicExample();
    extractValues();
    splitString();
    numberToString();
    stringToNumber();
    isoExamples();
    parseCSV();
    formattedSentence();
    vectorToString();
}
