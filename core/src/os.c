#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "reg.h"
#include "systick.h"
#include "threads.h"
#include "stream.h"

#define puts(x) do {                       \
                   stream_write(USART,x);  \
                }while(0)

static void delay(volatile int count)
{
	count *= 25000;
	while (count--) {
	}
}

static void busy_loop(void *str)
{
	void *i = NULL;
	i = str;
	while (1) {
		puts(i);
		puts(": Running...\r\n");
		delay(RECOMMAND_TIME_INTERVAL);
	}
}

void test1(void *userdata)
{
	busy_loop(userdata);
}

void test2(void *userdata)
{
	busy_loop(userdata);
}

void test3(void *userdata)
{
	puts("Task 3 starting... userdata:");
	puts(userdata);
	puts("\r\n");
	//char strr[30];
	int result[2];
	result[1] = 0x0;
	result[0] = 0x0;
	puts("Computating...\r\n");
	
	for(unsigned i = 0; i<100000; ++i){
		char str[5];
		itoa(result[0], str, 10);
		puts((void *)str);
		puts("\r\n");
		result[0] = result[0]+1;
	}

	puts("done processing...");
	puts((void *)result);
	//sprintf(strr,"%ul",result);
	//puts(strr);
	puts("\r\n");
}

int main(void)
{
	const char *str1 = "Task1", *str2 = "Task2", *str3 = "Task3";

	stream_init(USART);

	if (thread_create(test1, (void *) str1) == -1) {
		puts("Thread 1 creation failed\r\n");
	}

	if (thread_create(test2, (void *) str2) == -1) {
		puts("Thread 2 creation failed\r\n");
	}

	if (thread_create(test3, (void *) str3) == -1) {
		puts("Thread 3 creation failed\r\n");
	}

	SysTick_init();

	thread_start();

	return 0;
}
