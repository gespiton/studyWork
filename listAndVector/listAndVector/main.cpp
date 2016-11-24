#include<iostream>
#include<string>
#include<stdio.h>
#include<map>
#include<time.h>
#include<thread>
#include<cstdlib>
#include<sstream>
#include"li_stu.h"
#include"v_stu.h"
using namespace std;
enum operation {
	E_add,
	//E_help,
	E_size,
	E_removeAt,
	E_clear,
	E_print,
	E_printAt,
	E_insert,
	E_find,
	//E_exit
};
map<string, operation> table{
	{ "add",E_add },
	//{ "help",E_help },
	{"size",E_size},
	{"remove",E_removeAt},
	{"clear",E_clear},
	{"print",E_print},
	{"insert",E_insert},
	{"find",E_find},
	{"printAt",E_printAt}
	//{}
};
void handle(base_stu* student ) {

	cout << "\noperation  :\nadd(para1)\nprint\nprintAt(para1)\nfind(para1)\nclear\nremove(para1)\ninsert(para1)\n" << endl;
	cout << "example:\nadd 3(add three element to table)\nremove 2(remove element at pos 2)\nfind Michale(find record about Michale)" << endl;
	while (true)
	{

		cout << "=================================================================="<<endl;
		cout << ">>> ";
		string fuc;
		getline(cin, fuc);
		stringstream getIt(fuc);
		string buf;


		operation ope;
		getIt >> buf;
		if (buf == "q") {
			cout << "goodbye" << endl;
			this_thread::sleep_for(2s);
			return;
		}

		if (buf == "find") {
			string name="";
			getIt >> name;
			student->find_byName(name);
			continue;
		}

		if (table.count(buf) == 0) {
			cout << "command not found! " << endl;
			continue;
		}
		int para1 = 0, para2 = 0;
		while ((!para1||!para2)&&(int(getIt.tellg())!=-1))                 // this fucking line
		{
			getIt >> (para1?para2:para1);
			if (getIt.fail()) {
				return handle(student);
			}
		}

		if (para1 < 0 || para2 < 0) {
			cout << "#parameter error" << endl;
			return handle(student);
		}
		cout << endl;
		//cout <<"your command:"<< buf<<" "<<para1 << " " << para2<<endl;
		
		// real opration
		switch (table[buf])
		{
		case E_size:
			student->size();
			break;
		case E_print:
			student->printAll();
			break;
		case E_printAt:
			student->printAt(para1);
			break;
		case E_add:
			if (!para1)
			{
				cerr << "#parameter error" << endl;
				return handle(student);
			}
			student->add(para1);
			break;
		case E_clear:
			student->clear();
			break;
		case E_removeAt:
			student->removeAt(para1);
			break;
		case E_insert:
			student->insertAt(para1);
			break;
		}


	}













	system("pause");
	//while (true)
	//{
	//	string para2 = "-1", para3 = "-1";
	//	int p1 = 0, p2 = 0;
	//beg:
	//	cout << ">>> ";

	//	cin >> para1;
	//	if (para1 == "q") {
	//		cout << "goodbye" << endl;
	//		this_thread::sleep_for(2s);

	//		return;
	//	}
	//	if (table.count(para1) == 0) {
	//		cout << "command not found! " << endl;
	//		goto beg;
	//	}

		//switch (table[para1])
		//{
		//case E_size:
		//	student->size();
		//	goto beg;
		//	break;
		//}


	//	try {
	//		cin >> para2;
	//		p1 = stoi(para2);
	//	}
	//	catch (...)
	//	{
	//		cout << "parameter error" << endl;
	//		goto beg;
	//	}

	//	switch (table[para1]) {
	//	case E_add:
	//		student->add(p1);
	//		student->printAll();
	//		break;
	//	case E_size:
	//		break;
	//	}
	//}
}
int start() {
	bool chose = true;
	while (true)
	{
		int i = 0;
		cout << "which kind of data_structure you wanna use? \n\n1.array\n2.list\n(chose by number)"<<endl;
		cin >> i;
		if (cin.fail() || (i != 1 && i != 2)) {
			cout << "#Error, please enter 1 or 2";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		i == 1 ? (chose = true) : (chose = false);
		break;
	}
	base_stu *student = nullptr;
	if (chose) student = new v_stu(); else student = new li_stu();
	cin.get();
	handle(student);
	

		
	return 0;
}
int main()
{
	start();
	//base_stu *n =new li_stu();
	//n->add(3);
	////n->clear();
	//n->printAll();
	////n->insertAt(2);
	//cout << endl;
	////n->printAll();
	//cout << endl;
	////n->find_byName("2");
	//cout << endl;
	//n->printAt(2);
	//n->size();
	//system("pause");
	////thread s = thread(start);
	////s.join();
	////s.
}

