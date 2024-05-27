void setup() {
  Serial.begin(115200);
}

void loop() {

  while(Serial.available())
  {
    String input = Serial.readStringUntil('\n');

    if (input == "who")
    {
      Serial.println("Ard2");
    } 
    else if (input[5] == 'A')
    {
      delay(100);

      Serial.println("DoneAss");
    }

  }
}
