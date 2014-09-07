srcDir = '../src';
srcFiles = {'', 'bitreader.cpp',  'cinefileheader.cpp',  'bitmapinfoheader.cpp', 'imageoffsets.cpp' 'cineimage.cpp', 'cinereader.cpp' ,'setup.cpp'}; 
for k = 1:numel(srcFiles)
   srcFiles{k} = fullfile(srcDir, srcFiles{k}); 
end
srcFiles{1} = 'CineReaderInterface.cpp';

mex(srcFiles{:});