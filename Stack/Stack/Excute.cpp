#include "Stack.h"

typedef ListStack<int> Stack;

int main()
{
	Stack* stack = new Stack();
	for (int i = 1; i <= 7; i++)
	{
		int* index = new int;
		*index = *(&i);
		stack->Push_Back(Stack::Create(&index));
	}

	stack->Print();

	cout << stack->GetSize() << endl << endl;

	ListStack<int>::Node* node = stack->Pop_Back();

	cout << *node->Data << endl;
	
	stack->Print();

	cout << stack->GetSize() << endl << endl;

	stack->RemoveAll();

	cout << stack->GetSize() << endl << endl;


	return 0;
}