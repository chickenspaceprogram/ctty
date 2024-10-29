# "Visual Studio at home"

# To compile, run `make` or `make all`
# To run, run `make run`.
# To delete compiled files, run `make clean`.
# To export the project as a .zip file, run `make zip`.
# To make a new project, run `make new`.


# comments are here since I will have to review this in 6 months and will wonder what it's doing

.PHONY: all clean objects run zip build new copy-files

# directories and file names
NAME:=ctty
SYMLINK:=./$(NAME)# puts a symlink to the actual binary in this directory path

TARGET:=target
BIN:=$(TARGET)/bin
OBJ:=$(TARGET)/obj
SRC:=src
ALL_SRCS:=$(shell find . -name "*.c") # gets a space separated list of every source file in src/
ALL_OBJS:=$(subst ./$(SRC),$(OBJ),$(ALL_SRCS:.c=.o)) # replaces src/ with target/obj/ and .c with .o for each thing in ALL_SRCS
FILE_SRCS:=$(shell find src -not -type d | grep -v '\.[ch]$$')
FILE_DESTS:=$(subst $(SRC)/,,$(FILE_SRCS))

# wrapper for `build`
all: $(BIN) build $(FILE_DESTS) $(SYMLINK)
	@printf "\nBuild completed successfully!\n"

# linking source files into a single executable
build: $(ALL_OBJS)
	$(CC) $^ -o $(BIN)/$(NAME)

# this is a very hacky way to put all of the text files in the right places, oh well
$(FILE_DESTS): $(SRC)/$(FILE_DESTS)
	mkdir -p $(dir $@)
	cp $(SRC)/$@ $@


# compiling source files
$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	mkdir -p $(dir $@)
	$(CC) -Wall -c -I$(SRC) $< -o $@

# Making target directories

$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

clean: 
	rm -rf target
	rm -f $(NAME).zip
	rm -f Boose_PA5
	rm -f rules.txt

# running executable
run: all
	$(BIN)/$(NAME)

zip: clean
	mkdir $(NAME)
	cp -R $(SRC) $(NAME)
	cp Makefile $(NAME)
	zip -r $(NAME).zip $(NAME)
	rm -rf $(NAME)

new: 
	mkdir src
	printf ".DS_Store\ntarget\n$(NAME).zip\n$(NAME)" >> .gitignore

$(SYMLINK):
	ln -s $(BIN)/$(NAME) $(SYMLINK)