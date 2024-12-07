const int PIN_BUZZER = 5;
const int PIN_PIR = 23;
const int PIN_BUTTON = 14;
const int PIN_TRIGGER = 13;
const int PIN_ECHO = 12;

int contador = 0;
long duration;
int distancia;
bool buttonState = HIGH; // Estado anterior do botão
bool pirState = LOW;     // Estado anterior do PIR

void setup() {
  Serial.begin(115200); // Comunicação serial
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  Serial.println("Sistema de Monitoramento de Dispenser Iniciado!");
  Serial.println("Sensor de movimento Ready!");
}

void loop() {
  // Medição de distância com sensor ultrassônico
  digitalWrite(PIN_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);
  distancia = duration * 0.034 / 2; // Conversão para centímetros

  if (distancia > 0 && distancia <= 10) {
    Serial.print("Pessoa detectada a ");
    Serial.print(distancia);
    Serial.println(" cm do dispenser.");

    // Verifica se há movimento detectado pelo PIR
    pirState = digitalRead(PIN_PIR);
    if (pirState == HIGH) {
      Serial.println("Movimento detectado pelo sensor PIR.");
    }

    // Verifica se o botão foi pressionado
    if (digitalRead(PIN_BUTTON) == LOW && buttonState == HIGH) {
      delay(50); // Debounce
      buttonState = LOW; // Atualiza o estado do botão
      contador++;
      digitalWrite(PIN_BUZZER, HIGH); // Ativa o buzzer
      Serial.print("Dispenser utilizado. Total de usos: ");
      Serial.println(contador);

      // Aguarda o botão ser liberado
      while (digitalRead(PIN_BUTTON) == LOW);
    } else if (digitalRead(PIN_BUTTON) == HIGH) {
      buttonState = HIGH; // Atualiza o estado do botão
      digitalWrite(PIN_BUZZER, LOW); // Desativa o buzzer
    }
  }

  delay(100); // Aguarda antes da próxima leitura
}
