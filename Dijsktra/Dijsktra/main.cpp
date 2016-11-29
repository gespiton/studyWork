#include"Graph.hpp"
#include"Dijsktra.hpp"
#include"Queue.hpp"
#include<functional>
int main() {


	Graph("graph.txt");
	Dijsktra g(Graph("graph.txt"));
	g.travelTo("海韵学生公寓");

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

}