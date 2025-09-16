//
// Created by JAD on 16/09/2025.
//

#include "unsignedhugeint.h"

DigitCell *createDigitCell(unsigned short digit);

void deleteDigitCell(DigitCell *digitCell);

UnsignedHugeInt *createUnsignedHugeIntFromString(char *stringToConvert) {
    UnsignedHugeInt *uhi = malloc(sizeof(UnsignedHugeInt));
    uhi->first = NULL;
    DigitCell *tempCell;
    char *tepChar = stringToConvert;

    while (*tepChar != '\0') {
        if (uhi->first == NULL) {
            uhi->first = createDigitCell(*tepChar);
            tempCell = uhi->first;
        } else {
            tempCell->next = createDigitCell(*tepChar);
            tempCell = tempCell->next;
        }
        tepChar++;
    }

    simplifyUnsignedHugeInt(uhi);
    return uhi;
}

void displayUnsignedHugeInt(UnsignedHugeInt *unsignedHugeInt) {
    if (unsignedHugeInt == NULL) return;
    DigitCell *tempCell = unsignedHugeInt->first;
    while (tempCell != NULL) {
        printf("%c", tempCell->digit);
        tempCell = tempCell->next;
    }
}

UnsignedHugeInt *addUnsignedHugeInt(UnsignedHugeInt *first, UnsignedHugeInt *second) {
}

void simplifyUnsignedHugeInt(UnsignedHugeInt *unsignedHugeInt) {
    if (unsignedHugeInt == NULL) return;
    DigitCell *tempCell = unsignedHugeInt->first;
    while ((tempCell->digit == '0') && (tempCell->next != NULL)) {
        DigitCell *previousCell = tempCell->next;
        tempCell->next = NULL;
        deleteDigitCell(tempCell);
        tempCell = previousCell;
    }
    unsignedHugeInt->first = tempCell;
}

void deleteUnsignedHugeInt(UnsignedHugeInt *unsignedHugeInt) {
    if (unsignedHugeInt == NULL) return;
    deleteDigitCell(unsignedHugeInt->first);
    free(unsignedHugeInt);
}

void deleteDigitCell(DigitCell *digitCell) {
    if (digitCell == NULL) return;
    deleteDigitCell(digitCell->next);
    free(digitCell);
};

DigitCell *createDigitCell(unsigned short digit) {
    DigitCell *newDigit = malloc(sizeof(DigitCell));
    newDigit->digit = digit;
    newDigit->next = NULL;
    return newDigit;
}
