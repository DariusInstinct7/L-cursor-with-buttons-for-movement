
byte pin = 13;    //Definimos la variable pin
void setup (){
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(9,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(6,OUTPUT);
}
void loop() {
   digitalWrite(pin, 1);
   delay(500);
   digitalWrite(pin, 0);
   pin=(pin==6)*13+(pin!=6)*(pin-1);
}
