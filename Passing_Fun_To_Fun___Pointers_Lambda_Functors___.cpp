#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//***********************************************************************
bool Is_5_letters(string word)
{
    return (word.size() == 5);
}
//*********************************************************************
int countingAlgorithm(vector<string>vec, bool (*crit)(string))
{
    int how_many{}; // or int how_many = 0;

    for(string ele: vec)
    {
        if(crit(ele))
            {
                how_many++;
            }
    }
    return how_many;

}
//////////////////////////functor class(struct)//////////////////////////////////////
struct Is_chosen_lenght_letters
{
    int lettersNo;
    Is_chosen_lenght_letters(int letNo): lettersNo(letNo) {}

    bool operator()(string s)
    {
        return (s.size() == lettersNo);
    }
};
//*******************************************************************************
int countingAlgorithm(vector<string>vec, Is_chosen_lenght_letters obj)
{
    int how_many{}; // or int how_many = 0;

    for(string ele: vec)
    {
        if(obj(ele))
            {
                how_many++;
            }
    }
    return how_many;

}
//****************************************************************************
int main()
{
   vector<string>words;

   words.push_back("one");
   words.push_back("two");
   words.push_back("three");
   words.push_back("one");
   words.push_back("two");
   words.push_back("three");
   words.push_back("one");
   words.push_back("two");
   words.push_back("three");
   words.push_back("one");
   words.push_back("two");
   words.push_back("three");

///using lambda expression and count_if function
int letterNumber = 5;
int how_many_1 = count_if(words.begin(),words.end(),[letterNumber](string word){if(word.size() == letterNumber) return true;});
cout << how_many_1 << endl;

///passing function to template count_if function
int how_many_2 = count_if(words.begin(),words.end(),Is_5_letters);
cout << how_many_2 << endl;


///using self defined counting algorithm function(passing pointer to algorithm fun)
bool (*pIs_5_letters)(string) = &Is_5_letters;
int how_many_3 = countingAlgorithm(words,pIs_5_letters);
cout << how_many_3 <<endl;


///using self defined counting algorithm function- passing functor"object of class that has overloaded operator ()"
int how_many_4 = countingAlgorithm(words,Is_chosen_lenght_letters(5));
cout << how_many_4;

}



