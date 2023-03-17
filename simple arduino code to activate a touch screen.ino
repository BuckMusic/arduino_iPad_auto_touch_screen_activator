// The first inspiration for this project started in 2019 with this youtube:
//        Arduino Plays Piano Tiles tutorial
//        https://www.youtube.com/watch?v=8hlQ0MiowN8
//
// There are many ways to achieve this process.
// There were lots of things to sort out in this project.
// There needs to be a wire or wires connected between a touch screen and a controller (in this case the controller is an arduino unit).
// The connection to the touch screen must fulfill certian parameters:
//      1. There needs to be about a 1cm square (or round) conductive touch point attached to the touch screen.
//      2. The wire connecting the touch point to the controller should be fairly short (as short as possible). 
//      3. The wires should be insulated.
//      4. If two or more touch points are used, the wires MUST be seperated by a cm or more along their path.
//            If the wires are too close together, they will effect one another and 'funny things' may happen.
//
// Regarding the youtube video above, there are other ways than using relays to 'artifically touch' the touch screen.
//      I stopped using relays after about a month of experiments. This project does NOT include relays.
//
//    OK let's get started
//
//  MATERIALS NEEDED
//      CONTROLLER (Arduino)
//      TOUCH POINT tape
//      WIRES
//      GROUNDING WIRE
//      LIGHT SENSOR (LDR light dependand resistor) optional for the more advanced operation.
//
//  THE CONTROLLER
//  An arduino unit. Any arduino will work but this sketch will involve an ARDUINO NANO, I have also used ARDUINO UNO, and ARDUINO MEGA and they work well.
//
//  THE TOUCH POINTS
//  The touch point pads I have found to be the most effective, are made from aluminium adhesive tape. This adhesive is very inexpensive, 
//  widely available, and marketed to secure duct seams. The wire to pin 9 should be connected to this by some means.
//
//  THE WIRES
//  Any small guage insulated wire will work. One consideration is to match the guage to a size that will attach securely to the input/output
//  pin sockets of the arduino. Another good idea is to use many different colors of wire along the way.
//
//  GROUNDING WIRE
//  This can be an 1/8th inch headphone plug cable from a scavenged wired ear bud. Use the wire connected to the ground on the plug. 
//
//
//
/**************************************************************************************************************************************************************
                                                                                                                                                     
                                                                                                                                                     
       +5volt______          ARDUINO NANO                                                                                                           
          |        |       ________________           any one of the digital                                          iPad (not to scale)    TP=touch point           
        __|__      |      |    |      |    |          pins will work                                         _______________________________________  
       /     \     |      |D13 |      | D12|          Let's use pin 9 (D9)                                 |                                        |
      | LDR   |    |      |3V3 |______| D11|          to connect to the                                    |                             ____       |
       \____ /     ^      |REF    /\    D10|          touch point (TP)                                     |                            | TP |      |
          |---------------|A0    /  \    D9|--------------------------------------------------------------------------------------------|____|      |
          |        ^      |A1   /    \   D8|                                                               |                                        |
          |        |      |A2   \    /   D7|                                                               |                        ___             |
          |        |      |A3    \  /    D6|                                                               |                       /   \            |
          |        |      |A4     \/     D5|                                                               |              optional| LDR |           |
      resistor     |      |A5  ________  D4|                                                               |                       \___/            |
      [22Kohm]     |      |A6 [________] D3|                                                               |                                        |
          |        to     |A7  . . . .   D2|                                                               |                                        |
          |      +5v LDR--|5V  * * * *  GND|------------connect this to the ground of the iPad-------------|Headphone socket                        |
          |               |RST          RST|            (see notation, use headphone socket)               |________________________________________|
          ----------------|GND  o o o   RX0|                                                                                                         
    (optional LDR)        |VIN  o o o   TX1|                                                                                                         
                          |________________|                                                                                                         
                                                                                                                                                     
                                                                                                                                                      
 *************************************************************************************************************************************************************/
//
//  The theory behind this process is to use pin 9 to trigger the 'touch'.
//  Pin 9 will alternate between an input and output.
//  When pin 9 is set as an input, it is 'listening' for a voltage and will appear 'passive' to the touch screen.
//  When pin 9 is set as an output, the digitalWrite(9,LOW) indicates that the output will be grounded and the touch screen will act as if the
//      'touch point' has been grounded thru the arduino to the ground of the headphone jack.
//  After the 'touch' process, pin 9 is changed back to an input and the touch point on the screen will not be grounded.
//  There is a built in LED on pin 13, so if using this, avoid using pin 13.
//  The LED is used for troubleshooting and as an indicator when there is a 'touch'
//
//  Experiment with the values untill the system works for you 
//



int Touch_Time = 80;             // set this to the amount of time in miliseconds, and should be catered to your needs
int Delay_Interval = 5000;       // set this to the amount of time in miliseconds 5000 is 5 seconds
int LDR_value;                   // this is used as a brightness threshold for where the LDR is placed on the touch screen 

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);    // built in LED is set to pim 13
  digitalWrite(LED_BUILTIN,LOW);   // LOW indicates 0volts (grounded)
  digitalWrite(9,LOW);             // LOW indicates 0volts (grounded), when this pin is set as an output pin, it will be grounded
  pinMode(9,INPUT);                // When this pin is set as an input pin, it is not grounded
  LDR_value = analogRead(A0)+50;   // This adds 50 to the value read be pin A0 just to raise the threshold a bit (change this to your needs)
}

void loop() {
  Touch_Screen();                         // initiat the touch process
  while (analogRead(A0)>=(LDR_value) {    // this while loop is another way to pause untill the LDR pin (A0) observes a lower value than LDR_value
                                          // let's say that the touch point is placed to refresh the screen and after refreshing the screen, the screen goes   
    }                                     // very bright untill it is refreshed. this will delay untill the screen is dark again (fully refreshed)
  delay(Delay_Interval);                  // wait this amount of time before repeating this loop
  
}

void Touch_Screen(){              // this is the actual 'touch' process
  digitalWrite(LED_BUILTIN,HIGH); // turn ON the built in LED
  pinMode(9,OUTPUT);              // ground out this pin (touch the screen) 
  delay(Touch_Time);              // for this amount of time
  pinMode(9,INPUT);               // set this pin to listen and not be grounded (stop touching the screen)
  digitalWrite(LED_BUILTIN,LOW);  // turn OFF the built in LED
}


  
  
  
  
  
  
