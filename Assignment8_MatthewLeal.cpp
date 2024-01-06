/************************************************************************************************************************

Name:  Matthew Leal          Z#: Z23593275
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  04/05/2050           Due Time: 11:59 PM
Total Points: 10
Assignment #: amazon_porders8.cpp

Description:

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;


class order_record
{
public:
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
};


//Prototypes for your functions will go here

void initialize(order_record * & INV, int & count, int & size);
bool is_Empty(int count);
bool is_full(int count, int size);
int search(order_record * INV, int  count, string key);
void add(order_record * & INV, int & count, int & size);
void remove(order_record * INV, int & count, string key);
void double_size(order_record * & INV, int  count, int & size);
void process(order_record * INV, int count);
void print(const order_record  * INV, const int  count);
void destroy_INV(order_record  * INV, int & count, int & size);

//Function Implementations will go here
/*************************************************************************************************************************************************/
//Name: initialize
//Precondition:
//Postcondition:
//Decription: Reads the data file of call information (cell number, item_number, quantity, price, and processing_plant) into the dynamic
//array of call record, INV. If the count because equal to the size the function double_size is called and the memory allocated to INV is doubled.
/***********************************************************************************************************************************************/
void initialize(order_record * & INV, int & count, int & size)
{
	count = 0;
	size = 1;
	INV = new order_record[size];
	ifstream in;
	in.open("purchase_data8.txt");

	while (!in.eof())
	{
		if (is_full(count, size))
		{
			double_size(INV, count, size);
		}
		in >> INV[count].cell_number
           >> INV[count].item_number
           >> INV[count].quantity
           >> INV[count].price
           >> INV[count].processing_plant;
		//add code here

		count++;
	}
	in.close();
}

/**********************************************************************************************************************************/
//Name: is_Empty
//Precondition:
//Postcondition:
//Decription: returns true if INV is empty
/*********************************************************************************************************************************/
bool is_Empty(int count)
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: Is_full
//Precondition:
//Postcondition:
//Decription: returns true if INV is full
/*********************************************************************************************************************************/
bool is_full(int count, int size)
{
	return count == size;
}


/**********************************************************************************************************************************/
//Name: search
//Precondition:
//Postcondition:
//Decription: locates key in INV if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int search(order_record * INV, int  count, string key)
{

    for(int i=0; i<count; i++)
	{
		if (INV[i].cell_number == key)
		{
			return i;
		}
	}
	return -1;
}


/*********************************************************************************************************************************/
//Name: add
//Precondition:
//Postcondition:
//Decription: adds a new record to INV; if INV is full, double_size is called to increase the capacity of INV.
/********************************************************************************************************************************/
void add(order_record *  & INV, int & count, int & size)
{
    if (is_full(count, size))
    {
        double_size(INV, count, size);
    }
    cout << "Please enter your cell number" << endl;
    cin >> INV[count].cell_number;
    cout << endl << "Enter the item number" << endl;
    cin >> INV[count].item_number;
    cout << endl << "Enter the quantity" << endl;
    cin >> INV[count].quantity;
    cout << endl << "Enter the price of one item" << endl;
    cin >> INV[count].price;
    cout << endl << "Enter the processing plant identification number" << endl;
    cin >> INV[count].processing_plant;
    count++;
    process(INV, count);
}


/********************************************************************************************************************************/
//Name: Remove
//Precondition:
//Postcondition:
//Decription: remove all occurences of key from INV if it is there.
/*******************************************************************************************************************************/
void remove(order_record * INV, int & count, string key)
{
    int loc = 0;
    while(loc != -1 && !(is_Empty(count)))
    {
        loc = search(INV, count, key);
        for(int i=loc; i < count-1; i++)
		{
			INV[i] = INV[i+1];
		}
		count--;
    }

}

/******************************************************************************************************************************/
//Name: double_size
//Precondition:
//Postcondition:
//Decription: doubles the size (capacity) of INV
/******************************************************************************************************************************/
void double_size(order_record * & INV, int  count, int & size)
{
    size *= 2;
	order_record * t = new order_record[size];

	for(int i = 0; i < count; i++)
		t[i] = INV[i];

	delete [ ] INV;
	INV = t;
}

/******************************************************************************************************************************/
//Name: process
//Precondition:
//Postcondition:
//Decription: calculate the net cost, tax rate, order tax and total cost for every order record in INV.
/*****************************************************************************************************************************/
void process(order_record * INV, int count)
{
    for(int i = 0; i < count; i++)
    {
        if(INV[i].processing_plant <= 50)
            INV[i].tax_rate = 0.06;
        else if(INV[i].processing_plant <= 110)
            INV[i].tax_rate = 0.07;
        else if(INV[i].processing_plant <= 200)
            INV[i].tax_rate = 0.08;
        else if(INV[i].processing_plant <= 500)
            INV[i].tax_rate = 0.09;
        else if(INV[i].processing_plant > 500)
            INV[i].tax_rate = 0.11;
        INV[i].order_tax = INV[i].quantity * INV[i].price * INV[i].tax_rate;
        INV[i].net_cost = INV[i].quantity * INV[i].price;
        INV[i].total_cost = INV[i].net_cost + INV[i].order_tax;
    }
}

/****************************************************************************************************************************/
//Name: print
//Precondition:
//Postcondition:
//Decription: prints every field of every order_record in INV formatted to the screen.
/***************************************************************************************************************************/
void print(const order_record  * INV, const int  count)
{
    ofstream out;
	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(2);
	out.open("purchase8_results.txt");

    for(int i = 0; i < count; i++)
	{
		out << INV[i].cell_number << "\t"
             << INV[i].item_number << "\t"
             << INV[i].quantity << "\t"
             << INV[i].price << "\t"
             << INV[i].processing_plant << "\t"
             << INV[i].tax_rate << "\t"
             << INV[i].order_tax << "\t"
             << INV[i].net_cost << "\t"
             << INV[i].total_cost << endl;
	}
	out.close();
}



/****************************************************************************************************************************/
//Name: destroy_INV
//Precondition:
//Postcondition:
//Decription: de-allocates all memory allocated to INV.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
void destroy_INV(order_record  * INV, int & count, int & size)
{
    delete [ ] INV;
    count = 0;
    size = 0;
}


//Here is your driver to test the program
int main()
{
	int count = 0; //intializating count
	int size = 1;
	order_record * INV = 0; //declaring the dynamic array

	cout << "**********************************************************************\n";
	//Test 1:
	//void initialize(order_record * & INV, int & count, int & size);
	cout << "Test 1: Testing initialize, double_size, process, is_full and print " << endl;
	initialize(INV, count, size);
	process(INV, count);
	print(INV, count);
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";

	////Test 2:
	////void add(order_record * & INV, int & count, int & size);
	cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
	//add(INV, count, size);
	print(INV, count);
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";

	////Test 3:
	////void remove(order_record * INV, int & count, string key);
	cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
	cout << "Removing 9546321555\n";
	remove(INV, count, "9546321555");
	print(INV, count);
	cout << "Removing 787716590\n";
	remove(INV, count, "7877176590");
	print(INV, count);
	cout << "Removing 3051234567\n";
	remove(INV, count, "3051234567");
	print(INV, count);
	cout << "Removing 9546321555 ---AGAIN--- SHOULD GET MESSAGE\n";
	remove(INV, count, "9546321555");
	print(INV, count);
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";

	////Test 4:
	////void destroy_INV(order_record  * INV, int & count, int & size);
	cout << "Test 4: destroy_INV and print " << endl;
	destroy_INV(INV, count, size);
	cout << "size = " << size << endl;
	cout << "  count = " << count << endl;
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	return 0;
}
