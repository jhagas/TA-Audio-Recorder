#include <Arduino.h>

TMRpcm audio;
File myFile;

// delay function for serial log.
void wait_sec(int secs)
{
  int count = 0;
  while (1)
  {
    delay(1000);
    count++;
    if (count == secs)
    {
      count = 0;
      break;
    }
  }
  return;
}

void SD_init()
{
  Serial.println("EVENT:Initializing SD card");
  if (!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("ERROR:An Error has occurred while mounting SD");
  }
  else
  {
    Serial.println("EVENT:SD Card Intialized!");
  }
  while (!SD.begin(SD_ChipSelectPin))
  {
    delay(500);
  }
  audio.CSPin = SD_ChipSelectPin;
}