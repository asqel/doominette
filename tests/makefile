DIRS = $(wildcard */)
OUTS = $(DIRS:/=.so)

all: build


build: $(OUTS)

%.so:
	gcc -fPIC -shared -o $(basename $@)/tester.so $(wildcard $(basename $@)/*.c $(basename $@)/*/*.c) -I../include


clean:
	rm -rf $(DIRS)/tester.so


.PHONY: clean

