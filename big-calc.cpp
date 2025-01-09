#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string add(string a, string b) {
    string output = "";
    int carry = 0;
    int temp = 0;

    int lena = a.length();
    int lenb = b.length();

    if (lenb > lena) {
        swap(a, b);
        swap(lena, lenb);
    }

    for (int i = 0; i < lenb; i++) {
        temp = (a[lena - i - 1] - '0') + (b[lenb - i - 1] - '0') + carry;
        if (temp >= 10) {
            carry = 1;
            temp -= 10;
        } else {
            carry = 0;
        }
        output.push_back(temp + '0');
    }

    for (int i = lenb; i < lena; i++) {
        temp = (a[lena - i - 1] - '0') + carry;
        if (temp >= 10) {
            carry = 1;
            temp -= 10;
        } else {
            carry = 0;
        }
        output.push_back(temp + '0');
    }

    if (carry) {
        output.push_back('1');
    }

    reverse(output.begin(), output.end());

    return output;
}

string multiply(string a, string b) {

    int lena = a.length();
    int lenb = b.length();
    if (a == "0" || b == "0")
        return "0"; // نمایش صفر اگر یکی از ارقام صفر بود

    vector<int> result(lena + lenb, 0); //ساخت وکتور با حداثر اندازه

    // عمل ضرب از اخر به اول
    for (int i = lena - 1; i >= 0; i--) {
        for (int j = lenb - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string output; //خروجی
    //برعکس کردن خروجی و برگردادن آن به کاربر
    for (int num : result) {
        if (!(output.empty() && num == 0)) {
            output.push_back(num + '0');
        }
    }

    return output.empty() ? "0" : output;
}

int main() {
    string num1 = "";
    string num2 = "";

    cout << "enter first number : ";
    cin >> num1;

    cout << "enter second number : ";
    cin >> num2;

    cout << "\nAnswer: " << multiply(num1, num2) << endl;

    system("pause");
    return 0;
}
