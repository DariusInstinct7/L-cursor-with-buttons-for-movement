
void setup(){
   Serial.begin(9600);
}
void loop(){
   float x = 1.589;
   Serial.println(x,0);
   Serial.println(x,1);
   Serial.println(x,2);
   Serial.println(x,3);
   Serial.println(x,4);
   while(1){} //DETENGO EL PROGRAMA.
}
