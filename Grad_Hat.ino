#include <OneWire.h>
#include <DallasTemperature.h>
#include <SevSeg.h>

// Data wire is plugged into pin A15 on the Arduino 
#define ONE_WIRE_BUS A15 

//update from SAnwandter

#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};
const byte col[] = {
  COL_1,COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};


// 8x8 display font. Custom designed by Merddyn using Miro Božík's sprite generator on http://robojax.com/learn/arduino/8x8LED/
byte EX[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte ALL[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte A[] = {B11100111,B11000011,B10011001,B10011001,B10000001,B10000001,B10011001,B10011001};
byte B[] = { B11000001,B10011001,B10011001,B11000001,B11000001,B10011001,B10011001,B11000001};
byte C[] = { B10000011,B10000001,B11111001,B11111001,B11111001,B11111001,B10000001,B10000011};
byte D[] = { B11000001,B10000001,B10011001,B10011001,B10011001,B10011001,B10000001,B11000001};
byte E[] = {B10000001,B10000001,B11111001,B11100001,B11100001,B11111001,B10000001,B10000001};
byte F[] = {B10000001,B10000001,B11111001,B11100001,B11100001,B11111001,B11111001,B11111001};
byte G[] = { B11000011,B10000001,B11111001,B11111001,B10001001,B10011001,B10000001,B11000011};
byte H[] = { B10011001,B10011001,B10011001,B10000001,B10000001,B10011001,B10011001,B10011001};
byte I[] = {B10000001,B10000001,B11100111,B11100111,B11100111,B11100111,B10000001,B10000001};
byte J[] = {B10011111,B10011111,B10011111,B10011111,B10011001,B10011001,B10000001,B11000011};
byte K[] = { B10011001,B10001001,B11000001,B11100001,B11100001,B11000001,B10001001,B10011001};
byte L[] = {B11111001,B11111001,B11111001,B11111001,B11111001,B11111001,B10000001,B10000001};
byte M[] = {B00111100,B00011000,B00000000,B00100100,B00100100,B00100100,B00100100,B00100100};
byte N[] = {B10011001,B10011001,B10010001,B10000001,B10000001,B10001001,B10011001,B10011001};
byte O[] = {B11000011,B10000001,B10011001,B10011001,B10011001,B10011001,B10000001,B11000011};
byte P[] = { B11000001,B10000001,B10011001,B10000001,B11000001,B11111001,B11111001,B11111001};
byte Q[] = {B11000011,B10111101,B10111101,B10111101,B10110101,B10101101,B11011101,B10100011};
byte R[] = {B11000001,B10000001,B10011001,B10011001,B11000001,B10000001,B10011001,B10011001};
byte S[] = {B10000011,B10000001,B11111001,B10000001,B10000001,B10011111,B10000001,B11000001};
byte T[] = { B10000001,B10000001,B11100111,B11100111,B11100111,B11100111,B11100111,B11100111};
byte U[] = {B10011001,B10011001,B10011001,B10011001,B10011001,B10011001,B10000001,B11000011};
byte V[] = {B10011001,B10011001,B10011001,B10011001,B10011001,B10000001,B11000011,B11100111};
byte W[] = {B00111100,B00111100,B00100100,B00100100,B00100100,B00000000,B00011000,B10011001};
byte X[] = {B01111110,B10111101,B11011011,B11100111,B11100111,B11011011,B10111101,B01111110};
byte Y[] = {B10011001,B10011001,B10011001,B10000001,B11000011,B11100111,B11100111,B11100111};
byte Z[] = {B10000001,B10000001,B10001111,B11000111,B11100011,B11110001,B10000001,B10000001};
byte DOLLAR[] = { B11100111,B10000001,B11100101,B11100101,B10000001,B10100111,B10000001,B11100111};
byte ONE[] = {B11100111,B11100011,B11100001,B11100111,B11100111,B11100111,B10000001,B10000001};
byte TWO[] = { B10000001,B10000001,B10011111,B10000001,B10000001,B11111001,B10000001,B10000001};
byte THREE[] = {B11000001,B10000001,B10011111,B10000011,B10000011,B10011111,B10000001,B11000001};
byte FOUR[] = {B10011001,B10011001,B10011001,B10000001,B10000001,B10011111,B10011111,B10011111};
byte FIVE[] = {B10000001,B10000001,B11111001,B11000001,B10000001,B10011111,B10000001,B11000001};
byte SIX[] = {B11000011,B10000001,B11111001,B11000001,B10000001,B10011001,B10000001,B11000011};
byte SEVEN[] = {B10000001,B10000001,B10011111,B10011111,B10011111,B10011111,B10011111,B10011111};
byte EIGHT[] = {B11000011,B10000001,B10011001,B10000001,B10000001,B10011001,B10000001,B11000011};
byte NINE[] = {B11000011,B10000001,B10011001,B10000001,B10000011,B10011111,B10000001,B11000011};
byte ZERO[] = {B10000001,B10000001,B10011001,B10011001,B10011001,B10011001,B10000001,B10000001};
byte DASH[] = {B11111111,B11111111,B11111111,B10000001,B10000001,B11111111,B11111111,B11111111};

float timeCount = 0;

/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 

// Type of the seven segment display.
int displayType = COMMON_CATHODE;

SevSeg myDisplay;

//Create global variables
unsigned long timer;
int deciSecond = 0;
float temp, last_temp = 0;
char tempString[10]; //Used for sprintf
unsigned long textTime = 0;
    
void setup() 
{
  // start serial port 
  Serial.begin(9600); 
  Serial.println("Dallas Temperature IC Control Library Demo"); 
  // Start up the temperature library 
  sensors.begin(); 
  

  // Number of digits
  int digits = 4;
  
  // Digit control pins for seven segment display.  
  int digit1 = 26; // R1
  int digit2 = 20; // R2
  int digit3 = 19; // R3
  int digit4 = 18; // R4
  
  // Segment Control Pins for seven segment display.
  int SegA = 14; // T2
  int SegB = 28; // T6
  int SegC = 29; // B4
  int SegD = 30; // B2
  int SegE = 32; // B1
  int SegF = 34; // T3
  int SegG = 22; // B5
  int SegDP = 36; // B3
  // B6 is resistor 4
  // T1 is R1
  // T4 is R2
  // T5 is R3
    myDisplay.Begin(displayType, digits, digit1, digit2, digit3, digit4, SegA, SegB, SegC, SegD, SegE, SegF, SegG, SegDP);
  
  myDisplay.SetBrightness(100); //Set the display to 100% brightness level

  // Set all used pins to OUTPUT
    // This is very important! If the pins are set to input
    // the display will be very dim.
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() 
{
  temp = 66;
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus 
  // Between each message on the 8x8 display, check the current temperature. 
  // This is because it takes a moment and neither display displays anything while the temperature is being checked. 
  // Therefore we're running this at times that the 8x8 display should be blank anyway.
  if (textTime == 0 || textTime == 4550 || textTime == 7650 || textTime == 11050 || textTime == 15850)
  {
    /********************************************************************/
    Serial.print(" Requesting temperatures..."); 
    sensors.requestTemperatures(); // Send the command to get temperature readings 
    Serial.println("DONE"); 
  /********************************************************************/
    Serial.print("Temperature is: "); 
    temp = sensors.getTempFByIndex(0);
    temp *= 10;
    int Temperature = temp;
    Serial.print(Temperature);
      
    sprintf(tempString, "%4d", Temperature); //Convert deciSecond into a string that is right adjusted
    
  }
  myDisplay.DisplayString(tempString, 4); //(numberToDisplay, decimal point location)
     
  //Example ways of displaying a decimal number
  //sprintf(tempString, "%d", deciSecond); //Convert deciSecond into a string that is left adjusted
  //sprintf(tempString, "%04d", deciSecond); //Convert deciSecond into a string with leading zeros
  //sprintf(tempString, "%4d", deciSecond * -1); //Shows a negative sign infront of right adjusted number
  //sprintf(tempString, "%4X", deciSecond); //Count in HEX, right adjusted

  //Produce an output on the display
 
  //Other examples
  //myDisplay.DisplayString(tempString, 0); //Display string, no decimal point
  //myDisplay.DisplayString("-23b", 3); //Display string, decimal point in third position

  textTime += 2; // Adjust the time that each letter cycles by adjusting this.                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ;
  checkText(textTime);
  
  if (textTime > 18800)
    textTime = 0; 
}

// checkText handles what letter to draw each cycle through the loop.
void checkText(int timeCount)
{
  // Displays "If you can read this you're staring too long"
  if(timeCount <  100) 
  {
    drawScreen(I);
  } 
  else if (timeCount <  200) 
  {
    drawScreen(F);
  } 
  else if (timeCount <  300) 
  {
    drawScreen(EX);
  } 
  else if (timeCount <  400) 
  {
    drawScreen(Y);
  } 
  else if (timeCount <  500) 
  {
    drawScreen(O);
  } 
  else if (timeCount <  600) 
  {
    drawScreen(U);
  } 
  else if (timeCount <  700) 
  {
    drawScreen(EX);
  } 
  else if (timeCount <  800) 
  {
    drawScreen(C);
  } 
  else if (timeCount <  900) 
  {
    drawScreen(A);
  }
  else if (timeCount <  1000) 
  {
    drawScreen(N);
  }
  else if (timeCount <  1100) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  1200) 
  {
    drawScreen(R);
  }
  else if (timeCount <  1300) 
  {
    drawScreen(E);
  }
  else if (timeCount <  1400) 
  {
    drawScreen(A);
  }
  else if (timeCount <  1500) 
  {
    drawScreen(D);
  }
  else if (timeCount <  1600) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  1700) 
  {
    drawScreen(T);
  }
  else if (timeCount <  1800) 
  {
    drawScreen(H);
  }
  else if (timeCount <  1900) 
  {
    drawScreen(I);
  }
  else if (timeCount <  2000) 
  {
    drawScreen(S);
  }
  else if (timeCount <  2100) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  2200) 
  {
    drawScreen(Y);
  }
  else if (timeCount <  2300) 
  {
    drawScreen(O);
  }
  else if (timeCount <  2400) 
  {
    drawScreen(U);
  }
  else if (timeCount <  2500) 
  {
    drawScreen(R);
  }
  else if (timeCount <  2600) 
  {
    drawScreen(E);
  }
  else if (timeCount <  2700) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  2800) 
  {
    drawScreen(S);
  }
  else if (timeCount <  2900) 
  {
    drawScreen(T);
  }
  else if (timeCount <  3000) 
  {
    drawScreen(A);
  }
  else if (timeCount <  3100) 
  {
    drawScreen(R);
  }
  else if (timeCount <  3200) 
  {
    drawScreen(I);
  }
  else if (timeCount <  3300) 
  {
    drawScreen(N);
  }
  else if (timeCount <  3400) 
  {
    drawScreen(G);
  }
  else if (timeCount <  3500) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  3600) 
  {
    drawScreen(T);
  }
  else if (timeCount <  3700) 
  {
    drawScreen(O);
  }
  else if (timeCount <  3800) 
  {
    drawScreen(O);
  }
  else if (timeCount <  3900) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  4000) 
  {
    drawScreen(L);
  }
  else if (timeCount <  4100) 
  {
    drawScreen(O);
  }
  else if (timeCount <  4200) 
  {
    drawScreen(N);
  }
  else if (timeCount <  4300) 
  {
    drawScreen(G);
  } 
  else if (timeCount <  4400) 
  {
    drawScreen(EX);
  } 
  else if (timeCount <  4500) 
  {
    drawScreen(EX);
  } 
  else if (timeCount <  4600) 
  {
    drawScreen(EX);
  } 
  // ===========================================================
  // Displays "Bachelor of Computer Science"
  else if (timeCount <  4700) 
  {
    drawScreen(B);
  }
  else if (timeCount <  4800) 
  {
    drawScreen(A);
  }
  else if (timeCount <  4900) 
  {
    drawScreen(C);
  }
  else if (timeCount <  5000) 
  {
    drawScreen(H);
  }
  else if (timeCount <  5100) 
  {
    drawScreen(E);
  }
  else if (timeCount <  5200) 
  {
    drawScreen(L);
  }
  else if (timeCount <  5300) 
  {
    drawScreen(O);
  }
  else if (timeCount <  5400) 
  {
    drawScreen(R);
  }
  else if (timeCount <  5500) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  5600) 
  {
    drawScreen(O);
  }
  else if (timeCount <  5700) 
  {
    drawScreen(F);
  }
  else if (timeCount <  5800) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  5900) 
  {
    drawScreen(C);
  }
  else if (timeCount <  6000) 
  {
    drawScreen(O);
  }
  else if (timeCount <  6100) 
  {
    drawScreen(M);
  }
  else if (timeCount <  6200) 
  {
    drawScreen(P);
  }
  else if (timeCount <  6300) 
  {
    drawScreen(U);
  }
  else if (timeCount <  6400) 
  {
    drawScreen(T);
  }
  else if (timeCount <  6500) 
  {
    drawScreen(E);
  }
  else if (timeCount <  6600) 
  {
    drawScreen(R);
  }
  else if (timeCount <  6700) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  6800) 
  {
    drawScreen(S);
  }
  else if (timeCount <  6900) 
  {
    drawScreen(C);
  }
  else if (timeCount <  7000) 
  {
    drawScreen(I);
  }
  else if (timeCount <  7100) 
  {
    drawScreen(E);
  }
  else if (timeCount <  7200) 
  {
    drawScreen(N);
  }
  else if (timeCount <  7300) 
  {
    drawScreen(C);
  }
  else if (timeCount <  7400) 
  {
    drawScreen(E);
  }
  else if (timeCount <  7500) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  7600) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  7700) 
  {
    drawScreen(EX);
  }
  //====================================================
  // Display "This degree cost me over $76043"
  else if (timeCount <  7800) 
  {
    drawScreen(T);
  }
  else if (timeCount <  7900) 
  {
    drawScreen(H);
  }
  else if (timeCount <  8000) 
  {
    drawScreen(I);
  }
  else if (timeCount <  8100) 
  {
    drawScreen(S);
  }
  else if (timeCount <  8200) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  8300) 
  {
    drawScreen(D);
  }
  else if (timeCount <  8400) 
  {
    drawScreen(E);
  }
  else if (timeCount <  8500) 
  {
    drawScreen(G);
  }
  else if (timeCount <  8600) 
  {
    drawScreen(R);
  }
  else if (timeCount <  8700) 
  {
    drawScreen(E);
  }
  else if (timeCount <  8800) 
  {
    drawScreen(E);
  }
  else if (timeCount <  8900) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  9000) 
  {
    drawScreen(C);
  }
  else if (timeCount <  9100) 
  {
    drawScreen(O);
  }
  else if (timeCount <  9200) 
  {
    drawScreen(S);
  }
  else if (timeCount <  9300) 
  {
    drawScreen(T);
  }
  else if (timeCount <  9400) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  9500) 
  {
    drawScreen(M);
  }
  else if (timeCount <  9600) 
  {
    drawScreen(E);
  }
  else if (timeCount <  9700) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  9800) 
  {
    drawScreen(O);
  }
  else if (timeCount <  9900) 
  {
    drawScreen(V);
  }
  else if (timeCount <  10000) 
  {
    drawScreen(E);
  }
  else if (timeCount <  10100) 
  {
    drawScreen(R);
  }
  else if (timeCount <  10200) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  10300) 
  {
    drawScreen(DOLLAR);
  }
  else if (timeCount <  10400) 
  {
    drawScreen(SEVEN);
  }
  else if (timeCount <  10500) 
  {
    drawScreen(SIX);
  }
  else if (timeCount <  10600) 
  {
    drawScreen(ZERO);
  }
  else if (timeCount <  10700) 
  {
    drawScreen(FOUR);
  }
  else if (timeCount <  10800) 
  {
    drawScreen(THREE);
  }
  else if (timeCount <  10900) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  11000) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  11100) 
  {
    drawScreen(EX);
  }
  // =====================================================
  // Displays "See other display for the current temperature"
  else if (timeCount <  11200) 
  {
    drawScreen(S);
  }
  else if (timeCount <  11300) 
  {
    drawScreen(E);
  }
  else if (timeCount <  11400)
  {
    drawScreen(E);
  }
  else if (timeCount <  11500) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  11600) 
  {
    drawScreen(O);
  }
  else if (timeCount <  11700) 
  {
    drawScreen(T);
  }
  else if (timeCount <  11800) 
  {
    drawScreen(H);
  }
  else if (timeCount <  11900) 
  {
    drawScreen(E);
  }
  else if (timeCount <  12000) 
  {
    drawScreen(R);
  }
  else if (timeCount <  12100) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  12200) 
  {
    drawScreen(D);
  }
  else if (timeCount <  12300) 
  {
    drawScreen(I);
  }
  else if (timeCount <  12400) 
  {
    drawScreen(S);
  }
  else if (timeCount <  12500) 
  {
    drawScreen(P);
  }
  else if (timeCount <  12600) 
  {
    drawScreen(L);
  }
  else if (timeCount <  12700) 
  {
    drawScreen(A);
  }
  else if (timeCount <  12800) 
  {
    drawScreen(Y);
  }
  else if (timeCount <  12900) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  13000) 
  {
    drawScreen(F);
  }
  else if (timeCount <  13100) 
  {
    drawScreen(O);
  }
  else if (timeCount <  13200) 
  {
    drawScreen(R);
  }
  else if (timeCount <  13300) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  13400) 
  {
    drawScreen(T);
  }
  else if (timeCount <  13500) 
  {
    drawScreen(H);
  }
  else if (timeCount <  13600) 
  {
    drawScreen(E);
  }
  else if (timeCount <  13700) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  13800) 
  {
    drawScreen(C);
  }
  else if (timeCount <  13900) 
  {
    drawScreen(U);
  }
  else if (timeCount <  14000) 
  {
    drawScreen(R);
  }
  else if (timeCount <  14100) 
  {
    drawScreen(R);
  }
  else if (timeCount <  14200) 
  {
    drawScreen(E);
  }
  else if (timeCount <  14300) 
  {
    drawScreen(N);
  }
  else if (timeCount <  14400) 
  {
    drawScreen(T);
  }
  else if (timeCount <  14500) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  14600) 
  {
    drawScreen(T);
  }
  else if (timeCount <  14700) 
  {
    drawScreen(E);
  }
  else if (timeCount <  14800) 
  {
    drawScreen(M);
  }
  else if (timeCount <  14900) 
  {
    drawScreen(P);
  }
  else if (timeCount <  15000) 
  {
    drawScreen(E);
  }
  else if (timeCount <  15100) 
  {
    drawScreen(R);
  }
  else if (timeCount <  15200) 
  {
    drawScreen(A);
  }
  else if (timeCount <  15300) 
  {
    drawScreen(T);
  }
  else if (timeCount <  15400) 
  {
    drawScreen(U);
  }
  else if (timeCount <  15500) 
  {
    drawScreen(R);
  }
  else if (timeCount <  15600) 
  {
    drawScreen(E);
  }
  else if (timeCount <  15700) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  15800) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  15900) 
  {
    drawScreen(EX);
  }
  //================================= 
  // Displays "Congrats everyone -Merddyn"
  else if (timeCount <  16000) 
  {
    drawScreen(C);
  }
  else if (timeCount <  16100) 
  {
    drawScreen(O);
  }
  else if (timeCount <  16200) 
  {
    drawScreen(N);
  }
  else if (timeCount <  16300) 
  {
    drawScreen(G);
  }
  else if (timeCount <  16400) 
  {
    drawScreen(R);
  }
  else if (timeCount <  16500) 
  {
    drawScreen(A);
  }
  else if (timeCount <  16600) 
  {
    drawScreen(T);
  }
  else if (timeCount <  16700) 
  {
    drawScreen(S);
  }
  else if (timeCount <  16800) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  16900) 
  {
    drawScreen(E);
  }
  else if (timeCount <  17000) 
  {
    drawScreen(V);
  }
  else if (timeCount <  17100) 
  {
    drawScreen(E);
  }
  else if (timeCount <  17200) 
  {
    drawScreen(R);
  }
  else if (timeCount <  17300) 
  {
    drawScreen(Y);
  }
  else if (timeCount <  17400) 
  {
    drawScreen(O);
  }
  else if (timeCount <  17500) 
  {
    drawScreen(N);
  }
  else if (timeCount <  17600) 
  {
    drawScreen(E);
  }
  else if (timeCount <  17700) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  17800) 
  {
    drawScreen(DASH);
  }
  else if (timeCount <  17900) 
  {
    drawScreen(M);
  }
  else if (timeCount <  18000) 
  {
    drawScreen(E);
  }
  else if (timeCount <  18100) 
  {
    drawScreen(R);
  }
  else if (timeCount <  18200) 
  {
    drawScreen(D);
  }
  else if (timeCount <  18300) 
  {
    drawScreen(D);
  }
  else if (timeCount <  18400) 
  {
    drawScreen(Y);
  }
  else if (timeCount <  18500) 
  {
    drawScreen(N);
  }
  else if (timeCount <  18600) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  18700) 
  {
    drawScreen(EX);
  }
  else if (timeCount <  18800) 
  {
    drawScreen(EX);
  }

  
}


 void  drawScreen(byte buffer2[])
 { 
   // Turn on each row in series
    for (byte i = 0; i < 8; i++)        // count next row
     {
        digitalWrite(rows[i], HIGH);    //initiate whole row
        for (byte a = 0; a < 8; a++)    // count next row
        {
          // if You set (~buffer2[i] >> a) then You will have positive
          digitalWrite(col[a], (buffer2[i] >> a) & 0x01); // initiate whole column
          
          delayMicroseconds(100);       // uncoment deley for diferent speed of display
          //delayMicroseconds(1000);
          //delay(10);
          //delay(100);
          
          digitalWrite(col[a], 1);      // reset whole column
        }
        digitalWrite(rows[i], LOW);     // reset whole row
  //       otherwise last row will intersect with next row
    }
}
// 
