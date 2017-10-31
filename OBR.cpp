#include"OBR.h"

Controle::Controle(int in1_, int in2_, int P_vel_A, int in3_, int in4_, int P_vel_B){
  
  in1 = in1_;
  in2 = in2_;
  p_vel_A = P_vel_A;
  
  in3 = in3_;
  in4 = in4_;
  p_vel_B = P_vel_B;
  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(p_vel_A,OUTPUT);
 
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(p_vel_B,OUTPUT);
      
}

void Controle::pwm(int V_vel_A, int V_vel_B){
	
vel_A = V_vel_A;
vel_B = V_vel_B;

if(vel_A < 0){
	vel_A*=-1;
	digitalWrite(in1,LOW);
	digitalWrite(in2,HIGH);
	analogWrite(p_vel_A,vel_A);
}

else if(vel_A > 0){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	analogWrite(p_vel_A,vel_A);
} else{
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);
	analogWrite(p_vel_A,vel_A);
}

if(vel_B < 0){
	vel_B*=-1;
	digitalWrite(in3,LOW);
	digitalWrite(in4,HIGH);
	analogWrite(p_vel_B,vel_B);
}

else if(vel_B > 0){
	digitalWrite(in3,HIGH);
	digitalWrite(in4,LOW);
	analogWrite(p_vel_B,vel_B);
}else{
	digitalWrite(in3,LOW);
	digitalWrite(in4,LOW);	
	analogWrite(p_vel_B,vel_B);
}
  
}

Sensores::Sensores(){
	pinMode(entrada,INPUT);
}

void Sensores::Leitura(int entrada,int powersensor,int ana_dig, int activemillis, int timereading){

	if(powersensor)
		digitalWrite(powersensor,HIGH);
	
	if(activemillis){
		time = millis();

		if(time - lastime > timereading){
			if(ana_dig)value = analogRead(entrada);
			else value = digitalRead(entrada);
			lastime = time;
		}

	}else{
		if(ana_dig) value = analogRead(entrada);
		else if (!ana_dig) value = digitalRead(entrada);
	}
}

// digita 0 analog 1
// desativa millis 0 ativa 1
