#include "../Include/Templates/templates.h"

int max2(int a, int b)
{
	cout << "non-template max is being called ";
	return	b < a ? a : b;
}
