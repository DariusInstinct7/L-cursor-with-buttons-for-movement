byte num1,num2,cociente; //Definimos la variable numero
bool bit0,bit1,bit2,bit3;      //Definimos variables del tipo booleano
bool bit4,bit5,bit6,bit7;      //Definimos variables del tipo booleano
bool bitA,bitB,bitC,bitD;     //Definimos variables del tipo booleano
void setup() {
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(7,INPUT);
   pinMode(6,INPUT);
   pinMode(5,INPUT);
   pinMode(4,INPUT);
   pinMode(3,INPUT);
   pinMode(2,INPUT);
   pinMode(1,INPUT);
   pinMode(0,INPUT);
}
void loop() {
   bit4 = digitalRead(7);      // Leemos el bit0
   bit5 = digitalRead(6);      // Leemos el bit1
   bit6 = digitalRead(5);      // Leemos el bit2
   bit7 = digitalRead(4);      // Leemos el bit3
   //Calculamos el segundo dígito en BCD
   num2 = bit7*8 + bit6*4 + bit5*2 + bit4;
   bit0 = digitalRead(3);     // Leemos el bit0
   bit1 = digitalRead(2);     // Leemos el bit1
   bit2 = digitalRead(1);     // Leemos el bit2
   bit3 = digitalRead(0);     // Leemos el bit3
   //Calculamos el primer dígito en BCD
   num1 = bit3*8 + bit2*4 + bit1*2 + bit0;
   cociente = num2/num1;
   bitA = cociente%2;
   digitalWrite(13,bitA);      // Encendemos el led D1
   cociente = cociente/2;
   bitB = cociente%2;
   digitalWrite(12,bitB);      // Apagamos el led D1
   cociente = cociente/2;
   bitC = cociente%2;
   digitalWrite(11,bitC);      // Encendemos el led D1
   cociente = cociente/2;
   bitD = cociente%2;
   digitalWrite(10,bitD);      // Apagamos el led D1
}
