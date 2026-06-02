# STM32 Morse Code Transcriber

An embedded systems project built on the STM32 Nucleo-F401RE using C and the STM32 HAL framework. The project reads Morse code input from the onboard push button, stores the detected dot/dash pattern, translates the pattern into an alphabet character, and displays the result on a common-anode 7-segment display.

## Project Overview

This project uses a push button as the Morse code input device. Short button presses are interpreted as dots, and longer button presses are interpreted as dashes. After the user pauses for a set gap duration, the recorded Morse sequence is compared against Morse code patterns and the matching alphabet character is shown on the 7-segment display.

The project is designed as a hands-on embedded systems exercise covering GPIO input, GPIO output, button timing, debouncing, state machines, and 7-segment display control.

## Hardware Used

- STM32 Nucleo-F401RE
- Onboard B1 push button
- Onboard LD2 LED
- 4-digit common-anode 7-segment display
- Breadboard
- Jumper wires
- Resistors
- USB Mini-B cable for programming/debugging

## Software and Tools

- C
- STM32 HAL framework
- STM32CubeIDE
- ST-LINK debugger/programmer
- UART2 configuration included for debugging/serial output

## Features

- Reads push button input from the onboard B1 button
- Uses debounce logic to filter unstable button presses
- Measures button press duration using `HAL_GetTick()`
- Classifies short presses as dots and long presses as dashes
- Stores Morse symbols in a 4-element array
- Detects a pause/gap to determine when one Morse character is complete
- Translates Morse patterns into alphabet characters A-Z
- Displays translated letters on a common-anode 7-segment display
- Uses LD2 as a visual indicator while the button is being pressed

## Morse Code Input Logic

The project uses the following representation:

```c
1 = dot
2 = dash
0 = empty / unused slot
```

Example:

```text
A = .-  = [1, 2, 0, 0]
B = -... = [2, 1, 1, 1]
S = ... = [1, 1, 1, 0]
T = - = [2, 0, 0, 0]
```

The array is limited to four symbols because Morse code letters A-Z use at most four dot/dash symbols.

```c
uint8_t morseCode[4] = {0, 0, 0, 0};
uint8_t morseCodeIndex = 0;
```

## Button State Machine

The button logic uses a simple state machine:

```c
typedef enum {
    BUTTON_RELEASED = 0,
    BUTTON_PRESSED_DEBOUNCE,
    BUTTON_HELD,
    WAITING_FOR_GAP
} ButtonState;
```

### State behavior

- `BUTTON_RELEASED`: waiting for the button to be pressed
- `BUTTON_PRESSED_DEBOUNCE`: confirms the press lasts long enough to ignore bounce
- `BUTTON_HELD`: measures how long the button is held
- `WAITING_FOR_GAP`: waits for the user to pause, then transcribes the stored Morse pattern

## Timing Rules

Current timing values:

```c
50 ms debounce time
<= 300 ms = dot
> 300 ms = dash
>= 1000 ms gap = end of character
```

These values are easier for manual button testing and can be adjusted later for faster Morse input.

## 7-Segment Display Logic

The display is common-anode, so the segment logic is inverted compared to a normal LED.

```text
GPIO RESET = segment ON
GPIO SET   = segment OFF
```

Helper functions are used to make the code easier to read:

```c
void segment_on(uint16_t segment, char port)
{
    HAL_GPIO_WritePin(..., GPIO_PIN_RESET);
}

void segment_off(uint16_t segment, char port)
{
    HAL_GPIO_WritePin(..., GPIO_PIN_SET);
}
```

## Segment Pin Mapping

Current segment mapping:

| Segment | STM32 Pin | Port |
|---------|-----------|------|
| A | PB4 | GPIOB |
| B | PB3 | GPIOB |
| C | PA8 | GPIOA |
| D | PB6 | GPIOB |
| E | PA7 | GPIOA |
| F | PB5 | GPIOB |
| G | PB10 | GPIOB |
| DP | PA9 | GPIOA |

The first digit is enabled using:

```c
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); // D1
```

## Main Program Flow

1. Initialize HAL
2. Configure the system clock
3. Initialize GPIO and USART2
4. Enable the first digit of the 7-segment display
5. Turn all display segments off
6. Continuously check button state in the infinite loop
7. Store dot/dash input based on press duration
8. Transcribe the Morse sequence after a gap
9. Display the matching letter on the 7-segment display

## Example Input

To display `A`:

```text
short press  -> dot
long press   -> dash
wait 1 second
```

Stored pattern:

```text
[1, 2, 0, 0]
```

Displayed output:

```text
A
```

## Skills Practiced

- STM32 GPIO input and output
- Push button input handling
- Software debouncing
- Timing with `HAL_GetTick()`
- State machine design
- Common-anode 7-segment display control
- Embedded C programming
- STM32CubeIDE project workflow
- ST-LINK flashing and debugging

## Future Improvements

- Add UART debug output for Morse input and detected letters
- Clean up Morse translation using a lookup table instead of long `if/else` chains
- Add support for numbers 0-9
- Add support for multiple digits using display multiplexing
- Add external button input instead of only the onboard B1 button
- Add buzzer feedback for dots and dashes
- Improve timing thresholds for real Morse code speed
- Refactor GPIO segment logic into a reusable display driver