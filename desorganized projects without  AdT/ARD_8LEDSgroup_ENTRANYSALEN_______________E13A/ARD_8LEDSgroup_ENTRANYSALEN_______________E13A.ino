
byte pin = 13;
bool digito = 1;
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
   digitalWrite(pin, digito);//aqui entran los 1s o 0s PARA EL PIN RESPECTIVO que va variando pin--
   delay(500);
    // ingresa 1s y despues ingresa 0s.
   //digito = 1. digito es bool.....pin =13.
   //LLENA DE 1S de arriba a abajo, luego llena de ceros : ENTRA POR UN LADO LOS 1S Y SALEN POR EL OTRO LADO.
   digito=(pin==6)*(!digito)+(pin!=6)*(digito); // digito cambia de 1 y 0 , de  0 a 1.
   //NEGACION DE DIGITO, ESO, HACE QUE digito= !digito. cuando estemos en pin==6, pues (pin!=6)hace cero el otro termino.
   //digito cambia justo cuando "pin" reinicia de 6 a 13. YA LLENO TODO. ENTONCES VACIARA TODO DE A POCOS.
   pin=(pin==6)*13+(pin!=6)*(pin-1);//el pin vuelve a 13 cuando pin=6  ó el pin pasa al siguiente con -1.
}
