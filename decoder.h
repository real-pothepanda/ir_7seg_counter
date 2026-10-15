// Digit 1 Pins 
const uint8_t Pin_A1 = 16;
const uint8_t Pin_B1 = 17;
const uint8_t Pin_C1 = 5;
const uint8_t Pin_D1 = 18;
const uint8_t Pin_E1 = 19;
const uint8_t Pin_F1 = 21;
const uint8_t Pin_G1 = 22;

// Digit 2 Pins pati ini libugon mo pa?
const uint8_t Pin_A2 = 33;
const uint8_t Pin_B2 = 25;
const uint8_t Pin_C2 = 26;
const uint8_t Pin_D2 = 27;
const uint8_t Pin_E2 = 14;
const uint8_t Pin_F2 = 12;
const uint8_t Pin_G2 = 23;

const uint8_t digit1Pins[7] = {Pin_A1, Pin_B1, Pin_C1, Pin_D1, Pin_E1, Pin_F1, Pin_G1};
const uint8_t digit2Pins[7] = {Pin_A2, Pin_B2, Pin_C2, Pin_D2, Pin_E2, Pin_F2, Pin_G2};

// porma porma lang ta di para indi maglibog ai sir
const byte patterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0 
  {0, 1, 1, 0, 0, 0, 0}, // 1 
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {0, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8 
  {1, 1, 1, 0, 0, 1, 1}  // 9
};

void setupDecoder() {
  // Ginapanitan ta tanan nga pins as OUTPUT kay para sugoon naton sila mag siga
  for (int i = 0; i < 7; i++) {
    pinMode(digit1Pins[i], OUTPUT); 
    pinMode(digit2Pins[i], OUTPUT);
  }
}

void displayTwoDigits(int number) {
  if (number < 0) number = 0;     // safety shite para di mag-buggy ang esp32 kag ma-praning
  if (number > 99) number = 99;   // duha lang ka digit ni uy, limit ta lang sa 99 para safe sa gisa

  int tens = number / 10; // divide sa tens kuno-kuno bright
  int ones = number % 10; // modulo para sa ones pwerteng pahuway sang utok

  for (int i = 0; i < 7; i++) {  // para sa tens digit
    digitalWrite(digit1Pins[i], patterns[tens][i]);
  }

  for (int i = 0; i < 7; i++) {  // para sa ones digit
    digitalWrite(digit2Pins[i], patterns[ones][i]);
  }
}
// tani di kami magisa sa qna (amen)