void setup() {
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
}
void loop() {
   //El número DOS se expresa en binario como 0010
   digitalWrite(13,0);     // Leemos el bit0
   digitalWrite(12,1);     // Leemos el bit1
   digitalWrite(11,0);     // Leemos el bit2
   digitalWrite(10,0);     // Leemos el bit3
   delay(100);
   //El número CINCO se expresa en binario como 0101
   digitalWrite(13,1);     // Leemos el bit0
   digitalWrite(12,0);     // Leemos el bit1
   digitalWrite(11,1);     // Leemos el bit2
   digitalWrite(10,0);     // Leemos el bit3
   delay(500); 
}
