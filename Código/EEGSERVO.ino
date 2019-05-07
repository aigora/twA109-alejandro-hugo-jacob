#include <Brain.h>
#include <Servo.h>

Brain brain(Serial);

Servo SERVO;

const int LEDAZUL = 12;
const int PULSADOR = 3;

int ATENCION;

int SWITCH = 0;
int PRESWITCH = 0;
int ESTADO = 0;

int GRADOS = 0; 

void setup() {

  SERVO.attach(9);
  Serial.begin(9600);
}

void loop() {

  SWITCH = digitalRead(PULSADOR); 
  
  if ((SWITCH == HIGH) && (PRESWITCH == LOW)){
    ESTADO = 1 - ESTADO;
    delay(10);
}
  PRESWITCH = SWITCH;
  
  if (brain.update()) {

    ATENCION = brain.readAttention();
    
    Serial.print("Atencion: ");
    Serial.print(ATENCION);
    
    Serial.print("\t\t\t\t\t");
    
    Serial.print("Señal: ");
    Serial.println(brain.readSignalQuality());
  }

 if(ESTADO == 1){
  if ( brain.readSignalQuality() < 100) {

    digitalWrite(LEDAZUL, HIGH);
    GRADOS = map(ATENCION, 0, 100, 0, 180);
    SERVO.write(GRADOS); 
  }
}
else{
      GRADOS = 0;
      SERVO.write(GRADOS);   
      digitalWrite(LEDAZUL, LOW);
}
}
