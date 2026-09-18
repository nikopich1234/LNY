// LogCon.h

#include <stdbool.h>

#ifndef LOGCON
#define LOGCON

bool NOT(bool a);

bool AND(bool a, bool b);

bool OR(bool a, bool b);

bool IMP(bool a, bool b);

bool EQU(bool a, bool b);

bool XOR(bool a, bool b);

bool F15(bool a, bool b, bool c);

#endif