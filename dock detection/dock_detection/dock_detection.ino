#include "TimerOne.h"
#include <SharpIR.h> 

SharpIR sharp1(A0, 25, 93, 20150);
SharpIR sharp2(A1, 25, 93, 20150);
SharpIR sharp3(A2, 25, 93, 20150);
SharpIR sharp4(A3, 25, 93, 20150);
SharpIR sharp5(A4, 25, 93, 20150);
SharpIR sharp6(A5, 25, 93, 20150);
int dis1=1000;
int dis2=1000;
int dis3=1000;
int dis4=1000;
//int dis5=1000;
//int dis6=1000;

int limit1 = 38;
int limit2 = 38;
int limit3 = 38;
int limit4 =42 ;
int flag = 0;
unsigned long time;
void setup()
{
  Serial.begin(9600);
  //Timer1.initialize(10000);    //note to rushat: 500000 gives a value every 0.5 seconds ; 1000000 gives a value every 1 second;
}
 
void loop()
{
   int dis1=sharp1.distance();
  dis1= ((dis1+5.5287)/1.1864);
  int dis2=sharp2.distance();
  dis2= ((dis2+5.5287)/1.164);
  int dis3=sharp3.distance();
  dis3= ((dis3+5.5287)/1.1064);
  int dis4=sharp4.distance();
  dis4= ((dis4+5.5287)/1.1064);
  if(dis1<=10)
  {
    dis1 = 80;
  }
  if(dis2<=10)
  {
    dis2 = 80;
  }
  if(dis3<=10)
  {
    dis3 = 80;
  }
  if(dis4<=10)
  {
    dis4 = 80;
  }
  dis1= constrain(dis1,10,80);
  dis2= constrain(dis2,10,80);
  dis3= constrain(dis3,10,80);
  dis4= constrain(dis4,10,80);

    
  
  //int dis5=sharp5.distance();
  //dis5= ((dis5+5.5287)/1.1864);
  //int dis6=sharp6.distance();
  //dis6= ((dis6+5.5287)/1.1864);
  flag=0;
  if(dis1<limit1 || dis2<limit2 || dis3<limit3 || dis4<limit4)
  {
    delay(100);
    if(dis1<limit1 || dis2<limit2 || dis3<limit3 || dis4<limit4){
        flag = 1;
        }
    else
        {
        flag = 0; 
        }
  }
  else
  {
    flag = 0;
  }
//  
//  Serial.print("dis1 \t");
//  Serial.print(dis1);
//  Serial.print("\t dis2\t");
//  Serial.print(dis2);
//  Serial.print("\t dis3\t");
//  Serial.print(dis3);  
//  Serial.print("\t dis4\t");
//  Serial.print(dis4);
//  Serial.print("\tflag:\t");
  Serial.println(flag);
  

}
 
//void loop()
//{
// Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
//}
