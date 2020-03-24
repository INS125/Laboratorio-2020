# Para subir nuestro avance al repositorio remoto

(crear archivo main.c o cualquier nombre)
git status
git add . 
git status


git commit -m "nombre del cmmit"
(te va a arrojar error que falta tu nombre de usuario y mail)

git config --global user.email "micorreo@uandresbello.edu"
git config --global user.name "matgreco"

(ahora esta listo para hacer un commit)

git commit -m "nombre del cmmit"
git push origin master

(ahora revisamos nuestro repositorio en github y el commit aparece ahi)

# Para compilar manual
gcc main.c -o main.o
(donde main.c es el nombre del programa fuente que programamos y main.o es el nombre del programa objeto)
(Para ejecutar, llamamos al programa objeto de la siguiente manera)
./main.o
