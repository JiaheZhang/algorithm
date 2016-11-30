#include<iostream>
#include<deque> 
#include<stack> 
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
		BinTree(BinTree&);//拷贝构造 
		~BinTree();
		void createPreOrder(T ch[],const T &endSign);//先序建造 
		int getDepth(void)const;//获取树的深度 
		void clear(void);
		Node<T>* getRoot(void);
		bool traversePerOrder(void);//先序遍历 非递归 
		
		
	private:
		Node<T> *root;
		void _copy(BinTree &r);
		void _createPreOrder(Node<T> * &r,T ch[],int &i,const T &endSign);
		void _createMidOrder(Node<T> * &r,T ch[],int &i,const T &endSign);
		int _deep(Node<T> *p)const;
		void _clear(Node<T> * &p);
		
	
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

/**********先序构造************/ 
template<typename T>
void BinTree<T>::createPreOrder(T ch[],const T &endSign)
{
	int i = 0;
	_createPreOrder(this->root,ch,i,endSign);
}

/*********获取根节点**************/ 
template<typename T>
Node<T>* BinTree<T>::getRoot(void)
{
	return this->root;
}

/*************清楚树的所有元素****************/
template<typename T>
void BinTree<T>::clear(void)
{
	_clear(this->root);
}

/**********先序遍历************/ 
template<typename T>
bool BinTree<T>::traversePerOrder(void)
{
	if(this->root == NULL)
		return false;
	Node<T> *temp;
	stack<Node<T>* > nodeStack;
	nodeStack.push(this->root);
	while(!nodeStack.empty())
	{
		
		while(nodeStack.top() != NULL)//每次遇到左孩子压栈
		{
			cout<<nodeStack.top()->date;
			nodeStack.push(nodeStack.top()->leftChild);
		}
		nodeStack.pop(); //弹空指针 
		if(!nodeStack.empty())
		{
			temp = nodeStack.top();	
			nodeStack.pop();	
			nodeStack.push(temp->rightChild);
		}
	}
	return true;
}
/*************get the tree's depth***************/
template<typename T>
int BinTree<T>::getDepth(void)const
{
	return _deep(this->root);
}

/**********先序构造函数接口********/ 
template<typename T>
void BinTree<T>::_createPreOrder(Node<T> * &r,T ch[],int &i,const T &endSign)
{
	if(ch[i] == endSign)
	{
		r = NULL;
	}
	else
	{
		r = new Node<T>;
		r->date = ch[i];
		_createPreOrder(r->leftChild,ch,++i,endSign);
		_createPreOrder(r->rightChild,ch,++i,endSign);
	}
}
/*************求树的深度的函数接口*************/
template<typename T>
int BinTree<T>::_deep(Node<T> *p) const
{
	if(p == NULL)
		return 0;
	else
	{
		int left = _deep(p->leftChild) + 1;
		int right = _deep(p->rightChild) + 1;
		return left > right ? left : right;
		
	}
} 

/*************清除函数的接口****************/
template<typename T>
void BinTree<T>::_clear(Node<T> * &p)
{
	if(p != NULL)
	{
		_clear(p->leftChild);
		_clear(p->rightChild);
		delete p;
		p = NULL;
	}
	else
		return;
}

/************中序构造接口************/ 
template<typename T>
void BinTree<T>::_createMidOrder(Node<T> * &r,T ch[],int &i,const T &endSign)
{
	
}

int main()
{
	BinTree<char> bt;
	char date[7] = {'a','b','#','#','c','#','#'};
	bt.createPreOrder(date,'#');
	cout<<bt.getDepth();

	return 0;
} 
 
