#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Person
{
public:
	string surname;
	string name;
	int age;
	string phone;

	Person(string line)
	{
		vector<string> words;
		istringstream stream(line);

		string tmp = "";

		for (int i = 0; getline(stream, tmp, ' '); ++i)
			words.push_back(tmp);

		if (words.size() != 4)
		{
			cout << "Line does not right" << endl;
			return;
		}

		surname = words[0];
		name = words[1];
		age = stoi(words[2]);
		phone = words[3];
	}
	
	string to_str()
	{
		string str = "";

		str += surname + " ";
		str += name + " ";
		str += to_string(age) + " ";
		str += phone + "\n";

		return str;
	}
};

int main()
{
	string path = "test.txt";

	ifstream file(path);

	if(!file.is_open())
	{
		cout << "Не открыт файл" << endl;
		return 0;
	}

	string line = "";
	vector<Person> persons;

	while (getline(file, line))
	{
		Person tmp{line};

		if (tmp.surname.empty())
			continue;
		
		persons.push_back(tmp);
	}

	auto pred = [](Person &l, Person &r) {return l.age > r.age; };

	sort(persons.begin(), persons.end(), pred);

	int avg = 0;
	int sum = 0;

	for (auto person : persons)
	{
		sum += person.age;
		
		cout << person.to_str();
	}
	
	avg = sum / persons.size();

	cout << "Who youngest avg(" << avg << ") at least 7 years" << endl << endl;

	for (auto person : persons)
	{
		if (person.age < avg)
			cout << person.to_str();
	}

	return 0;
}