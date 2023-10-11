##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## By Thomas Baruzier
##

CC=gcc
CFLAGS= -Wall -Wextra
#CFLAGS= -Wall -Wextra -Ofast -march=native -flto

all: main

########
# MAIN #
########

main: *.c lib/my/libmy.a
	@echo -e '\n\e[34;1m==> TARGET: main\e[0m\n'
	$(CC) $(CFLAGS) *.c -c -I./include/
	$(CC) $(CFLAGS) *.o -o main -L./lib/my/ -lmy
	@echo -e '\n\e[32;1m==> SUCCESS: Built main!\e[0m\n'
	@echo -e '\e[0;1mExecuting ./main...\n\e[33m▼\e[0m'
	@./main
	@echo -e '\e[s\n\e[u\e[33;1m\e[B▲\e[0m\n'
	@make clean >/dev/null

live: *.c
	@echo -e '\n\e[0;1m==> INFO: Live mode activated.\e[0m'
	@{ \
		trap "echo -e '\e[?25h' && exit" 2 3 && echo -e '\e[?25l'; \
		while true; do \
			new=$$(cat $$(find -name '*.c' -o -name '*.h') | md5sum); \
			[ "$$previous" != "$$new" ] && previous="$$new" && \
			echo -en '\e[A' && make --no-print-directory main; \
			sleep 0.5; \
		done \
	}

#########
# LIBMY #
#########

libmy: lib/my/libmy.a

lib/my/libmy.a: ./lib/my/*.c ./lib/my/build.sh
	@echo -e '\n\e[34;1m==> TARGET: libmy\e[0m\n'
	@cd lib/my && ./build.sh && cd ../..
	@echo -e '\n\e[32;1m==> SUCCESS: Built libmy!\e[0m\n'

#########
# TESTS #
#########

test:
	@make --no-print-directory clean_all >/dev/null
	@make --no-print-directory tests_run
	@echo -en '\e[A'
	@make --no-print-directory coverage
	@echo -en '\e[A'
	@make --no-print-directory banana

tests_run: *.c tests/*.c lib/my/libmy.a
	@echo -e '\n\e[34;1m==> TARGET: tests_run\e[0m\n'
	$(CC) $(CFLAGS) $$(ls *.c | grep -v main.c) tests/*.c -o tests/unit_tests \
        -I./include/ -L./lib/my/ -lcriterion -lmy --coverage
	@echo -e '\n\e[32;1m==> SUCCESS: Built tests_run!\e[0m\n'
	@echo -e '\e[0;1mExecuting ./tests/unit_tests...\e[0m\n'
	@./tests/unit_tests
	@echo

coverage: tests/unit_tests tests/*.gcno tests/*.gcda
	@echo -e '\n\e[34;1m==> TARGET: coverage\e[0m\n'
	@{ \
 		output=$$(gcovr --exclude tests | tail -n+5); \
		output=$$(head -n-3 <<< "$$output" | grep -v 100%); \
		if [ $$(wc -l <<< "$$output") -le 2 ]; then \
 		   echo -e "> \e[0;1m100% Line coverage\e[0m\n"; \
 	   else \
 		   echo -e "$$output\n"; \
 	   fi; \
 	   output=$$(gcovr --exclude tests --branches | tail -n+5); \
 	   output=$$(head -n-3 <<< "$$output" | grep -v 100%); \
 	   if [ $$(wc -l <<< "$$output") -le 2 ]; then \
 		   echo -e "> \e[0;1m100% Branch coverage\e[0m"; \
 	   else \
 		   echo "$$output"; \
 	   fi \
	}
	@echo

##########
# BANANA #
##########

banana:
	@echo -e '\n\e[34;1m==> TARGET: banana\e[0m\n'
	@make --no-print-directory clean_all
	@{ \
		input="$$PWD"; \
		output="/home/$$USER/.cache/coding-style-checker"; \
		sudo rm -rf "$$output"; \
		mkdir -p "$$output"; \
		sudo docker run --rm -i -v "$$input":/mnt/delivery \
			-v "$$output":/mnt/reports \
			ghcr.io/epitech/coding-style-checker:latest \
			/mnt/delivery /mnt/reports; \
		export_file=$$(find "$$output" -type f | head -n 1); \
		sed -i '/illegal token in column/d' "$$export_file"; \
		if [ -f "$$export_file" ]; then \
			errors=$$(wc -l < "$$export_file"); \
			fatal=$$(grep -c 'FATAL' < "$$export_file"); \
			major=$$(grep -c 'MAJOR' < "$$export_file"); \
			minor=$$(grep -c 'MINOR' < "$$export_file"); \
			info=$$(grep -c 'INFO' < "$$export_file"); \
			if [ -s "$$export_file" ]; then \
				echo -e "\n\e[0;1m> Banana report: \e[0m\n"; \
				column < "$$export_file"; \
				echo; \
			else \
				echo -en "\n\e[0;1m> Banana report: \e[0m"; \
			fi; \
		echo -en "\e[31mFATAL: $$fatal \e[0m- \e[33mMAJOR: $$major \e[0m"; \
		echo -e "- \e[32mMINOR: $$minor \e[0m- \e[34mINFO: $$info\e[0m\n"; \
		fi; \
	}

#########
# CLEAN #
#########

clean_all:
	@make --no-print-directory clean_lib
	@make --no-print-directory clean

clean_lib:
	rm -f lib/*/*.o lib/*/*.a

clean:
	rm -f main *.o tests/unit_tests tests/*.gcno tests/*.gcda
