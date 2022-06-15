format:
	clang-format -i *.cpp *.h

run-sudoku:  format
	@rm sudoku ||:
	g++ -std=c++11 sudoku.cpp sudoku_run.cpp -o sudoku
	./sudoku

test: format
	rm sudoku_test || true
	g++ -std=c++11 sudoku.cpp sudoku_test.cpp -lgtest -lgtest_main -pthread -o sudoku_test
	./sudoku_test
