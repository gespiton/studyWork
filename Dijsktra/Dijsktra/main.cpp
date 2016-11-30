#include"Graph.hpp"
#include"Dijsktra.hpp"
#include"Queue.hpp"
#include<functional>
#include<regex>
#include"Manager.hpp"
#include<Windows.h>
void test_regex();
//void displayGuide(Graph g);


int main() {
	SetConsoleTitle("XMU map system");
	//SetConsoleCursorPosition(3, 4);
	//MessageBox(NULL, TEXT("GetStdHandle"), TEXT("Console Error"),
	//	MB_OK);

	//test_regex();
	Manager m(Graph("graph.txt"));
	m.Start();
	system("pause");
}
void test1() {
	//Graph("graph.txt");
	//Dijsktra(Graph("graph.txt"));

	//Queue<int,greater<int>> queue{4,1,3,2,16,9,10,14,8,7};
	Queue<int> queue{ 4,1,3,2,16,9,10,14,8,7 };

	queue.print();

	queue.changeV(1, -9);
	queue.print();
	//cout << queue.getIndex(80) << endl;
	queue.enQueue(-3);
	queue.print();

	//while (!queue.isEmpty())
	//{
	//	
	//	cout<<endl<<"dequeue :"<<queue.top()<<"  "<< queue.dequeue()<<"  "<<endl<<endl; // this is amazing, the order of excution is right to left

	//	cout << queue.top() << endl;
	//	queue.print();
	//}
}
void test2() {
	Graph("graph.txt");
	Dijsktra g(Graph("graph.txt"));
	//g.travel("海韵学生公寓");

}
void test_regex() {
	regex r("^[ ]*\\d+[ ]*$");
	string target = "345534  ";
	string target2 = "3455 34";
	//match_results<string> result;
	cout << regex_match(target,r);
}


