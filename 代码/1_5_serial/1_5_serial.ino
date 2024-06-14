void setup() {
  Serial.begin(9600);  // 初始化串口，波特率为9600
  Serial.setTimeout(5000);  // 设置读取操作的超时时间为5秒，可注释
  Serial.println("Enter a string (timeout 5 seconds):");  // 提示用户输入字符串
}

void loop() {
  // 检查是否有数据可读
  if (Serial.available() > 0) {
    String receivedString = Serial.readString();  // 读取串口缓冲区中的字符串
    Serial.print("You entered: ");
    Serial.println(receivedString);  // 打印接收到的字符串
  }
  delay(500);  // 延迟500毫秒
}
