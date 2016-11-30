#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<sstream>
//#include"Dijsktra.hpp"
using namespace std;
class Graph
{
public:
	Graph(string file) {
		fstream File(file, ios::in);
		if (getInfo(File) && storeGraph(File))
		{

		}
		else
		{
			return;
		}
	}

	map<string, string>& getDescription() {
		return description;
	}
	map<string, list<string>>& getEdges() {
		return edges;
	}
	map<string, map<string, int>>& getEdgeLen() {
		return edgeLen;
	}


	int intermediate;
	int edge;
	map<string, string>description;
	map<string, list<string>>edges;
	map<string, map<string, int>> edgeLen;
	vector<string> spot;
	~Graph(){}
private:
	//friend Dijsktra;


	bool getInfo(fstream& file) {
		string buf1, buf2;
		file >> buf1>>buf2;
		try {
			intermediate = stoi(buf1);
			edge = stoi(buf2);
		}
		catch(...){
			cerr << "wrong file format" << endl;
			return false;
		}
		return true;
	}


	bool storeGraph(fstream&file) {
		// get description and store order
		for (size_t i = 0; i < intermediate; i++)
		{
			string buf;
			while (file.peek()=='\n'||file.peek()==' ')
			{
				getline(file,buf);
			}
			getline(file, buf);
			int prePos = buf.find_first_of('(');
			int postPos = buf.find_first_of(')');
			description[buf.substr(0, prePos)] = buf.substr(prePos+1, postPos - prePos-1);
			spot.push_back(buf.substr(0, prePos));
		}


		for (size_t i = 0; i < edge; i++)
		{
			string lhs, rhs,buf;
			int length;
			file >> lhs >> rhs >> buf;
			length = stoi(buf);

			edges[lhs].push_back(rhs);
			edges[rhs].push_back(lhs);
			edgeLen[lhs][rhs] = length;
			edgeLen[rhs][lhs] = length;
		}
		
		//for each (auto var in description)
		//{
		//	cout << var.first << "  :  " << var.second << endl;
		//}
		//cout << endl;

		//for each (auto var in edges)
		//{
		//	cout << var.first<<" :";
		//	for (auto &i : var.second)
		//		cout << i << " ";
		//	cout << endl;
		//}
		//cout << endl;

		//for each (auto var in edgeLen)
		//{
		//	cout << var.first << ":" << endl;
		//	for each (auto varr in var.second)
		//	{
		//		cout << varr.first << " ------ " << varr.second << endl;
		//	}
		//	cout << endl;
		//}
		return true;
	}


};

