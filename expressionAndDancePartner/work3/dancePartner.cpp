#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int main() {
	fstream file("DancePartner.txt");
	string buf;

	queue<string> boy;
	queue<string> girl;
	while (file)
	{
		buf.clear();
		getline(file, buf);
		if (buf.length() == 0)
			break;
		cout << buf << endl;
		//cout << buf[buf.size() - 1]<<endl;
		if (buf[buf.size() - 1] == 'M') {
			boy.push(buf.substr(0,6));
		}
		else {
			girl.push(buf.substr(0,6));
		}
	}
	//cout << "========"<<endl;
	//for (auto i : boy) {
	//	cout << i << endl;
	//}
	//for (auto i : girl) {
	//	cout << i << endl;
	//}
	for (size_t i = 0; i < 15; i++)
	{
		buf.clear();
		cout << i<<"  "<<boy.front() << "  " << girl.front() << endl;
		buf = boy.front();
		boy.pop();
		boy.push(buf);

		buf = girl.front();
		girl.pop();
		girl.push(buf);
	}


	system("pause");
}