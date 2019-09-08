#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string line;
	vector<string> lines;

	ifstream in("hello.txt"); // окрываем файл для чтения

	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "No such file" << endl;
		in.close();     // закрываем файл

		return 0;
	}
		
	in.close();     // закрываем файл

	std::cout << "End of program" << std::endl;
	return 0;
}