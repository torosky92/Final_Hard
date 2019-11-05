#include <Arduino.h>

#include <pinout.h>
#include <display.h>
#include <MicroSD.h>


DisplayHandler display(OLED_RESET);
MicroSD Memory = MicroSD();

void setup() {
  Serial.begin(9600);
  setIO();
  Memory.setupSD(5);
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.base();
  delay(1000);
  
}

void loop() {
  //display.template1("Aguila","$1.05","15/11/19");
  //delay(20000);
  //display.template2("Aguila",12,"9356743");
  //Memory.writeFile(SD, "hello", "Hello ");
  //Memory.appendFile(SD, "hello", "World!\n");
  //Memory.readFile(SD, "hello");
  //delay(500);
  //display.template1("Aguila","$1.05","15/11/19");
}