#include <Keypad.h>

#define RELAY 10
String secret = "221196";
String password = "";

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {5, 4, 0, 2}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {14, 12, 13}; // Connect to the column pinouts of the keypad

// Create an object of the Keypad class
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
  Serial.begin(9600);
  Serial.println("");
  delay(2000);
  Serial.println("Enter Password to unlock:\nPress * to clear, # to confirm.");
}

void loop() {
  char key = keypad.getKey(); // Read the key
  // Print if key is pressed
  if (key) {
    if (key == '#') {
      if (secret == password) {
        Serial.println(password);
        Serial.println("Door Unlocked");
        digitalWrite(RELAY, LOW);
      } else {
        Serial.println(password);
        Serial.println("Wrong password, please try again.");
        digitalWrite(RELAY, HIGH);
      }
      password = ""; // Clear the password after checking
    } else if (key == '*') {
      Serial.println(password);
      password = ""; // Clear the password if * is pressed
      Serial.println("Password Cleared");
    } else {
      password += key; // Append the key to the password string
      //Serial.println(password);
    }
  }
}
