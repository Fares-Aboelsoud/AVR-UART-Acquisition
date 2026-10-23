#define INPUT_H_
#define BUTTON_PIN PD2   /* Push button connected to Pin 2*/
#define LED_PIN    PD4   /* LED connected to Pin 4*/

void Input_Init(void);
unsigned char Button_State(void);
void LED_On(void);
void LED_Off(void);