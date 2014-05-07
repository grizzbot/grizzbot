
// Includes
#include <stdlib.h>
#include <stdio.h>
#include "gbot_data.h"


int main(int argc, char *argv[]) {
	if (gbot_sensors.flag != 0)
		return -1;
	if (gbot_sensors.index != 0)
		return -2;
	if (gbot_motion.distance != 0)
		return -3;
	if (gbot_motion.angle != 0)
		return -4;
	return 0;
}
