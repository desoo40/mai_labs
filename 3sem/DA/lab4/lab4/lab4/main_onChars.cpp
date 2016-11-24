//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> PreBadChars(string cs)
//{
//	size_t len = cs.length();
//	vector<int> BC(10);
//
//	for (size_t i = 0; i < BC.size(); ++i)
//	{
//		BC[i] = len;
//	}
//
//	for (size_t i = 0; i < len - 1; ++i)
//	{
//		BC[cs[i]] = len - 1 - i;
//	}
//
//	return BC;
//}
//
//bool isPrefix(string cs, size_t p)
//{
//	int j = 0;
//	for (size_t i = p; i < cs.length() - 1; ++i)
//	{
//		if (cs[i] != cs[j])
//			return false;
//		++j;
//	}
//
//	return true;
//}
//
//size_t SuffixLenght(string cs, size_t p)
//{
//	size_t len = 0;
//	size_t i = p;
//	size_t j = cs.length() - 1;
//
//	while (i >= 0 && cs[i] == cs[j])
//	{
//		++len;
//		--i;
//		--j;
//	}
//
//	return len;
//}
//
//vector<int> PreGoodSuff(string cs)
//{
//	size_t len = cs.length();
//
//	vector<int> GS(len);
//	size_t LastPrefixPosition = len;
//	
//	for (size_t i = len - 1; i > 0; --i)
//	{
//		if (isPrefix(cs, i + 1))
//			LastPrefixPosition = i + 1;
//
//		GS[len - 1 - i] = LastPrefixPosition - i + len - 1;
//	}
//
//	for (size_t i = 0; i < len - 2; ++i)
//	{
//		size_t suffLen = SuffixLenght(cs, i);
//		GS[suffLen] = len - 1 - i + suffLen;
//	}
//
//	return GS;
//}
//
//vector<int> BoyerMure(string text, string pat)
//{
//	size_t n = text.length();
//	size_t m = pat.length();
//
//	vector<int> answer;
//
//	if (pat.length() == 0 || text.length() == 0) {
//		answer.push_back(-1);
//		return answer;
//	}
//
//	vector<int> BadChars = PreBadChars(pat);
//	vector<int> GoodSuff = PreGoodSuff(pat);
//
//	for (size_t i = m - 1; i < n - 1; ++i)
//	{
//		size_t j = m - 1;
//
//		while (pat[j] == text[i])
//		{
//			if (j == 0)
//				answer.push_back(i);
//			--i;
//			--j;
//		}
//
//		i += max(GoodSuff[m - 1 - j], BadChars[text[i]]);
//	}
//
//	if (answer.size() == 0)
//	{
//		answer.push_back(-1);
//	}
//
//	return answer;
//}
//
//int main()
//{
//    string pattern = "";
//	string text = "";
//    getline(cin, pattern, '\n');
//	getline(cin, text, '\n');
//
//	vector<int> answer = BoyerMure(pattern, text);
//
//	for (int i = 0; i < answer.size(); ++i)
//	{
//		cout << answer[i] << endl;
//	}
//   
//	return 0;
//    /*vector<size_t> R(10);
//    vector<string> lines;
//
//    for (size_t i = 0; ; ++i)
//    {
//        string tmp;
//
//        getline(cin, tmp);
//        
//        if (tmp.length() == 0)
//            break;
//
//        tmp.push_back('\n');
//        lines.push_back(tmp);
//    }
//
//    for(size_t i = 0; i < lines.size(); ++i)
//    {
//        cout << lines[i];
//    }*/
//
//    return 0;
//}
