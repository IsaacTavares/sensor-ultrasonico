/*
  Autor: Isaac Tavares Ponce
  GitHub: https://github.com/IsaacTavares
  Proyecto: Sensor HC-SR04
  Licencia: MIT
*/


//Entrada pines
#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);           //Inicializa el monitor serial
  pinMode(TRIG_PIN, OUTPUT);    //Pin TRIG como salida
  pinMode(ECHO_PIN, INPUT);     //Pin ECHO como entrada
}

void loop() {
  long duration;
  float distance;

  //Enviar pulso ultrasónico
  digitalWrite(TRIG_PIN, LOW);      //Asegura que el pin TRIG esté en LOW para iniciar limpio
  delayMicroseconds(2);             //Espera 2 microsegundos para estabilizar la señal
  digitalWrite(TRIG_PIN, HIGH);     //Envia un pulso de 10 microsegundos
  delayMicroseconds(10);            //Tiempo suficiente para generar el pulso ultrasónico
  digitalWrite(TRIG_PIN, LOW);      //Termina el pulso; ahora el sensor emite la señal


  //Leer duración del pulso de retorno
  duration = pulseIn(ECHO_PIN, HIGH);

  //Calcular distancia en centímetros
  distance = duration * 0.034 / 2;

  //Mostrar en monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); //Esperar medio segundo antes de la próxima lectura
}