
TESTING_FILES=
CPP_FILES=
O_FILES=$(addprefix srcs/,$(patsubst %.o,%.cpp,$(CPP_FILES)))

CPP=c++ -std=c++26 -Wall -Wextra -I . -I ./headers

TEST_NAME=test.out
NAME=libftpp.a

all: $(NAME)

$(NAME): O_FILES
	$(CPP) -o $(NAME) $(O_FILES)

test: $(TESTING_FILES) $(O_FILES)
	$(CPP) -o $(TEST_NAME) $(O_FILES) $(TESTING_FILE)

%.o: %.cpp
	$(CPP) -Werror -o $? -c $@

fclean: clean
	@rm -f $(NAME) $(TEST_NAME)

clean:
	rm -f $(O_FILES)
