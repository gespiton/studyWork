#include "virus.h"
#include<iostream>

Virus::Virus(string vDna,string hDna):v(vDna),len(vDna.size()),pos(vDna.size())
{
	//for each (int var in pos)
	//{
	//	std::cout << var << endl;
	//}
	auto v= match(vDna,hDna);
	for each (int var in v)
	{
		cout << var<<"  ";
	}
	//for (auto i : bad_character_table(vDna))
	//	cout << i << " ";
}

Virus::~Virus()
{
}

string Virus::match(string hD)
{
	for (size_t i = 0; i < hD.size(); i++)
	{
		for (size_t vIte = 0; vIte < v.size(); vIte++)
		{
			if (hD[i] == v[vIte]) {
				pos[vIte] = i;
			}
		}
	}

	return string();
}



