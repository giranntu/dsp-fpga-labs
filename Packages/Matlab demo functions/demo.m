
%clear all;
close all;
clc;
%please change to your own directory
cd 'C:\Users\zhwj814\Desktop\EE443\Matlab demo functions'
load('data.mat');
s = serial('COM4', 'BaudRate',115200);
set(s,'InputBufferSize',20000);
fopen(s);  

%Read 256/511 integers value from the board
%a = fread(s,256,'int16'); %->for raw data display
a = fread(s,27,'int16');  %->for convolution display
cpuconv = a(1:1000);
rawdata = a(1001:2000);
matlabconv = conv(rawdata, h);
figure; hold on; plot(cpuconv, 'bx'); plot(matlabconv(1:1000), 'r'); plot(rawdata,'g');
legend('CPU Conv', 'Matlab Conv', 'Raw Data');

% while(1)
%     i = i+1;
%     fwrite(s, '1');
%     fwrite(s, '2');
%     fwrite(s, '3');
%     fwrite(s, '2');
%     if(i == 20)
%         break;
%     end
% end

fclose(s);
delete(s);
'done'