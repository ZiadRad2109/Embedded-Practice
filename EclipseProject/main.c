/*
 * main.c
 *
 *  Created on: Sep 7, 2023
 *      Author: Lenovo
 */

#include <stdio.h>

void main(void){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//fflush(stdout);
	printf("hello world");

}
