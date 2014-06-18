
// Includes
#include "gbot_common.h"
#include "gbot_data.h"
#include "gbot_interface.h"

// Delay for the specified time in ms and update sensor values
void gbot_DelayAndUpdateSensors(uint16_t time_delay_ms)
{
  uint8_t temp;
  volatile uint8_t *sensors = gbot_sensors.sensors;
  volatile uint8_t *sensors_in = gbot_sensors.in;

  gbot_timer.is_on = 1;
  gbot_timer.count = time_delay_ms;
  while(gbot_timer.is_on)
  {
    if(!gbot_sensors.flag)
    {
      for(temp = 0; temp < Sen6Size; temp++)
      	sensors[temp] = sensors_in[temp];

      // Update running totals of distance and angle
      gbot_motion.distance += (int)((sensors[SenDist1] << 8) | sensors[SenDist0]);
      gbot_motion.angle += (int)((sensors[SenAng1] << 8) | sensors[SenAng0]);

      gbot_SendByte(CmdSensors);
      gbot_SendByte(6);
      gbot_sensors.index = 0;
      gbot_sensors.flag = 1;
    }
  }
}
