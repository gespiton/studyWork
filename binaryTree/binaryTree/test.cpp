#include"BinarySearchTree.h"
using std::cout;
using std::endl;
int main(){
    BinarySearchTree<int> tree;
    tree.insert(12);
    tree.insert(1);
    tree.insert(2);
    tree.insert(532);
    tree.insert(1234);
    tree.insert(13);
    tree.insert(1234);
    tree.insert(121);

	cout << "inorder travesal:" << endl;
    tree.inOrderTravesal();
    cout<<endl;
	cout << "preorder travesal:" << endl;
    tree.preTravesal();
    cout<<endl;
	cout << "postorder travesal:" << endl;
    tree.postTranvesal();
    cout<<endl;
    cout<<"the height of the tree: "<<tree.height()<<endl;
    cout<<"the total nodes in the tree: "<<tree.nodeCount()<<endl;
    cout<<"the total leave nodes in the tree: "<<tree.leaveCount()<<endl;
	cout << "the nodes at height 2: " << tree.countAtHeight(2)<<endl;
	cout << "all path from root to leave :" << endl;
	tree.printPathToLeave();

	system("pause");
}
