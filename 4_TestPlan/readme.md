# TEST PLAN:

## Table no 1: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Display all choices to operate | A choice from the list of choices | Display list | Display list |Requirement based |
|  H_02       |Provide required details for Master & User Credentials|  Master & User Credentials|Successfully created Master & User Credentials|----------------|Scenario based    |
|  H_03       | Username or Password Not Entered | No Input |Display What is missed|----------------|Boundary based    |
|  H_04       | Listing all Sorted Users and Passwords as per user command | A choice from the list of choices|List of Users|----------------|Scenario based    |

## Table no 2: Low level test plan
| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |Fuction should check wether a given string contains any special character or not |string||Functions that check strings return Boolean values |Requirement based |
|  L_02       |Function should check wether a given string contains numbers or not |numbers|Functions check the string and return the numbers|----------------|Scenario based    |
|  L_03       |A function should check wether a given string contain upper case letter or not |upper case letter|function return upper case letter|----------------|Boundary based    |
|  L_04       |A function should check wether a given string contain lower case letter or not|lower case letter|function return lower case letter|----------------|Requirement based |
|  L_05       |Function should verify the format of the password| user password|function verify the password|----------------|Requirement based |
|  L_06       |Function should verify the format of the username| user username|function verify the username|----------------|Requirement based |
|  L_07       |Test the function which is used to call to create the master user|create user|function create master user|----------------|Requirement based |
|  L_08       |Test the function which is used to call to delete the master user|delete user|function delete master user|----------------|Requirement based |
|  L_09       |Test the modify function for master account username|master username|function check the master account username|----------------|Requirement based |
|  L_10       |Test the modify function for master account password|master password|function check the master account password|----------------|Requirement based |
|  L_11       |While creating a user,check if the master user already exists or not|  ------------|-------------|----------------|Requirement based |
|  L_12       |When master user tries to sign in authoenticate master user|  ------------|-------------|----------------|Requirement based |
|  L_13       |Test for the function used to add new credentials|add new credentials|-------------|----------------|Requirement based |
|  L_14       |Test for the function used to delete new credentials|delete new credentials|-----------------|----------------|Requirement based |
|  L_15       |While creating a credential check whether the credential already exists in the system or not and then preceeding|user credentials|value indicating the existence of user credentials|----------------|Requirement based |
