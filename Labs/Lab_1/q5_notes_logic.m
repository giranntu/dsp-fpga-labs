close all; clear all; clc;
Fs = 8000;
accum = 0;
step = pi/4;
delta = 100;
n = 0:pi/delta:2*pi-pi/4;
% n = 0:1/Fs:0.01;
f = 1000;
y = sin(n);

% make gain larger, like ~10k
sq = zeros(1, length(y));

for i=1:length(y)
    if abs(y(i)) >= accum
        accum = accum + step;
        sq(i) = 1;
    else 
        accum = accum - step;
        sq(i) = -1;
    end
end

plot(sq)

