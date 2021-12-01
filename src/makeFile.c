CFLAGS=-g -03

  all: tokenizer

  tokenizer: cc-o tokenizer tokenizer.h history.h

  tokenizer: tokenizer.o

  clean:

  rm -f *.o tokenizer
  run:
  tokenizer
  ./tokenizer
  
