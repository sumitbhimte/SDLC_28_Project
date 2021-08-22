#include "unity.h"
#include "passwordUsernameFormatChecker.h"
#include "masterAccountFunctions.h"
#include "credentialFunctions.h"
#define PROJECT_NAME "TextPad"

/* Prototypes for all the test functions */

/********************************
 * Filename -> passwordUsernameFormatChecker.c
*/


/********************************
 * Filename -> masterAccountFunctions.c
*/
void test_createMasteUserAccount(void);
void test_deleteMasterUserAccount(void);

/********************************
 * Filename -> credentialFunctions.c
*/
void test_addNewCredential(void);
void test_showAllCredentials(void);
void test_showAllSortedCredentials(void);
/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown() {}


/* Start of the application test */
int main()
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */

  /********************************
 * Filename -> passwordUsernameFormatChecker.c
 */

  /********************************
 * Filename -> masterAccountFunctions.c
*/
   RUN_TEST(test_createMasteUserAccount);
  RUN_TEST(test_deleteMasterUserAccount);

  /********************************
 * Filename -> credentialFunctions.c
*/
  RUN_TEST(test_addNewCredential);
  RUN_TEST(test_showAllCredentials);
  RUN_TEST(test_showAllSortedCredentials);
  
  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */

/********************************
 * Filename -> passwordUsernameFormatChecker.c
*/

/********************************

* Filename -> masterAccountFunctions.c
*/

void test_createMasteUserAccount(void)
{
  TEST_ASSERT_EQUAL(SUCCESS, createMasterUserAccount("AnkitKumar", "Ankit123"));
  TEST_ASSERT_EQUAL(NULL_PTR, createMasterUserAccount(NULL, NULL));
}
void test_deleteMasterUserAccount(void)
{
  createMasterUserAccount("Ankit123", "Ankit123");
  TEST_ASSERT_EQUAL(SUCCESS, deleteMasterUserAccount());

  TEST_ASSERT_EQUAL(FAILURE, deleteMasterUserAccount());
}

/********************************
 * Filename -> credentialFunctions.c
*/

void test_addNewCredential(void)
{
  TEST_ASSERT_EQUAL(SUCCESS, addNewCredential("facebook", "User1", "Pass123"));
  TEST_ASSERT_EQUAL(SUCCESS, addNewCredential("twitter", "User2", "Pass123"));
  TEST_ASSERT_EQUAL(FAILURE, addNewCredential("facebook", "User3", "Pass123"));
  TEST_ASSERT_EQUAL(NULL_PTR, addNewCredential(NULL, "User4", "Pass123"));
  TEST_ASSERT_EQUAL(EMPTY_STRING, addNewCredential("", "", "Pass123"));
  TEST_ASSERT_EQUAL(NULL_PTR, addNewCredential("as", "User5", NULL));

  deleteAllCredentials();
}
void test_showAllCredentials(void)
{
  addNewCredential("facebook", "User1", "Pass123");
  addNewCredential("Amcat", "User2", "Pass123");
  TEST_ASSERT_EQUAL(SUCCESS, showAllCredentials());
  deleteAllCredentials();

  TEST_ASSERT_EQUAL(FAILURE, showAllCredentials());

  deleteAllCredentials();
}

void test_showAllSortedCredentials(void)
{
  addNewCredential("facebook", "User1", "Pass123");
  addNewCredential("twitter", "User2", "Pass213");
  addNewCredential("Amcat", "User3", "Pass312");
  TEST_ASSERT_EQUAL(SUCCESS, showAllSortedCredentials());
  deleteAllCredentials();

  TEST_ASSERT_EQUAL(FAILURE, showAllSortedCredentials());

  deleteAllCredentials();
}
