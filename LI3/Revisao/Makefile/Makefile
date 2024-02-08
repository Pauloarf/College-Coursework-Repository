# Compiler used
CC=gcc
# Flags to use when compiling
# - Wall: show all warnings
# - Iinclude: directory for the local header files
# - `pkg-config --cflags glib-2.0`: glib header files directories (optional, only needed if using glib)
CFLAGS=-Wall -Iinclude `pkg-config --cflags glib-2.0`
# Flags to use when linking
# - `pkg-config --libs glib-2.0`: glib library (optional, only needed if using glib)
# - `-lm`: math library (optional, only needed if using glib)
LDFLAGS=`pkg-config --libs glib-2.0` -lm
# Executable called 'program'.
#
# To generate it, we link all the .o files and the glib and math libraries.
# We use £(NAME) to use the variable NAME.
# £@ is equivalent to the target. In this case, £@ evaluates to: program
# £^ evaluates to the dependencies: In this case, it evaluates to: src/main.o src/file1.o src/file2.o
# In this example, we have the following rule:
# gcc `pkg-config --libs glib-2.0` -lm -Wall -Iinclude `pkg-config --cflags glib-2.0` src/main.o src/file#
# Since this is the first rule, it will be the one called when executing 'make' without any arguments.
# In other words, 'make' is equivalent to 'make program'.
#
# To execute this rule, the make will first need to execute rules 'src/main.o', 'src/file1.o',
# and 'src/file2.o', as specified in the list of dependencies (right)
program: src/main.o src/file1.o src/file2.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@


#// WARNING: Erro corrigido, antes lia-se
#// $(CC) $(LDFLAGS) $(CFLAGS) $^ -o $@


# Here we generate the object files for each source.
# An empty rule is equivalent to £(CC) £(CPPFLAGS) £(CFLAGS) -c <left param> <right param>.
# As such, we set the target (left) as the name of the object file to be generated
# and the name of the source file in the list of dependencies (right).
# This specific rule is equivalent to:
# gcc -Wall -Iinclude `pkg-config --cflags glib-2.0` -c -o src/main.o src/main.c
src/main.o: src/main.c
# Equivalent to the one above
#src/main.o: src/main.c
# £(CC) £(CFLAGS) -c -o £@ £^
src/file1.o: src/file1.c
src/file2.o: src/file2.c
# The clean will remove the executable (program) and object files (*.o).
# To run it, we must execute 'make clean'
clean:
	rm -f program src/*.o