#include<iostream>
#include<string>
#include<stack>
#include<map>
#include<utility>
#include<sstream>
#include<vector>
#include<functional>
using namespace std::placeholders;
using namespace std;

map<char, int> priority{
	{'+',1},
	{'-',1},
	{'*',2},
	{'/',2},
	{'(',3},
	{')',3}
};
map<char, int> calTable{
	{'+',0},
	{'-',1},
	{'*',2},
	{'/',3}
};
//class Cal
//{
//public:
//	Cal() {
//		//cal['+'] = bind(&Cal::add,_1,_2);
//		cal[0] = Cal::add;
//	}
//	//static map<char,function<double(double, double)>>cal;
//	static function<double(double, double)> cal[4];
//	static double add(double lhs, double rhs) {
//		return lhs + rhs;
//	}
//	static double sub(double lhs, double rhs) {
//	 	return lhs - rhs;
//	 }
//	static double mutiply(double lhs, double rhs) {
//	 	return lhs*rhs;
//	 }
//	static double divi(double lhs, double rhs) {
//		return lhs / rhs;
//	}
//
//};
double add(double lhs, double rhs) {
	return lhs + rhs;
}
double sub(double lhs, double rhs) {
 	return rhs - lhs;
}
 double muti(double lhs, double rhs) {
 	return lhs*rhs;
}
 double divi(double lhs, double rhs) {
	return rhs / lhs;
}

string inToPostFic(string src);

int main() {
	//Cal c;



	//cout << (Cal::cal['+'])(2, 3);

	function<double(double, double)> cal[4];
	cal[0] = add;
	cal[1] = sub;
	cal[2] = muti;
	cal[3] = divi;


	vector<double> num;
	vector<char> opt;

	string buf;
	cout << "enter expression:"<<endl;
	cin >> buf;
	//string src =  ;

	stringstream in(inToPostFic(buf));

	//cout << inToPostFic(buf) << endl;
	while (in)
	{
		buf.clear();
		in >> buf;

		if (buf.length() == 0)
			break;

		try
		{
			//string bufS = buf;
			double n = stod(buf);
			num.push_back(n);
			continue;
		}
		catch (const std::exception&)
		{
			//opt.push_back(buf[0]);
			double res = (cal[calTable[buf[0]]])(num[num.size() - 1], num[num.size() - 2]);
			num.pop_back();
			num.pop_back();
			num.push_back(res);
		}
	}
	cout << num[0] << endl;

	//for each (auto var in num)
	//{
	//	cout << var << endl;
	//}

	//for each (auto var in opt)
	//{
	//	cout << var << endl;
	//}





	system("pause");
}
string inToPostFic(string src) {
	vector<double> num;
	vector<char> opt;
	string result;
	stringstream in(src);
	while (in)
	{
		char p = in.peek();

		if (p > 47 && p < 58) {
			double buf;
			in >> buf;
			//cout << buf << endl;

			result += to_string(buf);
			result += " ";

			//num.push(buf);
		}
		else
		{
			char buf='#';
			in >> buf;
			if (buf == '#') {
				while (opt.size())
				{
					result += opt.back();
					result += " ";
					opt.pop_back();
				}
				break;
			}
			//cout << buf << endl;


			if (opt.size() == 0) {
				opt.push_back(buf);
				continue;
			}


			while(opt.size()&&priority[opt.back()] >= priority[buf] && opt.back()!='(') 
			{
				result += opt.back();
				result += " ";

				opt.pop_back();
			}

			if (buf == ')') {
				while (opt.back()!='(')
				{
					result += opt.back();
					result += " ";

					opt.pop_back();
				}
				opt.pop_back();
			}
			else
			{
				opt.push_back(buf);
			}
		}
	}
	return result;
	//for (size_t i = 0; i < 10; i++)
	//{
	//	int ii=0;
	//	in >> ii;
	//	cout << ii << endl;
	//}
	return string();
}