
// Includes
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>
#include "oi.h"

typedef struct gbot_sensors_t
{
	uint8_t flag;
	uint8_t index;
	uint8_t in[Sen6Size];
	uint8_t sensors[Sen6Size];
} gbot_sensors_t;

extern volatile gbot_sensors_t gbot_sensors;



typedef struct gbot_motion_t
{
	int16_t distance;
	int16_t angle;
} gbot_motion_t;

extern volatile gbot_motion_t gbot_motion;



typedef struct gbot_timer_t
{
	uint8_t is_on;
	uint16_t count;
} gbot_timer_t;

extern volatile gbot_timer_t gbot_timer;
