#ifndef OBR_H
#define OBR_H

#include <Arduino.h>

class Controle
{
public:
  Controle(int in1_, int in2_, int P_vel_A, int in3_, int in4_, int P_vel_B);
  void pwm(int V_vel_A, int V_vel_B);

private:
  int in1;
  int in2;
  int p_vel_A;
  int vel_A;
  int V_vel_A;
  
  int in3;
  int in4;
  int p_vel_B;
  int vel_B;
  int V_vel_B;
  
  int vel_neg_A;
  int vel_neg_B;
};

class Sensores
{
public:

  Sensores();
  void Leitura(int entrada,int powersensor, int ana_dig, int activemillis, int timereading);

  
  int value;


private:

  int entrada;
  int time,lastime,timereading,activemillis,ana_dig,powersensor;

};

#endif
