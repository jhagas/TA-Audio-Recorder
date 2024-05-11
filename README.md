# Simple Arduino Nano Audio Recorder

Flow:

- Computer send "RECORD" message via serial communication
- Arduino Nano record audio (analog input) data from A0, A2, A4. 2 seconds each, store to MicroSD Card
- Arduino Nano send that audio files to computer via serial communication

## Communication Rules

`CODE:Message`

For example `Error:An Error has occurred while mounting SD`
