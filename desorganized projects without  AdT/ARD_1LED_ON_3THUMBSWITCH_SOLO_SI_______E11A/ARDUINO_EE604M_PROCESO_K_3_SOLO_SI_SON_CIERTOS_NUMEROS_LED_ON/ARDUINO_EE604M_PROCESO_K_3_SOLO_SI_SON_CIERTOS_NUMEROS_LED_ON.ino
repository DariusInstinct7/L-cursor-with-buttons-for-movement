byte num1,num2,num3;          //Definimos las variables a usar
bool bit0,bit1,bit2,bit3,igual;   //Definimos variables del tipo booleano
bool bit4,bit5,bit6,bit7;            //Definimos variables del tipo booleano
bool bit8,bit9,bit10,bit11;        //Definimos variables del tipo booleano
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
   num3 = bit11*8 + bit10*4 + bit9*2 + bit8;
   bit4 = digitalRead(7);
   bit5 = digitalRead(6);
   bit6 = digitalRead(5);
   bit7 = digitalRead(4);
   //Calculamos el segundo dígito en BCD
   num2 = bit7*8 + bit6*4 + bit5*2 + bit4;
   bit0 = digitalRead(3);
   bit1 = digitalRead(2);
   bit2 = digitalRead(1);
   bit3 = digitalRead(0);
   //Calculamos el primer dígito en BCD
   num1 = bit3*8 + bit2*4 + bit1*2 + bit0;
   igual = (num1 == num2*2 && num1 == num3*3); // si hay un cero aunque sea. si alguno no se cumple, entonces igual = 0.
   //solo si num1 es 6 num2 es 3 num3 es 2.
   // 4 3 y 12=C .. si el thumbswitch es hex si se cumple tambien en este valor.
   digitalWrite(13,igual);  }    // Si los tres dígitos son iguales, se enciende el led
