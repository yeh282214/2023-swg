int analogpin = A0; // 알코올 센서를 아날로그핀 A0에 연결 측정값 0~1023

int buzzer = 10 ; // 부저에 디지털핀 9번을 연결


int value; // 측정값을 저장할 변수 선언
int ml[2]={3, 11};
int mr[2]={5, 6};


void setup() {

 Serial.begin(9600); // 통신속도 9600bps로 시리얼 통신 시작

 pinMode(buzzer, OUTPUT); // 부저를 출력모드로 설정
 for(int i=0; i<2; i++){
  pinMode(mr[i], OUTPUT);
  pinMode(ml[i], OUTPUT);
 }
}


void loop()

{
 if(Serial.available()>0){
  char ser = Serial.read();
  value= analogRead(analogpin); // A0에서 읽은 알코올 측정값을 읽어서 value에 저장

  Serial.print("Alcohol value: "); //시리얼 모니터에  출력

  Serial.println(value); // 시리얼 모니터에 알코올 측정값 출력'
  printf(value); 

  delay(100); //0.1초 딜레이

   if (value >= 400 && ser == 'red'){ //알코올 측정값이 300이상일 경우 부저 on

    digitalWrite(buzzer, HIGH);
    analogWrite(ml[0], 0);
    analogWrite(ml[1], 0);
    analogWrite(mr[0], 0);
    analogWrite(mr[1], 0);

 } 
   else if(value < 400 && ser == 'normal'){

    digitalWrite(buzzer, LOW);
    analogWrite(ml[0], 255);
    analogWrite(ml[1], 0);
    analogWrite(mr[0], 255);
    analogWrite(mr[1], 0);

 }
 }
}