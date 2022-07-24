// -- PINOS DA PONTE H ------------
#define ENA 10 // MOTOR A (ESQUERDO)
#define ENB 11 // MOTOR B (DIREITO)

#define IN1 6 // DIREÇÃO MOTOR A (ESQUERDO)
#define IN2 7 //
#define IN3 8 // DIREÇÃO MOTOR B (DIREITO)
#define IN4 9 //

// -- PINOS DA MATRIZ -------------
#define NEAR A0
#define CLP A1  
#define S5 A2
#define S4 A3
#define S3 A4
#define S2 A5
#define S1 A6

// -- ARRAY DOS SENSORES ----------
int s[5] = {0, 0, 0, 0, 0};

void setup(){
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(CLP, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);

}

void loop(){
  lerMatriz();
  controleMotor();

} 

void lerMatriz(){
  s[0] = digitalRead(S1);
  s[1] = digitalRead(S2);
  s[2] = digitalRead(S3);
  s[3] = digitalRead(S4);
  s[4] = digitalRead(S5); 
}

void controleMotor(){
    // BOTAO CLP
  if (digitalRead(CLP)) {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }


  // -- VIRAR PARA A DIREITA ---------------------------

  // 1 0 0 0 0
  else if( (s[0] == HIGH) && (s[1] == LOW) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == LOW)){
    analogWrite(ENA, 100);
    analogWrite(ENB, 140);
  }
  // 1 1 0 0 0
  else if( (s[0] == HIGH) && (s[1] == HIGH) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == LOW)){
    analogWrite(ENA, 110);
    analogWrite(ENB, 140);
  }
  // 0 1 0 0 0
  else if((s[0] == LOW) && (s[1] == HIGH) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == LOW)){
    analogWrite(ENA, 120);
    analogWrite(ENB, 140);
  }
  // 0 1 1 0 0
  else if((s[0] == LOW) && (s[1] == HIGH) && (s[2] == HIGH) && (s[3] == LOW) && (s[4] == LOW)){
    analogWrite(ENA, 130);
    analogWrite(ENB, 140);
  }


  
  
  // 0 0 1 0 0 -- RETO -------------------------------------------
  else if((s[0] == LOW) && (s[1] == LOW) && (s[2] == HIGH) && (s[3] == LOW) && (s[4] == LOW)){
    analogWrite(ENA, 140);
    analogWrite(ENB, 140);
  } // -------------------------------------------------------




  // -- VIRAR PARA A DIREITA ---------------------------
  // 0 0 1 1 0
  else if( (s[0] == LOW) && (s[1] == LOW) && (s[2] == HIGH) && (s[3] == HIGH) && (s[4] == LOW)){
    analogWrite(ENA, 140);
    analogWrite(ENB, 130);
  }
  // 0 0 0 1 0
  else if((s[0] == LOW) && (s[1] == LOW) && (s[2] == LOW) && (s[3] == HIGH) && (s[4] == LOW)){
    analogWrite(ENA, 140);
    analogWrite(ENB, 120);
  }
  // 0 0 0 1 1
  else if((s[0] == LOW) && (s[1] == LOW) && (s[2] == LOW) && (s[3] == HIGH) && (s[4] == HIGH)){
    analogWrite(ENA, 140);
    analogWrite(ENB, 110);
  }
  // 0 0 0 0 1
  else if((s[0] == LOW) && (s[1] == LOW) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == HIGH)){
    analogWrite(ENA, 140);
    analogWrite(ENB, 100);
  }

  }
