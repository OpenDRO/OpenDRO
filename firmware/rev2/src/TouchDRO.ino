/* Touch DRO
 *
 * rev 2
 *
 */

#include <Encoder.h>
#include <Metro.h>
#include <FreqMeasureMulti.h>
#include <Button.h>
#include <EEPROM.h>

#define DEVICE_NAME "TouchDRO Lathe"

#define ZEROSET_PIN 5

#define TACH_PIN 6

#define X_A_PIN 11
#define X_B_PIN 12
#define Y_A_PIN 14
#define Y_B_PIN 15
#define Z_A_PIN 22
#define Z_B_PIN 23

#define BT_KEY 2

#define PULLUP true
#define INVERT true

// Set up three variables for receiving encoder information
Encoder encoderX(X_A_PIN, X_B_PIN);
Encoder encoderY(Y_A_PIN, Y_B_PIN);
Encoder encoderZ(Z_A_PIN, Z_B_PIN);

FreqMeasureMulti tach;

// Periodic 'interrupt' in order to keep TouchDRO connection active
Metro keepAlive = Metro(100);

// Zero button
Button zeroset = Button(ZEROSET_PIN, PULLUP, INVERT, 10);

void setup() {
  // initialize the console output
  Serial.begin(9600);

  // initialize the bluetooth output
  Serial1.begin(9600);

  // set the bluetooth module name
  // delay(250);
  // pinMode(BT_KEY,OUTPUT);
  // delay(250);
  // digitalWrite(BT_KEY, HIGH);
  // delay(250);
  // String device_name = String("AT+NAME=") + String(DEVICE_NAME) + String("\r\n");
  // Serial1.print(device_name);
  // delay(250);
  // digitalWrite(BT_KEY, LOW);

  // initialize the frequency library (tach)
  tach.begin(TACH_PIN);
}

// variables for current x, y & z positions
long positionX = -999;
long positionY = -999;
long positionZ = -999;

// variables for tach
double rpm = 0;
int samples = 0;
float frequency = 0;

void loop() {

   zeroset.read();
   
   if (tach.available()) {
    // average every 30 frequency samples
    rpm = rpm + tach.read();
    samples = samples + 1;
    if (samples > 30) {
      frequency = tach.countToFrequency(rpm / samples) * 60;
      rpm = 0;
      samples = 0;
    }
  }

// zero-set the encoder values
if (zeroset.wasPressed()) {
        encoderX.write(0);
        encoderY.write(0);
        encoderZ.write(0);
}

  // read the current position of the encoders
  long _positionX = encoderX.read();
  long _positionY = encoderY.read();
  long _positionZ = encoderZ.read();

  // if any of the positions have changed or periodic interupt triggered
  if( (_positionX != positionX) ||
      (_positionY != positionY) ||
      (_positionZ != positionZ) ||
        keepAlive.check() == 1) {

        // set new values to current values
        positionX = _positionX;
        positionY = _positionY;
        positionZ = _positionZ;

        // send current position to TouchDRO app via bluetooth serial interface
        Serial1.print(F("x")); Serial1.print((long)positionX); Serial1.print(F(";"));
        Serial1.print(F("y")); Serial1.print((long)positionY); Serial1.print(F(";"));
        Serial1.print(F("z")); Serial1.print((long)positionZ); Serial1.print(F(";"));

        // send current tach reading to TouchDRO app via bluetooth serial interface
        Serial1.print(F("t")); Serial1.print((long)frequency); Serial1.print(F(";"));


        // uncomment to debug via console
        // Serial.print(F("x")); Serial.print((long)positionX); Serial.print(F(";"));
        // Serial.print(F("y")); Serial.print((long)positionY); Serial.print(F(";"));
        // Serial.print(F("z")); Serial.print((long)positionZ); Serial.print(F(";"));
        // Serial.print(F("t")); Serial.print((long)frequency); Serial.print(F(";"));

        // reset the periodic interupt
        keepAlive.reset();

      }

}
