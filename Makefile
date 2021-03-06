OUTDIR=./bin

all: $(OUTDIR) $(OUTDIR)/00_minimum $(OUTDIR)/01_function $(OUTDIR)/02_hello_world $(OUTDIR)/03_variable $(OUTDIR)/04_read_file

$(OUTDIR): 
	mkdir $(OUTDIR)

$(OUTDIR)/00_minimum: src/00_minimum/main.c
	gcc -o $(OUTDIR)/00_minimum src/00_minimum/main.c

$(OUTDIR)/01_function: src/01_function/main.c
	gcc -o $(OUTDIR)/01_function src/01_function/main.c

$(OUTDIR)/02_hello_world: src/02_hello_world/main.c
	gcc -o $(OUTDIR)/02_hello_world src/02_hello_world/main.c

$(OUTDIR)/03_variable: src/03_variable
	gcc -o $(OUTDIR)/03_variable src/03_variable/main.c

$(OUTDIR)/04_read_file: src/04_read_file
	gcc -o $(OUTDIR)/04_read_file src/04_read_file/main.c

run:
	$(OUTDIR)/00_minimum;$(OUTDIR)/01_function;$(OUTDIR)/02_hello_world;$(OUTDIR)/03_variable;$(OUTDIR)/04_read_file;
