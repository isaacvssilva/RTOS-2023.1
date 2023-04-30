/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
TaskHandle_t led_t1;	/*identificador da tarefa 1*/
TaskHandle_t led_t2;	/*identificador da tarefa 2*/
TaskHandle_t bnt_t3;	/*identificador da tarefa 3*/
TaskHandle_t volatile next_t = NULL;	/*identificador para proxima task que precisa ser excluida*/
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
static void tarefa1(void *parameters);
static void tarefa2(void *parameters);
static void tarefa3(void *parameters);
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
  /* USER CODE BEGIN 2 */

  /*
   * criar duas tasks toggle de dois leds diferentes e uma task para o botao,
   * que verifica o pressionamento do botao a cada 10ms. Se a task do botao
   * detectar pressionamento, envia uma notificao para a task toggle led. A
   * Notificacao ocorre apenas quando o botao pressionado é detectado. Quando
   * a task toggle receber a notifcao, ela deve se auto excluir.
   * */

  xTaskCreate(tarefa1, "task_led1", configMINIMAL_STACK_SIZE, NULL, 1, &led_t1);
  xTaskCreate(tarefa2, "task_led2", configMINIMAL_STACK_SIZE, NULL, 2, &led_t2);
  xTaskCreate(tarefa3, "task_bnt1", configMINIMAL_STACK_SIZE, NULL, 3, &bnt_t3);
  next_t = led_t1; /*iniciando ponteiro para a primeira task toggle*/
  vTaskStartScheduler();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, led2_Pin|led1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led2_Pin led1_Pin */
  GPIO_InitStruct.Pin = led2_Pin|led1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : botao1_Pin */
  GPIO_InitStruct.Pin = botao1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(botao1_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
static void tarefa1(void *parameters){
	BaseType_t status;
	while(1){
		/*configurando para aguardar a notificacao para auto deletar*/
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);

		/*caso nao tenha nenhuma notificacao pendente, a task hibernada por 1seg*/
		status = xTaskNotifyWait(0, 0, NULL, pdMS_TO_TICKS(1000));

		if(status == pdTRUE){ /*verificando se a notificacao foi recebida*/
			/*supendendo escalonador para nao ocorrer preempcao de outra task, sem interrupcao*/
			vTaskSuspendAll();
			/*atualizando ponteiro para a proxima task toggle*/
			next_t = led_t2;
			/*executando novamente o escalonador*/
			xTaskResumeAll();
			/*excluindo a task referente ao toggle led1*/
			vTaskDelete(NULL);
		}
	}
}
static void tarefa2(void *parameters){
	BaseType_t status;
	while(1){
		/*configurando para aguardar a notificacao para auto deletar*/
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11);

		/*caso nao tenha nenhuma notificacao pendente, a task hibernada por 0.5 seg*/
		status = xTaskNotifyWait(0, 0, NULL, pdMS_TO_TICKS(500));

		if(status == pdTRUE){ /*verificando se a notificacao foi recebida*/
			/*supendendo escalonador para nao ocorrer preempcao de outra task, sem interrupcao*/
			vTaskSuspendAll();
			/*atualizando ponteiro para NULL, pois nao há mais tasks */
			next_t = NULL;
			/*executando novamente o escalonador*/
			xTaskResumeAll();
			/*excluindo a task referente ao botao*/
			vTaskDelete(bnt_t3);
			/*excluindo a task referente ao toggle led2*/
			vTaskDelete(NULL);

		}
	}
}
static void tarefa3(void *parameters){
	/*verificando, a cada 10ms, se o botao foi pressionado*/
	uint8_t btn_read = 0;
	uint8_t prev_read = 0;
//	TickType_t xLastWakeTime; /*ponteiro para ultima hora que a tarefa foi desbloquada pela ultima vez*/
//	xLastWakeTime = xTaskGetTickCount(); /*contagem de ticks atual do RTOS*/

	/*verificando, a cada 10ms, se o botao foi pressionado*/
	while(1){
		/*lendo o status do botao*/
		btn_read = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
		if(btn_read){ /*verificando nivel logico*/
			if(!prev_read){ /*se a leitura anterior for nivel logico alto, ainda esta pressionado*/
				/*notificacao iniciamente para a primira task toggle*/
				xTaskNotify(next_t, 0, eNoAction);
			}
		}
		prev_read = btn_read; /*atualizando a leitura do botao*/
//		xTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(10));
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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

#ifdef  USE_FULL_ASSERT
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
