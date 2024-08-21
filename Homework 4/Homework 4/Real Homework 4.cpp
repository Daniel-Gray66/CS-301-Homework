#include <string>
#include "StackType.h"
#include "ItemType.h"
#include <fstream>
#include <iostream>
using namespace std;

//Function Lists
void Print(string, string);
int Precedence(char);
bool Operators(char);
void infix2Post();

int main()
{
    try
    {
       infix2Post();
    }
    catch (const char* error)
    {
        cout << error << endl;
    }
    catch (...)
    {
        cout << "Something bad happened" << endl;
    }
  

     //ending program
    return 0;
}


void infix2Post()
{
    StackType Stack;
    fstream Input;
    ofstream Output;
    string PostFixString;
    string Infix;
   

    //opening files
    Input.open("Infix.txt");
    Output.open("Output.txt");

    //checking if the files did open 
    if (!Input.is_open()){
        throw "couldnt open infix file";
    }

    if (!Output.is_open()) {
        throw "couldnt open output file";
    }
    
    while (getline(Input, Infix))
    {
        //getting rid of the last character
        Infix = Infix.substr(0, Infix.size() - 1);
        cout << Infix << endl;
        
        //Clearing the previous poststring
        PostFixString.clear();
        int ParaDepth = 0;

        for (char c : Infix)
        {
            //if the symbol Scanned is an operand its adds to the post string
            if (c >= 'A' && c <= 'Z') {
                PostFixString += c;
            }

            // If the symbol is an operator
            else if (Operators(c)) {

                //Pushing the first thing onto the stack
                if (Stack.IsEmpty()) {
                    Stack.Push(c);
                    continue;
                }


                if (Precedence(Stack.Top()) >= Precedence(c)) {
                    PostFixString += Stack.Top();
                    Stack.Pop();
                    Stack.Push(c);
                    continue;
                }

                Stack.Push(c);
            }
            else if (c == '(') {
                Stack.Push(c);
                ParaDepth++;
                
                continue;
            }

            else if (c == ')')
            {
                while (Stack.Top() != '(')
                {
                    ItemType c1 = Stack.Top();
                    Stack.Pop();
                    PostFixString += c1;

                }
                ParaDepth--;
                Stack.Pop();
            }

        }
        if (ParaDepth != 0)
        {
            throw EmptyStack();
        }
     //pop everything into the postfix string
    while (!Stack.IsEmpty())
    {
     PostFixString += Stack.Top();
     Stack.Pop();
    }

        //Printing to console
        cout << "Infix: " << Infix << endl;
        cout << "Postfix " << PostFixString << endl;

        //Printing  to a file 
        Output << "Infix: " << Infix << endl;
        Output << "Postfix " << PostFixString << endl;

    }

    //Closing the file 
    Input.close();
    Output.close();
}


       
bool Operators(char symbol)
{
    if (symbol == '*' ||
        symbol == '/' ||
        symbol == '+' ||
        symbol == '-' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Precedence(char x) {
    switch (x)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/':
    case '%': return 2;
    default: return -1;
    }
}







