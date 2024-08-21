#include "Matrix.h"


//The main switch statement
void Switch(int, MatrixType*, bool* initialized, int size);

// the matrix that is stored in the array
int MatrixIndex();

//The four main options the user has
MatrixType* addMatrix(MatrixType*, bool* initialized);
MatrixType* subMatrix(MatrixType*, bool* initialized);
MatrixType* MultMatrix(MatrixType*, bool* initialized);
void PrintMatrix(MatrixType*);

// Get matrix
MatrixType* InitializeMatrix(MatrixType*, int);

//prompting all the user options
int PromptUser(int);

//This will there is anything in the matrix
bool validate(bool*, int);

int main()
{
	const int size = 10;
	bool Initialized[size] =
	{ false,false,false,false,false,
	false,false,false,false,false,
	};


	MatrixType* List = new MatrixType[size];
	int UserOption = 0;
	int Matrix = 0;
	int Sentinel = 0;
	do {
		try {

			UserOption = PromptUser(UserOption);
			Switch(UserOption, List, Initialized, size);

		}
		catch (const char* err) {
			cout << err << endl;
		}
		catch (...)
		{
			cout << "Something happen with the program" << endl;
		}
	} while (UserOption != 6);
	cout << "Ending the program" << endl;
	return 0;
}


void Switch(int UserInput, MatrixType* List, bool* initialized, int size)
{

	switch (UserInput)
	{
	case getMatrix://This is supposed to initialize the matrix
	{

		int matrix = 0;
		cout << "We are creating a matrix" << endl;
		cout << "which matric would you like to initialize" << endl;
		matrix = MatrixIndex();
		List = InitializeMatrix(List, matrix);
		initialized[matrix - 1] = true;

		break;
	}
	case Addition:
	{
		
		if (!validate(initialized, size))
		{
			throw "Nothing has been initialized yet please choose other option";
		}

		cout << "Additon case" << endl;
		addMatrix(List, initialized);
		break;
	}
	case Subtraction:
	{

		if (!validate(initialized, size))
		{
			throw "Nothing has been initialized yet please choose other option";
		}
		cout << "subtraction case " << endl;
		subMatrix(List, initialized);
		break;
	}
	case Multiplication:
	{

		if (!validate(initialized, size))
		{
			throw "Nothing has been initialized yet please choose other option";
		}
		cout << "Multiplication case" << endl;

		MultMatrix(List, initialized);
		break;
	}
	case Print:
	{
		if (!validate(initialized, size))
		{
			throw "Nothing has been initialized yet please choose other option";
		}

		cout << "The Print case " << endl;

	PrintMatrix(List);

	}
	case EXIT:
	{

		break;
	}
	default:
	{
		cout << "invalid Menu Option" << endl;

	}
	cout << List << endl;
	}
}







//We need to initiazlide two matrices and the save the result into another matrix
MatrixType* MultMatrix(MatrixType* List, bool* initialized) {
	int First = 0;
	int Second = 0;
	int stored = 0;


	cout << "Enter the First matrix you would like to input" << endl;
	First = MatrixIndex();

	if (!initialized[First - 1])
	{
		throw "This index has not been initialized";
	}


	cout << "Enter the Second Matrix" << endl;
	Second = MatrixIndex();

	if (!initialized[Second - 1])
	{
		throw "This index has not been initialized";
	}

	cout << "Choose the location where u want it to be  stored" << endl;
	stored = MatrixIndex();


	List[First - 1].Mult(List[Second - 1], List[stored - 1]);
	return List;
}


MatrixType* addMatrix(MatrixType* List, bool* initialized) {
	int First = 0;
	int Second = 0;
	int stored = 0;



	cout << "Enter the First matrix you would like to input" << endl;
	First = MatrixIndex();

	if (!initialized[First - 1])
	{
		throw "This index has not been initialized";
	}


	cout << "Enter the Second Matrix" << endl;
	Second = MatrixIndex();

	if (!initialized[Second - 1])
	{
		throw "This index has not been initialized";
	}



	cout << "Choose the location where u want it stored" << endl;
	stored = MatrixIndex();

	List[First - 1].Add(List[Second - 1], List[stored - 1]);
	return List;
}



MatrixType* subMatrix(MatrixType* List, bool* initialized) {
	int First = 0;
	int Second = 0;
	int stored = 0;


	cout << "Enter the First matrix you would like to input" << endl;
	First = MatrixIndex();
	if (!initialized[First - 1])
	{
		throw "This index has not been initialized";
	}



	cout << "Enter the Second Matrix" << endl;
	Second = MatrixIndex();
	if (!initialized[Second - 1])
	{
		throw "This index has not been initialized";
	}

	cout << "Choose the location where u want it stored" << endl;
	stored = MatrixIndex();

	List[First - 1].Sub(List[Second - 1], List[stored - 1]);
	return List;
}



int MatrixIndex() {
	int Matrix = 0;

	cin >> Matrix;
	if (Matrix <= 0 || Matrix >= MAX_ROWS)
	{
		throw  "invalid location";
	}

	return Matrix;
}



MatrixType* InitializeMatrix(MatrixType* List, int Matrix) {

	int rowSize = 0;
	int colSize = 0;
	int value = 0;
	//asking for the dension of the matrix;
	cout << "How many rows " << endl;
	rowSize = MatrixIndex();
	cout << "How many cols" << endl;
	colSize = MatrixIndex();

	List[Matrix - 1].SetSize(rowSize, colSize);// setting the size of that matrix

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++)
		{
			cout << "Enter value " << endl;
			cin >> value;
			List[Matrix - 1].StoreItem(value, i, j);// initialzing each place in the matrix
		}
	}

	cout << "Matrix has been created" << endl;
	return List;
}


int PromptUser(int option)
{
	cout << "Welcome to the matrix Testing program " << endl;
	cout << "Enter 1 to Get a matrix" << endl;
	cout << "Enter 2 to Add" << endl;
	cout << "Enter 3 to subtract" << endl;
	cout << "Etner 4 to multiply" << endl;
	cout << "Enter 5 to print" << endl;
	cout << "Enter 6 to end the program " << endl;
	cin >> option;


	return option;

}

bool validate(bool* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == true)
		{
			return true;
		}

	}
	return false;

}

void PrintMatrix(MatrixType* List)
{
	ofstream OutPutFile("Output.txt");
	int Matrix = 0;
	if (!OutPutFile.is_open())
	{
		cout << "failed to open file " << endl;
		return;
	}


	cout << "Please enter which matrix you would like to print out" << endl;
	Matrix = MatrixIndex() - 1;
	List[Matrix].Print(OutPutFile);

}