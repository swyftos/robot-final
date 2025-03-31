/*
 Pilotage d'un moteur à CC sur M1
 Sens de rotation défini par un poussoir
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"//

// Instanciation de l'objet pilotage à l'adresse I2C par défaut
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Pilotage du moteur M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(2);

// Variables
int Etat_BP1 = 0;           // Lecture bouton
int dernierEtatBP1 = 0;     // État précédent
int sens = 0;               // 0 = avant, 1 = arrière
const int pinBouton = 4;    // Broche du bouton

void setup() {
  AFMS.begin();             // Démarrage du shield
  myMotor->setSpeed(204);   // Vitesse moteur
  myMotor->run(RELEASE);    // Moteur à l'arrêt
  pinMode(pinBouton, INPUT_PULLUP);  // Bouton avec résistance de pull-up
}

void loop() {
  Etat_BP1 = digitalRead(pinBouton);

  // Détection d’un appui (front descendant)
  if (dernierEtatBP1 == HIGH && Etat_BP1 == LOW) {
    if (sens == 0) {
      Marche_Avant();
      sens = 1;  // Inverser pour la prochaine fois
    } else {
      Marche_Arriere();
      sens = 0;
    }
  }

  dernierEtatBP1 = Etat_BP1;
}

// Fonctions de marche :
void Marche_Avant() {
  myMotor->run(FORWARD);
 
}

void Marche_Arriere() {
  myMotor->run(BACKWARD);
  
}
