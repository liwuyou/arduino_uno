#include "NewPing.h"
 
#define TRIGGER_PIN  2   //引脚定义
#define ECHO_PIN     3
#define MAX_DISTANCE 90  //设置最大距离
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;
 
int iterations = 5;  //求平均的次数
void setup() {
  Serial.begin (115200);
}
 
void loop() {
  duration = sonar.ping_median(iterations);   //多次测量时间求平均值  
  distance = (duration / 2) * 0.0343;      //将测量的时间转换成距离 

  Serial.print("Distance = ");
  if (distance >= MAX_DISTANCE || distance <= 3) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
}
