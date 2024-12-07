const int PIN_BUZZER = 5;
const int PIN_PIR = 23;
const int PIN_BUTTON = 14;
// #define PIN_BUTTON 14  <- antiga       

// pins do sensor ultrassonico
const int PIN_TRIGGER = 13;  
const int PIN_ECHO = 12;

int contador=0;
long duration;             
int distancia;             

void setup() {
  Serial.begin(115200); /* Define baud rate for serial communication */
  pinMode(PIN_BUZZER,OUTPUT);
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_BUTTON,INPUT_PULLUP);
  pinMode(PIN_TRIGGER, OUTPUT);    
  pinMode(PIN_ECHO, INPUT);        

  //Serial.println("Sistema de Monitoramento de Dispenser Iniciado!");
  //Serial.print("Sensor de movimento Ready!\n");
}

void loop() {
  // Gera um pulso de 10 microssegundos no pino Trigger para iniciar a medição
  digitalWrite(PIN_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);

  // Lê a duração do pulso no pino Echo
  duration = pulseIn(PIN_ECHO, HIGH);
  
  // Calcula a distância em centímetros
  distancia = duration * 0.034 / 2;

  if (distancia > 0 && distancia <= 8){
    Serial.println("Pessoa detectada próxima ao dispenser");

    // Verifica se o botão foi pressionado e está detectando movimento atraves do sensor PIR para simular o uso do dispenser
    if ( (digitalRead(PIN_PIR) == HIGH) && (digitalRead(PIN_BUTTON) == LOW)) {
                delay(50); // debounce 

                digitalWrite(PIN_BUZZER,HIGH);
                contador++; // Incrementa o contador de usos do dispenser
                Serial.print("Dispenser utilizado. Total de usos: ");
                Serial.println(contador);
                // Aguarda até que o botão seja solto
                while (digitalRead(PIN_BUTTON) == LOW);
            } 
    else{
        digitalWrite(PIN_BUZZER,LOW);
    }

  }
  delay(100);  // Aguarda um pouco antes da próxima verificação

}
