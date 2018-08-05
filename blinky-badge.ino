/*****
 * Simple Party Mode test for the DC916 badge.
 * 
 * Is a *slightly* modified version of Adafruit's DotStar library strand test example.
 */

#include <Adafruit_DotStar.h>
#include <SPI.h>

#define NUMPIXELS 4

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS);

void setup() {
  strip.begin();
  strip.show();
}

int head = 0, tail = -10;   // Index 0f first 'on' and 'off' pixels
uint32_t color = 0xFF0000;  // 'on' color for rotating flashing
uint32_t yellow = 0x7F8000;
uint32_t red = 0x07F800;
uint32_t purple = 0x007F80;
uint32_t green = 0xF80007; // or maybe is better 0x FF0000
uint32_t blue = 0x003FC0;  
uint32_t litblue = 0x80007F; 
uint32_t litgreen = 0xC0003F;
int speed=0;
int n=0,i=0;
uint32_t c;

void setColor(uint32_t hex){
  color = hex;
}
void onColor(){
  strip.setPixelColor(0, color);      // 'On' pixel
  strip.setPixelColor(1, color);      // 'On' pixel
  strip.setPixelColor(2, color);      // 'On' pixel
  strip.setPixelColor(3, color);      // 'On' pixel
  strip.show();
}
void allOff(){                    //turns all pixels off
  strip.setPixelColor(0, 0);      // 'Off' pixel
  strip.setPixelColor(1, 0);      // 'Off' pixel
  strip.setPixelColor(2, 0);      // 'Off' pixel
  strip.setPixelColor(3, 0);      // 'Off' pixel
  strip.show(); 
}
void onLitGreen(){                       // all pixels red
  strip.setPixelColor(0, litgreen);      // 'On' pixel
  strip.setPixelColor(1, litgreen);      // 'On' pixel
  strip.setPixelColor(2, litgreen);      // 'On' pixel
  strip.setPixelColor(3, litgreen);      // 'On' pixel
  strip.show();                     // Refresh strip
}
void onLitBlue(){                       // all pixels red
  strip.setPixelColor(0, litblue);      // 'On' pixel
  strip.setPixelColor(1, litblue);      // 'On' pixel
  strip.setPixelColor(2, litblue);      // 'On' pixel
  strip.setPixelColor(3, litblue);      // 'On' pixel
  strip.show();                     // Refresh strip
}
void onPurple(){                       // all pixels red
  strip.setPixelColor(0, purple);      // 'On' pixel
  strip.setPixelColor(1, purple);      // 'On' pixel
  strip.setPixelColor(2, purple);      // 'On' pixel
  strip.setPixelColor(3, purple);      // 'On' pixel
  strip.show();                     // Refresh strip
}
void onYellow(){                       // all pixels red
  strip.setPixelColor(0, yellow);      // 'On' pixel
  strip.setPixelColor(1, yellow);      // 'On' pixel
  strip.setPixelColor(2, yellow);      // 'On' pixel
  strip.setPixelColor(3, yellow);      // 'On' pixel
  strip.show();                     // Refresh strip
}
void onRed(){                       // all pixels red
  strip.setPixelColor(0, red);      // 'On' pixel
  strip.setPixelColor(1, red);      // 'On' pixel
  strip.setPixelColor(2, red);      // 'On' pixel
  strip.setPixelColor(3, red);      // 'On' pixel
  strip.show();                     // Refresh strip
}
void onBlue(){                       // all pixels blue
  strip.setPixelColor(0, blue);      // 'On' pixel
  strip.setPixelColor(1, blue);      // 'On' pixel
  strip.setPixelColor(2, blue);      // 'On' pixel
  strip.setPixelColor(3, blue);      // 'On' pixel
  strip.show();                     // Refresh strip
}
void onGreen(){                       // all pixels green
  strip.setPixelColor(0, green);      // 'On' pixel
  strip.setPixelColor(1, green);      // 'On' pixel
  strip.setPixelColor(2, green);      // 'On' pixel
  strip.setPixelColor(3, green);      // 'On' pixel
  strip.show();                     // Refresh strip
}
void colorChange(int speed){            // show each color on all pixels with pause in between
  onLitGreen();
  delay(speed);                        // Pause.  20 milliseconds is ~50 FPS
  allOff();
  onYellow();
  delay(speed);                        // Pause.  20 milliseconds is ~50 FPS
  allOff();
  onRed();
  delay(speed);                        // Pause.  20 milliseconds is ~50 FPS
  allOff();
  onLitBlue();
  delay(speed);                        // Pause.  20 milliseconds is ~50 FPS
  allOff();
  onGreen();
  delay(speed);                        // Pause.  20 milliseconds is ~50 FPS
  allOff();
  onBlue();
  delay(speed);                        // Pause.  20 milliseconds is ~50 FPS
  allOff();
  onPurple();
  delay(speed);
  allOff();
}
void partyMode(int speed){
  strip.setPixelColor(head, color); // 'On' pixel at head
  strip.setPixelColor(tail, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(speed);                      // Pause 20 milliseconds 

  if(++head >= NUMPIXELS) {         // Increment head index.  Off end of strip?
    head = 0;                       //  Yes, reset head index to start
    if((color >>= 8) == 0)          //  Next color (R->G->B) ... past blue now?
      color = 0xFF0000;             //   Yes, reset to red
  }
  if(++tail >= NUMPIXELS) tail = 0; // Increment, reset tail index
}
void heartBeat(){                   // heart beat each color one at a time
  onYellow();
  delay(100);
  allOff();
  delay(100);
  onYellow();
  delay(100);
  allOff();
  delay(1000);
  onRed();
  delay(100);
  allOff();
  delay(100);
  onRed();
  delay(100);
  allOff();
  delay(1000);
  onLitGreen();
  delay(100);
  allOff();
  delay(100);
  onLitGreen();
  delay(100);
  allOff();
  delay(1000);
  onGreen();
  delay(100);
  allOff();
  delay(100);
  onGreen();
  delay(100);
  allOff();
  delay(1000);
  onLitBlue();
  delay(100);
  allOff();
  delay(100);
  onLitBlue();
  delay(100);
  allOff();
  delay(1000);
  onBlue();
  delay(100);
  allOff();
  delay(100);
  onBlue();
  delay(100);
  allOff();
  delay(1000);
  onPurple();
  delay(100);  
  allOff();
  delay(100);
  onPurple();
  delay(100);
  allOff();
  delay(1000);
  allOff();
}

void loop() {
  n=0;
  do{
    colorChange(200); //relatively slow
    delay(1000);

    i=0;
    do{
      partyMode(20);    //fast party mode
      i++;
    } while (i<256); // i times through party mode at speed set 2 lines above
    allOff();
    
    heartBeat();

    i=0;
    do{
      partyMode(40);    //moderate party mode
      i++;
    } while (i<128); // i times through party mode at speed set 2 lines above
    allOff();
    
    heartBeat();
    
    i=0;
    do{
      partyMode(20);    //fast party mode
      i++;
    } while (i<256); // i times through party mode at speed set 2 lines above
    
    n++;
  }while(n<16); // n loops of above chunk
  colorChange(200); //relatively slow
  delay(1000);
  n=0;
  do{
    heartBeat();
    n++;
  }while(n<32); // 32 reps of above
  n=0;
}
