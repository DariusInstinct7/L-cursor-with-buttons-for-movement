void setup() {
   pinMode(13, OUTPUT); 
}
void loop() {
   digitalWrite(13, 1);       // Encendemos el led  1 o HIGH
   delay(500);                // Esperamos 0.5 segundo
   digitalWrite(13, 0);       // Apagamos el led
   delay(500);                // Esperamos 0.5 segundo
}
