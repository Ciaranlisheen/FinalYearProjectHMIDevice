
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/drivers/PIN.h>
#include <ti/drivers/SPI.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Watchdog.h>

/* Board Header files */
#include "Board.h"

#define TASKSTACKSIZE   1024

Task_Struct task0Struct;
Char task0Stack[TASKSTACKSIZE];

/* Pin driver handle */
static PIN_Handle ledPinHandle;
static PIN_State ledPinState;

/*
 * Application LED pin configuration table:
 *   - All LEDs board LEDs are off.
 */
PIN_Config pinTable[] =
{
    Board_LED0 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    Board_LED1 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};


void delay_s(int dly) { //delay seconds
    while (dly > 0) {
        __delay_cycles(48000000);
        dly--;}}
void delay_ms(int dly) {//delay milliseconds
    while (dly > 0) {
        __delay_cycles(48000);
        dly--; }}


Char myTaskStack[1024];
Task_Struct myTaskStruct;


Void SPIFxn(UArg arg0, UArg arg1) {
  System_printf("Start SPI task\n");

  SPI_Handle handle;
  SPI_Params spiParams;
  SPI_Transaction spiTransaction;
  uint8_t transmitBuffer[3];
  uint8_t recieveBuffer[3];
  uint8_t devid;
  bool ret;

  SPI_Params_init(&spiParams); //initialise spi params object
  spiParams.transferMode = SPI_MODE_BLOCKING; //block thread until transaction complete
  spiParams.transferTimeout = SPI_WAIT_FOREVER;//wait forever
  spiParams.frameFormat = SPI_POL1_PHA1;//clock polarity 1 phase 1
  spiParams.transferCallbackFxn = NULL; //no callback
  spiParams.mode = SPI_MASTER; //master mode
  spiParams.bitRate = 400000; //400MHz
  spiParams.dataSize = 8; //data size
  handle = SPI_open(0, &spiParams);//open spiHandle

  transmitBuffer[0] = 0xAD;//write to power control
  transmitBuffer[1] = 0x08;//turn device on

  spiTransaction.count = 2;
  spiTransaction.txBuf = transmitBuffer;
  spiTransaction.rxBuf = recieveBuffer;

  PIN_setOutputValue(ledPinHandle, Board_LED1, 0); //turn chip select low
  delay_ms(1);
  ret = SPI_transfer(handle, &spiTransaction); //transfer data (device ID)
  PIN_setOutputValue(ledPinHandle, Board_LED1, 1); //set chip select high
  if (!ret) {
      System_printf("Unsuccessful SPI transfer");
  }
  delay_s(3);
  transmitBuffer[0] = 0x80;//read from address 0x00 with read bit 0x80 (devID)
  transmitBuffer[1] = 0x00;//fake request for interchange


  PIN_setOutputValue(ledPinHandle, Board_LED1, 0); //turn chip select low
  delay_ms(1);
  ret = SPI_transfer(handle, &spiTransaction); //transfer data (device ID)
  devid = recieveBuffer[1];
  PIN_setOutputValue(ledPinHandle, Board_LED1, 1); //set chip select high

  if (!ret) {
        System_printf("Unsuccessful SPI transfer");
    }
  delay_s(1);


while(true){
    if(devid == 0b11100101 ){
        spiTransaction.count = 3;

        transmitBuffer[0] = 0xD0;//read from address 0x00 with read bit 0x80 (devID)
        transmitBuffer[1] = 0xD1;
        transmitBuffer[2] = 0x00;//fake request for interchange

        PIN_setOutputValue(ledPinHandle, Board_LED1, 0); //turn chip select low
        delay_ms(1);
        ret = SPI_transfer(handle, &spiTransaction); //transfer data (device ID)
        PIN_setOutputValue(ledPinHandle, Board_LED1, 1); //set chip select high
        delay_ms(20);

        transmitBuffer[0] = 0xD2;//read from address 0x00 with read bit 0x80 (devID)
        transmitBuffer[1] = 0xD3;
        transmitBuffer[2] = 0x00;//fake request for interchange

        PIN_setOutputValue(ledPinHandle, Board_LED1, 0); //turn chip select low
        delay_ms(1);
        ret = SPI_transfer(handle, &spiTransaction); //transfer data (device ID)
        PIN_setOutputValue(ledPinHandle, Board_LED1, 1); //set chip select high
        delay_ms(20);
        delay_ms(20);

        transmitBuffer[0] = 0xD4;//read from address 0x00 with read bit 0x80 (devID)
        transmitBuffer[1] = 0xD5;
        transmitBuffer[2] = 0x00;//fake request for interchange

        PIN_setOutputValue(ledPinHandle, Board_LED1, 0); //turn chip select low
        delay_ms(1);
        ret = SPI_transfer(handle, &spiTransaction); //transfer data (device ID)
        PIN_setOutputValue(ledPinHandle, Board_LED1, 1); //set chip select high
        delay_ms(20);
        delay_ms(20);
    }
}
}

// ======== SETUP ========
Int main(){

  System_printf("Start Setup\n");

  Board_initGeneral();
  Board_initSPI();

  ledPinHandle = PIN_open(&ledPinState, pinTable);
      if(!ledPinHandle)
      {
          System_abort("Error initializing board LED pins\n");
      }

  /* Configure task. */
  Task_Params taskParams;
  Task_Params_init(&taskParams);
  taskParams.stack = myTaskStack;
  taskParams.stackSize = sizeof(myTaskStack);
  Task_construct(&myTaskStruct, SPIFxn, &taskParams, NULL);

  PIN_setOutputValue(ledPinHandle, Board_LED1, 1);

  System_printf("End Setup\n");

  BIOS_start();

  return (0);
}
