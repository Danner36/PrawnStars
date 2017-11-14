#include "lcd.h"

/// Simple 'Hello, world' program
/**
 * This program prints "Hello, world" to the LCD screen
 * @author Chad Nelson
 * @date 06/26/2012
 */
int main (void) {
	// Initialize the the LCD.  This also clears the screen.
	lcd_init(); 

	// Clear the LCD screen and print "Hello, world" on the LCD
	//lcd_printf("Hello, world");

	// lcd_puts("Hello, world");// Replace lprintf with lcd_puts
                                 // step through in debug mode
                                 // and explain to TA how it
                                 // works

	// Notes: Open util.h to see what functions are available for you to use.
	// You will need to use these functions in future labs.
    
	// It is recommended that you use only lcd_init(), lcd_printf(), lcd_putc, and lcd_puts from lcd.h.

	const char* message = "                    Hello World!                    ";
	const char* blank = "                    ";

	int startingIndex = 0;
	int i;
	int lineCounter = 1;

	//OUR CODE START HERE
	while(1) {

	    for (i = startingIndex; i < 20 + startingIndex; i++) {
	        lcd_putc(message[i]);
	    }

	    startingIndex++;

	    timer_waitMillis(300);

	    if (startingIndex == 12 + 20) startingIndex = 0;

	    lcd_clear();
	}
    
	return 0;
}