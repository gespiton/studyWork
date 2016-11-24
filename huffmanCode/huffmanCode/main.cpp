#include"huffmanTree.h"
#include<fstream>
using namespace std;
int main() {
	//map<char, int> table;
	//table['f'] = 5;
	//table['b'] = 13;
	//table['e'] = 9;
	//table['c'] = 12;
	//table['d'] = 16;
	//table['a'] = 45;
	//huffmanTree tree(table);
	//tree.printTree();
	//auto code = tree.generageCode();

	map<char, int> table;
	fstream file("src.txt",ios_base::in);
	char buf;
	while (file.get(buf))
	{
		table[buf]++;
	}


	huffmanTree tree(table);
	//tree.printTree();
	auto code = tree.generageCode();
	for each(auto i in code) {
		cout << i.first << ":" << i.second << endl;
	}
	tree.clear();
	system("pause");
}