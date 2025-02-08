const int pwmInputPin = 8;

// Define the input voltage range
const float inputMin = 0.24; // Minimum expected voltage
const float inputMax = 0.49; // Maximum expected voltage

// Define the mapped output voltage range
const float outputMin = 0.0;
const float outputMax = 5.0;

const int controlPinsPulse[] = {2, 3, 4, 5, 6}; // Adjust based on actual pin numbers
const int controlPinsAnalog[] = {9, 10, 11, 12, 13}; // Adjust based on actual pin numbers

void setup() {
    Serial.begin(9600); // Start Serial Communication
    Serial.println("Setting up...");
    for (int i = 0; i < 5; i++) {
        pinMode(controlPinsPulse[i], OUTPUT);
        digitalWrite(controlPinsPulse[i], LOW); // Start with all off
    }
    for (int i = 0; i < 5; i++) {
        pinMode(controlPinsAnalog[i], OUTPUT);
        digitalWrite(controlPinsAnalog[i], LOW); // Start with all off
    }
    pinMode(pwmInputPin, INPUT);
    Serial.println("Setup complete!");
}

float pinsOnReadingPulse() {

    // Measure HIGH duration
    unsigned long highTime = pulseIn(pwmInputPin, HIGH, 50000UL);
    // Measure LOW duration
    unsigned long lowTime = pulseIn(pwmInputPin, LOW, 50000UL);
    
    // pulseIn() returns zero on timeout
    if (highTime == 0 || lowTime == 0)
      return digitalRead(pwmInputPin) ? 100 : 0;  // HIGH == 100%,  LOW = 0%

    // Calculate period and duty cycle
    unsigned long period = highTime + lowTime;
    float dutyCycle = (highTime * 100.0) / period;

    Serial.print("✅ Duty Cycle: ");
    Serial.print(dutyCycle);

    return (dutyCycle * 5) / 100; // Determine how many pins to turn on
}

float pinsOnReadingAnalog() {
    int rawValue = analogRead(pwmInputPin);
    float voltage = rawValue * (5.0 / 1023.0);
    Serial.print("%, Voltage: ");
    Serial.print(voltage);
    Serial.println("V");
    float percentage = (voltage - inputMin) / (inputMax - inputMin) * 100.0;
    return (percentage * 5) / 100; 
}

void loop() {
    Serial.println("Looping...");

    float pinsOnPulse = pinsOnReadingPulse();
    float pinsOnAnalog = pinsOnReadingAnalog();

    for (int i = 0; i < 5; i++) {
        if (i >= pinsOnPulse) {
            digitalWrite(controlPinsPulse[i], HIGH); // Turn on pin
        } else {
            digitalWrite(controlPinsPulse[i], LOW); // Turn off pin
        }
    }
    
    for (int i = 0; i < 5; i++) {
        if (i >= pinsOnAnalog) {
            digitalWrite(controlPinsAnalog[i], HIGH); // Turn on pin
        } else {
            digitalWrite(controlPinsAnalog[i], LOW); // Turn off pin
        }
    }


    delay(00);
}
