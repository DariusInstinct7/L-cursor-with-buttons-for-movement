
void setup() {
   pinMode(5,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(8,OUTPUT);
}
void loop() {
   digitalWrite(5,1);   // Encendemos el led D1
   delay(500);           // Esperamos medio segundo
   digitalWrite(5,0);  // Apagamos el led D1
   digitalWrite(6,1);  // Encendemos el led D2
   delay(500);           // Esperamos medio segundo
   digitalWrite(6,0);  // Apagamos el led D2
   digitalWrite(7,1);  // Encendemos el led D3
   delay(500);           // Esperamos medio segundo
   digitalWrite(7,0);  // Apagamos el led D3
   digitalWrite(8,1);  // Encendemos el led D4
   delay(500);           // Esperamos medio segundo
   digitalWrite(8,0);  // Apagamos el led D4
}
