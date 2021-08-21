#ifndef FILE_ENCRYPTION_DECRYPTION_H
#define FILE_ENCRYPTION_DECRYPTION_H

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include "common.h"

/*********************** FUNCTION DECLARATIONS **********************/

const char *increseKeySize(char *key_s);

/* Key should be strictly of length 16 */
status encryptFile(FILE *input, FILE *output, char *key);
status decryptFile(FILE *input, FILE *output, char *key);

#endif