/*
**
** QWASAR.IO -- is_power_of_2
**
** @param {int} param_1
**
** @return {int}
**
*/

int is_power_of_(int n)
{
  if (n == 0 || n == 1)
    return 0;
  while (n != 1)
  {
      if (n%2 != 0)
         return 0;
      n = n/2;
  }
  return 1;
}
