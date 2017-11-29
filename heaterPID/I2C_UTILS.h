

#ifndef I2C_UTILS_H
#define	I2C_UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif


void I2C_Write_Byte_Single_Reg(unsigned char device, unsigned char info);

unsigned char I2C_Read_Byte_Single_Reg(unsigned char device);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_UTILS_H */

