#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    String a("267");
    String b("17");
    String sum = a + b;
    cout << "первая строка: " << a << "вторая строка: " << b << endl;
    cout << "сумма: " << sum << endl;
    cout << "введите строку:";
    String input;
    cin >> input;
    if (input == sum)
        cout << "такая же строка" << endl;
    else if (input < sum)
        cout << "ваша строка < сумма" << endl;
    else if (input > sum)
        cout << "ваша строка > сумма" << endl;
    cout << "введите число: ";
    int number;
    cin >> number;
    cout << number << endl;
    cout << "введите кол-во повторений:";
    int amount;
    cin >> amount;
    String repeat;
    input = repeat.repeater(input, amount);
    cout << input;
}
