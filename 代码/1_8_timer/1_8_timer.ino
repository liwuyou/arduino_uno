int toggle0, toggle1, toggle2;

void setup() {
  cli(); // 关闭全局中断
  
  // 设置定时器0为10kHz(100us)
  TCCR0A = 0; // 将整个TCCR0A寄存器设置为0
  TCCR0B = 0; // 将整个TCCR0B寄存器设置为0
  TCNT0 = 0; // 将计数器值初始化为0
  // 设置计数器为10kHz，即100us
  OCR0A = 24; // 比较匹配寄存器 = [16,000,000Hz /（预分频器 * 所需中断频率）] - 1
              // 比较匹配寄存器 = 24, 中断间隔 = 100us 即中断频率10kHz
  TCCR0A |= (1 << WGM01); // 打开CTC模式
  TCCR0B |= (1 << CS01) | (1 << CS00); // 设置CS01位为1，CS00位为1(64倍预分频)
  TIMSK0 |= (1 << OCIE0A); // 启用定时器比较中断

  // 设置定时器1为1kHz
  TCCR1A = 0; // 将整个TCCR1A寄存器设置为0
  TCCR1B = 0; // 将整个TCCR1B寄存器设置为0
  TCNT1 = 0; // 将计数器值初始化为0
  // 设置计数器为1kHz，即1ms
  OCR1A = 1999; // = (16*10^6)/(1000*8) - 1 (must be <65536)
  TCCR1B |= (1 << WGM12); // 打开CTC模式
  TCCR1B |= (1 << CS11); // 设置CS11位为1(8倍预分频)
  TIMSK1 |= (1 << OCIE1A); // 启用定时器比较中断

  // 设置定时器2为8kHz
  TCCR2A = 0; // 将整个TCCR2A寄存器设置为0
  TCCR2B = 0; // 将整个TCCR2B寄存器设置为0
  TCNT2 = 0; // 将计数器值初始化为0
  // 设置计数器为8kHz
  OCR2A = 249; // = (16*10^6) / (8000*8) - 1 (must be <256)
  TCCR2A |= (1 << WGM21); // 打开CTC模式
  TCCR2B |= (1 << CS21); // 设置CS21位为1(8倍预分频)
  TIMSK2 |= (1 << OCIE2A); // 启用定时器比较中断

  sei(); // 打开全局中断
}

// 中断0服务函数
ISR(TIMER0_COMPA_vect) { // timer0中断，产生频率为10kHz / 2 = 5kHz的脉冲波
  if (toggle0) {
    digitalWrite(8, HIGH);
    toggle0 = 0;
  } else {
    digitalWrite(8, LOW);
    toggle0 = 1;
  }
}

// 中断1服务函数
ISR(TIMER1_COMPA_vect) { // timer1中断，产生频率为2Hz / 2 = 1Hz的脉冲波
  if (toggle1 >= 500) {
    digitalWrite(13, HIGH);
  }
  if (toggle1 <= 500) {
    digitalWrite(13, LOW);
  }
  toggle1 += 1;
  if (toggle1 >= 1000) {
    toggle1 = 0;
  }
}

// 中断2服务函数
ISR(TIMER2_COMPA_vect) { // timer2中断，产生频率为8kHz / 2 = 4kHz的脉冲波
  if (toggle2) {
    digitalWrite(9, HIGH);
    toggle2 = 0;
  } else {
    digitalWrite(9, LOW);
    toggle2 = 1;
  }
}

// 主循环函数
void loop() {

}
