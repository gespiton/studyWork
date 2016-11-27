#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
class Data {
private:
	vector<double> storage;

public:
	bool bad = false;
	Data() {
		storage.clear();
	}
	void insert(double i) {
		storage.push_back(i);
	}

	void reArrange(int lhs, int rhs) {
		sort(storage.begin() + lhs-1, storage.begin() + rhs);
	}


	void print() {
		for each (double var in storage)
		{
			cout << var << "  ";
		}
		cout << endl;
	}


	bool check() {
		return storage.size();
	}
	int size() {
		return storage.size();
	}


};

void handle_input() {
	Data New = Data();
	cout << "please entering number to start(press q to stop) :" << endl;


	// so much for input 
	string buf = "";
	while (true) {
		cout << ">>>";
		cin >> buf;
		if (buf == "q") {
			if (!New.check()) {
				cout << "can't do nothing without number, goodbye" << endl;
				return;
			}
			break;
		}
		try {
			New.insert(stod(buf));
		}
		catch (invalid_argument) {
			cout << "number only";
		}
		cout << endl;
		New.print();
	}


	cout << "-----------------------------------" << endl;
	cout << "all: ";
	New.print();
	cout << "-----------------------------------" << endl << endl << endl;



	cout << "now enter the range you wanna sort through, press q to quit" << endl;
	buf = "";
	int lhs = 0, rhs = 0;
	while (!(lhs&&rhs))
	{
		cout << ">>> ";
		cin >> buf;
		if (buf == "q") {
			cout << "goodbye" << endl;
			return;
		}
		try
		{
			auto num = stoi(buf);
			if (num<0 || num>New.size()) {
				cout << "number out of range" << endl;
				continue;
			}
			if (lhs) {
				if (num <= lhs) {
					cout << "must bigger than " << lhs << endl;
					continue;
				}
			}
			(lhs?rhs:lhs) = stoi(buf);
		}
		catch (invalid_argument)
		{
			cout << "number only" << endl;
			continue;
		}
	}
	cout << "after sorted range " << lhs << ":" << rhs << endl;
	New.reArrange(lhs, rhs);
	New.print();
	//////// operation begin now 
	//////cout << "now, select you operation, press n to exit" << endl;
	//////buf = "";
	//while (true)
	//{
	//	cout << "1 -----mean\n2 -----stdev\n3 -----mid\n(press number to proceed, q to quit)" << endl;
	//	cin >> buf;

	//////	if (buf == "q") {
	//////		cout << "goodbye" << endl;
	//////		return;
	//////	}

	//////	int ope = 0;

	//////	try
	//////	{
	//////		ope = stoi(buf);
	//////	}
	//////	catch (invalid_argument)
	//////	{
	//////		cout << "invaid command" << endl;
	//////		continue;
	//////	}


	//////	if (ope < 1 || ope>3) {
	//////		cout << "please enter 1,2,3 " << endl;
	//////		continue;
	//////	}

	//////	switch (ope)
	//////	{
	//////	case 1:
	//////		cout << "-----------------------------------" << endl;
	//////		cout << "the arvarage num :" << New.mean() << endl;
	//////		cout << "-----------------------------------" << endl;

	//////		break;
	//////	case 2:
	//////		cout << "-----------------------------------" << endl;
	//////		cout << "the standard deviation :" << New.stdev() << endl;
	//////		cout << "-----------------------------------" << endl;
	//////		break;
	//////	case 3:
	//////		cout << "-----------------------------------" << endl;
	//////		cout << "the median :" << New.mid() << endl;
	//////		cout << "-----------------------------------" << endl;

	//////	}
	//}

}
int main() {
	//auto me = Data();
	//me.insert(30);
	//me.insert(10);
	//me.insert(20);
	////me.insert(30);
	//me.print();

	//me.reArrange(1, 2);
	//me.print();
	handle_input();

}