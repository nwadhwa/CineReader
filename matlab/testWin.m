%% Make
clear;
compile

%% Test
clear;
pause(0.2);
rootDir = 'C:\Users\wadhwa\Downloads';
%cines = {'testCineC.cine', 'testCine_flipHC.cine', 'testCine_flipVC.cine', 'testCine_flipHVC.cine'};
cines = {'testCineB10G1G4.cine'};
for k = 1:numel(cines)
    spice = CineReader(fullfile(rootDir, cines{k}));
    spice
    im = spice.read(1);
    figure();
    imshow(im)
    
end

%% reverse order
