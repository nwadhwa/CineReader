%% Make

clear;
cd ..
!make
cd matlab

%% Test
clear;
pause(0.2);
spice = CineReader('/home/nwadhwa/Downloads/Untitled Folder/MembraneTexture.cine');
im = spice.read(1);

%% reverse order

for k = 1:400
    for j = 1:768
        ridx = (k-1)*768+j;
        cidx = (j-1)*400+k;
        spice2(cidx) = im(ridx);
    end
end
close all
imshow(reshape(spice2, [400 768]));