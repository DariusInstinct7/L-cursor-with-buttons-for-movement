byte CLK=12,SERIE=11,RESET=10,DATO=0b01100111,i;
//DATO=0b01100111 ES EL BYTE A ENVIAR. donde 0b solo es para que Arduino reconozca que es numero binario. 1bye = 8 bits.
void setup() {
   pinMode(CLK,OUTPUT);
   pinMode(SERIE,OUTPUT);
   pinMode(RESET,OUTPUT);
   digitalWrite(CLK,0);
   digitalWrite(SERIE,0);
}
void loop() {
   digitalWrite(RESET,0); //Reseteamos las salidas
   digitalWrite(RESET,1);
   for(i=0;i<8;i++){
      digitalWrite(SERIE,DATO%2); //Extraemos el bit de menor peso
      // Si quisieramos extraer el de MAYOR PESO MSB , seria DATO/ (2^7) desplaza 7 veces hasta que solo queda
      // el bit MSB en la posicion LSB, ya NI es necesario extraerlo con %2.
      digitalWrite(CLK,1); //Flanco de subida aqui recien lo enviamos
      digitalWrite(CLK,0); // preparamos para siguiente flanco. 
      DATO=DATO>>1;  //Dividimos el DATO entre 2, para que el siguiente bit de menor peso sea el siguiente en enviarse.
      delay(500);
   }
   while(1){} //Mediante esta instrucción, se DETIENE al programa
}
