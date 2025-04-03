#include <Wire.h>
#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *myMotor1 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);

void setup() 
{
  AFMS.begin();  
  myMotor1->setSpeed(150);
  myMotor2->setSpeed(150);
  
  delay(1000); // Pause avant démarrage

  dessinerE(); // Lancement du tracé

  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
}

void loop() 
{
  while (1); // On fait le E une seule fois
}

void dessinerE() {
  // Barre verticale (20 cm)
  avancer(2000); // avancer 20 cm
  stop_moteurs();
  
  // Tourner à droite
  tournerDroite(450);
  
  // Barre horizontale du haut (10 cm)
  avancer(1000); // 10 cm
  stop_moteurs();
  
  // Demi-tour
  demiTour();
  
  // Revenir à la verticale
  avancer(1000);
  stop_moteurs();

  // Descendre de 5 cm
  tournerGauche(450);
  avancer(500);
  stop_moteurs();
  
  // Tourner à droite pour milieu
  tournerDroite(450);
  avancer(700); // barre du milieu (7 cm)
  stop_moteurs();
  
  // Demi-tour
  demiTour();
  avancer(700); // retour
  stop_moteurs();

  // Descendre pour barre du bas
  tournerGauche(450);
  avancer(500);
  stop_moteurs();

  // Tourner à droite et faire barre du bas
  tournerDroite(450);
  avancer(1000); // 10 cm
  stop_moteurs();
}

void avancer(int t) {
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  delay(t);
  stop_moteurs();
}

void tournerDroite(int t) {
  myMotor1->run(FORWARD);
  myMotor2->run(RELEASE);
  delay(t);
  stop_moteurs();
}

void tournerGauche(int t) {
  myMotor1->run(RELEASE);
  myMotor2->run(FORWARD);
  delay(t);
  stop_moteurs();
}

void demiTour() {
  myMotor1->run(FORWARD);
  myMotor2->run(BACKWARD);
  delay(900); // Ajuste ce temps pour un vrai 180°
  stop_moteurs();
}

void stop_moteurs() {
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  delay(300);
}
