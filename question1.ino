/* 
 Pilotage de moteurs à CC sur M1 et M2
 Implémentation sur un châssis
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"//

// Instanciation de l'objet pilotage à l'adresse I2C par défaut
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Moteurs connectés sur M3 et M4
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);

void setup() 
{
  // Initialisation du shield moteur
  AFMS.begin();  // fréquence par défaut : 1.6 KHz
   
  // Vitesse 150 sur 255
  myMotor1->setSpeed(150);
  myMotor2->setSpeed(150);
  
  // Moteurs à l'arrêt
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);

  delay(1000);  // Petite pause de démarrage

  // ➤ Tourner vers l’avant
  myMotor1->run(FORWARD);         
  myMotor2->run(FORWARD);          
  delay(3000);  // Pendant 3 secondes

  // ➤ Tourner vers l’arrière
  myMotor1->run(BACKWARD);         
  myMotor2->run(BACKWARD);  
  delay(2000);  // Pendant 2 secondes

  // ➤ Arrêt moteur
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
}

void loop() 
{
  // Rien dans loop, car la séquence se joue une fois dans setup()
}
