
byte pin=10;
void setup() {
   for(byte i=6;i<=13;i++){pinMode(i,OUTPUT);}
   pinMode(3,INPUT);
   pinMode(2,INPUT); 
}
void loop() {
   digitalWrite(pin,HIGH);
   while(digitalRead(3)==HIGH && digitalRead(2)==HIGH){delay(100);}
   if(digitalRead(3)==LOW){
      while(digitalRead(3)==LOW){delay(100);}
      digitalWrite(pin,LOW);  //apago ese led, y luego , segun el pulsador que presione pin-- para que se prenda el next led.
      if(pin>6)
         pin--; 
   }
   if(digitalRead(2)==LOW){
      while(digitalRead(2)==LOW){delay(100);}
      digitalWrite(pin,LOW);
      if(pin<13)
         pin++; 
   }
}
