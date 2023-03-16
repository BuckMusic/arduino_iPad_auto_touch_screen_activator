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
//      WIRE
//
//  THE CONTROLLER
//  An arduino unit. Any arduino will work but this sketch will involve an ARDUINO NANO, I have also used ARDUINO UNO, and ARDUINO MEGA and they work well.
//
//  THE TOUCH POINTS
//  The touch point pads I have found to be the most effective, are made from aluminium adhesive tape. This adhesive is very inexpensive, 
//  widely available, and marketed to secure duct seams.
//
//  THE WIRES
//  Any small guage insulated wire will work. One consideration is to match the guage to a size that will attach securely to the input/output
//  pin sockets of the arduino. Another good idea is to use many different colors of wire along the way.
//
//
//  code and more instructions coming soon
