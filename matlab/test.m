%% Make
clear;
compile

%% Test
clear;
pause(0.2);
spice = CineReaderRaw('/home/nwadhwa/Downloads/drumhead_20140613.cine');
im = spice.read(1);

%% reverse order
spice