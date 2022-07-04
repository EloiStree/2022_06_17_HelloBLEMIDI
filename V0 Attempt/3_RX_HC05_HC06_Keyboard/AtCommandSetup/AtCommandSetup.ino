/* utilisation d'un module Bluetooth HC-05
 *  et d'une liaison série avec le PC
 *  de plus nous pilotons la led
 *  en envoyant 1 depuis le terminal Android sur le module bluetooth on allume la led
 *  en envoyant 0, on éteint la led
*
* cablage du module Bluetooth
* module  -> arduino
* VCC     –> +5V
* GND     –>  GND
* TXD     –> Pin 4 RX des digital IO
* RXD     –> Pin 5 TX des digital IO
*
*/

/* nous utilisons une liaison série virtuelle pour le module bluetooth */  
#include <SoftwareSerial.h>   // Software Serial Port  
#define RxD 11              // Pin 4 pour la réception dans l'arduino
#define TxD 10                 // Pin 5 pour l'émission de l'arduino
SoftwareSerial BTSerie(RxD,TxD);  

void setup() {  
  // initialisation de la liaison série avec le PC à la vitesse de 9600 bauds
  Serial.begin(9600);
 
  // Configuration du module bluetooth à 9600 bauds, la vitesse du module par défaut
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);  
  BTSerie.begin(9600);

  // configuration de la broche de la led en sortie
  pinMode(13, OUTPUT);
  

}  

// dans la boucle principale nous faisons le relai entre le PC et le module bluetooth : les caractères envoyés depuis le terminal Android sont recopiés sur le mode terminal du PC pour visualisation.
void loop() {  
  char recvChar;  
  //On lit caractere par caractere sur le BTSerie et on affiche sur le Terminal Serie  
  if (BTSerie.available()) {  
    recvChar = BTSerie.read();
    Serial.write(recvChar);     // cette ligne n'est pas indispensable, mais elle peut aider au debugage pour vérifier que le module Android envoie correctement les caractères 0 et 1

   // teste du caractère reçu
   if (recvChar=='1'){          // s'il est à 1 on allume la led
      digitalWrite(13,HIGH);
    }
    if (recvChar=='0'){         // s'il est a 0 on eteint la led
      digitalWrite(13,LOW);
    }
  }  
} 
