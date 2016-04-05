%% Create the serial object
delete(instrfindall);
serialPort = 'COM3';
serialObject = serial(serialPort, 'BaudRate', 115200);
fopen(serialObject);

%% Set up the figure window
time = 0;

w1 = 0;
target1 = 0;

sample = 0;

%figureHandle = figure('NumberTitle','off',...
%    'Name','EE443 USB data transmission Demo',...
%    'Color',[0 0 0],'Visible','off');

figureHandle = figure('NumberTitle','off',...
    'Name','EE443 USB data transmission Demo',...
    'Visible','off');

% Set axes
%axesHandle = axes('Parent',figureHandle,...
%    'YGrid','on',...
%    'YColor',[0.9725 0.9725 0.9725],...
%    'XGrid','on',...
%    'XColor',[0.9725 0.9725 0.9725],...
%    'Color',[0 0 0]);

axesHandle = axes('Parent',figureHandle,'YGrid','on','XGrid','on');

hold on;

plotHandle = plot(axesHandle,time,w1,time,target1,'LineWidth',2);

%xlim(axesHandle,[min(time) max(time+0.001)]);

% Create xlabel
xlabel('Timp [s]','FontWeight','bold','FontSize',14,'Color',[0 0 1]);

% Create ylabel
ylabel('ADC value','FontWeight','bold','FontSize',14,'Color',[0 0 1]);

% Create title
title('EE443 USB data transmission Demo','FontSize',15,'Color',[0 0 1]);

% microcontroller - time between each value sent on RS232
sampleTime = 0.00000007;

% interval pause for PC data collection
pauseInterval = sampleTime / 10;

%% Collect data
count = 1;

set(figureHandle,'Visible','on');

hf=figure('position',[0 0 eps eps],'menubar','none');



while 1
    ch = get(hf,'currentcharacter');
    
    if strcmp(ch, 'q') %quit
        close(hf)
        break
    end
    
    if strcmp(ch, 'c') %clear
        time = 0;
        w1 = 0;
        target1 = 0;
        count = 1;
    end
    
    sample = fread(serialObject,2,'int16');

    time(count) = count * sampleTime;
    
    w1(count) = sample(1);
    %target1(count) = sample(2);
    
    if count  >= 100
        count = 0;
%         time = time(end-100:end);
%         w1 = w1(end-100:end);
    end
    
    hold off;
    
    set(plotHandle, {'YData'}, {w1}, {'XData'}, {time});

    pause(pauseInterval);
    count = count + 1;

end

%% Clean up the serial object
fclose(serialObject);
delete(serialObject);
clear serialObject;
%clear all;