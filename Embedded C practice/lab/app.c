#include "uart.h"

unsigned char string_buffer[100] = "zizo kalabeezo";
void main(){
	
	Uart_send_string(string_buffer);
} 