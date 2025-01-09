#include <iostream>
#include <sstream> //
#include <map> // کتابخانه هش مپ
using namespace std;

int main(void) 
{ 
    string input; 
    cin>>input; // گرفتن ورودی از کاربر

    map <string, int> frequency; // یک هش مپ به نام frequency

    string number; 

    stringstream ss(input); 
    while (getline(ss, number, ',')) // جداکردن ورودی کاربر با کاراکتر کاما
        frequency[number]++; // اضافه کردن یک عدد به frequency
    for (auto i : frequency)
        cout << i.first << ": " << i.second << endl; // نمایش خروجی به صورت خواسته شده
    system("pause");
    return 0; 
}