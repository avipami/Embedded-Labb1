
PORT = /dev/tty.usbmodem1401
BAUD = 115200
FILENAME = main
FILENAME2 = serial
DEVICE = atmega328p
PROGRAMMER = arduino
COMPILE = avr-gcc -Wall -Os -mmcu=${DEVICE}

default: compile upload clean


compile:
	${COMPILE} -c ${FILENAME}.c -o ${FILENAME}.o
	${COMPILE} -c ${FILENAME2}.c -o ${FILENAME2}.o
	${COMPILE} -o ${FILENAME}.elf ${FILENAME}.o ${FILENAME2}.o
	avr-objcopy -j .text -j .data -O ihex ${FILENAME}.elf ${FILENAME}.hex
	avr-size --format=avr --mcu =${DEVICE} ${FILENAME}.elf

upload:
	avrdude -v -p ${DEVICE} -c ${PROGRAMMER} -P ${PORT} -b ${BAUD} -U flash:w:${FILENAME}.hex:i
clean:
	rm ${FILENAME}.o
	rm ${FILENAME}.elf
	rm ${FILENAME}.hex
