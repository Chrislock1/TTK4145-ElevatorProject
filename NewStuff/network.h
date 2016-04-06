/*
//////////////////////////////
//   SHARED WITH SENSOR THREAD
//////////////////////////////

int ext_orders EXTERNAL_ORDER_CHANNEL_MATRIX[N_FLOORS][2] =
  {BUTTON_UP1, BUTTON_DOWN1},
  {BUTTON_UP2, BUTTON_DOWN2},
  {BUTTON_UP3, BUTTON_DOWN3},
  				.
  				.
  				.
  {BUTTON_UP[N], BUTTON_DOWN[N]},
};



///////////////////////////////////
//   SHARED WITH ELEVATOR THREAD
//////////////////////////////////

int ext_orders EXTERNAL_ORDER_CHANNEL_MATRIX[N_FLOORS][2] =
  {BUTTON_UP1, BUTTON_DOWN1},
  {BUTTON_UP2, BUTTON_DOWN2},
  {BUTTON_UP3, BUTTON_DOWN3},
  				.
  				.
  				.
  {BUTTON_UP[N], BUTTON_DOWN[N]},
};




INTER NETWORK COMMUNICATIONS:



*/