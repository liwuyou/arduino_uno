#include <U8g2lib.h>                                       //u8g2库

#define SCL A5   //引脚定义，可替换为数字引脚
#define SDA A4
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,SCL,SDA); //配置构造函数      
int a=66;                                                  //定义变量a=66

void setup() 
{
    u8g2.begin();                                          //启动u8g2驱动程序
    u8g2.clearBuffer();                                    //清空显示屏缓存
}

void loop() 
{
    face();                                                //调用函数，显示图案
    delay(1000);                                           //持续一秒钟
    heart();                                               //调用函数，显示英文字母和图案
    delay(1000);                                           //持续一秒钟
    letter(a);                                             //调用函数，显示中文和变量
    delay(1000);                                           //持续一秒钟
}

void face()
{
    u8g2.clearBuffer();                                    //清空显示屏缓存
    
    u8g2.drawCircle(56,40,8,U8G2_DRAW_LOWER_LEFT);         //画四分之一圆，圆心坐标（56,44），半径8
    u8g2.drawCircle(56,40,8,U8G2_DRAW_LOWER_RIGHT);        //画四分之一圆
    u8g2.drawCircle(72,40,8,U8G2_DRAW_LOWER_LEFT);         //画四分之一圆
    u8g2.drawCircle(72,40,8,U8G2_DRAW_LOWER_RIGHT);        //画四分之一圆
    u8g2.drawCircle(56,41,8,U8G2_DRAW_LOWER_LEFT);         //加粗画四分之一圆
    u8g2.drawCircle(56,41,8,U8G2_DRAW_LOWER_RIGHT);        //加粗画四分之一圆
    u8g2.drawCircle(72,41,8,U8G2_DRAW_LOWER_LEFT);         //加粗画四分之一圆
    u8g2.drawCircle(72,41,8,U8G2_DRAW_LOWER_RIGHT);        //加粗画四分之一圆
    u8g2.drawLine(40,18,20,30);                            //画斜线，两端点坐标分别是（40，18）（20,30）
    u8g2.drawLine(88,18,108,30);                           //画斜线
    u8g2.drawLine(40,17,20,29);                            //加粗画斜线
    u8g2.drawLine(88,17,108,29);                           //加粗画斜线
    
    u8g2.sendBuffer();                                     //加载以上内容
}

  void heart()
{
    u8g2.clearBuffer();                                    //清空显示屏缓存
    
    u8g2.setFont(u8g2_font_open_iconic_human_2x_t);        // 设置字体
    u8g2.drawGlyph(58,30,66);                              // 画心，符号左下角坐标为（58,36），符号编号为66
    u8g2.setFont(u8g2_font_unifont_t_chinese2);            //设置字体
    u8g2.drawUTF8(58+20,30,"ZFY");                         //显示英文，左下角位置坐标为（78，30）
    u8g2.drawUTF8(58-14-16,30,"JHR");                      //显示英文，左下角位置坐标为（28，30）    
    
    u8g2.sendBuffer();                                     // 加载以上内容
}

  void letter(int a)
{   
    u8g2.clearBuffer();                                    //清空显示屏缓存
    
    //int8_t a=u8g2.getMaxCharHeight();                      //获取最大高度
    //int8_t b=u8g2.getMaxCharWidth();                       //获取最大宽度
    
    u8g2.setFont(u8g2_font_unifont_t_chinese2);            //设置字体
    u8g2.drawUTF8(20,17,"智能检测系统");                    //显示文字，左下角位置坐标为（20，17）
    u8g2.drawUTF8(50,34,"：");                             //显示:，左下角坐标为（50,34）
    u8g2.drawUTF8(0,34,"位移为:");
    u8g2.setCursor(64,34);                                 //设置将要打印变量的左下角坐标
    u8g2.drawUTF8(0,34,"位移为:");

    u8g2.print(a);                                         //打印变量a
     
    u8g2.sendBuffer();                                     // 加载以上内容
  }
