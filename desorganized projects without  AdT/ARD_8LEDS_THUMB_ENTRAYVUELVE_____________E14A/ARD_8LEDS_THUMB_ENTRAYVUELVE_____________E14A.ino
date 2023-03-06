
byte dato,leds; //Definimos las variables a usar
bool bit0,bit1,bit2,bit3; //Definimos variables del tipo booleano
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
   //Calculamos el dígito ingresado
   dato = bit3*8 + bit2*4 + bit1*2 + bit0;
   leds = 0B11111111 >>(8-dato); // 0B para que Arduino sepa que es un numero BINARIO.
   // 8-dato para ESPECIFICAR CUANTAS VECES DESPLAZAR cada loop Y ES VARIABLE pues el loop lee y lee a cada rato. yo en hardware vario.
   // LO DESPLAZO A LA DERECHA 8-dato vece  s , el metodo que elegimos, de los 2 que hay, pero los
   dos para diferentes conexiones.
   //hora de extraer bit por bit.
   digitalWrite(6,leds%2);// el resto de dividir entre dos, es el bit LSB. %2 es para sacar el lsb y tener en variable.
   leds = leds>>1; // pasamos al siguiente termino, poniendolo en la posicion LSB.
   //LA POSICION DEPENDE. DE . COMO SALGA EL BINARIO DESPLAZADO.
   digitalWrite(7,leds%2); //la variable leds siempre tendra puros 1s seguidos y ceros seguidos por el codigo anterior a esta parte.
   leds = leds>>1;
   digitalWrite(8,leds%2);
   leds = leds>>1;
   digitalWrite(9,leds%2);
   leds = leds>>1;
   digitalWrite(10,leds%2);
   leds = leds>>1;
   digitalWrite(11,leds%2);
   leds = leds>>1;
   digitalWrite(12,leds%2);
   leds = leds>>1;
   digitalWrite(13,leds%2);
}
