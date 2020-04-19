git:
		git add *
		git commit -m "$(s)"
		git push

ls:
		@gcc -o ls ls.c addons.c
		@./ls
		@rm ls

lsv:
		@gcc -o ls ls.c addons.c
		@valgrind ./ls
		@rm ls

pwd:
		@gcc -o pwd pwd.c
		@./pwd
		@rm pwd

mkdir:
		@gcc -o mkdir mkdir.c addons.c
		@./mkdir $(s)
		@rm mkdir

cd:
		@gcc -o cd cd.c
		@./cd $(s)
		@rm cd

cp:
		@gcc -o cp cp.c
		@./cp $(s) inp24.txt ./salida.txt
		@rm cp
