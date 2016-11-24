#include<iostream>
using namespace std;
//class BinarySearchTree;

//struct BinarySearchTree::BinaryNode;
template<typename T>
class BinarySearchTree
{
private:
    struct BinaryNode
    {
    public:
        T element;
        BinaryNode*left;
        BinaryNode*right;

        BinaryNode(const BinaryNode&rhs):element(rhs.element),left(rhs.left),right(rhs.right) {}
        BinaryNode(const T&theElement,BinaryNode*lt,BinaryNode*rt):element(theElement),left{lt},right{rt} {}
        BinaryNode(T&&theElement,BinaryNode*lt,BinaryNode*rt):element{std::move(theElement)},left{lt},right{rt} {}
    };

    BinaryNode*root;

    void insert(const T &x, BinaryNode* &t);
    void insert(T &&x, BinaryNode* &t);
    void remove(const T &x, BinaryNode* &t);
    BinaryNode * findMin(BinaryNode * t) const;
    BinaryNode * findMax(BinaryNode * t) const;
    bool contains(const T& x, BinaryNode * t) const;
    void makeEmpty(BinaryNode * &t);
    void printTree(BinaryNode * t,ostream &out) const;
    BinaryNode * clone(BinaryNode *t) const;
    int height(BinaryNode * t)const;
public:
    BinarySearchTree():root(nullptr) {}
    BinarySearchTree(const BinarySearchTree &rhs):root(clone(rhs.root)) {}
    BinarySearchTree(BinarySearchTree&&rhs);
    ~BinarySearchTree()
    {
        makeEmpty(root);
    }

    /// these function is for study purpose
    void output(const T& ele, int depth)
    {
        for(int i = 0; i!= depth; ++i)
        {
            cout<<"- ";
        }
        cout<<ele<<endl;
    }

    void postTranvesal()
    {
        if(isEmpty())
            cout<<"empty tree";
        else
            postTranvesal(root,0);
    }
    void postTranvesal(BinaryNode* t,int depth)
    {

        if(t==nullptr)
            return;
        else
        {
            postTranvesal(t->left,depth+1);
            postTranvesal(t->right,depth+1);
            output(t->element,depth);
        }
    }


    void preTravesal()
    {
        if(isEmpty())
            cout<<"empty tree";
        else
            preTravesal(root,0);
    }
    void preTravesal(BinaryNode* t, int depth)
    {
        if(t==nullptr)
            return;
        else
        {
            output(t->element, depth);
            preTravesal(t->left, depth +1);
            preTravesal(t->right, depth + 1);
        }
    }


    void inOrderTravesal()
    {
        if(isEmpty())
            cout<<"empty tree";
        else
            inOrderTravesal(root,0);
    }
    void inOrderTravesal(BinaryNode* t, int depth)
    {
        if(t==nullptr)
            return;
        else
        {
            preTravesal(t->left, depth +1);
            output(t->element, depth);
            preTravesal(t->right, depth + 1);
        }
    }

    int nodeCount()const
    {
        if(isEmpty())
            return 0;
        return 1 + nodeCount(root);
    }
    int nodeCount(const BinaryNode* t)const
    {
        if(t==nullptr)
            return -1;
        else{
            return 2+nodeCount(t->left)+nodeCount(t->right);
        }
    }

    int leaveCount()const{
        if(isEmpty())
            return 0;
        return nodeCount(root);
    }
    int leaveCount(const BinaryNode* t)const{
        if(t->left==nullptr&&t->right==nullptr)
            return 1;
        else if(t->left==nullptr||t->right==nullptr){
            return t->left==nullptr?leaveCount(t->right):leaveCount(t->left);
        }else{
            return leaveCount(t->left)+leaveCount(t->right);
        }
    }








    T  findMin()const;
    T  findMax()const;
    bool contains(const T&x) const;
    bool isEmpty ()const
    {
        return root==nullptr;
    }
    void printTree(ostream&out=cout)const
    {
        if(root==nullptr)
            out<<"empty tree";
        else
            printTree(root,out);
    }

    void makeEmpty()const
    {
        if(isEmpty())
            return;
        else
            makeEmpty(root);
    }
    void insert(const T&x)
    {
        insert(x, root);
    }
    void insert(T&&x)
    {
        insert(std::move(x), root);
    }
    void remove(const T &x)
    {
        return remove(x, root);
    }

    int height()const
    {
        if(root==nullptr)
            return 0;
        return 1+height(root);
    }

    BinarySearchTree& operator=(const BinarySearchTree&rhs);
    BinarySearchTree& operator=(BinarySearchTree&&rhs);

};

template<typename T>
inline bool BinarySearchTree<T>::contains(const T& x) const
{
    return contains(x, root);
}

template<typename T>                               /// can improve this.
bool BinarySearchTree<T>::contains(const T& x, BinaryNode * t) const
{
    if(t!=nullptr)
    {
        if(t->element==x)
            return true;
        else if(t->element>x)
            return contains(x, t->left);
        else
            return contains(x, t->right);
    }
    else
        return false;
}

//template<typename T>
//inline void BinarySearchTree<T>::insert(const T &x)
//{
//    return insert(x, root);
//}

//template<typename T>
//inline void BinarySearchTree<T>::insert( T &&x)
//{
//    return insert(x, root);
//}
template<typename T>
void BinarySearchTree<T>::insert(const T&x, BinaryNode* &t)
{
    if(t==nullptr)
    {
        t=new BinaryNode{x, nullptr, nullptr};
        return;
    }
    if(x < t->element)
        return insert(x, t->left);
    else if(x > t->element)
        return insert(x, t->right);
    else
        ;
}
template<typename T>
void BinarySearchTree<T>::insert(T&&x, BinaryNode* &t)
{
    if(t==nullptr)
    {
        t=new BinaryNode{std::move(x),nullptr,nullptr};                     ///? do we have to write so many std::move();
        return;
    }
    if(x<t->element)
        return insert(std::move(x), t->left);
    else if(x>t->element)
        return insert(std::move(x), t->right);
    else
        ;
}


template<typename T>
void BinarySearchTree<T>::remove(const T&x, BinaryNode* &t)
{
    if(t==nullptr)
        return;
    else if(t->element==x)
    {
        if(t->left==nullptr&&t->right==nullptr)
        {
            delete t;
            t=nullptr;
        }
        else if(t->left==nullptr||t->right==nullptr)
        {
            BinaryNode* buf=t;
            t=(t->left==nullptr)? t->right: t->left;
            delete buf;
            /// ! much simple than my silly resolution, mavel
//                        BinaryNode* buf=t;
//            t=t->right;
//            buf->left=buf->right=nullptr;
//            delete buf;
//        } else if(t->right==nullptr) {
//            BinaryNode* buf=t;
//            t=t->right;
//            buf->left=buf->right=nullptr;
//            delete buf;
        }
        else
        {
            auto buf=findMin(t->right);
            t->element=buf->element;
            remove(buf->element,buf);
        }
    }
    else if(x<t->element)
        return remove(x, t->left);
    else
        return remove(x, t->right);
}


template<typename T>
inline T BinarySearchTree<T>::findMin() const
{
    if(isEmpty())
    {
        cerr<<"empty tree";
        return T();
    }
    else
        return findMin(root)->element;
}


template<typename T>
auto BinarySearchTree<T>::findMin(BinaryNode * t) const->BinaryNode*
{
    if(t->left)
        return findMin(t->left);
    else
        return t;
}


template<typename T>
T BinarySearchTree<T>::findMax() const
{
    if(isEmpty())
    {
        cerr<<"empty tree"<<endl;
        return T();
    }
    else
        return findMax(root)->element;
}


template<typename T>
auto BinarySearchTree<T>::findMax(BinaryNode * t) const ->BinaryNode*
{
    if(t->right)
        return findMax(t->right);
    else
        return t;
}


template<typename T>
void BinarySearchTree<T>::makeEmpty(BinaryNode * &t)
{
    if(t!=nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t=nullptr;              /// for the pre call of makeEmpty
}


template<typename T>
auto BinarySearchTree<T>::clone(BinaryNode * t) const->BinaryNode *
{
    if(t==nullptr)
        return nullptr;
    else
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}


template<typename T>
void BinarySearchTree<T>::printTree(BinaryNode * t,ostream &out) const
{
    if(t!=nullptr)
    {
        printTree(t->left,out);
        out<<t->element<<endl;
        printTree(t->right,out);
    }
}
/*
this function of mine is really stupid ...........
template<typename T>
void BinarySearchTree<T>::height(BinaryNode * t, int ite)const
{
    if(t->left==nullptr&&t->right==nullptr) {
        if(ite>H)
            H=ite;
        return;
    } else if(t->left!=nullptr&&t->right!=nullptr) {
        height(t->left,ite+1);
        height(t->right,ite+1);
    } else {
        height((t->left==nullptr?t->right:t->left),ite+1);
    }
}
*/
template<typename T>
int BinarySearchTree<T>::height(BinaryNode * t) const
{
    if(t==nullptr)
        return -1;
    else
        return 1+max(height(t->left),height(t->right));
}



