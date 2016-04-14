// Import Fathym library
#include "Fathym-io.h"
#include "FathymBuild.h"

// Create an instance of the Fathym API
Fathym fathym;

void setup() {
  // Uncomment t
  //Serial.begin(57600);
  //delay(2000); // waiting a little bit after Serial.begin() seems to help the serial monitor catch

  //= Initialize Sensors ================================================================/

  // Initialize your sensors here
  // ----------------------------

  //= End Initialize Sensors ============================================================/

  // Setup Fathym and connect to the messaging service
  fathym.setup();
}

void loop() {
  // Start a Fathym update cycle
  fathym.beginUpdate();

  // Set your variables you want to publish below
  // --------------------------------------------

  // Uncomment below if you want to add a fixed lattitude/longitude location
  /*fathym.set("lat", 40.014688);,
  fathym.set("long", -105.258421);*/

  // Set some random test values to publish
  fathym.set("testInt", random(10, 4096));
  fathym.set("testFloat",  (float)random(1, 100) / 1.5);
  fathym.set("testBool", true);
  fathym.set("intWithUnits", random(0, 120), "v");
  fathym.set("floatWithUnits", (float)random(1, 10000) / 3.5, "m/s");

  // End the update cycle and publish the latest values to Fathym
  fathym.endUpdate();
}
