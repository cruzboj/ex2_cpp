#ifndef FUNTEXT_H
#define FUNTEXT_H

#include <cstring> // For strlen and strcpy
#include <iostream>

class FunText{
        char* data;
        int length;
    public:
        // Default Constructor
        FunText();
        
        // Parameterized Constructor
        FunText(const char* str);
        
        // Copy Constructor
        //FunText(const FunText& other);
        
        // Destructor
        ~FunText();

        friend std::ostream& operator<<(std::ostream& os, const FunText& funText);
        
        //### `operator+=` (Appending)
        //Append various types to your `FunText`:
        FunText &operator+=(const FunText &other);          //`**: Append another `FunText` object’s text.
        FunText &operator+=(const char *other);             //`**: Append a C-style string.
        FunText &operator+=(int number);                    //`**: Convert the integer to text (e.g., `42` -> `"42"`) and append.
        FunText &operator+=(float number);                  //`**: Convert the float to text (e.g., `3.14` -> `"3.14"`) and append.
        
        //### `operator+` (Concatenation)
        //Return a new `FunText` without changing the originals:
        //FunText operator+(const FunText &other) const;   //`**: Concatenate this and `other`.
        // FunText operator+(const char *other) const;      //`**: Concatenate this and a C-string.
        // FunText operator+(int number) const;             //`**: Concatenate this and a converted integer.
        // FunText operator+(float number) const;           //`**: Concatenate this and a converted float.

        //### `operator-=` (In-Place Removal)
        //Remove content from the current text:
        FunText &operator-=(const FunText &other);          //`**: Remove **all occurrences** of `other`’s text.
        FunText &operator-=(const char *other);             //`**: Remove all occurrences of this C-string.
        FunText &operator-=(int n);                         //`**: Remove the last `n` characters (if `n` > length, remove all).
        
        //### `operator*` (Repetition)
        FunText operator*(int n) const;                     //`**: Return a new `FunText` that repeats the current text `n` times.
        
        //### `operator()(int start, int length)` (Substring Extraction)
        FunText operator()(int start, int length) const;     //`**: Extract a substring of given `length` starting at `start`, return as a new `FunText`. Handle out-of-range gracefully.

        //### Comparison Operators
        bool operator==(const FunText &other) const;         //`**: Return true if both texts are identical.
        bool operator!=(const FunText &other) const;         //`**: Return true if texts differ.

        //### Indexing Operator
        //char operator[](int index) const; //`**: Return the character at `index`. Document what happens if `index` is out-of-range (e.g., `assert`, or return `'\0'`).


        //**Utility Methods**
        // int length() const;                                  //`**: Return the current length.
        // void clear();                                        //`**: Empty the text (length = 0).
        // void toUpper();                                      //`**: Convert all letters to uppercase.
        // void toLower();                                      //`**: Convert all letters to lowercase.
        void reverse();                                      //`**: Reverse the entire text.
        int find(const FunText &other) const;                //`**: Find the first occurrence of `other`’s text, return the index or -1 if not found.

        //getters
        char * getData() const {return data;}
        int getLength()  const {return length;} 
};

#endif