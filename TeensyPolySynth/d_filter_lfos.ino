
//filter
filter1.frequency(cut + filterExtMod);
filter1.resonance(res);

filter2.frequency(cut + filterExtMod);
filter2.resonance(res);

filter3.frequency(cut + filterExtMod);
filter3.resonance(res);

filter4.frequency(cut + filterExtMod);
filter4.resonance(res);

filter5.frequency(cut + filterExtMod);
filter5.resonance(res);

filter6.frequency(cut + filterExtMod);
filter6.resonance(res);


//filter env
filterEnv1.attack(filtAtt);
filterEnv1.release(filtDec);
dc1.amplitude(filtAmt);

filterEnv2.attack(filtAtt);
filterEnv2.release(filtDec);
dc2.amplitude(filtAmt);

filterEnv3.attack(filtAtt);
filterEnv3.release(filtDec);
dc3.amplitude(filtAmt);

filterEnv4.attack(filtAtt);
filterEnv4.release(filtDec);
dc4.amplitude(filtAmt);

filterEnv5.attack(filtAtt);
filterEnv5.release(filtDec);
dc5.amplitude(filtAmt);

filterEnv6.attack(filtAtt);
filterEnv6.release(filtDec);
dc6.amplitude(filtAmt);


//filter mode
if (filterMode == 1) { //low pass
  filterMode1.gain(0, 1);
  filterMode1.gain(1, 0);
  filterMode1.gain(2, 0);
  filterMode2.gain(0, 1);
  filterMode2.gain(1, 0);
  filterMode2.gain(2, 0);
  filterMode3.gain(0, 1);
  filterMode3.gain(1, 0);
  filterMode3.gain(2, 0);
  filterMode4.gain(0, 1);
  filterMode4.gain(1, 0);
  filterMode4.gain(2, 0);
  filterMode5.gain(0, 1);
  filterMode5.gain(1, 0);
  filterMode5.gain(2, 0);
  filterMode6.gain(0, 1);
  filterMode6.gain(1, 0);
  filterMode6.gain(2, 0);
} else if (filterMode == 0) { //band pass
  filterMode1.gain(0, 0);
  filterMode1.gain(1, 1);
  filterMode1.gain(2, 0);
  filterMode2.gain(0, 0);
  filterMode2.gain(1, 1);
  filterMode2.gain(2, 0);
  filterMode3.gain(0, 0);
  filterMode3.gain(1, 1);
  filterMode3.gain(2, 0);
  filterMode4.gain(0, 0);
  filterMode4.gain(1, 1);
  filterMode4.gain(2, 0);
  filterMode5.gain(0, 0);
  filterMode5.gain(1, 1);
  filterMode5.gain(2, 0);
  filterMode6.gain(0, 0);
  filterMode6.gain(1, 1);
  filterMode6.gain(2, 0);
}
else if (filterMode == 2) { //high pass
  filterMode1.gain(0, 0);
  filterMode1.gain(1, 0);
  filterMode1.gain(2, 1);
  filterMode2.gain(0, 0);
  filterMode2.gain(1, 0);
  filterMode2.gain(2, 1);
  filterMode3.gain(0, 0);
  filterMode3.gain(1, 0);
  filterMode3.gain(2, 1);
  filterMode4.gain(0, 0);
  filterMode4.gain(1, 0);
  filterMode4.gain(2, 1);
  filterMode5.gain(0, 0);
  filterMode5.gain(1, 0);
  filterMode5.gain(2, 1);
  filterMode6.gain(0, 0);
  filterMode6.gain(1, 0);
  filterMode6.gain(2, 1);
}






//lfo shape switch
if (lfoAshape == 0) {
  lfoA1.begin(WAVEFORM_SINE);

} else if (lfoAshape == 1) {
  lfoA1.begin(WAVEFORM_SAWTOOTH_REVERSE);

} else if (lfoAshape == 2) {
  lfoA1.begin(WAVEFORM_SAMPLE_HOLD);

}


finalMix.gain(0, 3);
finalMix.gain(1, 3);    




//lfo B params
lfoB1.amplitude(lfoBamp);
if (lfoBSnap == 0){
  lfoB1.frequency(lfoBfreq);
  lfoB2.frequency(lfoBfreq);
  lfoB3.frequency(lfoBfreq);
  lfoB4.frequency(lfoBfreq);
  lfoB5.frequency(lfoBfreq);
  lfoB6.frequency(lfoBfreq);
  if (justSnapped == 1){
    lfoB1.phase(0); 
    lfoB2.phase(0); 
    lfoB3.phase(0); 
    lfoB4.phase(0); 
    lfoB5.phase(0); 
    lfoB6.phase(0); 
    justSnapped = 0;
  }
}
else{
  lfoB1.frequency(c1Freq);
  lfoB2.frequency(c2Freq);
  lfoB3.frequency(c3Freq);
  lfoB4.frequency(c4Freq);
  lfoB5.frequency(c5Freq);
  lfoB6.frequency(c6Freq);
  justSnapped = 1;
}




//LFO A DESTINATION
if (lfoAdest == 0) { //lfo - pitch
  patchCord7.connect(); //vcoA
  patchCord8.connect(); //vcoB
  patchCord9.connect(); //vcoC
  patchCord10.connect(); //sub
  patchCord15.connect(); //vcoA
  patchCord16.connect(); //vcoB
  patchCord17.connect(); //vcoC
  patchCord18.connect(); //sub
  patchCord20.connect(); //vcoA
  patchCord21.connect(); //vcoB
  patchCord22.connect(); //vcoC
  patchCord23.connect(); //sub
  patchCord25.connect(); //vcoA
  patchCord26.connect(); //vcoB
  patchCord27.connect(); //vcoC
  patchCord28.connect(); //sub
  patchCord36.connect(); //vcoA
  patchCord37.connect(); //vcoB
  patchCord38.connect(); //vcoC
  patchCord39.connect(); //sub
  patchCord41.connect(); //vcoA
  patchCord42.connect(); //vcoB
  patchCord43.connect(); //vcoC
  patchCord44.connect(); //sub

  patchCord11.disconnect(); //filter
  patchCord19.disconnect(); //filter
  patchCord24.disconnect(); //filter
  patchCord29.disconnect(); //filter
  patchCord40.disconnect(); //filter
  patchCord45.disconnect(); //filter

  patchCord12.disconnect(); //amp - lfo env to multiplier
  patchCord165.disconnect();
  patchCord166.disconnect();
  patchCord167.disconnect();
  patchCord168.disconnect();
  patchCord169.disconnect();

  patchCord170.connect(); //amp - DC source to multiplier
  patchCord171.connect(); //amp
  patchCord172.connect(); //amp
  patchCord173.connect(); //amp
  patchCord174.connect(); //amp
  patchCord175.connect(); //amp
  
  lfoA1.frequency(lfoAfreq);
  lfoAampMin = 0;

  lfoA1.offset(0);



} if (lfoAdest == 1) { //lfo - filter

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

  patchCord11.connect(); //filter
  patchCord19.connect(); //filter
  patchCord24.connect(); //filter
  patchCord29.connect(); //filter
  patchCord40.connect(); //filter
  patchCord45.connect(); //filter

  patchCord12.disconnect(); //amp - lfo env to multiplier
  patchCord165.disconnect();
  patchCord166.disconnect();
  patchCord167.disconnect();
  patchCord168.disconnect();
  patchCord169.disconnect();

  patchCord170.connect(); //amp - DC source to multiplier
  patchCord171.connect(); //amp
  patchCord172.connect(); //amp
  patchCord173.connect(); //amp
  patchCord174.connect(); //amp
  patchCord175.connect(); //amp

  lfoA1.frequency(lfoAfreq);
  lfoAampMin = 0;
  lfoA1.offset(0);




} if (lfoAdest == 2) { //lfo - amp

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

  

  patchCord170.disconnect(); //amp - DC source to multiplier
  patchCord171.disconnect(); //amp
  patchCord172.disconnect(); //amp
  patchCord173.disconnect(); //amp
  patchCord174.disconnect(); //amp
  patchCord175.disconnect(); //amp

  patchCord12.connect(); //amp - lfo env to multiplier
  patchCord165.connect();
  patchCord166.connect();
  patchCord167.connect();
  patchCord168.connect();
  patchCord169.connect();

  //lfoA1.frequency(lfoAfreq/2.0); //half frequency when going to amp because reasons
  lfoA1.frequency(lfoAfreq);
  lfoA1.offset(0.5);
  lfoAampMin = 0.01;

}

//lfo A params
lfoA1.amplitude(lfoAamp + lfoAampMin);

lfoAenv1.attack(lfoAatt);
lfoAenv1.release(lfoArel);
lfoAenv2.attack(lfoAatt);
lfoAenv2.release(lfoArel);
lfoAenv3.attack(lfoAatt);
lfoAenv3.release(lfoArel);
lfoAenv4.attack(lfoAatt);
lfoAenv4.release(lfoArel);
lfoAenv5.attack(lfoAatt);
lfoAenv5.release(lfoArel);
lfoAenv6.attack(lfoAatt);
lfoAenv6.release(lfoArel);
