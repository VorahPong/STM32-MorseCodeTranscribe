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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void segment_on(uint16_t segment, char port);
void segment_off(uint16_t segment, char port);

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

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET) {			// check if button is press
		  HAL_GPIO_WritePin(GPIOA, LD2_Pin, GPIO_PIN_SET);			// PA5 LED
	  }
	  else {
		  HAL_GPIO_WritePin(GPIOA, LD2_Pin, GPIO_PIN_RESET);
	  }

	  // PA0 & PA1
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);		// PA0 (D1)
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

//	  segment_off(SEGMENT_A, SEGMENT_A_PORT);
//	  segment_off(SEGMENT_B, SEGMENT_B_PORT);
//	  segment_off(SEGMENT_C, SEGMENT_C_PORT);
//	  segment_off(SEGMENT_D, SEGMENT_D_PORT);
//	  segment_off(SEGMENT_DP, SEGMENT_DP_PORT);
//	  segment_off(SEGMENT_E, SEGMENT_E_PORT);
//	  segment_off(SEGMENT_F, SEGMENT_F_PORT);
//	  segment_off(SEGMENT_G, SEGMENT_G_PORT);

//	  display_A();
//	  HAL_Delay(500);
//	  display_B();
//	  HAL_Delay(500);
//	  display_C();
//	  HAL_Delay(500);
//	  display_D();
//	  HAL_Delay(500);
//	  display_E();
//	  HAL_Delay(500);
//	  display_F();
//	  HAL_Delay(500);
//	  display_G();
//	  HAL_Delay(500);
//	  display_H();
//	  HAL_Delay(500);
//	  display_I();
//	  HAL_Delay(500);
//	  display_J();
//	  HAL_Delay(500);
//	  display_K();
//	  HAL_Delay(500);
//	  display_L();
//	  HAL_Delay(500);
//	  display_M();
//	  HAL_Delay(500);
//	  display_N();
//	  HAL_Delay(500);
//	  display_O();
//	  HAL_Delay(500);
//	  display_P();
//	  HAL_Delay(500);
//	  display_Q();
//	  HAL_Delay(500);
//	  display_R();
//	  HAL_Delay(500);
//	  display_S();
//	  HAL_Delay(500);
//	  display_T();
//	  HAL_Delay(500);
//	  display_U();
//	  HAL_Delay(500);
//	  display_V();
//	  HAL_Delay(500);
//	  display_W();
//	  HAL_Delay(500);
//	  display_X();
//	  HAL_Delay(500);
//	  display_Y();
//	  HAL_Delay(500);
//	  display_Z();
//	  HAL_Delay(500);

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
