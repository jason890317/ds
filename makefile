exe=string_reverse string_reverse_2
cc=g++
config=-Wall -g -o

string_reverse_2:string_reverse_2.o
	$(cc) $(config) $@ $^


string_reverse:string_reverse.o
	$(cc) $(config) $@ $^

.PHONY:clean
clean:
	@echo "---clean---"
	-@rm -rf $(exe) *.o *.out
