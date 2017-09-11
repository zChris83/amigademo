#include <stdio.h>
#include <proto/intuition.h>

int main(int argc, int **argv)
{
	struct IntuitionBase *IBase;
	//Open the library Intu 39 == Workbench 3.0
	IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",39);

	return 0;
}
