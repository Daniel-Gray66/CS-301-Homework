#include "Matrix.h"

//constructorr
MatrixType::MatrixType()
{
	this->SetSize(0, 0);
}

void MatrixType::MakeEmpty()
{
	this->SetSize(0, 0);

}

void MatrixType::SetSize(int rowsSize, int colSize) {
	numCols = colSize;
	numRows = rowsSize;
}

void MatrixType::StoreItem(int item, int row, int col) {
	this->values[row][col] = item;
}

void MatrixType::Add(MatrixType otherOperand, MatrixType& result) {
	//checking if the operation is possible
	
	if (!AddSubCompatible(otherOperand)) {
		throw "Subtraction operation not possible ";
	}
	//Setting the size of result 
	result.SetSize(this->numRows, this->numCols);
		for (int i = 0; i < this->numRows; i++) {
			for (int j = 0; j < this->numCols; j++)
			{
				result.values[i][j] = this->values[i][j] + otherOperand.values[i][j];
			}
		}
		cout << "Matrix has been added" << endl;
	}
	

void MatrixType::Sub(MatrixType otherOperand, MatrixType& result) {
	//checking if the operation is possible
	if (!AddSubCompatible(otherOperand)) {
		throw "Subtraction operation not possible ";
		
	}
	//Setting the size of result 
	result.SetSize(this->numRows, this->numCols);

		for (int i = 0; i < this->numRows; i++) {
			for (int j = 0; j < this->numCols; j++)
			{
				result.values[i][j] = this->values[i][j] - otherOperand.values[i][j];
			}
		}
	}



void MatrixType::Mult(MatrixType otherOperand, MatrixType& result) {
	//checking if the operation is possible

	if (!MultCompatible(otherOperand))
	{
		throw " Multiplication operation not possible ";
		
	}
	
	// we need to change the size of the other matrix
	result.SetSize(this->numRows, otherOperand.numCols);

	for (int i = 0; i < this->numRows; i++)
	{
		for (int j = 0; j < otherOperand.numCols; j++)
		{
			int sum = 0;
			for (int k = 0; k < this->numCols; k++)
			{
				sum += this->values[i][k] * otherOperand.values[k][j];
					result.values[i][j] = sum;
			}
		}
	}
	cout << "Multuplication Complete" << endl;
	}




void MatrixType::Print(ofstream& outfile) const {
	
	for (int i = 0; i < this->numRows; i++) {
		for (int j = 0; j < this->numCols; j++)
		{
			outfile << this->values[i][j] << " ";
		}
		outfile << endl;
	}
	cout << "Matrix has been printed" << endl;
}
	







bool MatrixType::AddSubCompatible(MatrixType otherOperand) {
	if (this->numCols == otherOperand.numCols && this->numRows == otherOperand.numRows)
	{
		return true;
	}

	return  false;
}

bool MatrixType::MultCompatible(MatrixType otherOperand) {
	
	if (this->numCols == otherOperand.numRows)
	{
		return true;
	}
	return false;
	
}