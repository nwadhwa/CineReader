include_directories(${CINEREADER_SOURCE_DIR}/src)
link_directories(${CINEREADER_BINARY_DIR}/src)

add_library(cinereader STATIC bitmapinfoheader.cpp bitreader.cpp cinefileheader.cpp cineimage.cpp cinereader.cpp  imageoffsets.cpp setup.cpp test.cpp)
# add_executable(cinereadertest testwin.cpp bitmapinfoheader.cpp bitreader.cpp cinefileheader.cpp cineimage.cpp cinereader.cpp  imageoffsets.cpp setup.cpp)