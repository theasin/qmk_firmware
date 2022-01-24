# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/SN_SN32F240B/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/SN_SN32F240B

# Enter lower-power sleep mode when on the ChibiOS idle thread (enable this make it doesn't need OPT = 2)
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)