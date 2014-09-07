%CLASS_INTERFACE Example MATLAB class wrapper to an underlying C++ class
classdef CineReader < handle
    properties (SetAccess = private, Hidden = true)
        objectHandle; % Handle to the underlying C++ class instance
    end
    properties
        width;
        height;
        NumberOfFrames;        
    end
  
    
    methods
        %% Constructor - Create a new C++ class instance 
        function this =CineReader(filename)
            this.objectHandle = CineReaderInterface('new', filename);
            this.NumberOfFrames = CineReaderInterface('NumberOfFrames', this.objectHandle);
            this.width = CineReaderInterface('Width', this.objectHandle);
            this.height = CineReaderInterface('Height', this.objectHandle);            
        end
        
        %% Destructor - Destroy the C++ class instance
        function delete(this)
            CineReaderInterface('delete', this.objectHandle);
        end

        function im = fliptrans(this, im)
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
                    im = this.fliptrans(CineReaderInterface('read', this.objectHandle, frameRange-1));
                elseif (numel(frameRange) == 2)                
                    if (frameRange(2) <= frameRange(1))
                        error('Second element of frame range must be larger than first.\n');
                    end
                    temp = this.fliptrans(CineReaderInterface('read', this.objectHandle, frameRange(1)));
                    im = zeros(this.height, this.width, 1, frameRange(2)-frameRange(1)+1,class(temp));
                    for k = frameRange(1):frameRange(2)
                        im(:,:,1,k) = this.fliptrans(CineReaderInterface('read', this.objectHandle, k-1));
                    end                                                                       
                else 
                    error('Argument must be a single number or a two element array\n');
                end
            else
               temp = this.fliptrans(CineReaderInterface('read', this.objectHandle, 0));
               im = zeros(this.height, this.width, 1, this.NumberOfFrames,class(temp));
               for k = 1:this.NumberOfFrames
                  im(:,:,1,k) = this.fliptrans(CineReaderInterface('read', this.objectHandle, k-1)); 
               end
               
            end
        end
    end
end