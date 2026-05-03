cc = gcc
CFLAGS = -Wall -g -02

HW_DIR = homework
LAB_DIR = labs
BUILD = build

HW_SRC = $(wildcard $(HW_DIR)/*.c)
LAB_SRC = $(wildcard $(LAB_DIR)/*.c)

HW_PROGS = $(patsubst $(HW_DIR)/%.c,$(BUILD)/hw-%,$(HW_SRC))
LAB_PROGS = $(patsubst $(LAB_DIR)/%.c,$(BUILD)/lab-%,$(LAB_SRC))

.PHONY: all clean list run

all: $(HW_PROGS) $(LAB_PROGS)

list:
	@echo "Homework Programs:"
	@ls $(HW_DIR)/*.c 2>/dev/null || true
	@echo "Lab Programs:"
	@ls $(LAB_DIR)/*.c 2>/dev/null || true

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/hw-%: $(HW_DIR)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "Compiled: $@"

$(BUILD)/lab-%: $(LAB_DIR)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "Compiled: $@"

$(HW_DIR)/%.c: $(BUILD)/hw-%
	@true

$(LAB_DIR)/%.c: $(BUILD)/lab-%
	@true

run: FORCE
	@if [ -z "$(FILE)" ]; then \
		echo "Usage: make run FILE=<program>"; \
	    exit 1; \
	fi
	@case "$(FILE)" in \
		$(HW_DIR)/*.c) \
			$(MAKE) $(BUILD)/hw-$$(basename $(FILE) .c); \
			./$(BUILD)/hw-$$(basename $(FILE) .c) ;; \
		$(LAB_DIR)/*.c) \
			$(MAKE) $(BUILD)/lab-$$(basename $(FILE) .c); \
			./$(BUILD)/lab-$$(basename $(FILE) .c) ;; \
		*) \
			echo "Error: FILE must be in $(HW_DIR) or $(LAB_DIR)"; \
			exit 1; \
	esac

FORCE:

clean:
	rm -rf $(BUILD)
