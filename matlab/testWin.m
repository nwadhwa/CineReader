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
profile on
for k = 1:10
    im = spice.read(1);
end
profile viewer
imshow(im)
%% reverse order
