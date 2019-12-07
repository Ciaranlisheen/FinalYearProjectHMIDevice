
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/PIN.h>

#include "Board.h"

#define TASKSTACKSIZE   512
#define ADXL345_ADDRESS         0x86
#define MPU_ADDR                0x68
#define ADXL345_POWER_CTL       0x2D
#define MPU_POWER_CTL           0x6B
#define ADXL345_DATAX0          0x32


Task_Struct task0Struct;
Char task0Stack[TASKSTACKSIZE];


bool transferDone = false;

static void I2CFxn(UArg arg0, UArg arg1)
{
    I2C_Handle handle;
    I2C_Params params;
    I2C_Transaction i2cTrans;
    uint8_t rxBuffer[1];            // Receive buffer
    uint8_t txBuffer[1];            // Transmit buffer

    I2C_Params_init(&params);
    params.transferMode = I2C_MODE_BLOCKING; //thread waits for transaction
    params.bitRate = I2C_400kHz ; //400kHz

    txBuffer[0] = 0x75;//Get Device ID

    i2cTrans.writeCount   = 1; //one byte right (slave address is handled by I2C.H)
    i2cTrans.writeBuf     = txBuffer;
    i2cTrans.readCount    = 1;
    i2cTrans.readBuf      = rxBuffer;
    i2cTrans.slaveAddress = 0x69;//slave address when alt address pin is grounded

    handle = I2C_open(Board_I2C, &params);//open connection
    I2C_transfer(handle, &i2cTrans);//make transfer

    System_printf("testing %d \n", rxBuffer[0]);
    System_flush();
    I2C_close(handle);
}


int main(void)
{
    Task_Params taskParams;
    /* Call board init functions */
    Board_initGeneral();
    I2C_init();

    Task_Handle Task1;
    Task_Params_init(&taskParams);
    taskParams.arg0 = 1000000 / Clock_tickPeriod;
    taskParams.stackSize = 512;
    taskParams.stack = task0Stack;
    taskParams.priority = 3;
    Task1 = Task_create((Task_FuncPtr)I2CFxn, &taskParams, NULL);

    /* Start BIOS */
    BIOS_start();

    return (0);
}
