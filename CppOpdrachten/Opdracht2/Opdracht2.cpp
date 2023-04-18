#include <iostream>
#include <string>
#include "Opdracht2.h"

int main()
{
    string cardNumber;
    cout << "Enter a credit card number: " << endl;
    cin >> cardNumber;

    if (isValid(cardNumber)) {
        cout << "Your credit card number is valid" << endl;
    }
    else {
        cout << "Your credit card number is invalid" << endl;
    }
    return 1;
}

int sumOfDoubleEvenPlace(const string& cardNumber) {
    int sum = 0;
    for (int i = cardNumber.length() - 2; i >= 0; i -= 2) {
        int number = (cardNumber[i] - '0') * 2;
        sum += getDigit(number);
    }
    return sum;
}

int sumOfOddPlace(const string& cardNumber) {
    int sum = 0;
    for (int i = cardNumber.length() - 1; i >= 1; i -= 2) {
        int number = (cardNumber[i] - '0');
        sum += getDigit(number);
    }
    return sum;
}

int getDigit(int number) {
    if (number > 9) {
        return (number / 10) + (number % 10);
    }
    else {
        return number;
    }
}

bool isValid(const string& cardNumber) {
    if (cardNumber.length() < 13 || cardNumber.length() > 16) {
        cout << "Card number does not have a valid amount of digits" << endl;
        return false;
    }

    if (startsWith(cardNumber, "4") || startsWith(cardNumber, "5") || startsWith(cardNumber, "37") || startsWith(cardNumber, "6")) {
        int sumOfEven = sumOfDoubleEvenPlace(cardNumber);
        cout << "Sum of even: " << sumOfEven << endl;
        int sumOfOdd = sumOfOddPlace(cardNumber);
        cout << "Sum of odd: " << sumOfOdd << endl;
        int sumTotal = sumOfEven + sumOfOdd;

        return (sumTotal % 10 == 0);
    }
    return false;
}

bool startsWith(const string& cardNumber, const string& substr) {
    return cardNumber.starts_with(substr);
}
