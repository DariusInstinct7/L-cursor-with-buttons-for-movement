byte dato,uni,dec,CLK=12,SERIE=11,RESET=13,i;
bool u0,u1,u2,u3,d0,d1,d2,d3;
void setup() {
   pinMode(CLK,OUTPUT);pinMode(SERIE,OUTPUT);pinMode(RESET,OUTPUT);
   digitalWrite(CLK,0);digitalWrite(SERIE,0);
   for(i=3;i<=10;i++){pinMode(i,INPUT);}
}
void loop() {
  //THUMBSWITCH
   u3 = digitalRead(3);u2 = digitalRead(4);u1 = digitalRead(5);u0 = digitalRead(6);
   d3 = digitalRead(7);d2 = digitalRead(8);d1 = digitalRead(9);d0 = digitalRead(10);
   // yes
   digitalWrite(RESET,0);digitalWrite(RESET,1);   //Reseteamos las salidas
   // quiere todo en un solo byte, ambos digitos.
   dec = d3*8+d2*4+d1*2+d0;//decenas
   dec = dec<<4; //Desplazamos 4 bits a la izquierda a dec
   uni = u3*8+u2*4+u1*2+u0;
   dato = dec|uni; //Sumamos en forma lógica. Ojo que tambien se puede sumar aritméticamente
   
   for(i=0;i<8;i++){
      digitalWrite(SERIE,dato%2);
      digitalWrite(CLK,1); //Flanco de subida
      digitalWrite(CLK,0);
      dato=dato/2;
   }
   delay(500);
}
