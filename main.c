#include <stdio.h>

#include "unsignedhugeint.h"

int main(void) {
	UnsignedHugeInt *uhi = createUnsignedHugeIntFromString("0100000000000000000");
	displayUnsignedHugeInt(uhi);

	deleteUnsignedHugeInt(uhi);
	return 0;
}
