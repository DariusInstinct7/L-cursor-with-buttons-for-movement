byte dato,unidad,decena;    //Definimos las variables a usar
bool bit0,bit1,bit2,bit3;        //Definimos variables del tipo booleano
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
   Serial.begin(9600);
}
void loop() {
  //bit3 bit2 bit1 bit0   2 3 4 5
   bit0 = digitalRead(5);
   bit1 = digitalRead(4);
   bit2 = digitalRead(3);
   bit3 = digitalRead(2);
   //Calculamos el dígito ingresado
   dato = bit3*8 + bit2*4 + bit1*2 + bit0;
   unidad = dato%10; // si dato>10 , entonces unidad no sera 0.
   //10.. cero   11... 1 .... 12...2...13...3, 1 2 y 3 son las decenas.
   //sin embargo si trabajo con displays no puedo permitir que 1 2 3 etc llegue a mas de 9..
 // osea no pondre ni de chiste dato > 100. afortunadamente por hardware el thumbswitch tampoco puede superar valores > 15 :)
   //se les quito unidades, asumiendo que dato tiene 2 cifras.
   // y quedaran 4 bits o mas, com osea igual se puede almacenar todos esos en cada pin.
   //Serial.print("hola mundo\n"); // no puedo usar serial print ya que los bits se leen por hardware.
   //Serial.print(unidad); TECNICAMENTE. para compilar esto EN PIZARRA , debo SUBIR EL CODIGO
   //TENIENDO EL ARDUINO MEGA CONECTADO E INSTALADO, SELECCION EL PUERTO COMX CORRESPONDIENTE., NO COMPILARLO.
   //LUEGOP ABRO EL MONITOR SERIE
   //EN HERRAMIENTAS
   // Serial.print("\n");
   // delay(5000);
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
