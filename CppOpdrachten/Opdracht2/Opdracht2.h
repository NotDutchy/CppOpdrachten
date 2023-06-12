#include <iostream>

#pragma once

using namespace std;

// Return true if the card number is valid
bool isValid(const string& cardNumber);

// Get the result from Step 2
int sumOfDoubleEvenPlace(const string& cardNumber);

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(int number);

// Return sum of odd-place digits in the card number
int sumOfOddPlace(const string& cardNumber);

// Return true if substr is the prefix for cardNumber
bool startsWith(const string& cardNumber, const string& substr);
