
#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
template <typename T>
class BinarySearchTree
{
public: 
	struct Node {
		T value;
		Node* Left;
		Node* Right;

		int instance;
		

		//Node Constructor
		Node(T v = T(), Node* n = nullptr, Node* m = nullptr)
			: value(v), Left(n), Right(m) {
			instance = 1;
		}

	};
	//counting the number of nodes (unique words)
	int words;
	int DuplicateCount;
	int ThreeWord;
	int ThreeWordDuplicate;
	
	
	
	int WordLength;

	int SentCount;
	
	int TotalWords;

	
 
	//constructor 
	BinarySearchTree();
	
	//Deconstructor
	 ~BinarySearchTree();
	 
	 //main functions 
	 void Insert(T);
	 void Remove(T);
	 bool Search(T);
	 void display();

	 void stats();

	 
	

private:

	Node* Root;

	//helper functions 
	void HelpInsert(Node*&,Node*);
	void HelpRemove(Node*, T );
	Node* HelpSearch(Node*,T);
	void HelpDisplay(Node*);


	// Helper functions for the stat function
	int WordCount();
	int UniqueWords();
	int Unique3Words();
	float AverageWordLength();
	float AverageSentenceLength();

	//helper for the delete function 
	void Delete(Node*);



};
#endif






template <typename T>
int BinarySearchTree<T>:: WordCount() {
	return TotalWords;
}

template <typename T>
int BinarySearchTree<T>:: UniqueWords()
{
	return words;
}
template <typename T>
int BinarySearchTree<T>:: Unique3Words()
{
	return ThreeWord;
}

template <typename T>
float BinarySearchTree<T>:: AverageWordLength()
{
	return (float) WordLength / WordCount();
}
template <typename T>
float BinarySearchTree<T>:: AverageSentenceLength()
{
	return (float) WordCount() / SentCount;
}


template <typename T>  
 BinarySearchTree<T>:: BinarySearchTree()
{
	 Root = nullptr;
	 words = 0; 
	 ThreeWord = 0;

	 DuplicateCount = 0; 
	 WordLength = 0;
	 SentCount = 0;

	 TotalWords = 0;
}

 
 template <typename T>
 void BinarySearchTree<T>:: stats()
 {
	 ofstream outfile;
	 outfile.open("Outfile.txt");
	 
	 outfile << "Number of words: " << TotalWords << endl;
	 outfile << "Number of Unique words: " << UniqueWords() << endl;
	 outfile << "Number of Unique words with more than 3 characters: " << Unique3Words() << endl;
	 outfile << "Number of sentences: " << SentCount << endl;
	 outfile << "Average word length: " << AverageWordLength() << endl;
	 outfile << "Average sentence length: " << AverageSentenceLength() << " Word." << endl;


	 cout << "Number of words: " << TotalWords << endl;
	 cout << "Number of Unique words: "<< UniqueWords() << endl;
	 cout << "Number of Unique words with more than 3 characters: " << Unique3Words() << endl;
	 cout << "Number of sentences: " << SentCount << endl;
	 cout << "Average word length: " << AverageWordLength() << endl;
	 cout << "Average sentence length: " << AverageSentenceLength() << " Word." << endl;
	 outfile.close();
 }

 
//Deconstructor
 template <typename T>
 BinarySearchTree<T>::~BinarySearchTree()
{
	 Delete(Root);

}

 template <typename T>
 void BinarySearchTree<T>::Delete(Node* root)
 {
	 if (root != nullptr)
	 {
		 Delete(root->Left);
		 Delete(root->Right);
		 delete root;
	 }
 }

 template <typename T>
 void BinarySearchTree<T>::Insert(T data)
 {

	 if (data[data.length() - 1 ] == '.' || data[data.length() - 1] == '?' || data[data.length() - 1] == '!')
	 {
		 SentCount++;
		 data = data.substr(0,data.length() - 1);
	 }

	 if (data[data.length() - 1] == ',' || data[data.length() - 1] == ';') {
		 data = data.substr(0, data.length() - 1);
	 }

	 TotalWords++;
	 WordLength += data.length();
	 Node* n = new Node();

		 n->value = data;
		 

	 HelpInsert(Root, n);
 }


template <typename T>
void BinarySearchTree<T>::HelpInsert(Node*& root, Node* node) {

	
	//Base case
	if (root == nullptr)
	{
		root = node;

		if (root->value.length() > 3){
			ThreeWord++; // unique 3 word
		}

		words++; // unique word

		
		return;
	}

	if (root->value == node->value)
	{
		root->instance++;
		DuplicateCount++;
		delete node;
		
		return;
	}

	// both recursive cases
	else if(node->value < root->value)
	{
		HelpInsert(root->Left, node);
	}
	
	else
	{
		HelpInsert(root->Right, node);
	}

}


template <typename T>
void BinarySearchTree<T>::Remove(T data)
{
	  HelpRemove(Root, data);
}


template <typename T>
void BinarySearchTree<T>::HelpRemove(Node* root, T data)
{
	if (Search(data))
	{

	}
}




template <typename T>
bool BinarySearchTree<T>::Search(T data)
{
	return HelpSearch(Root, data) != nullptr;
}


template <typename T>
typename BinarySearchTree<T> ::Node* BinarySearchTree<T>::HelpSearch(Node* root, T data)
{
	//base case (item is not in the tree) 
	if (root == nullptr) {
		return nullptr;
	}
	//base case (finding the value) 
	else if (root->value == data)
	{
		return root;
	}
	//recursive case
	else if (root->value < data)
	{
		return HelpSearch(root->Left, data);
	}
	else
	{
		return HelpSearch(root->Right, data);
	}


}


template <typename T>
void BinarySearchTree<T>:: display()
{
	HelpDisplay(Root);
}

template <typename T>
void BinarySearchTree<T>::HelpDisplay(Node* root)
{
	if (root != nullptr)
	{
		HelpDisplay(root->Left);
		cout << root->value << " " << root->instance << endl;
		HelpDisplay(root->Right);
	}

}