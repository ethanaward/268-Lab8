Lab8: main.o ValueNotFoundException.o
	-g++ -g -std=c++11 -Wall -o Lab8 main.o ValueNotFoundException.o

main.o: main.cpp BinarySearchTree.h Node.h
	-g++ -g -std=c++11 -Wall -c main.cpp BinarySearchTree.h Node.h

ValueNotFoundException.o:
	-g++ -g -std=c++11 -Wall -c ValueNotFoundException.h ValueNotFoundException.cpp

clean:
	rm *.o Lab8
	echo clean done

