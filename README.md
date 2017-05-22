// MOTOR CONTROL

Controle Motor(3,4,5,6,7,8); // in1 , in2 , pwma, in3, in4, pmwb


// Control of speed and direction.

Reverse sense occurs with signal switching.

Motor.pwm(200,200);  

Motor.pwm(-255,-255); 


Motor.pwm(0,0); // Stop two motors


// SENSORS-------------------------------------------------------------------

Sensores namesensor; // Utilizing class sensor


int time_reading = 10 // Set read time in Milliseconds

namesensor.Leitura(9,0,1,1,time_reading);  
// Port // Port Sensor Port ONLY DIGITAL PORT 0 - Disables / 1-Active // 0 - Analog / 1 - Digital // 0 - deactivates Millis / 1 - Activates Millis // Millis time - NEED FOR SETTINGS

value_sensor = namesensor.value; // change value_sensor to name your sensor.


Att, Matheus Giovanni Lucena.
contact : matheus.giovanni.lu@gmail.com
phone : +551998333-5919
