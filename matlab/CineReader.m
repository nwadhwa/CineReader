% Matlab class to read CINE and post process them according to CINE
% parameters. Post processing includes demosaicing and color correction
classdef CineReader < CineReaderRaw
    %CINEREADER Summary of this class goes here
    %   Detailed explanation goes here
    
    properties        
        gammaLUT;
        maxVal;
        
    end
    
    
    methods
        function this = CineReader(filename)
            this@CineReaderRaw(filename);    
            if (this.rotate ~= 0 )
               swapVar = this.height;
               this.height = this.width;
               this.width = swapVar;
            end
            this.maxVal = 2.^this.BitsPerPixel-1; % Replace for non 8 bit image files                        
            tempIm = CineReaderInterface('read', this.objectHandle, 0);
            if (isa(tempIm, 'uint8'))
                this.gammaLUT = (0:255)/this.maxVal;
                this.gammaLUT = this.gammaLUT.^(1/this.Gamma);
                this.gammaLUT = im2uint8(this.gammaLUT);
            else
                % For images with < 16 BPP, this look up table maps the max
                % value (pure white) to 65535. This means that imshow will
                % work properly and not need to be scaled.
                this.gammaLUT = (0:65535)/this.maxVal;
                this.gammaLUT = this.gammaLUT.^(1/this.Gamma);
                this.gammaLUT = im2uint16(this.gammaLUT);
            end
        end

        function im = postprocess(this, im)
           im = flipud(im');
           % Demosaic
           im = demosaic(im, this.CFA);
           
           % Color correction                                                       
           im = im*this.Gain; % Gain
           
           % White Balance
           im(:,:,1) = im(:,:,1).*this.WhiteBalanceRedGain;
           im(:,:,3) = im(:,:,3).*this.WhiteBalanceBlueGain;
           
           % Brightness
           im = im + 0.255*this.Brightness;% Brightness
           
           % Gamma
           % im = im2uint8(im2single(im).^(1/this.Gamma)); % Gamma
           im = intlut(im, this.gammaLUT); %LUT implementaion
                      
           
           
           % Flip /rotate
           if (xor(this.flipH, this.rotate > 0))
               im = fliplr(im);
           end
           
           if (xor(this.flipV, this.rotate < 0))
               im = flipud(im);
           end
           if (abs(this.rotate) == 90)
              temp = zeros(size(im,2),size(im,1),size(im,3), 'like', im);
              for c = 1:size(im,3)
                 temp(:,:, c) = im(:,:,c)';
              end  
              im = temp;
           end
           
           
        end
        
    end
    
end

