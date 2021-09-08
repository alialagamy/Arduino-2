//define variable
 int light1;
 int light2;
 int ledpin1 = 10;
 int ledpin2 = 11;
 int buzzerpin = 12;
 int ldrpin1 = A0;
 int ldrpin2 = A1;
 int count = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(ldrpin1, INPUT);
  pinMode(ldrpin2, INPUT);
}

void loop() {
  Serial.println("Entry Sensor : ");
  Serial.println(light1);
  delay(200);
  Serial.println("Exit Sensor: ");
  Serial.println(light2);
  delay(200);
  Serial.println("Number of people: ");
  Serial.println(count);
  delay(200);
//Entry sensor and Green Led.
light1 = analogRead(ldrpin1);
  if (light1 <= 100){
    tone(buzzerpin, 250);
    delay(200);
    digitalWrite(ledpin1, HIGH);
    delay(200);
    noTone(buzzerpin);
    digitalWrite(ledpin1, LOW);
    count++;
    Serial.println("Person Enter");
    delay(1500); 
}else {
  noTone(buzzerpin);
  digitalWrite(ledpin1, LOW);
  }
//Exit sensor and Red Led.
light2 = analogRead(ldrpin2);
  if (light2 <= 40){
    tone(buzzerpin, 500);
    delay(200);
    digitalWrite(ledpin2, HIGH);
    delay(200);
    noTone(buzzerpin);
    digitalWrite(ledpin2, LOW);
    count--;
    Serial.println("Person Exit");
    delay(1500); 
  }else {
    noTone(buzzerpin);
  digitalWrite(ledpin2, LOW);
  }
 // Count Number Of People
  if (count >=5){
     tone(buzzerpin, 1000);
     digitalWrite(ledpin2, HIGH);
     Serial.println("Complete");
     delay(200);

  }
   else{
      noTone(buzzerpin);
    }
    delay(200);
}
