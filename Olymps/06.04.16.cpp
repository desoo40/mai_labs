Дерево отрезков

n - массив

vector<int> st(4 * n, 0);

// t == cell, x == add, p = positiion

void add(int cell, int l_cell, int r_cell, int position, int add_var)
{
	st[t] += x;
	if (l == r) return;
	int avg = (l + r) / 2;
	//[l;avg] [avg + 1; r]
	if (p <= avg) {
		add(t * 2 + 1, l, avg, p, x);
	} else {
		add(t * 2 + 2, avg + 1, r, p, x);
	}
}

int sum(int cell, int l, int r, int ql, int qr) //правая, левая границы запроса
{
	if (ql <= l && r <= qr)	
		return st[t];
	int avg = (l + r) / 2;
	int res = 0;
	if (ql <= avg)
		res += sum(t * 2 + 1, l, m, ql, qr);
	if (m < qr)
		res += sum(t * 2 + 2, m + 1, r, ql, qr);
	return res;
}

 для вершины p :

 p->{p * 2 + 1, p * 2 + 2}

 // Че-то там максимум какой-то

 vector<int> st(4 * n, 0);

// t == cell, x == add, p = positiion

int add(int cell, int l_cell, int r_cell, int position, int add_var)
{
	if (l == r) {
		st[t] += x;
		return st[t];
	}
	int avg = (l + r) / 2;
	if (p <= m)
		add(t * 2 + 1, l, m, p, st[t]);
	else 
		add(t * 2 + 2, avg + 1, r, p, x);
		st[t] = max(st[t * 2 + 1], st[t * 2 + 2]);