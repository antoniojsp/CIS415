git:
		git add *
		git commit -m "$(s)"
		git push

main:
	@gcc -o pseudu-shell main.c command.c addons.c
	@./pseudu-shell $(s)
	@rm main

mainv:
	@gcc -o main main.c command.c addons.c
	@ valgrind ./main $(s)
	@rm main
