#	Kamil Pawlik 254008

FLAGS = -c -g -Iinc -Wall -pedantic -std=c++11
FINAL = -Wall -pedantic -std=c++11
OBJEC = obj/main.o obj/link.o obj/macierz3D.o obj/surface.o obj/shape.o obj/drone.o obj/scene.o



__start__: ./rysowanie_3D
	./rysowanie_3D

./rysowanie_3D: obj ${OBJEC}
	g++ ${FINAL} -o ./rysowanie_3D ${OBJEC}



obj:
	mkdir -p obj

obj/main.o: src/main.cpp
	g++ ${FLAGS} -o obj/main.o src/main.cpp

obj/link.o: inc/link.hh src/link.cpp
	g++ ${FLAGS} -o obj/link.o src/link.cpp

obj/macierz3D.o: src/macierz3D.cpp inc/macierz3D.hh
	g++ ${FLAGS} -o obj/macierz3D.o src/macierz3D.cpp

obj/surface.o: src/surface.cpp inc/surface.hh
	g++ ${FLAGS} -o obj/surface.o src/surface.cpp

obj/shape.o: src/shape.cpp inc/shape.hh
	g++ ${FLAGS} -o obj/shape.o src/shape.cpp

obj/drone.o: src/drone.cpp inc/drone.hh
	g++ ${FLAGS} -o obj/drone.o src/drone.cpp

obj/scene.o: src/scene.cpp inc/scene.hh
	g++ ${FLAGS} -o obj/scene.o src/scene.cpp


clean:
	rm -f obj/*.o ./rysowanie_3D
