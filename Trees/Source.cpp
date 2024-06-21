#include "BST.h"

int main()
{
	BST obj;

	obj.insert(15);
	obj.insert(20);
	obj.insert(400);
	obj.insert(17);
	obj.insert(17);
	obj.insert(10);
	obj.insert(1);
	obj.insert(12);
	obj.insert(11);
	obj.insert(17);
	obj.insert(0);
	obj.insert(500);
	obj.insert(382);
	obj.insert(385);
	obj.insert(350);
	obj.insert(375);
	obj.insert(300);
	obj.insert(378);
	obj.insert(450);
	obj.insert(550);
	obj.insert(600);
	obj.insert(12);

	obj.inorder();

	cout << endl;

	cout << "Value Deleted or not? " << obj.deleteValue(14) << endl;

	obj.inorder();

	cout << endl;
	
	return 0;
}