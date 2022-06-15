format:
	clang-format -i *.cpp *.h

run:  format
	@rm nonogram ||:
	g++ -std=c++11 nonogram.cpp nonogram_run.cpp -o nonogram
	./nonogram

test: format
	rm nonogram_test || true
	g++ -std=c++11 nonogram.cpp nonogram_test.cpp -lgtest -lgtest_main -pthread -o nonogram_test
	./nonogram_test
