#include <OBR.h>

Controle Motor(3,4,5,6,7,8); // in1 , in2 , pwma, in3, in4, pmwb

Sensores sensor1;
Sensores sensor2;

int LinhaDireita, LinhaEsquerda;

int time_refletance = 500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1.Leitura(9,0,1,1,time_refletance);
  sensor2.Leitura(10,0,1,1,time_refletance);
  
  LinhaEsquerda = sensor1.value;
  LinhaDireita = sensor2.value;


  if( LinhaEsquerda == 0 && LinhaDireita == 0){
  Motor.pwm(200,200);  
  }

  if( LinhaEsquerda == 0 && LinhaDireita == 1){
  Motor.pwm(200,0);  
  }

  if( LinhaEsquerda == 1 && LinhaDireita == 0){
  Motor.pwm(0,200);  
  }

  if( LinhaEsquerda == 1 && LinhaDireita == 1){
  Motor.pwm(200,200);  
  }
  
  }
