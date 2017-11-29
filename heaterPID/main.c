/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.1
        Device            :  PIC16F1829
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "LCD_I2C_PCF8574.h"
#include "I2C_UTILS.h"

#include <stdlib.h>
#include <string.h>
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    IO_RC0_SetHigh();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    /*
    __delay_ms(2000);
    
    // Display first Logo Screen
    LCD_Init();
    LCDclear();
    LCDsetCursor(0, 0);
    LCD_Write_Str("   PIC16F1829   ");
    LCDsetCursor(0, 1);
    LCD_Write_Str("Receiver Ver 1.0");
    __delay_ms(4000);
    LCDclear();

    // Display second Logo Screen
    LCDsetCursor(0, 0);
    LCD_Write_Str("  Developed By  ");
    LCDsetCursor(0, 1);
    LCD_Write_Str("Jinzhouyun201705");
    __delay_ms(4000);
    LCDclear();*/

    while (1)
    {
        
        //EPWM2_LoadDutyValue(25);
        
        // Add your application code
        uint16_t nTemp = 0;

        IO_RC0_SetLow();
        nTemp += SPI2_Exchange8bit(DUMMY_DATA);
        nTemp <<= 8;
        nTemp += SPI2_Exchange8bit(DUMMY_DATA);
        IO_RC0_SetHigh();
        if(((nTemp >> 2 ) & 0x01)==1)
        {
            nTemp = 0;
        }
        else
        {
            nTemp = nTemp >> 3;
            nTemp = 25 * nTemp;
        }
        
        char txt[20];
        itoa(txt, nTemp, 10);
        
        for(uint8_t idx = 0; idx < strlen(txt); idx++)
        {
            if(txt[idx] == '\0')
                break;
        }
        
        I2C_Write_Byte_Single_Reg(0x20, 0xFF);
        __delay_ms(1000);
        I2C_Write_Byte_Single_Reg(0x20, 0x00);
        __delay_ms(1000);
        
    }
}
/**
 End of File
*/