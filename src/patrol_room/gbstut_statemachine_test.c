
// Includes
#include <CUnit/Basic.h>
#include "gbst_statemachine.h"

void gbstut_StateMachineTest(void)
{
    enum state_codes cur_state = ENTRY_STATE;
    enum ret_codes rc;
    int (* state_fun)(void);
    CU_ASSERT(0 == 0)
}

void gbstut_StateMachineFailTest(void)
{
    enum state_codes cur_state = ENTRY_STATE;
    enum ret_codes rc;
    int (* state_fun)(void);
    CU_ASSERT(0 == 1)
}




