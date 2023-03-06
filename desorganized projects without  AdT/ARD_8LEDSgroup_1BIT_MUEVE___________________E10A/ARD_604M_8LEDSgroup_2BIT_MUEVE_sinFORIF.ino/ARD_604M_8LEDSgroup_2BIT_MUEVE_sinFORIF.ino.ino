
byte pin = 12;
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
   digitalWrite(pin+1, 1);
   digitalWrite(pin, 1); 
   //desventaja de : desde el inicio se muestran ambos leds en pantalla.
   delay(500);
   digitalWrite(pin+1, 0);
   digitalWrite(pin, 0); 
   //ENCENDER DOS LEDS
   
   pin=(pin==6)*12+(pin!=6)*(pin-1);
}
