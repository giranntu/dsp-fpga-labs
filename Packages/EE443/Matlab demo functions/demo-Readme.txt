This "demo.m" Matlab function is used to collect integer data from DE2i-150 Board.
Please make sure you properly configure and program the board first.
Once the board has been properly setup, you can run the demo.m function and start sending data to Matlab.

*note

1. If there is no data receive in matlab, an timeout error will appear. You may need to restart the matlab to
open the USB Comm port.

2. "int16" means signed 16 bits integer. You can type "help fread" to explore more capabilities. 

3. If you want to send back control signal to the board, please uncomment the while(1) part in the code. 
Don't forget to check the initial value of "uart_RecvFlag". We should initialize it to 1 (always accept data from host computer).