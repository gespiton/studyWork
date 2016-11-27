#include"virus.h"
#include<fstream>
#include<sstream>
using namespace std;
int main() {
	/*fstream file("src.txt");
	string vD, hD;
	while (file)
	{
		file >> vD >> hD;
		Virus v(vD);
		


	}
	//Virus v("asdf","asdgfadgfadfadsfadgadgadgadfewetqreasdfasdfyflkahfjkxczhcpvupiayuriouwezbcayfiasdfzhdkjlvhajklhdfweyuihfkjlashdfjkhadhfadfqwetegdfgsajhdfjkhajifhkjadhfadfasdf");
	//Virus v("aaaa", "bbaaaaa");
	*/

	fstream file("src.txt");
	fstream out("outPut.txt",ios_base::out);

	string buf;
	while (getline(file,buf))
	{
		stringstream ss(buf);
		string p, src;
		ss >> p >> src;

		size_t i = 0;
		for (; i < p.length(); i++)
		{

			p = p.substr(1) + string(1, p[0]);
			//cout << p <<" "<<i<< endl;
			if ((Virus::match(p, src).size() != 0)) {
				cout << p << " M " << src << endl;
				out << buf + "   YES" << endl;
				break;
			}
		}
		if (i == p.length()) {
			cout << "no" << endl;
			out << buf + "  NO" << endl;
		}	    
	}





	//Virus::match("asdf", "asdgfadgfadfadsfadgadgadgadfewetqreasdfasdfyflkahfjkxczhcpvupiayuriouwezbcayfiasdfzhdkjlvhajklhdfweyuihfkjlashdfjkhadhfadfqwetegdfgsajhdfjkhajifhkjadhfadfasdf");
	system("pause");
}