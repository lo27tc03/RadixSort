#Radix sort makefile
#Targets :
# 	all 	: compile everything
# 	lib 	: generate library
#		clean : cleans temporary files and binary files

CXX = gcc
CFLAGS = -Wall -Werror -pedantic -fPIC -ggdb
#penser à retirer -g quand on rendra le projet
LIBSDIR = -L. -L/usr/lib
INCLUDEDIR = -I. -I/usr/include

#List lib Library-related macros
targetList = libList.so
targetListName = List

listSources = BaseNIntegerList
listSourcesC = $(listSources:=.c)
listSourcesO = $(listSources:=.o)

#ListOfList lib Library-related macros
targetListOfList = libListOfList.so
targetListOfListName = ListOfList

listOfListSources = BaseNIntegerListOfList
listOfListSourcesC = $(listOfListSources:=.c)
listOfListSourcesO = $(listOfListSources:=.o)


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
$(TARGET): $(EXESOURCEOFILE) $(targetList) $(targetListOfList)
	@echo "\n Generating the executable " $@
	$(CXX) $(EXESOURCEOFILE) $(LIBSDIR) -o $(TARGET) -l$(targetListName) -l$(targetListOfListName)

#Generating the library libList.so binary code
$(targetList): $(listSourcesO)
	@echo "\n Generating the library " $@
	$(CXX) $(CFLAGS) -shared $(listSourcesO) -o $(targetList)


#Generating the library libListOfList.so binary code
$(targetListOfList): $(listOfListSourcesO)
	@echo "\n Generating the library " $@
	$(CXX) $(CFLAGS) -shared $(listOfListSourcesO) -o $(targetListOfList)

#Generating an object file from a C file having the same name
.c.o:
	@echo "\n Generating " $@ " from " $<
	$(CXX) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

#Cleaning the content of the current directory
clean:
	@echo "\n Cleaning temporary files"
	rm -rf *.o *~ *.so *.exe
