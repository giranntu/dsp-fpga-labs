Amp = 1;
freq = 800;
fs = 8000;
dt = 1/fs;
index = 1;
sine = [];
sampleNumber = [];
for t = 0:dt:1-dt
   sine(index) = Amp * sin(2*pi*freq*t);
   sampleNumber(index) = index;
   index = index + 1;
end

% alternative to the above loop
% sine = Amp*sin(2*pi*freq*(0:dt:1-dt));

N = 8000;
transform = fft(sine,N)/N;
magTransform = abs(transform);

faxis = linspace(-fs/2,fs/2,N);
plot(faxis,fftshift(magTransform));
axis([-1000 1000 0 0.6])
xlabel('Frequency (KHz)')