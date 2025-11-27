// Піни підключення US-015
const int trigPin = 9; // Пін для Trig
const int echoPin = 10; // Пін для Echo

// Змінна для зберігання відстані
long duration;
float distance;

void setup() {
  // Налаштовуємо серійний порт для виводу даних
  Serial.begin(9600);
  
  // Налаштовуємо піни
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Створюємо короткий імпульс для запуску ультразвуку
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Читаємо час від Echo піна
  duration = pulseIn(echoPin, HIGH);
  
  // Обчислюємо відстань (в см)
  distance = duration * 0.0343 / 2;
  
  // Виводимо відстань у серійний монітор
  Serial.print("Відстань: ");
  Serial.print(distance);
  Serial.println(" см");
  
  delay(500); // Затримка перед наступним вимірюванням
}