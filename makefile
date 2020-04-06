all:
	clang++ -std=c++11 A2main.cpp Simulation.cpp Event.cpp EPartArrival.cpp EEndAssembly.cpp ListItem.cpp Node.cpp OrderedItem.cpp Parts.cpp EProductArrival.cpp PartiallyProduct.cpp Priority.cpp Queue.cpp EStartAssembly.cpp -o A2main
test:
	clang++ -std=c++11 UTest.cpp Simulation.cpp Event.cpp EPartArrival.cpp EEndAssembly.cpp ListItem.cpp Node.cpp OrderedItem.cpp Parts.cpp EProductArrival.cpp PartiallyProduct.cpp Priority.cpp Queue.cpp EStartAssembly.cpp -o TEST