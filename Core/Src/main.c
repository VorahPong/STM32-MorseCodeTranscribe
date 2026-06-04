/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
#define SEGMENT_A		GPIO_PIN_4
#define SEGMENT_A_PORT	'B'

#define SEGMENT_B		GPIO_PIN_3
#define SEGMENT_B_PORT	'B'

#define SEGMENT_C		GPIO_PIN_8
#define SEGMENT_C_PORT	'A'

#define SEGMENT_D		GPIO_PIN_6
#define SEGMENT_D_PORT	'B'

#define SEGMENT_E		GPIO_PIN_7
#define SEGMENT_E_PORT	'A'

#define SEGMENT_F		GPIO_PIN_5
#define SEGMENT_F_PORT	'B'

#define SEGMENT_G		GPIO_PIN_10
#define SEGMENT_G_PORT	'B'

#define SEGMENT_DP		GPIO_PIN_9
#define SEGMENT_DP_PORT	'A'

/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

typedef enum {
	BUTTON_RELEASED = 0,
	BUTTON_PRESSED_DEBOUNCE,
	BUTTON_HELD,
	WAITING_FOR_GAP
} ButtonState;

ButtonState btnState = BUTTON_RELEASED;
uint32_t pressStartTime = 0;
uint32_t holdDuration = 0;
uint32_t releaseStartTime = 0;
uint32_t gapDuration = 0;

uint8_t morseCode[4] = {0, 0, 0, 0};
uint8_t morseCodeIndex = 0;


/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void segment_on(uint16_t segment, char port);
void segment_off(uint16_t segment, char port);

void display_off(void);
void display_A(void);
void display_B(void);
void display_C(void);
void display_D(void);
void display_E(void);
void display_F(void);
void display_G(void);
void display_H(void);
void display_I(void);
void display_J(void);
void display_K(void);
void display_L(void);
void display_M(void);
void display_N(void);
void display_O(void);
void display_P(void);
void display_Q(void);
void display_R(void);
void display_S(void);
void display_T(void);
void display_U(void);
void display_Q(void);
void display_V(void);
void display_W(void);
void display_X(void);
void display_Y(void);
void display_Z(void);

void reset_morse(void);
void check_button_hold(void);

void morse_code_transcribe(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);		// PA0 (D1)
  display_off();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  check_button_hold();

	  /*
	  // PA0 & PA1
//	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);		// PA1 (D2)

	  // PA4 & PB0
//	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);		// PA4 (D3)
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);		// PB0 (D4)

	  // PA7 & PB6
//	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);		// PA7 (E)
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);		// PB6 (D)

	  // PA9 & PA8
//	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);		// PA9 (DP)
//	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);		// PA8 (C)

	  // PB10 & PB4
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);	// PB10 (G)
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);		// PB4 (A)

	  // PB5 && PB3
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);		// PB5 (F)
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);		// PB3 (B)
		*/

  }
  /* USER CODE END 3 */
}

void segment_on(uint16_t segment, char port) {
	if (port == 'B') {
		HAL_GPIO_WritePin(GPIOB, segment, GPIO_PIN_RESET);
	}
	else {
		HAL_GPIO_WritePin(GPIOA, segment, GPIO_PIN_RESET);
	}
	return;
}

void segment_off(uint16_t segment, char port) {
	if (port == 'B') {
		HAL_GPIO_WritePin(GPIOB, segment, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(GPIOA, segment, GPIO_PIN_SET);
	}
	return;
}

void morse_code_transcribe(void) {
	if (morseCode[0] == 1 && morseCode[1] == 2 && morseCode[2] == 0 && morseCode[3] == 0) {
		display_A();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 1 && morseCode[2] == 1 && morseCode[3] == 1) {
		display_B();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 1 && morseCode[2] == 2 && morseCode[3] == 1) {
		display_C();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 1 && morseCode[2] == 1 && morseCode[3] == 0) {
		display_D();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 0 && morseCode[2] == 0 && morseCode[3] == 0) {
		display_E();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 1 && morseCode[2] == 2 && morseCode[3] == 1) {
		display_F();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 2 && morseCode[2] == 1 && morseCode[3] == 0) {
		display_G();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 1 && morseCode[2] == 1 && morseCode[3] == 1) {
		display_H();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 1 && morseCode[2] == 1 && morseCode[3] == 1) {
		display_I();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 2 && morseCode[2] == 2 && morseCode[3] == 2) {
		display_J();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 1 && morseCode[2] == 1 && morseCode[3] == 0) {
		display_K();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 2 && morseCode[2] == 1 && morseCode[3] == 1) {
		display_L();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 2 && morseCode[2] == 0 && morseCode[3] == 0) {
		display_M();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 1 && morseCode[2] == 0 && morseCode[3] == 0) {
		display_N();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 2 && morseCode[2] == 2 && morseCode[3] == 0) {
		display_O();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 2 && morseCode[2] == 2 && morseCode[3] == 1) {
		display_P();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 2 && morseCode[2] == 1 && morseCode[3] == 2) {
		display_Q();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 2 && morseCode[2] == 1 && morseCode[3] == 0) {
		display_R();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 1 && morseCode[2] == 1 && morseCode[3] == 0) {
		display_S();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 0 && morseCode[2] == 0 && morseCode[3] == 0) {
		display_T();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 1 && morseCode[2] == 2 && morseCode[3] == 0) {
		display_U();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 1 && morseCode[2] == 1 && morseCode[3] == 2) {
		display_V();
	}
	else if (morseCode[0] == 1 && morseCode[1] == 2 && morseCode[2] == 2 && morseCode[3] == 0) {
		display_W();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 1 && morseCode[2] == 1 && morseCode[3] == 2) {
		display_X();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 1 && morseCode[2] == 2 && morseCode[3] == 2) {
		display_Y();
	}
	else if (morseCode[0] == 2 && morseCode[1] == 2 && morseCode[2] == 1 && morseCode[3] == 1) {
		display_Z();
	}
	else {
		display_off();
	}

	return;
}

void reset_morse(void) {
    morseCode[0] = 0;
    morseCode[1] = 0;
    morseCode[2] = 0;
    morseCode[3] = 0;
    morseCodeIndex = 0;
    gapDuration = 0;
    releaseStartTime = 0;
    holdDuration = 0;
}

void store_morse_symbol(uint8_t symbol) {
	if (morseCodeIndex < 4) {
		morseCode[morseCodeIndex] = symbol;
		morseCodeIndex += 1;
	}
	else {
		reset_morse();
	}
}

void check_button_hold(void) {
	if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET) { // check if B1 button being press
		HAL_GPIO_WritePin(GPIOA, LD2_Pin, GPIO_PIN_SET); // turn LED on
		if (btnState == BUTTON_RELEASED || btnState == WAITING_FOR_GAP) {
		    pressStartTime = HAL_GetTick();
		    holdDuration = 0;
		    gapDuration = 0;
		    releaseStartTime = 0;
		    btnState = BUTTON_PRESSED_DEBOUNCE;
		}
		else if (btnState == BUTTON_PRESSED_DEBOUNCE) {
			// Check if press has lasted longer than 50ms (Debounce period)
			if ((HAL_GetTick() - pressStartTime) >= 50) {
				btnState = BUTTON_HELD;
			}
		}
		else if (btnState == BUTTON_HELD) {
			// Calculate how long button has been held down so far
			holdDuration = HAL_GetTick() - pressStartTime;
		}
	}
	else { // B1 button is not press
		HAL_GPIO_WritePin(GPIOA, LD2_Pin, GPIO_PIN_RESET); // turn LED off

		if (btnState == BUTTON_HELD) {
			// Button was held, now we know the exact duration
			if (holdDuration > 300) { // 20 WPM (Conversational)
				// Do "Long Press" Action "Dash" (e.g., >= 180 ms)
				store_morse_symbol(2);
			}
			else if (holdDuration <= 300) { // Dot
				// Do "Short Press" Action
				store_morse_symbol(1);
			}
//			if (morseCodeIndex > 3) { // too long for a character
//				morseCodeIndex = 0;
//				// Reset state
//				morseCode[0] = 0;
//				morseCode[1] = 0;
//				morseCode[2] = 0;
//				morseCode[3] = 0;
//				morseCodeIndex = 0;
//				gapDuration = 0;
//				releaseStartTime = 0;
//				btnState = BUTTON_RELEASED;
//				holdDuration = 0;
//			}
			releaseStartTime = HAL_GetTick();
			btnState = WAITING_FOR_GAP;

		}
		else if (btnState == WAITING_FOR_GAP) {
			// if not press for 420 ms
			gapDuration = HAL_GetTick() - releaseStartTime;

			if (gapDuration >= 1000) {
				// transcribe the recorded signal into a letter
				morse_code_transcribe();

				// Reset state
				morseCode[0] = 0;
				morseCode[1] = 0;
				morseCode[2] = 0;
				morseCode[3] = 0;
				morseCodeIndex = 0;
				gapDuration = 0;
				releaseStartTime = 0;
				btnState = BUTTON_RELEASED;
				holdDuration = 0;
			}
		}
	}
}

void display_off(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_off(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_A(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_B(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_C(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_D(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_off(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_E(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_F(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_G(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_H(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_I(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_off(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_J(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_off(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_K(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_L(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_M(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_off(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_N(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_O(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_P(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_Q(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_R(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_S(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_T(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_U(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_V(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_W(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_X(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_off(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_off(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_off(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}

void display_Y(void) {
	segment_off(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_on(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_off(SEGMENT_E, SEGMENT_E_PORT);
	segment_on(SEGMENT_F, SEGMENT_F_PORT);
	segment_on(SEGMENT_G, SEGMENT_G_PORT);
}

void display_Z(void) {
	segment_on(SEGMENT_A, SEGMENT_A_PORT);
	segment_on(SEGMENT_B, SEGMENT_B_PORT);
	segment_off(SEGMENT_C, SEGMENT_C_PORT);
	segment_on(SEGMENT_D, SEGMENT_D_PORT);
	segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
	segment_on(SEGMENT_E, SEGMENT_E_PORT);
	segment_off(SEGMENT_F, SEGMENT_F_PORT);
	segment_off(SEGMENT_G, SEGMENT_G_PORT);
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  	/*Configure GPIO pin : PA0 */
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);



	// PA1
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	// PA4
	GPIO_InitStruct.Pin = GPIO_PIN_4;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	// PB0
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	// PA7
	GPIO_InitStruct.Pin = GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	// PB6
	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	// PA9
	GPIO_InitStruct.Pin = GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	// PA8
	GPIO_InitStruct.Pin = GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	// PB10
	GPIO_InitStruct.Pin = GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	// PB4
	GPIO_InitStruct.Pin = GPIO_PIN_4;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	// PB5
	GPIO_InitStruct.Pin = GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	// PB3
	GPIO_InitStruct.Pin = GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
