#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
class Data {
private:
	vector<double> storage;
	void reArrange() {
		sort(storage.begin(), storage.end());
	}

public:
	bool bad = false;
	Data(){
		storage.clear();
	}
	void insert(double i) {
		storage.push_back(i);
		reArrange();
	}


	double mean() {
		if (check() == 0) {
			cerr << "no element to operate upon";
			return 0;
		}

		double sum = 0;
		for_each(storage.begin(), storage.end(), [&](double i) {
			sum += i;
		});
		return sum / storage.size();
	}


	double stdev() {
		if (check() == 0) {
			cerr << "no element to operate upon";
			return 0;
		}

		double _mean = mean();
		double _stdev = 0;
		for_each(storage.begin(), storage.end(), [&](double i) {
			_stdev += pow(i - _mean, 2);
		});
		_stdev /= storage.size();
		return sqrt(_stdev);
	}


	double mid() {
		if (check() == 0) {
			cerr << "no element to operate upon";
			return 0;
		}

		auto size = storage.size();

		if (size % 2==0) {
			return (storage[size / 2] + storage[size / 2 - 1])/2;
		}
		else {
			return storage[(size - 1) / 2];
		}
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
				cerr << "cant do nothing without any number, goodbye" << endl;
				return;
			}
			break;
		}
		try{
			New.insert(stod(buf));
		}
		catch(invalid_argument){
			cout << "number only";
		}
		cout << endl;
		//New.print();
	}


	cout << "-----------------------------------" << endl;
	cout << "all: ";
	New.print();
	cout << "-----------------------------------" << endl<<endl<<endl;



	// operation begin now 
	cout << "now, select you operation, press n to exit"<<endl;
	buf = "";
	while (true)
	{
		cout << "1 -----mean\n2 -----stdev\n3 -----mid\n(press number to proceed, q to quit)"<<endl;
		cin >> buf;

		if (buf == "q") {
			cout << "goodbye" << endl;
			return;
		}

		int ope = 0;

		try
		{
			ope = stoi(buf);
		}
		catch (invalid_argument)
		{
			cout << "invaid command" << endl;
			continue;
		}


		if (ope < 1 || ope>3) {
			cout << "please enter 1,2,3 " << endl;
			continue;
		}

		switch (ope)
		{
		case 1:
			cout << "-----------------------------------"<<endl;
			cout << "the arvarage num :" << New.mean() << endl;
			cout << "-----------------------------------"<<endl;

			break;
		case 2:
			cout << "-----------------------------------" << endl;
			cout << "the standard deviation :" << New.stdev() << endl;
			cout << "-----------------------------------" << endl;
			break;
		case 3:
			cout << "-----------------------------------" << endl;
			cout << "the median :" << New.mid() << endl;
			cout << "-----------------------------------" << endl;

		}
	}

}
int main() {
	//auto me = Data();
	//me.insert(10);
	//me.insert(20);
	////me.insert(30);
	//me.insert(30);
	//me.print();

	//cout << me.mid();
	handle_input();

}