#ifndef VCU_SENSORS_H
#define VCU_SENSORS_H

//#include <stdint.h>

/* =========================================================
 *  GLOBAL CURRENT VALUES (AMPS)
 * ========================================================= */
extern float G_Current_1_A;
extern float G_Current_2_A;
extern float G_Current_3_A;

/* =========================================================
 *  FUNCTIONS
 * ========================================================= */
void VCU_Sensors_Init(void);
void VCU_Sensors_10ms(void);    // Called every 10ms

#endif /* VCU_SENSORS_H */
