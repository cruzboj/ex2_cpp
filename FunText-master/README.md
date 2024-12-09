# 🎉 C++ Assignment: Meet **FunText**! 🎉

Hey there, code explorers! Welcome to your new challenge: crafting a dynamic, pointer-powered text class called **`FunText`**! Because coding should be fun, right? 😜

In this assignment, you’ll hone your C++ skills with dynamic memory management, operator overloading, and handling multiple data types... all while keeping things upbeat! ✨

## What’s the Deal with `FunText`?

**`FunText`** manages text using a raw `char*` (no `std::string` allowed!). It’s your playground for overloading operators in creative ways and exploring a variety of functionalities. You’ll build a class that supports concatenation, removal, repetition, extraction, comparison, and transformations—just like a coding superhero! 🦸‍♀️🦸‍♂️

## Core Requirements

1. **No `std::string`**:  
   You must use raw `char*` for all internal storage. Handle your memory carefully—no leaks allowed! 🧹

2. **Class Name & Structure**:
   - Class: **`FunText`**  
   - Internally:
     - `char* data` for the text.
     - Track length (and capacity if you want).
   - Implement:
     - **Default Constructor**: Creates empty text.
     - **Parameterized Constructor**: Takes a `const char*` to initialize.
     - **Copy Constructor**: Deep copy from another `FunText`.
     - **Destructor**: Clean up memory.
     - **Assignment Operator=**: Deep copy logic, handle self-assignment.

3. **Operator Overloads & Methods**:

   You’ll implement multiple overloads for each operator, each handling a different input type. Let’s call the right-hand object/argument `other` for clarity.

   ### `operator+=` (Appending)
   Append various types to your `FunText`:
   - **`FunText &operator+=(const FunText &other)`**: Append another `FunText` object’s text.
   - **`FunText &operator+=(const char *other)`**: Append a C-style string.
   - **`FunText &operator+=(int number)`**: Convert the integer to text (e.g., `42` -> `"42"`) and append.
   - **`FunText &operator+=(float number)`**: Convert the float to text (e.g., `3.14` -> `"3.14"`) and append.

   **Example:**
   ```cpp
   FunText t("Hello");
   t += " there";       // t: "Hello there"
   t += 42;             // t: "Hello there42"
   ```

   ### `operator+` (Concatenation)
   Return a new `FunText` without changing the originals:
   - **`FunText operator+(const FunText &other) const`**: Concatenate this and `other`.
   - **`FunText operator+(const char *other) const`**: Concatenate this and a C-string.
   - **`FunText operator+(int number) const`**: Concatenate this and a converted integer.
   - **`FunText operator+(float number) const`**: Concatenate this and a converted float.

   **Example:**
   ```cpp
   FunText a("Value: ");
   FunText b = a + 3.14f;    // b: "Value: 3.14"
   FunText c = b + " is pi"; // c: "Value: 3.14 is pi"
   ```

   ### `operator-=` (In-Place Removal)
   Remove content from the current text:
   - **`FunText &operator-=(const FunText &other)`**: Remove **all occurrences** of `other`’s text.
   - **`FunText &operator-=(const char *other)`**: Remove all occurrences of this C-string.
   - **`FunText &operator-=(int n)`**: Remove the last `n` characters (if `n` > length, remove all).

   **Example:**
   ```cpp
   FunText ft("banana");
   ft -= "na";   // ft: "ba"
   ft -= 1;      // ft: "b"
   ```

   ### `operator-` (Removal Returning a New Object)
   Return a new `FunText` with removals, without changing the original:
   - **`FunText operator-(const FunText &other) const`**: Return a new `FunText` with all occurrences of `other` removed.
   - **`FunText operator-(const char *other) const`**: Return a new `FunText` with all occurrences of `other` removed.
   - **`FunText operator-(int n) const`**: Return a new `FunText` that is the original minus the last `n` chars.

   **Example:**
   ```cpp
   FunText original("HelloWorld");
   FunText shorter = original - 5;   // shorter: "Hello"
   FunText noO = original - "o";     // noO: "HellWrld"
   ```

   ### `operator*` (Repetition)
   - **`FunText operator*(int n) const`**: Return a new `FunText` that repeats the current text `n` times.
   
   **Example:**
   ```cpp
   FunText laugh("ha");
   FunText bigLaugh = laugh * 3; // bigLaugh: "hahaha"
   ```

   ### `operator()(int start, int length)` (Substring Extraction)
   - **`FunText operator()(int start, int length) const`**: Extract a substring of given `length` starting at `start`, return as a new `FunText`.  
     Handle out-of-range gracefully.

   **Example:**
   ```cpp
   FunText phrase("HelloWorld");
   FunText sub = phrase(0, 5);  // sub: "Hello"
   FunText end = phrase(5, 50); // end: "World"
   ```

   ### Comparison Operators
   - **`bool operator==(const FunText &other) const`**: Return true if both texts are identical.
   - **`bool operator!=(const FunText &other) const`**: Return true if texts differ.

   **Example:**
   ```cpp
   FunText x("test");
   FunText y("test");
   FunText z("exam");
   bool same = (x == y); // true
   bool diff = (x != z); // true
   ```

   ### Indexing Operator
   - **`char operator[](int index) const`**: Return the character at `index`.  
     Document what happens if `index` is out-of-range (e.g., `assert`, or return `'\0'`).

   **Example:**
   ```cpp
   FunText word("CAT");
   char letter = word[1]; // letter: 'A'
   ```

4. **Utility Methods**
   - **`int length() const`**: Return the current length.
   - **`void clear()`**: Empty the text (length = 0).
   - **`void toUpper()`**: Convert all letters to uppercase.
   - **`void toLower()`**: Convert all letters to lowercase.
   - **`void reverse()`**: Reverse the entire text.
   - **`int find(const FunText &other) const`**: Find the first occurrence of `other`’s text, return the index or -1 if not found.

   **Examples:**
   ```cpp
   FunText txt("HeLLo");
   txt.toLower();      // txt: "hello"
   txt.toUpper();      // txt: "HELLO"
   txt.reverse();      // txt: "OLLEH"
   int pos = txt.find("LL"); // pos: 2
   txt.clear();        // txt: ""
   ```

## Why All This Complexity? 😈

- You’ll practice multiple operator overloads for the same operators but different parameter types.
- You’ll get comfortable converting between textual and numeric data on your own.
- You’ll master substring operations, comparisons, repetition, extraction, and transformations.
- You’ll ensure correct object semantics, no memory leaks, and robust error handling.

## Submission Details

- **Files**:  
  - `FunText.h` and `FunText.cpp` for your class.
  - `main.cpp` to show off all these operations in action.
  - `README.md` (this file) as your guide.

- **Compilation**:  
  ```cpp
  g++ -o runMe FunText.cpp main.cpp && ./runMe
  ```

- **Commenting & Documentation**:  
  Add comments explaining your approach, especially for tricky parts like substring removal and number-to-string conversions. Your future self will thank you! 😇

## Final Words of Encouragement 🎉

This might feel like a lot, but remember: tackle it step-by-step. Get the basics stable first, then add one operator or method at a time. Test often, celebrate small victories, and don’t forget to have some fun with it! 🥳

Good luck, have a blast, and show that text who’s boss! 💪
