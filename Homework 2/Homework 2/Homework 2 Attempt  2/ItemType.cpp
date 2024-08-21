// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include "ItemType.h"

ItemType::ItemType()
{ 
  value = 0;

}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(int number) 
{
  value = number;
}


/// <summary>
/// Description: Need to print out the month assigned to the volunteer along with their name.
/// Instead of looping through an array of containnig all the months, I decided to use a map that can use an 
/// int (key) to map to its corresponding month. Makign this fucntion constant time O(1) Time.
/// 
/// Input: None
/// 
/// Output: The Month and the corresponding name of the volunteer
/// 
/// </summary>
void ItemType::Print() 
{
    
    map<int, string> Months;
    Months[1] = "January";
    Months[2] = "Febuary";
    Months[3] = "March";
    Months[4] = "April";
    Months[5] = "May";
    Months[6] = "June";
    Months[7] = "July";
    Months[8] = "August";
    Months[9] = "September";
    Months[10] = "October";
    Months[11] = "November";
    Months[12] = "December";
    cout << setw(18) <<  Months[this->GetAssigned()] << setw(18) << this->GetName() << endl;
    
}

//setters (mutators)
void ItemType:: SetName(string name) {
    this->Name = name;
}
void ItemType::SetFirst(int first) {
    this->First = first;
}
void ItemType::SetSecond(int second) {
    Second = second;
}
void ItemType::SetThird(int third) {
    this->Third = third;
}
void ItemType:: SetAssigned(int assigned) {
    this->Assigned = assigned;
}

//getters (observers)
string ItemType:: GetName() {
    return Name;
}
int  ItemType::GetFirst() {
    return First;
}
int ItemType:: GetSecond() {
    return Second;
}
int ItemType:: GetThird() {
    return Third;
}
int ItemType:: GetAssigned() {
    return Assigned;
}