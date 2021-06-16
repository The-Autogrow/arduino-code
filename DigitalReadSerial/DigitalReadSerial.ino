#include <dht.h>
#define dht_apin A2
dht DHT;
const int capt_1 = A0;
const int capt_2 = A1;
const int pompe = 6;
const int resistance = 3;
String trad1;
String trad2;
int taux1;
int taux2;
int eau_hiver;
int eau_été;
int temperature_hiver;
int temperature_été;
int inputString;
int junk;
int a;
void setup(){
    Serial.begin(9600);  
    pinMode(capt_1,INPUT);
    pinMode(capt_2,INPUT);
    pinMode(pompe,OUTPUT);
    pinMode(resistance,OUTPUT);
    while (a!=1){
        if(Serial.available()){ 
            while(Serial.available()) { 
                char inChar = (char)Serial.read(); //Lire l'entrée 
                inputString += inChar; //Construit une chaine de caractére a partir des caractére reçus
            } 
            while (Serial.available() > 0) { 
                junk = Serial.read() ; 
            }
            switch (inputString){
                case 'A':
                    eau_hiver='pot';
                    eau_été='coupelle';
                    temperature_hiver= 12;
                    temperature_été= 25;
                    a=1;
                    break;
                case 'B':
                    eau_hiver='pot';
                    eau_été='pot';
                    temperature_hiver= 10;
                    temperature_été= 25;
                    a=1;
                    break;
                case 'C':
                    eau_hiver='pot';
                    eau_été='pot';
                    temperature_hiver= 10;
                    temperature_été= 25;
                    a=1;
                    break;
            }
            inputString = ""; 
        }
    }
    delay(1000);
}
void loop(){
    DHT.read11(dht_apin);
    taux1=map(analogRead(capt_1),0,1024,0,100);
    taux2=map(analogRead(capt_2),0,1024,0,100);
    delay(1000);
}
