
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
