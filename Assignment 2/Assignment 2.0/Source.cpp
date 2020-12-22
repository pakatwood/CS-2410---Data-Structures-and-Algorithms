// Created by Haider Qazi                       
// This program reads data from 2 seperate text files and calculate the sum, average, and lettergrade. It will then write and output the results into new file.
// Program will then use sorting algorightm to sort the data by grade average and print it to the screen. Program will also use search algoritm to search data by student name.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

const int row = 10;
const int col = 5;

void readData(string stname[row], int stgrade[row][col]);
void stTotal(int stgrade[row][col], int stsum[row]);
void stAverage(int stsum[row], int average[row]);
void stLetterGrade(int average[row], char letterGrade[row]);
void displayData(string stname[row], int stgrade[row][col], int stsum[row], int average[row], char letterGrade[row]);
void sortdata(string stname[row], int stgrade[row][col], int stsum[row], int average[row], char letterGrade[row], int index[row]);
int searchList(const int[], int, int);

//Thsi is the Main Function in which we will declare all the other functions.
int main()
{
	string stname[row];
	int stgrade[row][col];
	int stsum[row];
	int average[row];
	char letterGrade[row];
	int index[row];

	// Declare Functions
	readData(stname, stgrade);
	stTotal(stgrade, stsum);
	stAverage(stsum, average);
	stLetterGrade(average, letterGrade);
	displayData(stname, stgrade, stsum, average, letterGrade);
	sortdata(stname, stgrade, stsum, average, letterGrade, index);

	system("pause");
	return 0;
}

// This function will open the files and read from them to store them into seperate arrays.
void readData(string stname[row], int stgrade[row][col])
{
	// Opens name file of students.
	ifstream namefile;
	namefile.open("stname.txt");

	// Opens grade file of students.
	ifstream gradefile;
	gradefile.open("stgrade.txt");

	// Reads from the files.
	for (int r = 0; r < row; r++)
	{
		getline(namefile, stname[r]);
		for (int c = 0; c < col; c++)
		{
			gradefile >> stgrade[r][c];
		}
	}

}

// This function will take the values in array stgrade to calculate the sum of 5 grade of each student.
void stTotal(int stgrade[row][col], int stsum[row])
{
	//Initialize accumulator
	int total = 0;
	// In a loop it will add the values in each row and then resets the value and start over. 
	// It will store the values in new array called 'stsum' inside the loop.
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			total += stgrade[r][c];
			stsum[r] = total;
		}
		total = 0;
	}
}

// This function will take the sum of each seperate student and calculate its averages. 
void stAverage(int stsum[row], int average[row])
{
	// It will take the sum of those 5 grade of each student and calculate the averages of them 
	// and store them into new array called 'average' inside the loop.
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			average[r] = stsum[r] / col;
		}
	}
}

// This function will take the averages of the students and seperate them into letter grades such as A, B, C, or F.
void stLetterGrade(int average[row], char letterGrade[row])
{
	for (int r = 0; r < row; r++)
	{
		average[r];
		if (average[r] >= 90)
		{
			letterGrade[r] = 'A';
		}
		else if (average[r] >= 80 && average[r] < 90)
		{
			letterGrade[r] = 'B';
		}
		else if (average[r] >= 70 && average[r] < 80)
		{
			letterGrade[r] = 'C';
		}
		else if (average[r] >= 0 && average[r] < 70)
		{
			letterGrade[r] = 'F';
		}
	}
}

// This function will only display the student data such as it's first and last name, all 5 sums, average of the sums, and letter grade 
// of each student to a new file called "outputfile.txt".
void displayData(string stname[row], int stgrade[row][col], int stsum[row], int average[row], char letterGrade[row])
{
	ofstream outdata;
	outdata.open("outputfile.txt");

	outdata << setw(16) << endl << "NAME" << setw(24) << "SCORES" << setw(19) << "AVERAGE" << setw(14) << "GRADE" << endl << endl;

	for (int r = 0; r < row; r++)
	{
		outdata << setw(20) << stname[r] << ": " << setw(10);
		for (int c = 0; c < col; c++)
		{
			outdata << stgrade[r][c] << " ";
		}
		outdata << setw(10) << "|| " << average[r] << " ||";
		outdata << setw(10) << "|| " << letterGrade[r] << " ||";
		outdata << endl;
	}
}

//This function will sort the student data by grade average to demonstrate sorting algorithm and display the result to the screen.
void sortdata(string stname[row], int stgrade[row][col], int stsum[row], int average[row], char letterGrade[row], int index[row])
{
	//--Sort Data by Student Average -----------------------------------------
	
	for (int r = 0; r <= row; r++)
	{
		index[r] = r;
	}
	
	for (int r = 0; r < (row - 1); r++)
	{
		for (int c = r + 1; c < row; c++)
		{
			if (average[index[r]] > average[index[c]])
			{
				int temp = index[r];
				index[r] = index[c];
				index[c ] = temp;
			}
		}
	}
	//------------------------------------------------------------------------
	// Prints the data that is Sorted by Grade Average

	cout << "**************************************************************************" << endl;
	cout << "*                                                                        *" << endl;
	cout << "*                       Sorted by GRADE AVERAGE                          *" << endl;
	cout << "*                                                                        *" << endl;
	cout << "**************************************************************************" << endl;

	for (int r = 0; r < row; r++)
	{
		cout << setw(20) << stname[index[r]] << ": " << setw(10);
		for (int c = 0; c < col; c++) 
		{
			cout << stgrade[index[r]][c] << " "; 
		}
		cout << setw(10) << "|| " << average[index[r]] << " ||";
		cout << setw(10) << "|| " << letterGrade[index[r]] << " ||";
		cout << endl;
	}
}