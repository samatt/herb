TINS_LIB_PATH="../lib/"
TINS_INCLUDE_PATH="../include/"
APP_NAME="debug"
SRC=""
g++ -std=c++11 $SRC"main.cpp" $SRC"HerbivoreUtils.cxx" $SRC"HerbParser.cxx"  $SRC"HerbSniffer.cxx"  -o $APP_NAME -L$TINS_LIB_PATH  -I$TINS_INCLUDE_PATH -lpthread -ltins -lpcap