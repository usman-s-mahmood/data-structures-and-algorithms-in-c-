#include "Tree.h"

class BST :public Tree
{
	void INORDER(Node*p);
	void PREORDER(Node*p);
	void POSTORDER(Node*p);
public:
	void insert(int);
	void inorder();
	void preorder();
	void postorder();
	bool deleteValue(int);
};

bool BST::deleteValue(int value)
{
	if (root == nullptr)
		return false;

	//there are cases for root here, that we will address later

	else
	{
		Node*p = root;
		Node*c = root;

		while (true)
		{
			if (value < c->data)
			{
				p = c;
				c = c->leftChild;
			}

			else
			{
				p = c;
				c = c->rightChild;
			}

			if (c == nullptr)
				return false;

			if (c->data == value)
				break;
		}


		cout << "p->data = " << p->data << endl;
		cout << "c->data = " << c->data << endl;

		if (c->leftChild != nullptr && c->rightChild != nullptr) // 2 children case
		{
			Node*t = c;
			c = c->rightChild;
			p = t;

			while (1)
			{
				if (c->leftChild == nullptr)
					break;

				p = c;
				c = c->leftChild;
			}
			
			t->data = c->data;
			value = c->data;

		}
		

		if (c->leftChild == nullptr && c->rightChild == nullptr) //leaf node
		{
			if (c->data < p->data)	//left child of parent
			{
				delete c;
				c = nullptr;
				p->leftChild = nullptr;
			}

			else //right child of the parent
			{
				delete c;
				c = nullptr;
				p->rightChild = nullptr;

			}

			return true;
		}

		else if (c->leftChild == nullptr && c->rightChild != nullptr) //single child case 1
		{
			if (c->data < p->data)	//left child of parent
			{
				p->leftChild = c->rightChild;
				delete c;
				c = nullptr;
			}

			else // right child of parent
			{
				p->rightChild = c->rightChild;
				delete c;
				c = nullptr;
			}

			return true;
		}

		else if (c->leftChild != nullptr && c->rightChild == nullptr) //single child case 2
		{
			if (c->data < p->data)	//left child of parent
			{
				p->leftChild = c->leftChild;
				delete c;
				c = nullptr;
			}

			else // right child of parent
			{
				p->rightChild = c->leftChild;
				delete c;
				c = nullptr;
			}

			return true;
		}
	}
}

void BST::POSTORDER(Node*p)
{
	if (p != nullptr)
	{
		POSTORDER(p->leftChild);
		POSTORDER(p->rightChild);
		cout << p->data << " ";
	}
}

void BST::postorder()
{
	if (root != nullptr)
		POSTORDER(root);
	else
		cout << "Tree in empty" << endl;
}

void BST::PREORDER(Node*p)
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		PREORDER(p->leftChild);
		PREORDER(p->rightChild);
	}
}

void BST::preorder()
{
	if (root != nullptr)
		PREORDER(root);
	else
		cout << "Tree in empty" << endl;
}

void BST::INORDER(Node*p)
{
	if (p != nullptr)
	{
		INORDER(p->leftChild);
		cout << p->data << " ";
		INORDER(p->rightChild);
	}
}

void BST::inorder()
{
	if (root != nullptr)
		INORDER(root);
	else
		cout << "Tree in empty" << endl;
}

void BST::insert(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->leftChild = nullptr;
	nn->rightChild = nullptr;

	if (root == nullptr)
		root = nn;

	else
	{
		Node*t = root;

		while (1)
		{
			if (value < t->data) //left case
			{
				if (t->leftChild == nullptr)
				{
					t->leftChild = nn;
					break;
				}

				else
					t = t->leftChild;
			}

			else //right case
			{
				if (t->rightChild == nullptr)
				{
					t->rightChild = nn;
					break;
				}

				else
					t = t->rightChild;
			}
		}
	}
}