#include <Arduino.h>
#include <TMRpcm.h>
#include <SD.h>
#include <SPI.h>
#include "const.h"
#include "functions.hpp"

void setup()
{
  // initializes the serial connection between the Arduino and computers
  Serial.begin(115200);

  // Sets up the pins
  for (int i = 0; i < 3; i++)
  {
    pinMode(mic_pin[i], INPUT);
  }

  SD_init();
}

void loop()
{
  Serial.setTimeout(1000L);
  if (Serial.available() > 0)
  {
    String command = Serial.readString();
    command.trim();
    if (command == "RECORD")
    {
      // Clean all previous file in MicroSD
      Serial.println("EVENT:Cleaning MicroSD");
      for (int file_number = 0; file_number < 3; file_number++)
      {
        SD.remove(filename[file_number]);
      }

      // Record from 3 separate microphone, one by one
      for (int file_number = 0; file_number < 3; file_number++)
      {
        int microphone = file_number + 1;
        Serial.println("EVENT:Recording Microphone " + String(microphone));

        // record audio for 2 sec. means, in this loop process record 2 secs of audio.
        audio.startRecording(filename[file_number], sample_rate, mic_pin[file_number]);
        wait_sec(2);
        audio.stopRecording(filename[file_number]);
      }
      Serial.println("EVENT:Done Recording");

      // Sending data to PC
      Serial.println("EVENT:Sending Data to PC");
      for (int file_number = 0; file_number < 3; file_number++)
      {
        String name = filename[file_number];
        myFile = SD.open(filename[file_number]);
        if (myFile)
        {
          Serial.println("EVENT:Sending File " + name);
          delay(50);
          // read from the file until there's nothing else in it:
          while (myFile.available())
          {
            Serial.write(myFile.read());
          }
          Serial.print("\n");
          // close the file:
          myFile.close();
          delay(50);
        }
        else
        {
          // if the file didn't open, print an error:
          Serial.println("ERROR:Failed Opening " + name);
        }
      }
      Serial.println("EVENT:Done Sending Data to PC");
    }
  }
}