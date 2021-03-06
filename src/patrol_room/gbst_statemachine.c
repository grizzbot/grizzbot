
// Includes
#include <stdlib.h>
#include "gbst_statemachine.h"

/* array and enum below must be in sync! */
int (* state[])(void) = { entry_state, turnaround_state, drive_state, exit_state};

/* transitions from end state aren't needed */
struct transition state_transitions[] = {
    {entry, ok,     drive},
    {entry, fail,   end},
    {drive,   ok,     turnaround},
    {drive,   fail,   end},
    {drive,   repeat, drive},
    {turnaround,   ok,     drive},
    {turnaround,   fail,   end},
    {turnaround,   repeat, turnaround},
    {nas,   narc,   nas }};

int entry_state(void){return 0;}
int turnaround_state(void){return 0;}
int drive_state(void){return 0;}
int exit_state(void){return 0;}

enum state_codes lookup_transitions( 
	enum state_codes last_state,
	enum ret_codes last_state_ret_code)
{
	int i = 0;
	for (i = 0; state_transitions[i].src_state != NULL_STATE; i++)
	{
		if (
			state_transitions[i].src_state == last_state &&
			state_transitions[i].ret_code == last_state_ret_code
		)
		{
			return state_transitions[i].dst_state;
		}
			
	}

	return last_state;
}

int state_machine()
{
    enum state_codes cur_state = ENTRY_STATE;
    enum ret_codes rc;
    int (* state_fun)(void);

    for (;;) {
        state_fun = state[cur_state];
        rc = state_fun();
        if (EXIT_STATE == cur_state)
            break;
        cur_state = lookup_transitions(cur_state, rc);
    }

    return 0;
}
