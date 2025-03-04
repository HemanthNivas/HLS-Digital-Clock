#include "ap_int.h"
#define N 100000000
//#define N 10
typedef enum{zero,one} clockss;
void clock_divider(bool &signals){
#pragma HLS INTERFACE ap_none port=signals
#pragma HLS INTERFACE ap_ctrl_none port=return

static clockss state=zero;
static long long int count=N/2-1;
clockss ns;
bool signal;
long long int temp_count;
switch(state){
case zero:
	if(count==0){
		temp_count=N/2-1;
		ns=one;
	}
	else{
		temp_count=count-1;
		ns=zero;
	}
	signal=0;
	break;
case one:
	if(count==0){
		temp_count=N/2-1;
		ns=zero;
	}
	else{
		ns=one;
		temp_count=count-1;
	}
	signal=1;
	break;
}
count=temp_count;
state=ns;
signals=signal;
}
