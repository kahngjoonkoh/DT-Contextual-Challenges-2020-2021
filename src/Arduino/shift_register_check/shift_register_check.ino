const int SER = 2;
const int SRCLK = 3;
const int RCLK = 4;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  
  Serial.begin(9600);
  delay(1000);
  display(1);
  delay(1000);
  display(2);
  delay(1000);
  display(3);
}

void loop() {
  
}
void display(byte b) {
  int binaryValue;
  Serial.println(b);
  for (int i = 0; i <= 7; i++){
    binaryValue = bitRead(b, i);
    Serial.println(binaryValue);
    digitalWrite(SER, binaryValue);
    digitalWrite(SRCLK, LOW);
    digitalWrite(SRCLK, HIGH);
  }
  digitalWrite(RCLK, LOW);
  digitalWrite(RCLK, HIGH);
}
