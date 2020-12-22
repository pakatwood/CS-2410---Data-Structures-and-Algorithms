// Created by Haider Qazi
//Write a program that uses a two-dimensional array to store the highest and lowest temperatures for each month of the year. 
//The program should output the average high, average low, and the highest and lowest temperatures for the year.

#include<iostream>
#include<fstream>
#include<iomanip>


const int rows = 12;	 //make # of rows/cols a constant int
const int cols = 3;


using namespace std;

void getData(int listTemp[rows][cols]);
void averageHigh(int listTemp[rows][cols]);
void averageLow(int listTemp[rows][cols]);
void indexHighTemp(int listTemp[rows][cols]);
void indexLowTemp(int listTemp[rows][cols]);

ifstream infile;

int main()
{

	double average;
	int listTemp[rows][cols];

	ifstream datafile;
	datafile.open("Data.txt"); //open datafile



	getData(listTemp);						   //calling functions
	averageHigh(listTemp);
	averageLow(listTemp);
	indexHighTemp(listTemp);
	indexLowTemp(listTemp);



	system("pause");
	return 0;

}

void getData(int listTemp[rows][cols])
{													 //read data in both arrays

	int x;
	int j;
	ifstream datafile;
	datafile.open("Data.txt");
   //  ofstream outfile;


	for (x = 0; x < rows; x++)
	{
		for (j = 0; j < cols; j++)
		{

			datafile >> listTemp[x][j];              // reads and stores into array
			

		}
	}
}
void averageHigh(int listTemp[rows][cols])
{
	int x = 1;
	double Sum = 0;								//read first column and find the average
	double Average = 0;							//from the highs	   


	for (x = 0; x < cols; x++)
	{
		Sum = listTemp[x+1][0] + Sum;
		// Average = Sum/x;			 
	}
	// Average = Sum/12;

	Average = Sum / x;

	cout << "Average high for the year: " << Average << endl;

	/*cout << "Average high for the year: " << Average << endl << endl;*/


}

void averageLow(int listTemp[rows][cols])
{
	int Sum = 0;											//read the second column and find the
	double Average;
	//average of the lows	   

	for (int x = 0; x < rows; x++)
	{
		Sum = listTemp[x][1] + Sum;
	}
	//  Average = Sum/12;

	Average = Sum / 12;

	cout << "Average low for the year: " << Average << endl << endl;
}



void indexHighTemp(int listTemp[rows][cols])
{
	int highestIndex = 0;

	//find highest in the "high" column					  
	for (int x = 0; x < rows; x++)
	{
		if (listTemp[0][x] > highestIndex)
			highestIndex = listTemp[0][x];

	}
	cout << "The index high temperature is " << highestIndex << endl << endl;

}

void indexLowTemp(int listTemp[rows][cols])
{
	int lowestIndex = 0;
	//find the lowest in the low column

	for (int x = 0; x < rows; x++)

	{
		if (lowestIndex > listTemp[0][x])
			lowestIndex = listTemp[0][x];

	}
	cout << "The index low temperature is " << lowestIndex << endl << endl;
}
