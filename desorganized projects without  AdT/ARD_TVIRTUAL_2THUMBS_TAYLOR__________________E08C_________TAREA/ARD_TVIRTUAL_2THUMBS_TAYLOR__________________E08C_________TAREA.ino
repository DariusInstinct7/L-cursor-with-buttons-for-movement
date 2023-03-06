
byte ntotal,i,j; //para que FUNCIONE el if, que te ahorra el do while, cuando son muchas comp de thumb
double senxtaylor=0,x,xanterior=-1,ntotalanterior=-1; //double no es suficiente para factoriales grandes.
unsigned long p; //double es para decimales, long NO.
bool a0,a1,a2,a3,c0,c1,c2,c3;
#define PI 3.141592653589 //sin punto y coma en #define siempre.
void setup(){
   Serial.begin(9600);
   for(i=10;i<=13;i++)
      pinMode(i,INPUT);
   for(i=3;i<=6;i++)
      pinMode(i,INPUT);
}
void loop(){
   a0=digitalRead(13);a1=digitalRead(12);a2=digitalRead(11);a3=digitalRead(10);
   c0=digitalRead(6);c1=digitalRead(5);c2=digitalRead(4);c3=digitalRead(3);
   x=(a3*8+a2*4+a1*2+a0)*10*PI/(180); //en rads x no INT o se arruinaa, angulo *10
   ntotal=c3*8+c2*4+c1*2+c0;
   
   if(x!=xanterior | ntotal!=ntotalanterior){ //si se cambio el numero en THUMBSWITCH ENTONCES RECIEN RECALCULO TODO :
      
         //0 1 2     3-1
         //para que i lo use como valor de k. pues la cantidad ya la relacione.
         for(i=0;i<=ntotal-1;i++){ 
         
          p=1; // reseteo el p aqui, para que no se acumule, ADEMAS evito error cuando i=0,
          if(i!=0){// SALTEO EL MODIFICANDO de p al inicio.
          for(j=1;j<=2*i+1;j++){   
           p=p*j;} //no poner parentesis a j, o se jode todo.
          }
          Serial.print("factorial de ");
          Serial.print(2*i+1);
          Serial.print(" es : ");
          Serial.println(p);
          //si la variable en que se almacena es byte, ENTERIZA y error. senxtaylor debe ser long.
         
          senxtaylor=  senxtaylor + pow(-1,i)*(pow( x,2*i+1)/(p));   //overflow?  //MINIMO  10 TERMINOS porque sino el error es 900%
         //p debe ser unisgned para que aumente su capacidad y que no interfiera su - con los otros.
          Serial.println(pow(-1,i)*(pow( x,2*i+1)/p));
          Serial.print("termino n ");
          Serial.print(i+1);
          Serial.print(" es : ");
          Serial.println(senxtaylor);
         }
         Serial.print(" La serie de Fourier de ");
         Serial.print(x*180/PI); //en grados.
         Serial.print(" con ");
         Serial.print(ntotal);
         Serial.print(" terminos es ");
         Serial.println(senxtaylor,6);
      senxtaylor=0;
      xanterior=x;
      ntotalanterior=ntotal;
   } delay (100); //Posibles rebotes que ocasionan MAL RECIBO DE INPUT, por tanto CALCULOS de otros numeros.
}
