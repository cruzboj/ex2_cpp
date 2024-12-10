#include "FunText.h"

FunText::FunText() : data(new char[1]{'\0'}), length(0) {}

FunText::FunText(const char* str) {
    data = new char[strlen(str)+1];
    strcpy(data,str);
    length = strlen(str);
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