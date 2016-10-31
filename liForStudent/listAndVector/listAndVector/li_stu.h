#include<iostream>
#include<string>
#include<stdio.h>
#include<map>
#include<time.h>
#include<thread>
#include<cstdlib>
#include"base_stu.h"

//using boost;
using namespace std;
class li_stu:public base_stu
{
private:
	struct info
	{
		string stu_no;
		string name;
		int score;
	};
	struct stu_node
	{
		friend li_stu;
	private:
		stu_node * Pre = nullptr;
		stu_node * Next = nullptr;
		info cur_info;
	public:
		stu_node()
		{
			//            cur_info = new info();
		}
		stu_node(const info& _info, stu_node* pre = nullptr, stu_node* next = nullptr)
		{
			cur_info = _info;
			Pre = pre;
			Next = next;
		}
	};


	int len = 0;
	stu_node* head = nullptr;
	stu_node* tail = nullptr;


public:
	// big5
	li_stu()
	{
		head = new stu_node();
		tail = new stu_node(info(), head, nullptr);
		head->Next = tail;
	}

	~li_stu()
	{
		clear();
	}

	void add(int num = 1)
	{
		int i = 0;
		while ( i != num)
		{
			stu_node *buf = new stu_node();
			cout << "please enter information(\"student_number   name    score\") :" << endl;
			cin >> buf->cur_info.stu_no >> buf->cur_info.name >> buf->cur_info.score;
			if (cin.fail())
			{
				cout << "bad input" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			insert(tail, buf);
			++len;
			++i;
		}
		cin.clear();
		cin.ignore(100, '\n');
	}
	void insert(stu_node* &pos, stu_node* &src)
	{
		auto buf = pos->Pre;
		pos->Pre = src;
		src->Next = pos;
		src->Pre = buf;
		buf->Next = src;
	}

	void insertAt(int pos) {
		if (pos<0 || pos>len) {
			cout << "#pos out of range" << endl;
			return;
		}
		while (true)
		{
			stu_node *des = head->Next;
			for (int i = 0; i < pos; i++)
			{
				des = des->Next;
			}
			stu_node *buf = new stu_node();
			cout << "please enter information(\"student_number   name    score\") :" << endl;
			cin >> buf->cur_info.stu_no >> buf->cur_info.name >> buf->cur_info.score;
			if (cin.fail())
			{
				cout << "bad input" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			insert(des, buf);
			++len;
			break;
		}
		cin.clear();
		cin.ignore(100, '\n');
	}

	void printAll() const
	{
		if (len == 0) {
			cout << "#empty list" << endl;
			return;
		}
		printf("          name       student number  score\n");
		int i = 1;
		for (auto ite = head->Next; ite != tail; ite = ite->Next, ++i)
		{

			printf("item[%3d] %-10s %-15s %-3d\n", i-1, ite->cur_info.name.data(), ite->cur_info.stu_no.data(), ite->cur_info.score);

		}
	}

	void printAt(stu_node* const & ite,int i) const {
		printf("item[%3d] %-10s %-15s %-3d\n", i, ite->cur_info.name.data(), ite->cur_info.stu_no.data(), ite->cur_info.score);
	}



	

	void printAt(int pos) const
	{
		int i = 0;
		if (i >= len||i<0)
		{
			cerr << "index out of range";
			return;
		}
		for (auto ite = head->Next; ite != tail; ite = ite->Next, ++i)
		{
			if (i == pos)
			{
				printf(" name       student number  score\n");
				printf(" %-10s %-15s %-3d\n", ite->cur_info.name.data(), ite->cur_info.stu_no.data(), ite->cur_info.score);
				return;
			}
		}
	}

	void removeAt(int pos)
	{
		if (pos >= len)
		{
			cerr << "index out of range" << endl;
			return;
		}
		int i = 0;
		for (auto ite = head->Next; ite != tail; ite = ite->Next, ++i)
		{
			if (i == pos)
			{
				ite->Pre->Next = ite->Next;
				ite->Next->Pre = ite->Pre;
				delete ite;
				return;
			}
		}
	}
	void find_byName(string _name) const
	{

		int i = 0;
		bool found = false;
		for (auto ite = head->Next; ite != tail; ite = ite->Next,++i)
		{
			if (ite->cur_info.name == _name)
			{
				printAt(ite,i);
				found = true;
			}
		}
		if(!found)
			cout << "not found" << endl;
	}

	void size() const
	{
		cout << "size :"<<len << endl;
	}

	void clear()
	{
		for (auto ite = head->Next; ite != tail;)
		{
			auto buf = ite;
			ite = ite->Next;
			delete buf;
			len = 0;

		}
		cout << "#cleared" << endl;
	}

	static void help()
	{
		cout << "This is a list which can store the information about the student's name,number and price." << endl;
	}
};