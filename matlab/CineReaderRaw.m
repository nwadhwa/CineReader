%CLASS_INTERFACE Example MATLAB class wrapper to an underlying C++ class
classdef CineReaderRaw < handle
    properties (SetAccess = private, Hidden = true)
        objectHandle; % Handle to the underlying C++ class instance
    end
    properties
        width;
        height;
        NumberOfFrames;        
        FrameRate;
        WhiteBalanceRedGain;
        WhiteBalanceBlueGain;
        Brightness;        
        Gain;
        Gamma;
        
        flipH;
        flipV;
        rotate;
        
        BitsPerPixel;
        
        Exposure;
        CFA;
    end
  
    
    methods
        %% Constructor - Create a new C++ class instance 
        function this =CineReaderRaw(filename)
            % Quick hack for now with regards to tilde in filename
            if (strcmp(filename(1), '~'))
               filename = [getenv('HOME') filename(2:end)]; 
            end
            
            this.objectHandle = CineReaderInterface('new', filename);
            this.NumberOfFrames = CineReaderInterface('NumberOfFrames', this.objectHandle);
            this.width = CineReaderInterface('Width', this.objectHandle);
            this.height = CineReaderInterface('Height', this.objectHandle);        
            this.FrameRate = CineReaderInterface('FrameRate', this.objectHandle);
            
            this.WhiteBalanceRedGain = CineReaderInterface('WBR', this.objectHandle);
            this.WhiteBalanceBlueGain = CineReaderInterface('WBB', this.objectHandle);
            this.Brightness = CineReaderInterface('Bright', this.objectHandle);
            this.Gain = CineReaderInterface('Gain', this.objectHandle);            
            this.Gamma = CineReaderInterface('Gamma', this.objectHandle);
            
            this.flipH = CineReaderInterface('flipH', this.objectHandle);
            this.flipV = CineReaderInterface('flipV', this.objectHandle);
            this.rotate = CineReaderInterface('rotate', this.objectHandle);
            
            this.BitsPerPixel = CineReaderInterface('BPP', this.objectHandle);
            
            this.Exposure = CineReaderInterface('Exposure', this.objectHandle);
            this.getCFAPatternString();
        end
        
        function getCFAPatternString(this)
            temp = CineReaderInterface('CFA', this.objectHandle);
            switch temp
                case 3
                    this.CFA = 'gbrg';
                case 4
                    this.CFA = 'rggb';                
                otherwise
                    this.CFA = 'rggb';
            end
        end
        
        %% Destructor - Destroy the C++ class instance
        function delete(this)
            CineReaderInterface('delete', this.objectHandle);
        end

        function im = postprocess(this, im)
            im = flipud(im');
        end
        
        %% Read frames from cine
        function im = read(this, frameRange)
            
            if (exist('frameRange', 'var'))
                frameRange = ceil(frameRange);
                if (numel(frameRange) == 1)                
                    if (or(frameRange <1, frameRange > this.NumberOfFrames))
                        error('Invalid value of frame range.');
                    end
                    im = this.postprocess(CineReaderInterface('read', this.objectHandle, frameRange-1));
                elseif (numel(frameRange) == 2)                
                    if (frameRange(2) <= frameRange(1))
                        error('Second element of frame range must be larger than first.\n');
                    end
                    temp = this.postprocess(CineReaderInterface('read', this.objectHandle, frameRange(1)));
                    im = zeros(this.height, this.width, size(temp,3), frameRange(2)-frameRange(1)+1,class(temp));
                    for k = frameRange(1):frameRange(2)
                        im(:,:,:,k-frameRange(1)+1) = this.postprocess(CineReaderInterface('read', this.objectHandle, k-1));
                    end                                                                       
                else 
                    error('Argument must be a single number or a two element array\n');
                end
            else
               temp = this.postprocess(CineReaderInterface('read', this.objectHandle, 0));
               im = zeros(this.height, this.width, size(temp,3), this.NumberOfFrames,class(temp));
               for k = 1:this.NumberOfFrames
                  im(:,:,:,k) = this.postprocess(CineReaderInterface('read', this.objectHandle, k-1)); 
               end
               
            end
        end
    end
end
