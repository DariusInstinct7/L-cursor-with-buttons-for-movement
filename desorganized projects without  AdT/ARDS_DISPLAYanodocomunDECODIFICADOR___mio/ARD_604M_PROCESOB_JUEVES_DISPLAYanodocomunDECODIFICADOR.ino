int a = 0;
void setup(){
   pinMode(10,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(13,OUTPUT);
}
void loop() {
   muestraenDISPLAY(a);
   a++;
   if(a==10){a=0;}
   delay(500);
}
void muestraenDISPLAY(int a){
 if (a==0){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,0);     // Leemos el bit3  D
   digitalWrite(11,0);     // Leemos el bit2  C
   digitalWrite(12,0);     // Leemos el bit1  B
   digitalWrite(13,0);     // Leemos el bit0  A
  }
   if (a==1){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,0);     // Leemos el bit3  D
   digitalWrite(11,0);     // Leemos el bit2  C
   digitalWrite(12,0);     // Leemos el bit1  B
   digitalWrite(13,1);     // Leemos el bit0  A
  }
   if (a==2){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,0);     // Leemos el bit3  D
   digitalWrite(11,0);     // Leemos el bit2  C
   digitalWrite(12,1);     // Leemos el bit1  B
   digitalWrite(13,0);     // Leemos el bit0  A
  }
   if (a==3){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,0);     // Leemos el bit3  D
   digitalWrite(11,0);     // Leemos el bit2  C
   digitalWrite(12,1);     // Leemos el bit1  B
   digitalWrite(13,1);     // Leemos el bit0  A
  }
   if (a==4){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,0);     // Leemos el bit3  D
   digitalWrite(11,1);     // Leemos el bit2  C
   digitalWrite(12,0);     // Leemos el bit1  B
   digitalWrite(13,0);     // Leemos el bit0  A
  }
   if (a==5){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,0);     // Leemos el bit3  D
   digitalWrite(11,1);     // Leemos el bit2  C
   digitalWrite(12,0);     // Leemos el bit1  B
   digitalWrite(13,1);     // Leemos el bit0  A
  }
   if (a==6){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,0);     // Leemos el bit3  D
   digitalWrite(11,1);     // Leemos el bit2  C
   digitalWrite(12,1);     // Leemos el bit1  B
   digitalWrite(13,0);     // Leemos el bit0  A
  }
    if (a==7){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,0);     // Leemos el bit3  D
   digitalWrite(11,1);     // Leemos el bit2  C
   digitalWrite(12,1);     // Leemos el bit1  B
   digitalWrite(13,1);     // Leemos el bit0  A
  }
    if (a==8){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,1);     // Leemos el bit3  D
   digitalWrite(11,0);     // Leemos el bit2  C
   digitalWrite(12,0);     // Leemos el bit1  B
   digitalWrite(13,0);     // Leemos el bit0  A
  }
     if (a==9){
   //El número CERO se expresa en binario como 0000
   // D C B A   0 0 1 0 = 0
   digitalWrite(10,1);     // Leemos el bit3  D
   digitalWrite(11,0);     // Leemos el bit2  C
   digitalWrite(12,0);     // Leemos el bit1  B
   digitalWrite(13,1);     // Leemos el bit0  A
  }
  }
