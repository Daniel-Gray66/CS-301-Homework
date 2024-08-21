// The following declarations and definitions go into file 
// ItemType.h. 

#ifndef ITEMTYPE_H
#define ITEMTYPE_H


#include <fstream>
#include <iostream>
using namespace std;
const int MAX_ITEMS = 12;
enum RelationType  {LESS, GREATER, EQUAL};


class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print() ;
  void Initialize(int number);
  static unsigned Highest;

  //setters (mutators)
  void SetName(string);
  void SetFirst(int);
  void SetSecond(int);
  void SetThird(int);
  void SetAssigned(int);
  
  //getters
  string GetName();
  int GetFirst() ;
  int GetSecond() ;
  int GetThird() ;
  int GetAssigned();


private:

  int value;
  string Name;
  int First;
  int Second;
  int Third;
  int Assigned;
  
};
 

#endif
