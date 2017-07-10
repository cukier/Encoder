CC = ccsc
PK2 = pk2cmd

DEVICE = PIC18F25K22
UNIT1 = Blink
UNIT1_FILE = main
SRC = src
OUT = Debug

#OBJ += *.pjt *.STA *.sym *.tre *.MCP *.PWI *.DBK
OBJ += *.err *.esym *.xsym *.cof *.hex *.lst *.ccspjt
MOBJ = $(OBJ:%=$(SRC)/%)

ifeq ($(DEVICE), PIC18F25K22)
CFLAGS += +FH
endif
ifeq ($(DEVICE), PIC18F252)
CFLAGS += +FH
endif
ifeq ($(DEVICE), PIC16F628A)
CFLAGS += +FM
endif
CFLAGS += +LN -T -A -M -Z +DF +Y=9 +STDOUT +EA
DFLAGS += +GMODUBS_USE_SL1=""
DFLAGS += +GENCODER_USE_SL2=""

PK2FLAGS =-E -P$(DEVICE) -M -R -J -F

all: $(UNIT1).hex

$(UNIT1).hex: $(SRC)/$(UNIT1_FILE).c
	$(CC) $(CFLAGS) $(DFLAGS) $<
	[[ -d $(OUT) ]] || mkdir $(OUT)
	mv $(MOBJ) $(OUT)
	
burn: $(OUT)/$(UNIT1_FILE).hex
	$(PK2) $(PK2FLAGS) $^
	
clean:
	rm $(OUT)/*
	