#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

class Kafedra
{
public:
	string name;
	string director;
	int bachalors_cnt;
	string year;

	Kafedra(string line)
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

		name = words[0];
		director = words[1];
		bachalors_cnt = stoi(words[2]);
		year = words[3];
	}
	
	string to_str()
	{
		string str = "";

		str += name + " ";
		str += director + " ";
		str += to_string(bachalors_cnt) + " ";
		str += year + "\n";

		return str;
	}
};

int main()
{
	string path = "test1.txt";

	ifstream file(path);

	if (!file.is_open())
	{
		cout << "Не открыт файл" << endl;
		return 0;
	}

	string line = "";
	vector<Kafedra> kafedras;

	while (getline(file, line))
	{
		Kafedra tmp{ line };

		if (tmp.name.empty())
			continue;

		kafedras.push_back(tmp);
	}

	map<string, int> kafs_grad;

	for (auto kafedra : kafedras)
		kafs_grad[kafedra.name] += kafedra.bachalors_cnt;

	int sum = 0;
	double avg = 0.0;

	cout << "Kafs" << endl;

	for (auto grad : kafs_grad)
	{
		sum += grad.second;
		cout << grad.first << " " << grad.second << endl;
	}

	avg = (double)sum / (double)kafs_grad.size();

	cout << "Kafs with on 10% more grads then avg " << avg << endl;

	for (auto grad : kafs_grad)
	{
		if (grad.second > avg * 1.1)

		cout << grad.first << " " << grad.second << endl;
	}
	return 0;
}