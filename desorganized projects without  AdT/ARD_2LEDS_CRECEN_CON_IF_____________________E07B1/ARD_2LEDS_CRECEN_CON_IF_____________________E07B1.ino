
byte num,i;
bool n0,n1,n2,n3;
void setup() { 
   for(i=4;i<=13;i++) {pinMode(i, OUTPUT);}
   for(i=0;i<=3;i++) {pinMode(i,INPUT);}
}
void loop() {
   n0=digitalRead(0);n1=digitalRead(1);n2=digitalRead(2);n3=digitalRead(3);
   num=8*n0+4*n1+2*n2+n3;
   for(i=0;i<10;i++){
      if(i<num)
         digitalWrite(4+i,HIGH);
      else
         digitalWrite(4+i,LOW); 
      } 
}
