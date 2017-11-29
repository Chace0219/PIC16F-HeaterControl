#include <xc.h>
#include "I2C_UTILS.h"
#include "mcc_generated_files/i2c1.h"

// 
#define I2C_WRITE   0b11111110
#define I2C_READ    0b00000001

// 
void I2C_Write_Byte_Single_Reg(unsigned char device, unsigned char info)
{
    char temp[2];
    temp[0] = info;
    I2C1_MESSAGE_STATUS status = I2C1_MESSAGE_PENDING;
    I2C1_MasterWrite( temp,
                            1,
                            device,
                            &status);

    // wait for the message to be sent or status has changed.
    while(status == I2C1_MESSAGE_PENDING);

}

unsigned char I2C_Read_Byte_Single_Reg(unsigned char device)
{
    I2C1_MESSAGE_STATUS status;
    status = I2C1_MESSAGE_PENDING;
    unsigned char b = 0;
    I2C1_MasterRead(&b,
                            1,
                            device,
                            &status);

    // wait for the message to be sent or status has changed.
    while(status == I2C1_MESSAGE_PENDING);

    if (status == I2C1_MESSAGE_COMPLETE)
        return b;
    else 
        return 0;
}



