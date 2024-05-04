#include <Arduino.h>

// delay function for serial log.
void wait_min(int secs)
{
  int count = 0;
  while (1)
  {
    Serial.print('.');
    delay(1000);
    count++;
    if (count == secs)
    {
      count = 0;
      break;
    }
  }
  Serial.println();
  return;
}
