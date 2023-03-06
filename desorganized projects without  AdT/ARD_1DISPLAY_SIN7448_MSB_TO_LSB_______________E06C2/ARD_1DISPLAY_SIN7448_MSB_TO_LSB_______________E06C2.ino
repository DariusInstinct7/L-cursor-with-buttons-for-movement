
byte i,dato=0b00111111;
void setup(){
   for(i=7;i<=13;i++)
       pinMode(i,OUTPUT);
   }
void loop(){
   //Enviando desde el MSB
   for(i=7;i<=13;i++){
      dato=dato<<1;
      digitalWrite(i,!(dato)/128); 
      //esto tiene que ir despues. de dato=dato<<1 SI O SI
      
   }
while(1){}
}
