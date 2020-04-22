git:
		git add *
		git commit -m "$(s)"
		git push

main:
	@gcc -o pseudu-shell main.c command.c addons.c
	@./pseudu-shell $(s)
	@rm pseudu-shell

mainv:
	@gcc -o pseudu-shell main.c command.c addons.c
	@ valgrind ./pseudu-shell $(s)
	@rm pseudu-shell
