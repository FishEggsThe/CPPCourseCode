/*
Name: Matthew Leal                    Z#: 23593275
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 2/16/2022            Due Time: 11:59pm
Total Points: 20
Assignment #: denominations.cpp

Description: A simple program that estimates the kinds of coins you have based on how many cents you input
*/

#include <iostream>
#include <string>
using namespace std;

void compute_coins(int coin_value, int & num, int & amount_left);

void compute_coins(int coin_value, int & num, int & amount_left)
{
    if (amount_left >= 1 || amount_left <= 99)
    num = amount_left / coin_value;
    amount_left %= coin_value;
}

int main()
{
    int num, amount_left;
    char user_choice;

    do{
        num = 0;
        cout << "Enter an amount of coins from 1 cent to 99: ";
        cin >> amount_left;
        while (amount_left < 1 || amount_left > 99)
        {
            cout << "Invalid amount, try again:  ";
            cin >> amount_left;
        }

        compute_coins(25, num, amount_left);
        cout << num << " quarter(s)" << endl;
        compute_coins(10, num, amount_left);
        cout << num << " dime(s)" << endl;
        compute_coins(1, num, amount_left);
        cout << num << " penny(pennies)" << endl;

        cout << "Would you like to run the program again? (y for yes, n for no)" << endl;
        cin >> user_choice;
    } while (user_choice == 'y');


    return 0;
}
