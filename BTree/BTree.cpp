#include<iostream>
#include<malloc.h>
using namespace std;

/**************/
template<typename T>
struct Node
{
	T date;
	Node *leftChild,*rightChild;
};
/*******************/

template<typename T>
class BinTree
{
	public:
		BinTree();
		BinTree(BinTree&);
		~BinTree();
		void creat();
		int getDeep(void)const;
		void clear(void);
		
		
		
	private:
		Node<T> *root;
		void _copy(BinTree &r);
		
	
};

template<typename T>
BinTree<T>::BinTree()
{
	this->root = NULL;
}
template<typename T>
BinTree<T>::BinTree(BinTree &r)
{
	_copy(r);
}

template<typename T>
BinTree<T>::~BinTree()
{
	clear();
	delete root;
}

template<typename T>
void BinTree<T>::creat()
{
	
}

int main()
{
	
	return 0;
} 
 
