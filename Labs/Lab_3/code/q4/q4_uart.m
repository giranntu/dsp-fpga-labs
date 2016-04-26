close all; clc; clear all;
% delete(instrfindall);
s = serial('COM7', 'BaudRate',115200); % Open the serial port to receive the data
set(s,'InputBufferSize',20000); % set the size of input buffer
fopen(s); % get ready to receive the data
buffersize = 256; % set the size of instant read of buffer
x = fread(s,buffersize,'int16'); % read the buffer when data arrive
fclose(s);
delete(s);

%%
if sum(x) > 256/2
    disp('yes')
else
    disp('no')    
end