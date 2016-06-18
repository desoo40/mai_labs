int two_power(int lvl)
{
	return lvl == 0 ? 1 : 2 * two_power(lvl - 1);
}

int max (int a, int b)
{
	return a > b ? a : b;
}