#ifndef BT_CONTROL_CONFIG_H
#define BT_CONTROL_CONFIG_H

/* ================= CAN IDs ================= */

/* ESP32 → VCU */
#define BT_CAN_ID_CMD        0x18FF4A01UL   /* Extended */
#define BT_CAN_ID_START      0x18FF4A02UL
#define BT_CAN_ID_EXIT       0x18FF4A03UL

/* ================= Timing ================= */

#define BT_ALIVE_TIMEOUT_MS  300U     /* must match ESP32 */
#define BT_TASK_PERIOD_MS   400U

/* ================= RPM LIMITS ================= */

#define BT_MAX_WHEEL_RPM     700U
#define BT_MAX_ROTOR_RPM     2600U

#define BT_RPM_SLEW_RATE     40U      /* RPM per 10 ms */

/* ================= Steering ================= */

#define BT_TURN_DIFF_PERCENT 30U      /* % RPM diff */

/* ================= Command Marker ================= */

#define BT_CMD_MAGIC         0xA1

#endif
