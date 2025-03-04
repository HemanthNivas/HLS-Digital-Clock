#include "ap_int.h"
void clock_hours1(bool ins,ap_int<8> &outs){
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE ap_none port=outs
#pragma HLS INTERFACE ap_none port=ins
	static ap_int<8> count=0;
	ap_int<8> counter;
	if(ins==1){
	if(count==23){
		counter=0;
	}
	else{
		counter=count+1;
	}}
	else{
		counter=count;
	}
	count=counter;
	outs=count;
}
