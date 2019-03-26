

![Underwater Vehicle](https://images.gitee.com/uploads/images/2019/0222/201120_1db060f5_2330851.png "控制中心")


# 1.目录说明

**software:【相关软件设计】**
```c
   └──Camera 【OV2640例程】
   ├──RT-Thread 【RTT示例】
   ├──rt-thread-master
        └──bsp
            └──stm32f40x 【控制中心】 详细目录说明**

```			

| 目录组 | 描述 |
| -- | -- |
|Kernel| 它用于存放RT-Thread内核源文件 |
|User| 它用于存放用户应用文件 |
|Applications| 它用于存放外设应用程序 |
|Drivers|  它用于存放相关外设驱动 |
|STM32_StdPeriph| 它用于存放STM32固件库文件 |
|cpu|  它用于存放内核相关文件 |
|Fliesystem| 它用于存放虚拟文件系统 |
|DeviceDrivers|  它用于存放RT-Thread驱动 |
|finsh| 它用于存放RT-Thread Finsh组件 |
|libc| 它用于存放RT-Thread 相关文件 |
|Easylogger| 它用于存放RT-Thread Easylogger组件 |
|EasyFlash| 它用于存放RT-Thread EasyFlash |
|Utilities| 它用于存放相关工具与滤波算法 |


# 2.软件架构
```
+——RT-Thread
|    └──Kernel 【RT-Thread内核初始化】                  
|    ├── Normal Peripherals Init 【普通外设初始化】
|    ├── System self-check 【系统自检:检测是否所有外设初始化完成】 
|           └── Read Gyroscope data 【读取JY901 九轴数据】 
|           ├── Detection input devices 【检测输入设别】 
|    └──...... 
```






