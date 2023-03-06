byte i,j,numero;
void setup() {
   for(i=9;i<=12;i++){pinMode(i,OUTPUT);}
}
void loop() {
   for(i=0;i<10;i++){
      numero=i;
      for(j=12;j>8;j--){
         digitalWrite(j,numero%2);
         numero=numero/2;
      }
      delay(500);
   }
} 
