#include "ip32.h"

void print_address(ip32 address){
	int i;

		for(i = 0;i < MAX; i++){ 
			if(i == 8 | i == 16 | i == 24)
				printf(".");
			printf("%d",address.a[i]);
		}
}

void to_decimal(ip32 address){
	int i, j;
	int count[] = {0,0,0,0};

	for(j = 0; j < 4; j++){
		for(i = 7; i >= 0; --i)
			count[j] = count[j] + address.a[7-i + 8*j] * (int) pow(2.0, i);
	}
	
	printf("%d.%d.%d.%d", count[0],count[1],count[2],count[3]);

}

int read_address(ip32 *address, const char *prompt){
	int i;
	int oct[4];
	byte count = 0;

	printf("%s", prompt);
	if(scanf("%d %d %d %d", &oct[0], &oct[1], &oct[2], &oct[3]) != 4)
		return 0;

	for(i = 0; i < 4; i++){
		int k;
			for(k = 7; k >= 0; k--){
				int power = (int) pow(2.0,k);
				if(oct[i] >= power){
					address->a[count++] = 1;
					oct[i] = oct[i] - power;
				}else{
					address->a[count++] = 0;
					}
			}
	}
	return 1;
}

byte calc_prefix(ip32 address){
	byte i, count = 0;

	for(i = 0; i < MAX; i++){
		if(address.a[i] == 1)
		count++;
	}

	return count;
}

ip32 calc_network_address(ip32 address, byte prefix){
	ip32 net;
	byte i;
	for(i = 0; i < MAX; i++){
		if(i < prefix){
			net.a[i] = address.a[i];
		}else{
			net.a[i] = 0;
		}
	}

	return net;
}