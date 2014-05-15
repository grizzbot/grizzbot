
// Includes
#include <stdio.h>
#include <string.h>
#include <CUnit/Basic.h>
#include "gbst_statemachine.h"

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 *   * Returns zero on success, non-zero otherwise.
 *    */
int init_suite1(void)
{
   return 0;
}

/* The suite cleanup function.
 *  * Closes the temporary file used by the tests.
 *   * Returns zero on success, non-zero otherwise.
 *    */
int clean_suite1(void)
{
   return 0;
}

/* Simple test of fprintf().
 *  * Writes test data to the temporary file and checks
 *   * whether the expected number of bytes were written.
 *    */
void test_StateMachine(void)
{
    enum state_codes cur_state = ENTRY_STATE;
    enum ret_codes rc;
    int (* state_fun)(void);
    CU_ASSERT(0 == 0)
}

void test_StateMachineFail(void)
{
    enum state_codes cur_state = ENTRY_STATE;
    enum ret_codes rc;
    int (* state_fun)(void);
    CU_ASSERT(0 == 1)
}


/* The main() function for setting up and running the tests.
 *  * Returns a CUE_SUCCESS on successful running, another
 *   * CUnit error code on failure.
 *    */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite(__FILE__, init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test pass", test_StateMachine)) ||
       (NULL == CU_add_test(pSuite, "test fail", test_StateMachineFail)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}




