/*
//////////////////////////////////
//   SHARED WITH NETWORK THREAD
//////////////////////////////////

EXTERNAL ORDERS:
	int ext_orders EXTERNAL_ORDER_CHANNEL_MATRIX[N_FLOORS][2] =
	  {BUTTON_UP1, BUTTON_DOWN1},
	  {BUTTON_UP2, BUTTON_DOWN2},
	  {BUTTON_UP3, BUTTON_DOWN3},
	  				.
	  				.
	  				.
	  {BUTTON_UP[N], BUTTON_DOWN[N]},
	};


COMPLETED ORDER:

	int completed_order = #etg; // 0 else


//////////////////////////////////
//   SHARED WITH SENSOR THREAD
//////////////////////////////////


LAST FLOOR:

	int[N_FLOORS] = {0/1,...,0/1};
	

*/