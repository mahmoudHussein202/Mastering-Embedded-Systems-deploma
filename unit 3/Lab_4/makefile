# @copyright : Mahmoud Hussein

# 1- tool chain
CC=arm-none-eabi-
# 2- options  
CFLAGS=  -mcpu=cortex-m4 -g -gdwarf-2
# 3-Includes "folders as an example"
INCS= -I.
# 4-Libraries
LIBS=
#wildcard to find any file.c
SRC=$(wildcard *.c)
OBJ= $(SRC:.c=.o)
#wild card to find any file.s
As= $(wildcard *.s)


project_name= TivaC

all: $(project_name).bin
	@echo "                                         "
	@echo "____________Build is done________________"

%.o : %.c
	$(CC)gcc.exe -c  $(INCS)  $(CFLAGS)  $< -o $@


$(project_name).elf: $(OBJ) $(As_obj)
	$(CC)ld.exe -T linker_script.ld $(OBJ)  -o $@ -Map=Map_file.map
clean:

$(project_name).bin : $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@ 
	rm *.elf  *.bin
clean_all :
	rm *.o *.elf *.bin 