%% Make
clear;
compile

%% Test
clear;
pause(0.2);
rootDir = '~/Downloads/';
cines = {'drum_flipH.cine', 'drum_flipV.cine', 'drum_rotateClock.cine', 'flipV_rotateCounter.cine'};

for k = 1:numel(cines)
    spice = CineReader(fullfile(rootDir, cines{k}));
    spice
end
im = spice.read(1);

%% reverse order
