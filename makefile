bin/carBase: addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o mainA3.o
	gcc -Wall -std=c99 bin/addNewCar.o bin/loadCarData.o bin/printAll.o bin/printOne.o bin/lookForCarId.o bin/lookForCarModelType.o bin/countCars.o bin/sortCarId.o bin/oneLessCar.o bin/noMoreCars.o bin/mainA3.o -o bin/carBase

addNewCar.o: src/addNewCar.c include/headerA3.h
	gcc -Wall -std=c99 -c src/addNewCar.c -o bin/addNewCar.o

loadCarData.o: src/loadCarData.c include/headerA3.h
	gcc -Wall -std=c99 -c src/loadCarData.c -o bin/loadCarData.o

printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printAll.c -o bin/printAll.o

printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printOne.c -o bin/printOne.o

lookForCarId.o: src/lookForCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookForCarId.c -o bin/lookForCarId.o

lookForCarModelType.o: src/lookForCarModelType.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookForCarModelType.c -o bin/lookForCarModelType.o

countCars.o: src/countCars.c include/headerA3.h
	gcc -Wall -std=c99 -c src/countCars.c -o bin/countCars.o

sortCarId.o: src/sortCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/sortCarId.c -o bin/sortCarId.o

oneLessCar.o: src/oneLessCar.c include/headerA3.h
	gcc -Wall -std=c99 -c src/oneLessCar.c -o bin/oneLessCar.o

noMoreCars.o: src/noMoreCars.c include/headerA3.h
	gcc -Wall -std=c99 -c src/noMoreCars.c -o bin/noMoreCars.o

mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/mainA3.c -o bin/mainA3.o
clean:
	rm bin/*