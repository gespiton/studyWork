#pragma once
#include<iostream>
#include<string>
#include"base_stu.h"
using namespace std;
class v_stu:public base_stu
{
	struct info {
		info() {}
		info(string name_, string stu_number_, int score_) :name(name_), Stu_number(stu_number_), score(score_) {}
		string Stu_number = "";
		string name = "";
		int score = 0;
	};
private:

	info * begin;
	int mySize = 5;
	int capacity = 5;
	int stu_num = 0;
public:
	//big5
	v_stu() {
		begin = new info[5];
	}
	v_stu(int size) {
		begin = new info[size];
		size = size;
		capacity = size;
	}

	v_stu(const v_stu& stu) {
		begin = new info[stu.stu_num*2];
		copy(stu);
		mySize = stu.stu_num*2;
		stu_num = stu.stu_num;
		capacity = stu.stu_num;
	}

	void add(int num) {
		check(num);
		for (int i = 0; i != num; ++i) {
			info buf;
			cout << "please enter information(\"student_number   name    score\") :" << endl;
			//            try {
			cin >> buf.Stu_number >> buf.name >> buf.score;

			//            } catch (...) {
			//                cout<<"error recording"<<endl;
			//                cout<<"quit....";
			//                throw("wrong");
			//            }
			if (cin.fail()) {
				cout << "bad input" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				--i;
				continue;
			}
			begin[stu_num] = buf;
			++stu_num;
			--capacity;
		}

		cin.clear();
		cin.ignore(100, '\n');
	}


	void insert(int pos, const info& scr) {

		if (capacity<1) {
			check(2);
		}
		if (pos > stu_num) {
			cerr << "insert index out of range" << endl;
			return;
		}
		for (int i = stu_num; i != pos; --i) {
			begin[i] = begin[i - 1];
		}
		begin[pos] = scr;
		++stu_num;
		--capacity;
	}

	info& operator[](int i) {
		return begin[i];
	}

	const info& operator[](int i)const {
		return begin[i];
	}




	void size() const {
		cout << "size: "<<stu_num << endl;
	}

	void copy(const v_stu& stu, info* dest = nullptr) {
		info *buf = nullptr;

		if (dest) {
			buf = dest;
		}
		else {
			buf = begin;
		}

		for (int i = 0; i != stu.stu_num; ++i) {
			buf[i] = stu.begin[i];
		}

	}

	void check(int dest_size) {

		if (dest_size > capacity) {
			auto buf_begin = new info[mySize + 2 * dest_size];
			copy(*this, buf_begin);
			delete[] begin;
			mySize += 2 * dest_size;
			capacity += 2 * dest_size;
			begin = buf_begin;
		}
	}


	void printAll () const {
		if (stu_num == 0) {
			cout << "#empty list" << endl;
			return;
		}
		printf("          name       student number  score\n");
		for (int i = 0; i != stu_num; ++i) {
			//            cout<<begin[i].name<<"  "<<begin[i].Stu_number<<"   "<<begin[i].score<<endl;
			printf("item[%3d] %-10s %-15s %-3d\n", i, begin[i].name.data(), begin[i].Stu_number.data(), begin[i].score);
		}
	}


	void printAt(int pos) const{
		if (pos<0 || pos>stu_num - 1) {
			cerr << "index out of range" << endl;
			return;
		}
		printf("item[%3d] %-10s %-15s %-3d\n", pos + 1, begin[pos].name.data(), begin[pos].Stu_number.data(), begin[pos].score);
	}

	void print_info()const {
		printf("item number:%-5d array size: %-5dcapacity: %-5d\n", stu_num, mySize, capacity);
	}


	void find_byName(string name)const {
		bool found = false;
		for (int i = 0; i < stu_num; i++)
		{
			if (begin[i].name == name) {
				printAt(i);
				found = true;
			}
		}
		if(!found)
			cout << "#Error : record not found" << endl;
	}

	void insertAt(int pos) {
		if (pos > stu_num || pos<0) {
			cerr << "pos out of range" << endl;
			return;
		}
		while(true) {
			info buf;
			cout << "please enter information(\"student_number   name    score\") :" << endl;
			//            try {
			cin >> buf.Stu_number >> buf.name >> buf.score;

			//            } catch (...) {
			//                cout<<"error recording"<<endl;
			//                cout<<"quit....";
			//                throw("wrong");
			//            }
			if (cin.fail()) {
				cout << "bad input" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			insert(pos, buf);
			break;
		}
		cin.clear();
		cin.ignore(100, '\n');
	}

	void removeAt(int pos) {
		for (int i = pos; i < stu_num; i++)
		{
			begin[i] = begin[i + 1];
		}

		--stu_num;
		++capacity;
		begin[stu_num] = info();
	}


	void clear() {
		delete[] begin;
		begin = nullptr;
		capacity = mySize;
		stu_num = 0;
	}


	~v_stu() {
		//base_stu::~base_stu();
		delete[] begin;
	}
};

