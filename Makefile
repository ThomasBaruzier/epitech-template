##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## By Thomas Baruzier
##

CC=gcc
CFLAGS= -Wall -Wextra -Werror
#CFLAGS= -Wall -Wextra -Werror -Ofast -march=native -flto

all: get_tasks

####################
# HIGH LEVEL TASKS #
####################

get_tasks: *.c
	@make clean_targets >/dev/null
	@{ [ -s "main.c" ] && make --no-print-directory main; }
	@{ [ -n "$$(find tests/*.c)" ] && make --no-print-directory tests_run; }
	@make clean >/dev/null

get_tasks_debug: *.c
	@make clean_all >/dev/null
	@{ [ -s "main.c" ] && make --no-print-directory debug; }
	@{ [ -n "$$(find tests/*.c)" ] && make --no-print-directory tests_run; }
	@make clean_all >/dev/null

review:
	@make --no-print-directory get_tasks_debug
	@echo -en '\e[A'
	@make --no-print-directory coverage
	@echo -en '\e[A'
	@make --no-print-directory banana

live: *.c
	@echo -e '\n\e[0;1m==> INFO: Live mode activated.\e[0m'
	@{ \
		trap "echo -e '\e[?25h' && exit" 2 3 && echo -e '\e[?25l'; \
		while true; do \
			new=$$(cat $$(find -name '*.c' -o -name '*.h') | md5sum); \
			[ "$$previous" != "$$new" ] && previous="$$new" && \
			echo -en '\e[A' && make --no-print-directory get_tasks; \
			sleep 0.5; \
		done \
	}

live_debug: *.c
	@echo -e '\n\e[0;1m==> INFO: Live mode activated.\e[0m'
	@{ \
		trap "echo -e '\e[?25h' && exit" 2 3 && echo -e '\e[?25l'; \
		while true; do \
			new=$$(cat $$(find -name '*.c' -o -name '*.h') | md5sum); \
			[ "$$previous" != "$$new" ] && previous="$$new" && \
			echo -en '\e[A' && make --no-print-directory get_tasks_debug; \
			sleep 0.5; \
		done \
	}

############
# BUILDING #
############

main: *.c lib/my/libmy.a
	@echo -e '\n\e[34;1m==> TARGET: main\e[0m\n'
	$(CC) $(CFLAGS) *.c -c -I./include/
	$(CC) $(CFLAGS) *.o -o main -L./lib/my/ -lmy
	@echo -e '\n\e[32;1m==> SUCCESS: Built main!\e[0m\n'
	@echo -e '\e[0;1mExecuting ./main...\n\e[33m▼\e[0m'
	@make --no-print-directory exec_params
	@echo -e '\e[s\n\e[u\e[33;1m\e[B▲\e[0m\n'

debug: *.c lib/my/libmy.a
	@echo -e '\n\e[34;1m==> TARGET: debug\e[0m\n'
	$(CC) $(CFLAGS) *.c -c -I./include/
	$(CC) $(CFLAGS) *.o -o main -L./lib/my/ -lmy
	@echo -e '\n\e[32;1m==> SUCCESS: Built main!\e[0m\n'
	@echo -e '\e[0;1mExecuting ./main in debugging mode...\n\e[33m▼\e[0m'
	@make --no-print-directory exec_params_debug
	@echo -e '\e[s\n\e[u\e[33;1m\e[B▲\e[0m\n'

test: tests_run

tests_run: *.c tests/*.c lib/my/libmy.a
	@echo -e '\n\e[34;1m==> TARGET: tests_run\e[0m\n'
	$(CC) $(CFLAGS) $$(ls *.c | grep -v main.c) tests/*.c -o tests/unit_tests \
		-I./include/ -L./lib/my/ -lcriterion -lmy --coverage
	@echo -e '\n\e[32;1m==> SUCCESS: Built tests_run!\e[0m\n'
	@echo -e '\e[0;1mExecuting ./tests/unit_tests...\e[0m\n'
	@./tests/unit_tests
	@echo

#########
# LIBMY #
#########

libmy: lib/my/libmy.a

lib/my/libmy.a: ./lib/my/*.c ./lib/my/build.sh
	@echo -e '\n\e[34;1m==> TARGET: libmy\e[0m\n'
	@cd lib/my && ./build.sh && cd ../..
	@echo -e '\n\e[32;1m==> SUCCESS: Built libmy!\e[0m\n'

########
# EXEC #
########

exec: main
	@./main

exec_params: main
	@./main "This is an arg built into the Makefile" "second" "third"

exec_debug: main
	@./main | cat -e

exec_params_debug: main
	@./main "This is an arg built into the Makefile" "second" "third" | cat -e

#################
# CODE COVERAGE #
#################

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
	@make --no-print-directory clean_targets
	@make --no-print-directory clean

clean_lib:
	rm -f lib/*/*.o lib/*/*.a

clean_targets:
	rm -f main tests/unit_tests

clean:
	rm -f *.o tests/*.gcno tests/*.gcda
