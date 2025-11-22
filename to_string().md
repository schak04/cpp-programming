# std::to_string(x) VS .to_string()

**Two entirely different things with the same name.**
    - `std::to_string(x)`
        A free function → converts numbers → decimal string
        Lives in the namespace std
        NOT tied to any class
    - `.to_string()`
        A member function of classes like std::bitset
        Converts the bitset → binary string
        Called on an object

They share the same name but:
    - Different purpose
    - Different type
    - Different usage
Just coincidence for naming consistency.
