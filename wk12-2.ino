byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,1,1,0,0 }   // = 9
                             };
byte pin_number[8] = {2,3,4,5,6,7,8,9};
const int buttonPin = 10;
int present_buttonState = 0, previous_buttonState = 0;
int num = 0;

void setup() {               
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, 0);  // 關閉小數點
  digitalWrite(buttonPin,HIGH);
  pinMode(buttonPin,INPUT_PULLUP);
}

void sevenSegWrite(byte digit) {
  for (byte seg = 0; seg < 7; ++seg) {
    digitalWrite(pin_number[seg], seven_seg_digits[digit][seg]);
  }
}

void loop() {
  present_buttonState = digitalRead(10);

  if(previous_buttonState == HIGH && present_buttonState == LOW){
     num ++;
     previous_buttonState = LOW;
  }

  if(num > 9){
     num = 0;
  }

  if(present_buttonState == HIGH){
       previous_buttonState = HIGH;
  }

  sevenSegWrite(num);
}
