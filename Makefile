CFLAGS := $(CFLAGS) -g -Wno-everything
PROGRAM = main
FILES = $(shell ls *.c)

$(PROGRAM): $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o main

.default: $(PROGRAM)

.PHONY: clean crun run debug
clean:
	rm -rf $(PROGRAM) *.dSYM

run: $(PROGRAM)
	./$(PROGRAM)

crun: clean run

debug: $(PROGRAM)
	lldb ./$(PROGRAM)

