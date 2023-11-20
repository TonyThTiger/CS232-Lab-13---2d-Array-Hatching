#include<iostream>

using namespace std;
const int SIZE = 9;

void initializeCrossArray(int crossArr[][SIZE]);
void displayArray(int array[][SIZE]);
void crossRow(int crossArr[][SIZE], int rowPar);
void crossColumn(int crossArr[][SIZE], int colPar);
void makeHatches(int puzzleArr[][SIZE], int crossArr[][SIZE], int currentNum);

int main() {
	int userInput;
	int puzzleArray[SIZE][SIZE] = {{5,3,4,0,7,0,9,1,2},
								   {6,0,0,1,9,5,0,0,0},
								   {0,9,8,0,0,0,0,6,0},
								   {8,0,0,0,6,0,0,0,3},
								   {4,0,0,8,0,3,0,0,1},
								   {7,0,0,0,2,0,0,0,6},
								   {0,6,0,0,0,0,2,8,4},
								   {2,8,7,4,1,9,0,0,5},
								   {3,4,5,0,8,0,0,7,9}};
	int crossHatch[SIZE][SIZE];

	cout << "What puzzle number do you want to cross hatch: ";
	cin >> userInput;

	cout << "Cross Hatch Before: " << endl;
	initializeCrossArray(crossHatch);
	displayArray(crossHatch);
	cout << endl;

	cout << "Puzzle Contents: " << endl;
	displayArray(puzzleArray);

	makeHatches(puzzleArray, crossHatch, userInput);


	cout << "Cross Hatch After: " << endl;
	displayArray(crossHatch);
	cout << endl;
	return 0;
}

void initializeCrossArray(int crossArr[][SIZE]) {
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			crossArr[i][j] = 0;
		}
	}
}

void makeHatches(int puzzleArr[][SIZE], int crossArr[][SIZE], int currentNum) {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (puzzleArr[row][col] == currentNum) {
				crossRow(crossArr, row);
				col = 10;
			}
		}
	}

	for (int col = 0; col < 9; col++) {
		for (int row = 0; row < 9; row++) {
			if (puzzleArr[row][col] == currentNum) {
				crossColumn(crossArr, col);
				row = 10;
			}
		}
	}
}

void displayArray(int array[][SIZE]) {
	for (int row = 1; row <= SIZE; row++)
	{
		for (int col = 1; col <= SIZE; col++)
		{
			cout << array[row - 1][col - 1];
			if (col % 3 == 0 && col != 9) {
				cout << "|";
			}
		}
		cout << endl;
		if (row % 3 == 0 && row != 9) {
			cout << "-----------" << endl;
		}
	}

}


void crossRow(int crossArr[][SIZE], int rowPar) {
	for (int col = 0; col < SIZE; col++)
	{
		crossArr[rowPar][col] = 1;
	}

}
void crossColumn(int crossArr[][SIZE], int colPar) {
	for (int row = 0; row < SIZE; row++)
	{
		crossArr[row][colPar] = 1;
	}
}