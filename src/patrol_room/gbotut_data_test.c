
// Includes
#include <CUnit/Basic.h>
#include "gbot_data.h"
#include "gbotut_data_test.h"


gbotut_DataInitTest() {
    CU_ASSERT(gbot_sensors.flag == 0)
    CU_ASSERT(gbot_sensors.index == 0)
    CU_ASSERT(gbot_motion.distance == 0)
    CU_ASSERT(gbot_motion.angle == 0)
    CU_ASSERT(gbot_timer.is_on == 0)
    CU_ASSERT(gbot_timer.count == 0)
}
