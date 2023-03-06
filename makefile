exe=string_reverse
cc=g++
config=-Wall -g -o

string_reverse:string_reverse.o
	$(cc) $(config) $@ $^

.PHONY:clean
clean:
	@echo "---clean---"
	-@rm -rf $(exe) *.o *.out
