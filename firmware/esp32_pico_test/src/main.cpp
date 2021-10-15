
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

//u8g2库
U8G2_SSD1306_128X80_NONAME_F_HW_I2C u8g2(U8G2_R1, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 22, /* data=*/21);

//IO口，做输出
int allio[] = {0,2,5,12,4,13,14,15,27,32,33,9,10,18,19,23,25,26};
//I口，输入
int alli[] = {34,35,39,38,37,36};
//输出值
int value = 1;
//输出值反转计数标志
int time_flag = 0;

void setup(void)
{
    //u8g2库
    u8g2.begin();
    u8g2.enableUTF8Print(); 
    //IO口，做输出
    for(int i = 0; i < sizeof(allio)/sizeof(allio[0]); i++)
    {
        pinMode(allio[i], OUTPUT);
    } 
    //I口，输入
    for(int i = 0; i < sizeof(alli)/sizeof(alli[0]); i++)
    {
        pinMode(alli[i], INPUT);
    }
    //u8g2库设置
    u8g2.setFont(u8g2_font_wqy12_t_gb2312);
    u8g2.setFontDirection(0);
}

void loop(void)
{
    //清除缓存
    u8g2.clearBuffer();

    //显示标题
    u8g2.setCursor(0, 10);
    u8g2.print("测试焊接 -fzxhub"); 

    //计数
    time_flag++;
    if(time_flag >= 10) 
    {
        value = !value; 
        time_flag = 0;
    }

    //输出
    for(int i = 0; i < sizeof(allio)/sizeof(alli[0]); i++)
    {
        digitalWrite(allio[i],value);
    }
    if(value) 
    {
        u8g2.setCursor(0, 25);
        u8g2.print("IO: 3.3V");
    }
    else
    {
        u8g2.setCursor(0, 25);
        u8g2.print("IO: 0.0V");
    }

    //输出采集
    for(int i = 0; i < sizeof(alli)/sizeof(alli[0]); i = i+2)
    {
        u8g2.setCursor(0, i/2*15+40);
        u8g2.print(String(alli[i]) + ": " + (analogRead(alli[i])/4096.0*3.3) + "V" + "  " + String(alli[i+1]) + ": " + (analogRead(alli[i+1])/4096.0*3.3) + "V");
    }
    
    //显示
    u8g2.sendBuffer();
    
    delay(10);
}

