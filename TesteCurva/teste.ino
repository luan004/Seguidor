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
#define S1 5

// -- ARRAY DOS SENSORES ----------
int s[6] = {0, 0, 0, 0, 0, 0};

int velocidade = 60;
int reducao = 10;

void setup() {
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

  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);

}

void loop() {
  lerMatriz();
  controleMotor();
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
}

void lerMatriz() {
  s[0] = digitalRead(CLP);
  s[1] = digitalRead(S1);
  s[2] = digitalRead(S2);
  s[3] = digitalRead(S3);
  s[4] = digitalRead(S4);
  s[5] = digitalRead(S5);
}

void controleMotor(){
    // BOTAO CLP
  if (s[0] == HIGH) {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }

  // 0 0 0 0 0
  else if( (s[1] == LOW) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == LOW) && (s[5] == LOW)){
    Serial.println("0 0 0 0 0");
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }


  // -- VIRAR PARA A DIREITA ---------------------------

  // 1 1 0 0 0
  else if( (s[1] == HIGH) && (s[2] == HIGH) && (s[3] == LOW) && (s[4] == LOW) && (s[5] == LOW)){
    Serial.println("1 1 0 0 0");
    analogWrite(ENA, velocidade - (reducao*3));
    analogWrite(ENB, velocidade);
  }
  // 1 0 0 0 0
  else if( (s[1] == HIGH) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == LOW) && (s[5] == LOW)){
    Serial.println("1 0 0 0 0");
    analogWrite(ENA, velocidade - (reducao*5));
    analogWrite(ENB, velocidade);
  }
  // 0 1 1 0 0
  else if((s[1] == LOW) && (s[2] == HIGH) && (s[3] == HIGH) && (s[4] == LOW) && (s[5] == LOW)){
    Serial.println("0 1 1 0 0");
    analogWrite(ENA, velocidade - reducao);
    analogWrite(ENB, velocidade);
  }
  // 0 1 0 0 0
  else if((s[1] == LOW) && (s[2] == HIGH) && (s[3] == LOW) && (s[4] == LOW) && (s[5] == LOW)){
    Serial.println("0 1 0 0 0");
    analogWrite(ENA, velocidade - (reducao*2));
    analogWrite(ENB, velocidade);
  }


  
  
  // 0 0 1 0 0 -- RETO -------------------------------------------
  else if((s[1] == LOW) && (s[2] == LOW) && (s[3] == HIGH) && (s[4] == LOW) && (s[5] == LOW)){
    Serial.println("0 0 1 0 0");
    analogWrite(ENA, velocidade);
    analogWrite(ENB, velocidade);
  } // -------------------------------------------------------




  // -- VIRAR PARA A DIREITA ---------------------------
  // 0 0 1 1 0
  else if( (s[1] == LOW) && (s[2] == LOW) && (s[3] == HIGH) && (s[4] == HIGH) && (s[5] == LOW)){
    Serial.println("0 0 1 1 0");
    analogWrite(ENA, velocidade);
    analogWrite(ENB, velocidade - reducao);
  }
  // 0 0 0 1 0
  else if((s[1] == LOW) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == HIGH) && (s[5] == LOW)){
    Serial.println("0 0 0 1 0");
    analogWrite(ENA, velocidade);
    analogWrite(ENB, velocidade - (reducao*2));
  }
  // 0 0 0 1 1
  else if((s[1] == LOW) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == HIGH) && (s[5] == HIGH)){
    Serial.println("0 0 0 1 1");
    analogWrite(ENA, velocidade);
    analogWrite(ENB, velocidade - (reducao*3));
  }
  // 0 0 0 0 1
  else if((s[1] == LOW) && (s[2] == LOW) && (s[3] == LOW) && (s[4] == LOW) && (s[5] == HIGH)){
    Serial.println("0 0 0 0 1");
    analogWrite(ENA, velocidade);
    analogWrite(ENB, velocidade - (reducao*5));
  }

}
