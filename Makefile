format:
	clang-format -i *.cpp *.h

run:  format
	@rm nonogram ||:
	g++ -std=c++11 nonogram.cpp nonogram_run.cpp -g -o nonogram
	./nonogram $(IN_FILE)

regex: format
	@rm regex ||:
	g++ -std=c++11 regex.cpp -o regex
	./regex