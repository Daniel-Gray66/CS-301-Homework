#include "BigInt.hpp"


BigInt::BigInt()
{
	append(1);
	Overflow();
	
}

BigInt:: ~BigInt() {

}


void BigInt::Overflow()
{
	Node* Cur = Trailer->prev;
	int n = 3;

	while (Cur != Header)
	{

		if (Cur->value >= pow(10, n) - 1)
		{
			if (Cur->prev == Header)
			{	
				Node* m = new Node;
				Header->next = m;
				m->prev = Header;
				Cur->prev = m;
				m->next = Cur;

			}

			int x = Cur->value % (int) pow(10, n);//being saved in the node
			int y = Cur->value / (int) pow(10, n); //being added to the next node

			Cur->value = x;
			Cur->prev->value += y;

		}

		Cur = Cur->prev;
	}

}

void BigInt::Reset()
{
	this->clear();
	append(1);
	
}


 ostream& operator<<(ostream& os, const BigInt& p )
{
	 os << static_cast <const DoublyLinkedList<int>&>(p);
	 
	 return os;

}


/*
* //random thoughts here
*  We want to mnultiply n and n-1 
* The nwe need to split up the nodes where each node contains a 3 digit number
* 
* when a number is greater than 3 digits it first number needs to be added with the last number of the next node.
* Start from the least significant digit
* 
* Step 1 Multiply every node by N 
* 
* Step 2 overflow: we start from the least sig fig and move towards the head.
* 
* Step 3 if the head is overflowed then we create a new node and have that be the new head.
* 
*/
void BigInt::multiply(int n)
{
	
	Node* Cur = Trailer->prev;

	while (Cur != Header){
		Cur->value *= n;

		Cur = Cur->prev;
	}
	Overflow();
}