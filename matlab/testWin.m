%% Make
clear;
compile

%% Test
clear;
pause(0.2);
rootDir = 'C:\Users\wadhwa\Desktop';
%cines = {'testCineC.cine', 'testCine_flipHC.cine', 'testCine_flipVC.cine', 'testCine_flipHVC.cine'};
cines = {'test01_4_87Hz_damageBall.cine'};
for k = 1:numel(cines)
    spice = CineReader(fullfile(rootDir, cines{k}));
    spice
    profile on
    for j = 1:10
        im = spice.read(1);
    end
    profile viewer
    figure();
    imshow(im)
    
end

%% reverse order
