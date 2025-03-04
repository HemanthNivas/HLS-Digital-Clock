#include "ap_int.h"
typedef enum{one,zero} s;
void pulse_generator(bool ins,bool &pulse_out){
#pragma HLS INTERFACE ap_none port=pulse_out
#pragma HLS INTERFACE ap_none port=ins
#pragma HLS INTERFACE ap_ctrl_none port=return
	static s state=zero;
	s ns;
	bool outs;
	switch(state){
	case zero:
		if(ins==1){
			ns=one;
			outs=1;
		}
		else{
			ns=zero;
			outs=0;
		}
		break;
	case one:
		if(ins==1){
			ns=one;
			outs=0;
		}
		else{
			ns=zero;
			outs=0;
		}
		break;
	}
	state=ns;
//
//	static bool ins2=0;
//	if(ins>ins2){
//		outs=1;
//	}
//	else{
//		outs=0;
//	}
	pulse_out=outs;
}
