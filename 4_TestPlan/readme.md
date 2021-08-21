# TEST PLAN:

## Table no 1: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Display all choices to operate | A choice from the list of choices | Display list | Display list |Requirement based |
|  H_02       |Provide required details for Master & User Credentials|  Master & User Credentials|Successfully created Master & User Credentials|----------------|Scenario based    |
|  H_03       | Username or Password Not Entered | No Input |Display What is missed|----------------|Boundary based    |
|  H_04       | Listing all Sorted Users and Passwords as per user command | A choice from the list of choices|List of Users|----------------|Scenario based    |
|  H_05       |	User shall create only 1 master account & multiple user accounts | A choice from the list of choices | Creation Successful & Display list | Creation Successful & Display list |Boundary based |
|  H_06       |A master shall be able to access all user credentials | A choice from the list of choices | Display list | Display list |Requirement based |
|  H_07       | All master and user credentials should be encrypted | User & Master Credentials | Encryption Successful | Encryption Successful |Requirement based |
|  H_08       | All master and user credentials should be decrypted while accessing | Commands to decrypt & show credentials | User & Master Credentials details decrypted | In Progress |Requirement based |
|  H_09       | Credentials file encryption | Commands to encrypt file | Credentials file encrypted | In Progress |Requirement based |
|  H_10      | Delete a master user | username to delete user| Successfully deleted | In Progress | Scenario based |
|  H_11      | Search a user | username to search| Search successful & searched user data or Unsuccessful message | In Progress | Scenario based |
|  H_11      | Search a user | username to search| Search successful & searched user data or Unsuccessful message | In Progress | Scenario based |

## Table no 2: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |--------------------------------------------------------------|  ------------|-------------|----------------|Requirement based |
|  L_02       |--------------------------------------------------------------|  ------------|-------------|----------------|Scenario based    |
|  L_03       |--------------------------------------------------------------|  ------------|-------------|----------------|Boundary based    |
