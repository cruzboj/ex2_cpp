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
        //friend std::ostream& operator+=(std::ostream& os, const FunText& FunText);
        //### `operator+=` (Appending)
        //Append various types to your `FunText`:
        //FunText &operator+=(const FunText &other);       //`**: Append another `FunText` object’s text.
        FunText &operator+=(const char *other);          //`**: Append a C-style string.
        FunText &operator+=(int number);                 //`**: Convert the integer to text (e.g., `42` -> `"42"`) and append.
        FunText &operator+=(float number);               //`**: Convert the float to text (e.g., `3.14` -> `"3.14"`) and append.
        
        //getters
        char * getData() const {return data;}
        int getLength()  const {return length;} 
};

#endif