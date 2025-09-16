//
// Created by JAD on 16/09/2025.
//

#include "unsignedhugeint.h"

DigitCell *createDigitCell(unsigned short digit);

void deleteDigitCell(DigitCell *digitCell);

int countDigitCells(DigitCell *cell);

UnsignedHugeInt *addDigitCells(DigitCell *firstCell, int sizeFirst, DigitCell *secondCell, int sizeSecond);

unsigned short addTwoChar(unsigned short first, unsigned short second);

UnsignedHugeInt *createUnsignedHugeInt();

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

unsigned short addTwoChar(unsigned short first, unsigned short second) {
    return first + second - '0';
}

UnsignedHugeInt *createUnsignedHugeInt() {
    UnsignedHugeInt *uhi = malloc(sizeof(UnsignedHugeInt));
    uhi->first = NULL;
    return uhi;
};

UnsignedHugeInt *addDigitCells(DigitCell *firstCell, int sizeFirst, DigitCell *secondCell, int sizeSecond) {
    if (sizeFirst == 1 && sizeSecond == 1) {
        UnsignedHugeInt *result = createUnsignedHugeInt();
        result->first = createDigitCell(addTwoChar(firstCell->digit, secondCell->digit));
        return result;
    }
    unsigned short firstDecrement = 0;
    if (sizeFirst >= sizeSecond) {
        firstDecrement = 1;
    }
    if (sizeSecond >= sizeFirst) {
        secondCell = secondCell->next;
        sizeSecond--;
    }
    if (firstDecrement) {
        firstCell = firstCell->next;
        sizeFirst--;
    }

    return addDigitCells(firstCell, sizeFirst, secondCell, sizeSecond);
}

UnsignedHugeInt *addUnsignedHugeInt(UnsignedHugeInt *first, UnsignedHugeInt *second) {
    int sizeFirst = countDigitsFromUnsignedHugeInt(first);
    int sizeSecond = countDigitsFromUnsignedHugeInt(second);

    return addDigitCells(first->first, sizeFirst, second->first, sizeSecond);
}

int countDigitCells(DigitCell *cell) {
    if (cell == NULL) return 0;
    return 1 + countDigitCells(cell->next);
}

int countDigitsFromUnsignedHugeInt(UnsignedHugeInt *unsignedHugeInt) {
    if (unsignedHugeInt == NULL) return 0;
    return countDigitCells(unsignedHugeInt->first);
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
