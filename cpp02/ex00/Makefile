CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME = fixed
SRCDIR = $(shell find . -type d  -not -name "includes" -not -path ".*" | xargs)
SRC = $(shell find . $(SRCDIR) -name "*.cpp" -type f | xargs)
OBJDIR = objs
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
INCLUDE = -I includes


vpath	$(SRCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAG) $(OBJ) $(INCLUDE) $(LIBRARY) -o $(NAME)
	@echo "Compilation done"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@
	@echo "Compiled "$<" successfully"

clean:
	@rm -rf $(OBJDIR)
	@echo "Objs deleted"
	@echo "Clean done"

fclean: clean
	@rm -rf $(NAME)
	@echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re
