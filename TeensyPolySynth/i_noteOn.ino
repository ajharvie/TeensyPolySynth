void myNoteOn(byte channel, byte note, byte velocity) {
  if (polyMode == 1) { //POLYPHONIC mode 
    switch (voices) {
      case 0 ... 5:
        if (env1on == false) {
          note1freq = note;
          env1.noteOn();
          filterEnv1.noteOn();
          lfoAenv1.noteOn();
          env1on = true;
          
        } else if (env2on == false) {
          note2freq = note;
          env2.noteOn();
          filterEnv2.noteOn();
          lfoAenv2.noteOn();
          env2on = true;
          
        } else if (env3on == false) {
          note3freq = note;
          env3.noteOn();
          filterEnv3.noteOn();
          lfoAenv3.noteOn();
          env3on = true;

        } else if (env4on == false) {
          note4freq = note;
          env4.noteOn();
          filterEnv4.noteOn();
          lfoAenv4.noteOn();
          env4on = true;

        } else if (env5on == false) {
          note5freq = note;
          env5.noteOn();
          filterEnv5.noteOn();
          lfoAenv5.noteOn();
          env5on = true;

        } else if (env6on == false) {
          note6freq = note;
          env6.noteOn();
          filterEnv6.noteOn();
          lfoAenv6.noteOn();
          env6on = true;

        }
        voices++;
        break;
    }


  } else if (polyMode == 0) { //MONOPHONIC mode
    note1freq = note;
    env1.noteOn();
    filterEnv1.noteOn();
    lfoAenv1.noteOn();
    env1on = true;
    voices++;
  }
  
  else{ //secret unhappy mode
    shout = 1;
  }
}




void myNoteOff(byte channel, byte note, byte velocity) {
  
  if (polyMode == 2){
    shout = 0;
  }
  
  else {
    switch (voices) {
      case 0 ... 6:
        if (note1freq == note) {
          env1.noteOff();
          filterEnv1.noteOff();
          lfoAenv1.noteOff();
          env1on = false;
        } else if (note2freq == note) {
          env2.noteOff();
          filterEnv2.noteOff();
          lfoAenv2.noteOff();
          env2on = false;
        } else if (note3freq == note) {
          env3.noteOff();
          filterEnv3.noteOff();
          lfoAenv3.noteOff();
          env3on = false;
        } else if (note4freq == note) {
          env4.noteOff();
          filterEnv4.noteOff();
          lfoAenv4.noteOff();
          env4on = false;
        } else if (note5freq == note) {
          env5.noteOff();
          filterEnv5.noteOff();
          lfoAenv5.noteOff();
          env5on = false;
        } else if (note6freq == note) {
          env6.noteOff();
          filterEnv6.noteOff();
          lfoAenv6.noteOff();
          env6on = false;
        }
        voices--;
        break;
  
    } 
  }
}

void myPitchChange(byte channel, int pitch) {
  numSemitones = mapf(pitch, -8192, 8191, -12, 12); 
  pitchFactor = pow(2,(numSemitones/12.0));
}

void myModChange(byte channel, byte number, byte value){
  if(number == 1){
    filterExtMod = 3*expLookup1024[(value + 1)*8 -1];
  }
}

//mapping function for pots, it's the standard arduino map but for floats
float mapf(float x, float in_min, float in_max, float out_min, float out_max){
  
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void startPlaying() {
  //start SCREAMING BLOODY MURDER
  
  if (silent == 1){
    playMem1.play(AudioSampleScreamattack);
    silent = 0;
  }
  else{ // a way to get a relatively smooth loop
    if(!playMem2.isPlaying() && !playMem3.isPlaying() && playMem1.lengthMillis() - playMem1.positionMillis() < delayFix){
      playMem2.play(AudioSampleScreamsustain);
    }
    if(playMem2.isPlaying() && playMem2.lengthMillis() - playMem2.positionMillis() < delayFix && !playMem3.isPlaying()){
      playMem3.play(AudioSampleScreamsustain);
    }
    if(playMem3.isPlaying() && playMem3.lengthMillis() - playMem3.positionMillis() < delayFix && !playMem2.isPlaying()){
      playMem2.play(AudioSampleScreamsustain);
    }       
  }   
}





void stopPlaying() {
  // okay that's enough SCREAMING
  if (silent == 0){
    if(playMem1.isPlaying() && playMem1.lengthMillis() - playMem1.positionMillis() < delayFix){
      playMem4.play(AudioSampleScreamdecay);
      silent = 1; 
    }
    if(playMem2.isPlaying() && playMem2.lengthMillis() - playMem2.positionMillis() < delayFix){
      playMem4.play(AudioSampleScreamdecay);
      silent = 1; 
    }
    if(playMem3.isPlaying() && playMem3.lengthMillis() - playMem3.positionMillis() < delayFix){
      playMem4.play(AudioSampleScreamdecay);
      silent = 1; 
    }    
  }    
}
