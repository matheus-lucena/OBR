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
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
analogWrite(p_vel_A,vel_A);
}

if(vel_A > 0){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
analogWrite(p_vel_A,vel_A);
}

if(vel_A == 0){
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
analogWrite(p_vel_A,vel_A);
}

if(vel_B < 0){
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(p_vel_B,vel_B);
}

if(vel_B > 0){
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(p_vel_B,vel_B);
}

if(vel_B == 0){
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);	
analogWrite(p_vel_B,vel_B);
}
  
}

Sensores::Sensores(){
	pinMode(entrada,INPUT);
	int time,lastime,timereading,activemillis;
}
void Sensores::Leitura(int entrada_,int powersensor_,int ana_dig_, int activemillis_, int timereading_){
	
	entrada = entrada_;
	ana_dig = ana_dig_;
	powersensor = powersensor_;
	
	timereading = timereading_;
	activemillis = activemillis_;
	
	if(powersensor != 0){
	digitalWrite(powersensor,HIGH);
	}
	
	if(ana_dig == 0){
	if(activemillis == 1){
	time = millis();
	
	if(time - lastime > timereading){
	value = analogRead(entrada);	
	// todos Sensores
	lastime = time;
	}else{
	value = analogRead(entrada);	
		// Todos Sensores
	}
}
}else{
	
	if(activemillis == 1){
	time = millis();
	
	if(time - lastime > timereading){
	value = digitalRead(entrada);	
	// todos Sensores
	lastime = time;
	}else{
	value = digitalRead(entrada);	
		// Todos Sensores
	}
		}
	
			}
			
}


// fazer controle de energia individual por sensor
