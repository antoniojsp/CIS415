git:
		git add *
		git commit -m "$(s)"
		git push

main:
	@gcc -o pseudu-shell main.c command.c addons.c
	@./pseudu-shell
	@rm pseudu-shell

mainv:
	@gcc -o pseudu-shell main.c command.c addons.c
	@ valgrind ./pseudu-shell
	@rm pseudu-shell

mainf:
	@gcc -o pseudu-shell main.c command.c addons.c
	@./pseudu-shell -f
	@rm pseudu-shell

mainvf:
	@gcc -o pseudu-shell main.c command.c addons.c
	@ valgrind ./pseudu-shell -f
	@rm pseudu-shell
