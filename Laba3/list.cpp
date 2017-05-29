#include <iostream>

struct Elem
{
	int el;
	Elem * next;

	Elem()
		:next(nullptr)
	{ }

	Elem(int a)
		:el(a)
		, next(nullptr)
	{ }

	~Elem()
	{ }
};

class List
{
	Elem * head;
public:

	List()
		:head(nullptr)
	{ }

	~List()
	{
		while (head)
			del(0);
	}

	int get(int pos)
	{
		Elem * a = head;
		for (int i = 0; i < pos; i++)
			a = a->next;
		return a->el;
	}

	void add(int pos, int el)
	{
		Elem * a = new Elem(el);
		if (pos == 0)
		{
			a->next = head;
			head = a;
		}
		else
		{
			Elem * b = head;
			for (int i = 0; i < pos - 1; i++)
				b = b->next;
			a->next = b->next;
			b->next = a;
		}
	}

	Elem & del(int pos)
	{
		Elem * a = head;
		if (pos == 0)
		{
			a = a->next;
			delete head;
			head = a;
			return *head;
		}
		for (int i = 0; i < pos - 1; i++)
			a = a->next;
		Elem * b = a->next->next;
		delete a->next;
		a->next = b;
		return *head;
	}
};

int main()
{
	List st;
	st.add(0, 3);
	st.add(1, 4);
	st.add(0, 2);
	st.del(1);
	std::cout << st.get(1) << std::endl;
	system("pause");
}
