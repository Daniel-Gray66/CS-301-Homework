#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
#include <iostream>

using namespace std;
//Enum for the switch statement
enum Choice {
	getMatrix = 1,
	Addition ,
	Subtraction ,
	Multiplication,
	Print,
	EXIT,
};

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
class MatrixType
{
public:
	//getter 
	MatrixType();
	void MakeEmpty();
	void SetSize(int rowsSize, int colSize);
	void StoreItem(int item, int row, int col);
	void Add(MatrixType otherOperand, MatrixType& result);
	void Sub(MatrixType otherOperand, MatrixType& result);
	void Mult(MatrixType otherOperand, MatrixType& result);
	void Print(ofstream& outfile) const;
	bool AddSubCompatible(MatrixType otherOperand);
	bool MultCompatible(MatrixType otherOperand);
private:
	int values[MAX_ROWS][MAX_COLS];
	int numRows;
	int numCols;
};
#endif // !

