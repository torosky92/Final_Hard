#include <Arduino.h>
#include <SD.h>
#include <FS.h>

class MicroSD {
    public:
        MicroSD();
        void setupSD(int SD_CS);
        void createDir(fs::FS &fs, const char * path);
        void removeDir(fs::FS &fs, const char * path);
        void readFile(fs::FS &fs, const char * path);
        bool writeFile(fs::FS &fs, const char * path, const char * message);
        bool appendFile(fs::FS &fs, const char * path, const char * message);
        bool renameFile(fs::FS &fs, const char * path1, const char * path2);
        bool deleteFile(fs::FS &fs, const char * path);
    private:
};

MicroSD::MicroSD(){
}

void MicroSD::setupSD(int SD_CS){
    if(!SD.begin(SD_CS)){ //Card Mount Failed
        return;
    }
    uint8_t cardType = SD.cardType();
    if(cardType == CARD_NONE){ // No SD card attached
        return;
    }
}

void MicroSD::createDir(fs::FS &fs, const char * path){
  fs.mkdir(String("/") + path); //Dir created
}

void MicroSD::removeDir(fs::FS &fs, const char * path){
  fs.rmdir(String("/") + path); // Dir removed
}

// Editar
void MicroSD::readFile(fs::FS &fs, const char * path){
  File file = fs.open(String("/") + path + String(".txt"));
  while(file.available()){
    Serial.write(file.read());
  }
}

// Editar
bool MicroSD::writeFile(fs::FS &fs, const char * path, const char * message){
  File file = fs.open(String("/") + path + String(".txt"), FILE_WRITE);
  if(file.print(message)){ //File written
    return true;
  }
  return false;
}

// Editar
bool MicroSD::appendFile(fs::FS &fs, const char * path, const char * message){
  File file = fs.open(String("/") + path + String(".txt"), FILE_APPEND);
  if(file.print(message)){
    return true;
  } 
  return false;
}

bool MicroSD::renameFile(fs::FS &fs, const char * path1, const char * path2){
  if (fs.rename(String("/") + path1 + String(".txt"), String("/") + path2 + String(".txt"))) { // File renamed
    return true;
  } 
  return false;
}

bool MicroSD::deleteFile(fs::FS &fs, const char * path){
  if(fs.remove(path)){ //File deleted
    return true;
  } 
  return false;
}
