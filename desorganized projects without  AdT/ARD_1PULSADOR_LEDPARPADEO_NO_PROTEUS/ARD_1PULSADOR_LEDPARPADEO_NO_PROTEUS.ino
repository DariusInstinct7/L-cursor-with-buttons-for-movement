
bool bit=false;
void setup() {
   pinMode(13,OUTPUT);
   pinMode(3,INPUT); 
}
void loop() { 
   while(digitalRead(3)==HIGH){
    //mientras no se presione nada, parpadea LENTO
      delay(500);
      bit=!bit;
      digitalWrite(13,bit); 
   }
   while(digitalRead(3)==LOW){
    // cuando lo presionas y lo mantiene presionado ahi se nota ,que parpadea a 200ms.RAPIDO. al soltarlo, vuelve a 500ms.
      delay(200); // LOS DELAYS TAMBIEN SIRVEN COMO ANTIREBOTE ADEMAS DE PARPADEO, PUES SUPERA LOS 100ms.
      bit=!bit;
      digitalWrite(13,bit); 
   }
}
