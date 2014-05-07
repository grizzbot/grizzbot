
// Includes
#include "gbot_data.h"

volatile gbot_sensors_t gbot_sensors = {
	.flag = 0,
	.index = 0
	};


volatile gbot_motion_t gbot_motion = {
	.distance = 0,
	.angle = 0
	};
