#pragma once
#include<queue>
#include<iostream>
#include<map>
#include<string>
using namespace std;

class huffmanTree
{
private:
	struct treeNode
	{
		treeNode() :left(nullptr), right(nullptr), freq(0),character(0){}

		char character;
		treeNode* left;
		treeNode* right;
		int freq;
	};

	treeNode* root=nullptr;

	struct comparator
	{
		bool operator()(treeNode* lhs, treeNode* rhs) {
			return lhs->freq > rhs->freq;
		}
	};

	priority_queue<treeNode*, vector<treeNode*>, comparator> createHeap(map<char, int>table);

	void clear(treeNode*&);

	map<char, string> code;
public:
	huffmanTree(map<char,int> table);
	void printTree();
	void printTree(treeNode*);

	map<char, string> generageCode();
	void generageCode(treeNode*t,string s);

	void clear();

	~huffmanTree();
};

