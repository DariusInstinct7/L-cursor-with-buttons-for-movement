
byte CLK=12,SERIE=11,RESET=10,DATO=0b01011011,i;
// abcdefg 1011011 si enviamos primero el LSB. estara bien en orden para el display.
void setup (){
   pinMode(CLK,OUTPUT);
   pinMode(SERIE,OUTPUT);
   pinMode(RESET,OUTPUT);
   digitalWrite(CLK,0);
   digitalWrite(SERIE,0);
}
void loop (){
   digitalWrite(RESET,0);
   digitalWrite(RESET,1);
   for(i=0;i<8;i++){
      digitalWrite(SERIE,DATO%2);
      digitalWrite(CLK,1);
      digitalWrite(CLK,0);
      DATO=DATO/2;
   }
   while(1){}
} 
