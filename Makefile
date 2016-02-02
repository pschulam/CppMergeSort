CC = clang++ -std=c++11

main: main.cpp
	$(CC) -o $@ $<

test: main
	python scripts/genwords.py 1000000 0 | tee random.txt | ./$< > sorted.txt

clean:
	rm -f main random.txt sorted.txt

.PHONY: test clean
