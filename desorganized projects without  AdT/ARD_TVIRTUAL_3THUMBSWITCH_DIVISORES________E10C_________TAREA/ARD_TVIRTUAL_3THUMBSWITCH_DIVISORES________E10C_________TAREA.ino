byte divisores=0;
int num,anterior=-1,i;
bool a0,a1,a2,a3,b0,b1,b2,b3,c0,c1,c2,c3;
void setup(){
   Serial.begin(9600);
   for(i=2;i<=13;i++)
      pinMode(i,INPUT);
}
void loop(){
   a0=digitalRead(5);a1=digitalRead(4);a2=digitalRead(3);a3=digitalRead(2);
   b0=digitalRead(9);b1=digitalRead(8);b2=digitalRead(7);b3=digitalRead(6);
   c0=digitalRead(13);c1=digitalRead(12);c2=digitalRead(11);c3=digitalRead(10);
   num=(a3*8+a2*4+a1*2+a0)*100+(b3*8+b2*4+b1*2+b0)*10+(c3*8+c2*4+c1*2+c0);
   if(num!=anterior){ //si se cambio el numero en THUMBSWITCH ENTONCES RECIEN RECALCULO TODO :
      Serial.print("El numero ");
      if( num==0){ //NUEVO NUMERO , NO ES PRIMO
         Serial.println("0 tiene 0 divisores");
      }
      if(num==1 ){ //NUEVO NUMERO , NO ES PRIMO
         Serial.println("1 tiene 1 divisor");
      }
      else{//casos>1
         for(i=2;i<=num;i++){ //divididos por todos los numeros y EL MISMO NUMERO, CUENTA COMO DIVISOR.
            if(num%i==0){divisores++;} //debe haber CERO divisores para ser primo
         }
         Serial.print(num);
         Serial.print(" tiene ");
          Serial.print(divisores);
         Serial.println(" divisores");
      }
      anterior=num;
      divisores=0;
   } delay (100); //Posibles rebotes que ocasionan MAL RECIBO DE INPUT, por tanto CALCULOS de otros numeros.
}
