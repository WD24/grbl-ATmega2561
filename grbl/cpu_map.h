/*
  cpu_map.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The cpu_map.h files serve as a central pin mapping selection file for different 
   processor types or alternative pin layouts. This version of Grbl supports only the 
   Arduino Mega2560. */

#ifndef cpu_map_h
#define cpu_map_h


#ifdef CPU_MAP_2560_INITIAL // (Arduino Mega 2560) Working @EliteEng

  // Serial port interrupt vectors
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect

  // Define step pulse output pins. NOTE: All step bit pins must be on the same port.
  #define STEP_DDR      DDRA
  #define STEP_PORT     PORTA
  #define STEP_PIN      PINA
  #define X_STEP_BIT    2 // PA2
  #define Y_STEP_BIT    3 // PA3
  #define Z_STEP_BIT    4 // PA4
  #define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)) // All step bits

  // Define step direction output pins. NOTE: All direction pins must be on the same port.
  #define DIRECTION_DDR     DDRC
  #define DIRECTION_PORT    PORTC
  #define DIRECTION_PIN     PINC
  #define X_DIRECTION_BIT   7 // PC7
  #define Y_DIRECTION_BIT   6 // PC6
  #define Z_DIRECTION_BIT   5 // PC5
  #define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)) // All direction bits

  // Define stepper driver enable/disable output pin.
  #define STEPPERS_DISABLE_DDR   DDRC
  #define STEPPERS_DISABLE_PORT  PORTC
  #define STEPPERS_DISABLE_BIT   4 // PC4
  #define STEPPERS_DISABLE_MASK (1<<STEPPERS_DISABLE_BIT)

  // Define homing/hard limit switch input pins and limit interrupt vectors. 
  // NOTE: All limit bit pins must be on the same port
  #define LIMIT_DDR       DDRE
  #define LIMIT_PORT      PORTE
  #define LIMIT_PIN       PINE
  #define X_LIMIT_BIT     5 // PE5
  #define Y_LIMIT_BIT     6 // PE6
  #define Z_LIMIT_BIT     7 // PE7
  
  // define each INT Vector
  #define X_LIMIT_INT_vect  INT5_vect
  #define Y_LIMIT_INT_vect  INT6_vect
  #define Z_LIMIT_INT_vect  INT7_vect
  
  #define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits
  
  // Set how the INT triggers. On ANY_EDGE to mimic the PCINT used by the mainstream GRBL 
  //OR to a RISING_EDGE or FALLING_EDGE if external pull down or pull up resistors are used.
  
  #define X_LIMIT_TRIGGER	(1<<ISC50)  //ANY_EDGE
  #define Y_LIMIT_TRIGGER	(1<<ISC60)  //ANY_EDGE
  #define Z_LIMIT_TRIGGER	(1<<ISC70)  //ANY_EDGE
  
  /*
  #define X_LIMIT_TRIGGER	(1<<ISC51)  //FALLING_EDGE
  #define Y_LIMIT_TRIGGER	(1<<ISC61)  //FALLING_EDGE
  #define Z_LIMIT_TRIGGER	(1<<ISC71)  //FALLING_EDGE
  */
  
  /*
  #define X_LIMIT_TRIGGER	(1<<ISC51) | (1<<ISC50)  //RISING_EDGE
  #define Y_LIMIT_TRIGGER	(1<<ISC61) | (1<<ISC60)  //RISING_EDGE
  #define Z_LIMIT_TRIGGER	(1<<ISC71) | (1<<ISC70)  //RISING_EDGE
  */

  // Define spindle enable and spindle direction output pins.
  #define SPINDLE_ENABLE_DDR      DDRF
  #define SPINDLE_ENABLE_PORT     PORTF
  #define SPINDLE_ENABLE_BIT      0 // PF0
  #define SPINDLE_DIRECTION_DDR   DDRF
  #define SPINDLE_DIRECTION_PORT  PORTF
  #define SPINDLE_DIRECTION_BIT   1 // PF1

  // Define flood and mist coolant enable output pins.
  #define COOLANT_FLOOD_DDR   DDRF
  #define COOLANT_FLOOD_PORT  PORTF
  #define COOLANT_FLOOD_BIT   2 // PF2
  #define COOLANT_MIST_DDR    DDRF
  #define COOLANT_MIST_PORT   PORTF
  #define COOLANT_MIST_BIT    3 // PF3

  // Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
  // NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
  #define CONTROL_DDR       DDRB
  #define CONTROL_PIN       PINB
  #define CONTROL_PORT      PORTB
  #define CONTROL_RESET_BIT         4  // PB4 PCINT4
  #define CONTROL_FEED_HOLD_BIT     5  // PB5 PCINT5
  #define CONTROL_CYCLE_START_BIT   6  // PB6 PCINT6
  #define CONTROL_SAFETY_DOOR_BIT   7  // PB7 PCINT7
  #define CONTROL_INT       PCIE0  // Pin change interrupt enable pin
  #define CONTROL_INT_vect  PCINT0_vect
  #define CONTROL_PCMSK     PCMSK0 // Pin change interrupt register
  #define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))

  // Define probe switch input pin.
  #define PROBE_DDR       DDRC
  #define PROBE_PIN       PINC
  #define PROBE_PORT      PORTC
  #define PROBE_BIT       0  // PC0
  #define PROBE_MASK      (1<<PROBE_BIT)

  // Advanced Configuration Below You should not need to touch these variables
  // Set Timer up to use TIMER4B which is attached to Digital Pin 7
  #define SPINDLE_PWM_MAX_VALUE     1024.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
  #ifndef SPINDLE_PWM_MIN_VALUE
    #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
  #endif
  #define SPINDLE_PWM_OFF_VALUE     0
  #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)
  #define SPINDLE_TCCRA_REGISTER		TCCR3A
  #define SPINDLE_TCCRB_REGISTER		TCCR3B
  #define SPINDLE_OCR_REGISTER	  	OCR3B
  #define SPINDLE_COMB_BIT			    COM3B1

  // 1/8 Prescaler, 16-bit Fast PWM mode
  #define SPINDLE_TCCRA_INIT_MASK ((1<<WGM30) | (1<<WGM31))
  #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM32) | (1<<WGM33) | (1<<CS31)) 
  #define SPINDLE_OCRA_REGISTER   OCR3A // 16-bit Fast PWM mode requires top reset value stored here.
  #define SPINDLE_OCRA_TOP_VALUE  0x0400 // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

  // Define spindle output pins.
  #define SPINDLE_PWM_DDR		DDRE
  #define SPINDLE_PWM_PORT  PORTE
  #define SPINDLE_PWM_BIT		4 // PE4

#endif


#endif
