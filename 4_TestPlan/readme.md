# TEST PLAN:

## Table no 1: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Display all choices to operate | A choice from the list of choices | Display list | Display list |Requirement based |
|  H_02       |Provide required details for Master & User Credentials|  Master & User Credentials|Successfully created Master & User Credentials|Successfully created Master & User Credentials|Scenario based    |
|  H_03       | Username or Password Not Entered | No Input |Display Username&Passwords are missed| Username&Passwords are missed|Boundary based    |
|  H_04       | Listing all Sorted Users and Passwords as per user command | A choice from the list of choices|List of Users|A List of Users|Scenario based    |
|  H_05       |	User shall create only 1 master account & multiple user accounts | A choice from the list of choices | Creation Successful & Display list | Creation Successful & Display list |Boundary based |
|  H_06       |A master shall be able to access all user credentials | A choice from the list of choices | Display list of all credentials| Display list of all credentials |Requirement based |
|  H_07       | All master and user credentials should be encrypted | User & Master Credentials | Encryption Successful | Encryption Successful |Requirement based |
|  H_08       | All master and user credentials should be decrypted while accessing | Commands to decrypt & show credentials | User & Master Credentials details decrypted | Decryption Successful |Requirement based |
|  H_09       | Credentials file encryption | Commands to encrypt file& Credentials file pointer | Credentials file encrypted | Credentials file encrypted |Requirement based |
|  H_10      | Delete a master user | username to delete user| Successfully deleted | Successfully deleted | Scenario based |
|  H_11      | Search a user by credential | username to search| Search successful & searched user data or Unsuccessful message | Search successful & searched user data or Unsuccessful message | Scenario based |


## Table no 2: Low level test plan


### Table for function containSpecialCharacter
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |Fuction should check wether a given string contains any special character or not |String username| Boolean value indicating the existence of special characters in a given string| Boolean value |Scenario based    |
|  L_01       |Fuction should check wether a given string contains any special character or not |"@SUMANTH"| true| true |Scenario based    |
|  L_01       |Fuction should check wether a given string contains any special character or not |"#Ankit654"| true| true |Scenario based   |
|  L_01       |Fuction should check wether a given string contains any special character or not |"####$!@$!$!FSD$#$@!#!@"| false| false |Scenario based   |

### Table for function containNumber
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_02       |Function should check wether a given string contains numbers or not |String input as parameter|Boolean value indicating the existence of numbers in a given string|Boolean value|Scenario based    |
|  L_02       |Function should check wether a given string contains numbers or not |"Hello"| false|false|Scenario based    |
|  L_02       |Function should check wether a given string contains numbers or not |"123password"|true|true|Scenario based    |
|  L_02       |Function should check wether a given string contains numbers or not |"####$!@$!$!FSD$#$@!#!@"|false|false|Scenario based    |

### Table for function containLowerCaseLetter
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_03       |A function should check whether a given string contain lower case letter or not|String input as parameter|Boolean value indicating the existence of lower case letters in a given string|Boolean value|Requirement based |
|  L_03       |A function should check wether a given string contain upper case letter or not |"Hello world"| true |true|Scenario based    |
|  L_03       |A function should check wether a given string contain upper case letter or not |"PWD"| false |false|Scenario based    |
|  L_03       |A function should check wether a given string contain upper case letter or not |"####$!@$!$!FS23D$#$@!#!@"| false |false|Scenario based    |
### Table for function containUpperCaseLetter
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_04       |A function should check whether a given string contain upper case letter or not|String input as parameter|Boolean value indicating the existence of upper case letters in a given string|Boolean value|Scenario based |
|  L_04       |A function should check whether a given string contain upper case letter or not|"operation"|false|false|Scenario based |
|  L_04       |A function should check whether a given string contain upper case letter or not|"Password"|true|true|Scenario based |
|  L_04       |A function should check whether a given string contain upper case letter or not|"####$!@$!$!FSD$er#$@!#!@"|true|true|Scenario based |



### Table for function passwordFormatCheck
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_05       |Function should verify the format of the password| String password|Boolean value based on the verification|Boolean Value|Scenario based |
|  L_05       |Function should verify the format of the password| "@npassWord123"|true|true|Scenario based |
|  L_05       |Function should verify the format of the password|"stringpassword"|false|false|Scenario based |
|  L_05       |Function should verify the format of the password|"pwd123456"|false|false|Scenario based |


### Table for function usernameFormatCheck
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_06       |Function should verify the format of the username| String username|Boolean value based on the verification|Boolean value|Scenario based |
|  L_06       |Function should verify the format of the username| "sumanth123"|true|true|Scenario based |
|  L_06       |Function should verify the format of the username| "@h123"|false|false|Requirement based |
|  L_06       |Function should verify the format of the username| "abcdefghi"|false|false|Scenario based |
|  L_06       |Function should verify the format of the username| "abc$$defgh12i"|false|false|Scenario based |




### Table for function createMasteUserAccount
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_07       |Test the function which is used to call to create the master user|Username string and Password sting| status SUCCESS or FAILURE |status SUCCESS or FAILURE|Scenario based |
|  L_07       |Test the function which is used to call to create the master user|"username" "Pass123"| status SUCCESS |status SUCCESS|Scenario based |
|  L_07       |Test the function which is used to call to create the master user|"!!name" "123"| status FAILURE |status FAILURE|Scenario based |

### Table for function void deleteMasterUserAccount(void)

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_08       |Test the function which is used to call to delete the master user| current master data|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_08       |Test the function which is used to call to delete the master user| current master data|status SUCCESS |status SUCCESS|Scenario based |
|  L_08       |Test the function which is used to call to delete the master user| current master data|status  FAILURE|statu FAILURE|Scenario based |

### Table for function modifyMasterName
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_09       |Test the modify function for master account username|New username string|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_09       |Test the modify function for master account username|"newusername|status SUCCESS |status SUCCESS |Scenario based |
|  L_09       |Test the modify function for master account username|"oldusername","newusername123"|status  FAILURE|status FAILURE|Scenario based |





### Table for function modifyMasterPassword
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_10       |Test the modify function for master account password|New password String|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_10       |Test the modify function for master account password|"newpassword123"|status SUCCESS |status SUCCESS |Scenario based |
|  L_10       |Test the modify function for master account password|"oldpassword","newpassword123"|status  FAILURE|status FAILURE|Scenario based |



### Table for function userAccountExist
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_11       |While creating a user,check if the master user already exists or not| master username stringsBoolean value based on the verification |status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_11       |While creating a user,check if the master user already exists or not|"username"|status SUCCESS |status SUCCESS|Scenario based |
|  L_11       |While creating a user,check if the master user already exists or not|"user555" |status FAILURE|status FAILURE|Scenario based |

### Table for function verifyMasterUserAccount
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_12       |When master user tries to sign in Verify master user|   master username & password string |Boolean value based on the verification|Boolean value|Scenario based |
|  L_12       |When master user tries to sign in Verify master user|  "username","usepwd@123rname"|true|true|Scenario based |
|  L_12       |When master user tries to sign in Verify master user| "user789","userpwd123"  |false|false|Scenario based |


### Table for function addNewCredential
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_13       |Test for the function used  to add new credentials|Strings organization name,username,password|status SUCCESS or FAILURE or NULL_PTR or EMPTY_STRING|status SUCCESS or FAILURE or NULL_PTR or EMPTY_STRING|Scenario based |
|  L_13       |Test for the function used  to add new credentials|"facebook", "Ankit", "ankit123"|status SUCCESS |status SUCCESS |Scenario based |
|  L_13       |Test for the function used  to add new credentials|"facebook", "Ankit", "ankit123"|status  FAILURE|status  FAILURE|Scenario based |
|  L_13       |Test for the function used  to add new credentials|NULL, "sumanth", "sumanth123"|status NULL_PTR|status NULL_PTR|Scenario based |
|  L_13       |Test for the function used  to add new credentials|"", "", "pass123"|status EMPTY_STRING|status EMPTY_STRING|Requirement based |



### Table for function deleteAllCredentials
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|

|  L_14       |Test for the function used to delete new credentials|credentials file|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_14       |Test for the function used to delete new credentials|"facebook", "abc", "abc123"|status FAILURE|status FAILURE|Scenario based |
|  L_14       |Test for the function used to delete new credentials|credentials file|status SUCCESS |status SUCCESS|Scenario based |


### Table for function searchCredential
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_15       |Test for the function used search credentials |organization name, username, outputvariable|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_15       |Test for the function used search credentials |"google", "abc", "&output_credential"|Status SUCCESS |Status SUCCESS|Scenario based |
|  L_15       |Test for the function used search credentials |"oname", "xyzz", "&opvariable"|Status FAILURE  |Status FAILURE|Scenario based |

### Table for function modifyCredentialUsername
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_16       |Test for the function used to modify credential username |Strings Username,organization name & new username|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_16       |Test for the function used to modify credential username |"Apple", "Anup", "Manoj"|status SUCCESS|status SUCCESS|Scenario based |
|  L_16       |Test for the function used to modify credential username |"8_facebook", "Ankit"|status FAILURE|status FAILURE|Scenario based |


### Table for function modifyCredentialOrganisation
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_17       |Test for the function used to modify credential organisation |Strings Username, organization name & neworganization name|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_17       |Test for the function used to modify credential organisation |"Akshay","google","facebook"|status SUCCESS|status SUCCESS|Scenario based |
|  L_17       |Test for the function used to modify credential organisation |"Akshay","google","google"|status FAILURE|status FAILURE|Scenario based |
### Table for function modifyCredentialPassword
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|

|  L_18       |Test for the function used to modify credential password |Strings organization name, username & new password|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_18       |Test for the function used to modify credential password |"facebook","Sumanth","qwer321"|status SUCCESS|status SUCCESS|Scenario based |
|  L_18       |Test for the function used to modify credential password |"Apple",NULL,"yiuo789"|status FAILURE|status FAILURE|Scenario based |

### Table for function showAllCredentials
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_19       |Show all credentials  | Credential File|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_19       |Show all credentials  | FILE *credential_file|status SUCCESS|status SUCCESS|Scenario based |
|  L_19       |Show all credentials  | FILE *credential_file|status FAILURE|status FAILURE|Scenario based |

### Table for function sortcredentialsbyorganization
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_20       |Test for the function used to sort given user credentials according to organisation name |Credential File|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_20       |Test for the function used to sort given user credentials according to organisation name |FILE FILE *credential_file |status SUCCESS|status SUCCESS|Scenario based |
|  L_20       |Test for the function used to sort given user credentials according to organisation name |FILE FILE *credential_file |status FAILURE|status FAILURE|Scenario based |

### Table for function credentialExist
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_21       |Test for the function used  check if credential exist or not in the system |Strings organization name & username|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_21       |Test for the function used  check if credential exist or not in the system |"Apple","John"|status FAILURE|status FAILURE|Scenario based |
|  L_21       |Test for the function used  check if credential exist or not in the system |"google","Smith"|status SUCCESS |status SUCCESS |Scenario based |
### Table for function encryptcredentialfile
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_22       |Test for the function used to encrypt credential file | credential file|status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_22       |Test for the function used to encrypt credential file | FILE *c_file_name|status FAILURE|status FAILURE|Scenario based |
|  L_22       |Test for the function used to encrypt credential file | NULL |status FAILURE|status FAILURE|Scenario based |
|  L_22       |Test for the function used to encrypt credential file | FILE *credential_file|status SUCCESS|status SUCCESS|Scenario based |

### Table for function decryptcredentialfile
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_23       |Test for the function used to decrypt credential file |credential file |status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_23       |Test for the function used to decrypt credential file |FILE *credential_file |status FAILURE|status FAILURE|Scenario based |
|  L_23       |Test for the function used to decrypt credential file |FILE *cr_file_name |status SUCCESS |status SUCCESS|Scenario based |
|  L_23       |Test for the function used to decrypt credential file |NULL |status FAILURE |status FAILURE |Scenario based |
### Table for function hashaccount
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_24       |Test for the function used to create hash of master account and username |Strings username, organization name & password |status SUCCESS or FAILURE|status SUCCESS or FAILURE|Scenario based |
|  L_24       |Test for the function used to create hash of master account and username |"","google","ad123"|status FAILURE|status FAILURE|Scenario based |
|  L_24       |Test for the function used to create hash of master account and username |"tiger",NULL,"iii888"|status FAILURE|status FAILURE|Scenario based |
|  L_24       |Test for the function used to create hash of master account and username |"Sumanth", "ltts","777pword" |status SUCCESS|status SUCCESS|Scenario based |