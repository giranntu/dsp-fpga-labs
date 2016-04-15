% HW1 Question 5
% Jake and Jisoo

close all; clc; clear all;

%% Read UART
s = serial('COM5', 'BaudRate',115200); % Open the serial port to receive the data
set(s,'InputBufferSize',20000); % set the size of input buffer
fopen(s); % get ready to receive the data
buffersize = 128*6; % set the size of instant read of buffer
x = fread(s,buffersize,'int16'); % read the buffer when data arrive
%%
close all;
original = x(1:128*3);
flipped = x(128*3+1:end);
% figure;
% plot(flipped);
% figure
% plot(original);
% 
% flipped_frame1 = flipud(flipped(1:128));
% flipped_frame2 = flipud(flipped(128+1:2*128));
% flipped_frame3 = flipud(flipped(2*128+1:end));
% 
% original_from_flipped = [flipped_frame1; flipped_frame2; flipped_frame3];
% figure;
% plot(original_from_flipped);
% original - original_from_flipped
