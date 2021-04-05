const int capt_1 = 14;
const int capt_2 = 15;
byte taux1;
byte taux2;
void setup(){
    Serial.begin(9600);  
    pinMode(capt_1,INPUT);
    pinMode(capt_2,INPUT);
}
void loop(){
    taux1=analogRead(capt_1);
    taux2=analogRead(capt_2);
    Serial.println(String(taux1)+"a"+String(taux2)+"b");
    delay(1000);
}
