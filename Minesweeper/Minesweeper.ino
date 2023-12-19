#include <EEPROM.h>
#include <LiquidCrystal.h>
const byte rs = A2;
const byte en = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5;
const byte d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte lcdIntensityPin = 9;
#define LCD_L 16


#include "LedControl.h"  // Include LedControl library for controlling the LED matrix
const byte dinPin = 12;
const byte clockPin = 13;
const byte loadPin = 10;
const byte xPin = A0; // A0 - analog pin connected to X output
const byte yPin = A1; // A1 - analog pin connected to Y output
const byte pinSW = 2; // digital pin connected to switch output
const byte ledPin = A5; // Pin for the information LED

LedControl lc = LedControl(dinPin, clockPin, loadPin, 1);  // LedControl object to manage the LED matrix


const byte buzzerPin = 11;


const byte flagButtonPin = 3;

const unsigned long flagDebounceDelay = 50;
bool flagButtonState = HIGH; // The previous state of the button (HIGH when not pressed due to INPUT_PULLUP)
bool flagButtonReading = HIGH; // The current reading from the button pin
bool flagLastReading = HIGH;
unsigned long flagLastDebounceTime = 0; // Keeps track of the last time the button was pressed



// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- BOMB GAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


// byte matrixBrightness = 2; // Variable to set the brightness level of the matrix

// Variables to track the current and previous positions of the joystick-controlled LED
// byte xPos = 0;
// byte yPos = 0;
// byte xLastPos = 0;
// byte yLastPos = 0;


const byte matrixSize = 8;         // Size of the LED matrix
byte numBombs = 8;
const byte bombValue = 'B';
const byte playerValue = 'P';
bool matrixChanged = true;         // Flag to track if the matrix display needs updating

const short numberBlinkInterval = 200;
const short numberBlinkPeriod = 2*10*numberBlinkInterval;
unsigned long lastNumberBlinkPeriodTime = 0;
unsigned long lastNumberBlinkToggleTime = 0;
unsigned long currentNumberBlinkToggleTime = 0;
byte numberBlinkCounter = 0;
bool numberBlinkState = false;
const byte periodUnits = 20;
bool numberBlinkRest = true;
#define EXPLOSION 14
#define VICTORY 5

#define EASY_NUM_BOMBS 4
#define MEDIUM_NUM_BOMBS 8
#define HARD_NUM_BOMBS 10
#define MEGA_NUM_BOMBS 40

typedef struct {
  byte value = 0;
  // bool explored = false;
  byte blinkCounter = 0;
  // bool numBlinkState = false;
  // bool flagged = false;
  byte flags = 0; // ___ (000-111) holds 3 flags, {flagged*100+blinkState*10+explored}
} tGameMap;

// tGameMap gameMap[matrixSize][matrixSize];





bool blinkState = 1;
const unsigned short blinkInterval = 750;
unsigned long lastBlinkToggleTime = 0;
unsigned long currentBlinkToggleTime = 0;


bool bombBlinkState = true;
const byte bombBlinkInterval = 50; // Bomb blink interval: very fast blinking (milliseconds)
unsigned long lastBombBlinktoggleTime = 0; // Used for timing the bomb blinks 

// #define NOTE_C4 261 // C4 note frequency
// #define NOTE_E3 164 // E3 note frequency
// #define NOTE_G3 196 // G3 note frequency
// #define NOTE_A3 220 // A3 note frequency
// #define NOTE_D4 293 // D4 note frequency
// #define NOTE_F4 349 // F4 note frequency
// #define NOTE_B3 247 // B3 note frequency
// #define NOTE_G4 392 // G4 note frequency

// short melody[] = {NOTE_C4, NOTE_E3, NOTE_G3, NOTE_A3, NOTE_D4, NOTE_F4, NOTE_B3, NOTE_G4};
// short noteDuration = 1000; // in milliseconds


bool gameOver = false;

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

bool paused = false;
unsigned short number = 0; // In-game timer
unsigned long lastIncrement = 0;
const unsigned short delayCount = 1000;



// const byte pinSW = 2; // digital pin connected to switch output
const byte pinX = A0; // A0 - analog pin connected to X output
const byte pinY = A1; // A1 - analog pin connected to Y output
short xValue = 0; // vertical axis
short yValue = 0; // horizontal axis
// joystick flags
short verticalMoving = 0;
short horizontalMoving = 0;


#define readingMinThreshold 300
#define readingMaxThreshold 700
#define resetMinThreshold 450
#define resetMaxThreshold 550
#define centerReferenceValue 500
// const byte moveInterval = 200;     // Timing variable to control the speed of LED movement
#define moveInterval 200 // Timing to control the speed of LED movement
unsigned long lastMoved = 0;  // Tracks the last time the LED moved


const byte debounceDelay = 50;
const unsigned short longPushDuration = 2500;
volatile bool possiblePress = false; // Indicates that a button press might have occurred
volatile bool possibleLongPress = false; // Indicates that a long button press might have occurred
volatile bool shouldStartCounter = false; // Indicates the need to start debounce counter
bool ledState = LOW; // Current state of the LED (ON/OFF)
bool buttonState = HIGH; // The previous state of the button (HIGH when not pressed due to INPUT_PULLUP)
bool buttonReading = HIGH; // The current reading from the button pin
unsigned long lastDebounceTime = 0; // Keeps track of the last time the button was pressed


#define INTRO_MESSAGE_CODE 0
#define MAIN_MENU_CODE 1
#define HIGHSCORE_LEVEL_CODE 2
#define HIGHSCORES_CODE 3
#define ABOUT_CODE 4
#define HOW_TO_PLAY_CODE 5
#define SETTINGS_CODE 10
#define LCD_BRIGHTNESS_SETTINGS_CODE 11
#define MATRIX_BRIGHTNESS_SETTINGS_CODE 12
#define SOUND_SETTINGS_CODE 13
#define END_MESSAGE_CODE 20
#define NEW_HIGHSCORE_CODE 21
#define INPUT_NAME_CODE 22
#define GAMEPLAY_CODE 30
#define PLAY_MENU_CODE 31

#define INPUT_UP 'u'
#define INPUT_DOWN 'd'
#define INPUT_LEFT 'l'
#define INPUT_RIGHT 'r'
#define INPUT_CLICK 'c'
#define INPUT_LONG_CLICK 'k'

#define MENU_OPTION_1 1
#define MENU_OPTION_2 2
#define MENU_OPTION_3 3
#define MENU_OPTION_4 4
#define MENU_OPTION_5 5
#define MENU_OPTION_BACK 47808 // hex BAC0 :)

#define EEPROM_HIGHSCORE_ADDRESS 0 
#define MAX_HIGHSCORES_SAVED 3
#define MAX_HIGHSCORE_NAME_LENGTH 4

#define EEPROM_EASY_HIGHSCORE_ADDRESS (EEPROM_HIGHSCORE_ADDRESS + 1)
#define EEPROM_MEDIUM_HIGHSCORE_ADDRESS 40
#define EEPROM_HARD_HIGHSCORE_ADDRESS 60
#define EEPROM_MEGA_HIGHSCORE_ADDRESS 80
byte highscoreAddress = EEPROM_EASY_HIGHSCORE_ADDRESS;
// #define EEPROM_LCD_BRIGHTNESS_ADDRESS EEPROM_HIGHSCORE_ADDRESS + 1 + MAX_HIGHSCORES_SAVED * (MAX_HIGHSCORE_NAME_LENGTH + sizeof(short)) + 1
// #define EEPROM_MATRIX_BRIGHTNESS_ADDRESS EEPROM_LCD_BRIGHTNESS_ADDRESS + 1



unsigned long IntroMessageStartTimestamp = 0;
const short IntroMessageDuration = 2000;
unsigned long lastCursorToggleTime = 0;
const short cursorToggleInterval = 500;
// -=-=-=-
byte menuPosition = MENU_OPTION_1;
char *mainMenuOptions[] = {"1.Play", "2.Highscore", "3.Settings", "4.About", "5.How to play"};
const byte mainMenuSize = 5; 
char *playMenuOptions[] = {"1.Easy 8x8", "2.Medium 8x8", "3.Hard 8x8", "4.Mega 16x16", "5.Custom TODO"};
const byte playMenuSize = 5;
char *settingsMenuOptions[] = {"1.LCD Bright.", "2.Matr Bright.", "3.Sound"}; //BONUS ADD SCROLLING EFFECT LIKE 314PRINTERS
const byte settingsMenuSize = 3; 

// -=-=-=-
const char lcdGameName[] = "  Minesweeper!  ";
const String lcdAuthor = "                Alexandru Marius  github.com/MariusAlexandru358                ";
unsigned long lastAboutScrollTime = 0;
const short scrollInterval = 500; // Time interval for scrolling (in milliseconds)
byte scrollPosition = 0;


typedef struct {
  char name[4];
  short score;
} tHighscore;
tHighscore highscoreStruct[MAX_HIGHSCORES_SAVED];
tHighscore newHscore;

#define EEPROM_LCD_BRIGHTNESS_ADDRESS (EEPROM_HIGHSCORE_ADDRESS + 1 + MAX_HIGHSCORES_SAVED * sizeof(tHighscore) + 1)
#define EEPROM_MATRIX_BRIGHTNESS_ADDRESS (EEPROM_LCD_BRIGHTNESS_ADDRESS + 1)


const String letters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
short letLim1 = 0;
short letLim2 = 12;
char selection[4] = "___";
byte selectionPosition = 0;

byte newHighscore = 0;
byte highscores[MAX_HIGHSCORES_SAVED+1][MAX_HIGHSCORE_NAME_LENGTH+1];
byte highscoresSaved = 0;

byte stateControl = 0;
bool startedIntroMessage = false;
bool playingIntroMessage = false;



// -=-=-=-
unsigned short input;
byte brightnessSetting = 9;
byte matrBrightnessSetting = 2;
bool cursor = false;



#define SCROLL_MENU 440   // Scrolling through the menu
#define SELECT_OPTION 880 // Selecting an option
#define BACK_MENU 600     // Going back to the previous menu
#define START_GAME 220    // Starting the game
#define MOVE_ON_MAP 330   // Moving on the game map
#define CLICK_POSITION_1 660// Clicking a position on the game map
#define CLICK_POSITION_2 550
#define LOSE_GAME 110     // Losing the game
#define WIN_GAME 990      // Winning the game

bool soundFlag = true;
#define EEPROM_SOUND_ADDRESS (EEPROM_MATRIX_BRIGHTNESS_ADDRESS + 1)
#define SOUND_ON_POSITION 2
#define SOUND_OFF_POSITION 10
byte soundMenuPosition = SOUND_ON_POSITION;


byte flagPic[8] = 
{
  0b00011000,
  0b01111000,
  0b11111000,
  0b00111000,
  0b00001000,
  0b00001000,
  0b01111110,
  0b11111111
};
byte anvilPic[8] = 
{
  0b01000000,
  0b11111100,
  0b11000000,
  0b00011111,
  0b11111111,
  0b01111100,
  0b00011000,
  0b00111110
};
byte infoPic[8] = 
{
  0b00011000,
  0b00011000,
  0b00000000,
  0b00111000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011100
};
byte cupPic[8] =
{
  0b00111100,
  0b01111110,
  0b01111110,
  0b00111100,
  0b00011000,
  0b00011000,
  0b00111100,
  0b01111110
};
byte soundPic[8] =
{
  0b00001000,
  0b00011010,
  0b00111011,
  0b11111001,
  0b11111001,
  0b00111011,
  0b00011010,
  0b00001000
};
void printPicture(byte picture[]) {
  for (byte row = 0; row < 8; row++) {
    lc.setRow(0, row, picture[row]);
  }
}



tGameMap gameMap16[16][16];
byte xPos16 = 0;
byte yPos16 = 0;
byte xLastPos16 = 0;
byte yLastPos16 = 0;
byte xViewOrigin16 = 0;
byte yViewOrigin16 = 0;
#define VIEW_SIZE 8
// tGameMap viewMap[VIEW_SIZE][VIEW_SIZE];

byte mapSize = VIEW_SIZE;









void setup() {
  pinMode(lcdIntensityPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pinSW, INPUT_PULLUP);
  pinMode(flagButtonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinSW), handleInterrupt, FALLING);  
  lcd.begin(16,2);
  lcd.clear();
  highscoresSaved = EEPROM.read(EEPROM_HIGHSCORE_ADDRESS);
  // for (short i=0; i<highscoresSaved; ++i) {
  //   for (short j=0; j<=MAX_HIGHSCORE_NAME_LENGTH; ++j) {
  //     highscores[i][j] = EEPROM.read(EEPROM_HIGHSCORE_ADDRESS+1+i+j);
  //   }
  // }
  for (byte i=0; i<highscoresSaved; ++i) {
    EEPROM.get(EEPROM_HIGHSCORE_ADDRESS+1+i*sizeof(tHighscore), highscoreStruct[i]); 
  }

  lc.shutdown(0, false);                 // turn off power saving, enables display
  lc.clearDisplay(0);                    // Clear the matrix display  

  // EEPROM.update(EEPROM_MATRIX_BRIGHTNESS_ADDRESS, 2);
  matrBrightnessSetting = EEPROM.read(EEPROM_MATRIX_BRIGHTNESS_ADDRESS);
  lc.setIntensity(0, matrBrightnessSetting);  // sets matrix brightness (0~15 possible values)

  // EEPROM.update(EEPROM_LCD_BRIGHTNESS_ADDRESS, 9);
  brightnessSetting = EEPROM.read(EEPROM_LCD_BRIGHTNESS_ADDRESS);
  byte lcdIntensityVal = map(brightnessSetting, 0, 9, 56, 255);
  analogWrite(lcdIntensityPin, lcdIntensityVal);

  soundMenuPosition = EEPROM.read(EEPROM_SOUND_ADDRESS);
  if (soundMenuPosition == SOUND_ON_POSITION)
    soundFlag = true;
  else
   soundFlag = false;

  // Serial.begin(9600);
  // printMainMenu(MENU_OPTION_1);

  // stateControl = MAIN_MENU_CODE;
  // printMainMenu(MENU_OPTION_1);
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  randomSeed(analogRead(A4)); // Initialize random seed

  // generateMap();
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
}


void loop() {
  switch (stateControl) {
  case INTRO_MESSAGE_CODE:
    IntroMessage(); 
    break;
  case MAIN_MENU_CODE:
    MainMenu(); 
    break;
  case PLAY_MENU_CODE:
    PlayMenu();
    break;
  case SETTINGS_CODE:
    SettingsMenu();
    break;
  case LCD_BRIGHTNESS_SETTINGS_CODE:
    LCDBrightnessMenu();
    break;
  case MATRIX_BRIGHTNESS_SETTINGS_CODE:
    MatrixBrightnessMenu();
    break;
  case SOUND_SETTINGS_CODE:
    SoundMenu();
    break; 
  case ABOUT_CODE:
    AboutMenu();
    break;
  case HOW_TO_PLAY_CODE:
    HowToPlayMenu();
    break;
  case END_MESSAGE_CODE:
    EndMessage();
    break;
  case NEW_HIGHSCORE_CODE:
    NewHighscoreMenu();
    break;
  case INPUT_NAME_CODE:
    InputNameMenu();
    break;
  case GAMEPLAY_CODE:
    Gameplay(); 
    break;
  case HIGHSCORES_CODE:
    HighscoreMenu(); 
    break;
  case HIGHSCORE_LEVEL_CODE:
    HighscoreLevelMenu();
    break;
  
  default:
    MainMenu();
    break;
  }

}


void IntroMessage() { 
  if (!startedIntroMessage && !playingIntroMessage) {
    printPicture(flagPic);
    lcd.setCursor(3,0);
    lcd.print(F("Greetings!")); 
    lcd.setCursor(17,0);
    lcd.print(F("Welcome to")); // probabil nu merge ^^ muta printuri noi dupa scroll?? nah, yt video?
    lcd.setCursor(16,1);
    lcd.print(F("Minesweeper!"));
    startedIntroMessage = true;
    IntroMessageStartTimestamp = millis();
  }
  if (startedIntroMessage && millis() - IntroMessageStartTimestamp > IntroMessageDuration) {
    for (short position=0; position<14; ++position) {
      lcd.scrollDisplayLeft();
      delayMicroseconds(10);
    }
    startedIntroMessage = false;
    playingIntroMessage = true;
    IntroMessageStartTimestamp = millis();
  }
  if (playingIntroMessage && millis() - IntroMessageStartTimestamp > IntroMessageDuration) {
    lcd.clear();
    // stateControl = MAIN_MENU_CODE;
    playingIntroMessage = false;
    stateControl = MAIN_MENU_CODE;
    printMainMenu(MENU_OPTION_1);  
  }
}

void printMainMenu(byte currentOption) {
  printPicture(flagPic);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F(">")); 
  lcd.setCursor(1,0);
  lcd.print(mainMenuOptions[currentOption-1]);
  if (currentOption != MENU_OPTION_1) {
    lcd.setCursor(15,0);
    lcd.print(F("^")); 
  }
  if (currentOption != mainMenuSize) {
    lcd.setCursor(1,1);
    lcd.print(mainMenuOptions[currentOption]); 
    lcd.setCursor(15,1);
    lcd.print(F("v")); 
  }
}
void MainMenu() {
  input = detectInput(); 
  switch (input) {
  case INPUT_UP:
    if (menuPosition > MENU_OPTION_1) {
      playGameTone(SCROLL_MENU);
      menuPosition--;
      printMainMenu(menuPosition);
    }
    break;
  case INPUT_DOWN:
    if (menuPosition < mainMenuSize) {
      playGameTone(SCROLL_MENU);
      menuPosition++;
      printMainMenu(menuPosition);
    }
    break;
  case INPUT_LEFT:
    break;
  case INPUT_RIGHT:
    break;
  case INPUT_CLICK:
    playGameTone(SELECT_OPTION);
    MainMenuAction(menuPosition);
    break;
  default:
    break;  
  }
}
void MainMenuAction(short selectedOption) { 
  menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
  switch (selectedOption) {
  case MENU_OPTION_1: // Start game 
    playGameTone(SELECT_OPTION);
    stateControl = PLAY_MENU_CODE;
    printPlayMenu(MENU_OPTION_1);
    break;
  case MENU_OPTION_2: // Highscore 
    stateControl = HIGHSCORE_LEVEL_CODE; 
    printHighscoreLevelMenu(MENU_OPTION_1); 
    HighscoreLevelMenu();
    
    break;
  case MENU_OPTION_3: // Settings
    stateControl = SETTINGS_CODE;
    printSettingsMenu(MENU_OPTION_1); 
    SettingsMenu();
    break;
  case MENU_OPTION_4: // About
    stateControl = ABOUT_CODE;
    printPicture(infoPic);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(lcdGameName);
    AboutMenu();
    // lcd.setCursor(0,1);
    break;
  case MENU_OPTION_5: // How to play
    stateControl = HOW_TO_PLAY_CODE;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Clear all tiles"));
    lcd.setCursor(0,1);
    lcd.print(F("Flag the mines"));
    HowToPlayMenu();
    break;
  default:
    break;
  }
}


void printPlayMenu(byte currentOption) {
  printPicture(flagPic);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F(">")); 
  lcd.setCursor(1,0);
  lcd.print(playMenuOptions[currentOption-1]);
  if (currentOption != MENU_OPTION_1) {
    lcd.setCursor(15,0);
    lcd.print(F("^")); 
  }
  if (currentOption != playMenuSize-1) {
    lcd.setCursor(1,1);
    lcd.print(playMenuOptions[currentOption]); 
    lcd.setCursor(15,1);
    lcd.print(F("v")); 
  }
}
void PlayMenu() {
  input = detectInput(); 
  switch (input) {
  case INPUT_UP:
    if (menuPosition > MENU_OPTION_1) {
      playGameTone(SCROLL_MENU);
      menuPosition--;
      printPlayMenu(menuPosition);
    }
    break;
  case INPUT_DOWN:
    if (menuPosition < playMenuSize-1) {
      playGameTone(SCROLL_MENU);
      menuPosition++;
      printPlayMenu(menuPosition);
    }
    break;
  case INPUT_LEFT:
    playGameTone(BACK_MENU);
    PlayMenuAction(MENU_OPTION_BACK);
    break;
  case INPUT_RIGHT:
    break;
  case INPUT_CLICK:
    playGameTone(SELECT_OPTION);
    PlayMenuAction(menuPosition);
    break;
  default:
    break;  
  }
}
void PlayMenuAction(short selectedOption) { 
  menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
  switch (selectedOption) {
  case MENU_OPTION_1: // Easy
    playGameTone(START_GAME);
    stateControl = GAMEPLAY_CODE;
    numBombs = EASY_NUM_BOMBS;
    highscoreAddress = EEPROM_EASY_HIGHSCORE_ADDRESS;
    mapSize = VIEW_SIZE;
    generateMap();
    Gameplay(); 
    break;
  case MENU_OPTION_2: // Medium
    playGameTone(START_GAME);
    stateControl = GAMEPLAY_CODE;
    numBombs = MEDIUM_NUM_BOMBS;
    highscoreAddress = EEPROM_MEDIUM_HIGHSCORE_ADDRESS;
    mapSize = VIEW_SIZE;
    generateMap();
    Gameplay(); 
    break;
  case MENU_OPTION_3: // Hard
    playGameTone(START_GAME);
    stateControl = GAMEPLAY_CODE;
    numBombs = HARD_NUM_BOMBS;
    highscoreAddress = EEPROM_HARD_HIGHSCORE_ADDRESS;
    mapSize = VIEW_SIZE;
    generateMap();
    Gameplay(); 
    break;
  case MENU_OPTION_4: // Mega
    playGameTone(START_GAME);
    stateControl = GAMEPLAY_CODE;
    numBombs = MEGA_NUM_BOMBS;
    highscoreAddress = EEPROM_MEGA_HIGHSCORE_ADDRESS;
    mapSize = 2*VIEW_SIZE;
    generateMap();
    Gameplay(); 
    break;
  case MENU_OPTION_BACK: // Back
    playGameTone(BACK_MENU);
    stateControl = MAIN_MENU_CODE;
    menuPosition = MENU_OPTION_1;
    printMainMenu(MENU_OPTION_1);
    MainMenu();
    break;
  default:
    break;
  }
}


void printHighscoreLevelMenu(byte currentOption) {
  printPicture(cupPic);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F(">")); 
  lcd.setCursor(1,0);
  lcd.print(playMenuOptions[currentOption-1]);
  if (currentOption != MENU_OPTION_1) {
    lcd.setCursor(15,0);
    lcd.print(F("^")); 
  }
  if (currentOption != playMenuSize-1) {
    lcd.setCursor(1,1);
    lcd.print(playMenuOptions[currentOption]); 
    lcd.setCursor(15,1);
    lcd.print(F("v")); 
  }
}
void HighscoreLevelMenu() {
  input = detectInput(); 
  switch (input) {
  case INPUT_UP:
    if (menuPosition > MENU_OPTION_1) {
      playGameTone(SCROLL_MENU);
      menuPosition--;
      printHighscoreLevelMenu(menuPosition);
    }
    break;
  case INPUT_DOWN:
    if (menuPosition < playMenuSize-1) {
      playGameTone(SCROLL_MENU);
      menuPosition++;
      printHighscoreLevelMenu(menuPosition);
    }
    break;
  case INPUT_LEFT:
    playGameTone(BACK_MENU);
    HighscoreLevelMenuAction(MENU_OPTION_BACK);
    break;
  case INPUT_RIGHT:
    break;
  case INPUT_CLICK:
    playGameTone(SELECT_OPTION);
    HighscoreLevelMenuAction(menuPosition);
    break;
  default:
    break;  
  }
}
void HighscoreLevelMenuAction(short selectedOption) { 
  menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
  switch (selectedOption) {
  case MENU_OPTION_1: // Easy
    playGameTone(SELECT_OPTION);
    stateControl = HIGHSCORES_CODE;
    highscoreAddress = EEPROM_EASY_HIGHSCORE_ADDRESS;
    for (byte i=0; i<MAX_HIGHSCORES_SAVED; ++i) {
      EEPROM.get(highscoreAddress + i*sizeof(tHighscore), highscoreStruct[i]); 
    }
    menuPosition = MENU_OPTION_1;
    printHighscoreMenu(0);
    break;
  case MENU_OPTION_2: // Medium
    playGameTone(SELECT_OPTION);
    stateControl = HIGHSCORES_CODE;
    highscoreAddress = EEPROM_MEDIUM_HIGHSCORE_ADDRESS;
    for (byte i=0; i<MAX_HIGHSCORES_SAVED; ++i) {
      EEPROM.get(highscoreAddress + i*sizeof(tHighscore), highscoreStruct[i]); 
    }
    menuPosition = MENU_OPTION_1;
    printHighscoreMenu(0);
    break;
  case MENU_OPTION_3: // Hard
    playGameTone(SELECT_OPTION);
    stateControl = HIGHSCORES_CODE;
    highscoreAddress = EEPROM_HARD_HIGHSCORE_ADDRESS;
    for (byte i=0; i<MAX_HIGHSCORES_SAVED; ++i) {
      EEPROM.get(highscoreAddress + i*sizeof(tHighscore), highscoreStruct[i]); 
    }
    menuPosition = MENU_OPTION_1;
    printHighscoreMenu(0);
    break;
  case MENU_OPTION_4: // Mega
    playGameTone(SELECT_OPTION);
    stateControl = HIGHSCORES_CODE;
    highscoreAddress = EEPROM_MEGA_HIGHSCORE_ADDRESS;
    for (byte i=0; i<MAX_HIGHSCORES_SAVED; ++i) {
      EEPROM.get(highscoreAddress + i*sizeof(tHighscore), highscoreStruct[i]); 
    }
    menuPosition = MENU_OPTION_1;
    printHighscoreMenu(0);
    break;

  case MENU_OPTION_5:
    break;

  case MENU_OPTION_BACK: // Back
    playGameTone(BACK_MENU);
    stateControl = MAIN_MENU_CODE;
    menuPosition = MENU_OPTION_1;
    printMainMenu(MENU_OPTION_1);
    MainMenu();
    break;
  default:
    break;
  }
}



void printHighscoreMenu(byte line) {
  printPicture(cupPic);
  // for (byte i = 0; i < MAX_HIGHSCORES_SAVED; ++i) {
  //   Serial.print(highscoreStruct[i].name);
  //   Serial.print(' ');
  //   Serial.println(highscoreStruct[i].score);
  // }
  // Serial.println(' ');
  
  lcd.clear();
  if (line == 0) {
    lcd.setCursor(0,0);
    lcd.print(F("> Highscore:"));
    lcd.setCursor(0,1);
    lcd.print(F("  "));
    lcd.setCursor(2,1);
    lcd.print(line+1);
    lcd.setCursor(3,1);
    lcd.print(F(". "));
    lcd.setCursor(15,1); 
    lcd.print(F("v"));
    lcd.setCursor(5,1);
    lcd.print(highscoreStruct[line].name);
    lcd.setCursor(8,1);
    lcd.print(F(" "));
    lcd.setCursor(9,1);
    if (highscoreStruct[line].score)
      lcd.print(highscoreStruct[line].score);
    else
     lcd.print(F("N/A"));
  }
  else if (line == MAX_HIGHSCORES_SAVED) {
    lcd.setCursor(0,0);
    lcd.print(F("> "));
    lcd.setCursor(2,0);
    lcd.print(line);
    lcd.setCursor(3,0);
    lcd.print(F(". "));
    lcd.setCursor(15,0); 
    lcd.print(F("^"));
    lcd.setCursor(5,0);
    lcd.print(highscoreStruct[line-1].name);
    lcd.setCursor(8,0);
    lcd.print(F(" "));
    lcd.setCursor(9,0);
    if (highscoreStruct[line-1].score)
      lcd.print(highscoreStruct[line-1].score);
    else
     lcd.print(F("N/A"));

    lcd.setCursor(1,1);
    lcd.print(F("Reset HS !"));
    lcd.setCursor(15,1);
    lcd.print(F("v"));
  }
  else if (line > MAX_HIGHSCORES_SAVED) {
    lcd.setCursor(0,0);
    lcd.print(F(">Reset HS !"));
    lcd.setCursor(15,0);
    lcd.print(F("^"));
  }
  else {
    lcd.setCursor(0,0);
    lcd.print(F("> "));
    lcd.setCursor(2,0);
    lcd.print(line);
    lcd.setCursor(3,0);
    lcd.print(F(". "));
    lcd.setCursor(15,0); 
    lcd.print(F("^"));
    lcd.setCursor(5,0);
    lcd.print(highscoreStruct[line-1].name);
    lcd.setCursor(8,0);
    lcd.print(F(" "));
    lcd.setCursor(9,0);
    if (highscoreStruct[line-1].score)
      lcd.print(highscoreStruct[line-1].score);
    else
     lcd.print(F("N/A"));

    lcd.setCursor(0,1);
    lcd.print(F("  "));
    lcd.setCursor(2,1);
    lcd.print(line+1);
    lcd.setCursor(3,1);
    lcd.print(F(". "));
    lcd.setCursor(15,1); 
    lcd.print(F("v"));
    lcd.setCursor(5,1);
    lcd.print(highscoreStruct[line].name);
    lcd.setCursor(8,1);
    lcd.print(F(" "));
    lcd.setCursor(9,1);
    if (highscoreStruct[line].score)
      lcd.print(highscoreStruct[line].score);
    else
     lcd.print(F("N/A"));
  }
}
void HighscoreMenu() {
  input = detectInput(); 
  switch (input) {
  case INPUT_UP:
    if (menuPosition > MENU_OPTION_1) {
      playGameTone(SCROLL_MENU);
      menuPosition--;
      printHighscoreMenu(menuPosition-1);
    }
    break;
  case INPUT_DOWN:
    if (menuPosition < highscoresSaved+2) {
      playGameTone(SCROLL_MENU);
      menuPosition++;
      printHighscoreMenu(menuPosition-1);
    }
    break;
  case INPUT_LEFT:
    playGameTone(BACK_MENU);
    stateControl = HIGHSCORE_LEVEL_CODE;
    menuPosition = MENU_OPTION_1;
    printHighscoreLevelMenu(MENU_OPTION_1);
    break;
  case INPUT_RIGHT:
    break;

  case INPUT_CLICK:
    if (menuPosition > MAX_HIGHSCORES_SAVED) {
    playGameTone(SELECT_OPTION);
    tHighscore defaultHighscore;
    memset(defaultHighscore.name, 0, sizeof(defaultHighscore.name)); // Clear the name array
    defaultHighscore.score = 0;
    // Update highscoreStruct with default values
    for (byte i = 0; i < MAX_HIGHSCORES_SAVED; ++i) {
      // Serial.println(highscoreStruct[i].score);
      highscoreStruct[i] = defaultHighscore;
    }
    for (byte i = 0; i < MAX_HIGHSCORES_SAVED; ++i) {
      // Serial.println(highscoreStruct[i].score);
      byte address = highscoreAddress + i * sizeof(tHighscore);
      EEPROM.put(address, highscoreStruct[i]);
    }
    for (byte i = 0; i < MAX_HIGHSCORES_SAVED; ++i) {
      byte address = highscoreAddress + i * sizeof(tHighscore);
      EEPROM.get(address, highscoreStruct[i]);
    }
    stateControl = HIGHSCORE_LEVEL_CODE;
    menuPosition = MENU_OPTION_1;
    printHighscoreLevelMenu(MENU_OPTION_1);
    }
    break;

  default:
    break;  
  }
}



void printSettingsMenu(byte currentOption) {
  printPicture(anvilPic);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F(">")); 
  lcd.setCursor(1,0);
  lcd.print(settingsMenuOptions[currentOption-1]);
  if (currentOption != MENU_OPTION_1) {
    lcd.setCursor(15,0);
    lcd.print(F("^")); 
  }
  if (currentOption != settingsMenuSize) {
    lcd.setCursor(1,1);
    lcd.print(settingsMenuOptions[currentOption]); 
    lcd.setCursor(15,1);
    lcd.print(F("v")); 
  }
}
void SettingsMenu() {
  input = detectInput();
  switch (input) {
  case INPUT_UP:
    if (menuPosition > MENU_OPTION_1) {
      playGameTone(SCROLL_MENU);
      menuPosition--;
      printSettingsMenu(menuPosition);
    }
    break;
  case INPUT_DOWN:
    if (menuPosition < settingsMenuSize) {
      playGameTone(SCROLL_MENU);
      menuPosition++;
      printSettingsMenu(menuPosition);
    }
    break;
  case INPUT_LEFT:
    playGameTone(BACK_MENU);
    SettingsAction(MENU_OPTION_BACK);
    break;
  case INPUT_RIGHT:
    break;
  case INPUT_CLICK:
    SettingsAction(menuPosition);
    break;
  default:
    break;  
  }
}
void SettingsAction(short selectedOption) {
  menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
  switch (selectedOption) {
  case MENU_OPTION_1: // LCD brightness control
    playGameTone(SELECT_OPTION);
    stateControl = LCD_BRIGHTNESS_SETTINGS_CODE;
    menuPosition = brightnessSetting;
    printLCDBrightnessMenu(); 
    LCDBrightnessMenu(); 
    break;
  case MENU_OPTION_2: // Matrix brightness control
    playGameTone(SELECT_OPTION);
    stateControl = MATRIX_BRIGHTNESS_SETTINGS_CODE;
    menuPosition = matrBrightnessSetting-1;
    printMatrixBrightnessMenu(); 
    MatrixBrightnessMenu(); 
    break;
  case MENU_OPTION_3: // Sound on/off
    playGameTone(SELECT_OPTION);
    stateControl = SOUND_SETTINGS_CODE;
    printSoundMenu(); 
    SoundMenu(); 
    break;

  case MENU_OPTION_BACK:
    playGameTone(BACK_MENU);
    stateControl = MAIN_MENU_CODE;
    menuPosition = MENU_OPTION_1;
    printMainMenu(MENU_OPTION_1);
    MainMenu();
    break;
  default:
    break;
  }
}

void printLCDBrightnessMenu() {
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print(F("^ LCD Brightness"));
  lcd.setCursor(1,1);
  lcd.print(F("< 0123456789 >"));
  lcd.setCursor(3+brightnessSetting,1);
  lcd.cursor(); 
}
void LCDBrightnessMenu() {
  byte val;
  unsigned long currentMillis;
  currentMillis = millis();
  if (currentMillis - lastCursorToggleTime >= cursorToggleInterval) {
    lastCursorToggleTime = currentMillis;
    if(cursor) {
      lcd.noCursor();
    }
    else {
      lcd.cursor();
    }  
    cursor = !cursor;
  }

  input = detectInput();
  switch (input) {
  case INPUT_UP:
    playGameTone(BACK_MENU);
    LCDBrightnessAction(MENU_OPTION_BACK);
    break;
  case INPUT_DOWN:
    break;

  case INPUT_LEFT:
    if (menuPosition) {
      playGameTone(SCROLL_MENU);
      menuPosition--;
    }
    
    val = map(menuPosition, 0, 9, 56, 255);
    analogWrite(lcdIntensityPin, val);
    brightnessSetting = menuPosition;
    lcd.setCursor(3+menuPosition,1);
    break;

  case INPUT_RIGHT:
    menuPosition++;
    if (menuPosition > 9)
      menuPosition = 9;
    else 
      playGameTone(SCROLL_MENU);
    val = map(menuPosition, 0, 9, 56, 255);
    analogWrite(lcdIntensityPin, val);
    brightnessSetting = menuPosition;
    lcd.setCursor(3+menuPosition,1);
    break;
  
  case INPUT_CLICK:
    lcd.noCursor();
    cursor = false;
    LCDBrightnessAction(menuPosition);
    break;
  default:
    break;  
  }
}
void LCDBrightnessAction(short selectedOption) {
  switch (selectedOption) {
  case MENU_OPTION_BACK:
    playGameTone(SELECT_OPTION);
    EEPROM.update(EEPROM_LCD_BRIGHTNESS_ADDRESS, brightnessSetting);

    stateControl = SETTINGS_CODE;
    menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
    printSettingsMenu(MENU_OPTION_1);
    SettingsMenu();
    break;
  default:
    LCDBrightnessAction(MENU_OPTION_BACK);
    break;
  }  
}

void printMatrixBrightnessMenu() {
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print(F("^ Matrix Bright."));
  lcd.setCursor(1,1);
  lcd.print(F("< 0123456789 >"));
  lcd.setCursor(2+matrBrightnessSetting,1);
  lcd.cursor(); 
}
void MatrixBrightnessMenu() {
  unsigned long currentMillis;
  input = detectInput();
  currentMillis = millis();
  if (currentMillis - lastCursorToggleTime >= cursorToggleInterval) {
    lastCursorToggleTime = currentMillis;
    if(cursor) {
      lcd.noCursor();
    }
    else {
      lcd.cursor();
    }  
    cursor = !cursor;
  }

  switch (input) {
  case INPUT_UP:
    playGameTone(BACK_MENU);
    MatrixBrightnessAction(MENU_OPTION_BACK);
    break;
  case INPUT_DOWN:
    break;

  case INPUT_LEFT:
    if (menuPosition)
      menuPosition--;
    if (menuPosition < 0)
      menuPosition = 0;
    else 
      playGameTone(SCROLL_MENU);
    // byte val = map(menuPosition, 0, 9, 1, 10);
    matrBrightnessSetting = menuPosition+1;
    lc.setIntensity(0, matrBrightnessSetting);  // sets matrix brightness (0~15 possible values)
    lcd.setCursor(3+menuPosition,1);
    break;

  case INPUT_RIGHT:
    menuPosition++;
    if (menuPosition > 9)
      menuPosition = 9;
    else
      playGameTone(SCROLL_MENU);
    // byte val = map(menuPosition, 0, 9, 1, 10);
    matrBrightnessSetting = menuPosition+1;
    lc.setIntensity(0, matrBrightnessSetting);  // sets matrix brightness (0~15 possible values)
    lcd.setCursor(3+menuPosition,1);
    break;

  case INPUT_CLICK:
    lcd.noCursor();
    cursor = false;
    MatrixBrightnessAction(menuPosition);
    break;
  default:
    break;  
  }
}
void MatrixBrightnessAction(short selectedOption) {
  switch (selectedOption) {
  case MENU_OPTION_BACK:
    playGameTone(SELECT_OPTION);
    EEPROM.update(EEPROM_MATRIX_BRIGHTNESS_ADDRESS, matrBrightnessSetting);

    stateControl = SETTINGS_CODE;
    menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
    printSettingsMenu(MENU_OPTION_1);
    SettingsMenu();
    break;
  default:
    MatrixBrightnessAction(MENU_OPTION_BACK);
    break;
  }
}

void printSoundMenu() {
  printPicture(soundPic);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print(F("^ Sound:"));
  lcd.setCursor(SOUND_ON_POSITION+1,1);
  lcd.print(F("ON"));
  lcd.setCursor(SOUND_OFF_POSITION+1,1);
  lcd.print(F("OFF"));
  lcd.setCursor(soundMenuPosition,1);
  lcd.print(F(">"));
  lcd.cursor(); 
}
void SoundMenu() { 
  unsigned long currentMillis;
  input = detectInput();
  currentMillis = millis();
  if (currentMillis - lastCursorToggleTime >= cursorToggleInterval) {
    lastCursorToggleTime = currentMillis;
    if(cursor) {
      lcd.noCursor();
    }
    else {
      lcd.cursor();
    }  
    cursor = !cursor;
  }

  switch (input) {
  case INPUT_UP:
    playGameTone(BACK_MENU);
    stateControl = SETTINGS_CODE;
    menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
    printSettingsMenu(MENU_OPTION_1);
    SettingsMenu();
    break;
  case INPUT_DOWN:
    break;

  case INPUT_LEFT:
    if (soundMenuPosition == SOUND_OFF_POSITION) {
      playGameTone(SCROLL_MENU);
      soundMenuPosition = SOUND_ON_POSITION;
      printSoundMenu();
    }
    break;

  case INPUT_RIGHT:
    if (soundMenuPosition == SOUND_ON_POSITION) {
      playGameTone(SCROLL_MENU);
      soundMenuPosition = SOUND_OFF_POSITION;
      printSoundMenu();
    }
    break;

  case INPUT_CLICK:
    playGameTone(SELECT_OPTION);
    lcd.noCursor();
    cursor = false;

    EEPROM.update(EEPROM_SOUND_ADDRESS, soundMenuPosition);
    if (soundMenuPosition == SOUND_ON_POSITION)
      soundFlag = true;
    else
     soundFlag = false;

    stateControl = SETTINGS_CODE;
    menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
    printSettingsMenu(MENU_OPTION_1);
    SettingsMenu();
    break;
  default:
    break;  
  }
}
void SoundMenuAction(short selectedOption) {
  switch (selectedOption) {
  case SOUND_ON_POSITION:
    EEPROM.update(EEPROM_SOUND_ADDRESS, SOUND_ON_POSITION);

    stateControl = SETTINGS_CODE;
    menuPosition = MENU_OPTION_1; //reset the menuPosition for the next time we enter a menu or submenu
    printSettingsMenu(MENU_OPTION_1);
    SettingsMenu();
    break;
  default:
    MatrixBrightnessAction(MENU_OPTION_BACK);
    break;
  }
}




void AboutMenu() {
  input = detectInput();
  unsigned long currentMillis = millis();
  if (currentMillis - lastAboutScrollTime >= scrollInterval) {
    lastAboutScrollTime = currentMillis;

    lcd.setCursor(0, 1); // Set the cursor to the second line

    // Print the scrolling portion of the message
    lcd.print(lcdAuthor.substring(scrollPosition, scrollPosition + LCD_L));

    // Move to the next position for the next loop
    scrollPosition++;

    // Reset the scroll position when the end of the message is reached
    if (scrollPosition > lcdAuthor.length() - LCD_L) {
      scrollPosition = 0;
      lcd.clear(); // Clear the LCD before displaying the constant text again
      lcd.setCursor(0, 0);
      lcd.print(lcdGameName);
    }
  }
  
  switch (input) {
  case INPUT_LEFT:
    playGameTone(BACK_MENU);
    stateControl = MAIN_MENU_CODE;
    menuPosition = MENU_OPTION_1;
    printMainMenu(MENU_OPTION_1);
    MainMenu();
    break;
  case INPUT_UP:
    playGameTone(BACK_MENU);
    stateControl = MAIN_MENU_CODE;
    menuPosition = MENU_OPTION_1;
    printMainMenu(MENU_OPTION_1);
    MainMenu();
    break;
  default:
    break;
  }
}


void HowToPlayMenu() {
  input = detectInput();
  switch (input) {
  case INPUT_LEFT:
    playGameTone(BACK_MENU);
    stateControl = MAIN_MENU_CODE;
    menuPosition = MENU_OPTION_1;
    printMainMenu(MENU_OPTION_1);
    MainMenu();
    break;
  case INPUT_UP:
    playGameTone(BACK_MENU);
    stateControl = MAIN_MENU_CODE;
    menuPosition = MENU_OPTION_1;
    printMainMenu(MENU_OPTION_1);
    MainMenu();
    break;
  default:
    break;
  }
}








void printEndMessage(byte outcome, short score) {
  if (outcome == VICTORY) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Congratulations!"));
    lcd.setCursor(0,1);
    lcd.print(F("Time: "));
    lcd.setCursor(6,1);
    lcd.print(score/1000);
    lcd.setCursor(7,1);
    lcd.print((score/100)%10);
    lcd.setCursor(8,1);
    lcd.print((score/10)%10);
    lcd.setCursor(9,1);
    lcd.print(score%10);
    lcd.setCursor(10,1);
    lcd.print(F("s"));

    
    for (byte i=0; i<MAX_HIGHSCORES_SAVED; ++i) {
      // tHighscore hscore;
      // EEPROM.get(highscoreAddress + i*sizeof(tHighscore), hscore);
      EEPROM.get(highscoreAddress + i*sizeof(tHighscore), highscoreStruct[i]);
      if (score < highscoreStruct[i].score || !highscoreStruct[i].score) {
        newHscore.score = score;
        newHighscore = i+1;
      }
      // if (score < hscore.score || !hscore.score) {
      //   newHscore.score = score;
      //   newHighscore = i+1;
      // }
    }
  }
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("You lost! Better"));
    lcd.setCursor(1,1);
    lcd.print(F("luck next time!"));
  }
}
void EndMessage() {
  input = detectInput();
  if (input) {
    if (newHighscore) {
      stateControl = NEW_HIGHSCORE_CODE;
      printNewHighscoreMenu();
    }
    else {
      stateControl = MAIN_MENU_CODE;
      printMainMenu(MENU_OPTION_1);
    }
    // stateControl = MAIN_MENU_CODE;
    // printMainMenu(MENU_OPTION_1);
    return;
  }
}

void printNewHighscoreMenu() {
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print(F("Hew highscore!"));
  lcd.setCursor(0,1);
  lcd.print(F("Input name:    >"));
}
void NewHighscoreMenu() {
  input = detectInput();
  if (input) {
    playGameTone(SELECT_OPTION);
    stateControl = INPUT_NAME_CODE;
    printInputNameMenu(letters.substring(letLim1, letLim2));
    return;
  }
}

void printInputNameMenu(String lettersSubstring) {
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print(F("Choose name: "));
  lcd.setCursor(13,0); 
  lcd.print(selection);
  lcd.setCursor(0,1);
  lcd.print(F("< "));
  lcd.setCursor(2,1);
  lcd.print(lettersSubstring);
  lcd.setCursor(14,1);
  lcd.print(F(" >"));
  lcd.setCursor(2+menuPosition,1);
  lcd.cursor(); 
}
void InputNameMenu() {
  unsigned long currentMillis;
  input = detectInput();
  currentMillis = millis();
  if (currentMillis - lastCursorToggleTime >= cursorToggleInterval) {
    lastCursorToggleTime = currentMillis;
    if(cursor) {
      lcd.noCursor();
    }
    else {
      lcd.cursor();
    }  
    cursor = !cursor;
  }

  switch (input) {
  case INPUT_UP:
    playGameTone(SCROLL_MENU);
    playGameTone(SCROLL_MENU);
    menuPosition = 0;
    letLim1 = 0;
    letLim2 = 12;
    lcd.setCursor(2+menuPosition,1);
    printInputNameMenu(letters.substring(letLim1, letLim2));
    break;
  case INPUT_DOWN:
    playGameTone(SCROLL_MENU);
    playGameTone(SCROLL_MENU);
    menuPosition = 11;
    letLim1 = letters.length()-12;
    letLim2 = letters.length();
    lcd.setCursor(2+menuPosition,1);
    printInputNameMenu(letters.substring(letLim1, letLim2));
    break;

  case INPUT_LEFT:
    if (menuPosition) {
      menuPosition--;
    }
    else {
      letLim1--;
      letLim2--;
    }
      
    if (menuPosition < 0 || letLim1 < 0) {
      menuPosition = 0;
      letLim1 = 0;
      letLim2 = 12;
    }
    else {
      playGameTone(SCROLL_MENU);
    }
    lcd.setCursor(2+menuPosition,1);
    printInputNameMenu(letters.substring(letLim1, letLim2));
    break;

  case INPUT_RIGHT:
    menuPosition++;
    // letLim1++;
    // letLim2++;
    if (menuPosition > 11) {
      menuPosition = 11;
      letLim1++;
      letLim2++;
    }
    if (letLim2 > letters.length()) {
      menuPosition = 11;
      letLim1 = letters.length()-12;
      letLim2 = letters.length();
    }
    else {
      playGameTone(SCROLL_MENU);
    }
    lcd.setCursor(2+menuPosition,1);
    printInputNameMenu(letters.substring(letLim1, letLim2));
    break;

  case INPUT_CLICK:
    playGameTone(SELECT_OPTION);
    lcd.noCursor();
    cursor = false;
    InputNameAction(menuPosition);
    break;
  default:
    break;  
  }
}
void InputNameAction(short selectedOption) {
  switch (selectedOption) {
  case MENU_OPTION_BACK:
    break;
  default:
    if (selectionPosition < 3) {
      selection[selectionPosition] = letters.substring(letLim1, letLim2)[selectedOption];
      selectionPosition++;
      printInputNameMenu(letters.substring(letLim1, letLim2));
    }
    else {
      selectionPosition = 0;
      for (byte i=0; i<MAX_HIGHSCORE_NAME_LENGTH; ++i) 
        newHscore.name[i] = selection[i];
      UploadHighscore();
    }
    break;
  }
}

void UploadHighscore() {
  byte insertIndex = MAX_HIGHSCORES_SAVED - 1;
  while (insertIndex > 0 && (newHscore.score < highscoreStruct[insertIndex - 1].score || !highscoreStruct[insertIndex - 1].score )) {
    --insertIndex;
  }
  // Shift lower scores' scores to make space for the new score
  for (byte i = MAX_HIGHSCORES_SAVED - 1; i > insertIndex; --i) {
    highscoreStruct[i].score = highscoreStruct[i - 1].score;
    for (byte j = 0; j < 4; ++j) {
      highscoreStruct[i].name[j] = highscoreStruct[i - 1].name[j];
    }
  }
  // Insert the new score into the appropriate position
  highscoreStruct[insertIndex].score = newHscore.score;
  for (byte j = 0; j < 4; ++j) {
    highscoreStruct[insertIndex].name[j] = newHscore.name[j];
  }

  // Save highscores to EEPROM
  for (byte i = 0; i < MAX_HIGHSCORES_SAVED; ++i) {
    int address = highscoreAddress + i * sizeof(tHighscore);
    EEPROM.put(address, highscoreStruct[i]);
  }
  // Print highscores to Serial Monitor
  

  // Reset newHighscore and update menu and state
  newHighscore = 0;
  number=0;
  menuPosition = 0;
  stateControl = MAIN_MENU_CODE;
  printMainMenu(MENU_OPTION_1);

  // Update and limit highscoresSaved
  highscoresSaved++;
  if (highscoresSaved > MAX_HIGHSCORES_SAVED)
    highscoresSaved = MAX_HIGHSCORES_SAVED;

  // Save the updated highscoresSaved to EEPROM
  EEPROM.update(EEPROM_HIGHSCORE_ADDRESS, highscoresSaved);
}



void playGameTone(short toneType) {
  short toneDuration = 200; // Adjust the duration as needed
  // noTone(buzzerPin);
  if (!soundFlag) {
    return;
  }
  switch (toneType) {
    case SCROLL_MENU:
      tone(buzzerPin, SCROLL_MENU, toneDuration);
      break;
    case SELECT_OPTION:
      tone(buzzerPin, SELECT_OPTION, toneDuration);
      break;
    case BACK_MENU:
      tone(buzzerPin, BACK_MENU, toneDuration);
      break;
    case START_GAME:
      tone(buzzerPin, START_GAME, toneDuration*2);
      break;
    case MOVE_ON_MAP:
      tone(buzzerPin, MOVE_ON_MAP, toneDuration);
      break;
    case CLICK_POSITION_1:
      tone(buzzerPin, CLICK_POSITION_1, toneDuration);
      break;
    case CLICK_POSITION_2:
      tone(buzzerPin, CLICK_POSITION_2, toneDuration);
      break;
    case LOSE_GAME:
      tone(buzzerPin, LOSE_GAME, toneDuration*2);
      break;
    case WIN_GAME:
      tone(buzzerPin, WIN_GAME, toneDuration*2);
      break;
    default:
      // Invalid tone type, do nothing
      break;
  }
}



unsigned char detectInput() {
  unsigned char returnedInput = 0;
  // Check if a possible button press was detected
  if (possiblePress || possibleLongPress) {
    
    // Start the debounce counter if needed
    if (shouldStartCounter) {
      lastDebounceTime = millis();
      shouldStartCounter = false;
    }
    // If the debounce period has elapsed
    if ((millis() - lastDebounceTime) > debounceDelay && possiblePress) {
      // Read the current state of the button
      buttonReading = digitalRead(pinSW);
      // If the button state has changed (i.e., if it was not a false press)
      if (buttonReading != buttonState) {
        // Toggle the LED state if the button was truly pressed (read as LOW due to INPUT_PULLUP)
        if (buttonReading == LOW) {
          // Serial.println(F("click"));
          returnedInput = INPUT_CLICK;
        }
      }  // If the states match, it was a false alarm due to noise
      // Reset the possiblePress flag
      possiblePress = false;
    }
    if (millis() - lastDebounceTime > longPushDuration) {
      buttonReading = digitalRead(pinSW);
      if (buttonReading != buttonState) {
        // Reset the display if the button was truly long-pressed (read as LOW due to INPUT_PULLUP)
        if (buttonReading == LOW) {
          // Serial.println(F("long click"));
          returnedInput = INPUT_LONG_CLICK;
        }
      }  // If the states match, it was a false alarm due to noise
      // Reset the possibleLongPress flag
      possibleLongPress = false;
    }
  }
  
  if (!returnedInput && millis() - lastMoved > moveInterval) {  // Check if it's time to move the LED
    // Directional readings:
    xValue = analogRead(pinX);
    yValue = analogRead(pinY);
    // Checking if the values read are past the thresholds and selecting the 'highest' value
    // (if we move the joystick diagonally, we want to know if we went more towards one side, i.e. the North Northwest direction is more north than west)
    if (xValue > readingMaxThreshold && abs(xValue - centerReferenceValue) > abs(yValue - centerReferenceValue)) {
      returnedInput = INPUT_UP;
    }
    if (xValue < readingMinThreshold && abs(xValue - centerReferenceValue) > abs(yValue - centerReferenceValue)) {
      returnedInput = INPUT_DOWN;
    }
    if (yValue > readingMaxThreshold && abs(yValue - centerReferenceValue) > abs(xValue - centerReferenceValue)) {
      returnedInput = INPUT_RIGHT;
    }
    if (yValue < readingMinThreshold && abs(yValue - centerReferenceValue) > abs(xValue - centerReferenceValue)) {
      returnedInput = INPUT_LEFT;
    }
    
    lastMoved = millis();  // Update the time of the last move
  }
  if (returnedInput) {
    // Serial.print((char)returnedInput);
    // Serial.print(F("| "));
    // Serial.print(INPUT_UP);
    // Serial.print(INPUT_DOWN);
    // Serial.print(INPUT_RIGHT);
    // Serial.print(INPUT_LEFT);
    // Serial.print(INPUT_CLICK);
    // Serial.println(INPUT_LONG_CLICK);
  }
  return returnedInput;
}

void handleInterrupt() {
  // Serial.println("ISR");
  possiblePress = true; // Indicate that a button press might have occurred
  possibleLongPress = true; // Indicate that a long button press might have occurred
  shouldStartCounter = true; // Indicate the need to start the debounce counter
}














bool getExplored(byte x, byte y) {
  // return gameMap16[x][y].explored;
  return gameMap16[x][y].flags % 2;
}
bool getFlagged(byte x, byte y) {
  return (gameMap16[x][y].flags / 100) % 2;
}
bool getBlinkState(byte x, byte y) {
  return (gameMap16[x][y].flags / 10) % 2;
}
void setExplored(byte x, byte y, bool val) {
  gameMap16[x][y].flags = (gameMap16[x][y].flags/10)*10 + (val)?1:0;
}
void setFlagged(byte x, byte y, bool val) {
  gameMap16[x][y].flags = ((val)?1:0)*100 + gameMap16[x][y].flags%100;
}
void setBlinkState(byte x, byte y, bool val) {
  gameMap16[x][y].flags = (gameMap16[x][y].flags/100)*100 + ((val)?1:0)*10 + gameMap16[x][y].flags%10;
}



void Gameplay() {
  if (millis() - lastMoved > moveInterval) {  // Check if it's time to move the LED
    // game logic
    updatePositions();     // Update the position of the LED based on joystick input
    lastMoved = millis();  // Update the time of the last move
  }

  detectClick();

  if (millis() - lastBlinkToggleTime > blinkInterval) { // player blinking //KEEP
    blinkState = !blinkState;
    // matrix[xPos][yPos] = blinkState;
    lc.setLed(0, xPos16-xViewOrigin16, yPos16-yViewOrigin16, blinkState);
    lastBlinkToggleTime = millis();
  }


  updateBlinks();

  incrementCounter();

  gameOver = checkGameOver();
  
  // gameOver = false;
  if (gameOver) {
    endGame(VICTORY);
  }
}


void incrementCounter() {
  if (!paused) {
    if (millis() - lastIncrement > delayCount) {
      number++;
      if (number > 9999) {
        number = 9999;
      } 
      // short noteIndex = number%8;
      // tone(buzzerPin, melody[noteIndex], noteDuration);
      
      lastIncrement = millis();
      printGameStats();
    }
  }
  
}
void printGameStats() {
  short sum = computeBobmsLeft();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(F("("));
  lcd.setCursor(1, 0);
  lcd.print(xPos16);
  lcd.setCursor(3, 0);
  lcd.print(F(","));
  lcd.setCursor(4, 0);
  lcd.print(yPos16);
  lcd.setCursor(6, 0);
  lcd.print(F(")"));

  lcd.setCursor(9, 0);
  if (getExplored(xPos16,yPos16)) 
    lcd.print(gameMap16[xPos16][yPos16].value);
  else if (getFlagged(xPos16,yPos16))
    lcd.print(F("F"));
  else
    lcd.print(F("?"));
  

  if (sum>0) {
  lcd.setCursor(0, 1);
  lcd.print(F("B:"));
  lcd.setCursor(3,1);
  lcd.print((sum/10)%10);
  lcd.setCursor(4,1);
  lcd.print(sum%10);
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print(F("B:"));
    lcd.setCursor(3, 1);
    lcd.print(sum);
  }
  
  lcd.setCursor(7, 1);
  lcd.print(F("Time:"));
  lcd.setCursor(12, 1);
  if (number/1000)
    lcd.print(number/1000);
  lcd.setCursor(13, 1);
  lcd.print((number/100)%10);
  lcd.setCursor(14,1);
  lcd.print((number/10)%10);
  lcd.setCursor(15,1);
  lcd.print(number%10);
}


void initializeMap() {
  // Set all matrix elements to 0 and unexplored
  for (short i = 0; i < mapSize; ++i) {
    for (short j = 0; j < mapSize; ++j) {
      gameMap16[i][j].value = 0;
      // gameMap16[i][j].explored = false;
      setExplored(i, j, false);
      gameMap16[i][j].blinkCounter = 0;
      // gameMap16[i][j].numBlinkState = false;
      setBlinkState(i, j, false);
      // gameMap16[i][j].flagged = false;
      setFlagged(i, j, false);
      lc.setLed(0, i, j, true);
    }
  }
}
void placeBombAndCalculateAdjacent(short row, short col) {
  // Place bomb
  gameMap16[row][col].value = bombValue;
  // Update adjacent squares
  for (short dx = -1; dx <= 1; ++dx) {
    for (short dy = -1; dy <= 1; ++dy) {
      short ni = row + dx;
      short nj = col + dy;

      if (ni >= 0 && ni < mapSize && nj >= 0 && nj < mapSize && gameMap16[ni][nj].value != bombValue) {
        gameMap16[ni][nj].value++;
      }
    }
  }
}
void placeBombs() {
  for (byte bombCount = 0; bombCount < numBombs; ++bombCount) {
    short row = random(mapSize);
    short col = random(mapSize);
    // Check if the element is already a bomb, if not, place bomb and update adjacent
    if (gameMap16[row][col].value != bombValue) {
      placeBombAndCalculateAdjacent(row, col);
    } else {
      // If the element is already a bomb, try again
      --bombCount;
    }
  }
}
void generateMap() {
  randomSeed(analogRead(A4)); // Initialize random seed
  initializeMap();
  placeBombs();
}


void updateMap() {
  for (short row = 0+xViewOrigin16; row < xViewOrigin16+VIEW_SIZE; ++row) {
    for (short col = 0+yViewOrigin16; col < yViewOrigin16+VIEW_SIZE; ++col) {
      if (getExplored(row,col) && gameMap16[row][col].value != 0) {
        // if (gameMap[row][col].blinkCounter % 2 == 0) {
          lc.setLed(0, row-xViewOrigin16, col-yViewOrigin16, getBlinkState(row,col));
        // }
      }
      // lc.setLed(0, row, col, !gameMap[row][col].explored);
    }
  }
}


void updateBlinks() {
  currentNumberBlinkToggleTime = millis();
  if (currentNumberBlinkToggleTime - lastNumberBlinkPeriodTime >= numberBlinkPeriod) {
    lastNumberBlinkPeriodTime = currentNumberBlinkToggleTime;
    for (short row = 0; row < mapSize; ++row) {
      for (short col = 0; col < mapSize; ++col) {
        gameMap16[row][col].blinkCounter = 0;
        numberBlinkRest = !numberBlinkRest;
        setBlinkState(row, col, false);
      }
    }
    // numberBlinkState = false;
    // updateMap();
  }
  if (currentNumberBlinkToggleTime - lastNumberBlinkToggleTime >= numberBlinkInterval && numberBlinkRest) {
    lastNumberBlinkToggleTime = currentNumberBlinkToggleTime;
    numberBlinkState = !numberBlinkState;
    for (short row = 0; row < mapSize; ++row) {
      for (short col = 0; col < mapSize; ++col) {
        // if (gameMap[row][col].explored && numberBlinkCounter <= gameMap[row][col].value) {
        if (getExplored(row, col)) {  
          if (gameMap16[row][col].blinkCounter / 2 < gameMap16[row][col].value) {
            setBlinkState(row, col, !getBlinkState(row, col));
            gameMap16[row][col].blinkCounter++;
          }
          // if (gameMap[row][col].blinkCounter > periodUnits) {
          //   gameMap[row][col].blinkCounter = 0;
          // }
          // lc.setLed(0, row, col, numberBlinkState);  // set each led individually
        }
      }
    }
    numberBlinkCounter++;
    updateMap();
  }
  if (currentNumberBlinkToggleTime - lastBombBlinktoggleTime >= bombBlinkInterval) {
    lastBombBlinktoggleTime = currentNumberBlinkToggleTime;
    bombBlinkState = !bombBlinkState;
    for (short row = 0+xViewOrigin16; row < xViewOrigin16+VIEW_SIZE; ++row) {
      for (short col = 0+yViewOrigin16; col < yViewOrigin16+VIEW_SIZE; ++col) {
        if (getFlagged(row, col)) {
          lc.setLed(0, row-xViewOrigin16, col-yViewOrigin16, bombBlinkState);
        }
      }
    }
  }
}









short computeBobmsLeft() {
  short sum = 0;
  for (short i=0; i<mapSize; ++i) 
    for (short j=0; j<mapSize; ++j) {
      if (getFlagged(i, j))  
        ++sum;
    }
  return numBombs-sum;
}
bool checkGameOver() {
  bool allBombsFlagged = true; // asuume
  byte sum = 0;
  byte flags = 0;
  for (short i=0; i<mapSize; ++i) 
    for (short j=0; j<mapSize; ++j) {
      if (!getExplored(i, j)) {
        ++sum;
      }
      if (getFlagged(i, j)) {
        ++flags;
      }
      if (gameMap16[i][j].value == 'B' && !getFlagged(i, j)) {
        allBombsFlagged = false;
      }
    }
  return ((sum==numBombs) || (flags==numBombs && allBombsFlagged));
}





// Function to read joystick input and update the position of the LED
void updatePositions() {
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  // Store the last positions of the LED
  xLastPos16 = xPos16;
  yLastPos16 = yPos16;
  // Update xPos based on joystick movement (X-axis)
  if (xValue < readingMinThreshold) {
    if (xPos16 < mapSize - 1) {
      xPos16++;
    } else {
      // xPos = 0;
    }
  }
  if (xValue > readingMaxThreshold) {
    if (xPos16 > 0) {
      xPos16--;
    } else {
      // xPos = matrixSize - 1;
    }
  }
  if (yValue > readingMaxThreshold) {
    if (yPos16 < mapSize - 1) {
      yPos16++;
    } else {
      // yPos = 0;
    }
  }
  // Update xPos based on joystick movement (Y-axis)
  if (yValue < readingMinThreshold) {
    if (yPos16 > 0) {
      yPos16--;
    } else {
      // yPos = matrixSize - 1;
    }
  }
  // Check if the position has changed and update the matrix if necessary
  // if (matrix[xPos][yPos] == 1) {
  //   xPos = xLastPos;
  //   yPos = yLastPos;
  // }
  if (xPos16 != xLastPos16 || yPos16 != yLastPos16) {
    if (!isInsideView()) {
      xViewOrigin16 = xViewOrigin16 + xPos16-xLastPos16;
      yViewOrigin16 = yViewOrigin16 + yPos16-yLastPos16;
      shiftUpdateMap();
    }
    playGameTone(MOVE_ON_MAP);
    printGameStats();
    // matrixChanged = true;
    // matrix[xLastPos][yLastPos] = 0;
    // matrix[xPos][yPos] = 1;
    bool restoredState = false;
    if (!getExplored(xLastPos16, yLastPos16)) {
      restoredState = true;
    }
    else {
      restoredState = getBlinkState(xPos16, yPos16);
      // restoredState = true;
    }
    lc.setLed(0, xLastPos16-xViewOrigin16, yLastPos16-yViewOrigin16, restoredState);

    bool newState = false;
    if (!getExplored(xPos16, yPos16)) {
      newState = false;
      blinkState = false;
    }
    else {
      newState = true;
      blinkState = true;
    }
    lc.setLed(0, xPos16-xViewOrigin16, yPos16-yViewOrigin16, newState);

    lastBlinkToggleTime = millis();
  }
}

bool isInsideView() {
  return xPos16 >= xViewOrigin16 && yPos16 >= yViewOrigin16 && xPos16 < xViewOrigin16+VIEW_SIZE && yPos16 < yViewOrigin16+VIEW_SIZE;
}

void shiftUpdateMap() {
  for (short row = 0+xViewOrigin16; row < xViewOrigin16+VIEW_SIZE; ++row) {
    for (short col = 0+yViewOrigin16; col < yViewOrigin16+VIEW_SIZE; ++col) {
      if (getExplored(row, col) && gameMap16[row][col].value != 0) {
        // if (gameMap[row][col].blinkCounter % 2 == 0) {
        lc.setLed(0, row-xViewOrigin16, col-yViewOrigin16, getBlinkState(row,col));
        // }
      }
      else if (getFlagged(row, col)) {
        lc.setLed(0, row-xViewOrigin16, col-yViewOrigin16, bombBlinkState);
      }
      else if (!getExplored(row, col)) {
        lc.setLed(0, row-xViewOrigin16, col-yViewOrigin16, true);
      }

      // lc.setLed(0, row, col, !gameMap[row][col].explored);
    }
  }
}



void detectClick() {
  if(possiblePress) {
    // Start the debounce counter if needed
    if (shouldStartCounter) {
      lastDebounceTime = millis();
      shouldStartCounter = false;
    }
    // If the debounce period has elapsed
    if ((millis() - lastDebounceTime) > debounceDelay && possiblePress) {
      // Read the current state of the button
      buttonReading = digitalRead(pinSW);
      // If the button state has changed (i.e., if it was not a false press)
      if (buttonReading != buttonState) {
        // Toggle the LED state if the button was truly pressed (read as LOW due to INPUT_PULLUP)
        if (buttonReading == LOW) {
          // 
          if (!getExplored(xPos16, yPos16) && !getFlagged(xPos16, yPos16)) {
            playGameTone(CLICK_POSITION_1);
            exploreTile(mapSize, xPos16, yPos16);
          }
        }
      }  // If the states match, it was a false alarm due to noise
      // Reset the possiblePress flag
      possiblePress = false;
    }
  }

  flagButtonReading = digitalRead(flagButtonPin);
   if (flagButtonReading != flagLastReading ) {
     flagLastDebounceTime = millis();
   }
   if ((millis() - flagLastDebounceTime) > flagDebounceDelay) {
     if (flagButtonReading != flagButtonState) {
       flagButtonState = flagButtonReading;
       if (flagButtonState == LOW) {
          if (!getExplored(xPos16, yPos16)) {
            playGameTone(CLICK_POSITION_2);
            toggleFlag();
          }
       }
     }
   }
   flagLastReading = flagButtonReading;
}





void exploreTile(byte mapSize, short x, short y) {
  setExplored(x, y, true);
  if (gameMap16[x][y].value == 'B') {
    endGame(EXPLOSION);
  }
  if (gameMap16[x][y].value == 0) {
    lc.setLed(0, x-xViewOrigin16, y-yViewOrigin16, getBlinkState(x, y));
    short ni;
    short nj;
    for (short dx = -1; dx <= 1; ++dx) {
      for (short dy = -1; dy <= 1; ++dy) {
        ni = x + dx;
        nj = y + dy;
        if (ni >= 0 && ni < mapSize && nj >= 0 && nj < mapSize && !getExplored(ni, nj)) {
          exploreTile(mapSize, ni, nj);
        }
      }
    }
  }
}


void toggleFlag() {
  setFlagged(xPos16, yPos16, !getFlagged(xPos16, yPos16));
  // gameMap16[xPos16][yPos16].flagged = !gameMap16[xPos16][yPos16].flagged;
  // gameMap[xPos][yPos].explored = !gameMap[xPos][yPos].explored;
}


void endGame(byte outcome) {

  // generateMap();
  xPos16 = 0;
  yPos16 = 0;
  stateControl = END_MESSAGE_CODE;
  if (outcome == VICTORY) {
    playGameTone(WIN_GAME);
    printEndMessage(VICTORY, number);
    gameOver = false;
  }
  else {
    playGameTone(LOSE_GAME);
    printEndMessage(EXPLOSION, 9999);
  }

}





