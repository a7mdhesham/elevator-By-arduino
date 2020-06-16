

#include <Stepper.h>
#include <Keypad.h>
#include <LiquidCrystal.h> 
//stepper constants
Stepper steppermotor(32, 8, 10, 9, 11);
int f=0;
float s = 7233.33;
//keybad constants
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {30,31,32,33}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {34,35,36}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//LCD
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
void setup()
{
// Nothing for stepper  (Stepper Library sets pins as outputs)
  Serial.begin(9600);
  Serial.println("Robojax 4x3 keypad");
  lcd.begin(16, 2);
}
void printFloor()
{
  lcd.setCursor(4,0);
  lcd.print("Floor ");
  lcd.print(f);
  }
  void up(float steps)
{
  steppermotor.setSpeed(1000);  
   for(int i=0 ; i < steps ; i++)
  {
    printFloor();
    lcd.setCursor(3,1);
    lcd.print(" << UP >>");
    steppermotor.step(1);
  }
  lcd.clear();
 // steppermotor.step(steps);
}
void down(float steps)
{
  steppermotor.setSpeed(1000);  
  /*for(int i=steps ; i <= 0 ; i++)
  {
    printFloor();
    lcd.setCursor(2,1);
    lcd.print("<< DOWN >>");
  steppermotor.step(-1);
  }
  lcd.clear();*/
  steppermotor.step(steps);
}
void loop()
{
  printFloor();
  char key = keypad.getKey();
  int k;
  switch(key)
  {
    case '0':
    k=-f;
    if(k>0)
    {
      up(s*k);
    }
    else if (k<0)
    {
      down(s*k);
    }
    f=0;
    break;
    case '1':
    k=1-f;
     if(k>0)
    {
      up(s*k);
    }
    else if (k<0)
    {
      down(s*k);
    }
    f=1;
    break;
    case '2':
    k=2-f;
     if(k>0)
    {
      up(s*k);
    }
    else if (k<0)
    {
      down(s*k);
    }
    f=2;
    break;
    case '3':
    k=3-f;
     if(k>0)
    {
      up(s*k);
    }
    else if (k<0)
    {
      down(s*k);
    }
    f=3;
    break;

    default:
    int c = 1;
  }
}