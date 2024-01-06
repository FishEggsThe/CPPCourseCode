/************************************************************************************************************************

Name: Matthew Leal                    Z#: 23593275
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 2/23/2022             Due Time: 11:59pm
Total Points: 10
Assignment #: amazon_porders.cpp

Description: Program that takes in a text file, processes costs and taxes and prints the text file info and extra it processes into an output text file

*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void input(ifstream &, string &, string &, double &, double &, int &);
void output(ofstream &, string, string, double, double, int, double, double, double, double);
void process(double, double, int, double &, double &, double &, double &);


void input(ifstream & in, string & cell_number, string & item_number, double & quantity, double & price, int & processing_plant) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> cell_number >> item_number >> quantity >> price >> processing_plant;
}

void output(ofstream & out, string cell_number, string item_number, double quantity, double price, int processing_plant, double tax_rate, double order_tax, double net_cost, double total_cost)
{
    out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

    out << cell_number << "\t" << item_number << "\t" << (int)(quantity) << "\t"
    << price << "\t" << processing_plant << "\t" << tax_rate << "\t"
    << order_tax << "\t" << net_cost << "\t" << total_cost << endl;
}

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

	ifstream in;
	ofstream out;
	in.open("purchase_data.txt");
	out.open("amazon_inventoryoutput.txt");

	if (in.fail() || out.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{

			input(in, cell_number, item_number, quantity, price, processing_plant);
			process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
			output(out, cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
		}
	}

	in.close();
	out.close();

	return 0;
}


