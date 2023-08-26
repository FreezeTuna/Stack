#pragma once

#include <iostream>
using namespace std;

template<typename T>
class ListStack
{
public:
	struct Node;

public:
	ListStack()
	{

	}

public:
	static Node* Create(T** data)
	{
		Node* node = new Node();
		node->Data = *data;
		node->Next = NULL;

		return node;
	}

public:
	void Push_Back(Node* node)
	{
		if (m_Head == NULL)
		{
			node->Next = NULL;
			m_Head = node;
			return;
		}

		Node* End = m_Head;
		while (End->Next != NULL)
		{
			End = End->Next;
		}
		End->Next = node;
		node->Next = NULL;
	}

	Node* Pop_Back()
	{
		if (m_Head == NULL)
		{
			return NULL;
		}

		Node* End = m_Head;
		Node* Prev = NULL;

		while (End->Next != NULL)
		{
			Prev = End;
			End = End->Next;
		}

		if (Prev != NULL)
		{
			Prev->Next = NULL;
		}
		else
		{
			m_Head = NULL;
		}

		return End;
	}

	void RemoveAll()
	{
		if (m_Head == NULL)
		{
			return;
		}

		if (m_Head->Next == NULL)
		{
			delete m_Head;
			m_Head = NULL;
			return;
		}

		Node* End = m_Head;
		while (End->Next != NULL)
		{
			Node* Temp = End;
			End = End->Next;

			delete Temp;
		}

		m_Head = NULL;
	}

	int GetSize()
	{
		if (m_Head == NULL)
		{
			return 0;
		}

		Node* End = m_Head;
		int Count = 1;

		while (End->Next != NULL)
		{
			End = End->Next;
			Count++;
		}

		return Count;
	}

	//Print Node <Àç±Í ÇÔ¼ö>
	void Print(Node* node = NULL)
	{
		if (node == NULL)
		{
			if (m_Head != NULL)
			{
				cout << *m_Head->Data;
				if (m_Head->Next != NULL)
				{
					cout << " -> ";
					Print(m_Head->Next);
				}
			}
			return;
		}
		cout << *node->Data;
		if (node->Next != NULL)
		{
			cout << " -> ";
			Print(node->Next);
		}
		else
		{
			cout << endl;
		}
	}

public:
	//	Struct of Linked List Node
	struct Node
	{
		//	List Data
		T* Data;
		//	Next List
		Node* Next;
	};

private:
	//	First Node
	Node* m_Head = NULL;
};