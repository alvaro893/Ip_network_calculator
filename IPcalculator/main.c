// Author: Álvaro Bolaños Rodríguez

#include "ip32.h"

int main(void){
	
	ip32 ad,mask,net;
	byte prefix;

	printf("Testing...\n");
	read_address(&ad,"insert address:"); putchar('\n');
	read_address(&mask, "insert submask:"); putchar('\n');
	
	prefix = calc_prefix(mask);
	net = calc_network_address(ad, prefix);

	printf("Testing...\n");
	print_address(ad);
	printf("/%d\n",prefix);
	print_address(net);

	fflush(stdin);
	getc(stdin);

	return 0;
}