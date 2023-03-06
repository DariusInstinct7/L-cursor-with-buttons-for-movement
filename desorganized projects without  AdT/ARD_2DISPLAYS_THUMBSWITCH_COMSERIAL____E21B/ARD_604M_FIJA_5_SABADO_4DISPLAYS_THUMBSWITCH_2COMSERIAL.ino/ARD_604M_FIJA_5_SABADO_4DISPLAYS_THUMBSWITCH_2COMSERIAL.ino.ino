byte dato,thumbdisplay=0,CLK2=12,SERIE2=11,RESET2=13,CLK1=9,SERIE1=8,RESET1=10,i;
byte numero01=0,num=0,var0=0,var1=0,var2=0,var3=0; 
bool bit3,bit2,bit1,bit0;
void setup() {
   pinMode(CLK1,OUTPUT);   pinMode(CLK2,OUTPUT);pinMode(SERIE1,OUTPUT);pinMode(SERIE2,OUTPUT);
   pinMode(RESET1,OUTPUT);pinMode(RESET2,OUTPUT);pinMode(0,OUTPUT);
   digitalWrite(CLK1,0); digitalWrite(CLK2,0);digitalWrite(SERIE1,0);digitalWrite(SERIE2,0);
   for(i=4;i<=7;i++){pinMode(i,INPUT);}
   for(i=2;i<=3;i++){pinMode(i,INPUT_PULLUP);}
   digitalWrite(RESET1,0);digitalWrite(RESET1,1);   
   digitalWrite(RESET2,0);digitalWrite(RESET2,1);  //Reseteamos las salidas
   delay(500);
   }

void loop() {
   //THUMBSWITCH
   bit3= digitalRead(4);bit2 = digitalRead(5);bit1 = digitalRead(6);bit0 = digitalRead(7);
   thumbdisplay = bit3*8+bit2*4+bit1*2+bit0;
   while(digitalRead(3)==HIGH && digitalRead(2)==HIGH ){delay(100);}
      if(digitalRead(3)==LOW){                         //el pin3 se presiono : DISMINUIR.
         while(digitalRead(3)==LOW){delay(100);} 
      
            if (thumbdisplay==0){
                 
                 if((var0>>4)!=0){  //solo varia var0 si es dif de 0.
                    
                    var0=var0>>4;
                    var0=var0-1; // display0
                    var0=var0<<4;
                    numero01=var0|var1;
                    //numero01 ABCDabcd 
                    num=numero01;  
                    for(i=0;i<4;i++){   // para DISPLAY 1 pines B
                       //0000 1101  numero empuja al resto.
                       // serial A.1110 B.0101 
                       //entran primero los de la derecha
                       digitalWrite(SERIE1,(num/8)%2); 
                       digitalWrite(CLK1,1); 
                       digitalWrite(CLK1,0);
                        num=num*2; }                
                    num=numero01>>4;
                    for(i=0;i<4;i++){  // para DISPLAY 0 pines A
                        //0000 1101  numero empuja al resto.
                        // serial A.1110 B.0101 
                        digitalWrite(SERIE1,(num/8)%2); 
                        digitalWrite(CLK1,1); 
                        digitalWrite(CLK1,0);
                         num=num*2; }   
                        }//FIN if(var0!=0)  
                        }//FIN IF  thumbdisplay==0

       /*  if (thumbdisplay==1){
    
    
       } // FIN IF  thumbdisplay==1
       if (thumbdisplay==2){
    
    
       }  // FIN IF  thumbdisplay==2
       if (thumbdisplay==3){
 
    
       }  // FIN IF  thumbdisplay==3
       */
     
   }
   
   if(digitalRead(2)==LOW){ //el pin2 se presiono : AUMENTAR.
    
      while(digitalRead(2)==LOW){delay(100);}
  
        if (thumbdisplay==0){
                   //yes
                 
                 if( (var0>>4) != 9){  //cuando no es cero, AUMENTA var0 del display0.

                   //yes
                   
                    var0=var0>>4;  
                    var0=var0+1; // display0     00000010
                    var0=var0<<4; //yes 00010000
                    numero01=var0|var1; //yes 00010000
                     
                    //numero01 ABCDabcd 
                    num=numero01;  
                    for(i=0;i<4;i++){ // para DISPLAY 1 pines B
                       //0000 1101  numero empuja al resto.
                       // serial A.1110 B.0101 
                       //entran primero los de la derecha
                       digitalWrite(SERIE1,(num/8)%2);  
                       digitalWrite(CLK1,1); 
                       digitalWrite(CLK1,0);
                       num=num*2; }     //00100000   
                       // 0001 0000        
                    num=numero01>>4;  // para DISPLAY 0 pines A
                    for(i=0;i<4;i++){ 
                        //0000 1101  numero empuja al resto.
                        // serial A.1110 B.0101 
                        digitalWrite(SERIE1,(num/8)%2);  
                        digitalWrite(CLK1,1); 
                        digitalWrite(CLK1,0);
                        num=num*2; }   
                        }//FIN if(var0!=9)  
                        }//FIN IF  thumbdisplay==0

   } //FIN if(digitalRead(2)==LOW)
}
