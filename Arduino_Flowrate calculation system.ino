#define kpa2atm1 0.00986923267
#define kpa2atm2 0.00986923267
#define kpa2atm3 0.00986923267
#define cd 0.8
#define Ev 10
#define Y 6
#define gc 0.7
#define p 0.4
#define a 0.5
#define tf 10
#define d1 0.05
#define LM35 A1


// pin defs
int pressurePin1 = 0;
int pressurePin2 = 2;
int pressurePin3 = 3;

// variables

int val1;
float pkPa1; // pressure in kPa
float pAtm1; // pressure in Atm
int val2;
float pkPa2; // pressure in kPa
float pAtm2; // pressure in Atm
int val3;
float pkPa3; // pressure in kPa
float pAtm3; // pressure in Atm


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  

  /* get the pressure */
  val1 = analogRead(pressurePin1);
  pkPa1 = ((float)val1/(float)1023+0.095)/0.009;
  pAtm1 = kpa2atm1*pkPa1;

  val2 = analogRead(pressurePin2);
  pkPa2 = ((float)val2/(float)1023+0.095)/0.009;
  pAtm2 = kpa2atm2*pkPa2;

  val3 = analogRead(pressurePin3);
  pkPa3 = ((float)val3/(float)1023+0.095)/0.009;
  pAtm3 = kpa2atm3*pkPa3;

  //Differential Pressure
  float diff = abs(pAtm3 - pAtm2);

  //Sensor Suhu
  int vals = analogRead(LM35);
  float mv = (vals/1024.0)*5000;
  int Cel = mv/10;

  //Kalkulasi flowrate
  float d=d1*(1+a*(Cel-tf));
  float qm=cd*Ev*Y*(3.14/4)*d*d*sqrt(2*gc*p*diff*100);
  
  /* send pressure to serial port */
  Serial.print(pkPa1);
  Serial.print(" kPa ");
  Serial.print(pAtm1);
  Serial.print(" Atm ");
  Serial.print("Differential Pressure = ");
  Serial.print(diff);
  Serial.print(" Cel = ");
  Serial.print(Cel);
  Serial.print(" Flow = ");
  Serial.println(qm);
  delay(1000);
    
}
