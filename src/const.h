#include <Arduino.h>

// defines the CS pin of the SD card.
#define SD_ChipSelectPin 10

// Microphone Pin
const int mic_pin0 = A0;
const int mic_pin1 = A2;
const int mic_pin2 = A4;

// Audio Recording Sample Rate
const int sample_rate = 16000;