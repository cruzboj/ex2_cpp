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
        FunText(const FunText& other);
        
        // Destructor
        ~FunText();
        friend std::ostream& operator<<(std::ostream& os, const FunText& funText);

        char * getData() const {return data;}
        int getLength()  const {return length;} 
};

#endif