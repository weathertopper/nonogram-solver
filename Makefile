format:
	clang-format -i *.cpp *.h

run:  format
	@rm nonogram ||:
	g++ -std=c++11 nonogram.cpp nonogram_run.cpp -o nonogram
	./nonogram $(IN_FILE) $(OUT_FILE)

test: format
	rm nonogram_test || true
	g++ -std=c++11 nonogram.cpp nonogram_test.cpp -lgtest -lgtest_main -pthread -o nonogram_test
	./nonogram_test

regex: format
	@rm regex ||:
	g++ -std=c++11 regex.cpp -o regex
	./regex