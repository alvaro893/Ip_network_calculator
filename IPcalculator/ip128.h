// Author: Álvaro Bolaños Rodríguez
/* 128 bits IP address ADT */
#include <stdio.h>
#include <math.h>
#define MAX 128

/* one byte integer data type for save memory */
typedef unsigned char byte;

/* ipv4 address */
typedef struct{
	byte a[MAX];
}ip128;

/* ip128 functions */
void print_address(ip128 address);
int read_address(ip128 *address, const char *prompt);
byte calc_prefix(ip128 address);
ip128 calc_network_address(ip128 address, byte prefix);
