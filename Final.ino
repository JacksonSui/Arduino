/*科协复试作品Arduino源代码 作者：水贾鑫*/
#include<LiquidCrystal.h>
#define Button1 A0
#define Button2 A1
#define Button3 A2
LiquidCrystal lcd(4,3,5,7,6,8);
const int Rled=2;
const int Yled=10;
const int Gled=9;
const int sensor=11;
const int fmq=12;
int value,value1;
int a;
int times=1;
int b1,b2,b3;
int maxi=4;
int middle;

void setup()
{
  pinMode(Rled,OUTPUT);
  pinMode(Yled,OUTPUT);
  pinMode(Gled,OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(fmq,OUTPUT);
  pinMode(Button1,INPUT_PULLUP);
  pinMode(Button2,INPUT_PULLUP);
  pinMode(Button3,INPUT_PULLUP);
  lcd.begin(16,2);
  lcd.print("Welcome");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Designed");
  delay(500);
  lcd.setCursor(2,1);
  lcd.print("by Shui Jiaxin");
  delay(1500);
  tone(fmq,523,200);
  delay(210);
  tone(fmq,587,200);
  delay(210);
  tone(fmq,659,200);
  delay(210);
  tone(fmq,698,200);
  delay(210);
  tone(fmq,784,200);
  delay(210);
  tone(fmq,880,200);
  delay(210);
  tone(fmq,988,200);
  delay(210);
  lcd.clear();
  lcd.print("Please choose a");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("mode.");
  delay(1000);
  lcd.clear();
  reader();
  choose();
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Number:");
  while(1){
  middle=maxi/2;  
  if(times==1)
    {
      value=digitalRead(sensor);
      delay(500);
      value1=digitalRead(sensor);
      delay(500);
    }
 if(times>1)
   {
     value=value1;
     delay(500);
     value1=digitalRead(sensor);
     delay(500);
   }
 if(value==0&&value1==1)
   {
     a++;
     lcd.setCursor(9,1);
     lcd.print(a);
     if(a<=middle)
     {
       digitalWrite(Gled,HIGH);
       tone(fmq,523);
       delay(200);
       digitalWrite(Gled,LOW);
       noTone(fmq);
     }
     if(a>middle&&a<maxi)
      {
       digitalWrite(Yled,HIGH);
       tone(fmq,1046);
       delay(300);
       digitalWrite(Yled,LOW);
       noTone(fmq);
      }
     if(a==maxi)
     {
       lcd.setCursor(0,0);
       lcd.print("FULL!!!!!!!!!");
       digitalWrite(Rled,HIGH);
       tone(fmq,1046,5000);
       delay(3000);
       lcd.clear();
       lcd.print("push the button2 to ");
       lcd.setCursor(0,1);
       lcd.print("quit.");
       reader();
       while(b2==1)
         reader();
       digitalWrite(Rled,LOW);
       delay(200);
       a=0;
       reader();
       choose();
       break;
     }  
    }
 lcd.setCursor(14,1);
 lcd.print(value);
 lcd.print(value1);
 lcd.setCursor(0,0);
 if(value1==1)
   lcd.print("counting...");
 if(value==1&&value1==0)
  lcd.print("next            ");
  lcd.setCursor(9,1);
  lcd.print(a);
  times++;
  delay(400);
  }
}
void setting()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("push the button2");
  delay(900);
  lcd.setCursor(0,1);
  lcd.print("to quit,the butt");
  delay(900);
  lcd.setCursor(0,0);
  lcd.print("on3 to increase    ");
  delay(900);
  lcd.setCursor(0,1);
  lcd.print("the maximum and ");
  delay(900);
  lcd.setCursor(0,0);
  lcd.print("the button1 to d");
  delay(900);
  lcd.setCursor(0,1);
  lcd.print("ecrease it.             ");
  delay(900);
  reader();
  change();
}

void reader()
{
  b1=digitalRead(Button1);
  b2=digitalRead(Button2);
  b3=digitalRead(Button3);
}

void choose()
{
 lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("1.Setting");
  lcd.setCursor(0,1);
  lcd.print("2.Begin counting");
  reader();
  while(b1==1&&b2==1)
    {
      reader();
      if(b2==0)
        break;
      if(b1==0){
        setting();
        break;
    }
  }
}

void change()
{
  while(b2==1)
    {
      lcd.clear();
      lcd.print("maximum:");
      delay(100); 
      reader();
      if(b3==0)
        maxi++;
       else if(b1==0)
         maxi--;
       else if(maxi<1)
       {
         lcd.clear();
         lcd.print("the maximum can'");
         delay(600);
         lcd.setCursor(0,1);
         lcd.print("t be a minus.");
         delay(1000);
         lcd.clear();
         lcd.print("Please try again.");
         delay(500);
         maxi=1;
         change();
       }
       else;
       lcd.setCursor(10,0);
       lcd.print(maxi);
       delay(150);
    }

}

