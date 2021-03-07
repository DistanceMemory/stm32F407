#ifndef _MS5611_H_
#define _MS5611_H_	 
#include "sys.h"
/***********�궨��****************/
//����������IIC�����еĴӵ�ַ,����CSB���Ų�ͬ�޸�

//#define MS561101BA_Device_Address  0xec   //CBR=1 0x76 I2C address when CSB is connected to HIGH (VCC) 
#define  MS561101BA_Device_Address   0xee   //CBR=0  0x77 I2C address when CSB is connected to LOW (GND)

// ����MS561101BA�ڲ��Ĵ�����ַ 

#define MS561101BA_D1             0x40  
#define MS561101BA_D2             0x50  
#define MS561101BA_RESET          0x1E //��λָ��
#define CMD_ADC_READ              0x00
// D1 and D2 result size (bytes)  
#define MS561101BA_D1D2_SIZE      3
// OSR (Over Sampling Ratio) constants

#define MS561101BA_OSR_256        0x00  
#define MS561101BA_OSR_512        0x02  
#define MS561101BA_OSR_1024       0x04  
#define MS561101BA_OSR_2048       0x06  
#define MS561101BA_OSR_4096       0x08  
//#define  MS561101BA_D1_OSR_256 0x40   
//#define  MS561101BA_D1_OSR_512 0x42   
//#define  MS561101BA_D1_OSR_1024 0x44   
//#define  MS561101BA_D1_OSR_2048 0x46   
#define  MS561101BA_Press_D1_OSR_4096   0x48   //12λ���ȣ�4096����ѹǿ�ɼ�
  
//#define  MS561101BA_D2_OSR_256 0x50   
//#define  MS561101BA_D2_OSR_512 0x52   
//#define  MS561101BA_D2_OSR_1024 0x54   
//#define  MS561101BA_D2_OSR_2048 0x56   
#define  MS561101BA_Temp_D2_OSR_4096   0x58  //12λ���ȣ�4096�����¶Ȳɼ�

#define MS561101BA_PROM_BASE_ADDR 0xA0 // by adding ints from 0 to 6 we can read all the prom configuration values. 
// C1 will be at 0xA2 and all the subsequent are multiples of 2 
//prom���������洢�Ļ���ַ����6����
#define MS561101BA_PROM_REG_COUNT  6 // number of registers in the PROM  
#define MS561101BA_PROM_REG_SIZE   2 // size in bytes of a prom registry.



/*��������----------------------------------------------------------------*/  
 void MS561101BA_Reset(void);  
 void MS561101BA_readPROM(void);  
 uint32_t MS561101BA_DO_CONVERSION(u8 command);  
 void MS561101BA_GetTemperature(u8 OSR_Temp);  
 void MS561101BA_GetPressure(u8 OSR_Pres);  
 void MS561101BA_Init(void);  
 void SampleANDExchange(void);  
void MS561101BA_data_transfer(void);
/*��������*--------------------------------------*/
extern uint16_t Cal_C[7];  //���ڴ��PROM�е�6������      
extern uint32_t D1_Pres,D2_Temp; // �������ѹ�����¶�  
extern float Pressure;             //�¶Ȳ�������ѹ  
extern float Temperature,Temperature2;//ʵ�ʺͲο��¶�֮��Ĳ���,ʵ���¶�,�м�ֵ  
extern double dT,OFF,SENS;  //ʵ���¶ȵ���,ʵ���¶�������  
extern float Aux,OFF2,SENS2;  //�¶�У��ֵ  
extern uint32_t ex_Pressure;           //���ڶ���ת��ֵ  
extern uint8_t  exchange_num[8]; 

void  get_ms5611_data(void);
#endif