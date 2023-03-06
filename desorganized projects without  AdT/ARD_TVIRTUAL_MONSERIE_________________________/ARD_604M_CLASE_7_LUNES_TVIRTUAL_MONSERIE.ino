
void setup(){
   Serial.begin(9600);
}
void loop(){
   Serial.println(); //Cambio de línea
   int x = -32768;  //Máximo valor negativo
   Serial.print("El valor de la variable x es: ");
   Serial.println(x);
   x = x - 1;
   Serial.print("Se decrementa x y se produce el UnderFlow: ");
   Serial.println(x);
   x = 32767;   //Máximo valor positivo
   Serial.print("El valor de la variable x es: ");
   Serial.println(x);
   x = x + 1;
   Serial.print("Se incrementa x y se produce el OverFlow: ");
   Serial.println(x);
   while(1){}
}
