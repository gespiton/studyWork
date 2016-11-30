#include<string>
#include<iostream>
#include"Graph.hpp"
#include<regex>
#include<Windows.h>
using namespace std;
class Manager
{
public:
	Manager(Graph g);
	~Manager();

	void Start();
	//void   displaySpot() {
	//	displaySpot(G);
	//}
private:
	void   displayGuide   ();
	string getCommand     ();
	int    verifyCommand  (string);
	bool   handleCommand  (int);
	void   displaySpot    ();
	void spotInfo();
	void travel();
	Graph G;
	Dijsktra dj;
	void holdon() {
		cout << "press enter to continue..." << endl;
		cin.ignore(1000, '\n');
		cin.get();
	}
};

Manager::Manager(Graph g) :G(g),dj(Dijsktra(g)){}

Manager::~Manager()
{
}
inline void Manager::Start()
{
	displaySpot();
	displayGuide();

	while (handleCommand(verifyCommand(getCommand()))) {
		system("cls");
		displaySpot();
		displayGuide();
	}
}
void Manager::displayGuide()
{
	cout << "============== Welcome to XMU ================" << endl;
	//cout << "           1.display tour spot   " << endl;
	//cout << "           2.check spot info   " << endl;
	cout << "           1.travel route inquery" << endl;
	cout << "           2.quit                " << endl;
	cout << "==============================================" << endl;
	cout << "please choose from 1-2:" << endl;
}


string Manager::getCommand() {
	cout << ">>> ";
	string buf;
	cin >> buf;
	return buf;
}

int Manager::verifyCommand(string s) {
	regex r("^[ ]*\\d[ ]*$");
	if (regex_match(s, r))
	{
		return stoi(s);
	}
	else
	{
		return -1;
	}
}

bool Manager::handleCommand(int c) {
	if (c == -1)
	{
		cerr << "#command error!" << endl<<endl;
		holdon();
		return true;
	}
	else
	{
		switch (c)
		{
		case 1:
			travel();
			return true;
		case 2:
			return false;
		default:
			cerr << "#command error!" << endl;
			holdon();
			return true;
		}
	}
}

void Manager::displaySpot() {
	cout <<endl<< "================== SPOT ======================" << endl;
	for (size_t i = 0; i < G.spot.size(); i++)
	{
		cout << i + 1 << ". " << G.spot[i] << "   ---" << G.description[G.spot[i]] << endl<<endl;
	}
	cout << "==============================================" << endl<<endl;
}


void Manager::spotInfo() {
	cout <<endl<< "enter the number of spot you wanna check(enter 0 to quit):" << endl;

	while (true) {
		// get the spot number
		cout << "|number|";
		int i = verifyCommand(getCommand());
		while(i==-1||i>=G.spot.size())
		{
			cerr << "#please enter valid number"<<endl;
			cout << "|number|";
			i = verifyCommand(getCommand());
		}

		switch (i)
		{
		case 0:
			return;
		default:
			cout << i << ". " << G.spot[i-1]<<"---"<<G.description[G.spot[i-1]] << endl;
			break;
		}

	}

}

inline void Manager::travel()
{
	system("cls");
	displaySpot();
	int s=-1, d=-1;
	while (true)
	{
		cout << "#enter the start place:" << endl;
		cout << "|From|";
		s = verifyCommand(getCommand());
		if (s == -1||s>G.spot.size())
		{
			cerr << "#please enter valid number" << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "#enter the destination:" << endl;
		cout << "|To|";
		d = verifyCommand(getCommand());
		if (d == -1||d>G.spot.size())
		{
			cerr << "#please enter valid number" << endl;
		}
		else
		{
			break;
		}
	}
	dj.travel(G.spot[s-1], G.spot[d-1]);
	holdon();
}
