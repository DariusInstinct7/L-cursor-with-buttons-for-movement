
byte CLK=12,SERIE=11,RESET=10,DATO=0b01100111,i;
void setup() {
   pinMode(CLK,OUTPUT);
   pinMode(SERIE,OUTPUT);
   pinMode(RESET,OUTPUT);
   digitalWrite(CLK,0);
   digitalWrite(SERIE,0);
}
void loop() {
   digitalWrite(RESET,0); 
   digitalWrite(RESET,1);//Reseteamos las salidas
   for(i=0;i<8;i++){
      digitalWrite(SERIE,DATO%2);
      // el clock era cero, como ahora lo pongo en uno, ya es flanco de subida.. luego lo ponoemos
      // a cero para que este listo para la siguiente activacion.
      digitalWrite(CLK,1); //Flanco de subida
      digitalWrite(CLK,0);
      DATO=DATO>>1;
      delay(500);
   }
   while(1){} //Mediante esta instrucción, se DETIENE al programa
}
