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
		Node<T> root;
		
	
};



int main()
{
	
	return 0;
} 
 
