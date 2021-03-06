#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


double calculateScore(double scoreArr[9]) {

	//cout << "Passed in array shows as: " << endl;
	double min = 10.0;
	double max = 0.0;
	for (int i = 0; i < 9; i++) {
		//cout << "i[" << i << "] = " << scoreArr[i] << endl;
		if (scoreArr[i] > max) {
			max = scoreArr[i];
		}
		if (scoreArr[i] < min) {
			min = scoreArr[i];
		}
	}

	cout << "max is: " << max << endl;
	cout << "min is: " << min << endl;
	return 0;
}

void sortArray(double scoreArr[9]) {
	int i, j, flag = 1;    // set flag to 1 to start first pass
	int temp;             // holding variable
	int numLength = 9;
	for (i = 1; (i <= numLength) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (numLength - 1); j++)
		{
			if (scoreArr[j + 1] > scoreArr[j])      // ascending order simply changes to <
			{
				temp = scoreArr[j];             // swap elements
				scoreArr[j] = scoreArr[j + 1];
				scoreArr[j + 1] = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}
}
int main()
{
	ifstream infile;
	infile.open("m6dive.txt");

	string numOfParticipants;
	double arr[9];
	
	getline(infile, numOfParticipants);

	string name;
	double diff;

	while (infile) {
		
		infile >> name;
		infile >> diff;
		cout << "Name is " << name << endl;
		cout << "Difficulty score is: " << diff << endl;
		for (int i = 0; i < 9; i++) {
			infile >> arr[i];
			//cout << arr[i] << " | ";
		}
		cout << endl;

		calculateScore(arr);
		sortArray(arr);
		cout << "sorted array is: ";
		for (int i = 0; i < 9; i++) {
			cout << arr[i] << " | ";
		}

		if (infile.eof())
			break;


	}

    return 0;
}

