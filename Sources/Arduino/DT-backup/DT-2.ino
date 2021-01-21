// with the help from http://masteringarduino.blogspot.com/2013/10/fastest-and-smallest-digitalread-and.html
// This speeds up the digitalRead speed by 60 times, and the digitalWrite speed by 28 times.

#define portOfPin(P)\
  (((P)>=0&&(P)<8)?&PORTD:(((P)>7&&(P)<14)?&PORTB:&PORTC))
#define ddrOfPin(P)\
  (((P)>=0&&(P)<8)?&DDRD:(((P)>7&&(P)<14)?&DDRB:&DDRC))
#define pinOfPin(P)\
  (((P)>=0&&(P)<8)?&PIND:(((P)>7&&(P)<14)?&PINB:&PINC))
#define pinIndex(P)((uint8_t)(P>13?P-14:P&7))
#define pinMask(P)((uint8_t)(1<<pinIndex(P)))

#define pinAsInput(P) *(ddrOfPin(P))&=~pinMask(P)
#define pinAsInputPullUp(P) *(ddrOfPin(P))&=~pinMask(P);digitalHigh(P)
#define pinAsOutput(P) *(ddrOfPin(P))|=pinMask(P)
#define digitalLow(P) *(portOfPin(P))&=~pinMask(P)
#define digitalHigh(P) *(portOfPin(P))|=pinMask(P)
#define isHigh(P)((*(pinOfPin(P))& pinMask(P))>0)
#define isLow(P)((*(pinOfPin(P))& pinMask(P))==0)
#define digitalState(P)((uint8_t)isHigh(P))

// pin number constants
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

// The rest time that is used for debugging
const int REST = 0;

// constant byte data that is made easier to understand by assigning them to the words
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

// a global variable that contains three bytes for each of the digits.(The last digit is always a 'C')
byte digitList[3];


// sets the pinmodes
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

  // Used for debugging
  Serial.begin(9600);
}


// The recursive loop.
// If the 'past' button is pressed, it will display past temperatures
// If the 'future' button is pressed, it will display future temperatures
// If no button is pressed, it will display current temperatures
void loop() {
  if (isHigh(BUTTON1)){
    int argumentArray1[8] = {12, 12, 12, 12, 260, 261, 262, 263};
    int argumentArray2[8] = {123, 456, 789, 123, 12, 23, 43, 12};
    int argumentArray3[8] = {123, 123, 432, 345, 654, 568, 22, 26};
        
    totalDisplay(argumentArray1, 1);
    totalDisplay(argumentArray2, 2);
    totalDisplay(argumentArray3, 3);
  }
  else if (isHigh(BUTTON2)){
    int argumentArray1[8] = {256, 257, 258, 259, 260, 261, 262, 263};
    int argumentArray2[8] = {123, 456, 789, 123, 12, 23, 43, 12};
    int argumentArray3[8] = {123, 123, 432, 345, 654, 568, 22, 26};
      
    totalDisplay(argumentArray1, 1);
    totalDisplay(argumentArray2, 2);
    totalDisplay(argumentArray3, 3);
  }
  else{
    int argumentArray1[8] = {256, 257, 258, 259, 260, 261, 262, 263};
    int argumentArray2[8] = {123, 456, 789, 123, 12, 23, 43, 12};
    int argumentArray3[8] = {123, 123, 432, 345, 654, 568, 22, 26};
        
    totalDisplay(argumentArray1, 1);
    totalDisplay(argumentArray2, 2);
    totalDisplay(argumentArray3, 3);
  }

}

void shift(byte a, int n) {
  for (int i = 0; i <= 7; i++){
    int binaryValue = bitRead(a, i);
    if (n==1){
      digitalWrite(SER1, binaryValue);
      digitalLow(SRCLK1);
      digitalHigh(SRCLK1);
    }
    else if (n==2){
      digitalWrite(SER2, binaryValue);
      digitalLow(SRCLK2);
      digitalHigh(SRCLK2);
    }
    else if (n==3){
      digitalWrite(SER3, binaryValue);
      digitalLow(SRCLK3);
      digitalHigh(SRCLK3);
    }
  }   
}


void fndShow(int n){
  if (n==1){
    digitalLow(RCLK1);
    digitalHigh(RCLK1);
  }
  else if (n==2){
    digitalLow(RCLK2);
    digitalHigh(RCLK2);
  }
  else if (n==3){
    digitalLow(RCLK3);
    digitalHigh(RCLK3); 
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
