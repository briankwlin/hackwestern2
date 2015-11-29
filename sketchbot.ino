void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  //Setup optional LED and Buzzer
  pinMode(13, OUTPUT); //Onboard LED
 
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
 
  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int incomingByte = 0;
  int speed = 255;
  bool backwards;
  int del = 750;
  int randomvar;
  //Serial.println(Serial.available(), DEC);
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    Serial.println(incomingByte, DEC);
    if(incomingByte == 49){ //ASCII VALUES
      //Both motors forward!
      digitalWrite(12, HIGH); //Establishes forward direction of Channel A
      digitalWrite(13, HIGH); //Establishes forward direction of Channel A
      analogWrite(3, speed); //Spins the motor on Channel A at set speed
      analogWrite(11, speed); //Spins the motor on Channel B at set speed
     
      delay(del);
      resetValues();
     
    }else if(incomingByte == 50){
      //Both motors backwards!
      digitalWrite(12, LOW); //Establishes backwards direction of Channel A
      digitalWrite(13, LOW); //Establishes backwards0 direction of Channel A
      analogWrite(3, speed); //Spins the motor on Channel A at set speed
      analogWrite(11, speed); //Spins the motor on Channel B at set speed
     
      delay(del);
      resetValues();
     
    }else if(incomingByte == 51){
      //Turn left!
      digitalWrite(9, HIGH); //Engage Brake for Channel A
      analogWrite(3, 0); //Set speed for Channel A to be 0
      digitalWrite(8, LOW); //Disengage Brake for channel B
      analogWrite(11, speed); //Spins the motor on Channel B at set speed
 
      delay(del);
      resetValues();
     
    }else if(incomingByte == 52){
      //Turn right!
      digitalWrite(9, LOW); //Engage Brake for Channel A
      analogWrite(3, speed); //Spins the motor on Channel A at set speed
      digitalWrite(8, HIGH); //Disengage Brake for channel B
      analogWrite(11, 0); //Set speed for Channel B to be 0
 
      delay(del);
      resetValues();
     
    }else if(incomingByte == 53){
      //Dance monkey, dance!
      for(int i = 0; i < 10; i++){
        randomvar = random(1,4);
        if(randomvar == 1){
          //Turn right!
          digitalWrite(9, LOW); //Engage Brake for Channel A
          analogWrite(3, speed); //Spins the motor on Channel A at set speed
          digitalWrite(8, HIGH); //Disengage Brake for channel B
          analogWrite(11, 0); //Set speed for Channel B to be 0
 
          delay(del/4);
          resetValues();
        }else if(randomvar == 2){
          //Turn left!
          digitalWrite(9, HIGH); //Engage Brake for Channel A
          analogWrite(3, 0); //Set speed for Channel A to be 0
          digitalWrite(8, LOW); //Disengage Brake for channel B
          analogWrite(11, speed); //Spins the motor on Channel B at set speed
   
          delay(del/4);
          resetValues();
        }else if(randomvar == 3){
          //Both motors backwards!
          digitalWrite(12, LOW); //Establishes backwards direction of Channel A
          digitalWrite(13, LOW); //Establishes backwards direction of Channel A
          analogWrite(3, speed); //Spins the motor on Channel A at set speed
          analogWrite(11, speed); //Spins the motor on Channel B at set speed
         
          delay(del/4);
          resetValues();
        }else if(randomvar == 4){
          //Both motors forward!
          digitalWrite(12, HIGH); //Establishes forward direction of Channel A
          digitalWrite(13, HIGH); //Establishes forward direction of Channel A
          analogWrite(3, speed); //Spins the motor on Channel A at set speed
          analogWrite(11, speed); //Spins the motor on Channel B at set speed
          delay(del/4);
          resetValues();
        }
      }
    }else if(incomingByte == 53){
        del = 1500;
    }else if(incomingByte == 54){
        del = 750;
    }else if(incomingByte == 55){
        del = 500;
    }
  }
}

void resetValues(){
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW); //Engage Brake for channel B
  digitalWrite(9, LOW); //Engage Brake for channel A
  analogWrite(3, 0);
  analogWrite(11, 0);
}