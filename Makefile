CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Encoder.o main.o

LIBS =		Encoder.h

TARGET =	encoder

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
