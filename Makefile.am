AUTOMAKE_OPTIONS = foreign
SUBDIRS = lib

bin_PROGRAMS = matrix
matrix_SOURCES = src/main.c
matrix_CFLAGS = -I$(srcdir)/lib
matrix_LDADD = lib/vector/libvector.a lib/matrix/libmatrix.a -lm