// created 11/27/2024
// view readme.md for wiring information and setup

#include <Keypad.h>

int x = 200;

const int speaker = 11;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the two-dimensional array on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
int duelOfFatesMelody[] = {
  659, 659, 739, 659, 739, 784, 740, 659, 659, 739, 784, 740, 659, 659, 739, 784, 740, 698, 
  659, 739, 784, 740, 659, 784, 740, 698, 659, 739, 784, 740, 784, 740, 659, 659, 739, 784,
  740, 784, 740, 698, 659, 739, 784, 740, 784, 698, 659, 739, 784, 740, 784, 740, 659, 659,
  739, 784, 740, 784, 698, 659, 739, 784, 740, 784, 740, 698
};

int duelOfFatesDurations[] = {
  400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400,
  400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400,
  400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400
};

int starWarsMainMelody[] = {
  659, 659, 659, 349, 523, 659, 784, 784, 784, 698, 659, 523, 440, 440, 440, 440, // Main Theme opening
  349, 523, 659, 784, 784, 784, 698, 659, 523, 440, 440, 440, 440, 349, 523, 659
};

int starWarsMainDurations[] = {
  500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500,
  500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500
};

int imperial_march_melody[] = {
  440, 440, 440, 349, 523, 440, 349, 523, 440, // Opening notes
  659, 659, 659, 698, 523, 415, 349, 523, 440 // Second phrase
};

int imperial_march_durations[] = {
  500, 500, 500, 350, 150, 500, 350, 150, 1000, // Durations for first phrase
  500, 500, 500, 350, 150, 500, 350, 150, 1000 // Durations for second phrase
};

int cantinaBandMelody[] = {
  659, 659, 659, 659, 587, 587, 523, 523, 440, 440, 523, 523, 587, 587, 659, 659,
  698, 698, 784, 784, 880, 880, 987, 987, 1046, 1046, 1174, 1174, 1318, 1318, 1396
};

int cantinaBandDurations[] = {
  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300
};

int melody[] = {
  261,   // C4
  293,   // D4
  329,   // E4
  349,   // F4
  392,   // G4
  440,   // A4
  493,    // B4
  523,   // C5
  587,   // D5
  659,   // E5
  698,   // F5
  784,   // G5
  880,   // A5
  987    // B5
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
}
  
void loop(){
  char customKey = customKeypad.getKey();

  switch(customKey){
    case '*':
      x = 200;
      break;
   case '#':
      x = 800;
      break;
    case '1':
      tone(speaker, melody[0], x);
      break;
    case '2':
      tone(speaker, melody[1], x);
      break;
    case '3':
      tone(speaker, melody[2], x);
      break;
    case  '4':
      tone(speaker, melody[3], x);
      break;
    case '5':
      tone(speaker, melody[4], x);
      break;
    case '6':
      tone(speaker, melody[5], x);
      break;
    case '7':
      tone(speaker, melody[6], x);
      break;
    case  '8':
      tone(speaker, melody[7], x);
      break;
    case '9':
      tone(speaker, melody[8], x);
      break;
    case '0':
      tone(speaker, melody[9], x);
      break;
    case 'A':
      playsong(duelOfFatesMelody, duelOfFatesDurations, sizeof(duelOfFatesMelody) / sizeof(duelOfFatesMelody[0]));
      break;
    case 'B':
      playsong(starWarsMainMelody, starWarsMainDurations, sizeof(starWarsMainMelody) / sizeof(starWarsMainMelody[0]));
      break;
    case 'C':
      playsong(imperial_march_melody, imperial_march_durations, sizeof(imperial_march_melody) / sizeof(imperial_march_melody[0]));
      break;
    case 'D':
      playsong(cantinaBandMelody, cantinaBandDurations, sizeof(cantinaBandMelody) / sizeof(cantinaBandMelody[0]));
      break;
  }
}

int playsong(int melody[], int duration[], int length) {
  for (int i = 0; i < length; i++){
    int note = melody[i];
    int noteduration = duration[i];
    tone(speaker, note, noteduration);
    delay(noteduration + 50); 
  }
}
