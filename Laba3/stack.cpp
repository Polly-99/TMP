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

class Stack
{
	Elem * head;
public:

	Stack()
		:head(nullptr)
	{ }

	~Stack()
	{
		while (head)
			del();
	}

	void add(int el)
	{
		Elem * a = new Elem(el);
		a->next = head;
		head = a;  
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
	Stack st;		
	st.add(5);		
	st.add(4);
	st.add(9);
	st.add(8);
	st.add(2);
	st.add(1);
	st.del();
	st.del();
	std::cout << st.get() << std::endl;
	system("pause");
}