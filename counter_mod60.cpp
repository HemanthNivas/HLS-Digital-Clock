#include "ap_int.h"
void counter_mod60(ap_uint<4> &d0,ap_uint<4> &d1,bool &outs){
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_ctrl_none port=return
//#pragma HLS INTERFACE ap_none port=d3
//#pragma HLS INTERFACE ap_none port=d2
#pragma HLS INTERFACE ap_none port=d1
#pragma HLS INTERFACE ap_none port=d0
//#pragma HLS INTERFACE ap_none port=rsts
	static ap_uint<8> counter=0;
	 ap_uint<8> c=0;
  if(counter==59){
		c=0;
		outs=1;
	}
	else{
		c=counter+1;
  outs=0;
	}

counter=c;

	ap_uint<16> nc=counter;
	ap_uint<16> ccs;
	d0=nc%10;
	ccs=nc/10;
	d1=ccs%10;
}
