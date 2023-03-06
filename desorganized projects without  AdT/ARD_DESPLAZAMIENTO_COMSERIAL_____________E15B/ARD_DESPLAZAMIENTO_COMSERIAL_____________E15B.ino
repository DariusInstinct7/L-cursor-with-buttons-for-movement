byte CLK=12,SERIE=11,i;
bool digitobool;
void setup() {
   pinMode(CLK,OUTPUT); //12
   pinMode(SERIE,OUTPUT);//11
   digitalWrite(CLK,0);
   digitalWrite(SERIE,0);
}
void loop() {
   digitobool= 1; // el unico y PRIMER DIGITO QUE NEVIO QU POR CERTO TERMINARA ULTIMO AL FINAL DE LOOP.
   for(i=0;i<8;i++){
      digitalWrite(SERIE,digitobool); //le envio 1 .
      digitalWrite(CLK,1); //Flanco de subida para que ENTRE EL PRIMER BIT SERIE. EMPUJANDO AL RESTO.para que ocupe el primer lugar.
      digitalWrite(CLK,0); //
      delay(500);
      digitobool=0;
   } // 8 veces  , la primera vez envio 1. las demas envie 0s. lo primero que envie terminara ULTIMA POSICION
   //OSEA QH... porque va de QA A QH primera y ultima posicion .
}
