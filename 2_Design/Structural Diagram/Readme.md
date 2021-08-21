# Structural Diagram For Project
## 1. Softwere Used:<br />
  * Structural Diagram has been created using the softwere named __STAR UML__.<br />
  * StarUML is a sophisticated software modeler aimed to support agile and concise modeling.<br />
  * The key features of StarUML are:
    1. Multi-platform support (MacOS, Windows and Linux).
    2. UML 2.x standard compliant.
    3. SysML support.
    4. Entity-Relationship diagram (ERD).
    5. Data-flow diagram (DFD).
    6. Flowchart diagram.
    7. Multiple windows.
    8. Modern UX.
    9. Model-driven development.
    10. Open APIs.
    11. Various third-party extensions.
    12. Export to HTML docs. <br />

## 2. DESIGN:<br />

  Mainly design consist of different block which represents following files:<br />
  <br />
  A.  __project_main.c__<br />
  B.  __common.h__<br />
  C.  __credentialFunctions.h__<br />
  D.  __fileEncryptionDecryption.h__<br />
  E.  __masterAccountFunctions.h__<br />
  F.  __sha256.h__<br />
  G.  __passwordUsernameFormatChecker.h__<br />
  H.  __credentialFunctions.c__<br />
  I.  __fileEncryptionDecryption.c__<br />
  J.  __masterAccountFunctions.c__<br />
  K.  __sha256.c__<br />
  L.  __passwordUsernameFormatChecker.c__<br />

Each block contains the the different functions in it. Some file name describe the function performed by the file. <br />   
A. __project_main.c__:<br />
* It contain the main function of the project.
* It also contain void clean_stdin(void) which allows only clean and aloowed standerd input.
* It also contain switch cases which are used to show User Interface(UI).

B. __common.h__:<br />
* It is a header file.
* It has micro defination in it.
* It has typedef enum which define different return type values for status.

C. __credentialFunctions.h__:<br />
* It is a header file created for credentialFunction.c.
* It has different function declaration inside it.
* It has functions like addNewCredential() ,deleteCredential(), modifyCredentialOrganisation(), modifyCredentialUsername(), etc.

D. __fileEncryptionDecryption.h__:<br />
* It is a header file assosiated with credentialFunction file.
* It has different function declaration inside it.
* It has functions like encryptFile() ,decryptFile().

E. __masterAccountFunctions.h__:<br />
* It is a header file assosiated with masterFunction file.
* It has different function declaration inside it.
* It has functions like create() ,delete(), modify(), etc.

F. __sha256.h__:<br />
* It is a header file.
* It has some typedef variables.
* It has functions declaration like init() , update() & final().

G. __passwordUsernameFormatChecker.h__:<br />
* It is a header file.
* It has different function declaration inside it which defines different constraints.
* It has functions like containSpecialCharecter(), containNumber(), etc.

H. __credentialFunctions.c__:<br />
* It contain defination of functions declared by credentailFunction.h header file.
* It has different function defination.
* It has functions like addNewCredential() ,deleteCredential(), modifyCredentialOrganisation(), modifyCredentialUsername(), etc.

I. __fileEncryptionDecryption.c__:<br />
* It contain defination of functions declared by fileEncryptionDecryption.h header file.
* It has function defination.
* It has functions like encryptFile() ,decryptFile().

J. __masterAccountFunctions.c__:<br />
* It contain defination of functions declared by masterAccountFunctions.h header file.
* It has different function defination.
* It has functions like create() ,delete(), modify(), etc.

K. __sha256.c__:<br />
* It contain defination of functions declared by sha256.h header file.
* It has different function defination.
* It has functions defination like init() , update() & final().

L. __passwordUsernameFormatChecker.c__:<br />
* It contain defination of functions declared by passwordUsernameFormatChecker.h header file.
* It has different function defination.
* It has functions like containSpecialCharecter(), containNumber(), etc.
