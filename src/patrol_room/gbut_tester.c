
// Includes
#include <stdio.h>
#include <string.h>
#include <CUnit/Basic.h>

#include "gbotut_data_test.h"
#include "gbstut_statemachine_test.h"

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
   if (
	CU_ADD_TEST(pSuite, gbotut_DataInitTest) ||
	CU_ADD_TEST(pSuite, gbstut_StateMachineTest) ||
	CU_ADD_TEST(pSuite, gbstut_StateMachineTestFail) ||
	NULL //for copy and paste above line purposes
	)
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




