#include "unsorted.h"
#include "ItemType.h"
#include <map>
#include <fstream>
#include <iostream>
#include <string>

//Keeping track of all Highest Score Permutation
unsigned ItemType::Highest = 0;


//For the John Trotter algorithem keeping track of the Direction and Value
struct Record {
    bool Dir;
    int Val;
};


//These Are more homeowrk #1 functions 
void JohnTrotter(int const, ItemType*);
int factorial(int);
int FindMobileIndex(Record*, int);

//HomeWork #2 Functions 
void ComparePermutation(Record*, const int, ItemType*);
unsigned Score(ItemType*,  int, ItemType);
ItemType* Userinfo(int);


int main()
{
    
    const int size = 12; 
    ItemType* Volunteer;
    Volunteer = Userinfo(size); // getting all the information from the dat file.

       
    JohnTrotter(size, Volunteer);
    delete[] Volunteer;
        
   
    return 0;
}

void JohnTrotter(int n, ItemType* T) {
    // Array given to print every permutation
    Record* List = new Record[n];

    // Initialize direction and values
    for (int i = 0; i < n; i++) {
        List[i].Dir = false; // All initially pointing left
        List[i].Val = i + 1; // Values from 1 to n
    }

    int loopCount = factorial(n); // Counting the amount of permutations 
    ComparePermutation(List, n, T);
    for (int i = 1; i < loopCount; i++) {

        // Find the mobile index
        int mobileIndex = FindMobileIndex(List, n);

        // Swap k and the element to which it is directed
        int DirMobile = List[mobileIndex].Dir ? 1 : -1;
        Record a = List[mobileIndex];
        List[mobileIndex] = List[mobileIndex + DirMobile];
        List[mobileIndex + DirMobile] = a;

        // Reverse the direction of all numbers greater than k
        for (int j = 0; j < n; j++) {
            if (List[j].Val > List[mobileIndex + DirMobile].Val) {
                List[j].Dir = !List[j].Dir;
            }
        }
        ComparePermutation(List, n, T);
    }
    delete[] List;
}

int factorial(int n) {
    int TotalPermutations = 1;
    for (int i = 1; i <= n; ++i) {
        TotalPermutations *= i;
    }
    return TotalPermutations;
}

int FindMobileIndex(Record* List, int size) {
    int mobileMax = -1;
    int mobileIndex = -1;

    for (int i = 0; i < size; i++) {
        int Point = List[i].Dir ? 1 : -1;
        if (List[i + Point].Val >= 0 && List[i + Point].Val < size &&
            List[i + Point].Val < List[i].Val && List[i + Point].Val != 0) {
            if (List[i].Val > mobileMax) {
                mobileMax = List[i].Val;
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

void ComparePermutation(Record* List, const  int size, ItemType* Volunteer) {

    ItemType temp;
    UnsortedType T;
    unsigned total = 0;
   
    //adding all the iteams in the list
    for (int i = 0; i < size; i++)
    {
        unsigned Scores = 0;
        temp.Initialize(List[i].Val);
        temp.SetAssigned(List[i].Val);
        temp.SetName(Volunteer[i].GetName());
        T.PutItem(temp);
       Scores =  Score(Volunteer, i, temp);
       if (Scores != 0)
       {
           total = total + Scores;
       }
    }
   
    T.ResetList();
  

    ItemType  temps;
    if (total > ItemType::Highest) {
        ItemType::Highest = total;
        cout << "CURRENT SCORE: " << total << endl;
        for (int i = 0; i < size; i++) {
            T.GetNextItem().Print();
        }
        T.ResetList();
        cout << endl;
        cout << endl;
    }

}

/*Description: This Function is Supposed to read in all the infomration from the user's dat file.
* 
* Input: An array of ItemTypes to keep track of all the infomration per volunteer.
* 
* Output: An a array of ItemTypes that has all the information of the users name and three preffered months. 
* 
*/

ItemType* Userinfo(int size) {

    ItemType* Volunteer = new ItemType[12];
    ifstream Myfile;
    Myfile.open("Volunteers.Dat");
    string name;
    int one;
    int two;
    int three;
    one = 0;
    two = 0;
    three = 0;
   
    //looping through the file and gathering all the data
    for (int p = 0; p < size; p++)
    {
        Myfile >> name >> one >> two >> three;

        Volunteer[p].SetName(name);
        Volunteer[p].SetFirst(one); 
        Volunteer[p].SetSecond(two);
        Volunteer[p].SetThird(three);
    }
    return Volunteer;

}

//Three points for the choise
//2 points for the second choice
// 1 point for the Third choice
unsigned Score(ItemType* Volunteers, int i, ItemType T) {
    int Sum;
    Sum = 0;
  
        if (Volunteers[i].GetFirst() == T.GetAssigned())
        {
            Sum = Sum + 3;
        }
        else if (Volunteers[i].GetSecond() == T.GetAssigned()) {
            Sum = Sum + 2;
        }

        else if (Volunteers[i].GetThird() == T.GetAssigned()) {
            Sum = Sum + 1;
          
        }
        return Sum;
}

