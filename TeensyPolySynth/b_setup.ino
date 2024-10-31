void setup() {
  Serial.begin(9600);

  AudioMemory(1000);

  EEPROM.setMemPool(32, 4096);
  EEPROM.setMaxAllowedWrites(500); 
  MIDI.setHandleNoteOn(myNoteOn);
  MIDI.setHandleNoteOff(myNoteOff);
  MIDI.setHandlePitchBend(myPitchChange); 
  MIDI.setHandleControlChange(myModChange);
  MIDI.begin(MIDI_CHANNEL_OMNI);


  //Switches
  pinMode(1, INPUT_PULLUP); //poly

  pinMode(2, INPUT_PULLUP); //shape A
  pinMode(3, INPUT_PULLUP); //shape A
  pinMode(4, INPUT_PULLUP); //shape B
  pinMode(5, INPUT_PULLUP); //shape B
  pinMode(6, INPUT_PULLUP); //main oct
  pinMode(8, INPUT_PULLUP); //main oct 
  pinMode(10, INPUT_PULLUP); //oct B
  pinMode(19, INPUT_PULLUP); //oct B
  pinMode(12, INPUT_PULLUP); //oct C
  pinMode(24, INPUT_PULLUP); //oct C
  pinMode(25, INPUT_PULLUP); //filter mode
  pinMode(26, INPUT_PULLUP); //filter mode
  pinMode(27, INPUT_PULLUP); //LFO target
  pinMode(28, INPUT_PULLUP); //LFO target
  pinMode(29, INPUT_PULLUP); //LFO shape
  pinMode(30, INPUT_PULLUP); //LFO shape
  pinMode(31, INPUT_PULLUP); //preset save
  pinMode(32, INPUT_PULLUP); //preset reset

  pinMode(14, INPUT_DISABLE); //or there's a weird hysteresis
  pinMode(15, INPUT_DISABLE);
  pinMode(16, INPUT_DISABLE);
  pinMode(17, INPUT_DISABLE);


  //Mux setup
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);

  digitalWrite(37, 0);
  digitalWrite(38, 0);
  digitalWrite(39, 0);

  
  //preset LEDs
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(18, OUTPUT);

  digitalWrite(33, 0); //LEDs off
  digitalWrite(34, 0);
  digitalWrite(35, 0);
  digitalWrite(36, 0);
  digitalWrite(18, 0);



  //vco setup
  vcoA1.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB1.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC1.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub1.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA2.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB2.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC2.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub2.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA3.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB3.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC3.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub3.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA4.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB4.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC4.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub4.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA5.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB5.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC5.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub5.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA6.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB6.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC6.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub6.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);


  //filter
  filter1.octaveControl(7);
  filterEnv1.sustain(1);
  filterEnv1.decay(10); //some very short value as it doesn't matter anyway

  filter2.octaveControl(7);
  filterEnv2.sustain(1);
  filterEnv2.decay(10);

  filter3.octaveControl(7);
  filterEnv3.sustain(1);
  filterEnv3.decay(10);

  filter4.octaveControl(7);
  filterEnv4.sustain(1);
  filterEnv4.decay(10);

  filter5.octaveControl(7);
  filterEnv5.sustain(1);
  filterEnv5.decay(10);

  filter6.octaveControl(7);
  filterEnv6.sustain(1);
  filterEnv6.decay(10);


  //lfo A
  lfoA1.begin(WAVEFORM_SINE);
//  lfoA1.offset(0.5);
//  lfoA1.amplitude(0.5);


  //lfo B
  lfoB1.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB2.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB3.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB4.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB5.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB6.begin(0.5, 1, WAVEFORM_TRIANGLE);


  //lfo A params
  
  lfoAenv1.delay(0);
  lfoAenv1.sustain(1);  
  lfoAenv2.delay(0);
  lfoAenv2.sustain(1);
  lfoAenv3.delay(0);
  lfoAenv3.sustain(1);
  lfoAenv4.delay(0);
  lfoAenv4.sustain(1);
  lfoAenv5.delay(0);
  lfoAenv5.sustain(1);
  lfoAenv6.delay(0);
  lfoAenv6.sustain(1);
  
  lfoAenv1.decay(minTime); //set default decay to something small to preempt weirdness
  lfoAenv2.decay(minTime);
  lfoAenv3.decay(minTime);
  lfoAenv4.decay(minTime);
  lfoAenv5.decay(minTime);
  lfoAenv6.decay(minTime);

  //output gain to get to normal line level
  amp1.gain(2);
  amp2.gain(2);

  //dly
  dlyFiltL.frequency(3000);
  dlyFiltR.frequency(4000);

  dlyMixL.gain(0, 0.85);
  dlyMixR.gain(0, 0.85);

  shoutMixer.gain(0, 0.15);
  shoutMixer.gain(1, 0.15);
  shoutMixer.gain(2, 0.15);
  shoutMixer.gain(3, 0.15);


  dlyL.disable(1); //disable unwanted taps
  dlyL.disable(2);
  dlyL.disable(3);
  dlyL.disable(4);
  dlyL.disable(5);
  dlyL.disable(6);
  dlyL.disable(7);

  dlyR.disable(1);
  dlyR.disable(2);
  dlyR.disable(3);
  dlyR.disable(4);
  dlyR.disable(5);
  dlyR.disable(6);
  dlyR.disable(7);


  //reverb
  amp3.gain(4);
  reverb.roomsize(0.9);
  reverb.damping(0.8);




  //LFO DESTINATION DISCONNECT
  patchCord7.disconnect(); //vcoA
  patchCord8.disconnect(); //vcoB
  patchCord9.disconnect(); //vcoC
  patchCord10.disconnect(); //sub
  patchCord15.disconnect(); //vcoA
  patchCord16.disconnect(); //vcoB
  patchCord17.disconnect(); //vcoC
  patchCord18.disconnect(); //sub
  patchCord20.disconnect(); //vcoA
  patchCord21.disconnect(); //vcoB
  patchCord22.disconnect(); //vcoC
  patchCord23.disconnect(); //sub
  patchCord25.disconnect(); //vcoA
  patchCord26.disconnect(); //vcoB
  patchCord27.disconnect(); //vcoC
  patchCord28.disconnect(); //sub
  patchCord36.disconnect(); //vcoA
  patchCord37.disconnect(); //vcoB
  patchCord38.disconnect(); //vcoC
  patchCord39.disconnect(); //sub
  patchCord41.disconnect(); //vcoA
  patchCord42.disconnect(); //vcoB
  patchCord43.disconnect(); //vcoC
  patchCord44.disconnect(); //sub

  patchCord11.disconnect(); //filter
  patchCord19.disconnect(); //filter
  patchCord24.disconnect(); //filter
  patchCord29.disconnect(); //filter
  patchCord40.disconnect(); //filter
  patchCord45.disconnect(); //filter

  patchCord170.connect(); //amp connection to unity DC
  patchCord171.connect(); //amp
  patchCord172.connect(); //amp
  patchCord173.connect(); //amp
  patchCord174.connect(); //amp
  patchCord175.connect(); //amp
  
  dc7.amplitude(0.707); //dc component for amp for when lfo is disconnected (should normal to unity gain not 0)
  dc8.amplitude(0.707);
  dc9.amplitude(0.707);
  dc10.amplitude(0.707);
  dc11.amplitude(0.707);
  dc12.amplitude(0.707);
  

 for (int i = 0; i <= 2; i++) { //flash the lights a bit. for fun
    digitalWrite(33, 1);
    digitalWrite(34, 1);
    digitalWrite(35, 1);
    digitalWrite(36, 1);
    digitalWrite(18, 1);
    delay(100);
    digitalWrite(33, 0);
    digitalWrite(34, 0);
    digitalWrite(35, 0);
    digitalWrite(36, 0);
    digitalWrite(18, 0);
    delay(100);
  }


}
