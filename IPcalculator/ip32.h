// Author: Álvaro Bolaños Rodríguez
/* 32 bits IP address ADT */
#include <stdio.h>
#include <math.h>
#define MAX 32

/* one byte integer data type for save memory */
typedef unsigned char byte;

/* ipv4 address structure */
typedef struct{
	byte a[MAX];
}ip32;

/* ip32 functions */
void print_address(ip32 address);
void to_decimal(ip32 address);
int read_address(ip32 *address, const char *prompt);
byte calc_prefix(ip32 address);
ip32 calc_network_address(ip32 address, byte prefix);
void calc_hosts(ip32 net_address, byte prefix);
