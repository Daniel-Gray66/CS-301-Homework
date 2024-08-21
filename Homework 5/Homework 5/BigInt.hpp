#ifndef BIG_INT_HPP
#define BIG_INT_HPP
#include "DoublyLinkedList.hpp"

class BigInt  :protected DoublyLinkedList<int>
{
	public: 
		BigInt();

		~BigInt();

		void multiply(int);

		void Reset();

		friend ostream& operator<<(ostream&, const BigInt&);

private : 

	void Overflow();
	

};


#endif