
byte dato,unidad,decena;    //Definimos las variables a usar
bool bit0,bit1,bit2,bit3;   //Definimos variables del tipo booleano
void setup() {
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(9,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(5,INPUT);
   pinMode(4,INPUT);
   pinMode(3,INPUT);
   pinMode(2,INPUT);
}
void loop() {
   bit0 = digitalRead(5);
   bit1 = digitalRead(4);
   bit2 = digitalRead(3);
   bit3 = digitalRead(2);
   //Calculamos el dígito ingresado por nosotros en hardware.
   dato = bit3*8 + bit2*4 + bit1*2 + bit0;
   //lo convertimos a 8bits. de decimal, a 8 bits.
   unidad = dato%10;
   digitalWrite(9,unidad%2);
   unidad = unidad/2;
   digitalWrite(8,unidad%2);
   unidad = unidad/2;
   digitalWrite(7,unidad%2);
   unidad = unidad/2;
   digitalWrite(6,unidad%2);
   decena = dato/10;
   digitalWrite(13,decena%2);
   decena = decena/2;
   digitalWrite(12,decena%2);
   decena = decena/2;
   digitalWrite(11,decena%2);
   decena = decena/2;
   digitalWrite(10,decena%2);
}
