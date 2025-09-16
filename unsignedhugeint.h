//
// Created by JAD on 16/09/2025.
//

#ifndef HUGEINT__UNSIGNEDHUGEINT_H_
#define HUGEINT__UNSIGNEDHUGEINT_H_

typedef struct DigitCell {
  unsigned short digit;
  struct DigitCell *next;
} DigitCell;

typedef struct UnsignedHugeInt {
  DigitCell *first;
} UnsignedHugeInt ;

UnsignedHugeInt *createUnsignedHugeIntFromString(char* stringToConvert);
void deleteUnsignedHugeInt(UnsignedHugeInt* unsignedHugeInt);
void displayUnsignedHugeInt(UnsignedHugeInt* unsignedHugeInt);
UnsignedHugeInt* addUnsignedHugeInt(UnsignedHugeInt* first, UnsignedHugeInt* second);
int countDigitsFromUnsignedHugeInt(UnsignedHugeInt* unsignedHugeInt);
UnsignedHugeInt* simplifyUnsignedHugeInt(UnsignedHugeInt* unsignedHugeInt);

#endif //HUGEINT__UNSIGNEDHUGEINT_H_
