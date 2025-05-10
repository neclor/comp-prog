# ======= Make ======= #

TARGET =

SRC_DIR	= src
OBJ_DIR = build

SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
INCS = $(shell find $(SRC_DIR) -type d)

I_INC = $(addprefix -I, $(INCS))

CC = gcc
CFLAGS = --std=c99 --pedantic -Wall -W -Wextra -Wmissing-prototypes $(I_INC)
LD = gcc
LDFLAGS = -lm

# ======= Test ======= #

TEST_DIR = test

TESTS = $(shell find $(TEST_DIR) -type f -name "*.c")
TEST_OBJS = $(TSTS:%.c=$(OBJ_DIR)/%.o)
TEST_INCS = $(shell find $(TEST_DIR) -type d)

TEST_I_INC = $(addprefix -I, $(TEST_INCS))

TEST_CFLAGS = --std=c99 --pedantic -Wall -W -Wextra -Wmissing-prototypes $(I_INC) $(TEST_I_INC)

# ======= Rules ======= #

all: test_array test_list

$(TARGET): $(OBJS)
	$(LD) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c $(INCS)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

# ======= Test Rules ======= #

test_array: course_tableau_test

test_list: course_liste_test

%_test: $(OBJ_DIR)/$(TST_DIR)/%_test.o $(OBJ_DIR)/$(SRC_DIR)/course/%.o $(OBJ_DIR)/$(SRC_DIR)/escale.o
	$(LD) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/$(TST_DIR)/%.o: $(TST_DIR)/%.c $(INCS) $(TEST_INCS)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(TEST_CFLAGS)

doc:
	@doxygen Doxyfile

clean:
	@make pnm_clean
	@rm -rf $(OBJ_DIR) $(TARGET) $(TST_DIR)/$(OBJ_DIR) $(TEST)

git:
	@git pull
	@git add .
	@git commit -m Update
	@git push

tar:
	@tar -czvf ../tad-groupe33.tar.gz ../code ../rapport

.PHONY: all test_array test_list clean git tar
