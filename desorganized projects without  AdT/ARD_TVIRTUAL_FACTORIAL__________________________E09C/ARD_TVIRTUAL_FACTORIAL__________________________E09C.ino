
int num,anterior=-1,i;
unsigned long fact; //El tipo de datos long va desde: 0 a 4,294'967,295 (solo llega a 12!)
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
   if(anterior!=num){
      fact=1;
      for(i=1;i<=num;i++){ fact=fact*i; }
      Serial.print("El factorial de ");
      Serial.print(num);
      Serial.print(" es ");
      Serial.print(fact);
      anterior=num;
      Serial.println();
   } delay(100); //Posibles rebotes
}
