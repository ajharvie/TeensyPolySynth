void loop() {
  
  if (debugTimer > 1000){
    debugTimer = 0;
    
    //Serial.println(rms1.read());
  }
  
  if (shout == 1){
    startPlaying();
  }
  else{
    stopPlaying();
  }

  MIDI.read();//read pitch bend
  MIDI.read();//why not two? as a treat

  if (voices < 0) {
    voices = 0;
  }
  

  //cross mod
  modMix1.gain(0, crossMod);
  modMix2.gain(0, crossMod);
  modMix3.gain(0, crossMod);
  modMix4.gain(0, crossMod);
  modMix5.gain(0, crossMod);
  modMix6.gain(0, crossMod);

  pitchFactorFiltered = 0.05*pitchFactor + 0.95*pitchFactorFiltered; //low pass the pitch bend input to make it smoother
  tuneBFiltered = 0.05*tuneB + 0.95*tuneBFiltered;
  tuneCFiltered = 0.05*tuneC + 0.95*tuneCFiltered;


  a1Freq = noteFreqs[note1freq] * octave * pitchFactorFiltered;
  b1Freq = noteFreqs[note1freq] * octave * octaveB * tuneBFiltered * pitchFactorFiltered;
  c1Freq = noteFreqs[note1freq] * octave * octaveC * tuneCFiltered * pitchFactorFiltered;
  sub1Freq = (noteFreqs[note1freq] / 2) * octave * pitchFactorFiltered;
  
  
  //exponential filtering for glide
  if (sinceLastFilter >= filterTime){
    sinceLastFilter = 0; //reset elapsedMicros
    if (polyMode == 0){
      a1FreqFiltered = glideVal*a1Freq + (1 - glideVal)*oldA1Freq;
      b1FreqFiltered = glideVal*b1Freq + (1 - glideVal)*oldB1Freq; 
      c1FreqFiltered = glideVal*c1Freq + (1 - glideVal)*oldC1Freq; 
      sub1FreqFiltered = glideVal*sub1Freq + (1 - glideVal)*oldSub1Freq;

      oldA1Freq = a1FreqFiltered;
      oldB1Freq = b1FreqFiltered;
      oldC1Freq = c1FreqFiltered;
      oldSub1Freq = sub1FreqFiltered;      
    }
  }


  
  if (polyMode == 0){ //mono (allows glide)
    vcoA1.frequency(a1FreqFiltered);
    vcoB1.frequency(b1FreqFiltered);
    vcoC1.frequency(c1FreqFiltered);
    sub1.frequency(sub1FreqFiltered);    
  }
  else{ //poly (no glide)
    vcoA1.frequency(a1Freq);
    vcoB1.frequency(b1Freq);
    vcoC1.frequency(c1Freq);
    sub1.frequency(sub1Freq);  
  }


  vcoA2.frequency(noteFreqs[note2freq] * octave * pitchFactorFiltered);
  b2Freq = noteFreqs[note2freq] * octave * octaveB * tuneBFiltered * pitchFactorFiltered; //separate because goes to LFO2 if needed
  vcoB2.frequency(b2Freq);
  c2Freq = noteFreqs[note2freq] * octave * octaveC * tuneCFiltered * pitchFactorFiltered;
  vcoC2.frequency(c2Freq);
  sub2.frequency(noteFreqs[note2freq] / 2 * octave * pitchFactorFiltered);

  vcoA3.frequency(noteFreqs[note3freq] * octave * pitchFactorFiltered);
  b3Freq = noteFreqs[note3freq] * octave * octaveB * tuneBFiltered * pitchFactorFiltered;
  vcoB3.frequency(b3Freq);
  c3Freq = noteFreqs[note3freq] * octave * octaveC * tuneCFiltered * pitchFactorFiltered;
  vcoC3.frequency(c3Freq);
  sub3.frequency(noteFreqs[note3freq] / 2 * octave * pitchFactorFiltered);

  vcoA4.frequency(noteFreqs[note4freq] * octave * pitchFactorFiltered);
  b4Freq = noteFreqs[note4freq] * octave * octaveB * tuneBFiltered * pitchFactorFiltered;
  vcoB4.frequency(b4Freq);
  c4Freq = noteFreqs[note4freq] * octave * octaveC * tuneCFiltered * pitchFactorFiltered;
  vcoC4.frequency(c4Freq);
  sub4.frequency(noteFreqs[note4freq] / 2 * octave * pitchFactorFiltered);

  vcoA5.frequency(noteFreqs[note5freq] * octave * pitchFactorFiltered);
  b5Freq = noteFreqs[note5freq] * octave * octaveB * tuneBFiltered * pitchFactorFiltered;
  vcoB5.frequency(b5Freq);
  c5Freq = noteFreqs[note5freq] * octave * octaveC * tuneCFiltered * pitchFactorFiltered;
  vcoC5.frequency(c5Freq);
  sub5.frequency(noteFreqs[note5freq] / 2 * octave * pitchFactorFiltered);

  vcoA6.frequency(noteFreqs[note6freq] * octave * pitchFactorFiltered);
  b6Freq = noteFreqs[note6freq] * octave * octaveB * tuneBFiltered * pitchFactorFiltered;
  vcoB6.frequency(b6Freq);
  c6Freq = noteFreqs[note6freq] * octave * octaveC * tuneCFiltered * pitchFactorFiltered;
  vcoC6.frequency(c6Freq);
  sub6.frequency(noteFreqs[note6freq] / 2 * octave * pitchFactorFiltered);



  //vco Mixer
  voiceMix1.gain(0, vcoAvol * mainVol);
  voiceMix1.gain(1, vcoBvol * mainVol);
  voiceMix1.gain(2, vcoCvol * mainVol);
  voiceMix1.gain(3, Subvol * mainVol);

  voiceMix2.gain(0, vcoAvol * mainVol);
  voiceMix2.gain(1, vcoBvol * mainVol);
  voiceMix2.gain(2, vcoCvol * mainVol);
  voiceMix2.gain(3, Subvol * mainVol);

  voiceMix3.gain(0, vcoAvol * mainVol);
  voiceMix3.gain(1, vcoBvol * mainVol);
  voiceMix3.gain(2, vcoCvol * mainVol);
  voiceMix3.gain(3, Subvol * mainVol);

  voiceMix4.gain(0, vcoAvol * mainVol);
  voiceMix4.gain(1, vcoBvol * mainVol);
  voiceMix4.gain(2, vcoCvol * mainVol);
  voiceMix4.gain(3, Subvol * mainVol);

  voiceMix5.gain(0, vcoAvol * mainVol);
  voiceMix5.gain(1, vcoBvol * mainVol);
  voiceMix5.gain(2, vcoCvol * mainVol);
  voiceMix5.gain(3, Subvol * mainVol);

  voiceMix6.gain(0, vcoAvol * mainVol);
  voiceMix6.gain(1, vcoBvol * mainVol);
  voiceMix6.gain(2, vcoCvol * mainVol);
  voiceMix6.gain(3, Subvol * mainVol);



  //vco A shape
  if (shapeA == 0) {
    vcoA1.begin(WAVEFORM_PULSE);
    vcoA2.begin(WAVEFORM_PULSE);
    vcoA3.begin(WAVEFORM_PULSE);
    vcoA4.begin(WAVEFORM_PULSE);
    vcoA5.begin(WAVEFORM_PULSE);
    vcoA6.begin(WAVEFORM_PULSE);
  } else if (shapeA == 1) {
    vcoA1.begin(WAVEFORM_SAWTOOTH);
    vcoA1.amplitude(vcoVol);
    vcoA2.begin(WAVEFORM_SAWTOOTH);
    vcoA2.amplitude(vcoVol);
    vcoA3.begin(WAVEFORM_SAWTOOTH);
    vcoA3.amplitude(vcoVol);
    vcoA4.begin(WAVEFORM_SAWTOOTH);
    vcoA4.amplitude(vcoVol);
    vcoA5.begin(WAVEFORM_SAWTOOTH);
    vcoA5.amplitude(vcoVol);
    vcoA6.begin(WAVEFORM_SAWTOOTH);
    vcoA6.amplitude(vcoVol);
  } else if (shapeA == 2) {
    vcoA1.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoA1.amplitude(vcoVol * 1.5);
    vcoA2.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoA2.amplitude(vcoVol * 1.5);
    vcoA3.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoA3.amplitude(vcoVol * 1.5);
    vcoA4.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoA4.amplitude(vcoVol * 1.5);
    vcoA5.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoA5.amplitude(vcoVol * 1.5);
    vcoA6.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoA6.amplitude(vcoVol * 1.5);
  }



  //vco B shape
  if (shapeB == 0) {
    vcoB1.offset(-0.006); //so that it doesn't tune the other wave
    vcoB2.offset(-0.006);
    vcoB3.offset(-0.006);
    vcoB4.offset(-0.006);
    vcoB5.offset(-0.006);
    vcoB6.offset(-0.006);
    vcoB1.begin(WAVEFORM_PULSE);
    vcoB2.begin(WAVEFORM_PULSE);
    vcoB3.begin(WAVEFORM_PULSE);
    vcoB4.begin(WAVEFORM_PULSE);
    vcoB5.begin(WAVEFORM_PULSE);
    vcoB6.begin(WAVEFORM_PULSE);
  } else if (shapeB == 1) {
    vcoB1.offset(-0.006);
    vcoB2.offset(-0.006);
    vcoB3.offset(-0.006);
    vcoB4.offset(-0.006);
    vcoB5.offset(-0.006);
    vcoB6.offset(-0.006);
    vcoB1.begin(WAVEFORM_SAWTOOTH);
    vcoB1.amplitude(vcoVol);
    vcoB2.begin(WAVEFORM_SAWTOOTH);
    vcoB2.amplitude(vcoVol);
    vcoB3.begin(WAVEFORM_SAWTOOTH);
    vcoB3.amplitude(vcoVol);
    vcoB4.begin(WAVEFORM_SAWTOOTH);
    vcoB4.amplitude(vcoVol);
    vcoB5.begin(WAVEFORM_SAWTOOTH);
    vcoB5.amplitude(vcoVol);
    vcoB6.begin(WAVEFORM_SAWTOOTH);
    vcoB6.amplitude(vcoVol);
  } else if (shapeB == 2) {
    vcoB1.offset(-0.006);
    vcoB2.offset(-0.006);
    vcoB3.offset(-0.006);
    vcoB4.offset(-0.006);
    vcoB5.offset(-0.006);
    vcoB6.offset(-0.006);
    vcoB1.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoB1.amplitude(vcoVol * 1.5);
    vcoB2.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoB2.amplitude(vcoVol * 1.5);
    vcoB3.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoB3.amplitude(vcoVol * 1.5);
    vcoB4.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoB4.amplitude(vcoVol * 1.5);
    vcoB5.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoB5.amplitude(vcoVol * 1.5);
    vcoB6.begin(WAVEFORM_TRIANGLE_VARIABLE);
    vcoB6.amplitude(vcoVol * 1.5);
  }



waveSelect = map(shapeC, 0, 1023, 1, 100);
switch (waveSelect) {
  case 1:
    vcoC1.arbitraryWaveform(wave1, 2000);
    vcoC2.arbitraryWaveform(wave1, 2000);
    vcoC3.arbitraryWaveform(wave1, 2000);
    vcoC4.arbitraryWaveform(wave1, 2000);
    vcoC5.arbitraryWaveform(wave1, 2000);
    vcoC6.arbitraryWaveform(wave1, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 2:
    vcoC1.arbitraryWaveform(wave2, 2000);
    vcoC2.arbitraryWaveform(wave2, 2000);
    vcoC3.arbitraryWaveform(wave2, 2000);
    vcoC4.arbitraryWaveform(wave2, 2000);
    vcoC5.arbitraryWaveform(wave2, 2000);
    vcoC6.arbitraryWaveform(wave2, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 3:
    vcoC1.arbitraryWaveform(wave3, 2000);
    vcoC2.arbitraryWaveform(wave3, 2000);
    vcoC3.arbitraryWaveform(wave3, 2000);
    vcoC4.arbitraryWaveform(wave3, 2000);
    vcoC5.arbitraryWaveform(wave3, 2000);
    vcoC6.arbitraryWaveform(wave3, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 4:
    vcoC1.arbitraryWaveform(wave4, 2000);
    vcoC2.arbitraryWaveform(wave4, 2000);
    vcoC3.arbitraryWaveform(wave4, 2000);
    vcoC4.arbitraryWaveform(wave4, 2000);
    vcoC5.arbitraryWaveform(wave4, 2000);
    vcoC6.arbitraryWaveform(wave4, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 5:
    vcoC1.arbitraryWaveform(wave5, 2000);
    vcoC2.arbitraryWaveform(wave5, 2000);
    vcoC3.arbitraryWaveform(wave5, 2000);
    vcoC4.arbitraryWaveform(wave5, 2000);
    vcoC5.arbitraryWaveform(wave5, 2000);
    vcoC6.arbitraryWaveform(wave5, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 6:
    vcoC1.arbitraryWaveform(wave6, 2000);
    vcoC2.arbitraryWaveform(wave6, 2000);
    vcoC3.arbitraryWaveform(wave6, 2000);
    vcoC4.arbitraryWaveform(wave6, 2000);
    vcoC5.arbitraryWaveform(wave6, 2000);
    vcoC6.arbitraryWaveform(wave6, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 7:
    vcoC1.arbitraryWaveform(wave7, 2000);
    vcoC2.arbitraryWaveform(wave7, 2000);
    vcoC3.arbitraryWaveform(wave7, 2000);
    vcoC4.arbitraryWaveform(wave7, 2000);
    vcoC5.arbitraryWaveform(wave7, 2000);
    vcoC6.arbitraryWaveform(wave7, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 8:
    vcoC1.arbitraryWaveform(wave8, 2000);
    vcoC2.arbitraryWaveform(wave8, 2000);
    vcoC3.arbitraryWaveform(wave8, 2000);
    vcoC4.arbitraryWaveform(wave8, 2000);
    vcoC5.arbitraryWaveform(wave8, 2000);
    vcoC6.arbitraryWaveform(wave8, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 9:
    vcoC1.arbitraryWaveform(wave9, 2000);
    vcoC2.arbitraryWaveform(wave9, 2000);
    vcoC3.arbitraryWaveform(wave9, 2000);
    vcoC4.arbitraryWaveform(wave9, 2000);
    vcoC5.arbitraryWaveform(wave9, 2000);
    vcoC6.arbitraryWaveform(wave9, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 10:
    vcoC1.arbitraryWaveform(wave10, 2000);
    vcoC2.arbitraryWaveform(wave10, 2000);
    vcoC3.arbitraryWaveform(wave10, 2000);
    vcoC4.arbitraryWaveform(wave10, 2000);
    vcoC5.arbitraryWaveform(wave10, 2000);
    vcoC6.arbitraryWaveform(wave10, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 11:
    vcoC1.arbitraryWaveform(wave11, 2000);
    vcoC2.arbitraryWaveform(wave11, 2000);
    vcoC3.arbitraryWaveform(wave11, 2000);
    vcoC4.arbitraryWaveform(wave11, 2000);
    vcoC5.arbitraryWaveform(wave11, 2000);
    vcoC6.arbitraryWaveform(wave11, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 12:
    vcoC1.arbitraryWaveform(wave12, 2000);
    vcoC2.arbitraryWaveform(wave12, 2000);
    vcoC3.arbitraryWaveform(wave12, 2000);
    vcoC4.arbitraryWaveform(wave12, 2000);
    vcoC5.arbitraryWaveform(wave12, 2000);
    vcoC6.arbitraryWaveform(wave12, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 13:
    vcoC1.arbitraryWaveform(wave13, 2000);
    vcoC2.arbitraryWaveform(wave13, 2000);
    vcoC3.arbitraryWaveform(wave13, 2000);
    vcoC4.arbitraryWaveform(wave13, 2000);
    vcoC5.arbitraryWaveform(wave13, 2000);
    vcoC6.arbitraryWaveform(wave13, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 14:
    vcoC1.arbitraryWaveform(wave14, 2000);
    vcoC2.arbitraryWaveform(wave14, 2000);
    vcoC3.arbitraryWaveform(wave14, 2000);
    vcoC4.arbitraryWaveform(wave14, 2000);
    vcoC5.arbitraryWaveform(wave14, 2000);
    vcoC6.arbitraryWaveform(wave14, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 15:
    vcoC1.arbitraryWaveform(wave15, 2000);
    vcoC2.arbitraryWaveform(wave15, 2000);
    vcoC3.arbitraryWaveform(wave15, 2000);
    vcoC4.arbitraryWaveform(wave15, 2000);
    vcoC5.arbitraryWaveform(wave15, 2000);
    vcoC6.arbitraryWaveform(wave15, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 16:
    vcoC1.arbitraryWaveform(wave16, 2000);
    vcoC2.arbitraryWaveform(wave16, 2000);
    vcoC3.arbitraryWaveform(wave16, 2000);
    vcoC4.arbitraryWaveform(wave16, 2000);
    vcoC5.arbitraryWaveform(wave16, 2000);
    vcoC6.arbitraryWaveform(wave16, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 17:
    vcoC1.arbitraryWaveform(wave17, 2000);
    vcoC2.arbitraryWaveform(wave17, 2000);
    vcoC3.arbitraryWaveform(wave17, 2000);
    vcoC4.arbitraryWaveform(wave17, 2000);
    vcoC5.arbitraryWaveform(wave17, 2000);
    vcoC6.arbitraryWaveform(wave17, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 18:
    vcoC1.arbitraryWaveform(wave18, 2000);
    vcoC2.arbitraryWaveform(wave18, 2000);
    vcoC3.arbitraryWaveform(wave18, 2000);
    vcoC4.arbitraryWaveform(wave18, 2000);
    vcoC5.arbitraryWaveform(wave18, 2000);
    vcoC6.arbitraryWaveform(wave18, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 19:
    vcoC1.arbitraryWaveform(wave19, 2000);
    vcoC2.arbitraryWaveform(wave19, 2000);
    vcoC3.arbitraryWaveform(wave19, 2000);
    vcoC4.arbitraryWaveform(wave19, 2000);
    vcoC5.arbitraryWaveform(wave19, 2000);
    vcoC6.arbitraryWaveform(wave19, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 20:
    vcoC1.arbitraryWaveform(wave20, 2000);
    vcoC2.arbitraryWaveform(wave20, 2000);
    vcoC3.arbitraryWaveform(wave20, 2000);
    vcoC4.arbitraryWaveform(wave20, 2000);
    vcoC5.arbitraryWaveform(wave20, 2000);
    vcoC6.arbitraryWaveform(wave20, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 21:
    vcoC1.arbitraryWaveform(wave21, 2000);
    vcoC2.arbitraryWaveform(wave21, 2000);
    vcoC3.arbitraryWaveform(wave21, 2000);
    vcoC4.arbitraryWaveform(wave21, 2000);
    vcoC5.arbitraryWaveform(wave21, 2000);
    vcoC6.arbitraryWaveform(wave21, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 22:
    vcoC1.arbitraryWaveform(wave22, 2000);
    vcoC2.arbitraryWaveform(wave22, 2000);
    vcoC3.arbitraryWaveform(wave22, 2000);
    vcoC4.arbitraryWaveform(wave22, 2000);
    vcoC5.arbitraryWaveform(wave22, 2000);
    vcoC6.arbitraryWaveform(wave22, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 23:
    vcoC1.arbitraryWaveform(wave23, 2000);
    vcoC2.arbitraryWaveform(wave23, 2000);
    vcoC3.arbitraryWaveform(wave23, 2000);
    vcoC4.arbitraryWaveform(wave23, 2000);
    vcoC5.arbitraryWaveform(wave23, 2000);
    vcoC6.arbitraryWaveform(wave23, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 24:
    vcoC1.arbitraryWaveform(wave24, 2000);
    vcoC2.arbitraryWaveform(wave24, 2000);
    vcoC3.arbitraryWaveform(wave24, 2000);
    vcoC4.arbitraryWaveform(wave24, 2000);
    vcoC5.arbitraryWaveform(wave24, 2000);
    vcoC6.arbitraryWaveform(wave24, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 25:
    vcoC1.arbitraryWaveform(wave25, 2000);
    vcoC2.arbitraryWaveform(wave25, 2000);
    vcoC3.arbitraryWaveform(wave25, 2000);
    vcoC4.arbitraryWaveform(wave25, 2000);
    vcoC5.arbitraryWaveform(wave25, 2000);
    vcoC6.arbitraryWaveform(wave25, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 26:
    vcoC1.arbitraryWaveform(wave26, 2000);
    vcoC2.arbitraryWaveform(wave26, 2000);
    vcoC3.arbitraryWaveform(wave26, 2000);
    vcoC4.arbitraryWaveform(wave26, 2000);
    vcoC5.arbitraryWaveform(wave26, 2000);
    vcoC6.arbitraryWaveform(wave26, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 27:
    vcoC1.arbitraryWaveform(wave27, 2000);
    vcoC2.arbitraryWaveform(wave27, 2000);
    vcoC3.arbitraryWaveform(wave27, 2000);
    vcoC4.arbitraryWaveform(wave27, 2000);
    vcoC5.arbitraryWaveform(wave27, 2000);
    vcoC6.arbitraryWaveform(wave27, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 28:
    vcoC1.arbitraryWaveform(wave28, 2000);
    vcoC2.arbitraryWaveform(wave28, 2000);
    vcoC3.arbitraryWaveform(wave28, 2000);
    vcoC4.arbitraryWaveform(wave28, 2000);
    vcoC5.arbitraryWaveform(wave28, 2000);
    vcoC6.arbitraryWaveform(wave28, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 29:
    vcoC1.arbitraryWaveform(wave29, 2000);
    vcoC2.arbitraryWaveform(wave29, 2000);
    vcoC3.arbitraryWaveform(wave29, 2000);
    vcoC4.arbitraryWaveform(wave29, 2000);
    vcoC5.arbitraryWaveform(wave29, 2000);
    vcoC6.arbitraryWaveform(wave29, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 30:
    vcoC1.arbitraryWaveform(wave30, 2000);
    vcoC2.arbitraryWaveform(wave30, 2000);
    vcoC3.arbitraryWaveform(wave30, 2000);
    vcoC4.arbitraryWaveform(wave30, 2000);
    vcoC5.arbitraryWaveform(wave30, 2000);
    vcoC6.arbitraryWaveform(wave30, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 31:
    vcoC1.arbitraryWaveform(wave31, 2000);
    vcoC2.arbitraryWaveform(wave31, 2000);
    vcoC3.arbitraryWaveform(wave31, 2000);
    vcoC4.arbitraryWaveform(wave31, 2000);
    vcoC5.arbitraryWaveform(wave31, 2000);
    vcoC6.arbitraryWaveform(wave31, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 32:
    vcoC1.arbitraryWaveform(wave32, 2000);
    vcoC2.arbitraryWaveform(wave32, 2000);
    vcoC3.arbitraryWaveform(wave32, 2000);
    vcoC4.arbitraryWaveform(wave32, 2000);
    vcoC5.arbitraryWaveform(wave32, 2000);
    vcoC6.arbitraryWaveform(wave32, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 33:
    vcoC1.arbitraryWaveform(wave33, 2000);
    vcoC2.arbitraryWaveform(wave33, 2000);
    vcoC3.arbitraryWaveform(wave33, 2000);
    vcoC4.arbitraryWaveform(wave33, 2000);
    vcoC5.arbitraryWaveform(wave33, 2000);
    vcoC6.arbitraryWaveform(wave33, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 34:
    vcoC1.arbitraryWaveform(wave34, 2000);
    vcoC2.arbitraryWaveform(wave34, 2000);
    vcoC3.arbitraryWaveform(wave34, 2000);
    vcoC4.arbitraryWaveform(wave34, 2000);
    vcoC5.arbitraryWaveform(wave34, 2000);
    vcoC6.arbitraryWaveform(wave34, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 35:
    vcoC1.arbitraryWaveform(wave35, 2000);
    vcoC2.arbitraryWaveform(wave35, 2000);
    vcoC3.arbitraryWaveform(wave35, 2000);
    vcoC4.arbitraryWaveform(wave35, 2000);
    vcoC5.arbitraryWaveform(wave35, 2000);
    vcoC6.arbitraryWaveform(wave35, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 36:
    vcoC1.arbitraryWaveform(wave36, 2000);
    vcoC2.arbitraryWaveform(wave36, 2000);
    vcoC3.arbitraryWaveform(wave36, 2000);
    vcoC4.arbitraryWaveform(wave36, 2000);
    vcoC5.arbitraryWaveform(wave36, 2000);
    vcoC6.arbitraryWaveform(wave36, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 37:
    vcoC1.arbitraryWaveform(wave37, 2000);
    vcoC2.arbitraryWaveform(wave37, 2000);
    vcoC3.arbitraryWaveform(wave37, 2000);
    vcoC4.arbitraryWaveform(wave37, 2000);
    vcoC5.arbitraryWaveform(wave37, 2000);
    vcoC6.arbitraryWaveform(wave37, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 38:
    vcoC1.arbitraryWaveform(wave38, 2000);
    vcoC2.arbitraryWaveform(wave38, 2000);
    vcoC3.arbitraryWaveform(wave38, 2000);
    vcoC4.arbitraryWaveform(wave38, 2000);
    vcoC5.arbitraryWaveform(wave38, 2000);
    vcoC6.arbitraryWaveform(wave38, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 39:
    vcoC1.arbitraryWaveform(wave39, 2000);
    vcoC2.arbitraryWaveform(wave39, 2000);
    vcoC3.arbitraryWaveform(wave39, 2000);
    vcoC4.arbitraryWaveform(wave39, 2000);
    vcoC5.arbitraryWaveform(wave39, 2000);
    vcoC6.arbitraryWaveform(wave39, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
  case 40:
    vcoC1.arbitraryWaveform(wave40, 2000);
    vcoC2.arbitraryWaveform(wave40, 2000);
    vcoC3.arbitraryWaveform(wave40, 2000);
    vcoC4.arbitraryWaveform(wave40, 2000);
    vcoC5.arbitraryWaveform(wave40, 2000);
    vcoC6.arbitraryWaveform(wave40, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 41:
    vcoC1.arbitraryWaveform(wave41, 2000);
    vcoC2.arbitraryWaveform(wave41, 2000);
    vcoC3.arbitraryWaveform(wave41, 2000);
    vcoC4.arbitraryWaveform(wave41, 2000);
    vcoC5.arbitraryWaveform(wave41, 2000);
    vcoC6.arbitraryWaveform(wave41, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 42:
    vcoC1.arbitraryWaveform(wave42, 2000);
    vcoC2.arbitraryWaveform(wave42, 2000);
    vcoC3.arbitraryWaveform(wave42, 2000);
    vcoC4.arbitraryWaveform(wave42, 2000);
    vcoC5.arbitraryWaveform(wave42, 2000);
    vcoC6.arbitraryWaveform(wave42, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 43:
    vcoC1.arbitraryWaveform(wave43, 2000);
    vcoC2.arbitraryWaveform(wave43, 2000);
    vcoC3.arbitraryWaveform(wave43, 2000);
    vcoC4.arbitraryWaveform(wave43, 2000);
    vcoC5.arbitraryWaveform(wave43, 2000);
    vcoC6.arbitraryWaveform(wave43, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 44:
    vcoC1.arbitraryWaveform(wave44, 2000);
    vcoC2.arbitraryWaveform(wave44, 2000);
    vcoC3.arbitraryWaveform(wave44, 2000);
    vcoC4.arbitraryWaveform(wave44, 2000);
    vcoC5.arbitraryWaveform(wave44, 2000);
    vcoC6.arbitraryWaveform(wave44, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 45:
    vcoC1.arbitraryWaveform(wave45, 2000);
    vcoC2.arbitraryWaveform(wave45, 2000);
    vcoC3.arbitraryWaveform(wave45, 2000);
    vcoC4.arbitraryWaveform(wave45, 2000);
    vcoC5.arbitraryWaveform(wave45, 2000);
    vcoC6.arbitraryWaveform(wave45, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 46:
    vcoC1.arbitraryWaveform(wave46, 2000);
    vcoC2.arbitraryWaveform(wave46, 2000);
    vcoC3.arbitraryWaveform(wave46, 2000);
    vcoC4.arbitraryWaveform(wave46, 2000);
    vcoC5.arbitraryWaveform(wave46, 2000);
    vcoC6.arbitraryWaveform(wave46, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 47:
    vcoC1.arbitraryWaveform(wave47, 2000);
    vcoC2.arbitraryWaveform(wave47, 2000);
    vcoC3.arbitraryWaveform(wave47, 2000);
    vcoC4.arbitraryWaveform(wave47, 2000);
    vcoC5.arbitraryWaveform(wave47, 2000);
    vcoC6.arbitraryWaveform(wave47, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 48:
    vcoC1.arbitraryWaveform(wave48, 2000);
    vcoC2.arbitraryWaveform(wave48, 2000);
    vcoC3.arbitraryWaveform(wave48, 2000);
    vcoC4.arbitraryWaveform(wave48, 2000);
    vcoC5.arbitraryWaveform(wave48, 2000);
    vcoC6.arbitraryWaveform(wave48, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 49:
    vcoC1.arbitraryWaveform(wave49, 2000);
    vcoC2.arbitraryWaveform(wave49, 2000);
    vcoC3.arbitraryWaveform(wave49, 2000);
    vcoC4.arbitraryWaveform(wave49, 2000);
    vcoC5.arbitraryWaveform(wave49, 2000);
    vcoC6.arbitraryWaveform(wave49, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
  case 50:
    vcoC1.arbitraryWaveform(wave50, 2000);
    vcoC2.arbitraryWaveform(wave50, 2000);
    vcoC3.arbitraryWaveform(wave50, 2000);
    vcoC4.arbitraryWaveform(wave50, 2000);
    vcoC5.arbitraryWaveform(wave50, 2000);
    vcoC6.arbitraryWaveform(wave50, 2000);
    vcoC1.amplitude(vcoVol);
    vcoC2.amplitude(vcoVol);
    vcoC3.amplitude(vcoVol);
    vcoC4.amplitude(vcoVol);
    vcoC5.amplitude(vcoVol);
    vcoC6.amplitude(vcoVol);
    break;
  case 51:
    vcoC1.arbitraryWaveform(wave51, 2000);
    vcoC2.arbitraryWaveform(wave51, 2000);
    vcoC3.arbitraryWaveform(wave51, 2000);
    vcoC4.arbitraryWaveform(wave51, 2000);
    vcoC5.arbitraryWaveform(wave51, 2000);
    vcoC6.arbitraryWaveform(wave51, 2000);
    vcoC1.amplitude(vcoVol * 1.01);
    vcoC2.amplitude(vcoVol * 1.01);
    vcoC3.amplitude(vcoVol * 1.01);
    vcoC4.amplitude(vcoVol * 1.01);
    vcoC5.amplitude(vcoVol * 1.01);
    vcoC6.amplitude(vcoVol * 1.01);
    break;
  case 52:
    vcoC1.arbitraryWaveform(wave52, 2000);
    vcoC2.arbitraryWaveform(wave52, 2000);
    vcoC3.arbitraryWaveform(wave52, 2000);
    vcoC4.arbitraryWaveform(wave52, 2000);
    vcoC5.arbitraryWaveform(wave52, 2000);
    vcoC6.arbitraryWaveform(wave52, 2000);
    vcoC1.amplitude(vcoVol * 1.02);
    vcoC2.amplitude(vcoVol * 1.02);
    vcoC3.amplitude(vcoVol * 1.02);
    vcoC4.amplitude(vcoVol * 1.02);
    vcoC5.amplitude(vcoVol * 1.02);
    vcoC6.amplitude(vcoVol * 1.02);
    break;
  case 53:
    vcoC1.arbitraryWaveform(wave53, 2000);
    vcoC2.arbitraryWaveform(wave53, 2000);
    vcoC3.arbitraryWaveform(wave53, 2000);
    vcoC4.arbitraryWaveform(wave53, 2000);
    vcoC5.arbitraryWaveform(wave53, 2000);
    vcoC6.arbitraryWaveform(wave53, 2000);
    vcoC1.amplitude(vcoVol * 1.03);
    vcoC2.amplitude(vcoVol * 1.03);
    vcoC3.amplitude(vcoVol * 1.03);
    vcoC4.amplitude(vcoVol * 1.03);
    vcoC5.amplitude(vcoVol * 1.03);
    vcoC6.amplitude(vcoVol * 1.03);
    break;
  case 54:
    vcoC1.arbitraryWaveform(wave54, 2000);
    vcoC2.arbitraryWaveform(wave54, 2000);
    vcoC3.arbitraryWaveform(wave54, 2000);
    vcoC4.arbitraryWaveform(wave54, 2000);
    vcoC5.arbitraryWaveform(wave54, 2000);
    vcoC6.arbitraryWaveform(wave54, 2000);
    vcoC1.amplitude(vcoVol * 1.04);
    vcoC2.amplitude(vcoVol * 1.04);
    vcoC3.amplitude(vcoVol * 1.04);
    vcoC4.amplitude(vcoVol * 1.04);
    vcoC5.amplitude(vcoVol * 1.04);
    vcoC6.amplitude(vcoVol * 1.04);
    break;
  case 55:
    vcoC1.arbitraryWaveform(wave55, 2000);
    vcoC2.arbitraryWaveform(wave55, 2000);
    vcoC3.arbitraryWaveform(wave55, 2000);
    vcoC4.arbitraryWaveform(wave55, 2000);
    vcoC5.arbitraryWaveform(wave55, 2000);
    vcoC6.arbitraryWaveform(wave55, 2000);
    vcoC1.amplitude(vcoVol * 1.05);
    vcoC2.amplitude(vcoVol * 1.05);
    vcoC3.amplitude(vcoVol * 1.05);
    vcoC4.amplitude(vcoVol * 1.05);
    vcoC5.amplitude(vcoVol * 1.05);
    vcoC6.amplitude(vcoVol * 1.05);
    break;
  case 56:
    vcoC1.arbitraryWaveform(wave56, 2000);
    vcoC2.arbitraryWaveform(wave56, 2000);
    vcoC3.arbitraryWaveform(wave56, 2000);
    vcoC4.arbitraryWaveform(wave56, 2000);
    vcoC5.arbitraryWaveform(wave56, 2000);
    vcoC6.arbitraryWaveform(wave56, 2000);
    vcoC1.amplitude(vcoVol * 1.06);
    vcoC2.amplitude(vcoVol * 1.06);
    vcoC3.amplitude(vcoVol * 1.06);
    vcoC4.amplitude(vcoVol * 1.06);
    vcoC5.amplitude(vcoVol * 1.06);
    vcoC6.amplitude(vcoVol * 1.06);
    break;
  case 57:
    vcoC1.arbitraryWaveform(wave57, 2000);
    vcoC2.arbitraryWaveform(wave57, 2000);
    vcoC3.arbitraryWaveform(wave57, 2000);
    vcoC4.arbitraryWaveform(wave57, 2000);
    vcoC5.arbitraryWaveform(wave57, 2000);
    vcoC6.arbitraryWaveform(wave57, 2000);
    vcoC1.amplitude(vcoVol * 1.07);
    vcoC2.amplitude(vcoVol * 1.07);
    vcoC3.amplitude(vcoVol * 1.07);
    vcoC4.amplitude(vcoVol * 1.07);
    vcoC5.amplitude(vcoVol * 1.07);
    vcoC6.amplitude(vcoVol * 1.07);
    break;
  case 58:
    vcoC1.arbitraryWaveform(wave58, 2000);
    vcoC2.arbitraryWaveform(wave58, 2000);
    vcoC3.arbitraryWaveform(wave58, 2000);
    vcoC4.arbitraryWaveform(wave58, 2000);
    vcoC5.arbitraryWaveform(wave58, 2000);
    vcoC6.arbitraryWaveform(wave58, 2000);
    vcoC1.amplitude(vcoVol * 1.08);
    vcoC2.amplitude(vcoVol * 1.08);
    vcoC3.amplitude(vcoVol * 1.08);
    vcoC4.amplitude(vcoVol * 1.08);
    vcoC5.amplitude(vcoVol * 1.08);
    vcoC6.amplitude(vcoVol * 1.08);
    break;
  case 59:
    vcoC1.arbitraryWaveform(wave59, 2000);
    vcoC2.arbitraryWaveform(wave59, 2000);
    vcoC3.arbitraryWaveform(wave59, 2000);
    vcoC4.arbitraryWaveform(wave59, 2000);
    vcoC5.arbitraryWaveform(wave59, 2000);
    vcoC6.arbitraryWaveform(wave59, 2000);
    vcoC1.amplitude(vcoVol * 1.09);
    vcoC2.amplitude(vcoVol * 1.09);
    vcoC3.amplitude(vcoVol * 1.09);
    vcoC4.amplitude(vcoVol * 1.09);
    vcoC5.amplitude(vcoVol * 1.09);
    vcoC6.amplitude(vcoVol * 1.09);
  case 60:
    vcoC1.arbitraryWaveform(wave60, 2000);
    vcoC2.arbitraryWaveform(wave60, 2000);
    vcoC3.arbitraryWaveform(wave60, 2000);
    vcoC4.arbitraryWaveform(wave60, 2000);
    vcoC5.arbitraryWaveform(wave60, 2000);
    vcoC6.arbitraryWaveform(wave60, 2000);
    vcoC1.amplitude(vcoVol * 1.10);
    vcoC2.amplitude(vcoVol * 1.10);
    vcoC3.amplitude(vcoVol * 1.10);
    vcoC4.amplitude(vcoVol * 1.10);
    vcoC5.amplitude(vcoVol * 1.10);
    vcoC6.amplitude(vcoVol * 1.10);
    break;
  case 61:
    vcoC1.arbitraryWaveform(wave61, 2000);
    vcoC2.arbitraryWaveform(wave61, 2000);
    vcoC3.arbitraryWaveform(wave61, 2000);
    vcoC4.arbitraryWaveform(wave61, 2000);
    vcoC5.arbitraryWaveform(wave61, 2000);
    vcoC6.arbitraryWaveform(wave61, 2000);
    vcoC1.amplitude(vcoVol * 1.11);
    vcoC2.amplitude(vcoVol * 1.11);
    vcoC3.amplitude(vcoVol * 1.11);
    vcoC4.amplitude(vcoVol * 1.11);
    vcoC5.amplitude(vcoVol * 1.11);
    vcoC6.amplitude(vcoVol * 1.11);
    break;
  case 62:
    vcoC1.arbitraryWaveform(wave62, 2000);
    vcoC2.arbitraryWaveform(wave62, 2000);
    vcoC3.arbitraryWaveform(wave62, 2000);
    vcoC4.arbitraryWaveform(wave62, 2000);
    vcoC5.arbitraryWaveform(wave62, 2000);
    vcoC6.arbitraryWaveform(wave62, 2000);
    vcoC1.amplitude(vcoVol * 1.12);
    vcoC2.amplitude(vcoVol * 1.12);
    vcoC3.amplitude(vcoVol * 1.12);
    vcoC4.amplitude(vcoVol * 1.12);
    vcoC5.amplitude(vcoVol * 1.12);
    vcoC6.amplitude(vcoVol * 1.12);
    break;
  case 63:
    vcoC1.arbitraryWaveform(wave63, 2000);
    vcoC2.arbitraryWaveform(wave63, 2000);
    vcoC3.arbitraryWaveform(wave63, 2000);
    vcoC4.arbitraryWaveform(wave63, 2000);
    vcoC5.arbitraryWaveform(wave63, 2000);
    vcoC6.arbitraryWaveform(wave63, 2000);
    vcoC1.amplitude(vcoVol * 1.13);
    vcoC2.amplitude(vcoVol * 1.13);
    vcoC3.amplitude(vcoVol * 1.13);
    vcoC4.amplitude(vcoVol * 1.13);
    vcoC5.amplitude(vcoVol * 1.13);
    vcoC6.amplitude(vcoVol * 1.13);
    break;
  case 64:
    vcoC1.arbitraryWaveform(wave64, 2000);
    vcoC2.arbitraryWaveform(wave64, 2000);
    vcoC3.arbitraryWaveform(wave64, 2000);
    vcoC4.arbitraryWaveform(wave64, 2000);
    vcoC5.arbitraryWaveform(wave64, 2000);
    vcoC6.arbitraryWaveform(wave64, 2000);
    vcoC1.amplitude(vcoVol * 1.14);
    vcoC2.amplitude(vcoVol * 1.14);
    vcoC3.amplitude(vcoVol * 1.14);
    vcoC4.amplitude(vcoVol * 1.14);
    vcoC5.amplitude(vcoVol * 1.14);
    vcoC6.amplitude(vcoVol * 1.14);
    break;
  case 65:
    vcoC1.arbitraryWaveform(wave65, 2000);
    vcoC2.arbitraryWaveform(wave65, 2000);
    vcoC3.arbitraryWaveform(wave65, 2000);
    vcoC4.arbitraryWaveform(wave65, 2000);
    vcoC5.arbitraryWaveform(wave65, 2000);
    vcoC6.arbitraryWaveform(wave65, 2000);
    vcoC1.amplitude(vcoVol * 1.15);
    vcoC2.amplitude(vcoVol * 1.15);
    vcoC3.amplitude(vcoVol * 1.15);
    vcoC4.amplitude(vcoVol * 1.15);
    vcoC5.amplitude(vcoVol * 1.15);
    vcoC6.amplitude(vcoVol * 1.15);
    break;
  case 66:
    vcoC1.arbitraryWaveform(wave66, 2000);
    vcoC2.arbitraryWaveform(wave66, 2000);
    vcoC3.arbitraryWaveform(wave66, 2000);
    vcoC4.arbitraryWaveform(wave66, 2000);
    vcoC5.arbitraryWaveform(wave66, 2000);
    vcoC6.arbitraryWaveform(wave66, 2000);
    vcoC1.amplitude(vcoVol * 1.16);
    vcoC2.amplitude(vcoVol * 1.16);
    vcoC3.amplitude(vcoVol * 1.16);
    vcoC4.amplitude(vcoVol * 1.16);
    vcoC5.amplitude(vcoVol * 1.16);
    vcoC6.amplitude(vcoVol * 1.16);
    break;
  case 67:
    vcoC1.arbitraryWaveform(wave67, 2000);
    vcoC2.arbitraryWaveform(wave67, 2000);
    vcoC3.arbitraryWaveform(wave67, 2000);
    vcoC4.arbitraryWaveform(wave67, 2000);
    vcoC5.arbitraryWaveform(wave67, 2000);
    vcoC6.arbitraryWaveform(wave67, 2000);
    vcoC1.amplitude(vcoVol * 1.17);
    vcoC2.amplitude(vcoVol * 1.17);
    vcoC3.amplitude(vcoVol * 1.17);
    vcoC4.amplitude(vcoVol * 1.17);
    vcoC5.amplitude(vcoVol * 1.17);
    vcoC6.amplitude(vcoVol * 1.17);
    break;
  case 68:
    vcoC1.arbitraryWaveform(wave68, 2000);
    vcoC2.arbitraryWaveform(wave68, 2000);
    vcoC3.arbitraryWaveform(wave68, 2000);
    vcoC4.arbitraryWaveform(wave68, 2000);
    vcoC5.arbitraryWaveform(wave68, 2000);
    vcoC6.arbitraryWaveform(wave68, 2000);
    vcoC1.amplitude(vcoVol * 1.18);
    vcoC2.amplitude(vcoVol * 1.18);
    vcoC3.amplitude(vcoVol * 1.18);
    vcoC4.amplitude(vcoVol * 1.18);
    vcoC5.amplitude(vcoVol * 1.18);
    vcoC6.amplitude(vcoVol * 1.18);
    break;
  case 69:
    vcoC1.arbitraryWaveform(wave69, 2000);
    vcoC2.arbitraryWaveform(wave69, 2000);
    vcoC3.arbitraryWaveform(wave69, 2000);
    vcoC4.arbitraryWaveform(wave69, 2000);
    vcoC5.arbitraryWaveform(wave69, 2000);
    vcoC6.arbitraryWaveform(wave69, 2000);
    vcoC1.amplitude(vcoVol * 1.19);
    vcoC2.amplitude(vcoVol * 1.19);
    vcoC3.amplitude(vcoVol * 1.19);
    vcoC4.amplitude(vcoVol * 1.19);
    vcoC5.amplitude(vcoVol * 1.19);
    vcoC6.amplitude(vcoVol * 1.19);
  case 70:
    vcoC1.arbitraryWaveform(wave70, 2000);
    vcoC2.arbitraryWaveform(wave70, 2000);
    vcoC3.arbitraryWaveform(wave70, 2000);
    vcoC4.arbitraryWaveform(wave70, 2000);
    vcoC5.arbitraryWaveform(wave70, 2000);
    vcoC6.arbitraryWaveform(wave70, 2000);
    vcoC1.amplitude(vcoVol * 1.20);
    vcoC2.amplitude(vcoVol * 1.20);
    vcoC3.amplitude(vcoVol * 1.20);
    vcoC4.amplitude(vcoVol * 1.20);
    vcoC5.amplitude(vcoVol * 1.20);
    vcoC6.amplitude(vcoVol * 1.20);
    break;
  case 71:
    vcoC1.arbitraryWaveform(wave71, 2000);
    vcoC2.arbitraryWaveform(wave71, 2000);
    vcoC3.arbitraryWaveform(wave71, 2000);
    vcoC4.arbitraryWaveform(wave71, 2000);
    vcoC5.arbitraryWaveform(wave71, 2000);
    vcoC6.arbitraryWaveform(wave71, 2000);
    vcoC1.amplitude(vcoVol * 1.21);
    vcoC2.amplitude(vcoVol * 1.21);
    vcoC3.amplitude(vcoVol * 1.21);
    vcoC4.amplitude(vcoVol * 1.21);
    vcoC5.amplitude(vcoVol * 1.21);
    vcoC6.amplitude(vcoVol * 1.21);
    break;
  case 72:
    vcoC1.arbitraryWaveform(wave72, 2000);
    vcoC2.arbitraryWaveform(wave72, 2000);
    vcoC3.arbitraryWaveform(wave72, 2000);
    vcoC4.arbitraryWaveform(wave72, 2000);
    vcoC5.arbitraryWaveform(wave72, 2000);
    vcoC6.arbitraryWaveform(wave72, 2000);
    vcoC1.amplitude(vcoVol * 1.22);
    vcoC2.amplitude(vcoVol * 1.22);
    vcoC3.amplitude(vcoVol * 1.22);
    vcoC4.amplitude(vcoVol * 1.22);
    vcoC5.amplitude(vcoVol * 1.22);
    vcoC6.amplitude(vcoVol * 1.22);
    break;
  case 73:
    vcoC1.arbitraryWaveform(wave73, 2000);
    vcoC2.arbitraryWaveform(wave73, 2000);
    vcoC3.arbitraryWaveform(wave73, 2000);
    vcoC4.arbitraryWaveform(wave73, 2000);
    vcoC5.arbitraryWaveform(wave73, 2000);
    vcoC6.arbitraryWaveform(wave73, 2000);
    vcoC1.amplitude(vcoVol * 1.23);
    vcoC2.amplitude(vcoVol * 1.23);
    vcoC3.amplitude(vcoVol * 1.23);
    vcoC4.amplitude(vcoVol * 1.23);
    vcoC5.amplitude(vcoVol * 1.23);
    vcoC6.amplitude(vcoVol * 1.23);
    break;
  case 74:
    vcoC1.arbitraryWaveform(wave74, 2000);
    vcoC2.arbitraryWaveform(wave74, 2000);
    vcoC3.arbitraryWaveform(wave74, 2000);
    vcoC4.arbitraryWaveform(wave74, 2000);
    vcoC5.arbitraryWaveform(wave74, 2000);
    vcoC6.arbitraryWaveform(wave74, 2000);
    vcoC1.amplitude(vcoVol * 1.24);
    vcoC2.amplitude(vcoVol * 1.24);
    vcoC3.amplitude(vcoVol * 1.24);
    vcoC4.amplitude(vcoVol * 1.24);
    vcoC5.amplitude(vcoVol * 1.24);
    vcoC6.amplitude(vcoVol * 1.24);
    break;
  case 75:
    vcoC1.arbitraryWaveform(wave75, 2000);
    vcoC2.arbitraryWaveform(wave75, 2000);
    vcoC3.arbitraryWaveform(wave75, 2000);
    vcoC4.arbitraryWaveform(wave75, 2000);
    vcoC5.arbitraryWaveform(wave75, 2000);
    vcoC6.arbitraryWaveform(wave75, 2000);
    vcoC1.amplitude(vcoVol * 1.25);
    vcoC2.amplitude(vcoVol * 1.25);
    vcoC3.amplitude(vcoVol * 1.25);
    vcoC4.amplitude(vcoVol * 1.25);
    vcoC5.amplitude(vcoVol * 1.25);
    vcoC6.amplitude(vcoVol * 1.25);
    break;
  case 76:
    vcoC1.arbitraryWaveform(wave76, 2000);
    vcoC2.arbitraryWaveform(wave76, 2000);
    vcoC3.arbitraryWaveform(wave76, 2000);
    vcoC4.arbitraryWaveform(wave76, 2000);
    vcoC5.arbitraryWaveform(wave76, 2000);
    vcoC6.arbitraryWaveform(wave76, 2000);
    vcoC1.amplitude(vcoVol * 1.26);
    vcoC2.amplitude(vcoVol * 1.26);
    vcoC3.amplitude(vcoVol * 1.26);
    vcoC4.amplitude(vcoVol * 1.26);
    vcoC5.amplitude(vcoVol * 1.26);
    vcoC6.amplitude(vcoVol * 1.26);
    break;
  case 77:
    vcoC1.arbitraryWaveform(wave77, 2000);
    vcoC2.arbitraryWaveform(wave77, 2000);
    vcoC3.arbitraryWaveform(wave77, 2000);
    vcoC4.arbitraryWaveform(wave77, 2000);
    vcoC5.arbitraryWaveform(wave77, 2000);
    vcoC6.arbitraryWaveform(wave77, 2000);
    vcoC1.amplitude(vcoVol * 1.27);
    vcoC2.amplitude(vcoVol * 1.27);
    vcoC3.amplitude(vcoVol * 1.27);
    vcoC4.amplitude(vcoVol * 1.27);
    vcoC5.amplitude(vcoVol * 1.27);
    vcoC6.amplitude(vcoVol * 1.27);
    break;
  case 78:
    vcoC1.arbitraryWaveform(wave78, 2000);
    vcoC2.arbitraryWaveform(wave78, 2000);
    vcoC3.arbitraryWaveform(wave78, 2000);
    vcoC4.arbitraryWaveform(wave78, 2000);
    vcoC5.arbitraryWaveform(wave78, 2000);
    vcoC6.arbitraryWaveform(wave78, 2000);
    vcoC1.amplitude(vcoVol * 1.28);
    vcoC2.amplitude(vcoVol * 1.28);
    vcoC3.amplitude(vcoVol * 1.28);
    vcoC4.amplitude(vcoVol * 1.28);
    vcoC5.amplitude(vcoVol * 1.28);
    vcoC6.amplitude(vcoVol * 1.28);
    break;
  case 79:
    vcoC1.arbitraryWaveform(wave79, 2000);
    vcoC2.arbitraryWaveform(wave79, 2000);
    vcoC3.arbitraryWaveform(wave79, 2000);
    vcoC4.arbitraryWaveform(wave79, 2000);
    vcoC5.arbitraryWaveform(wave79, 2000);
    vcoC6.arbitraryWaveform(wave79, 2000);
    vcoC1.amplitude(vcoVol * 1.29);
    vcoC2.amplitude(vcoVol * 1.29);
    vcoC3.amplitude(vcoVol * 1.29);
    vcoC4.amplitude(vcoVol * 1.29);
    vcoC5.amplitude(vcoVol * 1.29);
    vcoC6.amplitude(vcoVol * 1.29);
  case 80:
    vcoC1.arbitraryWaveform(wave80, 2000);
    vcoC2.arbitraryWaveform(wave80, 2000);
    vcoC3.arbitraryWaveform(wave80, 2000);
    vcoC4.arbitraryWaveform(wave80, 2000);
    vcoC5.arbitraryWaveform(wave80, 2000);
    vcoC6.arbitraryWaveform(wave80, 2000);
    vcoC1.amplitude(vcoVol * 1.30);
    vcoC2.amplitude(vcoVol * 1.30);
    vcoC3.amplitude(vcoVol * 1.30);
    vcoC4.amplitude(vcoVol * 1.30);
    vcoC5.amplitude(vcoVol * 1.30);
    vcoC6.amplitude(vcoVol * 1.30);
    break;
  case 81:
    vcoC1.arbitraryWaveform(wave81, 2000);
    vcoC2.arbitraryWaveform(wave81, 2000);
    vcoC3.arbitraryWaveform(wave81, 2000);
    vcoC4.arbitraryWaveform(wave81, 2000);
    vcoC5.arbitraryWaveform(wave81, 2000);
    vcoC6.arbitraryWaveform(wave81, 2000);
    vcoC1.amplitude(vcoVol * 1.31);
    vcoC2.amplitude(vcoVol * 1.31);
    vcoC3.amplitude(vcoVol * 1.31);
    vcoC4.amplitude(vcoVol * 1.31);
    vcoC5.amplitude(vcoVol * 1.31);
    vcoC6.amplitude(vcoVol * 1.31);
    break;
  case 82:
    vcoC1.arbitraryWaveform(wave82, 2000);
    vcoC2.arbitraryWaveform(wave82, 2000);
    vcoC3.arbitraryWaveform(wave82, 2000);
    vcoC4.arbitraryWaveform(wave82, 2000);
    vcoC5.arbitraryWaveform(wave82, 2000);
    vcoC6.arbitraryWaveform(wave82, 2000);
    vcoC1.amplitude(vcoVol * 1.32);
    vcoC2.amplitude(vcoVol * 1.32);
    vcoC3.amplitude(vcoVol * 1.32);
    vcoC4.amplitude(vcoVol * 1.32);
    vcoC5.amplitude(vcoVol * 1.32);
    vcoC6.amplitude(vcoVol * 1.32);
    break;
  case 83:
    vcoC1.arbitraryWaveform(wave83, 2000);
    vcoC2.arbitraryWaveform(wave83, 2000);
    vcoC3.arbitraryWaveform(wave83, 2000);
    vcoC4.arbitraryWaveform(wave83, 2000);
    vcoC5.arbitraryWaveform(wave83, 2000);
    vcoC6.arbitraryWaveform(wave83, 2000);
    vcoC1.amplitude(vcoVol * 1.33);
    vcoC2.amplitude(vcoVol * 1.33);
    vcoC3.amplitude(vcoVol * 1.33);
    vcoC4.amplitude(vcoVol * 1.33);
    vcoC5.amplitude(vcoVol * 1.33);
    vcoC6.amplitude(vcoVol * 1.33);
    break;
  case 84:
    vcoC1.arbitraryWaveform(wave84, 2000);
    vcoC2.arbitraryWaveform(wave84, 2000);
    vcoC3.arbitraryWaveform(wave84, 2000);
    vcoC4.arbitraryWaveform(wave84, 2000);
    vcoC5.arbitraryWaveform(wave84, 2000);
    vcoC6.arbitraryWaveform(wave84, 2000);
    vcoC1.amplitude(vcoVol * 1.34);
    vcoC2.amplitude(vcoVol * 1.34);
    vcoC3.amplitude(vcoVol * 1.34);
    vcoC4.amplitude(vcoVol * 1.34);
    vcoC5.amplitude(vcoVol * 1.34);
    vcoC6.amplitude(vcoVol * 1.34);
    break;
  case 85:
    vcoC1.arbitraryWaveform(wave85, 2000);
    vcoC2.arbitraryWaveform(wave85, 2000);
    vcoC3.arbitraryWaveform(wave85, 2000);
    vcoC4.arbitraryWaveform(wave85, 2000);
    vcoC5.arbitraryWaveform(wave85, 2000);
    vcoC6.arbitraryWaveform(wave85, 2000);
    vcoC1.amplitude(vcoVol * 1.35);
    vcoC2.amplitude(vcoVol * 1.35);
    vcoC3.amplitude(vcoVol * 1.35);
    vcoC4.amplitude(vcoVol * 1.35);
    vcoC5.amplitude(vcoVol * 1.35);
    vcoC6.amplitude(vcoVol * 1.35);
    break;
  case 86:
    vcoC1.arbitraryWaveform(wave86, 2000);
    vcoC2.arbitraryWaveform(wave86, 2000);
    vcoC3.arbitraryWaveform(wave86, 2000);
    vcoC4.arbitraryWaveform(wave86, 2000);
    vcoC5.arbitraryWaveform(wave86, 2000);
    vcoC6.arbitraryWaveform(wave86, 2000);
    vcoC1.amplitude(vcoVol * 1.36);
    vcoC2.amplitude(vcoVol * 1.36);
    vcoC3.amplitude(vcoVol * 1.36);
    vcoC4.amplitude(vcoVol * 1.36);
    vcoC5.amplitude(vcoVol * 1.36);
    vcoC6.amplitude(vcoVol * 1.36);
    break;
  case 87:
    vcoC1.arbitraryWaveform(wave87, 2000);
    vcoC2.arbitraryWaveform(wave87, 2000);
    vcoC3.arbitraryWaveform(wave87, 2000);
    vcoC4.arbitraryWaveform(wave87, 2000);
    vcoC5.arbitraryWaveform(wave87, 2000);
    vcoC6.arbitraryWaveform(wave87, 2000);
    vcoC1.amplitude(vcoVol * 1.37);
    vcoC2.amplitude(vcoVol * 1.37);
    vcoC3.amplitude(vcoVol * 1.37);
    vcoC4.amplitude(vcoVol * 1.37);
    vcoC5.amplitude(vcoVol * 1.37);
    vcoC6.amplitude(vcoVol * 1.37);
    break;
  case 88:
    vcoC1.arbitraryWaveform(wave88, 2000);
    vcoC2.arbitraryWaveform(wave88, 2000);
    vcoC3.arbitraryWaveform(wave88, 2000);
    vcoC4.arbitraryWaveform(wave88, 2000);
    vcoC5.arbitraryWaveform(wave88, 2000);
    vcoC6.arbitraryWaveform(wave88, 2000);
    vcoC1.amplitude(vcoVol * 1.38);
    vcoC2.amplitude(vcoVol * 1.38);
    vcoC3.amplitude(vcoVol * 1.38);
    vcoC4.amplitude(vcoVol * 1.38);
    vcoC5.amplitude(vcoVol * 1.38);
    vcoC6.amplitude(vcoVol * 1.38);
    break;
  case 89:
    vcoC1.arbitraryWaveform(wave89, 2000);
    vcoC2.arbitraryWaveform(wave89, 2000);
    vcoC3.arbitraryWaveform(wave89, 2000);
    vcoC4.arbitraryWaveform(wave89, 2000);
    vcoC5.arbitraryWaveform(wave89, 2000);
    vcoC6.arbitraryWaveform(wave89, 2000);
    vcoC1.amplitude(vcoVol * 1.39);
    vcoC2.amplitude(vcoVol * 1.39);
    vcoC3.amplitude(vcoVol * 1.39);
    vcoC4.amplitude(vcoVol * 1.39);
    vcoC5.amplitude(vcoVol * 1.39);
    vcoC6.amplitude(vcoVol * 1.39);
  case 90:
    vcoC1.arbitraryWaveform(wave90, 2000);
    vcoC2.arbitraryWaveform(wave90, 2000);
    vcoC3.arbitraryWaveform(wave90, 2000);
    vcoC4.arbitraryWaveform(wave90, 2000);
    vcoC5.arbitraryWaveform(wave90, 2000);
    vcoC6.arbitraryWaveform(wave90, 2000);
    vcoC1.amplitude(vcoVol * 1.40);
    vcoC2.amplitude(vcoVol * 1.40);
    vcoC3.amplitude(vcoVol * 1.40);
    vcoC4.amplitude(vcoVol * 1.40);
    vcoC5.amplitude(vcoVol * 1.40);
    vcoC6.amplitude(vcoVol * 1.40);
    break;
  case 91:
    vcoC1.arbitraryWaveform(wave91, 2000);
    vcoC2.arbitraryWaveform(wave91, 2000);
    vcoC3.arbitraryWaveform(wave91, 2000);
    vcoC4.arbitraryWaveform(wave91, 2000);
    vcoC5.arbitraryWaveform(wave91, 2000);
    vcoC6.arbitraryWaveform(wave91, 2000);
    vcoC1.amplitude(vcoVol * 1.41);
    vcoC2.amplitude(vcoVol * 1.41);
    vcoC3.amplitude(vcoVol * 1.41);
    vcoC4.amplitude(vcoVol * 1.41);
    vcoC5.amplitude(vcoVol * 1.41);
    vcoC6.amplitude(vcoVol * 1.41);
    break;
  case 92:
    vcoC1.arbitraryWaveform(wave92, 2000);
    vcoC2.arbitraryWaveform(wave92, 2000);
    vcoC3.arbitraryWaveform(wave92, 2000);
    vcoC4.arbitraryWaveform(wave92, 2000);
    vcoC5.arbitraryWaveform(wave92, 2000);
    vcoC6.arbitraryWaveform(wave92, 2000);
    vcoC1.amplitude(vcoVol * 1.42);
    vcoC2.amplitude(vcoVol * 1.42);
    vcoC3.amplitude(vcoVol * 1.42);
    vcoC4.amplitude(vcoVol * 1.42);
    vcoC5.amplitude(vcoVol * 1.42);
    vcoC6.amplitude(vcoVol * 1.42);
    break;
  case 93:
    vcoC1.arbitraryWaveform(wave93, 2000);
    vcoC2.arbitraryWaveform(wave93, 2000);
    vcoC3.arbitraryWaveform(wave93, 2000);
    vcoC4.arbitraryWaveform(wave93, 2000);
    vcoC5.arbitraryWaveform(wave93, 2000);
    vcoC6.arbitraryWaveform(wave93, 2000);
    vcoC1.amplitude(vcoVol * 1.43);
    vcoC2.amplitude(vcoVol * 1.43);
    vcoC3.amplitude(vcoVol * 1.43);
    vcoC4.amplitude(vcoVol * 1.43);
    vcoC5.amplitude(vcoVol * 1.43);
    vcoC6.amplitude(vcoVol * 1.43);
    break;
  case 94:
    vcoC1.arbitraryWaveform(wave94, 2000);
    vcoC2.arbitraryWaveform(wave94, 2000);
    vcoC3.arbitraryWaveform(wave94, 2000);
    vcoC4.arbitraryWaveform(wave94, 2000);
    vcoC5.arbitraryWaveform(wave94, 2000);
    vcoC6.arbitraryWaveform(wave94, 2000);
    vcoC1.amplitude(vcoVol * 1.44);
    vcoC2.amplitude(vcoVol * 1.44);
    vcoC3.amplitude(vcoVol * 1.44);
    vcoC4.amplitude(vcoVol * 1.44);
    vcoC5.amplitude(vcoVol * 1.44);
    vcoC6.amplitude(vcoVol * 1.44);
    break;
  case 95:
    vcoC1.arbitraryWaveform(wave95, 2000);
    vcoC2.arbitraryWaveform(wave95, 2000);
    vcoC3.arbitraryWaveform(wave95, 2000);
    vcoC4.arbitraryWaveform(wave95, 2000);
    vcoC5.arbitraryWaveform(wave95, 2000);
    vcoC6.arbitraryWaveform(wave95, 2000);
    vcoC1.amplitude(vcoVol * 1.45);
    vcoC2.amplitude(vcoVol * 1.45);
    vcoC3.amplitude(vcoVol * 1.45);
    vcoC4.amplitude(vcoVol * 1.45);
    vcoC5.amplitude(vcoVol * 1.45);
    vcoC6.amplitude(vcoVol * 1.45);
    break;
  case 96:
    vcoC1.arbitraryWaveform(wave96, 2000);
    vcoC2.arbitraryWaveform(wave96, 2000);
    vcoC3.arbitraryWaveform(wave96, 2000);
    vcoC4.arbitraryWaveform(wave96, 2000);
    vcoC5.arbitraryWaveform(wave96, 2000);
    vcoC6.arbitraryWaveform(wave96, 2000);
    vcoC1.amplitude(vcoVol * 1.46);
    vcoC2.amplitude(vcoVol * 1.46);
    vcoC3.amplitude(vcoVol * 1.46);
    vcoC4.amplitude(vcoVol * 1.46);
    vcoC5.amplitude(vcoVol * 1.46);
    vcoC6.amplitude(vcoVol * 1.46);
    break;
  case 97:
    vcoC1.arbitraryWaveform(wave97, 2000);
    vcoC2.arbitraryWaveform(wave97, 2000);
    vcoC3.arbitraryWaveform(wave97, 2000);
    vcoC4.arbitraryWaveform(wave97, 2000);
    vcoC5.arbitraryWaveform(wave97, 2000);
    vcoC6.arbitraryWaveform(wave97, 2000);
    vcoC1.amplitude(vcoVol * 1.47);
    vcoC2.amplitude(vcoVol * 1.47);
    vcoC3.amplitude(vcoVol * 1.47);
    vcoC4.amplitude(vcoVol * 1.47);
    vcoC5.amplitude(vcoVol * 1.47);
    vcoC6.amplitude(vcoVol * 1.47);
    break;
  case 98:
    vcoC1.arbitraryWaveform(wave98, 2000);
    vcoC2.arbitraryWaveform(wave98, 2000);
    vcoC3.arbitraryWaveform(wave98, 2000);
    vcoC4.arbitraryWaveform(wave98, 2000);
    vcoC5.arbitraryWaveform(wave98, 2000);
    vcoC6.arbitraryWaveform(wave98, 2000);
    vcoC1.amplitude(vcoVol * 1.48);
    vcoC2.amplitude(vcoVol * 1.48);
    vcoC3.amplitude(vcoVol * 1.48);
    vcoC4.amplitude(vcoVol * 1.48);
    vcoC5.amplitude(vcoVol * 1.48);
    vcoC6.amplitude(vcoVol * 1.48);
    break;
  case 99:
    vcoC1.arbitraryWaveform(wave99, 2000);
    vcoC2.arbitraryWaveform(wave99, 2000);
    vcoC3.arbitraryWaveform(wave99, 2000);
    vcoC4.arbitraryWaveform(wave99, 2000);
    vcoC5.arbitraryWaveform(wave99, 2000);
    vcoC6.arbitraryWaveform(wave99, 2000);
    vcoC1.amplitude(vcoVol * 1.49);
    vcoC2.amplitude(vcoVol * 1.49);
    vcoC3.amplitude(vcoVol * 1.49);
    vcoC4.amplitude(vcoVol * 1.49);
    vcoC5.amplitude(vcoVol * 1.49);
    vcoC6.amplitude(vcoVol * 1.49);
  case 100:
    vcoC1.arbitraryWaveform(wave100, 2000);
    vcoC2.arbitraryWaveform(wave100, 2000);
    vcoC3.arbitraryWaveform(wave100, 2000);
    vcoC4.arbitraryWaveform(wave100, 2000);
    vcoC5.arbitraryWaveform(wave100, 2000);
    vcoC6.arbitraryWaveform(wave100, 2000);
    vcoC1.amplitude(vcoVol * 1.50);
    vcoC2.amplitude(vcoVol * 1.50);
    vcoC3.amplitude(vcoVol * 1.50);
    vcoC4.amplitude(vcoVol * 1.50);
    vcoC5.amplitude(vcoVol * 1.50);
    vcoC6.amplitude(vcoVol * 1.50);
}
 
