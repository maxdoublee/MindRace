#include <SimpleRSLK.h>
#include <LCD_5110.h>
#include <HCSR04.h>

#define CS 18
#define CLK 7
#define Din 15
#define DC 17
#define RST 35
#define BCKLIT 60
#define BCKLITPUSH 46
#define STRTBUTTON 19
#define calpushbutton 36
#define freeRoampushbutton 74
#define LEFTREDLED 37
#define LEFTGREENLED 33
#define nopushbutton 34
#define nextpushbutton 26
#define RIGHTGREENLED 44
#define RIGHTREDLED 42
#define yespushbutton 5
#define lefttrig 55
#define leftecho 32
#define righttrig 71
#define rightecho 23
#define middletrig 54
#define middleecho 70

LCD_5110 myScreen(CS, CLK, Din, DC, RST, BCKLIT, BCKLITPUSH);
boolean backlight = false;

uint16_t sensorVal[LS_NUM_SENSORS];
uint16_t sensorCalVal[LS_NUM_SENSORS];
uint16_t sensorMaxVal[LS_NUM_SENSORS];
uint16_t sensorMinVal[LS_NUM_SENSORS];
uint8_t lineColor = DARK_LINE;

HCSR04 leftUS(lefttrig, leftecho);
HCSR04 rightUS(righttrig, rightecho);
HCSR04 middleUS(middletrig, middleecho);

int startState = 0;
int yesState = 0;
int noState = 0;
int nextState = 0;
int calState = 0;
int LoadLEDsVar = 0;
int nextFlag = 0;
int calFlag = 0;
int bumperFlag = 0;
int calSpeed = 20;
int LeftEncoder = 0;
int RightEncoder = 0;
float motorSpeed = 0;
int encoderMin = 0;
int encoderLimit = 15;
int encoderNotWorking = 25;
int bumperState0 = 0;
int bumperState1 = 0;
int bumperState2 = 0;
int bumperState3 = 0;
int bumperState4 = 0;
int bumperState5 = 0;
int boundary = 0;
int hit = 0;
int wham = 0;
int done = 0;
int check = 0;
int backwards = 150;
int backwards2 = 300;
int display = 0;
int turn = 0;
int boom = 0;
int spin = 0;
int push = 0;
int thrower = 0;
int straight_reset1_var = 0;
long randStart = 0;
long randNum = 0;
long interval = 500;
unsigned long previousMillis = 0; 
unsigned long currentMillis = 0;
unsigned long prevMillisSec = 0;
unsigned long prevMillisMin = 0;
unsigned long prevMillisHour = 0;
unsigned long currentMillisSec = 0;
unsigned long currentMillisMin = 0;
unsigned long currentMillisHour = 0;
float edge1 = 18;
float edge2 = 12;
float edge3 = 12;
String convert1;
String convert2;
String convert3;
char state = 0;

void BCKLITE();
void StartInterrupt();
void NextInterrupt();
void CalInterrupt();
void Start();
void PreLoadLEDs();
void LoadLEDs();
void AllLEDs();
void OffLEDs();
void CalLEDs();
void VictoryLEDs();
void PreCalibration();
void NextCal();
void Calibration();
void CalStraight();
void Straight1();
void Straight2();
void Straight_reset1();
void Pre_Game();
void Start_Game();
void InitSpin();
void ObstacleCourse();
void UpdateTime1();
void UpdateTime2();
void Mindflex1();
void Mindflex2();
void OutofBounds1();
void OutofBounds2();
void LandMine();
void Victory();
void PlayAgain();
void Farewell();
void freeRoam();
void realFreeRoam();
void actuallyFreeRoam();
void BumperProtection();
void Off();
void DisplayProtection();

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  setupRSLK();
  pinMode(STRTBUTTON, INPUT_PULLUP);
  pinMode(yespushbutton, INPUT_PULLUP);
  pinMode(nopushbutton, INPUT_PULLUP);
  pinMode(nextpushbutton, INPUT_PULLUP);
  pinMode(calpushbutton, INPUT_PULLUP);
  pinMode(LEFTREDLED, OUTPUT);
  pinMode(RIGHTREDLED, OUTPUT);
  pinMode(LEFTGREENLED, OUTPUT);
  pinMode(RIGHTGREENLED, OUTPUT);
  pinMode(freeRoampushbutton, INPUT_PULLUP);
  pinMode(BP_SW_PIN_0,INPUT_PULLUP);
  pinMode(BP_SW_PIN_1,INPUT_PULLUP);
  pinMode(BP_SW_PIN_2,INPUT_PULLUP);
  pinMode(BP_SW_PIN_3,INPUT_PULLUP);
  pinMode(BP_SW_PIN_4,INPUT_PULLUP);
  pinMode(BP_SW_PIN_5,INPUT_PULLUP);
  digitalWrite(LEFTREDLED, LOW);
  digitalWrite(RIGHTREDLED, LOW);
  digitalWrite(LEFTGREENLED, LOW);
  digitalWrite(RIGHTGREENLED, LOW);
  attachInterrupt(digitalPinToInterrupt(BCKLITPUSH), BCKLITE, FALLING);
  attachInterrupt(digitalPinToInterrupt(STRTBUTTON), StartInterrupt, FALLING); //loadledvar 1
  attachInterrupt(digitalPinToInterrupt(nextpushbutton), NextInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(calpushbutton), CalInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(freeRoampushbutton), freeRoamInterrupt, FALLING); //loadledvar 2
  attachInterrupt(digitalPinToInterrupt(BP_SW_PIN_0), BumperInterrupt1, FALLING);
  attachInterrupt(digitalPinToInterrupt(BP_SW_PIN_1), BumperInterrupt1, FALLING);
  attachInterrupt(digitalPinToInterrupt(BP_SW_PIN_2), BumperInterrupt1, FALLING);
  attachInterrupt(digitalPinToInterrupt(BP_SW_PIN_3), BumperInterrupt2, FALLING);
  attachInterrupt(digitalPinToInterrupt(BP_SW_PIN_4), BumperInterrupt2, FALLING);
  attachInterrupt(digitalPinToInterrupt(BP_SW_PIN_5), BumperInterrupt2, FALLING);
  bumperState0 = digitalRead(BP_SW_PIN_0);
  bumperState1 = digitalRead(BP_SW_PIN_1);
  bumperState2 = digitalRead(BP_SW_PIN_2);
  bumperState3 = digitalRead(BP_SW_PIN_3);
  bumperState4 = digitalRead(BP_SW_PIN_4);
  bumperState5 = digitalRead(BP_SW_PIN_5);
  myScreen.begin();
  clearMinMax(sensorMinVal, sensorMaxVal);
  PreLoadLEDs();
}

void loop(){
  randStart = random(200);
  LoadLEDs();
  myScreen.setFont(1);
  myScreen.text(0, 0, "Welcome");
  myScreen.setFont(0);
  myScreen.text(0, 3, " Press middle button to play");
  if(LoadLEDsVar == 1){
    freeRoam();
  }
  else if(LoadLEDsVar == 2){
    Start();
  }
}
