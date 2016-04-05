close all; clc; clear all;
s = serial('COM5', 'BaudRate',115200); % Open the serial port to receive the data
set(s,'InputBufferSize',20000); % set the size of input buffer
fopen(s); % get ready to receive the data
buffersize = 256; % set the size of instant read of buffer
a = fread(s,buffersize,'int16'); % read the buffer when data arrive

%%
%% Time specifications:
Fs = 256;                      % samples per second
dt = 1/Fs;                     % seconds per sample
StopTime = 1;                  % seconds
t = (0:dt:StopTime-dt);
N = size(t,1);

%% Fourier Transform:
X = fftshift(fft(a));
%% Frequency specifications:
dF = Fs/N;                      % hertz
f = -Fs/2:dF:Fs/2-dF;           % hertz
%% Plot the spectrum:
plot(a);
figure;
plot(f,abs(X)/N);
xlabel('Frequency (in hertz)');
title('Magnitude Response');


%%
fclose(s);
delete(s);
'done'