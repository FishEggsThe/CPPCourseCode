/************************************************************************************************************************

Name: Matthew Leal                    Z#: 23593275
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 3/18/2022             Due Time: 11:59pm
Total Points: 20
Assignment #: semi_statistics.cpp

Description: Program that gets the numbers from each line in a text file, calculates their average, and outputs the numbers with their average to a new text file 

*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 50;

//my code I think
void input(double STR[][SIZE], int & count)
{

    ifstream in;
    in.open("monthly_stats.txt");

    while (!in.eof())
    {
        in >> STR[count][0] >> STR[count][1] >> STR[count][2]
           >> STR[count][3] >> STR[count][4] >> STR[count][5];
        count++;
	}


    in.close();
}

void process(double STR[][SIZE], int count)
{
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            STR[i][6] += STR[i][j];
        }
    STR[i][6] /= 6;
    }
}

void output(double STR[][SIZE], int count)
{
	ofstream out;
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);
    out.setf(ios::right);
	out.open("statistical_results.txt");


    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            out.width(10);
            out << STR[i][j] << "\t";
        }
        out << "\n";
    }

    out.close();
}

void calculate_totals(double STR[][SIZE], int count)
{
    ofstream out;
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);
    out.setf(ios::right);
	out.open("statistical_results.txt", ios::app);

	double total = 0.0;
    for(int j = 0; j < 7; j++)
    {
        for(int i = 0; i < count; i++)
        {
            total += STR[i][j];
        }
        out.width(10);
        out << total << "\t";
        total = 0.0;
    }
    out.close();
}

int main()
{
	int count = 0;
	double s_record[SIZE][SIZE] = {};
	input(s_record, count);
	process(s_record, count);
	output(s_record, count);
	calculate_totals(s_record, count);
	return 0;
}
