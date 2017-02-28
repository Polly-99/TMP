#include <iostream>
#include <string>
#include <fstream>
void compare(std::string filename1, std::string filename2)
{
	std::string line1, line2;
	std::fstream file1(filename1, std::fstream::in);
	std::fstream file2(filename2, std::fstream::in);
	if (!file1.is_open() || !file2.is_open())
	{
		std::cout << "Wrong name of file. Try again." << std::endl;
		return;
	}
	int number = 0, i = 0;
	while (!file1.eof())
	{
		i = 0;
		std::getline(file1, line1);
		while (!file2.eof())
		{
			std::getline(file2, line2);
			if (line1 == line2)
			{
				i = 1;
				break;
			}
		}
		if (i == 0)
		{
			std::cout << number << "." << line1 << std::endl;
		}
		number++;
		file2.close();
		file2.open(filename2);
	}
	file2.close();
}
int main()
{
	std::string line1, line2, filename1, filename2;
	std::cout << "Enter name of first file:  ";
	std::cin >> filename1;
	std::cout << "Enter name of second file:  ";
	std::cin >> filename2;
	std::cout << std::endl << "File #1:" << std::endl;
	compare(filename1, filename2);
	std::cout << std::endl << "File #2:" << std::endl;
	compare(filename2, filename1);
	system("pause");
}
