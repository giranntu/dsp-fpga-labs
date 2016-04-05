close all; clc; close all;
delete(instrfindall);
s = serial('COM3', 'BaudRate',115200);
set(s,'InputBufferSize',20000);
fopen(s);
buffersize = 128;

a = fread(s,buffersize,'int16');
plot(a);

fclose(s);
delete(s);
'done'