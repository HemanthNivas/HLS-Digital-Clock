#include "ap_int.h"
typedef enum{s0,s1,s2,s3} segs;
void seven_segment_driver(ap_uint<4> d0,ap_uint<4> d1,ap_uint<4> d2,ap_uint<4> d3,ap_uint<8> &sevens,ap_uint<4> &an,bool refresh_signal){
#pragma HLS INTERFACE ap_none port=refresh_signal
#pragma HLS INTERFACE ap_none port=ans
#pragma HLS INTERFACE ap_none port=sevens
#pragma HLS INTERFACE ap_none port=d3
#pragma HLS INTERFACE ap_none port=d2
#pragma HLS INTERFACE ap_none port=d1
#pragma HLS INTERFACE ap_none port=d0
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS PIPELINE II=1
	static segs state=s0;
ap_uint<4> ans;
	segs ns;
	ap_uint<8> sevs[10]={
			0b11000000,  //0
					0b11111001,  //1
					0b10100100,  //2
					0b10110000,  //3
					0b10011001,  //4
					0b10010010,  //5
					0b10000010,  //6
					0b11111000,  //7
					0b10000000,  //8
					0b10010000   //9
	};
	ap_uint<8> seven_out;
	switch(state){
	case s0:
		if(refresh_signal==1){
			ns=s1;
		}
		else{
			ns=s0;
		}
		ans=0b1110;
		seven_out=sevs[d0];
		break;
	case s1:
		if(refresh_signal==1){
			ns=s2;
		}
		else{
			ns=s1;
		}
		ans=0b1101;
		seven_out=sevs[d1];
		break;
	case s2:
		if(refresh_signal==1){
			ns=s3;
		}
		else{
			ns=s2;
		}
		ans=0b1011;
		seven_out=sevs[d2];
		break;
	case s3:
		if(refresh_signal==1){
			ns=s0;
		}
		else{
			ns=s3;
		}
		ans=0b0111;
		seven_out=sevs[d3];
		break;
	}
	an=ans;
	state=ns;
	sevens=seven_out;
}
