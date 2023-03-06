
byte i,numero;
bool bit0,bit1,bit2,bit3;
void setup() {
   for(i=9;i<=12;i++){pinMode(i,OUTPUT);}
}
void loop() {
   for(i=0;i<10;i++){
      numero=i; // numero es de tipo byte.
      bit0=numero%2;numero=numero/2;
      bit1=numero%2;numero=numero/2;
      bit2=numero%2;numero=numero/2;
      bit3=numero%2;
      digitalWrite(12,bit0);digitalWrite(11,bit1);digitalWrite(10,bit2);digitalWrite(9,bit3);
      delay(500);
   }
}
