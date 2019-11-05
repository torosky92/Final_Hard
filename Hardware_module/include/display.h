#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//#include <message.h>

class DisplayHandler : public Adafruit_SSD1306 {
    public:
        DisplayHandler(int rst): Adafruit_SSD1306(rst) {

        }
        void base(bool clear, int color);
        void template1(String Product, String Price, String Date);
        void template2(String Product, int Cant, String Code);
        //int handle(Message msg);
    private:
        //Message actual_message;
};

//int DisplayHandler::handle(Message input){}

void DisplayHandler::base(bool clear=false, int color=WHITE){
    if(!clear){
        this->clearDisplay();
        this->setTextColor(WHITE);
        this->setCursor(0, 0);
        this->setTextSize(2); // Draw 2X-scale text
        this->print("Setting");
        this->setCursor(0, 15);
        this->setTextSize(1); // Draw 2X-scale text
        this->print("Initialize...");
        this->display();      // Show initial text
    }
}

void DisplayHandler::template1(String Product, String Price, String Date){
    this->clearDisplay();
    this->setTextColor(WHITE);
    this->setCursor(0, 0);
    this->setTextSize(2); // Draw 2X-scale text
    this->print("PROD:");
    this->setCursor(0, 15);
    this->setTextSize(1); // Draw 2X-scale text
    this->print("Price:");
    this->setCursor(0, 25);
    this->setTextSize(1); // Draw 2X-scale text
    this->print("Exp:");
    this->setCursor(60, 5);
    this->setTextSize(1); // Draw 2X-scale text
    this->print(Product);
    this->setCursor(40, 15);
    this->setTextSize(1); // Draw 2X-scale text
    this->print(Price);
    this->setCursor(30, 25);
    this->setTextSize(1); // Draw 2X-scale text
    this->print(Date);
    this->display();      // Show initial text
}

void DisplayHandler::template2(String Product, int Cant, String Code){
    this->clearDisplay();
    this->setTextColor(WHITE);
    this->setCursor(0, 0);
    this->setTextSize(2); // Draw 2X-scale text
    this->print("PROD:");
    this->setCursor(0, 15);
    this->setTextSize(1); // Draw 2X-scale text
    this->print("Cant:");
    this->setCursor(0, 25);
    this->setTextSize(1); // Draw 2X-scale text
    this->print("Code:");
    this->setCursor(60, 5);
    this->setTextSize(1); // Draw 2X-scale text
    this->print(Product);
    this->setCursor(40, 15);
    this->setTextSize(1); // Draw 2X-scale text
    this->print(String(Cant));
    this->setCursor(40, 25);
    this->setTextSize(1); // Draw 2X-scale text
    this->print(Code);
    this->display();      // Show initial text
}