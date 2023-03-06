 int leds1=0B0000000000;
byte pin = 13,nthumb=0,n=0,i; //n veces que se desplaza.
bool medio=0,bit3,bit2,bit1,bit0;
void setup (){
   pinMode(13,OUTPUT);   pinMode(12,OUTPUT);   pinMode(11,OUTPUT);   pinMode(10,OUTPUT);
   pinMode(9,OUTPUT);   pinMode(8,OUTPUT);   pinMode(7,OUTPUT);   pinMode(6,OUTPUT);   
   pinMode(5,OUTPUT);  pinMode(4,OUTPUT);
   pinMode(3,INPUT);   pinMode(2,INPUT);   pinMode(1,INPUT);   pinMode(0,INPUT);
}

void loop() {
   bit3=digitalRead(0);
   bit2=digitalRead(1);
   bit1=digitalRead(2);
   bit0=digitalRead(3); //nthumb es cero al inicio.
   //tal vez * no sea para binarios de 10 bits, solo con bools funcionaria este metodo.
   leds1= (nthumb!= bit3*8+bit2*4+bit1*2+bit0)*(0B1111111111 <<(10-nthumb))+ (nthumb== bit3*8+bit2*4+bit1*2+bit0)*(leds1);//si el nthumb anterior es diferente al leido entonces reiniciamos leds
   //n y medio requieren ser reiniciados tambien 
   n = (nthumb== bit3*8+bit2*4+bit1*2+bit0)*(n); //si "a" se niega var se reinicia a 0 , si var se cumple n se mantiene igual.
   medio = (nthumb== bit3*8+bit2*4+bit1*2+bit0)*(medio);
   
   //siempre estamos leyendo los thumbswitch, para saber si hay algun cambio.
   nthumb= bit3*8+bit2*4+bit1*2+bit0;
   
  
   
   //leds1 = 0B1111111111 <<(10-nthumb);//CUMPLE QUE QUEDAN nthumbn 1s en los 10 leds y el resto 0s.
   //leds2 = 0B1111111111 >>(10-nthumb);
   //ledstotal= leds1|leds2; //solo puede haber maximo 5 leds encendidos.
   //ya tenemos la cantidad de leds prendidos
   //leds1= 11100 00000
   //leds2= 00000 00111
   //leds1>>(5-nthumb);
   //leds2<<(5-nthumb);

   //cuando SE CUANTAS VECES DEBO DESPLAZAR ESOS LEDS. Y CUANTOS DEBO REGRESAR y empezamos en n=0, 5-nthumb veces en este caso : 
   // leds1 = (n== 5-nthumb)*leds1 + (medio==0)*(n!=5-nthumb)*(leds1>>1) + (medio==1)*(n!=5-nthumb)*(leds<<1)// nunca se usa
   // el primer termino, nunca se usa. pues apenas choca regresa, no espera nada. 
   leds1=leds1>>5; //00000 11100
   for(i=0;i<5;i++){
      digitalWrite(9+i,leds1%2);
      leds1=leds1 /2;
   }
   for(i=0;i<5;i++){
      digitalWrite(8-i,leds1%2);
      leds1=leds1/2;
   }
    delay(1000);
    /*
    leds1 =  (medio==0)*(n!=5-nthumb)*(leds1>>1) + (medio==1)*(n!=5-nthumb)*(leds1<<1);//....(x)
    //al no hacer nada en n=5-nthumb, solo se reinicia n y medio cambia
    // ocurren n veces, pero el n==5-nthumb jamas se cumple en esa ecuacion,nunca llegamos al final. solo a 5-nthumb-1
    
    n++;  //primero se DESPLAZA luego se aumenta,como una evidencia de que si ocurrió y es certero, asi se evita lo del for que es. n-1 
    // aqui n es las veces que ya se DESPLAZO. luego de aumentarle uno mas, recien tiene esa definicion.

    //aqui si llegamos a 5-nthumb.
    medio = (n== 5-nthumb)*(!medio); //medio indica si ya se llego al medio con los leds. el n real, aparece cuando n++ ocurre recien.
    
    n = (n!= 5-nthumb)*(n); //no pasa nada si no cumple , pero si si cumple se hace cero.
    //se le reinicia apenas llego a n=5-nthumb para que no se llegue a un delay innecesario , donde(x) no hace ningun cambio en leds1.

    //contando el 4, por eso funciona 4. sino 5 en el for.
    //en total seran 13 a 9 , 5 numeros que procesaras. PLANR MEJOR. me mare.
 
*/
}
