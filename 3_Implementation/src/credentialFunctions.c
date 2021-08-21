/** 
* @author Ankit Kumar
* @author Anurag Thakur
* @author spoorti naik
* @file credentialFunctions.c
* @brief Functions related to User Credential management
*
*/

/*************************** HEADER FILES ***************************/
#include "credentialFunctions.h"

/*********************** FUNCTION DEFINITIONS ***********************/

status addNewCredential(const char *organisationName, const char *username, const char *password)
{
    FILE *outfile; // to open file for writing
    credential new_credential, credential;

    //check for NULL pointer
    if (organisationName == NULL ||
        username == NULL ||
        password == NULL)
        return NULL_PTR;

    if (strlen(organisationName) == 0 ||
        strlen(username) == 0 ||
        strlen(password) == 0)
    {
        return EMPTY_STRING;
    }

    // Check if credential file exist or not if not create it
    if (access(CREDENTIAL_FILE, F_OK) != 0)
    {
        outfile = fopen(CREDENTIAL_FILE, "w");

        if (outfile == NULL)
            return FAILURE;

        fclose(outfile);
    }

    if (credentialExist(organisationName, username))
    {
        printf("%s\n", "Organisation & Username combination already exist");
        return FAILURE;
    }

    strcpy(new_credential.organisationName, organisationName);
    strcpy(new_credential.username, username);
    strcpy(new_credential.password, password);

    // open CREDENTIAL_FILE to apend the credential
    outfile = fopen(CREDENTIAL_FILE, "a");
    if (outfile == NULL)
        return FAILURE;
    fwrite(&new_credential, sizeof(credential), 1, outfile);
    fclose(outfile);
    return SUCCESS;
}

status showAllCredentials()
{
    FILE *credential_file;
    credential credential;

    //*********open the credential file in read mode***********
    credential_file = fopen(CREDENTIAL_FILE, "r");
    if (credential_file == NULL)
    {
        printf("%s\n", "Show All Credential - Error opening file");
        return FAILURE;
    }

    //**************Reading the file until EOF and printing credentials*******************
    int i = 1;
    printf("%s\n", "********************************************************************************************");
    while (fread(&credential, sizeof(credential), 1, credential_file))
    {

        printf("%d) Organisation = %s, Username = %s, Password = %s\n", i,
               credential.organisationName, credential.username, credential.password);

        printf("%s\n", "********************************************************************************************");
        i++;
    }
    fclose(credential_file);
    return SUCCESS;
}

status deleteAllCredentials()
{
    // checking of file exist
    if (access(CREDENTIAL_FILE, F_OK) == 0)
    {
        remove(CREDENTIAL_FILE);
        return SUCCESS;
    }
    return FAILURE; // file does not exist
}

status deleteCredential(const char *organisationName, const char *username)
{
    credential credential_to_be_deleted;
    FILE *file,*temp_file;
    int counter;
    file=fopen(CREDENTIAL_FILE,"r");
    temp_file=fopen("Temp.dat","w");

    //********checking if there is any NULL or size 0 string in the arguments********
    if (organisationName == NULL ||
        username == NULL)
    {
        return NULL_PTR;
    }
    if (strlen(organisationName) == 0 ||
        strlen(username) == 0)
    {
        return EMPTY_STRING;
    }
    while (fread(&credential_to_be_deleted, sizeof(credential), 1,file))
    {
        if (strcmp(credential_to_be_deleted.organisationName, organisationName) == 0 &&
            strcmp(credential_to_be_deleted.username, username) == 0)
        {
            counter=1;            
        }
        else{
            //fprintf(temp_file,"%s %s %s \n",credential_to_be_deleted.organisationName,credential_to_be_deleted.username,credential_to_be_deleted.password);
            //fprintf(temp_file,"%s %s %s",credential_to_be_deleted.organisationName,
            //credential_to_be_deleted.username,credential_to_be_deleted.password);
            fwrite(&credential_to_be_deleted, sizeof(credential_to_be_deleted), 1, temp_file);
        }
    }
    if(counter==0){
        printf("Organisation name not found");
    }
    fclose(file);
    fclose(temp_file);
    remove(CREDENTIAL_FILE);
    int result = rename("Temp.dat", CREDENTIAL_FILE);
    if (result == 0) {
        printf("The file is renamed successfully.");
    } else {
        printf("The file could not be renamed.");
    }    
    printf("Deletion is success");
    return SUCCESS;
}
status searchCredential(const char *organisationName, const char *username, credential *out_credential)
{
    credential credential;
    FILE *credential_file;

    //********checking if there is any NULL or size 0 string in the arguments********
    if (organisationName == NULL ||
        username == NULL)
    {
        return NULL_PTR;
    }

    if (strlen(organisationName) == 0 ||
        strlen(username) == 0)
    {
        return EMPTY_STRING;
    }

    //*********open the credential file in read mode***********
    credential_file = fopen(CREDENTIAL_FILE, "r");
    if (credential_file == NULL)
    {
        printf("%s\n", "Search Credential - Error opening file");
        return FAILURE;
    }

    //**************Reading the file until EOF credential is found*******************
    while (fread(&credential, sizeof(credential), 1, credential_file))
    {
        if (strcmp(credential.organisationName, organisationName) == 0 &&
            strcmp(credential.username, username) == 0)
        {
            strcpy(out_credential->organisationName, credential.organisationName);
            strcpy(out_credential->username, credential.username);
            strcpy(out_credential->password, credential.password);
            fclose(credential_file);
            return SUCCESS;
        }
    }
    fclose(credential_file);
    return FAILURE;
}

bool credentialExist(const char *organisationName, const char *username)
{

    credential credential;
    FILE *credential_file;

    //********checking if there is any NULL or size 0 string in the arguments********
    if (organisationName == NULL ||
        username == NULL)
    {
        printf("%s\n", "credential exist- Null pointer");
        return false;
    }

    if (strlen(organisationName) == 0 || strlen(username) == 0)
    {
        return false;
    }

    //*********open the credential file in read mode***********
    credential_file = fopen(CREDENTIAL_FILE, "r");
    if (credential_file == NULL)
    {
        printf("%s\n", "credental exist - Error opening file");
        return false;
    }

    // **************Reading the file until EOF or credential is found*******************
    while (fread(&credential, sizeof(credential), 1, credential_file))
    {
        if (strcmp(credential.organisationName, organisationName) == 0 &&
            strcmp(credential.username, username) == 0)
        {
            fclose(credential_file);
            return true;
        }
    }
    fclose(credential_file);

    return false; // NO such credential found
}

status modifyCredentialOrganisation(char *organisation, char *username, char *new_Organisation_name)
{
    credential temp_credential;
    FILE *credential_file;

    if (organisation == NULL ||
        username == NULL ||
        new_Organisation_name == NULL)
    {
        return NULL_PTR;
    }

    if (strlen(organisation) == 0 ||
        strlen(username) == 0 ||
        strlen(new_Organisation_name) == 0)
    {
        return EMPTY_STRING;
    }

    if (credentialExist(organisation, username) == false)
    {
        printf("%s\n", "Organisation & Username combination does not exist");
        return FAILURE;
    }

    credential_file = fopen(CREDENTIAL_FILE, "r+");
    if (credential_file == NULL)
    {

        printf("%s\n", "error Opening file");
        return FAILURE;
    }

    int index = 0;
    while (fread(&temp_credential, sizeof(credential), 1, credential_file))
    {
        if (strcmp(temp_credential.organisationName, organisation) == 0 &&
            strcmp(temp_credential.username, username) == 0)
        {
            strcpy(temp_credential.organisationName, new_Organisation_name);
            break;
        }
        index++;
    }

    fseek(credential_file, index * sizeof(credential), SEEK_SET);
    fwrite(&temp_credential, sizeof(credential), 1, credential_file);

    fclose(credential_file);
    return SUCCESS;
}

status modifyCredentialUsername(char *organisation, char *username, char *new_username)
{
    credential temp_credential;
    FILE *credential_file;

    if (organisation == NULL ||
        username == NULL ||
        new_username == NULL)
    {
        return NULL_PTR;
    }

    if (strlen(organisation) == 0 ||
        strlen(username) == 0 ||
        strlen(new_username) == 0)
    {
        return EMPTY_STRING;
    }

    if (credentialExist(organisation, username) == false)
    {
        printf("%s\n", "Organisation & Username combination does not exist");
        return FAILURE;
    }

    credential_file = fopen(CREDENTIAL_FILE, "r+");
    if (credential_file == NULL)
    {

        printf("%s\n", "error Opening file");
        return FAILURE;
    }

    int index = 0;
    while (fread(&temp_credential, sizeof(credential), 1, credential_file))
    {
        if (strcmp(temp_credential.organisationName, organisation) == 0 &&
            strcmp(temp_credential.username, username) == 0)
        {
            strcpy(temp_credential.username, new_username);
            break;
        }
        index++;
    }

    fseek(credential_file, index * sizeof(credential), SEEK_SET);
    fwrite(&temp_credential, sizeof(credential), 1, credential_file);

    fclose(credential_file);
    return SUCCESS;
}

status modifyCredentialPassword(char *organisation, char *username, char *new_password)
{
    credential temp_credential;
    FILE *credential_file;

    if (organisation == NULL ||
        username == NULL ||
        new_password == NULL)
    {
        return NULL_PTR;
    }

    if (strlen(organisation) == 0 ||
        strlen(username) == 0 ||
        strlen(new_password) == 0)
    {
        return EMPTY_STRING;
    }

    if (credentialExist(organisation, username) == false)
    {
        printf("%s\n", "Organisation & Username combination does not exist");
        return FAILURE;
    }

    credential_file = fopen(CREDENTIAL_FILE, "r+");
    if (credential_file == NULL)
    {

        printf("%s\n", "error Opening file");
        return NULL_PTR;
    }

    int index = 0;
    while (fread(&temp_credential, sizeof(credential), 1, credential_file))
    {
        if (strcmp(temp_credential.organisationName, organisation) == 0 &&
            strcmp(temp_credential.username, username) == 0)
        {
            strcpy(temp_credential.password, new_password);
            break;
        }
        index++;
    }

    fseek(credential_file, index * sizeof(credential), SEEK_SET);
    fwrite(&temp_credential, sizeof(credential), 1, credential_file);

    fclose(credential_file);
    return SUCCESS;
}