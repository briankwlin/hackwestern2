#NOTE: YOU MAY NEED TO INSTALL PYSERIAL. OPEN YOUR CMD AND TYPE "pip install pyserial"
import socket
import cfg
import time
import re
import serial
import math

#Change COM port to wherever your arduino is connected
ser = serial.Serial('COM10',9600)

def serialwrite(string):
    string = str(string)
    ser.write(string.encode())
    while ser.read == (string):
        ser.read()

CHAT_MSG=re.compile(r"^:\w+!\w+@\w+\.tmi\.twitch\.tv PRIVMSG #\w+ :")

s = socket.socket()
s.connect((cfg.HOST, cfg.PORT))
s.send("PASS {}\r\n".format(cfg.PASS).encode("utf-8"))
s.send("NICK {}\r\n".format(cfg.NICK).encode("utf-8"))
s.send("JOIN {}\r\n".format(cfg.CHAN).encode("utf-8"))


while True:
    response = s.recv(1024).decode("utf-8")
    if response == "PING :tmi.twitch.tv\r\n":
        s.send("PONG :tmi.twitch.tv\r\n".encode("utf-8"))
        serialwrite(0)
    else:
        username = re.search(r"\w+", response).group(0)
        message = CHAT_MSG.sub("", response)
        if message[:len('forward')].upper() == 'FORWARD':
            print("Command acknowledged. Moving forward.")
            serialwrite(1)
        elif message[:len('backward')].upper() == 'BACKWARD':
            print("Command acknowledged. Moving backward.")
            serialwrite(2)
        elif message[:len('left')].upper() == 'LEFT':
            print("Command acknowledged. Turning left.")
            serialwrite(3)
        elif message[:len('right')].upper() == 'RIGHT':
            print("Command acknowledged. Turning right.")
            serialwrite(4)
        elif message[:len('dance')].upper() == 'DANCE':
            print("Command acknowledged. Dancing!")
            serialwrite(5)
        elif message[:len('slow')].upper() == 'SLOW':
            print("Command acknowledged. Speed changed to slow.")
            serialwrite(7)
        elif message[:len('medium')].upper() == 'MEDIUM':
            print("Command acknowledged. Speed changed to medium.")
            serialwrite(8)
        elif message[:len('fast')].upper() == 'FAST':
            print("Command acknowledged. Speed changed to fast.")
            serialwrite(9)
        print(username + ": " + message)
    time.sleep(0.1)
