%% Make
clear;
compile

%% Test
clear;
pause(0.2);
rootDir = 'C:\Users\wadhwa\Downloads';
cines = {'testCineG1.cine'};

for k = 1:numel(cines)
    spice = CineReader(fullfile(rootDir, cines{k}));
    spice
end
im = spice.read(1);
imshow(im)
%% reverse order
