//display.c

void openDisplay(void);
void closeDisplay(void);
void displayLetter(char letter, int xOffset, int yOffset);
void clearDisplay(void);

//input.c
void openJoystick(void);
void closeJoystick(void);
void checkJoystick(void (*callback)(unsigned int code), int delay);
