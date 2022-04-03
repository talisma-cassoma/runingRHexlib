# runingRhexlib

HARDWARE DO RHex: 

o RHex usa duas placas PC/104plus são SoCs bastante compactos, robustos e de alta confiabilidade.

Por ter um processador(AMD) bastante robusto ele pode suportar sistemas operacionais. No caso do RHex e do AQUA amphibious eles rodam o Linux(vision stack) numa board e QNX na outra(control stack).

Algumas informaçoes interessantes sobre os microprocessadores AMD,é que as funcoes passar acessar as o as portas I/O no linux sao:  ``inb(), outb(), inw(), outw(), inl(), outl()`` 
.Essas funcoes sao modificadas na ``rhexio.hh`` por questoes de abstracao de hardware

## Specifications 
### System

Form Factor: PC/104
- Processor: Onboard AMD Geode™ LX800 (500 MHz) Processor
- System Memory: 200-pin DDR SODIMM x 1, Max. 512 MB
(Only supports memory chips on upper side, not both sides)
- Chipset: AMD LX800 + CS5536
- I/O Chipset: ITE IT8712F-A
- Ethernet: Realtek RTL 8139DL, 10/100Base-TX
- BIOS: Award 512 KB FLASH ROM
- Watchdog Timer: Generates a time-out system reset
- H/W Status Monitoring:
- Supports power supply voltages and temperature monitoring
- Expansion Interface: PC/104 socket x 1
- Power Requirement: +5V/AT
- Power Consumption (Typical):
- AMD Geode™ LX800 500 MHz, DDR400 512 MB = 1.53A @ +5V
- Battery: Lithium battery
- Board Size: 3.55” (L) x 3.775” (W) (90mm x 96mm)
- Gross Weight: 0.25 lb (0.11 kg)
- Operating Temperature: 32oF ~ 140oF (0oC ~ 60oC)
- Storage Temperature: -40oF ~ 176oF (-40oC ~ 80oC)
- Operating Humidity: 0% ~ 90% relative humidity, non-condensing
- MTBF (Hours): 100,000

### I/O

- Storage:
- EIDE x 1 (UDMA 33 for one device),
- Type 1 CompactFlash™ x 1,
- Floppy Disk Drive x 1
- Serial Port: RS-232 x 1, RS-232/422/485 x 1
- Parallel Port: SPP/ EPP/ ECP mode
- USB: USB2.0 x 4
- PS/2 Port: Keyboard + Mouse x 1
- IrDA: One IrDA Tx/Rx header

- Display: Supports CRT/ LCD simultaneous display

- Chipset: AMD LX800
- Memory: Shared system memory up to 254 MB
- Resolutions:
- Up to 1600 x 1200 @ 32bpp for CRT
- Up to 1024 x 768 @ 24bpp for LCD
- LCD Interface: 18/24-bit TTL TFT LCD


