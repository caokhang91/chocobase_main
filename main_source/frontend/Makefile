CC = clang
SRC = \
    main.c \
    engine/engine.c \
    network/net.c \
    graphics/renderer.c \
    scene/scene.c \
    ui/ui.c \
    input/keyboard.c \
    input/mouse.c

CFLAGS = $(shell sdl2-config --cflags) -I. -lcurl
LDFLAGS = $(shell sdl2-config --libs)

all:
	$(CC) -o titan_client $(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f titan_client
