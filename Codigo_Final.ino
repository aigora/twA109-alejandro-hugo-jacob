#include <Brain.h>
#include <Servo.h>
#define N 20    //dimension del vector

Brain brain(Serial);
Servo servo;

/* FUNCIONES PROTOTIPO */

void intervalo(int valor);
float calculo_media_y_max_min (float _v[], int _dim, float *max, float *min);


void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  servo.attach(9);
}

boolean flag=true;              //flag que toma los valores logicos true o false (0/1)
int i=0;
 
void loop(){

  int dim=N,SENAL,ATENCION;
  float media,v[N],max,min,valor;
  
  if (brain.update() && i!=N  && flag==true ){    //si se actualiza y el vector no esta completo y el flag esta en true
    SENAL = brain.readSignalQuality();            //comprueba el estado de la señal
    if(SENAL<100){
        ATENCION = brain.readAttention();         //leer atencion
        v[i++]=ATENCION;                          //guardar en vector
        Serial.println(ATENCION);                 //manda estos valores por el puerto serie para la recepcion desde c
        intervalo(ATENCION);                      //llama a la funcion intervalo
      }
    }
  if(i==N && flag==true){   //si el vector está completo calcula la media y los valores max y min
      media=calculo_media_y_max_min(v,dim,&max,&min);
      Serial.print("\nLa media es:  ");
      Serial.println(media);
      Serial.print("\nEl max es:  ");
      Serial.println(max);
      Serial.print("\nEl min es:  ");
      Serial.println(min);
      Serial.print("\n\nLecura finalizada. Cierre la consola para terminar de guardar los datos");
      flag=false;     //flag en estado falso para evitar la repeticion de la lectura de datos en el loop
  }
}


/*====================================================================================================================================================*/


void intervalo(int valor){
  const int LedPin = 13;
  float s=valor;
  valor/=10;

  switch(valor){
    case 1:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 2:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 3:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 4:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 5:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 6:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 7:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 8:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 9:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    case 10:{
      digitalWrite(LedPin, HIGH);
      valor = map(s, 0, 100, 0, 180);     // mapeo para poner al servo entre 0 y180
      servo.write(s);                  // lo mueve a esa pos
      delay(15);
      break;
    }
    default:{
      break;
    }
  }
}

float calculo_media_y_max_min (float _v[], int _dim, float *max, float *min){   //devuelve la media por valor y el max y min por referencia
  float media,sum=0;
  int i;
  
  *max=_v[0];
  *min=_v[0];
  for(i=0;i<_dim;i++){
    sum+=_v[i];
    if(_v[i]>*max)
      *max=_v[i];
    else
      if(_v[i]<*min)
        *min=_v[i];
  }

  media=sum/_dim;
  return media;
}
