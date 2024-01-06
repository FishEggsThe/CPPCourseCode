//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name:  Matthew Leal          Z#: Z23593275
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  04/13/2022           Due Time: 11:59 PM
Total Points: 20
Assignment #: amazon_porders9.cpp

Description: Same as Assignment 8 except using a constructor and direct input from the user

*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

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

class order_class
{
public:
	order_class();
	~order_class(); //de-allocates all memory allocate to INV by operator new.
	bool is_Empty(); //inline implementation
	bool is_full();//inline implementation
	int search(const string key);//returns location if item in INV; otherwise return -1
	void add( ); //adds a order record to INV
	void remove(const string key); //removes all items in INV with a cell number that matches key.
	void double_size();
	void process();
	void print(); //prints all the elements in INV to the screen
private:
	int count;
	int size;
	order_record *INV;
};

/************************************************************************************************************************************/
//Name: default constructor
//Precondition:
//Postcondition:
//Decription: Reads the data file of purchase order information (cell number, item, quantity, price, and processing plant) into the dynamic array of order records,
//INV. If the count become equal to the size the function double_size is called and the memory allocated to INV is doubled.
/************************************************************************************************************************************/
order_class::order_class()
{
	cout << "The default constructor has been called\n";
    count = 0;
	size = 1;
	INV = new order_record[size];
	ifstream in;
	in.open("purchase_data.txt");

	while (!in.eof())
	{
		if (is_full())
		{
			double_size();
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

/***********************************************************************************************************************************/
//Name: is_Empty
//Precondition:
//Postcondition:
//Decription: returns true if INV is empty
/**********************************************************************************************************************************/
bool order_class::is_Empty()
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_full
//Precondition:
//Postcondition:
//Decription: returns true if INV is full
/*********************************************************************************************************************************/
bool order_class::is_full()
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition:
//Postcondition:
//Decription: locates key in INV if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int order_class::search(const string key)
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
//Decription: adds a call_record to INV; if INV is full, double_size is called to increase the size of INV. The user
//            is prompted to enter the cell number, item, quantity, price, and processing plant.
/********************************************************************************************************************************/
void order_class::add( )
{
    if (is_full())
    {
        double_size();
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
    process();
}

/********************************************************************************************************************************/
//Name: remove
//Precondition:
//Postcondition:
//Decription: removes all order records in INV with a cell number field that matches key, if it is there.
/*******************************************************************************************************************************/
void order_class::remove(const string key)
{
    int loc = 0;
    while(loc != -1 && !(is_Empty()))
    {
        loc = search(key);
        if(loc != -1)
        {
            for(int i=loc; i < count-1; i++)
            {
                INV[i] = INV[i+1];
            }
            count--;
            cout << "." << endl;
        }
        else
            cout << "Removal finished" << endl;

    }
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition:
//Postcondition:
//Decription: doubles the size (capacity) of INV
/******************************************************************************************************************************/
void order_class::double_size( )
{
	size *=2;
	order_record *temp = new order_record[size];

	for(int i=0; i<count; i++)
	{
		temp[i] = INV[i];
	}

	delete [ ] INV;
	INV = temp;
}


/******************************************************************************************************************************/
//Name: process
//Precondition:
//Postcondition:
//Decription: calculate the tax rate, order tax, net cost, total order cost for every call record in INV.
/*****************************************************************************************************************************/
void order_class::process()
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
//Decription: prints every field of every call_record in INV formatted to the screen.
/***************************************************************************************************************************/
void order_class::print()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	for(int i=0; i<count; i++)
	{
		cout << INV[i].cell_number << "\t"
             << INV[i].item_number << "\t"
             << INV[i].quantity << "\t"
             << INV[i].price << "\t"
             << INV[i].processing_plant << "\t"
             << INV[i].tax_rate << "\t"
             << INV[i].order_tax << "\t"
             << INV[i].net_cost << "\t"
             << INV[i].total_cost << endl;
	}
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition:
//Postcondition:
//Decription: de-allocates all memory allocated to INV.  This will be the last function to be called (automatically by the compiler)
//before the program is exited.
/***************************************************************************************************************************/
order_class::~order_class()
{
    delete [] INV;
	cout << "The destructor has been called\n";
}


//Here is your driver to test the program
int main()
{

	order_class myOrders;//declaring order_class object myOrders; the default constructor is called automically.
	cout << "**********************************************************************\n";
	//Test 1:
	cout << "Test 1: Testing default construcor, double_size, process, is_full and print " << endl;
	myOrders.process( );
	myOrders.print( );
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 2:
	//void add();
	cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
	myOrders.add( );
	myOrders.print( );
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 3:
	//void remove(string key);
	cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
	cout << "Removing 9546321555\n";
	myOrders.remove("9546321555");
	myOrders.print( );
	cout << "Removing 787716590\n";
	myOrders.remove("7877176590");
	myOrders.print( );
	cout << "Removing 3051234567\n";
	myOrders.remove("3051234567");
	myOrders.print( );
	cout << "Removing 9546321555 ---AGAIN--- SHOULD GET MESSAGE\n";
	myOrders.remove("9546321555");
	myOrders.print( );
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 4:
	//destructor will be invoked when object myOrders goes out of scope
	cout << "Test 4: Destructor called" << endl;
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	return 0;
}
