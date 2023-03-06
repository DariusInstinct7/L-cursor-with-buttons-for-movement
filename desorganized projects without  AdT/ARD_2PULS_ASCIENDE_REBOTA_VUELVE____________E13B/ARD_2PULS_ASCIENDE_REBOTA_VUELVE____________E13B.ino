byte i,numero=0,k;
bool inc,dec;
void setup() {
for(i=9;i<=12;i++){pinMode(i,OUTPUT);}
   pinMode(2,INPUT);
   pinMode(3,INPUT);}
void loop() {
   inc=digitalRead(2);
   dec=digitalRead(3);
   if (inc==LOW&&numero<9){numero=numero+1;}
   if (dec==LOW&&numero>0){numero=numero-1;}
   i=numero;
   for(k=12;k>8;k--){
      digitalWrite(k,i%2);
      i=i/2;
   }
   while(digitalRead(2)==LOW||digitalRead(3)==LOW){delay(100);}
   delay(100);  //delay cuando se suelta el pulsador
}
