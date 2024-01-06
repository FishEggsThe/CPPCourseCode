

//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name: Matthew Leal                    Z#: 23593275
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 2/8/2022             Due Time: 11:59pm
Total Points: 20
Assignment #: amazon_purchase_recs.cpp

Description: This program takes in a text file and outputs the data with specific costs and taxes

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;


//Prototypes for your functions: input, output, and process will go here

void input(ifstream &, string &, string &, double &, double &, int &);
void output(string, string, double, double, int, double, double, double, double);
void process(double, double, int, double &, double &, double &, double &);


//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:
// Example:Get input (values of cell_number, item_number, quantity, price, processing_plant )
//from data file.

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream & in, string & cell_number, string & item_number, double & quantity, double & price, int & processing_plant) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> cell_number >> item_number >> quantity >> price >> processing_plant;
	//add more code to read the rest of the variables (item_number, quantity, price and processing_plant)
}

///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************


void output(string cell_number, string item_number, double quantity, double price, int processing_plant, double tax_rate, double order_tax, double net_cost, double total_cost)
{

	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/

    cout << cell_number << "\t";
    cout << item_number << "\t";
    cout << (int)(quantity) << "\t";
    cout << price << "\t";
    cout << processing_plant << "\t";
    cout << tax_rate << "\t";
    cout << order_tax << "\t";
    cout << net_cost << "\t";
    cout << total_cost << endl;
	//add more code to print all the variables


}

///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************


//Note: there is one 1 input/output parameter
void process(double quantity, double price, int processing_plant, double & tax_rate, double & order_tax, double & net_cost, double & total_cost)
{

	//put your code here to process/calculate the tax_rate, order_tax, net_cost, and total_cost
	if(processing_plant <= 50)
        tax_rate = 0.06;
	else if(processing_plant <= 110)
        tax_rate = 0.07;
	else if(processing_plant <= 200)
        tax_rate = 0.08;
	else if(processing_plant <= 500)
        tax_rate = 0.09;
	else if(processing_plant > 500)
        tax_rate = 0.11;
	order_tax = quantity * price * tax_rate;
	net_cost = quantity * price;
    total_cost = net_cost + order_tax;

}

//Here is your driver to test the program
int main()
{
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;

	ifstream in;    //declaring an input file stream
	in.open("purchase_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{

			input(in, cell_number, item_number, quantity, price, processing_plant);
			process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
			output(cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
		}
	}

	in.close();

	return 0;
}


