# This is tests/Makefile.am.
# MPI_16a_PI computes the value of PI and uses distributed processing
# to do it. This test it is not always executed. 
AUTOMAKE_OPTIONS = gnits

# check_PROGRAMS = MPI_16a_PI 

check_PROGRAMS = \
sysdata \
benchmark \
Test_threads_a \
Test_threads_b

#MPI_16a_PI_SOURCES = MPI_16a_PI.c 
#MPI_16a_PI_LDADD = @MPILIBS@ @LIBS@

benchmark_SOURCES = \
benchmark.c \
try_aix.c \
try_bsd.c \
try_hpux.c \
try_irix.c \
try_linux.c \
try_portable.c \
try_solaris.c \
try_tru64.c \
try_unicos.c \
defs.h

sysdata_SOURCES = \
sysdata.c \
try_aix.c \
try_bsd.c \
try_hpux.c \
try_irix.c \
try_linux.c \
try_portable.c \
try_solaris.c \
try_tru64.c \
try_unicos.c \
defs.h

Test_threads_a_SOURCES = Test_threads_a.c
Test_threads_a_CPPFLAGS = @PTHREAD_CFLAGS@
#Test_threads_a_LDADD = @PTHREAD_LIBS@ @LIBS@ @GSL_LIBS@ @MPILIBS@ 
#Test_threads_a_LDADD = @PTHREAD_LIBS@ @LIBS@ @GSL_LIBS@ 
Test_threads_a_LDADD = @PTHREAD_LIBS@ @LIBS@ 

Test_threads_b_SOURCES = Test_threads_b.c
Test_threads_b_CPPFLAGS = @PTHREAD_CFLAGS@
#Test_threads_b_LDADD = @PTHREAD_LIBS@ @LIBS@ @GSL_LIBS@ @MPILIBS@ 
#Test_threads_b_LDADD = @PTHREAD_LIBS@ @LIBS@ @GSL_LIBS@ 
Test_threads_b_LDADD = @PTHREAD_LIBS@ @LIBS@ 

TESTS_ENVIRONMENT = \
top_builddir=$(top_builddir) \
top_srcdir=$(top_srcdir) \
built_with_posix_threads=$(built_with_posix_threads) \
no_gsl=$(no_gsl) 


TESTS =  \
Test_threads_a \
Test_threads_b \
find-zero-length.test \
1a-create_bmp_for_symmetrical_stripline.bmp.test \
1b-create_bmp_for_symmetrical_stripline.txt.test \
1c-create_bmp_for_symmetrical_stripline.E.bmp.test \
1d-create_bmp_for_symmetrical_stripline.Er.bmp.test \
1e-create_bmp_for_symmetrical_stripline.Ey.bmp.test \
1f-create_bmp_for_symmetrical_stripline.Ex.bmp.test \
1g-create_bmp_for_symmetrical_stripline.U.bmp.test \
1h-create_bmp_for_symmetrical_stripline.V.bmp.test \
1i-create_bmp_for_symmetrical_stripline.E.bin.test \
1j-create_bmp_for_symmetrical_stripline.Er.bin.test \
1k-create_bmp_for_symmetrical_stripline.Ey.bin.test \
1l-create_bmp_for_symmetrical_stripline.Ex.bin.test \
1m-create_bmp_for_symmetrical_stripline.U.bin.test \
1n-create_bmp_for_symmetrical_stripline.V.bin.test \
2a-create_bmp_for_rect_in_rect.bmp.test \
3a-create_bmp_for_rect_cen_in_rect.bmp.test \
3b-create_bmp_for_rect_cen_in_rect.txt.test \
4a-create_bmp_for_microstrip_coupler.test \
5a-check-s_and_-S_options_of_atlc-2conductor.test \
5b-check-s_and_-S_options_of_atlc-3conductor.test \
5c-check_numeric_data_from_atlc-2conductor.test \
6a-create_and_check_25ohm_201Pixel_high_symmetrical_stripline.test \
6b-create_25ohm_401Pixel_high_symmetrical_stripline.test \
6c-create_25ohm_801Pixel_high_symmetrical_stripline.test \
6d-create_and_check_50ohm_201Pixel_high_symmetrical_stripline.test \
6e-create_50ohm_401Pixel_high_symmetrical_stripline.test \
6f-create_50ohm_801Pixel_high_symmetrical_stripline.test \
6g-create_100ohm_201Pixel_high_symmetrical_stripline.test \
6h-create_100ohm_401Pixel_high_symmetrical_stripline.test \
6i-create_100ohm_801Pixel_high_symmetrical_stripline.test \
6j-create_200ohm_201Pixel_high_symmetrical_stripline.test \
6k-create_200ohm_401Pixel_high_symmetrical_stripline.test \
6l-create_200ohm_801Pixel_high_symmetrical_stripline.test \
7a-create_bmp_for_stripline_coupler.bmp.test \
7b-create_bmp_for_stripline_coupler.txt.test \
7c-create_bmp_for_stripline_coupler.Ex.odd.bmp.test \
7d-create_bmp_for_stripline_coupler.Ey.odd.bmp.test \
7e-create_bmp_for_stripline_coupler.E.odd.bmp.test \
7f-create_bmp_for_stripline_coupler.V.odd.bmp.test \
7g-create_bmp_for_stripline_coupler.U.odd.bmp.test \
7h-create_bmp_for_stripline_coupler.Er.bmp.test \
7i-create_bmp_for_stripline_coupler.U.even.bmp.test \
7j-create_bmp_for_stripline_coupler.Ex.even.bmp.test \
7k-create_bmp_for_stripline_coupler.Ey.even.bmp.test \
7l-create_bmp_for_stripline_coupler.E.even.bmp.test \
7m-create_bmp_for_stripline_coupler.V.even.bmp.test \
7n-create_bmp_for_stripline_coupler.bmp.pre-atlc.txt.test \
8a-design_coupler.bmp.test \
9a-create-25-Ohm-201b.bmp.test \
9b-create-25-Ohm-401b.bmp.test \
9c-create-50-Ohm-201b.bmp.test \
9d-create-50-Ohm-401b.bmp.test \
9e-create-100-Ohm-201b.bmp.test \
9f-create-100-Ohm-401b.bmp.test \
9g-create-200-Ohm-201b.bmp.test \
9h-create-200-Ohm-401b.bmp.test \
9i-create-200-Ohm-801b.bmp.test \
10a-create-lots-of-examples-check-last-one.test \
10b-create-lots-of-examples-check-last-one.test \
11a-verify-checksum-of-supplied-test-coupler1.bmp.test \
11b-verify-checksum-of-created-test-coupler1.Ex.odd.bmp.test \
11c-verify-checksum-of-created-test-coupler1.Ey.odd.bmp.test \
11d-verify-checksum-of-created-test-coupler1.E.odd.bmp.test \
11e-verify-checksum-of-created-test-coupler1.V.odd.bmp.test \
11f-verify-checksum-of-created-test-coupler1.U.odd.bmp.test \
11g-verify-checksum-of-created-test-coupler1.Er.bmp.test \
11h-verify-checksum-of-created-test-coupler1.Ex.even.bmp.test \
11i-verify-checksum-of-created-test-coupler1.Ey.even.bmp.test \
11j-verify-checksum-of-created-test-coupler1.E.even.bmp.test \
11k-verify-checksum-of-created-test-coupler1.U.even.bmp.test \
11l-verify-checksum-of-created-test-coupler1.V.even.bmp.test \
13a-check_rect_cen_in_rect.test \
13b-check_rect_cen_in_rect.test \
13c-check_rect_cen_in_rect.test \
13d-check_rect_cen_in_rect.test \
14a-check-circ-in-rect.test \
14b-check-circ-in-rect.test \
14c-check-circ-in-rect.test \
14d-check-circ-in-rect.test  \
WARNING-The-next-test-is-a-benchmark-and-takes-a-long-while.test \
benchmark.test 

#MPI_16a_PI 

EXTRA_DIST = \
benchmark.test \
Test_threads_a.c \
Test_threads_b.c \
find-zero-length.test \
MPI_16a_PI.c      \
10a-create-lots-of-examples-check-last-one.test \
10b-create-lots-of-examples-check-last-one.test \
11a-verify-checksum-of-supplied-test-coupler1.bmp.test \
11b-verify-checksum-of-created-test-coupler1.Ex.odd.bmp.test \
11c-verify-checksum-of-created-test-coupler1.Ey.odd.bmp.test \
11d-verify-checksum-of-created-test-coupler1.E.odd.bmp.test \
11e-verify-checksum-of-created-test-coupler1.V.odd.bmp.test \
11f-verify-checksum-of-created-test-coupler1.U.odd.bmp.test \
11g-verify-checksum-of-created-test-coupler1.Er.bmp.test \
11h-verify-checksum-of-created-test-coupler1.Ex.even.bmp.test \
11i-verify-checksum-of-created-test-coupler1.Ey.even.bmp.test \
11j-verify-checksum-of-created-test-coupler1.E.even.bmp.test \
11k-verify-checksum-of-created-test-coupler1.U.even.bmp.test \
11l-verify-checksum-of-created-test-coupler1.V.even.bmp.test \
13a-check_rect_cen_in_rect.test \
13b-check_rect_cen_in_rect.test \
13c-check_rect_cen_in_rect.test \
13d-check_rect_cen_in_rect.test \
14a-check-circ-in-rect.test \
14b-check-circ-in-rect.test \
14c-check-circ-in-rect.test \
14d-check-circ-in-rect.test \
WARNING-The-next-test-is-a-benchmark-and-takes-a-long-while.test \
1a-create_bmp_for_symmetrical_stripline.bmp.test \
1b-create_bmp_for_symmetrical_stripline.txt.test \
1c-create_bmp_for_symmetrical_stripline.E.bmp.test \
1d-create_bmp_for_symmetrical_stripline.Er.bmp.test \
1e-create_bmp_for_symmetrical_stripline.Ey.bmp.test \
1f-create_bmp_for_symmetrical_stripline.Ex.bmp.test \
1g-create_bmp_for_symmetrical_stripline.U.bmp.test \
1h-create_bmp_for_symmetrical_stripline.V.bmp.test \
1i-create_bmp_for_symmetrical_stripline.E.bin.test \
1j-create_bmp_for_symmetrical_stripline.Er.bin.test \
1k-create_bmp_for_symmetrical_stripline.Ey.bin.test \
1l-create_bmp_for_symmetrical_stripline.Ex.bin.test \
1m-create_bmp_for_symmetrical_stripline.U.bin.test \
1n-create_bmp_for_symmetrical_stripline.V.bin.test \
2a-create_bmp_for_rect_in_rect.bmp.test \
2b-create_bmp_for_rect_in_rect.txt.test \
2c-create_bmp_for_rect_in_rect.E.bmp.test \
2d-create_bmp_for_rect_in_rect.Er.bmp.test \
2e-create_bmp_for_rect_in_rect.Ey.bmp.test \
2f-create_bmp_for_rect_in_rect.Ex.bmp.test \
2g-create_bmp_for_rect_in_rect.U.bmp.test \
2h-create_bmp_for_rect_in_rect.V.bmp.test \
3a-create_bmp_for_rect_cen_in_rect.bmp.test \
3b-create_bmp_for_rect_cen_in_rect.txt.test \
4a-create_bmp_for_microstrip_coupler.test \
5a-check-s_and_-S_options_of_atlc-2conductor.test \
5b-check-s_and_-S_options_of_atlc-3conductor.test \
5c-check_numeric_data_from_atlc-2conductor.test \
6a-create_and_check_25ohm_201Pixel_high_symmetrical_stripline.test \
6b-create_25ohm_401Pixel_high_symmetrical_stripline.test \
6c-create_25ohm_801Pixel_high_symmetrical_stripline.test \
6d-create_and_check_50ohm_201Pixel_high_symmetrical_stripline.test \
6e-create_50ohm_401Pixel_high_symmetrical_stripline.test \
6f-create_50ohm_801Pixel_high_symmetrical_stripline.test \
6g-create_100ohm_201Pixel_high_symmetrical_stripline.test \
6h-create_100ohm_401Pixel_high_symmetrical_stripline.test \
6i-create_100ohm_801Pixel_high_symmetrical_stripline.test \
6j-create_200ohm_201Pixel_high_symmetrical_stripline.test \
6k-create_200ohm_401Pixel_high_symmetrical_stripline.test \
6l-create_200ohm_801Pixel_high_symmetrical_stripline.test \
6m-create_400ohm_1551Pixel_high_symmetrical_stripline.test \
7a-create_bmp_for_stripline_coupler.bmp.test \
7b-create_bmp_for_stripline_coupler.txt.test \
7c-create_bmp_for_stripline_coupler.Ex.odd.bmp.test \
7d-create_bmp_for_stripline_coupler.Ey.odd.bmp.test \
7e-create_bmp_for_stripline_coupler.E.odd.bmp.test \
7f-create_bmp_for_stripline_coupler.V.odd.bmp.test \
7g-create_bmp_for_stripline_coupler.U.odd.bmp.test \
7h-create_bmp_for_stripline_coupler.Er.bmp.test \
7i-create_bmp_for_stripline_coupler.U.even.bmp.test \
7j-create_bmp_for_stripline_coupler.Ex.even.bmp.test \
7k-create_bmp_for_stripline_coupler.Ey.even.bmp.test \
7l-create_bmp_for_stripline_coupler.E.even.bmp.test \
7m-create_bmp_for_stripline_coupler.V.even.bmp.test \
7n-create_bmp_for_stripline_coupler.bmp.pre-atlc.txt.test \
8a-design_coupler.bmp.test \
9a-create-25-Ohm-201b.bmp.test \
9b-create-25-Ohm-401b.bmp.test \
9c-create-50-Ohm-201b.bmp.test \
9d-create-50-Ohm-401b.bmp.test \
9e-create-100-Ohm-201b.bmp.test \
9f-create-100-Ohm-401b.bmp.test \
9g-create-200-Ohm-201b.bmp.test \
9h-create-200-Ohm-401b.bmp.test \
9i-create-200-Ohm-801b.bmp.test 

CLEANFILES = \
test.E.bin \
test.E.bmp \
test.Er.bin \
test.Er.bmp \
test.Ex.bin \
test.Ex.bmp \
test.Ey.bin \
test.Ey.bmp \
test.U.bin \
test.U.bmp \
test.V.bin \
test.V.bmp \
test.bmp \
test.bmp.txt \
test2.txt \
test_rect_in_rect.E.bin \
test_rect_in_rect.E.bmp \
test_rect_in_rect.Er.bin \
test_rect_in_rect.Er.bmp \
test_rect_in_rect.Ex.bin \
test_rect_in_rect.Ex.bmp \
test_rect_in_rect.Ey.bin \
test_rect_in_rect.Ey.bmp \
test_rect_in_rect.U.bin \
test_rect_in_rect.U.bmp \
test_rect_in_rect.V.bin \
test_rect_in_rect.V.bmp \
test_rect_in_rect.bmp \
test_rect_in_rect.txt \
test_stripline_coupler.E.even.bin \
test_stripline_coupler.E.even.bmp \
test_stripline_coupler.E.odd.bin \
test_stripline_coupler.E.odd.bmp \
test_stripline_coupler.Er.bin \
test_stripline_coupler.Er.bmp \
test_stripline_coupler.Ex.even.bin \
test_stripline_coupler.Ex.even.bmp \
test_stripline_coupler.Ex.odd.bin \
test_stripline_coupler.Ex.odd.bmp \
test_stripline_coupler.Ey.even.bin \
test_stripline_coupler.Ey.even.bmp \
test_stripline_coupler.Ey.odd.bin \
test_stripline_coupler.Ey.odd.bmp \
test_stripline_coupler.U.even.bin \
test_stripline_coupler.U.even.bmp \
test_stripline_coupler.U.odd.bin \
test_stripline_coupler.U.odd.bmp \
test_stripline_coupler.V.even.bin \
test_stripline_coupler.V.even.bmp \
test_stripline_coupler.V.odd.bin \
test_stripline_coupler.V.odd.bmp \
test_stripline_coupler.bmp \
test_stripline_coupler.bmp.pre-atlc.txt \
test_stripline_coupler.bmp.txt \
test_stripline_coupler.txt \
test_sym_strip.E.bin \
test_sym_strip.E.bmp \
test_sym_strip.Er.bin \
test_sym_strip.Er.bmp \
test_sym_strip.Ex.bin \
test_sym_strip.Ex.bmp \
test_sym_strip.Ey.bin \
test_sym_strip.Ey.bmp \
test_sym_strip.U.bin \
test_sym_strip.U.bmp \
test_sym_strip.V.bin \
test_sym_strip.V.bmp \
test_sym_strip.bmp \
test_sym_strip.txt \
test-coupler2.bmp.txt \
microstrip_coupler.bmp \
undefined_permittivities.bmp 

DISTCLEANFILES = tests.log test.txt benchmark.foo.html tests.html benchmark.foo.dat
