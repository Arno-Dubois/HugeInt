#include <stdio.h>

#include "unsignedhugeint.h"

int main(void) {
	UnsignedHugeInt *uhi = createUnsignedHugeIntFromString("0012345");
	displayUnsignedHugeInt(uhi);
	int num = countDigitsFromUnsignedHugeInt(uhi);
	printf("\n%d\n", num);

	UnsignedHugeInt *secondUhi = createUnsignedHugeIntFromString("234");
	displayUnsignedHugeInt(addUnsignedHugeInt(uhi, secondUhi));

	deleteUnsignedHugeInt(uhi);
	deleteUnsignedHugeInt(secondUhi);
	return 0;
}
