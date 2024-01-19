# Stop-Watch-System-with-Multiplexed-7-Segments
This repo implements a 1MHz ATmega32-based Stop Watch using Timer1 in CTC mode. Features six multiplexed common anode 7-segments controlled by 7447 decoders and NPN BJT transistors. External interrupts (INT0, INT1, INT2) handle reset, pause, and resume functions.

### Project Specifications:
1. ATmega32 Microcontroller @ 1MHz.
2. Timer1 configured in CTC mode for Stop Watch time counting.
3. Six Common Anode 7-segments in a multiplexed setup.
4. 7447 decoder for multiplexing control.
5. External interrupts (INT0, INT1, INT2) with push buttons for reset, pause, and resume.
6. PORTC used for 7447 decoder connections.
7. PORTA (pins 0-5) used for enable/disable control of 7-segments.

### Hardware Setup:
- Follow the multiplexed 7-segments configuration using 7447 decoders and NPN BJT transistors as illustrated in the provided image.
- Connect 7447 decoder pins to the first 4 pins in PORTC.
- Use the first 6 pins in PORTA for enable/disable of the six 7-segments.
- Configure external interrupts INT0, INT1, and INT2 as specified.

### How to Use:
1. Clone the repository.
2. Set up the hardware connections as described in the project documentation.
3. Build and upload the code to the ATmega32 microcontroller.
4. Power on the MCU to start the Stop Watch.
5. Press the push button connected to INT0 for a falling edge to reset the Stop Watch.
6. Press the push button connected to INT1 for a rising edge to pause the Stop Watch.
7. Press the push button connected to INT2 for a falling edge to resume the Stop Watch.
