
#include <Matrix.h>

//Entradas de los pulsadores
byte A=2,B=3,C=4,D=5,E=6,F=7; 

//Pines elegidos
Matrix pixel= Matrix(12,10,11); //DIN,CLK,CS

//Rotacion y movimiento
int i=0,j=0;
bool valor1,valor0,valor6,valor7;
int x=0,y=0,pos=0; //posición inicial del cursor
bool datosL[]={1,0,0,0,1,1,1,1};

void setup(){
   //Valores Iniciales y Reconocimiento de Botones en los pines. 
   for(i=2;i<=7;i++)
   pinMode(i,INPUT);
   pixel.clear(); 
   
}

void loop(){

   //SIN PRESIONAR NI UN BOTON SI MUESTRA LA PRIMERA FORMA DE L SOLO SI ESTAMOS EN X 0 Y 0.
   if(x==0&&y==0){ 
    
    //ESCRITURA de datosL[pos]ALREDEDOR DEL Cursor x,y LINES 30-60
    pos=0;
    for(j=y-1;j<=y+1;j++){// 0 1 2
      if(x-1>=0){
      i=x-1; 
      pixel.write(i,j,datosL[pos]);
      }
    pos++;    
    }
    
     if(y+1<=7){
     i=x;
     j=y+1;
     pixel.write(i,j,datosL[pos]);
     }
 pos++;
 for(j=y+1;j>=y-1;j--){ // 0 1 2
    if(x+1<=7){
    i=x+1; 
    pixel.write(i,j,datosL[pos]);
    }
    pos++;
}
   if(y-1>=0){
   i=x;
   j=y-1;
   pixel.write(i,j,datosL[pos]);
   }
 pos++;
 }
 //FIN DE ESCRITURA ALREDEDOR DEL Cursor x,y .
  

 // ESPERANDO A PRESIONAR BOTON PARA MOVER O ROTAR LA L.
   while(digitalRead(F)==HIGH && digitalRead(E)==HIGH && digitalRead(A)==HIGH && digitalRead(B)==HIGH && digitalRead(C)==HIGH && digitalRead(D)==HIGH){}
   delay(100); //Evitar rebote
   pixel.clear(); //Apagamos cursor
   if(digitalRead(A)==LOW){
      if(y!=0){
         y--;
      }
   }
   if(digitalRead(C)==LOW){
      if(y!=7){
         y++;
      }
   }
   if(digitalRead(D)==LOW){
      if(x!=0){
         x--;
      }
   }
   if(digitalRead(B)==LOW){
      if(x!=7){
         x++;
      }
   }
   
    // GIRA EN SENTIDO ANTIHORARIO
    if(digitalRead(F)==LOW){ 
        valor6=datosL[6];
        valor7=datosL[7];
        
         // GIRA EN SENTIDO HORARIO
          
         //los  que cuyos datos no se pierden.  --- Desplazado en 2 posiciones el arreglo.  A LA DERECHA
         for(i=7;i>=0;i--){
            if(i!=6 && i!=7) { 
         datosL[i+2]=datosL[i];
             } 
         }   /
         
         //los  que cuyos datos SI se pierden.
         datosL[0]=valor6;        
         datosL[1]=valor7; 
         
   }// FIN GIRA EN SENTIDO ANTIHORARIO
   


// GIRA EN SENTIDO HORARIO
if(digitalRead(E)==LOW){ 
   
         //los  que cuyos datos no se pierden.  --- Desplazado en 2 posiciones el arreglo A LA IZQUIERDA
         for(i=0;i<=7;i++){
            if(i==0){
            valor0=datosL[0];
            } else
            if(i==1){
            valor1=datosL[1];
            } else {
            datosL[i-2]=datosL[i];
            } 
          //tip desplazamiento a la izquierda es de 0 a 7 porque sino se pierden todos los datos. el primero en desplazarse tiene que ser el mas cercano a posicion 0.
   
         //los  que cuyos datos SI se pierden.   
            if(i==7){
            datosL[6]=valor0;
            datosL[7]=valor1;
            }
         
         } 
         
   } // FIN GIRA EN SENTIDO HORARIO

   
   
//ESCRITURA ALREDEDOR DEL Cursor x,y . Escritura en perimetro Rectangulo. Como la matriz tiene valores que forman una L, una L se mostrará
   
   
   //escritura en lado izquierda del perimetro  rectangulo
   
            //empezamos desde posicion 0 del arreglo que contiene a la L. un arreglo (datosL[] ) que no incluye el punto central,solo los alrededores de este.
            pos=0;
   for(j=y-1;j<=y+1;j++){
      //solo escribimos partes de la L si es que la L sobrepasa los limites de la matriz de puntos.
      f(x-1>=0){
        
        i=x-1; 
        pixel.write(i,j,datosL[pos]);
      }
      pos++;    
   }
   
   //escritura en punto inferior central de todo el rectangulo
   if(y+1<=7){ i=x; j=y+1; pixel.write(i,j,datosL[pos]);
   
   }
   pos++;
   
    //escritura en lado derecho del perimetro rectangulo
   for(j=y+1;j>=y-1;j--){ // 0 1 2
      if(x+1<=7){  
         i=x+1;   
         pixel.write(i,j,datosL[pos]);
      }
      pos++; 
   }
    //escritura en punto superior central de todo el rectangulo
    if(y-1>=0){ i=x; j=y-1; pixel.write(i,j,datosL[pos]); }
    pos++; 
    //FIN DE ESCRITURA ALREDEDOR DEL Cursor x,y .
 
 
   //Hasta que se suelten los botones esperaremos 100ms mas y listo.
   while(digitalRead(F)==LOW || digitalRead(E)==LOW || digitalRead(A)==LOW || digitalRead(B)==LOW || digitalRead(C)==LOW || digitalRead(D)==LOW){}
   delay(100); //Evitar rebote
}
