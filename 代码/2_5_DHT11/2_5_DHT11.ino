// 需要以下 Arduino 库：
// - DHT 传感器库：https://github.com/adafruit/DHT-sensor-library
// - Adafruit 统一传感器库：https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 2    // 连接到 DHT 传感器的数字引脚
// Feather HUZZAH ESP8266 注意：使用引脚 3, 4, 5, 12, 13 或 14 --
// 引脚 15 也可以使用，但在上传程序时必须断开 DHT 连接。

// 取消注释你正在使用的传感器类型！
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)


// 将传感器的引脚 1（左边的）连接到 +5V
// 注意：如果使用 3.3V 逻辑电平的板子（如 Arduino Due），将引脚 1 连接到 3.3V 而不是 5V！
// 将传感器的引脚 2 连接到 DHTPIN
// 将传感器的引脚 3（右边的）连接到 GND（如果传感器有 3 个引脚）
// 将传感器的引脚 4（右边的）连接到 GND，并且引脚 3 空置（如果传感器有 4 个引脚）
// 将一个 10K 电阻从传感器的引脚 2（数据）连接到引脚 1（电源）


// 初始化 DHT 传感器。
// 注意：旧版本的库有一个可选的第三参数来调整较快处理器的时序。
// 现在不再需要这个参数，因为当前的 DHT 读取算法会自适应较快的处理器。
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // 检查是否有读取失败并提前退出（以便重试）
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
