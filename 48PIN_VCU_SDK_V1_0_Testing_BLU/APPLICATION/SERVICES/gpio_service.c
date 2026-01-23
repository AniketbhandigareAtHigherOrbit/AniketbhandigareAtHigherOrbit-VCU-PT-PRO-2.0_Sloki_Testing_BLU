#include "databank.h"
#include "vehicle_state.h"

/* =========================================================
 *  GPIO SERVICE
 *  Reads all GPIO inputs continuously
 *  Updates global vehicle state variables
 * ========================================================= */
void GPIO_Service_Run(void)
{
    VS_KillSwitch       = Get_GPInput_State(B2_GPINUPUT1_E);
    VS_TurnLeft         = Get_GPInput_State(C2_GPINUPUT2_E);
    VS_TurnRight        = Get_GPInput_State(D2_GPINUPUT3_E);

    /* Direction toggle switch (level-based) */
    VS_Direction_Request = Get_GPInput_State(E2_GPINUPUT4_E);

    VS_RotorEnable      = Get_GPInput_State(F2_GPINUPUT5_E);

    VS_GPIO6 = Get_GPInput_State(B3_GPINUPUT6_E);
    VS_GPIO7 = Get_GPInput_State(C3_GPINUPUT7_E);
    VS_GPIO8 = Get_GPInput_State(D3_GPINUPUT8_E);
}
