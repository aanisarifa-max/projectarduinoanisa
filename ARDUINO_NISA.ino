int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

int tombol1 = 8; // kiri ke kanan
int tombol2 = 9; // kanan ke kiri
int potPin  = A0; // pin potensiometer

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(tombol1, INPUT);
  pinMode(tombol2, INPUT);

  Serial.begin(9600); // untuk lihat nilai potensiometer (opsional)
}

void loop() {
  int tombol1State = digitalRead(tombol1);
  int tombol2State = digitalRead(tombol2);

  // Baca nilai potensiometer (0–1023)
  int potValue = analogRead(potPin);

  // Ubah menjadi nilai delay (semakin besar pot, semakin lambat)
  int jeda = map(potValue, 0, 1023, 50, 500);

  // Semua LED mati dulu
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  // Tombol 1 ditekan → kiri ke kanan
  if (tombol1State == HIGH) {
    digitalWrite(led1, HIGH);
    delay(jeda);
    digitalWrite(led1, LOW);
    digitalWrite(led3, HIGH);
    delay(jeda);
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    delay(jeda);
    digitalWrite(led2, LOW);
    digitalWrite(led4, HIGH);
    delay(jeda);
    digitalWrite(led4, LOW);
  }

  // Tombol 2 ditekan → kanan ke kiri
  if (tombol2State == HIGH) {
    digitalWrite(led4, HIGH);
    delay(jeda);
    digitalWrite(led4, LOW);
    digitalWrite(led3, HIGH);
    delay(jeda);
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    delay(jeda);
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    delay(jeda);
    digitalWrite(led1, LOW);
  }

  // Tampilkan nilai potensiometer di serial monitor (opsional)
  Serial.println(jeda);
}