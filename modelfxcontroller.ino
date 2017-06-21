int redPin = 3;
int greenPin = 5;
int bluePin = 6;
int buttonApin = 9;
int buttonBpin = 10;
int indicatorPin = 13;

#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
  pinMode(indicatorPin, OUTPUT);  
}

void loop()
{
  // Set indicator on to know we are booted
  digitalWrite(indicatorPin, HIGH); 
  // set RBG off to start
  setColor(0, 0, 0);  
  // If button pression, show red explosion colour and then slowly fade
  if (digitalRead(buttonApin) == LOW)
  {
    setColor(255, 0, 0);  
    delay(1000);
    setColor(220, 0, 0);  
    delay(250);
    setColor(200, 0, 0);  
    delay(250);
    setColor(150, 0, 0);  
    delay(250);
    setColor(100, 0, 0);  
    delay(250);
    setColor(50, 0, 0);  
    delay(250);
    setColor(25, 0, 0);  
    delay(250);
    // Create random flame effect until the stop button is pushed
    do
    {   
      if (digitalRead(buttonBpin) == LOW)
      {
        break;
      }
      setColor(random(100)+150, random(120)+135, 0);
      delay(random(100));
    } while (true);
  }
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
