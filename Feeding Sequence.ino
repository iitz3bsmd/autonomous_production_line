
#include <Servo.h>
Servo s_vertical ;
Servo s_Horizontal ;
#define IR 3 
int Parts_count=0;
int s_vertical_angle=180;        ///=180;
int s_Horizontal_angle=0;    ///=100;
int conveyor_check=0;
int feeding_check = 0;

void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR,INPUT);
  s_vertical.attach(5);
  s_vertical.write(180);
  delay(1500);
  s_vertical.detach();
  s_vertical.detach();
  s_Horizontal.attach(11);
  s_Horizontal.write(0);
  delay(1500);
  //s_Horizontal.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(IR)){
      feeding();
      Serial.print("Parts Count:");
      Serial.println(Parts_count);
    }
    //Serial.println(Parts_count );

}

void feeding(){

 while(Parts_count % 3 == 0 && Parts_count!=0) {
       s_vertical.attach(5);
      for(s_vertical_angle;s_vertical_angle<180;s_vertical_angle++){ 
      s_vertical.write(s_vertical_angle);
      delay(15);
  }  
      s_vertical.detach();
  if(Parts_count==3){
      s_Horizontal.attach(11);
      Serial.println("horizontaolllllllllll        1");   
  /*for(s_Horizontal_angle=0;s_Horizontal_angle<60;s_Horizontal_angle++){       
      s_vertical.write(s_Horizontal_angle);
      delay(15);
  }  
    for(s_Horizontal_angle=60;s_Horizontal_angle>30;s_Horizontal_angle--){    
      s_vertical.write(s_Horizontal_angle);
      delay(15);      
  }*/  
       s_Horizontal.write(60);
       delay(1000);
      s_Horizontal.write(30);
       delay(1000);
       s_Horizontal.detach();  
    }

    
    if(Parts_count==6){
       s_Horizontal.attach(11);
       Serial.println("horizontaolllllllllll        2");  
 /* for(s_Horizontal_angle;s_Horizontal_angle<120;s_Horizontal_angle++){    
      s_vertical.write(s_Horizontal_angle);
      delay(15);
  }
  for(s_Horizontal_angle;s_Horizontal_angle>0;s_Horizontal_angle--){    
      s_vertical.write(s_Horizontal_angle);
      delay(15);      
  }*/
      s_Horizontal.write(120);
      delay(1000);
      s_Horizontal.write(0);
      delay(1000);
       s_Horizontal.detach(); 
     }
     break;
        }
  for(s_vertical_angle;s_vertical_angle>0;s_vertical_angle--){  
      s_vertical.attach(5);  
      delay(20); 
    if(!digitalRead(IR)){
        Parts_count++;
        break;
    }
      s_vertical.write(s_vertical_angle);
      Serial.print("verical pos:");
      Serial.println(s_vertical_angle);    
  }
  s_vertical.detach();
}

