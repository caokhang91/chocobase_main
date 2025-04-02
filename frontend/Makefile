CC = clang
CFLAGS = $(shell sdl2-config --cflags) -lcurl
LDFLAGS = $(shell sdl2-config --libs)
TARGET = chocobase_client

all: $(TARGET)

$(TARGET): main.c
	$(CC) -o $(TARGET) main.c $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)
