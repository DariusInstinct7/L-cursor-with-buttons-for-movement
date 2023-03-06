
bool bit = false;
void setup() { 
   pinMode(3,INPUT);  // EN VEZ DE INPUT PONES INPUT_PULLUPP,CONECTAS EL PULSADOR "SOLO" AL PIN 3 Y YA. LISTO. AHORRAS HARDWARE.
   // ES EL MISMO CIRCUITO PULL UP SOLO QUE ESTA INTERNO EN EL ARDUINO.
   pinMode(13,OUTPUT); 
} 
void loop() {
   while(digitalRead(3)==HIGH){delay(100);} 
   //el delay no sirve, solo esta esperando a que se presione el boton hasta ahora, NO CORRIGE NADA AUN. en la segunda vuelta SI.
   //2. aqui se corrige el ultimo rebote, como estamos en loop() asi funciona.
   /* bit=!bit;
   digitalWrite(13,bit);  //AQUI SE UBICARIA SI QUISISERAMOS QUE AL PRESIONAR AL INSTANTE SE PRENDA EL LED, SINO,
   //SI LO PONEMOS ABAJO SOLO CUANDO SOLAMOS EL BOTON SE PRENDE EL LED.*/ 
   while(digitalRead(3)==LOW){delay(100);} //estamos en el primer cero de bloque1. espera 1 delay 
   //ese 1 delay ya nos ubica en estado estable de cero y luego sale del while en 1 de bloque2
   //aqui recien ya se sabe que se presiono y que estamos en "1" bloque 2. osea ya se solto PERO REBOTE AUN NO CORREGIDO.. entonces hacemos :
   // si mantenemo presionado el boton por joder, hasta ahora nos quedamos en ANTES DE 1 del bloque 2,ESPERANDO. aun sin el ultimo rebote evitado o corregido
   // asi que aqui ya cuena como que se presiono y solto, LA INSTRUCCION SE EJECUTA MIENTRAS EL REBOTE SE CORRIGE EN EL SEGUNDO LOOP.
   //no pasanada porque las instruccion son mas rapidas, mientras no sean muchas, normal en el segundo loop.
   bit=!bit;
   digitalWrite(13,bit);  
}
