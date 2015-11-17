#Radix sort makefile
#Targets :
# 	all 	: compile everything
# 	lib 	: generate library
#		clean : cleans temporary files and binary files

CXX = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -fPIC -g
#penser à retirer -g quand on rendra le projet
LIBSDIR = -L. -L/usr/lib
INCLUDEDIR = -I. -I/usr/include

#Listlib Library-related macros
LLIBTARGET = libList.so
LLIBTARGET2 = List
LLIBSOURCE = BaseNIntegerList
LLIBSOURCECFILE = $(LLIBSOURCE:=.c)
LLIBSOURCEOFILE = $(LLIBSOURCE:=.o)

#ListOfListlib Library-related macros


#Application-related macros
TARGET = radix
EXESOURCE = radix
EXESOURCECFILE = $(EXESOURCE:=.c)
EXESOURCEOFILE = $(EXESOURCE:=.o)

#To overload the content of the LD_LIBRARY_PATH
# export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.

#Running the program
run: $(TARGET)
	@echo "\n Executing the executable " $(TARGET)
	./$(TARGET)

#Generating the executable
$(TARGET): $(EXESOURCEOFILE) $(LLIBTARGET)
	@echo "\n Generating the executable " $@
	$(CXX) $(EXESOURCEOFILE) -l$(LLIBTARGET2) $(LIBSDIR) -o $(TARGET)

#Generating the library binary code
$(LLIBTARGET): $(LLIBSOURCEOFILE)
	@echo "\n Generating the library " $@
	$(CXX) $(CFLAGS) -shared $(LLIBSOURCEOFILE) -o $(LLIBTARGET)

#Generating an object file from a C file having the same name
.c.o:
	@echo "\n Generating " $@ " from " $<
	$(CXX) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

#Cleaning the content of the current directory
clean:
	@echo "\n Cleaning temporary files"
	rm -rf *.o *~ *.so *.exe
