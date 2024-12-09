#include "FunText.h"

FunText::FunText() : data(new char[1]{'\0'}), length(0) {}

FunText::FunText(const char* str) {
    data = new char[strlen(str)+1];
    strcpy(data,str);
    length = strlen(str);
}

FunText::FunText(const FunText& other) {
    
}

std::ostream& operator<<(std::ostream& os, const FunText& funText){
    for (int i = 0; i < funText.getLength() ; i++)
    {
        os << funText.getData()[i];
    }
    return os;
}

FunText::~FunText() {
    delete[] data;                  // Release allocated memory
}