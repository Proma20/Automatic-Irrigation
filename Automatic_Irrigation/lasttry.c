
         // LCD module connections
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
float value=0;
char value1[15];

void main() {
 TRISA.RA0=1;
 TRISC2_bit=0;
 TRISB = 0x00;
 TRISD = 0x00;
 portc=0x00;
 ADC_INIT();
 LCD_INIT();
 lcd_cmd(_lcd_cursor_off);
 lcd_cmd(_lcd_clear);
 lcd_out(1,1,"Automatic");
  lcd_out(2,1,"Irrigation");
 delay_ms(2000);
 lcd_cmd(_lcd_clear);
  lcd_out(1,1,"MOISTURE");
  PWM1_Init(5000);
  PWM1_Start();
  PWM1_Set_Duty(127);

  while(1)
  {       //PORTD =0x00;
          value= adc_read(0);
          value= value;
          floattostr(value,value1);
          lcd_chr(2,9,39);
          lcd_out(2,10,"c");
          lcd_out(2,1,value1);
          delay_ms(500);
          if(value>990)
          {

                   PORTD =0xff;
          }
          else
          {

                   PORTD =0x00;
          }

          // delay_ms(300);
  }
}