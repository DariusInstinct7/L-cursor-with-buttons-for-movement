void setup() {
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(9,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(7,OUTPUT);
}
void loop() {
  //El número SEIS se expresa en binario como 00000110, que no tiene ninguna relación con el valor que se necesita para visualizarlo.
   digitalWrite(13,0);
   digitalWrite(12,1);
   digitalWrite(11,0);
   digitalWrite(10,0);
   digitalWrite(9,0);
   digitalWrite(8,0);
   digitalWrite(7,0);
}
