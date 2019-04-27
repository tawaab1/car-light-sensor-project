int photoresistor = 0;
int firstThreshold = 700;
int secondThreshold= 400;

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();  

}

void loop() {
photoresistor = analogRead(A0);
  Serial.println(photoresistor); //trouble shooting purposes
  // put your main code here, to run repeatedly:
  lcd.clear(); //clearing the reading on the lcd display

  lcd.setCursor(0,0); //turn cursor to top left position
  if (photoresistor > firstThreshold)
  {
    lcd.print("Sunlight: Bright"); // print out result if the light density is above the first threshold.
  }
  if ((photoresistor < firstThreshold) && (photoresistor > secondThreshold))
  {
    lcd.print("Sunlight: Shady"); //print out result if the light density is below the first threshold but above the second threshold.
  }
  if (photoresistor < secondThreshold)
  {
    lcd.print("Sunlight: Dark"); //print out the result if the light is below both the first and second threshold.
  }

  lcd.setCursor(0,1);   //turn cursor to lower left position
  if (photoresistor > firstThreshold)
  {
    lcd.print("Drive Freely"); // print out result if the light density is above the first threshold.
  }
  if ((photoresistor < firstThreshold) && (photoresistor > secondThreshold))
  {
    lcd.print("Drive carefully");  //print out result if the light density is below the first threshold but above the second threshold.
  }
  if (photoresistor < secondThreshold)
  {
    lcd.print("Turn Lights on"); //print out the result if the light is below both the first and second threshold.
  }

  delay(1000); //dealy makes it easier to read
}
