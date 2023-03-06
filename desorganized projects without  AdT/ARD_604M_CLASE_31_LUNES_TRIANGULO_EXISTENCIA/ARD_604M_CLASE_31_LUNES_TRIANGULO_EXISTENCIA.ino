byte lado1,lado2,lado3;              //Definimos las variables a usar
bool bit0,bit1,bit2,bit3,triangulo;   //Definimos variables del tipo booleano
bool bit4,bit5,bit6,bit7;              //Definimos variables del tipo booleano
bool bit8,bit9,bit10,bit11;           //Definimos variables del tipo booleano
void setup() {
   pinMode(13,OUTPUT);
   pinMode(11,INPUT);
   pinMode(10,INPUT);
   pinMode(9,INPUT);
   pinMode(8,INPUT);
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
   bit8 = digitalRead(11);
   bit9 = digitalRead(10);
   bit10 = digitalRead(9);
   bit11 = digitalRead(8);
   //Calculamos el tercer dígito en BCD
   lado3 = bit11*8 + bit10*4 + bit9*2 + bit8;
   bit4 = digitalRead(7);
   bit5 = digitalRead(6);
   bit6 = digitalRead(5);
   bit7 = digitalRead(4);
   //Calculamos el segundo dígito en BCD
   lado2 = bit7*8 + bit6*4 + bit5*2 + bit4;
   bit0 = digitalRead(3);
   bit1 = digitalRead(2);
   bit2 = digitalRead(1);
   bit3 = digitalRead(0);
   //Calculamos el primer dígito en BCD
   lado1 = bit3*8 + bit2*4 + bit1*2 + bit0;
   triangulo = (lado1+lado2>lado3 && lado1+lado3>lado2 && lado2+lado3>lado1);
   // SI ALGUNA DE LAS COMPARCIONES NO SE CUMPLE, TRIANGULO ES CERO.
   digitalWrite(13,triangulo);
}
