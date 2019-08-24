#include <ResistiveTouchController.hpp>

extern "C"
{
#include "stm32f429i_discovery_ts.h"

    uint32_t LCD_GetXSize();
    uint32_t LCD_GetYSize();
}

using namespace touchgfx;

void ResistiveTouchController::init()
{
    BSP_TS_Init(LCD_GetXSize(), LCD_GetYSize());
}

bool ResistiveTouchController::sampleTouch(int32_t& x, int32_t& y)
{
    TS_StateTypeDef state;
    BSP_TS_GetState(&state);
    if (state.TouchDetected)
    {
        x = state.X;
        y = state.Y;
        return true;
    }
    return false;
}
