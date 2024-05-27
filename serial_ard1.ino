void setup() {
  Serial.begin(115200);
}

void loop() {
  while(Serial.available())
  {
    //String x = "hi pi!";

    String input = Serial.readStringUntil('\n');

    if (input == "who")
    {
      Serial.println("Ard1");
    } 
    else if (input == "StartFeeding")
    {
      delay(100);

      Serial.println("DoneFeeding");
    }
    else if (input == "Red")
    {
      delay(100);

      Serial.println("DoneSorting");
    }
    else if (input == "Green")
    {
      delay(100);

      Serial.println("DoneSorting");
    }
    else if (input == "Yellow")
    {
      delay(100);

      Serial.println("DoneSorting");
    }
    else if (input == "Blue")
    {
      delay(100);

      Serial.println("DoneSorting");
    }
  }
}
