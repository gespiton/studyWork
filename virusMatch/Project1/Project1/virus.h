#pragma once
#include<string>
#include<list>
#include<vector>
#include<fstream>
#include<map>
#include<iostream>
using namespace std;
class Virus
{
public:
	Virus(string,string);
	~Virus();
	string match(string);
	static vector<int> fundamentle_process(const string& src) {
		// empty string
		if (src == "")
			return vector<int>();
		//single char str
		if (src.size() == 1)
			return vector<int>{ 1 };

		vector<int> table(src.size());
		table[0] = src.size();
		// first match
		table[1] = match_len(src, 0, 1);
		// only possible situ: aaaaaaaabcdeffgdag
		for (size_t i = 2; i < table[1]+1; i++)
		{
			table[i] = table[1] - i + 1;
		}

		// iterator pos
		int ite = table[1] + 1;

		int lhb = 0, rhb = 0;
		for(;ite!=src.size();++ite)
		{
			// fall within the box
			if (ite < rhb) {

				int lLen = table[ite - lhb];
				int leftLen = rhb - ite ;

				// length covered
				if (lLen < leftLen) {
					table[ite] = lLen;
				}
				else {
					table[ite] = lLen + match_len(src, leftLen, rhb); // shit hard to understand, but i got it
					lhb = ite;
					rhb = table[ite] + ite;
				}
			}
			else {
				table[ite] = match_len(src, 0, ite);
				if (table[ite] > 0) {
					lhb = ite;
					rhb = ite + table[ite];
				}
			}
		}
		return table;
	}
	static vector<vector<int>> bad_character_table(const string&src) {
		//map<char, int> bufTable;
		//vector<int> result(src.size(),-1);

		//for (size_t i = 0; i < src.size(); i++)
		//{
		//	if (bufTable.count(src[i]) != 0) {
		//		result[i] = bufTable[src[i]];
		//	}
		//	else {
		//		bufTable[src[i]] = i;
		//	}
		//}
		//return result;
		vector<vector<int>> result(26, { -1 });
		vector<int> buf(26, -1);
		for (size_t i = 0; i < src.length(); i++)
		{
			buf[src[i] - 97] = i;
			for (size_t i = 0; i < 26; i++)
			{
				result[i].push_back(buf[i]);
			}
		}
		//for each (auto vec in result)
		//{
		//	for each (int var in vec)
		//	{
		//		cout << var<<" ";
		//	}
		//	cout << endl;
		//}
		return result;
	}
	static int match_len(const string&src, int lhs, int rhs) {
		int count = 0;
		while (src[lhs]==src[rhs])
		{
			++lhs, ++rhs, ++count;
		}
		return count;
	}
	static vector<int> good_suffix_table(const string&src) {
		vector<int> result(src.size(), -1);
		string bufString(src.crbegin(),src.crend());
		//cout << src << endl << bufString;
		auto buf = fundamentle_process(bufString);
		vector<int> buf2(buf.rbegin(), buf.rend());
	/*	for each (int var in buf2)
		{
			cout << var << "  ";
		}*/
		//cout << endl;
		//std::cout << buf2.size();
		for (size_t i = 0; i < src.length()-2; i++)
		{
			auto t = buf2[i];
			if(t!=0)
				result[src.length() - t] = i;
		}
		//for each (int var in result)
		//{
		//	cout << var << "  ";
		//}
		//cout << endl;
		return result;
	}
	static vector<int> full_shift_table(const string&src) {
		vector<int> result(src.size(), 0);
		auto buf = fundamentle_process(src);
		vector<int> buf2(buf.rbegin(), buf.rend());
		//for each (int var in buf2)
		//{
		//	cout << var << "  ";
		//}
		//cout << endl;


		int longest = 0;
		for (size_t i = 0; i < src.length(); i++)
		{
			if ((i + 1) == buf2[i]) {
				if (i + 1 > longest) {
					longest = buf2[i];
					result[src.length() - buf2[i]] = longest;
				}
				
			}else{
				result[src.length() - i-1] = longest;
			}
		}

		return result;
	}
	static vector<int> match(const string&p,const string&src) {
		vector<int> pos;
		auto F = full_shift_table(p);
		auto L = good_suffix_table(p);
		auto R = bad_character_table(p);
		int srcIndex = p.length() - 1;
		int pIndex = srcIndex;

		
		int pre_srcindex = -1;  // gali's rule

		int char_shift = 0;
		int sufix_shift = 0;

		int h = 0;   // character to compare in src
		while (srcIndex<src.length())
		{
			pIndex = p.length() - 1;                        // camparing from the end again
			h = srcIndex;

			while (pIndex>=0&&h > pre_srcindex &&src[h] == p[pIndex]) {   // h>pre index because the new part is the sufix
				--h;
				--pIndex;
			}

			if (pIndex == -1|| h == pre_srcindex) {   // match found  abcde|ftaaassdef  
				//                                                      cde|fta
				pos.push_back(srcIndex-p.length()+1);
				srcIndex += p.length() > 1 ? p.length() - F[1] : 1; // fucking clear
				continue;
			}

			char_shift = pIndex - R[src[h]-97][pIndex];           //bad char shift         //? +1
			// not found
			//if (pIndex != p.length() - 1) {                      // has sufix
			if (pIndex + 1 == p.length())
				sufix_shift = 1;
			else if (L[pIndex+1] != -1) {                          // has match sufix
				sufix_shift = p.length() - L[pIndex+1]-1;   // need -1 for not shift too much
			}
			else {                                           //don't have match sufix, use full shift
				sufix_shift = p.length() - F[pIndex+1];       // this table is very tricy [5,1,1,1,1,1,0] such that, no matter where is scrindex, it can alwayse shift to the right place
				// cause every shift can be view as eliminate the unsuficient sufix
			}
			
			sufix_shift = char_shift > sufix_shift ? char_shift : sufix_shift;
			pre_srcindex = sufix_shift > pIndex + 1 ? srcIndex : pre_srcindex;      // if shift pass the curent aliment end, then pre index should be changed
			srcIndex += sufix_shift;   // move the index in src to new aliment

		}
		return pos;
	}
private:
	string v;
	int len;
	vector<int> pos;
};

