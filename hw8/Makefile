# Makefile for hw8
# format of entries;

# <target list>: <dependency list>
# 	<command list>

# make will look at the last-write dates of each file, and if the
# target file hasn't been updated since the source files were last
# modified, it will update the target file by executing the shell
# command.  Note that the character before <command list> MUST be a
# tab, not spaces.

cc = icc
CFLAGS = -Wall

graham: main.o graham.o
	$(cc) $(CFLAGS) -o graham main.o graham.o 

# note that if calc.h changes, main.c and getop.c must be recompiled

main.o: main.c point.h
	$(cc) $(CFLAGS) -c main.c

graham.o: graham.c 
	$(cc) $(CFLAGS) -c -o graham.o graham.c

# This tells make what to make if you just type 'make'; if this isn't
# there, the first rule in the file will be the default.


# Here is a rule to clean up the directory when calc is final and you
# want to reduce the clutter in the listing.  Note that clean doesn't
# need to depend on any file modification time, so the <dependency
# list> position is just left empty.

clean:
	rm *.o


