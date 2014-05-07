
// Includes
#include "gbot_common.h"
#include "gbot_data.h"

// Delay for the specified time in ms and update sensor values
void gbot_DelayAndUpdateSensors(uint16_t time_delay_ms)
{
  uint8_t temp;

  timer_on = 1;
  timer_cnt = time_delay_ms;
  while(timer_on)
  {
    if(!sensors_flag)
    {
      for(temp = 0; temp < Sen6Size; temp++)
        sensors[temp] = sensors_in[temp];

      // Update running totals of distance and angle
      distance += (int)((sensors[SenDist1] << 8) | sensors[SenDist0]);
      angle += (int)((sensors[SenAng1] << 8) | sensors[SenAng0]);

      byteTx(CmdSensors);
      byteTx(6);
      sensors_index = 0;
      sensors_flag = 1;
    }
  }
}
