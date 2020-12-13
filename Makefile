#directories
IDIR = inc
ODIR = obj
SDIR = src
LDIR = lib
#compiler settings
CC = clang
CFLAGS= -I $(IDIR)
CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I $(IDIR)
#dependencies
EXECUTABLE = matrix_rain
#libs
LIBS = -lncurses $(LIB_NAME)
LIBS_AWS = -lncurses $(LIB_NAME)
#headers
_DEPS = -I inc
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
#objects
_OBJ = stream.o printer.o tear.o generator.o clear.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
#make objects
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
    mkdir -p obj
    $(CC) -c -o $@ $< $(CCFLAGS)
#make excecutable
$(EXECUTABLE): $(OBJ) $(LIB_NAME)
    $(CC) -o $@ $^ $(CCLAGS) $(LIBS)
#for AWS
AWS: $(OBJ) $(LIB_NAME)
    $(CC) -o $(EXECUTABLE) $^ $(CFLAGS) $(LIBS_AWS)
#build library
#$(LIB_NAME):
#   mkdir -p lib
#   cp src/$(LIB_FILES).c lib
#   $(CC) $(CFLAGS) -I inc -c lib/$(LIB_FILES).c
#   mv $(LIB_FILES).o lib
#   ar rcs $(LIB_NAME) lib/$(LIB_FILES).o
#   rm -rf lib
.PHONY: clean uninstall reinstall
#delete all files
uninstall: clean
    rm -f $(LIB_NAME)
    rm -f $(EXECUTABLE)
    rm -rf $(LDIR)
#remove all temporary files
clean: 
    rm -rf $(ODIR)
    rm -f *.a
#rebuild project
reinstall: uninstall all
