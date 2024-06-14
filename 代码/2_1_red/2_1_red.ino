void setup() {
  pinMode(3,INPUT_PULLUP);//使用三号数字引脚探测DO
  Serial.begin(115200);  // 初始化串口，波特率为115200
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = digitalRead(3); //变量a接受数字值
  int b = analogRead(A0); //变量b接受模拟值
  Serial.println(a);
  Serial.println(b);
  delay(100);
}
