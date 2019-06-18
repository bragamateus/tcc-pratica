#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

bool leituraSensor;
//bool leituraAnterior;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  while (!Serial);
  Serial.println("Olá Mundo");

  //Sensor
  pinMode(8, INPUT);

  //Atuador
  pinMode(12, OUTPUT);

  //LEDs
  pinMode(5, OUTPUT);  //vermelho

  pinMode(6, OUTPUT);  //verde
  pinMode(7, OUTPUT);  //amarelo

  //SINALIZAÇÃO INICIAL
  digitalWrite (5, HIGH);
  delay(1000);
  digitalWrite (6, HIGH);
  delay(1000);
  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
}

void loop() {

  leituraSensor = digitalRead(8);

  if (leituraSensor == HIGH) {

    //No estado seco
    Serial.println("Solo Seco");
    mySerial.println ("AT+SEND FFFFF");
    digitalWrite(5, HIGH);  //vermelho
    digitalWrite(6, LOW);   //verde

    //Aciona o solenoide
    digitalWrite(12, HIGH);   //rele / válvula / solenoide / bomba
    delay(1000);
    digitalWrite(12, LOW);   //rele / válvula / solenoide / bomba
    delay(5000);

    }else {
      //No estado úmido
      Serial.println("Solo Úmido");
      mySerial.println ("AT+SEND 11111");
      digitalWrite(5, LOW);   //vermelho
      digitalWrite(6, HIGH);  //verde
    }

  //Ao entrar no estado seco
  //  if (leituraSensor && !leituraAnterior) {
  //     delay(5000);
  //     digitalWrite(5, LOW);   //vermelho
  //     digitalWrite(6, HIGH);  //amarelo
  //
  //     while (digitalRead(8)) {
  //        digitalWrite(12, HIGH);   //rele / válvula / solenoide / bomba
  //        delay(500);
  //        digitalWrite(12, LOW);   //rele / válvula / solenoide / bomba
  //
  //        delay(10000);
  //     }
  //     digitalWrite(6, LOW);  //amarelo
  //  }
  //
  //  leituraAnterior = leituraSensor;
  //  Serial.println(leituraSensor);
  delay(5000);
}