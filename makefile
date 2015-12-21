#Compiler GCC

CC = gcc

#compiler flags

CFLAGS = -g -Wall

TARGET = calendar

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)

