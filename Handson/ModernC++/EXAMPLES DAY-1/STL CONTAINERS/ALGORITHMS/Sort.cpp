#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class student
{
private:
   //...
   int id;
   int marks;
public:
	student(int x=0, int y=0):id(x),marks(y){ }
	void print() { cout <<"id = " << id << ",marks = " << marks << endl; } 
	int getmarks()
	{
		return marks;
	}
    bool operator()(student &s1, student &s2)
    {
		//s1.print();
		//cout <<"-----------"<<endl;
		//s2.print();
		bool result = (s1.getmarks() < s2.getmarks())?true:false;
		return result;
    }
};

void main()
{
	vector<student> ls1;
	student obj1;
	for(int i=1;i<=5;i++)
		ls1.push_back(student(i, i+50));
	sort(ls1.begin(), ls1.end(), obj1);
	vector<student>::iterator itr = ls1.begin();
	while(itr != ls1.end())
	{
		(*itr).print();
		itr++;
	}
}
