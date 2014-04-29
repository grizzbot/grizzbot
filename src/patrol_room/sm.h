
// Includes
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>
#include "oi.h"

#define EXIT_STATE end
#define ENTRY_STATE entry
#define NULL_STATE nas

enum state_codes { entry, foo, bar, end, nas};

enum ret_codes { ok, fail, repeat, narc};
struct transition {
    enum state_codes src_state;
    enum ret_codes   ret_code;
    enum state_codes dst_state;
};


int state_machine(void);

enum state_codes lookup_transitions( 
	enum state_codes last_state,
	enum ret_codes last_state_ret_code);

int entry_state(void);
int foo_state(void);
int bar_state(void);
int exit_state(void);

