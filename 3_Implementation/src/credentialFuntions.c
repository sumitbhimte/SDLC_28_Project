/** 
* @author Sumit Bhimte
* @author Ankit Kumar
* @author Anurag Thakur
* @author Chaluvadi Sanjay Sai Naresh
* @author Chappdi Harish
* @author Edara Raj Kumar
* @author Hrituj Uday Wadyalkar
* @author Purva Dilip Baniya
* @author Spoorti Suresh Naik
* @author Sumanth Kubasad
* @file credetnialFunctions.c
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

        printf("%d) Organisation = %s, Username = %s, Password = %s\n", i,credential.organisationName, credential.username, credential.password);
        printf("%s\n", "********************************************************************************************");
        i++;
    }

    fclose(credential_file);
    return SUCCESS;
}

status showAllSortedCredentials()
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
    struct Store{
        char name[12];
        char user[12];
        char pass[12];
    };
    struct Store arr[10], temp;

    int i = 1;
    while (fread(&credential, sizeof(credential), 1, credential_file))
    {
        strcpy(arr[i].name,credential.organisationName);
        strcpy(arr[i].user,credential.username);
        strcpy(arr[i].pass,credential.password);
        i++;
    }

    for (int x = 1; x < i; x++)
    {
        for (int j = 0; j < i-x; j++)
        {
            if (strcmp(arr[j].name, arr[j+1].name) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
    }
    for (int j = 1; j < i; j++)
    {
        printf("OrganisationName = %s", arr[j].name);
        printf("UserName = %s", arr[j].user);
        printf("Password = %s", arr[j].pass);
        printf("=================================================\n");
    }
    
    fclose(credential_file);
    return SUCCESS;
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
    // ***** reading from file till EOF
    {
        if (strcmp(credential_to_be_deleted.organisationName, organisationName) == 0 &&
            strcmp(credential_to_be_deleted.username, username) == 0)
        {
            counter=1; 
            return SUCCESS;           
        }
        else{
            // ***** writing into new file 
            fwrite(&credential_to_be_deleted, sizeof(credential_to_be_deleted), 1, temp_file);
            return FAILURE;
        }
    }
    if(counter==0){
        // If file not found
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