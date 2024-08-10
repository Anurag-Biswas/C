#define BUILTIN_LED_PIN 13    // A Built-in LED connected to digital Pin 13
 
/* 
 * Setup() runs only once for initialization 
 */
void setup() {
   pinMode(BUILTIN_LED_PIN, OUTPUT);    // Set Pin 13 (digital) to OUTPUT mode
}

/* 
 * loop() repeats forever after setup() completed
 */
void loop() {
   digitalWrite(BUILTIN_LED_PIN, HIGH);  // Set Pin 13 to HIGH (5V) to turn ON its built-in LED
   delay(1000);                  // Delay in msec
 
   digitalWrite(BUILTIN_LED_PIN, LOW);   // Set Pin 13 to LOW (0V) to turn OFF its built-in LED
   delay(1000);                  // Delay in msec
}
