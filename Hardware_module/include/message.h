#include <Arduino.h>

struct metadata {
    float expiration;
    float discount;
};

class Message {
private:
    int id;
    float price;
    int inventory;   
public:
    Message(int id, float price, int inventory);
};

Message::Message(float price, int inventory){

}
