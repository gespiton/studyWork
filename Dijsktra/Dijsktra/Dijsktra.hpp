#pragma once
#include"Graph.hpp"
#include<queue>
#include<list>
#include"Queue.hpp"
using namespace std;
class Dijsktra
{
private:
	struct Vetex
	{
		Vetex(string n, string des) :name(n), description(des),p(nullptr),known(false) {
			distance = 100000;  // don't wanna find the infinity
		}

		string name;
		string description;
		vector<Vetex*> adj;
		size_t distance;
		Vetex* p;
		bool known;
	};
	struct comparator
	{
		// this is a function for comparision for Vetex
		bool operator()(Vetex*lhs, Vetex*rhs) {
			if (lhs==nullptr||rhs==nullptr)
			{
				return false;
			}
			return lhs->distance >= rhs->distance;
		}
	};
	map<string, Vetex*> table;
	Graph graph;
	list<Vetex*> V;
	//list<Vetex*> S;
	Queue<Vetex*, comparator> pQueue;

	void buildV() {
		for each (auto var in graph.description)
		{
			//table name->Vetex* , update V
			auto buf = new Vetex(var.first, var.second);
			V.push_back(buf);
			table[var.first] = buf;
		}

		for each (auto var in graph.edges)
		{
			// build the connection between Vetexes
			auto &bufV = table[var.first];
			for (auto &s : var.second) {
				bufV->adj.push_back(table[s]);
			}
		}

		/*for each (auto var in V)
		{
			cout << var->name << "  " << var->adj.size()<<endl;
		}*/
	}

	void dj(string s) {

		for each (auto v in V)
		{
			v->known = false;
			v->distance = 100000;
			v->p = nullptr;
			pQueue.enQueue(v);
		}

		Vetex* curV = table[s];
		curV->distance = 0;
		pQueue.adjust(curV);
		//pQueue.print();

		while (!pQueue.isEmpty())
		{
			curV = pQueue.deQueue();
			for each (auto v in curV->adj)
			{
				size_t d = curV->distance + graph.edgeLen[curV->name][v->name];
				if (!v->known&&d<v->distance)
				{
					v->distance = d;
					v->p = curV;
					
					pQueue.adjust(v);
					//cout << pQueue.top()->name << "  " << pQueue.top()->distance << endl;
				}
			}
			curV->known = true;
		}
	}
	
	string travelTo(Vetex* v);
public:
	void travel(string s,string des);
	Dijsktra(Graph& G):graph(G) {
		buildV();
	}

	~Dijsktra(){
		for each (auto var in V)
		{
			delete var;
		}
	}
	//priority_queue<Vetex*, vector<Vetex*>, comparator> pQueue;


};

void Dijsktra::travel(string s,string des) {
	

	dj(s);
	auto v = table[des];
	if (v!=nullptr)
	{
		cout << travelTo(v->p) + v->name;
		cout << "  distance : " << v->distance << endl;
	}

}

string Dijsktra::travelTo(Vetex * v)
{
	if (v==nullptr)
	{
		return "";
	}
	else
	{
		return travelTo(v->p) + v->name +"->";
	}
}

