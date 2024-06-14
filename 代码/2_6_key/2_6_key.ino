int value = 0;
 
void setup()
 
{
 pinMode(6, INPUT_PULLUP);
 Serial.begin(115200);
}
 
void loop(){
 value = analogRead(A0);
 Serial.print("X:");
 Serial.print(value, DEC);
 value = analogRead(A1);
 Serial.print(" | Y:");
 Serial.print(value, DEC);
 value = digitalRead(6);
 Serial.print(" | Z: ");
 Serial.println(value, DEC);
 delay(100);
}