Строки

Хэши

	Алгоритм Рабина-Карпа

	s - искомая строка
	h - которую ищем

	abcd смю рисунок)

	//

	bool check (const string &s, const string &h, int i)
	{
		for (size_t j = 0; j < size.(); ++j)
		{
			if (s[j] != h[i + j])
				return false;
		}
		return true;
	}

	string s;
	string h;
	maxpow = 1;
	base = 37 // берется простое число > 26 т.е. букв больше кол-ва букв
	mod = 10^9 + 7;
	shash = 0;

	for (size_t i = 0; i < s.size(); ++i)
	{
		shash == shash * base + s[i] - 'a' + 1;
	}

	hhash = 0;

	for (size_t i = 0; i < s.size(); ++i)
	{
		hhash = (hhash * base + h[i] - 'a' + 1) % mod; 
	}

	maxpow *= base % mod;

	if (shash == hhash)
		check(s, h, 0);

	for (size_t i = s.size(); i < h.size(); ++i)
	{ 
		hhash = (hhash - h[i] - s.size() - 'a' + 1) * maxpow * base + h[i] - 'a' + 1;
		check (s, h, i)
	}


Префикс-функция Алгоритм Кнута-Морриса-Пратта

s = s + '#' + h;
pf[0] = 0; 

for (int i = 1; i < s.size(); ++i)
{
	int j = pf[i - 1];
	while (j && s[i]) j = pf[j - 1];

	if (s[i] == s[j])
		j += 1
	pf[i] = j;
}

////////////////////////////////////////////

Z-функция (обратная Префикс-функция)

z[0] = 0;
l = 0;
r = 0;

for (int i = 1; i < s.size(); ++i)
{
	if (l <= r)
		z[i] = min(x[i - l], r - i + 1);
	while(i + z[i] , n && s[z[i]] == s[z[i]]) ++ z[i];
	if (i + z[i] > r)
	{
		l = i;
		r = i + z[i] - 1;
	}
}

cout.flush();


//////////////////////////////////////////////

Разбор задач

s = a + '#' + b + b;