

/* 
Pilotage de moteurs a CC sur M1 et M2
Imlantation sur un chassis
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// instanciation  de l'objet Pilotage a l'adresse par defaut I2C
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Pilotage de M1
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);


void setup() 
{

  // Initialisation Moteur
   // Pilotage par défaut a 1.6KHz
  AFMS.begin();  // create with the default frequency 1.6KHz
   
  // Vitesse 150 sur 255
  myMotor1->setSpeed(150);
  myMotor2->setSpeed(150);
  
 // Moteurs a l'arret
  myMotor1->run(FORWARD);
  myMotor2->run(RELEASE);
  delay(5000);
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  
  
}

// Boucle sans fin
void loop() 
{
  // Premier carré
  cote_carre();
  cote_carre();
  cote_carre();
  cote_carre();

  // Deuxième carré
  cote_carre();
  cote_carre();
  cote_carre();
  cote_carre();

  // Stop
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  
  while(1);
}
void cote_carre() 
{
  // Avancer tout droit
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  delay(1000); // Durée à adapter en fonction de la distance souhaitée

  // S'arrêter un court moment
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  delay(200);

  // Tourner pour former un angle droit (90°)
  myMotor1->run(FORWARD);
  myMotor2->run(RELEASE);  // Seul M1 tourne pour un virage
  delay(400); // Durée du virage à adapter selon le châssis

  // Stop après le virage
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  delay(200);
}
