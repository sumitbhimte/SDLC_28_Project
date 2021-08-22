/** 
* @authors Ankit Anurag Harish Hrituj Purva Raj Sanjay Sumanth Sumit Spoorti 
* @file masterAccountFunctions.c
* @brief Function definitions for the master account management
*
*/

/*************************** HEADER FILES ***************************/
#include "masterAccountFunctions.h"

typedef struct
{
    unsigned char username[SHA256_BLOCK_SIZE];
    unsigned char password[SHA256_BLOCK_SIZE];

} masterAccount;

/*********************** FUNCTION DEFINITIONS ***********************/
