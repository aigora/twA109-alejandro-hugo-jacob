#include <Brain.h>

Brain brain(Serial);

const int LEDAMARILLO = 7;
const int LEDROJO = 2;
const int LEDBLANCO = 8;
const int LEDVERDE = 4;
const int LEDAZUL = 12;
int ATENCION;
int MEDITACION;

void setup() {

  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDBLANCO, OUTPUT);
  pinMode(LEDAMARILLO, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (brain.update()) {

    ATENCION = brain.readAttention();
    MEDITACION = brain.readMeditation();
    
    Serial.print("Atencion: ");
    Serial.print(ATENCION);
    
    Serial.print("\t");
    
    Serial.print("Meditacion: ");
    Serial.print(MEDITACION);
    
    Serial.print("\t\t\t\t\t");
    
    Serial.print("Señal: ");
    Serial.println(brain.readSignalQuality());
  }


  if ( brain.readSignalQuality() < 100) {

    digitalWrite(LEDAZUL, HIGH);

    if (ATENCION < 50) {
      digitalWrite(LEDVERDE, LOW);
      digitalWrite(LEDROJO, HIGH);
    }
    else
    {
      digitalWrite(LEDVERDE, HIGH);
      digitalWrite(LEDROJO, LOW);
    }


    if (MEDITACION < 50) {
      digitalWrite(LEDAMARILLO, HIGH);
      digitalWrite(LEDBLANCO, LOW);
    }
    else {
      digitalWrite(LEDAMARILLO, LOW);
      digitalWrite(LEDBLANCO, HIGH);
    }


  }
}
