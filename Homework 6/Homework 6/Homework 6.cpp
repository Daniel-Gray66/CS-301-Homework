#include <fstream>
#include <iostream>
#include <string>
#include "BinarySearchTree.hpp"
#include <fstream>
using namespace std;

void Lexicon();





int main()
{
    try
    {
        Lexicon();
    }
    catch (const char* e)
    {
        cout << e;
    }
    catch (...)
    {
        cout << "Something bad happened in the program" << endl;
    }
    return 0;
    
}






void Lexicon() {
    BinarySearchTree<string> tree;
    ifstream infile;
    string word;
    infile.open("Info.txt");



    
    if (!infile.is_open())
    {
        throw "File did not open";
    }

    while (infile >> word)
    {
        tree.Insert(word);

    }

    tree.display();
    tree.stats();
        


}



