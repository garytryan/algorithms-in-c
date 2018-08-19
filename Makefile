reverse_string: ./src/reverse_string.c
	gcc ./src/reverse_string.c -o ./bin/reverse_string

palindrome: ./src/palindrome.c
	gcc ./src/palindrome.c -o ./bin/palindrome

reverse_int: ./src/reverse_int.c
	gcc ./src/reverse_int.c -o ./bin/reverse_int

max_char: ./src/max_char.c
	gcc ./src/max_char.c -o ./bin/max_char

fizz_buzz: ./src/fizz_buzz.c
	gcc ./src/fizz_buzz.c -o ./bin/fizz_buzz

array_chunk: ./src/array_chunk.c
	gcc ./src/array_chunk.c -o ./bin/array_chunk

are_anagrams: ./src/are_anagrams.c
	gcc ./src/are_anagrams.c -o ./bin/are_anagrams

spiral: ./src/spiral.c
	gcc ./src/spiral.c -o ./bin/sprial

find_rotation_point: ./src/find_rotation_point.c
	gcc ./src/find_rotation_point.c -o ./bin/find_rotation_point

linked_list_find_midpoint: ./src/linked_list_find_midpoint.c
	gcc ./src/linked_list_find_midpoint.c -o ./bin/linked_list_find_midpoint