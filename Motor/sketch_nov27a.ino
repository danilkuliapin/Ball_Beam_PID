const int stepPin = 12;
const int dirPin  = 14;

const int buttonPin = 0; // BOOT = GPIO0

bool direction = false;    // текущее направление
bool lastState = HIGH;     // состояние кнопки при последней проверке

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP); // BOOT замыкает на GND

  digitalWrite(dirPin, direction);
}

void loop() {

  bool currentState = digitalRead(buttonPin);

  // --- Обнаружение нажатия (переход HIGH → LOW) ---
  if (lastState == HIGH && currentState == LOW) {
    direction = !direction;                 // меняем направление
    digitalWrite(dirPin, direction);        // отправляем на драйвер
    delay(200);                             // антидребезг
  }

  lastState = currentState;

  // --- Мотор крутится постоянно ---
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
}
