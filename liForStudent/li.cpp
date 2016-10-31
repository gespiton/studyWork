#include<iostream>
#include<string>
#include<stdio.h>
#include<map>
#include<time.h>
#include<thread>
#include<cstdlib>
#include"aaa.h"
using namespace std;
enum operation {
	add,
	help,
	size,
	removeAt,
	clear,
	print,
	pritnAt,
	insert,
	find,
	exit
};
map<string, operation> table{
	{ "add",add },
	{ "help",help },{}
};
//void handle() {
//	cout << "useage:  " << endl;
//	string para1;
//	while (true)
//	{
//		string para2 = "-1", para3 = "-1";
//		int p1 = 0, p2 = 0;
//	beg:
//		cout << ">>> ";
//
//		cin >> para1;
//		if (para1 == "q") {
//			cout << "goodbye" << endl;
//			this_thread::sleep_for(2s);
//
//			return 0;
//		}
//		if (table.count(para1) == 0) {
//			cout << "command not found! " << endl;
//			goto beg;
//		}
//
//		switch (table[para1])
//		{
//		case size:
//			cout << student.size() << endl;
//			goto beg;
//			break;
//		}
//
//
//		try {
//			cin >> para2;
//			p1 = stoi(para2);
//		}
//		catch (...)
//		{
//			cout << "parameter error" << endl;
//			goto beg;
//		}
//
//		switch (table[para1]) {
//		case add:
//			student.add(p1);
//			student.print();
//			break;
//		case size:
//
//		}
//	}
//}
int start() {;
	auto student = v_stu();
}
int main()
{
	start();
	//thread s = thread(start);
	//s.join();
	//s.
}

