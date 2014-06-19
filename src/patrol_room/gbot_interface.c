
// Includes
#include <avr/io.h>
#include <stdlib.h>
#include "oi.h"




// Functions
void byteTx(uint8_t value);

void gbot_SendByte(uint8_t value)
{
	byteTx(value);
}
