# hackwestern2
Control an Arduino robot (hence, sketch) and make it dance via Twitch chat!
This was a project for Hack Western 2, which was held from Nov 27-29.

The Python script would run on a laptop that was connected to the robot via a serial cable.
The Python script grabs messages from the Twitch IRC, isolates commands, and sends input to the Arduino.
The Arduino then executes the command that was called.
