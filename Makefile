OUTFILE = "arz.so"
# -static-libstdc++
COMPILE_FLAGS = -m32 -fpermissive -c -O2 -w -idirafter "sdk"
LINK_FLAGS = -m32 -fpermissive -shared -O2

all:
	gcc $(COMPILE_FLAGS) sdk/pawn/amx/*.h
	g++ $(COMPILE_FLAGS) -std=c++11 sdk/pawn/*.cpp
	g++ $(COMPILE_FLAGS) -std=c++11 sdk/raknet/*.cpp
	g++ $(COMPILE_FLAGS) -std=c++11 *.cpp
	g++ $(LINK_FLAGS) -o $(OUTFILE) *.o
	rm *.o
	strip -s $(OUTFILE)
