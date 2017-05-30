#include <iostream>
#include <vector>

template <class T>
class Prior_Queue
{
public:
	using value_type = T;

private:
	std::vector <value_type> vec;

public:
	Prior_Queue()
	{}

	~Prior_Queue()
	{}

	void add(value_type value)
	{
		vec.push_back(value);
		int i = vec.size() - 1;
		int parent = (i - 1) / 2;

		while (i > 0 && vec[parent] > vec[i])
		{
			std::swap(vec[i], vec[parent]);
			i = parent;
			parent = (i - 1) / 2;
		}
	}

	value_type get()
	{
		return vec[0];
	}

	void del()
	{
		vec[0] = vec[vec.size() - 1];
		vec.erase(vec.end() - 1);
		int i = 0, left = 0, right = 0, min = 0;
		bool flag = false;
		do
		{
			if (flag)
			{
				std::swap(vec[i], vec[min]);
				i = min;
			}
			flag = true;
			left = 2 * i + 1;
			right = 2 * i + 2;
			if (left <vec.size() && vec[left] < vec[min])
				min = left;
			if (right <vec.size() && vec[right] < vec[min])
				min = right;
		} while (min != i);
	}
};

int main()
{
	Prior_Queue <char> a;
	a.add('F');
	a.add('H');
	a.add('P');
	a.del();
	std::cout << a.get() << std::endl;
	system("pause");
}