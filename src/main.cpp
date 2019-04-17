#include "mbed.h"
#include "USBSerial.h" 
#include "PwmOut.h"

 
Serial pc(USBTX, USBRX);
PwmOut led(PD_12); //green
DigitalOut leds[]={(PD_13),(PD_15)};// orange, blue
Timeout cout ;
char cmd;

void blink_blue();
void blink_orange();
 
float brightness = 0.02;
 
int main() {
    pc.printf("Press '+' to turn LED1 brightness up, '-' to turn it down \n\r");
    led.period(0.02);
    while(1) {
        char c = pc.getc();
        if ((c == '+') && (brightness > 0.0)) {
            led=led+brightness;
            leds[0]=0;
            blink_blue();
        }
        if ((c == '-') && (brightness < 0.999)) {
            led=led+brightness;
            leds[1]=0;
            blink_orange();
            }
        else {
            
            leds[0]= 0;
            leds[1]=0;
             }
         }
    }
     void blink_blue(){  
            leds[1] = !leds[1];
            cout.attach(&blink_blue, 0.1); // blink blue 5Hz 
            }
        void blink_orange(){  
            leds[0] = !leds[0];
            cout.attach(&blink_orange, 0.1); // blink orange 5Hz
            
        }
