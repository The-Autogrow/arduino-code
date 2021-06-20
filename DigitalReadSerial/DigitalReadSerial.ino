#include <dht11.h>
#include <RTClib.h>
#define dht_apin 4
dht11 DHT11;
RTC_DS3231 rtc;
const int capt_1 = A0;
const int capt_2 = A1;
const int pompe = 6;
const int resistance = 3;
String trad1, trad2;
int taux1,taux2,eau_hiver,eau_été,temperature_hiver,temperature_été,inputString,junk,a;
void setup(){
    Serial.begin(9600);
    pinMode(capt_1,INPUT);
    pinMode(capt_2,INPUT);
    pinMode(pompe,OUTPUT);
    pinMode(resistance,OUTPUT);
    if (! rtc.begin()){
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13,LOW); 
        while (1);
   }
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
    int chk = DHT11.read(dht_apin);
    DateTime time = rtc.now();
    taux1=map(analogRead(capt_1),0,1024,0,100);
    taux2=map(analogRead(capt_2),0,1024,0,100);
    if ( time.month() >= 4 and time.month() <= 9){//été
        if (DHT11.temperature < temperature_été){//gestion temperature
            digitalWrite(resistance,HIGH);
            while(DHT11.temperature < temperature_été);
        }
        digitalWrite(resistance,LOW);
        if (taux1 < 20 and eau_été=='coupelle'){
            digitalWrite(pompe,HIGH);
            while (taux1 < 20 and eau_été=='coupelle');
        }
        if (taux2 < 20 and eau_été=='pot'){
            digitalWrite(pompe, HIGH);
            while (taux2 < 20 and eau_été=='pot');
        }
        digitalWrite(pompe,LOW);
    } 
    else{//hiver
        if (DHT11.temperature < temperature_hiver){//gestion temperature
            digitalWrite(resistance,HIGH);
            while(DHT11.temperature < temperature_hiver);
        }
        digitalWrite(resistance,LOW);
        if (taux1 < 20 and eau_hiver=='coupelle'){
            digitalWrite(pompe,HIGH);
            while (taux1 < 20 and eau_hiver=='coupelle');
        }
        if (taux2 < 20 and eau_hiver=='pot'){
            digitalWrite(pompe, HIGH);
            while (taux2 < 20 and eau_hiver=='pot');
        }
        digitalWrite(pompe,LOW);
    }
    Serial.println((float)DHT11.temperature, 2);
    Serial.println((float)DHT11.humidity, 2);
    delay(1000);
}
