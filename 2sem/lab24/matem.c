int two_power(int lvl)
{
	return lvl == 0 ? 1 : 2 * two_power(lvl - 1);
}

int _max (int a, int b)
{
	return a > b ? a : b;
}

int power(int a, int b)
{
	return b == 0 ? 1 : a * power(a, b - 1);
}

int operation(char t, int a, int b)
{
	if (t == '-')
		return a - b;
	if (t == '+')
		return a + b;
	if (t == '*')
		return a * b;
	if (t == '/')
		return a / b;
	if (t == '^')
		return power(a, b);

	return 0;
}