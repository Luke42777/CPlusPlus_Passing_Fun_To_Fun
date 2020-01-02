#include <iostream>

using namespace std;
/////////////////////////////////////////////
struct Smatch
{
    virtual bool operator()(string other) = 0;
    virtual ~Smatch(){}

};
//////////////////////////////////////////////
struct SstringMatch: public Smatch
{
    string pattern;

public:
    SstringMatch(string ss): pattern(ss){}

    bool operator()(string other)override
    {
        return (pattern == other);
    }
};
//********************************************
void check(string text,Smatch& obj)
{
    if(obj(text))
        {
            cout << "match";
        }
    else
        {
            cout << " no match";
        }
}
//********************************************
int main()
{

 SstringMatch test1("real");

 cout << boolalpha << test1("barca");
 cout  << endl;
 check("real", test1);

}

