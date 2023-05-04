#include "mbed.h"


Serial pc(USBTX, USBRX); // tx, rx

PwmOut led(LED1);
float brightness = 0.0;

int main() {
    pc.printf("Press 'u' to turn LED1 brightness up, 'd' to turn it down\n");
    while (1) {
        char c = pc.getc();
        if ((c == 'u') && (brightness < 0.5)) {
            brightness += 0.01;
            led = brightness;
            // the brightness is increased, the Mbed sends the character ‘^’ to the PC
            // add the e'putc' below
            pc.putc('^');
        }
        if ((c == 'd') && (brightness > 0.0)) {
            brightness -= 0.01;
            led = brightness;
            // the brightness is decreased, the Mbed sends the character ‘v’ to the PC
            // add the e'putc' below
            pc.putc('v');
        }
    }
}


