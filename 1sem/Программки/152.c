#include <assert.h>
#include <stdio.h>

int
binomial (int row, int pos)
{
  int koef = 1;
  int i;
  if (row - pos > pos)
    pos = row - pos;
  for (i = pos + 1; i <= row; i++)
    koef = koef * i;
  for (i = 1; i < (row - pos + 1); i++)
    koef = koef / i;
  return koef;
}

int
main (void)
{
  int row, pos;
  int r = scanf ("%i%i", &row, &pos);
  assert (r == 2);
  printf ("%i", binomial (row, pos));
  return 0;
}
