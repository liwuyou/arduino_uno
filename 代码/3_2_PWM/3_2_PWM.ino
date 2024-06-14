/**
 * 通过一个除数来分频给定的 PWM 引脚频率。
 *
 * 生成的频率等于基频除以给定的除数：
 *   – 基频：
 *      o 引脚 3、9、10 和 11 的基频是 31250 Hz。
 *      o 引脚 5 和 6 的基频是 62500 Hz。
 *   – 除数：
 *      o 引脚 5、6、9 和 10 可用的除数有：1、8、64、256 和 1024。
 *      o 引脚 3 和 11 可用的除数有：1、8、32、64、128、256 和 1024。
 *
 * PWM 频率成对关联。如果一对中的一个改变，另一个也会改变以匹配：
 *   – 引脚 5 和 6 在定时器0上成对
 *   – 引脚 9 和 10 在定时器1上成对
 *   – 引脚 3 和 11 在定时器2上成对
 *
 * 请注意，此函数会对其他使用定时器的内容产生副作用：
 *   – 改变引脚 3、5、6 或 11 可能会导致 delay() 和 millis() 函数停止工作。其他与定时相关的函数也可能受到影响。
 *   – 改变引脚 9 或 10 会导致 Servo 库无法正常工作。
 *
 * 感谢 Arduino 论坛的 macegr 提供的 PWM 频率除数文档。他的帖子可以在以下链接查看：
 *   http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1235060559/0#4
 */

void setup() {
// Set pin 6’s PWM frequency to 62500 Hz (62500/1 = 62500)
// Note that the base frequency for pins 5 and 6 is 62500 Hz
  setPwmFrequency(6, 1);
  analogWrite(6,125);
}

void loop() {
  // put your main code here, to run repeatedly:

}


void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
