
byte cateto1,cateto2,i,cat1antes=0,cat2antes=0;
void setup(){
   Serial.begin(9600);
   for(i=6;i<=13;i++)
      pinMode(i,INPUT);
}
void loop(){
   do { //lee (repite codigo si, pero solo estas dos lineas :) )mientras no se cambie ningun INPUT.
      cateto1=digitalRead(10)*8+digitalRead(11)*4+digitalRead(12)*2+digitalRead(13);
      cateto2=digitalRead(6)*8+digitalRead(7)*4+digitalRead(8)*2+digitalRead(9);
   }while(cateto1==cat1antes && cateto2==cat2antes || cateto1==0 || cateto2==0);
   
   Serial.print("El valor del cateto1 es: ");
   Serial.println(cateto1);
   Serial.print("El valor del cateto2 es: ");
   Serial.println(cateto2);
   double hipo=sqrt(pow(cateto1,2)+pow(cateto2,2));
   Serial.print("El valor de la hipotenusa es: ");
   Serial.println(hipo,4);  
   Serial.println(hipo,8);  
   cat1antes=cateto1;  //Pasa a ser el cateto1 "del pasado"
   cat2antes=cateto2;  //Pasa a ser el cateto2 "del pasado"
}
