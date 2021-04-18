const int capt_1 = 14;
const int capt_2 = 15;
String trad1;
String trad2;
int taux1;
int taux2;
void setup(){
    Serial.begin(9600);  
    pinMode(capt_1,INPUT);
    pinMode(capt_2,INPUT);
}
void loop(){
    taux1=analogRead(capt_1);
    taux2=analogRead(capt_2);
    Serial.println(map(taux1,0,1024,0,100));
    Serial.println(map(taux2,0,1024,0,100));
    delay(1000);
}
