byte CLK=12,SERIE=11,RESET=10,i;
bool digito;
void setup() {
   pinMode(CLK,OUTPUT);
   pinMode(SERIE,OUTPUT);
   pinMode(RESET,OUTPUT);
   digitalWrite(CLK,0);
   digitalWrite(SERIE,0);
}
void loop() {
   digitalWrite(RESET,0);  //Reseteamos las salidas
   digitalWrite(RESET,1);
   delay(500);
   digito=1;
   for(i=0;i<8;i++){
      digitalWrite(SERIE,digito);
      digitalWrite(CLK,1);   //Flanco de subida
      digitalWrite(CLK,0);
      delay(500);}
      }
