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
		@gcc -o pwd pwd.c addons.c
		@./pwd
		@rm pwd
pwdv:
		@gcc -o pwd pwd.c addons.c
		@valgrind ./pwd
		@rm pwd

mkdir:
		@gcc -o mkdir mkdir.c addons.c
		@./mkdir
		@rm mkdir

mkdirv:
		@gcc -o mkdir mkdir.c addons.c
		@valgrind ./mkdir
		@rm mkdir

cd:
		@gcc -o cd cd.c
		@./cd
		@rm cd
cdv:
		@gcc -o cd cd.c
		@valgrind ./cd
		@rm cd

cp:
		@gcc -o cp cp.c addons.c
		@./cp
		@rm cp

cpv:
		@gcc -o cp cp.c addons.c
		@valgrind ./cp
		@rm cp

mv:
		@gcc -o mv mv.c
		@./mv
		@rm mv

mvv:
		@gcc -o mv mv.c
		@valgrind ./mv
		@rm mv

rm:
		@gcc -o rm rm.c addons.c
		@./rm cp
		@rm rm

rmv:
		@gcc -o rm rm.c addons.c
		@valgrind ./rm cp
		@rm rm

cat:
		@gcc -o cat cat.c addons.c
		@./cat hola11.txt
		@rm cat

catv:
		@gcc -o cat cat.c addons.c
		@valgrind ./cat 
		@rm cat
