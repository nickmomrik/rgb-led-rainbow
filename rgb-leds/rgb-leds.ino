// These need to be PWM pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  pinMode( redPin, OUTPUT );
  pinMode( greenPin, OUTPUT );
  pinMode( bluePin, OUTPUT );

  setColor( 0, 0, 0 );
}

void loop() {
  rainbow( 60 );
}

void setColor( int red, int green, int blue ) {
  // My RGB LED strip has a common anode, so reverse the values.
  analogWrite( redPin, 255 - red );
  analogWrite( greenPin, 255 - green );
  analogWrite( bluePin, 255 - blue );
}

/*
 * Adapted from the Adafruit NeoPixel strandtest example
 * https://github.com/adafruit/Adafruit_NeoPixel/tree/master/examples/strandtest
 */

void rainbow( uint8_t wait ) {
  uint16_t i, j;

  for ( j = 0; j < 256; j++ ) {
    Wheel( j & 255 );

    delay( wait );
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel( byte WheelPos ) {
  WheelPos = 255 - WheelPos;

  if ( WheelPos < 85 ) {
    setColor( 255 - WheelPos * 3, 0, WheelPos * 3 );
  } else if( WheelPos < 170 ) {
    WheelPos -= 85;
    setColor( 0, WheelPos * 3, 255 - WheelPos * 3 );
  } else {
    WheelPos -= 170;
    setColor( WheelPos * 3, 255 - WheelPos * 3, 0 );
  }
}
