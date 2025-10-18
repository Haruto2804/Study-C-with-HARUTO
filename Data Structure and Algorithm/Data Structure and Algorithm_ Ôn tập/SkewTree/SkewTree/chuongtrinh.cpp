#include "thuvien.h"
int main()
{
	Node* sh = new Node;
	Node* sh2 = new Node;
	Init(sh);
	Init(sh2);
	sh = Insert(sh,1);
	sh2 = Insert(sh2,2);
	Node* temp = new Node;
	temp = Merge(sh, sh2);
	preOrder(temp);
	return 0;
}