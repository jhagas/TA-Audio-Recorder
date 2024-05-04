#include <Arduino.h>
#include <TMRpcm.h>
#include <SD.h>
#include <SPI.h>
#include "const.h"
#include "functions.hpp"

TMRpcm audio; // make instance variable
int file_number = 0;
char filePrefixname[50] = "spy";
char exten[10] = ".wav";

void setup()
{
  // initializes the serial connection between the Arduino and any connected serial device(e.g. computer, phone, raspberry pi...)
  Serial.begin(115200);
  // Sets up the pins
  pinMode(mic_pin0, INPUT);
  Serial.println("loading... SD card");
  if (!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("An Error has occurred while mounting SD");
  }
  while (!SD.begin(SD_ChipSelectPin))
  {
    Serial.print(".");
    delay(500);
  }
  audio.CSPin = SD_ChipSelectPin;
}

void loop()
{
  Serial.println("####################################################################################");
  char fileSlNum[20] = "";
  itoa(file_number, fileSlNum, 10);
  char file_name[50] = "";
  strcat(file_name, filePrefixname);
  strcat(file_name, fileSlNum);
  strcat(file_name, exten);
  Serial.print("New File Name: ");
  Serial.println(file_name);

  audio.startRecording(file_name, sample_rate, mic_pin0);
  Serial.println("startRecording ");

  // record audio for 2 sec. means, in this loop process record 2 secs of audio.
  wait_min(2);

  audio.stopRecording(file_name);
  Serial.println("stopRecording");
  file_number++;
  Serial.println("####################################################################################");
}