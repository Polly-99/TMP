#include <exception>
#include <iostream>

struct TNode
{
	int Data;
	TNode * Prev;
	TNode * Right;
	TNode * Left;
	bool flag_p = false;
	bool flag_o = false;
	bool flag_s = false;

	TNode(const int& data, TNode * next = nullptr, TNode * prev = nullptr)
		: Data(data)
		, Right(next)
		, Left(prev)
	{ }
	TNode()
		: Data(int())
		, Right(nullptr)
		, Left(nullptr)
	{ }

	~TNode()
	{
		delete Left;
		delete Right;
	}
};

class Tree
{
	TNode * Root;
	TNode * End;
public:
	Tree()
		:Root(nullptr)
	{ }

	~Tree()
	{
		delete Root;
	}

	void Insert(int data)
	{
		if (Root == nullptr)
		{
			Root = new TNode(data);
			End = new TNode;
			Root->Right = End;
			End->Prev = Root;
			return;
		}
		TNode * next = Root;
		TNode * prev = next;
		while (next != End && next != nullptr)
		{
			prev = next;
			if (data < next->Data)
				next = next->Left;
			else
				next = next->Right;
		}
		TNode * List = new TNode(data);
		if (data < prev->Data)
			prev->Left = List;
		else
		{
			if (prev->Right == End)
			{
				List->Right = End;
				End->Prev = List;
				prev->Right = List;
			}
			else
				prev->Right = List;
		}
		List->Prev = prev;
	}

	void Pr_Obhod()
	{
		TNode * curNode = Root;
		TNode * prevNode = Root;
		while (curNode)
		{
			while (curNode != nullptr)
			{
				prevNode = curNode;
				if (curNode != End)
					std::cout << curNode->Data << " ";
				curNode = curNode->Left;
			}
			curNode = prevNode;
			while ((curNode->Right == nullptr && curNode != End) || curNode->flag_p)
				curNode = curNode->Prev;
			curNode->flag_p = true;
			curNode = curNode->Right;
		}
	}

	void Obr_Obhod()
	{
		TNode * curNode = Root;
		TNode * prevNode = Root;
		do
		{
			while (curNode != nullptr && !curNode->flag_o)
			{
				prevNode = curNode;
				curNode = curNode->Left;
			}
			curNode = prevNode;
			curNode->flag_o = true;
			std::cout << curNode->Data << " ";
			curNode = curNode->Prev;
			while (curNode->Right != nullptr &&  curNode->Right != End && !curNode->Right->flag_o)
				curNode = curNode->Right;	
		} while (curNode != Root);
		std::cout << curNode->Data;
	}

	void Sym_Obhod()
	{
		TNode * curNode = Root;
		TNode * prevNode = Root;
		bool prav = false;
		while (!prav || (curNode->Prev != nullptr && !curNode->Prev->flag_s)
			|| (curNode->Left != nullptr && !curNode->Left->flag_s)
			|| (curNode->Right != End && curNode->Right != nullptr && !curNode->Right->flag_s))
		{
			while (curNode != nullptr)
			{
				prevNode = curNode;
				curNode = curNode->Left;
			}
			curNode = prevNode;
			curNode->flag_s = true;
			std::cout << curNode->Data << " ";
			while (curNode->flag_s && curNode != Root)
				curNode = curNode->Prev;
			if (curNode == Root)
				prav = true;
			if (curNode != Root || !curNode->flag_s)
				std::cout << curNode->Data << " ";
			else
				curNode = prevNode;
			curNode->flag_s = true;
			if (curNode->Right != nullptr &&  curNode->Right != End && !curNode->Right->flag_s)
				curNode = curNode->Right;
		}
	}
};

int main()
{
	Tree tr;
	tr.Insert(8);
	tr.Insert(3);
	tr.Insert(1);
	tr.Insert(6);
	tr.Insert(4);
	tr.Insert(7);
	tr.Insert(10);
	tr.Insert(14);
	tr.Insert(13);
	std::cout << "Pryamoy obhod:" << std::endl;
	tr.Pr_Obhod();
	std::cout << std::endl << "Obratnyy obhod" << std::endl;
	tr.Obr_Obhod();
	std::cout << std::endl << "Symmetric obhod" << std::endl;
	tr.Sym_Obhod();
	std::cout << std::endl;
	system("pause");
}