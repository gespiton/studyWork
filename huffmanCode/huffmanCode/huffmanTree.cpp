#include "huffmanTree.h"

auto huffmanTree::createHeap(map<char, int> table)->priority_queue<treeNode*,vector<treeNode*>, comparator>
{
	priority_queue<treeNode*, vector<treeNode*>, comparator> minHeap;
	for each(auto &i in table) {
		treeNode* buf = new treeNode();
		buf->character = i.first;
		buf->freq = i.second;
		minHeap.push(buf);
	}
	return minHeap;
}

void huffmanTree::clear()
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		clear(root);
	}
}

void huffmanTree::clear(treeNode *& t)
{
	if (t==nullptr)
	{
		return;
	}
	clear(t->left);
	clear(t->right);
	if (t->left==nullptr&&t->right==nullptr)
	{
		//cout << "delete " << t->freq<<endl;
		delete t;
		t = nullptr;
	}
}

huffmanTree::huffmanTree(map<char, int> table)
{
	auto queue = createHeap(table);
	size_t nodeCount = queue.size()-1;
	for (size_t i = 1; i <= nodeCount; i++)
	{
		treeNode* buf = new treeNode();

		buf->left = queue.top();
		queue.pop();

		buf->right = queue.top();
		queue.pop();

		buf->freq = buf->left->freq + buf->right->freq;
		
		queue.push(buf);

	}

	//while (queue.size())
	//{
	//	cout << queue.top()->character<<":"<<queue.top()->freq <<" "<<(queue.top()->left==nullptr)<< endl;
	//	queue.pop();
	//}
	root = queue.top();
}

void huffmanTree::printTree()
{
	if (root == nullptr)
	{
		cout << "empty tree";
	}
	else
	{
		printTree(root);
	}
}

void huffmanTree::printTree(treeNode *t)
{
	if (t==nullptr)
	{
		return;
	}
	else
	{
		cout << t->character << ":" << t->freq << " " << endl;
		printTree(t->left);
		printTree(t->right);

	}
}

map<char, string> huffmanTree::generageCode()
{

	if (root == nullptr)
	{
		return map<char, string>();
	}
	else
	{
		// if we had generated it before, return directory
		if (code.size()!=0)
		{
			return code;
		}
		generageCode(root, "");
		return code;
	}
}

void huffmanTree::generageCode(treeNode * t, string s)
{
	if (t->character!=0)
	{
		if (s=="")  // handle the case that only one element was passed
		{
			code[t->character] = "0";
		}
		else
		{
			code[t->character] = s;
		}
	}
	else
	{
		if (t->left)
		{
			generageCode(t->left, s + "0");
		}
		if (t->right)
		{
			generageCode(t->right, s + "1");
		}
	}
}


huffmanTree::~huffmanTree()
{
	clear();
}
