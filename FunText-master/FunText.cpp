#include "FunText.h"

FunText::FunText() : data(new char[1]{'\0'}), length(0) {}

FunText::FunText(const char* str) {
    data = new char[strlen(str)+1];
    strcpy(data,str);
    length = strlen(str);
}
FunText& FunText::operator+=(const FunText &other){

    char* temp = new char[length + other.length + 1];
    strcpy(temp,data);
    strcat(temp,other.data);
    delete[] data;
    data = temp;
    length = strlen(data);

    return * this;
}
FunText& FunText::operator+=(const char *other)       //`**: Append another `FunText` object’s text.
{
    char *temp = new char[length + strlen(other) + 1];
    strcpy(temp,data);
    strcat(temp,other);
    delete[] data;
    data = temp;
    length = strlen(data);

    return *this;
}
FunText& FunText::operator+=(int number){
    int count = number;
    int num_lenght = 0;
    while(count != 0){
        count/=10;
        num_lenght++;
    } 
    char * temp_num = new char[num_lenght + 1];

    sprintf(temp_num, "%d", number);
    //char *temp = new char[length + strlen(temp_num)+1];
    char *temp = new char[length + num_lenght + 1];
    strcpy(temp,data);
    strcat(temp,temp_num);
    delete[] data;
    data = temp;
    length = strlen(data);

    return *this;
}  
FunText& FunText::operator+=(float number){ //4.13 n*10 (n%10 == 0) && n/10 = 0
    int count = number;
    int countf = number;
    int num_lenght = 0;
    int num_lenghtf = 0;
    while(count != 0){ 
        count/=10;
        num_lenght++;
    }
    while(countf%10 != 0){ 
        countf*=10;
        num_lenghtf++;
    } 
    num_lenght += num_lenghtf;
    char * temp_num = new char[num_lenght + 2];

    sprintf(temp_num, "%.*f",num_lenghtf+1,number);
    char *temp = new char[length + num_lenght + 1];
    strcpy(temp,data);
    strcat(temp,temp_num);
    delete[] data;
    data = temp;
    length = strlen(data);

    return *this;
}

//FunText operator+(const FunText &other) const;          //`**: Concatenate this and `other`.
// FunText FunText::operator+(const char *other) const      //`**: Concatenate this and a C-string.
// {

// }
// FunText FunText::operator+(int number) const             //`**: Concatenate this and a converted integer.
// {

// }
// FunText FunText::operator+(float number) const           //`**: Concatenate this and a converted float.
// {

// }

FunText& FunText::operator-=(const FunText &other)          //`**: Remove **all occurrences** of `other`’s text.
{
    int i, j = 0;
        int otherLength = strlen(other.data);

        // Create a temporary buffer to store the result
        char* temp = new char[length + 1];  // New memory block for the modified string

        for (i = 0; i < this->length; i++) {
            if (strncmp(&this->data[i], other.data, otherLength) == 0) {
                i += otherLength - 1;  // Skip over the matched substring
            } else {
                temp[j++] = this->data[i];  // Copy the current character to the new buffer
            }
        }

        temp[j] = '\0';  // Null-terminate the new string

        // Free the old memory
        delete[] data;

        // Point to the new memory block
        data = temp;
        length = j;  // Update the length to match the new string size

        return *this;
}
FunText& FunText::operator-=(const char *other)             //`**: Remove all occurrences of this C-string.
{
    int i, j = 0;
    int other_len = strlen(other);
    // Loop through str1 and construct the modified string
    for (i = 0; i < length ; i++) {
        // Compare the current substring with str2
        if (strncmp(&data[i], other, other_len) == 0) {
            // Skip the length of str2
            i += other_len - 1;
        } else {
            // Otherwise, copy the character into the new string
            data[j++] = other[i];
        }
    }

    char * temp = new char[j+1];
    // Null-terminate the modified string
    data[j] = '\0';
    strcpy(temp,data);
    delete[] data;
    data = temp;
    
    return *this;
}
FunText& FunText::operator-=(int n)                         //`**: Remove the last `n` characters (if `n` > length, remove all).
{
    int count = n;
    int num_lenght = 0;
    while(count != 0){
        count/=10;
        num_lenght++;
    } 
    char * temp_num = new char[num_lenght + 1];
    sprintf(temp_num, "%d", n);

    int i, j = 0;
    // Loop through str1 and construct the modified string
    for (i = 0; i < length ; i++) {
        // Compare the current substring with str2
        if (strncmp(&data[i], temp_num, num_lenght) == 0) {
            // Skip the length of str2
            i += num_lenght - 1;
        } else {
            // Otherwise, copy the character into the new string
            data[j++] = temp_num[i];
        }
    }

    char * temp = new char[j+1];
    // Null-terminate the modified string
    data[j] = '\0';
    strcpy(temp,data);
    delete[] data;
    data = temp;
    
    return *this;
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