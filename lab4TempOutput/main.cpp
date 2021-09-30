/*
Jayce Abens
FA2021
Due : October 13, 2021
Lab 4 Temperature Output

Design and write a C++ program that inputs a series of hourly temperature from a file, and outputs a bar chart (using stars) of the temperatures.
The temperature should be printed to the left of the corresponding bar, and there should be a heading that gives the scale of the chart. The range
of temperatures should be from  -30 to 120. Because it is hard to display 150 characters on the screen, you should have each star represent a range
of 3 degrees. That way, the bars will be at most 50 characters wide. Use meaningful variable names, proper indentation, and appropriate comments.
Thoroughly test the program using your own data sets. Make sure to vet the values from the input file.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

void printHeading();
void printChart();

int main()
{
	printHeading(); // prints the heading of the chart, scale from -30 to 120
	printChart();	// reads data from the input file, prints a bar for each temperature value, ends when the end of the file is reached
	return 0;
}

void printHeading()
{
	const string heading = " Temp | -30  -15  0    15   30   45   60   75   90   105  120";
	cout << heading << endl;
}

void printChart()
{
	const string inputFileName = "C:/Users/Jayce Abens/OneDrive/Documents/C++2021/lab4TempOutput/lab4TempOutput/hourlyTemperatures.dat"; //input file location, temperature values are separated by line
	ifstream inFile;
	inFile.open(inputFileName);		// opens in file stream

	float temp;
	string bar;
	while (!inFile.eof())	// repeats until the end of the file is reached (eof() returns nonzero value)
	{
		inFile >> temp;	// reads and stores the next temperature value
		cout << setw(5) << setprecision(4) << temp << " |";	// prints the temperature with a constant width for alignment 
		for (float f = abs(temp); f > 0; f = f - 3) bar.append("*"); // loops subracting 3 from the absolute value of the temperature, appends a * each time ( * = 3 degrees)
		if (temp < 0) cout << setw(11) << bar << "|" << endl;	// if the temperature is negative, prints the bar left of zero with a set width for alignment
		else cout << "           |" << bar << endl;	// if the temperature is positive, prints a space for negative values, then the positive bar
		bar = "";	// resets bar to empty
	}

	inFile.close(); // closes file stream
}