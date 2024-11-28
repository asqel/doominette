DIRS = $(wildcard */)
OUTS = $(DIRS:/=.so)

all: build


build: $(OUTS)

%.so:
	cc -fPIC --shared -g -o $(basename $@)/tester.so $(wildcard $(basename $@)/*.c $(basename $@)/*/*.c) -I../include


clean:
	rm -rf ./*/*.so


.PHONY: clean

