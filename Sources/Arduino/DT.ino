const int SER1 = 2;
const int SRCLK1 = 3;
const int RCLK1 = 4;

const int SER2 = 5;
const int SRCLK2 = 6;
const int RCLK2 = 7;

const int SER3 = 8;
const int SRCLK3 = 9;
const int RCLK3 = 10;

const int SER4 = 11;
const int SRCLK4 =12;
const int RCLK4 = 13;

const int BUTTON1 = A0;
const int BUTTON2 = A1;

const int REST = 0;

const byte one = 0x60;  // 0110 0000
const byte two = 0xDA;  // 1101 1010
const byte three = 0xF2;  // 1111 0010
const byte four = 0x66;  // 0110 0110
const byte five = 0xB6;  // 1011 0110
const byte six = 0xBE;  // 1011 1110
const byte seven = 0xE0;  // 1110 0000
const byte eight = 0xFE; // 1111 1110
const byte nine = 0xF6;  // 1111 0110
const byte zero = 0xFC;  // 1111 1100
const byte none = 0x00;
const byte C = 0x9C;  // 1001 1100

const int TempMatrix[25][3] = {{123,456,789},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

byte digitList[3];


void setup() {
  pinMode(SER1, OUTPUT);
  pinMode(SRCLK1, OUTPUT);
  pinMode(RCLK1, OUTPUT);
  pinMode(SER2, OUTPUT);
  pinMode(SRCLK2, OUTPUT);
  pinMode(RCLK2, OUTPUT);
  pinMode(SER3, OUTPUT);
  pinMode(SRCLK3, OUTPUT);
  pinMode(RCLK3, OUTPUT);
  pinMode(SER4, OUTPUT);
  pinMode(SRCLK4, OUTPUT);
  pinMode(RCLK4, OUTPUT);
  
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  int argumentArray1[8] = {256, 257, 258, 259, 260, 261, 262, 263};
  totalDisplay(argumentArray1, 1);
  int argumentArray2[8] = {123, 456, 789, 123, 12, 23, 43, 12};
  totalDisplay(argumentArray2, 2);
  int argumentArray3[8] = {123, 123, 432, 345, 654, 568, 22, 26};
  totalDisplay(argumentArray3, 3);
}

void shift(byte a, int n) {
  for (int i = 0; i <= 7; i++){
    int binaryValue = bitRead(a, i);
    if (n==1){
      digitalWrite(SER1, binaryValue);
      digitalWrite(SRCLK1, LOW);
      digitalWrite(SRCLK1, HIGH);
    }
    else if (n==2){
      digitalWrite(SER2, binaryValue);
      digitalWrite(SRCLK2, LOW);
      digitalWrite(SRCLK2, HIGH);
    }
    else if (n==3){
      digitalWrite(SER3, binaryValue);
      digitalWrite(SRCLK3, LOW);
      digitalWrite(SRCLK3, HIGH);
    }
  }   
}


void fndShow(int n){
  if (n==1){
    digitalWrite(RCLK1, LOW);
    digitalWrite(RCLK1, HIGH);
  }
  else if (n==2){
    digitalWrite(RCLK2, LOW);
    digitalWrite(RCLK2, HIGH);
  }
  else if (n==3){
    digitalWrite(RCLK3, LOW);
    digitalWrite(RCLK3, HIGH); 
  }
}


void totalDisplay(int inputIntegers[], int n){
  byte tempList[8][3];
  for (int i=0;i<8;i++){
    eachDigit(inputIntegers[i]);
    for (int j=0;j<3;j++){
      tempList[i][j] = digitList[j];
    }
  }
  fndDisplay(tempList, n);
}


void fndDisplay(byte inputByte[8][3], int n){ //byte arrays
  for (int j=0;j<4;j++){
    shift(inputByte[j][0],n);
    shift(inputByte[j+4][0],n);
    shift(68*j,n);
    fndShow(n);
    NOP(REST);
    shift(inputByte[j][1]+1,n);
    shift(inputByte[j+4][1]+1,n);
    shift(68*j+17,n);
    fndShow(n);
    NOP(REST);
    shift(inputByte[j][2],n);
    shift(inputByte[j+4][2],n);
    shift(68*j+34,n);
    fndShow(n);
    NOP(REST);
    shift(C,n);
    shift(C,n);
    shift(68*j+51,n);
    fndShow(n);
  }
  shift(none,n);
  shift(none,n);
  shift(0xFF,n);
  fndShow(n);
}


void eachDigit(int x){
  String s = String(x);
  if (x<100){
    digitList[0] = none;
    digitList[1] = convertDigit(s[0]);
    digitList[2] = convertDigit(s[1]);
  }
  else{
    digitList[0] = convertDigit(s[0]);
    digitList[1] = convertDigit(s[1]);
    digitList[2] = convertDigit(s[2]);
  }
}

byte convertDigit(char c){
  switch (c){
    case '1':
      return one;
      break;
    case '2':
      return two;
      break;
    case '3':
      return three;
      break;
    case '4':
      return four;
      break;
    case '5':
      return five;
      break;
    case '6':
      return six;
      break;
    case '7':
      return seven;
      break;
    case '8':
      return eight;
      break;
    case '9':
      return nine;
      break;
    case '0':
      return zero;
  }
}

void NOP(int val){
  for (int i=0;i<val;i++){
    __asm__("nop\n\t");
  }
}
