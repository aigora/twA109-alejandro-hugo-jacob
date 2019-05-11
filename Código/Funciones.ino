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
