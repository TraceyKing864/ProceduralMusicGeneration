#include <iostream>
#include <cstdlib>
#include "../include/MusicProcessor.h"
int main() {
    MidiFileGenerator midifile;
    midifile.mainGeneratorLoop();
    midifile.outputToFile();

}
