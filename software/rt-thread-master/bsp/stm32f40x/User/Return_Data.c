/*
 * Return_Data.c
 *
 *  Created on: 2019��4��20��
 *      Author: zengwangfa
 *      Notes:  �������ݰ� Return Data
 */

#include "Return_Data.h"
#include "sensor.h"
#include <rtthread.h>
#include "uart.h"
SensorType Sensor;//����������
uint8 Return_Data[18] = {0};
uint8 hint;		//��ʾ�ַ�

/**
  * @brief  get_decimal(�õ�����������ͷ��λС����100��)
  * @param  ���������� data
  * @retval ͷ��λС����100��
  * @notice 
  */
uint8 get_decimal(float data) //�õ������� ��2λС��λ
{
		return (data - (int)data)*100;
}

/**
  * @brief  Convert_Return_Computer_Data(ת��������λ�������ݰ�)
  * @param  None
  * @retval None
  * @notice 
  */
void Convert_Return_Computer_Data(void) //������λ������ ת��
{
		Return_Data[0] = (int)Sensor.Power_volatge; //������
		Return_Data[1] = get_decimal(Sensor.Power_volatge);//С����100��
	
		Return_Data[2] = (int)Sensor.MS5837.Temperature; //������
		Return_Data[3] = get_decimal(Sensor.MS5837.Temperature);//С����100��	
		
		Return_Data[4] = (int)Sensor.CPU.Temperature; //������
		Return_Data[5] = get_decimal(Sensor.CPU.Temperature) ;//С����100��
	
		Return_Data[6] = Sensor.MS5837.Depth; //��8λ
		Return_Data[7] = Sensor.MS5837.Depth << 8 ;//��8λ
		Return_Data[8] = Sensor.MS5837.Depth << 16; //��8λ
	
		Return_Data[9] = (int)Sensor.JY901.Euler.Yaw; //������
		Return_Data[10] = get_decimal(Sensor.JY901.Euler.Yaw); //С����100��
	
		Return_Data[11] = (int)Sensor.JY901.Euler.Pitch ;//С����100��
		Return_Data[12] = get_decimal(Sensor.JY901.Euler.Pitch)  ;//С����100��	
	
		Return_Data[13] = (int)Sensor.JY901.Euler.Roll; //������
		Return_Data[14] = get_decimal(Sensor.JY901.Euler.Roll); //С����100��
		
		Return_Data[15] = Sensor.JY901.Speed.x; 
		Return_Data[16] = hint;//С����100��

}

/**
  * @brief  Calculate_Check_Byte(����õ����У��λ)
  * @param  ��ʼ��ͷ*begin_buff�����ݰ�*buff�����ݰ�����len
  * @retval None
  * @notice 
  */
uint8 Calculate_Check_Byte(uint8 *begin_buff,uint8 *buff,uint8 len)
{
		uint8 Check_Byte = 0;
		uint8 i = 0;
		for(i = 0;i < 3;i++){
				Check_Byte += begin_buff[i];
		}
		for(i = 0;i < len;i++){
			 	Check_Byte += buff[i];
		}
		return Check_Byte;
}

/**
	* @brief  Send_Buffer_Agreement(�������ݰ���Э��)
  * @param  ��ʼ��ͷ*begin_buff�����ݰ�*buff�����ݰ�����len
  * @retval None
  * @notice 
  */
void Send_Buffer_Agreement(uint8 *begin_buff,uint8 *buff,uint8 len)
{
		uint8 Check_Byte = Calculate_Check_Byte(begin_buff ,buff ,len);
		
		begin_buff[2] = len; //����λ
		rt_device_write(control_uart_device,0,begin_buff, 3);    //���Ͱ�ͷ
		rt_device_write(control_uart_device,0,buff, len);    		 //�������ݳ���
		rt_device_write(control_uart_device,0,&Check_Byte, 1);   //����У��λ
}




















