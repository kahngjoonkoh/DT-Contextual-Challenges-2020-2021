// with the help from 
// http://masteringarduino.blogspot.com/2013/10/fastest-and-smallest-digitalread-and.html
// This speeds up the digitalRead speed by 60 times, and the digitalWrite speed by 28 times.
#define portOfPin(P)\
  (((P)>=0&&(P)<8)?&PORTD:(((P)>7&&(P)<14)?&PORTB:&PORTC))
#define ddrOfPin(P)\
  (((P)>=0&&(P)<8)?&DDRD:(((P)>7&&(P)<14)?&DDRB:&DDRC))
#define pinOfPin(P)\
  (((P)>=0&&(P)<8)?&PIND:(((P)>7&&(P)<14)?&PINB:&PINC))
#define pinIndex(P)((uint8_t)(P>13?P-14:P&7))
#define pinMask(P)((uint8_t)(1<<pinIndex(P)))

#define digitalLow(P) *(portOfPin(P))&=~pinMask(P)
#define digitalHigh(P) *(portOfPin(P))|=pinMask(P)
#define isHigh(P)((*(pinOfPin(P))& pinMask(P))>0)

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

const int TRIGGER0 = A2;
const int TRIGGER1 = A3;
const int TRIGGER2 = A4;
const int TRIGGER3 = A5;

const int BUTTON1 = A0;
const int BUTTON2 = A1;

// The rest time that is used for debugging
const int REST = 0;

// constant byte data that is made easier 
// to understand by assigning them to the words
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

// a global variable that contains three bytes 
// for each of the digits.(The last digit is always a 'C')
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
}


// The recursive loop.
// If the 'past' button is pressed, it will display past temperatures
// If the 'future' button is pressed, it will display future temperatures
// If no button is pressed, it will display current temperatures
void loop() {
  if (isHigh(BUTTON1)){
    int pastTemp1[8] = {143, 107, 217, 257, 104, 165, 176, 255};
    int pastTemp2[8] = {026, 076, 099, 197, 099, 175, 159, 104};
    int pastTemp3[8] = {085, 172, 089, 006, 148, 181, 218, 155};
        
    displayAll(pastTemp1, 1);
    displayAll(pastTemp2, 2);
    displayAll(pastTemp3, 3);
    singleDisplay(127);
  }
  else if (isHigh(BUTTON2)){
    int futureTemp1[8] = {156, 119, 226, 268, 121, 176, 187, 267};
    int futureTemp2[8] = {049, 091, 113, 213, 111, 190, 169, 121};
    int futureTemp3[8] = {100, 182, 099, 021, 159, 187, 232, 168};
      
    displayAll(futureTemp1, 1);
    displayAll(futureTemp2, 2);
    displayAll(futureTemp3, 3);
    singleDisplay(141);
  }
  else{
    int currentTemp1[8] = {186, 153, 253, 292, 160, 205, 210, 302};
    int currentTemp2[8] = {096, 125, 145, 245, 139, 220, 193, 157};
    int currentTemp3[8] = {140, 208, 132, 067, 188, 213, 261, 191};
    
    displayAll(currentTemp1, 1);
    displayAll(currentTemp2, 2);
    displayAll(currentTemp3, 3);
    singleDisplay(158);
  }
}


// A function that recieves a byte and shifts it bit by bit into the shift register
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
    else if (n==4){
      digitalWrite(SER4, binaryValue);
      digitalLow(SRCLK4);
      digitalHigh(SRCLK4);
    }
  }   
}


// A trigger function that displays a digit on the seven segment
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
  else if (n==4){
    digitalLow(RCLK4);
    digitalHigh(RCLK4); 
  }
}


// A function that recieves an array of integers 
// and displays them in order to eight seven segment displays
void displayAll(int inputIntegers[], int n){
  byte tempList[8][3];
  for (int i=0;i<8;i++){
    eachDigit(inputIntegers[i]);  // Uses the function 'eachDigit()' to convert 
    for (int j=0;j<3;j++){        // an integer value into byte data for each digit
      tempList[i][j] = digitList[j];
    }
  }
  fndDisplay(tempList, n);
}


// A 2D byte array is given and it processes the seven segment displays 
// to light up digit by digit across all the displays
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
  // This part is added in order to fix the error where the last digit 
  // of the fourth seven segment display appeared brighter than all the others.
  shift(none,n);
  shift(none,n);
  shift(0xFF,n);
  fndShow(n);
}


// Used to light up the global temperature display where only one display has to be programmed
void singleDisplay(int inputInteger){
  byte tempList[3];
  eachDigit(inputInteger);
  for (int i=0;i<3;i++){
    tempList[i] = digitList[i];
  }
  shift(tempList[0],4);
  digitalHigh(TRIGGER0);
  fndShow(4);
  digitalLow(TRIGGER0); 
  NOP(REST);
  shift(tempList[1]+1,4);
  digitalHigh(TRIGGER1);
  fndShow(4);
  digitalLow(TRIGGER1); 
  NOP(REST);
  shift(tempList[2],4);
  digitalHigh(TRIGGER2);
  fndShow(4);
  digitalLow(TRIGGER2); 
  NOP(REST);
  shift(C,4);
  digitalHigh(TRIGGER3);
  fndShow(4);
  digitalLow(TRIGGER3); 
  NOP(REST);
  
  shift(none,4);
  digitalHigh(TRIGGER3);
  fndShow(4);
  digitalLow(TRIGGER3); 
  NOP(REST);
}


// A function that converts an integer value into a byte value for each digit
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


// seperated from the 'eachDigit()' function to make clean code.
// basically a part of the 'eachDigit()' function
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


// The 'No OPeration' function that is used with the 'REST' 
// constant when debugging or delaying the display speed.
void NOP(int val){
  for (int i=0;i<val;i++){
    __asm__("nop\n\t");
  }
}
