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

class Queue
{
	Elem * head;
public:

	Queue()
		:head(nullptr)
	{ }

	~Queue()
	{
		while (head)
			del();
	}

	void add(int el)
	{
		if (head == nullptr)
		{
			head = new Elem(el);
			return;
		}
		Elem * a = head;
		while (a->next != nullptr)
			a = a->next;
		Elem * b = new Elem(el);
		a->next = b;
	}

	Elem & del()
	{
		if (head == nullptr)
			return *head;
		Elem * a = head->next;
		delete head;
		head = a;
		return *head;
	}

	int get()
	{
		return head->el;
	}
};

int main()
{
	Queue st;
	st.add(7);
	st.add(5);
	st.add(9);
	st.add(2);
	st.add(0);
	st.del();
	st.del();
	st.del();
	std::cout << st.get() << std::endl;
	system("pause");
}