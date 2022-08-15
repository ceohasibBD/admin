
#include <LiquidCrystal.h>
LiquidCrystal lcd (2, 3, 4, 5, 6, 7) ;
int trigpin = 8 ; 
int echopin = 9 ; 
int buzzer = 11 ; 
float time ; 
float cm ; 
float inch ; 

void setup ( )
  { lcd.begin (20, 4) ;
    pinMode (trigpin, OUTPUT) ; 
    pinMode (echopin, INPUT) ; 
    pinMode (buzzer, OUTPUT) ; }

void loop ( ) 
  { digitalWrite (trigpin, LOW) ; 
    delay (2) ; 
    digitalWrite (trigpin, HIGH) ; 
    delayMicroseconds (10) ; 
    digitalWrite (trigpin, LOW ) ; 
    time = pulseIn(echopin, HIGH ) ; 
    cm = (time/2) / 40;
    inch = (time/2) / 92; 
    lcd.setCursor (2, 0) ; 
    lcd.print ("Obstacle Distance") ; 
    lcd.setCursor (0,1) ; 
    lcd.print (cm) ; 
    lcd.print ("cm") ;
    lcd.setCursor (12, 1) ; 
    lcd.print (inch) ; 
    lcd.print ("inch") ; 
    lcd.setCursor (0, 3) ; 
    lcd.print ("MUPI |IPCT| 2018-19") ; 
    
     if (cm<10) 
     { digitalWrite (buzzer, HIGH) ; 
       lcd.setCursor (2 , 2) ; 
       lcd.print ("Obstacle In Range") ; } 

    else 
   { digitalWrite (buzzer, LOW) ; }           
     delay (1000) ; 
     lcd.clear ( ) ; }