#pragma once
#include<vector>
#include<iostream>
#include<map>
using namespace std;
template<typename T,typename comp=less<T>>
class Queue {
private:
	vector<T> data;
	map<T, int> lookUp;



	void initTB(){
		for (size_t i = 0; i < data.size(); i++)
		{
			lookUp[data[i]] = i;
		}
	}


	void exchange(unsigned l, unsigned r) {
		// updata lookup table
		lookUp[data[l]] = r;
		lookUp[data[r]] = l;

		T buf = data[l];
		data[l] = data[r];
		data[r] = buf;
	}

	void heapify(unsigned i);

	void build_heap();
	
	unsigned Left(unsigned i) {
		return i << 1;
	}
	unsigned Right(unsigned i) {
		return (i << 1)+1;
	}
	unsigned Parent(unsigned i) {
		return i >> 1;
	}

public:
	Queue() {

	}

	Queue(std::initializer_list<T> li):data(li) {
		//comp f = comp();
		//cout << f(5, 4);
		build_heap();
		initTB();
		
	}

	bool isEmpty() {
		return data.size() == 0;
	}

	void print() {
		cout << "==========heap===========" << endl;
		for each (auto var in data)
		{
			cout << var<<":"<<lookUp[var] << " ";
		}
		cout << endl << "--------------------------"<<endl;
	}

	T    top() {
		if(!isEmpty())
			return data[0];
		return T();
	}

	T    deQueue();

	void adjust(const T&t);

	void changeV(unsigned i, const T& t);

	void enQueue(const T& t);

	int  getIndex(const T&t) {
		return lookUp.count(t) != 0 ? lookUp[t] : -1;
	}
};

template<typename T, typename comp>
void Queue<T, comp>::heapify(unsigned i)
{
	// this i is index + 1
	// due to the problem of the array index start from zero, -1
	auto l = Left(i)-1;
	auto r = Right(i)-1;
	unsigned smallest = --i;
	comp f;

	if (l<data.size() && f(data[smallest],data[l]))
		smallest = l;
	if (r<data.size()&& f(data[smallest], data[r]))
	{
		smallest = r;
	}

	if (smallest != i)
	{
		exchange(smallest, i);
		heapify(smallest+1); // because we decrement the index before, so we have to add one here
	}
}


template<typename T, typename comp>
void Queue<T, comp>::build_heap()
{
	for (int i = data.size()/2; i >0 ; --i)
	{
		heapify(i);
	}

}


template<typename T, typename comp>
T Queue<T, comp>::deQueue()
{
	auto buf = data[0];
	data[0] = data[data.size() - 1]; lookUp[data[0]] = 0;
	data.pop_back();
	heapify(1);
	return buf;
}


template<typename T, typename comp>
void Queue<T, comp>::adjust(const T & t)
{
	comp f;
	unsigned i = lookUp[t]+1;  // index 
	unsigned l = Left(i) - 1;
	unsigned r = Right(i) - 1;
	bool down = true;

	if (i==data.size()||l>=data.size()) // if that is the last element in the queue,or has no child
	{
		down = false;
	}

	// try to go up
	if (down&&(f(t,data[l])||(r<data.size()&&f(t,data[r]))))
	{
		// go down
		return heapify(i);
	}
	else
	{
		--i; 
		while (i>0)
		{
			unsigned p = i % 2 ? i / 2 : i / 2 - 1; // because the index start in 0
			if (f(data[p], data[i]))
			{
				exchange(p, i);
				i = p;
			}
			else {
				return;
			}
		}
	}

}


template<typename T, typename comp>
void Queue<T, comp>::changeV(unsigned i,const T& t)
{
	if (data.size()<1||i>=data.size())
	{	
		return;
	}
	else {
		comp f;
		if (f(data[i],t))
		{	// go up
			data[i] = t;
			lookUp[t] = i;
			while (i>0)
			{
				unsigned p = i % 2 ? i / 2 : i / 2 - 1; // because the index start in 0
				if (f(data[p],data[i]))
				{
					exchange(p, i);
					i = p;
				}
				else {
					return;
				}
			}
		}
		else
		{
			//go down
			data[i] = t;
			lookUp[t] = i;
			heapify(i+1);  //index problem again
		}
	}

}


template<typename T, typename comp>
void Queue<T, comp>::enQueue(const T & t) {
	if (lookUp[t] != 0)  // don't allow multiple node
		return;
	data.push_back(T());          // what is T() equals to t
	lookUp[t] = data.size() - 1;
	changeV(data.size() - 1, t);
}
