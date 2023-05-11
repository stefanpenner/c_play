CFLAGS := $(CFLAGS) -g -Wno-everything
PROGRAM = l
FILES = type.c value.c node.c l.c

$(PROGRAM): $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o l

.default: $(PROGRAM)

.PHONY: clean crun run debug
clean:
	rm -rf l

run: l
	./l

crun: clean run


debug: l
	lldb ./l

