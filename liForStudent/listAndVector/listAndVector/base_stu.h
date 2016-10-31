#pragma once
#include<string>
using namespace std;
class base_stu
{
public:
	virtual void add(int) = 0;
	//virtual void print(int) const = 0;
	virtual void clear() = 0;
	virtual void find_byName(string) const= 0;
	virtual void insertAt(int) = 0;
	virtual void printAll() const = 0;
	virtual void printAt(int) const = 0;
	virtual void removeAt(int) = 0;
	virtual void size() const= 0;

	/*virtual ~base_stu()=0;*/
};

