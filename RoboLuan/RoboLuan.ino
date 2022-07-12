// -- PINOS DA PONTE H ------------
#define ENA 10 // MOTOR A
#define IN1 6 // DIREÇÃO MOTOR A 
#define IN2 7 //
#define IN3 8 // DIREÇÃO MOTOR B
#define IN4 9 //
#define ENB 11 // MOTOR B

// -- PINOS DA MATRIZ -------------
#define NEAR A0
#define CLP A1  
#define S5 A2
#define S4 A3
#define S3 A4
#define S2 A5
#define S1 A6

int sensor[5] = {0, 0, 0, 0, 0};
int error, previousError, P, I, D, rightInitSpeed = 120, leftInitSpeed = 140;

double PIDvalue;

float Kp = 0.5;
float Ki = 1.9;
float Kd = 0;

void setup(){
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);

}

void loop(){
  readSensors();

  analogWrite(ENA, 200); // Ambos motores ligam na mesma velocidade
  analogWrite(ENB, 200);



if (digitalRead(CLP)) {
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  
  }

else {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
  
  }

} 

void readSensors(){
  sensor[0] = digitalRead(S1);
  sensor[1] = digitalRead(S2);
  sensor[2] = digitalRead(S3);
  sensor[3] = digitalRead(S4);
  sensor[4] = digitalRead(S5);

  
  if((sensor[0] == HIGH) && (sensor[1] == LOW) && (sensor[2] == LOW) && (sensor[3] == LOW) && (sensor[4] == LOW)){
    error = -4;
  }else if((sensor[0] == HIGH) && (sensor[1] == HIGH) && (sensor[2] == LOW) && (sensor[3] == LOW) && (sensor[4] == LOW)){
    error = -3;
  }else if((sensor[0] == LOW) && (sensor[1] == HIGH) && (sensor[2] == LOW) && (sensor[3] == LOW) && (sensor[4] == LOW)){
    error = -2;
  }else if((sensor[0] == LOW) && (sensor[1] == HIGH) && (sensor[2] == HIGH) && (sensor[3] == LOW) && (sensor[4] == LOW)){
    error = -1;
  }else if((sensor[0] == LOW) && (sensor[1] == LOW) && (sensor[2] == HIGH) && (sensor[3] == LOW) && (sensor[4] == LOW)){
    error = 0;
  }else if((sensor[0] == LOW) && (sensor[1] == LOW) && (sensor[2] == HIGH) && (sensor[3] == HIGH) && (sensor[4] == LOW)){
    error = 1;
  }else if((sensor[0] == LOW) && (sensor[1] == LOW) && (sensor[2] == LOW) && (sensor[3] == HIGH) && (sensor[4] == LOW)){
    error = 2;
  }else if((sensor[0] == LOW) && (sensor[1] == LOW) && (sensor[2] == LOW) && (sensor[3] == HIGH) && (sensor[4] == HIGH)){
    error = 3;
  }else if((sensor[0] == LOW) && (sensor[1] == LOW) && (sensor[2] == LOW) && (sensor[3] == LOW) && (sensor[4] == HIGH)){
    error = 4;
  }else if((sensor[0] == LOW) && (sensor[1] == LOW) && (sensor[2] == LOW) && (sensor[3] == LOW) && (sensor[4] == LOW)){
    error = 0;
  }
}
