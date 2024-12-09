#include <iostream>
#include "FunText.h"

int main() {
    FunText greeting("Hello");
    // greeting += " World";     // "Hello World"
    // greeting += 123;          // "Hello World123"
    // greeting += 4.56f;        // "Hello World1234.56"

    std::cout << "Greeting: " << greeting << std::endl;

    // FunText toRemove("World");
    // greeting -= toRemove;     // remove "World"
    // std::cout << "After removal: " << greeting << std::endl; // "Hello 1234.56"

    // FunText repeatMe("ha");
    // FunText laughter = repeatMe * 3; // "hahaha"
    // std::cout << "Laughter: " << laughter << std::endl;

    // // Extract substring
    // FunText phrase("HelloWorld");
    // FunText sub = phrase(0,5); // "Hello"
    // std::cout << "Substring: " << sub << std::endl;

    // // Comparison
    // FunText a("test");
    // FunText b("test");
    // std::cout << "a == b? " << (a == b ? "true" : "false") << std::endl;

    // // Reverse
    // a.reverse(); // "tset"
    // std::cout << "Reversed a: " << a << std::endl;

    // // Find
    // FunText searchIn("BANANABREAD");
    // FunText searchFor("ANA");
    // int pos = searchIn.find(searchFor);
    // std::cout << "Found 'ANA' in 'BANANABREAD' at index: " << pos << std::endl;

    // // Clear
    // searchIn.clear();
    // std::cout << "Cleared searchIn: '" << searchIn << "' length: " << searchIn.length() << std::endl;

    return 0;
}
