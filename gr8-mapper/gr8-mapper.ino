const int pwmInputPin = 8;
const int pwmDcMotorPin = 11;

// Define the input voltage range
const float inputMin = 0.24; // Minimum expected voltage
const float inputMax = 0.49; // Maximum expected voltage

// Define the mapped output voltage range
const float outputMin = 0.0;
const float outputMax = 5.0;

const int controlPinsPulse[] = {2, 3, 4, 5, 6}; // Adjust based on actual pin numbers

const float dutyMin = 4.98;
const float dutyMax = 10.06;

void setup() {
    Serial.begin(9600); // Start Serial Communication
    Serial.println("Setting up...");
    for (int i = 0; i < 5; i++) {
        pinMode(controlPinsPulse[i], OUTPUT);
        digitalWrite(controlPinsPulse[i], LOW); // Start with all off
    }
    pinMode(pwmInputPin, INPUT);
    pinMode(pwmDcMotorPin, OUTPUT);
    Serial.println("Setup complete!");
}

float percentageReadingPulse() {

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
    
    float percentage = (dutyCycle - dutyMin) * (100.0 / (dutyMax - dutyMin));

    Serial.print(" ✅ Pulse percentage: ");
    Serial.print(percentage);
    return percentage;
}

float logAnalogPercentage() {
    int rawValue = analogRead(pwmInputPin);
    float voltage = rawValue * (5.0 / 1023.0);
    Serial.print("%, Voltage: ");
    Serial.print(voltage);
    Serial.println("V");
}

void loop() {
    Serial.println("Looping...");

    float percentagePulse = percentageReadingPulse();
    float pinsOnPulse = (percentagePulse * 5) / 100;
    logAnalogPercentage();

    for (int i = 0; i < 5; i++) {
        if (i < pinsOnPulse) {
            digitalWrite(controlPinsPulse[i], HIGH); // Turn on pin
        } else {
            digitalWrite(controlPinsPulse[i], LOW); // Turn off pin
        }
    }

    float motorSpeed = percentagePulse * 255.0 / 100.0;
    Serial.print("Motor speed: ");
    Serial.print(motorSpeed);
    if (motorSpeed < 150) {
      Serial.print(" but clapped to 0!");
      motorSpeed = 0;
    }
    Serial.println();
    analogWrite(pwmDcMotorPin, motorSpeed);

    delay(1000);
}
