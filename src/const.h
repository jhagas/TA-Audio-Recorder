#include <Arduino.h>

// defines the CS pin of the SD card.
#define SD_ChipSelectPin 10

// Microphone Pin
const int mic_pin[3] = {A0, A2, A4};

// Audio Recording Sample Rate
const int sample_rate = 16000;

// Filename
const char filename[3][50] = {"rec_1.wav", "rec_2.wav", "rec_3.wav"};