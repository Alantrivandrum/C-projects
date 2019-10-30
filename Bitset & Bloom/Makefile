TEST_BITSET_CREATE_CASES=1 2
TEST_BITSET_UNION_CASES=1 2
TEST_BITSET_INTERSECT_CASES=1 2
TEST_BITSET_REMOVE_CASES=1 2
TEST_BLOOM_CASES=1 2 3 4
pass=PASSED
fail=FAILED

all: file_check build-prep filter run_all_bitset_create run_all_bitset_union run_all_bitset_intersect run_all_bitset_remove run_all_bloom

filter: test_files/main.c bitset.c bitset.h bloom.c bloom.h
	echo "Compiling stack tests"
	echo "gcc -Wall -Og -g -o filter test_files/main.c bitset.c bloom.c -I."
	gcc -Wall -Og -g -o filter test_files/main.c bitset.c bloom.c -I. \
	&& a="PASSED" || a="FAILED";\
	echo "Compilation "$$a;\
	bash -c "if [[ $$a == PASSED ]]; then echo Test 1.0 4 >> results.txt; else echo Test 1.0 0 >> results.txt; fi"

run_all_bitset_create : $(foreach test,$(TEST_BITSET_CREATE_CASES),run_test_bitset_create_$(test))

run_all_bitset_union : $(foreach test,$(TEST_BITSET_UNION_CASES),run_test_bitset_union_$(test))

run_all_bitset_intersect : $(foreach test,$(TEST_BITSET_INTERSECT_CASES),run_test_bitset_intersect_$(test))

run_all_bitset_remove : $(foreach test,$(TEST_BITSET_REMOVE_CASES),run_test_bitset_remove_$(test))

run_all_bloom : $(foreach test,$(TEST_BLOOM_CASES),run_test_bloom_$(test))

run_test_bitset_create_%:
	echo
	echo -n "Run bitset create test $* "
	./filter bitset_create test_files/test_inputs/test_bitset_create_$*.txt | tail -n 1 > test_files/build/test_bitset_create_output_$*.txt \
  && a="PASSED" || a="FAILED"; \
  bash -c "if diff -eq test_files/test_outputs/test_bitset_create_$*.txt test_files/build/test_bitset_create_output_$*.txt; \
  then if [[ $$a == PASSED ]]; then echo PASSED; echo Test 2.$* 1 >> results.txt; else echo PARTIAL; echo Test 2.$* 0.5 >> results.txt; fi; \
  else echo FAILED; echo Test 2.$* 0 >> results.txt; fi"

run_test_bitset_union_%:
	echo
	echo -n "Run bitset union test $* "
	./filter bitset_union test_files/test_inputs/test_bitset_union_$*.txt | tail -n 1 > test_files/build/test_bitset_union_output_$*.txt \
  && a="PASSED" || a="FAILED"; \
  bash -c "if diff -eq test_files/test_outputs/test_bitset_union_$*.txt test_files/build/test_bitset_union_output_$*.txt; \
  then if [[ $$a == PASSED ]]; then echo PASSED; echo Test 3.$* 1 >> results.txt; else echo PARTIAL; echo Test 3.$* 0.5 >> results.txt; fi; \
  else echo FAILED; echo Test 3.$* 0 >> results.txt; fi"

run_test_bitset_intersect_%:
	echo
	echo -n "Run bitset intersect test $* "
	./filter bitset_intersect test_files/test_inputs/test_bitset_intersect_$*.txt | tail -n 1 > test_files/build/test_bitset_intersect_output_$*.txt \
  && a="PASSED" || a="FAILED"; \
  bash -c "if diff -eq test_files/test_outputs/test_bitset_intersect_$*.txt test_files/build/test_bitset_intersect_output_$*.txt; \
  then if [[ $$a == PASSED ]]; then echo PASSED; echo Test 4.$* 1 >> results.txt; else echo PARTIAL; echo Test 4.$* 0.5 >> results.txt; fi; \
  else echo FAILED; echo Test 4.$* 0 >> results.txt; fi"

run_test_bitset_remove_%:
	echo
	echo -n "Run bitset remove test $* "
	./filter bitset_remove test_files/test_inputs/test_bitset_remove_$*.txt | tail -n 1 > test_files/build/test_bitset_remove_output_$*.txt \
  && a="PASSED" || a="FAILED"; \
  bash -c "if diff -eq test_files/test_outputs/test_bitset_remove_$*.txt test_files/build/test_bitset_remove_output_$*.txt; \
  then if [[ $$a == PASSED ]]; then echo PASSED; echo Test 5.$* 1 >> results.txt; else echo PARTIAL; echo Test 5.$* 0.5 >> results.txt; fi; \
  else echo FAILED; echo Test 5.$* 0 >> results.txt; fi"

run_test_bloom_%:
	echo
	echo -n "Run bitset bloom test $* "
	./filter bloom test_files/test_inputs/test_bloom_$*.txt | tail -n 1 > test_files/build/test_bloom_output_$*.txt \
  && a="PASSED" || a="FAILED"; \
  bash -c "if diff -eq test_files/test_outputs/test_bloom_$*.txt test_files/build/test_bloom_output_$*.txt; \
  then if [[ $$a == PASSED ]]; then echo PASSED; echo Test 6.$* 2 >> results.txt; else echo PARTIAL; echo Test 6.$* 1 >> results.txt; fi; \
  else echo FAILED; echo Test 6.$* 0 >> results.txt; fi"

file_check:
	echo "Filecheck bitset.c "
	test -s bitset.c
	echo "Filecheck bitset.h "
	test -s bitset.h
	echo "Filecheck bloom.c "
	test -s bloom.c
	echo "Filecheck bloom.h "
	test -s bloom.h
	echo "Filecheck test_files/main.c "
	test -s test_files/main.c

build-prep: clean
	mkdir -p test_files/build
	touch results.txt

clean:
	rm -rf test_files/build
	rm -rf results.txt
	rm -rf filter

submission_archive:
	tar -cvf lab6_submission.tar *.h *.c

.SILENT: 
