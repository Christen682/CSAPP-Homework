SUBDIRS = $(wildcard ch*/labs) $(wildcard ch*/homework)

all:
	@for dir in $(SUBDIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "Starting: $$dir"; \
			$(MAKE) -C $$dir; \
		fi; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "Cleaning: $$dir"; \
			$(MAKE) -C $$dir clean; \
		fi; \
	done

.PHONY: all clean