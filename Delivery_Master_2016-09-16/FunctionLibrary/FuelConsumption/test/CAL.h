#ifndef CAL_H
#define CAL_H

/********************************* Includes **********************************/
#include "Platform_Types.h"

/**************************** Constants and Types ****************************/
typedef enum
{
    CAL_OK,
    CAL_NOK
} CAL_STATUS;

typedef enum
{
    TOTAL_FUEL_CONSUMPTION,
    TOTAL_FUEL_CONSUMPTION_TICKS
} calibration_parameter_id_t;

typedef struct
{
    uint16 Offset;
    uint8 Length;
} calibration_parameter_t;

/***************************** Exported Functions ****************************/
void CAL_Init(void);

void CAL_Refresh(void);

CAL_STATUS CAL_Read8(calibration_parameter_id_t u16ParameterId, uint8* value);
CAL_STATUS CAL_Read16(calibration_parameter_id_t u16ParameterId, uint16* value);
CAL_STATUS CAL_Read32(calibration_parameter_id_t u16ParameterId, uint32* value);

//Arbitrary length intefaces
CAL_STATUS CAL_Write(calibration_parameter_id_t CalId, uint8* pData, uint16 u16Length);
CAL_STATUS CAL_Read(calibration_parameter_id_t CalId, uint8* pData, uint16 u16Length);


//ODO storage interfaces
CAL_STATUS CAL_NoCacheWrite32(calibration_parameter_id_t u16ParameterId, uint32* value);
CAL_STATUS CAL_NoCacheRead32(calibration_parameter_id_t u16ParameterId, uint32* value);

#endif // CAL_H
