test.m is a Matlab function that can real time plot data from USB comm port.
Once a data is received, the plot will immediately update.

-This is the example we found online and we modified it to fit our example.
Please feel free to change any setting, titles, parameters inside to make your own version.
We are sorry that we are not the matlab experts so we firmly believe that you can make a better version! :))))



*notes:
1. Matlab needs time to update so if your transmission rate is too fast. Matlab may not be able
to plot in real time and the data needed to be printed will be store in the "inputbuffer".

2. For this demo code, the time interval between each plotting should equal to the sampling rate.
Please take care of it.