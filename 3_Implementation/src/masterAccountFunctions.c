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
status createMasterUserAccount(const char *username, const char *password)
{
    status return_value;   //
    FILE *outfile;         // To write the USER_FILE.
    SHA256_CTX sha256;     // For hashing
    masterAccount account; // For username and password hash

    if (username == NULL || password == NULL)
    {
        return NULL_PTR;
    }

    if (strlen(username) == 0 || strlen(password) == 0)
    {
        return EMPTY_STRING;
    }

    //1. Open USER_FILE to write master account data.
    outfile = fopen(USER_FILE, "w");
    if (outfile == NULL)
    {
        printf("%s\n", "Failed to open USER_FILE");
        return FAILURE;
    }

    // 2. Create hash of Username string and save it in account.username
    sha256_init(&sha256);
    sha256_update(&sha256, username, strlen(username));
    sha256_final(&sha256, account.username);

    //3. create hash of Password string and save it in account.password
    sha256_init(&sha256);
    sha256_update(&sha256, password, strlen(password));
    sha256_final(&sha256, account.password);

    // EVP_Digest(username, strlen(username), account.username, NULL, EVP_sha256(), NULL);

    // EVP_Digest(password, strlen(password), account.password, NULL, EVP_sha256(), NULL);

    // 4. Write struct masterAccount to USER_FILE
    fwrite(&account, sizeof(masterAccount), 1, outfile);
    if (fwrite != 0)
    {
        //printf("Account created Succefully !\n");
        return_value = SUCCESS;
    }
    else
    {
        printf("error writing masterUser file !\n");
        return_value = FAILURE;
    }

    // Close  FILE *outfile
    fclose(outfile);
    return return_value;
}

status deleteMasterUserAccount()
{
    status return_value;
    //1. Check if master Account Exist if true delete it
    if (masterUserAccountExist())
    {
        remove(USER_FILE);
        return_value = SUCCESS;
    }
    else // There was no USER_FILE to delete
        return_value = FAILURE;

    // 2. check if credential file exist , if true delete it
    if (access(CREDENTIAL_FILE, F_OK) == 0)
    {
        remove(CREDENTIAL_FILE);
    }

    return return_value;
}


status modifyMasterUsername(const char *new_username)
{
    masterAccount account; // For master user password and username
    status return_value;
    FILE *infile, *outfile;
    SHA256_CTX sha256;

    if (new_username == NULL)
    {
        return NULL_PTR;
    }

    if (strlen(new_username) == 0)
    {
        return EMPTY_STRING;
    }

    //1. open current Userfile
    infile = fopen(USER_FILE, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        return FAILURE;
    }

    //2. Read the current userfile
    fread(&account, sizeof(masterAccount), 1, infile);
    fclose(infile);

    //3. change the username

    sha256_init(&sha256);
    sha256_update(&sha256, new_username, strlen(new_username));
    sha256_final(&sha256, account.username);

    // EVP_Digest(new_username, strlen(new_username), account.username, NULL, EVP_sha256(), NULL);

    // 4. open USER_FILE again in write mode to write new password
    outfile = fopen(USER_FILE, "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        return FAILURE;
    }

    // write to USER_FILE
    fwrite(&account, sizeof(masterAccount), 1, outfile);
    if (fwrite != 0)
    {
        //printf("Account password changed Succefully !\n");
        return_value = SUCCESS;
    }
    else
    {
        //printf("error writing masterUser file !\n");
        return_value = FAILURE;
    }

    fclose(outfile);

    return return_value;
}
status modifyMasterPassword(const char *new_password)
{
    masterAccount account; // For master user password and username
    status return_value;
    FILE *infile, *outfile;
    SHA256_CTX sha256;

    if (new_password == NULL)
    {
        return NULL_PTR;
    }

    if (strlen(new_password) == 0)
    {
        return EMPTY_STRING;
    }

    //1. open current Userfile
    infile = fopen(USER_FILE, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        return FAILURE;
    }

    //2. Read the current userfile
    fread(&account, sizeof(masterAccount), 1, infile);
    fclose(infile);

    //3. change the password
    sha256_init(&sha256);
    sha256_update(&sha256, new_password, strlen(new_password));
    sha256_final(&sha256, account.password);
    // EVP_Digest(new_password, strlen(new_password), account.password, NULL, EVP_sha256(), NULL);

    // 4. open USER_FILE again in write mode to write new password
    outfile = fopen(USER_FILE, "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        return FAILURE;
    }

    // write to USER_FILE
    fwrite(&account, sizeof(masterAccount), 1, outfile);
    if (fwrite != 0)
    {
        //printf("Account password changed Succefully !\n");
        return_value = SUCCESS;
    }
    else
    {
        printf("error writing masterUser file !\n");
        return_value = FAILURE;
    }

    fclose(outfile);

    return return_value;
}
