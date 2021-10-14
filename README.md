# esp32_pico
这是一个使用esp32-pico-d4设计的迷你开发板

## 背景

这是根据[稚晖君的ESP32-PicoDK](https://github.com/peng-zhihui/ESP32-PicoDK)修改的esp32迷你开发板。

## 修改要点

1. 增加所有IO引出，由于板子非常mini，所以在背面设计表贴焊盘，需要使用这些特殊接口时，使用贴片2.54的插针引出后再使用即可。
2. 将CAN使用的插针改为VCC3.3V和GND管脚。然后将CANL和CANH在背面设计表贴焊盘引出，个人CAN使用较少，使用时贴片2.54的插针引出后再使用即可。
3. 修改两排插针之间间距为700mil，更加规范的间距，可以使用面包板等。

## 图片

![正面](image/positive.png)
![实物](image/1.jpg)


