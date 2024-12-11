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

FunText FunText::operator+(const FunText &other) const          //`**: Concatenate this and `other`.
{
    char *temp = new char[this->length + other.length + 1];
    
    // Copy data from the current object
    strcpy(temp, this->data);

    // Concatenate data from the other object
    strcat(temp, other.data);
    
    return temp;
}
FunText FunText::operator+(const char *other) const      //`**: Concatenate this and a C-string.
{
    char *temp = new char[length + strlen(other) + 1];
    strcpy(temp,data);
    strcat(temp,other);
    
    return temp;
}
FunText FunText::operator+(int number) const             //`**: Concatenate this and a converted integer.
{
    int count = number;
    int num_lenght = 0;
    while(count != 0){
        count/=10;
        num_lenght++;
    } 
    char * temp_num = new char[num_lenght + 1];

    sprintf(temp_num, "%d", number);
    
    char *temp = new char[length + num_lenght + 1];
    strcpy(temp,data);
    strcat(temp,temp_num);

    return temp;
}
FunText FunText::operator+(float number) const           //`**: Concatenate this and a converted float.
{
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

    return temp;
}

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

FunText FunText::operator-(const FunText &other) const      //`**: Return a new `FunText` with all occurrences of `other` removed.
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
        return temp;
}
FunText FunText::operator-(const char *other) const         //`**: Return a new `FunText` with all occurrences of `other` removed.
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
    strcpy(temp,data);

    return temp;
}
FunText FunText::operator-(int n) const                     //`**: Return a new `FunText` that is the original minus the last `n` chars.
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
    strcpy(temp,data);
    return temp;
}

FunText FunText::operator*(int n) const{
    char * temp = new char[(length * n)+1];
    temp[0] = '\0';

    int count = 0 ;
    while(count != n)
    {
        strcat(temp,data);
        count++;
    }

    return temp;
}

FunText FunText::operator()(int start, int length) const{
    char * temp = new char[(length - start)+1];
    temp[0] = '\0';
    for (int i = start; i < length; i++)
    {
        temp[i] = data[i];
    }
    temp[length] = '\0';

    return temp;
}

bool FunText::operator==(const FunText &other) const{
    return strcmp(data, other.data) == 0;
} 
bool FunText::operator!=(const FunText &other) const{
    return strcmp(data, other.data) != 0;
}

char FunText::operator[](int index) const{
    if(this->length < index)
        return '\0';
    for (int i = 0; i < this->length; i++)
    {
        if(index == i)
            return data[i];
    }
        
    return '\0';
}

void FunText::clear(){
    char *temp = new char[1];
    temp[0] = '\0';
    delete[] data;
    data = temp;
    length = 1;
}
void FunText::toUpper(){
    for (size_t i = 0; data[i] != '\0'; ++i) {
            data[i] = std::toupper(static_cast<unsigned char>(data[i]));
        }
}
void FunText::toLower(){
    for (size_t i = 0; data[i] != '\0'; ++i) {
            data[i] = std::tolower(static_cast<unsigned char>(data[i]));
        }
}
void FunText::reverse(){
    char *temp = new char[length + 1];
    int j = 0;  
    for (int i = length - 1; i >= 0; i--) {
        temp[j++] = data[i];
    }
    temp[length] = '\0';

    delete[] data;
    data = temp;  
}
int FunText::find(const FunText &other) const{
    char* p = strstr(data, other.data);

    // If substring is found, return the index, else return -1
    if (p != nullptr) {
        return p - data;  // Calculate the index relative to 'data'
    } else {
        return -1;  // Substring not found
    }
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