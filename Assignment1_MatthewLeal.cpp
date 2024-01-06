/****SAMPLE PROGRAM HEADER*******************************************************
Name:               Matthew Leal
Z-Number:           Z23593275
Total Points:	    10
Due Date:           1/26/2022
Course:             C0P3014
Assignment:         Assignment 1
Professor:          Dr. Lofton Bullard

Description: It does stuff

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <iomanip> //library that contain stream manipulators
using namespace std;


int main()
{
	//**********MAGIC FORMULA	WILL EXPLAIN**************************
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	//***************************************************************
	//declare and comment your user variable here
	//declare and comment your user variables here
	string pname;	//string that holds the plant name string pname;
	string cname;     //string that holds the county name
	double plant_cost; //double that hold the cost of a plant;
	int quantity; //int that hold the number of plants purchased;
	double purchase_tax = 0;
	double tax_rate = 0;
	double net_cost = 0;
	double discount_rate = 0;
	double discount = 0;
	double total_cost = 0;
	string user_response = "y";

	while (user_response == "y" || user_response == "Y")
	{
		//The code to get the user's input if given in the following
		//Input Statements
		cout << "Enter the Plant Name: ";
		cin >> pname;
		cout << "Enter the County Name: ";
		cin >> cname;
		cout << "Enter the Plant Cost: ";
		cin >> plant_cost;
		cout << "Enter the Quantity: ";
		cin >> quantity;


		//Calculation for net cost
		net_cost = quantity * plant_cost;

		//Logic ...if else statements for discount rate
		if (quantity <= 0)
			discount_rate = 0;
		else if (quantity >= 1 && quantity <= 6)
			discount_rate = .02;
		else if (quantity >= 7 && quantity <= 13)
            discount_rate = .04;
        else if (quantity >= 14 && quantity <= 25)
            discount_rate = .07;
        else if (quantity >= 26 && quantity <= 60)
            discount_rate = .09;
        else if (quantity > 60)
            discount_rate = .14;
        discount = net_cost * discount_rate;

		//Logic ...if else statements for tax rate
		if (cname == "dade")
			tax_rate = .055;
		else if (cname == "broward")
			tax_rate = .05;
		else if (cname == "palm")
			tax_rate = .06;
		else
		{
			cout << "Error - In proper County Name\n" << endl;
			exit(1);
		}

		//Calculations for purchase tax and total cost
		purchase_tax = net_cost * tax_rate;
		total_cost = net_cost + purchase_tax - discount;

		//Print Results to screen here
		cout << endl << endl;
		cout << "Plant Name = " << pname << "\n";
		cout << "County Name = " << cname << "\n";
		cout << "Plant Cost = $" << plant_cost << "\n";
		cout << "Quantity = " << quantity << "\n";
		cout << "Tax Rate = " << (int)(tax_rate*100) << "%\n";
		cout << "Net Cost = $" << net_cost << "\n";
		cout << "Discount Rate = " << (int)(discount_rate*100) << "%\n";
		cout << "Discount = $" << discount << "\n";
		cout << "Purchase Tax = $" << purchase_tax << "\n";
		cout << "Total Cost = $" << total_cost << "\n";

		cout << "Would you like to do another calculation (Y or N): ";
		cin >> user_response;
	}

	return	0;
}
