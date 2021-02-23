#include "NumberList.h"

int main()
{
	NumberList n;
	n.Init();
	n.Add(10);
	n.Add(5);
	n.Add(12);
	n.Add(1);
	n.Print();
	n.Sort();
	n.Print();

	return 0;
}