#include"BinarySearchTree.h"
using std::cout;
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


    tree.inOrderTravesal();
    cout<<endl;
    tree.preTravesal();
    cout<<endl;
    tree.postTranvesal();
    cout<<endl;
    cout<<"the height of the tree: "<<tree.height()<<endl;
    cout<<"the total nodes in the tree: "<<tree.nodeCount()<<endl;
    cout<<"the total leave nodes in the tree: "<<tree.leaveCount()<<endl;
}
