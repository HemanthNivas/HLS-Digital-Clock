#include <ap_int.h>
#define SIGNAL_PERIOD 400000
//#define SIGNAL_PERIOD 10  // Only for simulation
void refresh_signal(bool &out_signal) {
#pragma HLS INTERFACE ap_none port=out_signal
#pragma HLS INTERFACE ap_ctrl_none port=return
	static int count = SIGNAL_PERIOD-1;
	int next_count = count;
	bool next_out_signal;
	if (count == 0) {
		next_out_signal = 1;
		next_count = SIGNAL_PERIOD-1;
	} else {
		next_out_signal = 0;
		next_count = count-1;
	}
	count = next_count;
	out_signal= next_out_signal;
}
