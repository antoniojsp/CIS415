all:
	@gcc -o part1.out part1.c utilities.c
	@gcc -o part2.out part2.c utilities.c
	@gcc -o part3.out part3.c utilities.c
	@gcc -o part4.out part4.c utilities.c screen.c

part1:
	@gcc -o part1 part1.c utilities.c
	@gcc -o iobound iobound.c
	@gcc -o cpubound cpubound.c
	@./part1 input.txt
	@rm part1 iobound cpubound

part1v:
	@gcc -o part1 part1.c utilities.c
	@gcc -o iobound iobound.c
	@gcc -o cpubound cpubound.c
	@valgrind ./part1 input.txt
	@rm part1 iobound cpubound


part2:
	@gcc -o part2 part2.c utilities.c
	@gcc -o iobound iobound.c
	@gcc -o cpubound cpubound.c
	@./part2 input.txt
	@rm part2 iobound cpubound

part2v:
	@gcc -o part2 part2.c utilities.c
	@gcc -o iobound iobound.c
	@gcc -o cpubound cpubound.c
	@valgrind ./part2 input.txt
	@rm part2 iobound cpubound

part3:
	@gcc -o part3 part3.c utilities.c
	@gcc -o hello hello.c
	@gcc -o hola hola.c
	@gcc -o iobound iobound.c
	@gcc -o cpubound cpubound.c
	@./part3 input.txt
	@rm part3 iobound cpubound

part3v:
	@gcc -o part3 part3.c utilities.c
	@gcc -o iobound iobound.c
	@gcc -o cpubound cpubound.c
	@gcc -o hello hello.c
	@gcc -o hola hola.c
	@valgrind ./part3 input.txt
	@rm part3 iobound cpubound

part4:
	@gcc -o part4 part4.c utilities.c screen.c
	@gcc -o hello hello.c
	@gcc -o hola hola.c
	@gcc -o iobound iobound.c
	@gcc -o cpubound cpubound.c
	@./part4 input.txt
	@rm part4 iobound cpubound hello hola

part4v:
	@gcc -o part4 part4.c utilities.c screen.c
	@gcc -o iobound iobound.c
	@gcc -o cpubound cpubound.c
	@gcc -o hello hello.c
	@gcc -o hola hola.c
	@valgrind ./part4 input.txt
	@rm part4 iobound cpubound hello hola
