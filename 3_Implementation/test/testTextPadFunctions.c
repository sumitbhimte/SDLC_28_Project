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

