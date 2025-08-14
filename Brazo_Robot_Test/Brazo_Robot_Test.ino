#include <Servo.h>

#define BTN1 2
#define BTN2 4
// Crear objetos para cada servo
Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
}

void loop() {

  servo1.detach();
  servo2.detach();
  servo3.detach();

  if (digitalRead(BTN1) == LOW) {
    // Conectar los servos a los pines
    servo1.attach(9);   //
    servo2.attach(10);  //
    servo3.attach(11);  //

    servo1.write(0);
    servo2.write(75);
    servo3.write(0);
    delay(1000);

    for (int pos = 75; pos >= 0; pos--) {  // Mover de 75° a 0° (Bajar Brazo)
      servo2.write(pos);
      delay(5);
    }
    delay(200);  // pausa en extremo

    for (int pos = 0; pos <= 135; pos++) {  // Mover de 0° a 135° (Cerrar Gripper)
      // servo1.write(pos);
      servo3.write(pos);
      delay(5);  // velocidad del movimiento
    }
    delay(200);  // pausa en extremo

    for (int pos = 0; pos <= 75; pos++) {  // Mover de 0° a 75° (Subir Brazo)
      servo2.write(pos);
      delay(5);  // velocidad del movimiento
    }
    delay(200);  // pausa en extremo

    for (int pos = 0; pos <= 270; pos++) {  // Mover de 45° a 140° (Giro Izquierda Brazo)
      servo1.write(pos);
      delay(5);  // velocidad del movimiento
    }
    delay(200);  // pausa en extremo

    for (int pos = 75; pos >= 0; pos--) {  // Mover de 75° a 0° (Bajar Brazo)
      servo2.write(pos);
      delay(5);
    }
    delay(200);  // pausa en extremo

    for (int pos = 135; pos >= 0; pos--) {  // Mover de 135° a 0° (Abrir Gripper)
      // servo1.write(pos);
      servo3.write(pos);
      delay(5);
    }
    delay(200);  // pausa en extremo

    for (int pos = 0; pos <= 75; pos++) {  // Mover de 0° a 75° (Subir Brazo)
      servo2.write(pos);
      delay(5);  // velocidad del movimiento
    }
    delay(200);  // pausa en extremo

    for (int pos = 270; pos >= 0; pos--) {  // Mover de 140° a 45° (Giro Derecha Brazo)
      servo1.write(pos);
      delay(5);
    }
    delay(200);  // pausa en extremo
  }
}