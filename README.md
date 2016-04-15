## Super Simple Function Generator

#### Waveform Generator IC

First off, I want to use a waveform generator IC. It seems like oscillators, audio waveform generators, and pulse generators are all limited kinds of waveform generator ICs. They all seem to cost less than the $10 chip I ended up with.

As far as full waveform generators go, the ICL8038 had an output frequency of up to 300kHz, and the derived MAX038 had an output frequency of up to 20MHz. Both chips are out of stock and no longer manufactured, so they're not an option for this project. 

I'm going to explore PLLs later on but for now I just want a chip that Just Works because the important thing is to generate my own signals. I could use the AD9833 or AD5930, both of which use direct digital synthesis (DDS) that converts a digital signal into an analog waveform.  

It's a tossup between AD9833 and AD5930. They both have 10 bit resolution and run on the same input range between 2.3V to 5.5V. 

AD9833 depends on 25MHz clock and is immediately available in quantity 1 for $9.27 at Digikey. 

AD5930 depends on a 50MHz clock and is not immediately available, and in any case it costs $13.40. And lo, another engineering decision decides itself. 

#### Using the AD9833 

It will produce sine, triangular, and square waves. No external components needed, except that it needs a microcontroller. The analog and digital grounds will need to be separated. It can create sine waves up to 12.5MHz. 

I don't understand how to build the chip itself, so I'm just going to put this on a breakout board and use it. 
