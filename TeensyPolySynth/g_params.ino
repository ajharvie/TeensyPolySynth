if (sinceMeasure > timer) {
  
  sinceMeasure = 0;
  
  mainVol = (float)mux0_1 / 4096;

  preset = mux5_3 / 190;
  
  if (preset == 0){ //all leds off
    digitalWrite(33, 0);
    digitalWrite(34, 0);
    digitalWrite(35, 0);
    digitalWrite(36, 0);
    digitalWrite(18, 0);
  }

  glideVal = mapf((float)mux1_1, 0, 1023, 1.0, 0.02);



  //chicken nuggets

  ///////////////  EDIT MODE EDIT ///////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (preset == 0) {

    //polyphony mode
    if (digitalRead(6) == 0) {
      polyMode = 0;
    } else if (digitalRead(6) == 1 && digitalRead(8) == 1) {
      polyMode = 1;
    } else if (digitalRead(8) == 0) {
      polyMode = 2;
    }

    if (digitalRead(10) == 0) {
      octaveB = 2;
    } else if (digitalRead(10) == 1 && digitalRead(19) == 1) {
      octaveB = 1;
    } else {
      octaveB = 0.5;
    }

    if (digitalRead(12) == 0) {
      octaveC = 2;
    } else if (digitalRead(12) == 1 && digitalRead(24) == 1) {
      octaveC = 1;
    } else {
      octaveC = 0.5;
    }


    if (digitalRead(2) == 0) {
      shapeA = 1;
    } else if (digitalRead(2) == 1 && digitalRead(3) == 1) {
      shapeA = 0;
    } else {
      shapeA = 2;
    }

    if (digitalRead(4) == 0) {
      shapeB = 1;
    } else if (digitalRead(4) == 1 && digitalRead(5) == 1) {
      shapeB = 0;
    } else  {
      shapeB = 2;
    }

    //Vco C shape
    shapeCpot = mux2_1;
    if (oldShapeCpot + 5 < shapeCpot || oldShapeCpot - 5 > shapeCpot || resetting == 1) {
      shapeC = mux2_1;
      oldShapeCpot = shapeCpot + tresh2 / 2;
    }


    //now with middle deadzone
    if (mux3_1 < 463){
      tuneB = mapf((float)mux3_1, 0, 462, -1.5, 0);
      tuneB = pow(2,(tuneB));
    }
    else if (mux3_1 >= 562){
      tuneB = mapf((float)mux3_1, 562, 1023, 0, 1.5);
      tuneB = pow(2,(tuneB));
    }
    else{
      tuneB = 1;
    }

    
    if (mux4_1 < 463){
      tuneC = mapf((float)mux4_1, 0, 462, -1.5, 0);
      tuneC = pow(2,(tuneC));
    }
    else if (mux4_1 > 562){
      tuneC = mapf((float)mux4_1, 563, 1023, 0, 1.5);
      tuneC = pow(2,(tuneC));
    }
    else{
      tuneC = 1;
    }



    crossMod = (float)mux5_1 / 2048;

    vcoAvol = (float)mux6_1 / 1023;
    vcoBvol = (float)mux7_1 / 1023;
    vcoCvol = (float)mux0_2 / 1023;
    Subvol = (float)mux1_2 / 1023;
    
    cutpot = mux2_2;
    if (oldCutpot + tresh3 < cutpot || oldCutpot - tresh3 > cutpot || resetting == 1) {
      //cut = 12000 * (float)mux2_2 / 1023 + 15;  
      cut = 12000 * expLookup1024[mux2_2] / 1023 + 15;  //cut
      oldCutpot = cutpot + tresh3 / 2;
    }

    //cut = (12000 * (float)mux2_2 / 1023) + 15;
    res = (4.5 * (float)mux3_2 / 1023) + 1.1;

   

    filtAtt = (3000 * expLookup1024[mux0_0] / 1023) + minTime; //now exponential!!
    filtDec = (3000 * expLookup1024[mux1_0] / 1023) + minTime;
    
    if (mux2_0 >= 590){
      filtAmt = mapf((float)mux2_0, 590, 1023, 0.01, 1);
    }
    else if(mux2_0 <= 450){
      filtAmt = mapf((float)mux2_0, 0, 450, -1, 0);
    }
    else{
      filtAmt = 0;
    }


    
    if (digitalRead(25) == 0) {//low pass
      filterMode = 1;
    } 
    else if (digitalRead(25) == 1 && digitalRead(26) == 1) {//band pass
      filterMode = 0;
    }
    else  { //high pass
      filterMode = 2;
    }

    envAtt = 3000 * expLookup1024[mux4_2] / 1023 + minTime;
    envDec = 5000 * expLookup1024[mux5_2] / 1023 + minTime;
    envRel = 5000 * expLookup1024[mux5_2] / 1023 + minTime;
    
    envSus = (float)mux6_2 / 1024;

    if (lfoAdest == 0 && lfoAshape != 2) {
      lfoAamp = ((float)mux3_0 / 1024) / 10;
    } else {
      lfoAamp = ((float)mux3_0 / 1024) / 3;
    }

    lfoAfreq = lfoAMaxFreq * expLookup1024[mux4_0] / 10240 + 1;
    lfoAatt = 3000 * expLookup1024[mux5_0] / 1024 + minTime;
    lfoArel = 4000 * expLookup1024[mux6_0]/ 1024 + minTime;


    if (digitalRead(27) == 0) { //lfo - pitch
      lfoAdest = 0;
    } else if ( digitalRead(27) == 1 && digitalRead(28) == 1) { //lfo - filter
      lfoAdest = 1;
    } else { //lfo - amp
      lfoAdest = 2;
    }

    if (digitalRead(29) == 0) { //sine
      lfoAshape = 0;
    } else if ( digitalRead(29) == 1 && digitalRead(30) == 1) { //ramp
      lfoAshape = 1;
    } else { //random "s&h"
      lfoAshape = 2;
    }

    lfoBamp = (float)mux6_3 / 1023;
    lfoBfreq = lfoBMaxFreq * expLookup1024[mux0_3] / 1023 + 0.1; //exponential now oooooo
    
    if (mux0_3 > lfoBSnapKnobThresh){ //check if it should snap to osc C frequency
      lfoBSnap = 1;
    }
    else{
      lfoBSnap = 0;
    }

    dlyAmt = (float)mux1_3 / 1100 - 0.1;
    
    dlyTimepot = mux2_3;
    if (oldDlyTimepot + tresh2 < dlyTimepot || oldDlyTimepot - tresh2 > dlyTimepot || resetting == 1) {
      dlyTimeL = mux2_3 / 2;
      dlyTimeR = mux2_3;
      oldDlyTimepot = dlyTimepot + tresh2 / 2;
    }



    
    revMix = (((float)mux3_3 / 1024) / 5);
    revSize = ((float)mux4_3 / 1024 - 0.01);

    

    if (dlyAmt < 0) {
      dlyAmt = 0;
    }

    resetting = 0;


  } else {



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // PRESET MODE ///////// PRESET MODE //////// PRESET MODE //////////// PRESET MODE /////// PRESET MODE ////
    // PRESET MODE ///////// PRESET MODE //////// PRESET MODE //////////// PRESET MODE /////// PRESET MODE ////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////  OCTAVES OCTAVES //////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    //or check for pressed "read controls/reset" button. when reset button pressed, values should take those as read on controls

    resetting = 1; //for properly resetting things to knob position on return to preset 0/non memory mode

    resetPressed = digitalRead(32);

     //glide
    glidePot = mux1_1;
    if (oldGlidePot + tresh2 < glidePot || oldGlidePot - tresh2 > glidePot || resetPressed == 0) {
      glideVal = mapf((float)mux1_1, 0, 1023, 0.02, 1.0);
      oldGlidePot = glidePot + tresh2 / 2;
      //Serial.println("shape C turn");
    }

     //poly mode 
    if (digitalRead(6) == 0) {
      polyModesw = 0;
    } else if (digitalRead(6) == 1 && digitalRead(8) == 1) {
      polyModesw = 1;
    } else {
      polyModesw = 2;
    }
    if (oldPolyModesw < polyModesw || oldPolyModesw > polyModesw || resetPressed == 0) {
      oldPolyModesw = polyModesw;
      polyMode = polyModesw;
    }

    
    if (digitalRead(10) == 0) {
      octBsw = 2;
    } else if (digitalRead(10) == 1 && digitalRead(19) == 1) {
      octBsw = 1;
    } else{
      octBsw = 0.5;
    }
    if (oldOctBsw < octBsw || oldOctBsw > octBsw || resetPressed == 0) {
      oldOctBsw = octBsw;
      octaveB = octBsw;
      //Serial.println("octave B switch");
    }



    //octave vco C
    if (digitalRead(12) == 0) {
      octCsw = 2;
    } else if (digitalRead(12) == 1 && digitalRead(24) == 1) {
      octCsw = 1;
    } else{
      octCsw = 0.5;
    }
    if (oldOctCsw < octCsw || oldOctCsw > octCsw || resetPressed == 0) {

      octaveC = octCsw;
      oldOctCsw = octCsw;
      //Serial.println("octave C switch");
    }

    //////////// SHAPES SHAPES ////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Shape A
    if (digitalRead(2) == 0) {
      shapeAsw = 1;
    } else if (digitalRead(2) == 1 && digitalRead(3) == 1) {
      shapeAsw = 0;
    } else{
      shapeAsw = 2;
    }
    if (oldShapeAsw < shapeAsw || oldShapeAsw > shapeAsw || resetPressed == 0) {

      oldShapeAsw = shapeAsw;
      shapeA = shapeAsw;
      //Serial.println("shape A switch");
    }



    //Shape B
    if (digitalRead(4) == 0) {
      shapeBsw = 1;
    } else if (digitalRead(4) == 1 && digitalRead(5) == 1) {
      shapeBsw = 0;
    } else{
      shapeBsw = 2;
    }
    if (oldShapeBsw < shapeBsw || oldShapeBsw > shapeBsw || resetPressed == 0) {

      shapeB = shapeBsw;
      oldShapeBsw = shapeBsw;
      //Serial.println("shape B switch");
    }




    //Vco C shape
    shapeCpot = mux2_1;
    if(firstBoot == true){
      oldShapeCpot = shapeCpot + tresh3 / 2;
    }
    
    if (oldShapeCpot + tresh3 < shapeCpot || oldShapeCpot - tresh3 > shapeCpot || resetPressed == 0) {
      ++shapeCCount;
    }
    else{
      shapeCCount = 0;
    }
    if (shapeCCount > threshCounts){
      shapeC = mux2_1;
      oldShapeCpot = shapeCpot + tresh3 / 2;
      shapeCCount = 0;
      //Serial.println("shape C turn");
    }




    /////////// TUNINGS TUNINGS //////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    //tuneB
    tuneBpot = mux3_1;
    if(firstBoot == true){
      oldTuneBpot = tuneBpot + tresh3 / 2;
    }
    if (oldTuneBpot + tresh3 < tuneBpot || oldTuneBpot - tresh3 > tuneBpot || resetPressed == 0) {
      ++tuneBCount;
    }
    else{
      tuneBCount = 0;
    }
    if (tuneBCount > threshCounts){
      //now with middle deadzone
      if (mux3_1 < 463){
        tuneB = mapf((float)mux3_1, 0, 462, -1.5, 0);
        tuneB = pow(2,(tuneB));
      }
      else if (mux3_1 > 562){
        tuneB = mapf((float)mux3_1, 563, 1023, 0, 1.5);
        tuneB = pow(2,(tuneB));
      }
      else{
        tuneB = 1;
      }
    
      oldTuneBpot = tuneBpot + tresh3 / 2;
      tuneBCount = 0;
      //Serial.println("tuneB turn");
    }

    //tuneC
    tuneCpot = mux4_1;
    if(firstBoot == true){
      oldTuneCpot = tuneCpot + tresh3 / 2;
    }
    
    if (oldTuneCpot + tresh3 < tuneCpot || oldTuneCpot - tresh3 > tuneCpot || resetPressed == 0) {
      ++tuneCCount;
    }
    else{
      tuneCCount = 0;
    }
    if (tuneCCount > threshCounts){
      
      if (mux4_1 < 463){
        tuneC = mapf((float)mux4_1, 0, 462, -1.5, 0);
        tuneC = pow(2,(tuneC));
      }
      else if (mux4_1 > 562){
        tuneC = mapf((float)mux4_1, 563, 1023, 0, 1.5);
        tuneC = pow(2,(tuneC));
      }
      else{
        tuneC = 1;
      }
      oldTuneCpot = tuneCpot + tresh3 / 2;
      tuneCCount = 0;
      //Serial.println("tuneC turn");
    }

    //Cross mod
    crossModpot = mux5_1;
    if (oldCrossModpot + tresh < crossModpot || oldCrossModpot - tresh > crossModpot || resetPressed == 0) {
      crossMod = (float)mux5_1 / 2048;
      oldCrossModpot = crossModpot + tresh / 2;
      //Serial.println("crossmod turn");
    }




    ///////////// VOLUMES VOLUMES /////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    volApot = mux6_1;
    if (oldVolApot + tresh2 < volApot || oldVolApot - tresh2 > volApot || resetPressed == 0) {
      vcoAvol = (float)mux6_1 / 1023;
      oldVolApot = volApot + tresh2 / 2;
      //Serial.println("volA turn");
    }


    volBpot = mux7_1;
    if (oldVolBpot + tresh2 < volBpot || oldVolBpot - tresh2 > volBpot || resetPressed == 0) {
      vcoBvol = (float)mux7_1 / 1023;
      oldVolBpot = volBpot + tresh2 / 2;
      //Serial.println("volB turn");
    }

    volCpot = mux0_2;
    if (oldVolCpot + tresh2 < volCpot || oldVolCpot - tresh2 > volCpot || resetPressed == 0) {
      vcoCvol = (float)mux0_2 / 1023;
      oldVolCpot = volCpot + tresh2 / 2;
      //Serial.println("volC turn");
    }

    volSubpot = mux1_2;
    if (oldVolSubpot + tresh2 < volSubpot || oldVolSubpot - tresh2 > volSubpot || resetPressed == 0) {
      Subvol = (float)mux1_2 / 1023;
      oldVolSubpot = volSubpot + tresh2 / 2;
      //Serial.println("vol sub turn");
    }

    //////////// FILTER FILTER ////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Filter
    cutpot = mux2_2;
    if(firstBoot == true){
      oldCutpot = cutpot + tresh3 / 2;
    }
    
    if (oldCutpot + tresh3 < cutpot || oldCutpot - tresh3 > cutpot || resetPressed == 0) {
      ++cutCount;
    }
    else{
      cutCount = 0;
    }
    if (cutCount > threshCounts){  
      
      //cut = 12000 * (float)mux2_2 / 1023 + 15;          //cut
      cut = 12000 * expLookup1024[mux2_2] / 1023 + 15;  //cut
      oldCutpot = cutpot + tresh3 / 2;
      cutCount = 0;
      //Serial.println("cut turn");
    }

    respot = mux3_2;
    if (oldRespot + tresh2 < respot || oldRespot - tresh2 > respot || resetPressed == 0) {
      res = (4.5 * (float)mux3_2 / 1023) + 1.1;
      oldRespot = respot + tresh2 / 2;
      //Serial.println("res turn");
    }

    //Filter Env

    fAttpot = mux0_0;
    if (oldFAttpot + tresh2 < fAttpot || oldFAttpot - tresh2 > fAttpot || resetPressed == 0) {
      filtAtt = (3000 * expLookup1024[mux0_0] / 1023) + minTime;
      oldFAttpot = fAttpot + tresh2 / 2;
      //Serial.println("filter attack turn");
    }

    fDecpot = mux1_0;
    if (oldFDecpot + tresh2 < fDecpot || oldFDecpot - tresh2 > fDecpot || resetPressed == 0) {
      filtDec = (3000 * expLookup1024[mux1_0] / 1023) + minTime;
      oldFDecpot = fDecpot + tresh2 / 2;
      //Serial.println("filter decay turn");
    }

    fAmtpot = mux2_0;
    if (oldFAmtpot + tresh2 < fAmtpot || oldFAmtpot - tresh2 > fAmtpot || resetPressed == 0) {
      if (mux2_0 >= 590){
        filtAmt = mapf((float)mux2_0, 590, 1023, 0.01, 1);
      }
      else if(mux2_0 <= 450){
        filtAmt = mapf((float)mux2_0, 0, 450, -1, 0);
      }
      else{
        filtAmt = 0;
      }
      oldFAmtpot = fAmtpot + tresh2 / 2;
      //Serial.println("filter Amt turn");
    }



    //FilterMode
    if (digitalRead(25) == 0) {
      filtModesw = 1;
    } else if (digitalRead(25) == 1 && digitalRead(26) == 1) {
      filtModesw = 0;
    } else{
      filtModesw = 2;
    }
    if (oldFiltModesw < filtModesw || oldFiltModesw > filtModesw  || resetPressed == 0) {
      oldFiltModesw = filtModesw;
      filterMode = filtModesw;
    }


    /////////////// MAIN ENVELOPE ////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    attpot = mux4_2;
    if (oldAttpot + tresh2 < attpot || oldAttpot - tresh2 > attpot || resetPressed == 0) {
      envAtt = 3000 * expLookup1024[mux4_2] / 1023 + minTime;
      oldAttpot = attpot + tresh2 / 2;
      //Serial.println("Attack turn");
    }

    decpot = mux5_2;
    if (oldDecpot + tresh2 < decpot || oldDecpot - tresh2 > decpot || resetPressed == 0) {
      envDec = 5000 * expLookup1024[mux5_2] / 1023 + minTime;
      envRel = 5000 * expLookup1024[mux5_2] / 1023 + minTime;
      oldDecpot = decpot + tresh2 / 2;
      //Serial.println("Decay turn");
    }

    suspot = mux6_2;
    if (oldSuspot + tresh2 < suspot || oldSuspot - tresh2 > suspot || resetPressed == 0) {
      envSus = (float)mux6_2 / 1024;
      oldSuspot = suspot + tresh2 / 2;
      //Serial.println("Sustain turn");
    }





    ////////////// LFO A   LFO A  /////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    lfoAmppot = mux3_0;
    if (oldLfoAmppot + tresh2 < lfoAmppot || oldLfoAmppot - tresh2 > lfoAmppot || resetPressed == 0) {
      if (lfoAdest == 0 && lfoAshape != 2) {
        lfoAamp = (float)mux3_0 / 1024 / 10;
      } else {
        lfoAamp = (float)mux3_0 / 1024 / 3;
      }
      oldLfoAmppot = lfoAmppot + tresh2 / 2;
      //Serial.println("Lfo A amp turn");
    }

    lfoFreqpot = mux4_0;
    if (oldLfoFreqpot + tresh2 < lfoFreqpot || oldLfoFreqpot - tresh2 > lfoFreqpot || resetPressed == 0) {
      lfoAfreq = lfoAMaxFreq * expLookup1024[mux4_0] / 10240 + 1;
      oldLfoFreqpot = lfoFreqpot + tresh2 / 2;
      //Serial.println("Lfo A Freq turn");
    }

    lfoAttpot = mux5_0;
    if (oldLfoAttpot + tresh2 < lfoAttpot || oldLfoAttpot - tresh2 > lfoAttpot || resetPressed == 0) {
      lfoAdel = 1;
      lfoAatt = 3000 * expLookup1024[mux5_0] / 1024 + minTime;
      oldLfoAttpot = lfoAttpot + tresh2 / 2;
      //Serial.println("Lfo A Att turn");
    }

    lfoDecpot = mux6_0;
    if (oldLfoDecpot + tresh2 < lfoDecpot || oldLfoDecpot - tresh2 > lfoDecpot || resetPressed == 0) {
      //lfoAdec = 4000 * (float)mux6_0 / 1024;      
      lfoAdec = 1; //no need for decay now, just release
      lfoArel = 4000 * expLookup1024[mux6_0] / 1024 + minTime;
      oldLfoDecpot = lfoDecpot + (tresh2 / 2);
      //Serial.println("Lfo A Dec turn");
    }



    //lfoA destination
    if (digitalRead(27) == 0) { //lfo - pitch
      lfoDestsw = 0;
    } else if ( digitalRead(27) == 1 && digitalRead(28) == 1) { //lfo - filter
      lfoDestsw = 1;
    } else{ //lfo - amp
      lfoDestsw = 2;
    }
    if (oldLfoDestsw < lfoDestsw || oldLfoDestsw > lfoDestsw || resetPressed == 0) {

      lfoAdest = lfoDestsw;
      oldLfoDestsw = lfoDestsw;
      //Serial.println("Lfo dest switch");
    }



    //lfoA shape
    if (digitalRead(29) == 0) {
      lfoShapesw = 0;
    } else if ( digitalRead(29) == 1 && digitalRead(30) == 1) {
      lfoShapesw = 1;
    } else{
      lfoShapesw = 2;
    }

    if (oldLfoShapesw < lfoShapesw || oldLfoShapesw > lfoShapesw || resetPressed == 0) {

      lfoAshape = lfoShapesw;
      oldLfoShapesw = lfoShapesw;
      //Serial.println("Lfo shape switch");
    }



    ///////////// LFO B    LFO B //////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    lfoBAmppot = mux6_3;
    if (oldLfoBAmppot + tresh2 < lfoBAmppot || oldLfoBAmppot - tresh2 > lfoBAmppot || resetPressed == 0) {
      lfoBamp = (float)mux6_3 / 1023;
      oldLfoBAmppot = lfoBAmppot + tresh2 / 2;
      //Serial.println("Lfo B amp turn");
    }

    lfoBFreqpot = mux0_3;
    if (oldLfoBFreqpot + tresh2 < lfoBFreqpot || oldLfoBFreqpot - tresh2 > lfoBFreqpot || resetPressed == 0) {
      lfoBfreq = lfoAMaxFreq * expLookup1024[mux0_3] / 1023 + 0.1;
      oldLfoBFreqpot = lfoBFreqpot + tresh2 / 2;
      //Serial.println("Lfo B freq turn");
    }


    if (mux0_3 > lfoBSnapKnobThresh){ 
      lfoBSnapsw = 1; //pretend it's a switch like the others because why not
    }
    else{
      lfoBSnapsw = 0;
    }
    if (lfoBSnapsw != oldlfoBSnapsw || resetPressed == 0){
      oldlfoBSnapsw = lfoBSnapsw;
      lfoBSnap = lfoBSnapsw;  
    }



    //////////////// FX FX FX FX //////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Delay
    dlyAmtpot = mux1_3;
    if (oldDlyAmtpot + tresh2 < dlyAmtpot || oldDlyAmtpot - tresh2 > dlyAmtpot || resetPressed == 0) {
      dlyAmt = (float)mux1_3 / 1100 - 0.1;
      if (dlyAmt < 0) {
        dlyAmt = 0;
      }
      oldDlyAmtpot = dlyAmtpot + tresh2 / 2;
      //Serial.println("Dly amt turn");
    }


    dlyTimepot = mux2_3;
    if (oldDlyTimepot + tresh2 < dlyTimepot || oldDlyTimepot - tresh2 > dlyTimepot || resetPressed == 0) {
      dlyTimeL = mux2_3 / 2;
      dlyTimeR = mux2_3;
      oldDlyTimepot = dlyTimepot + tresh2 / 2;
      //Serial.println("Dly time turn");
    }



    //Reverb
    revMixpot = mux3_3;
    if (oldRevMixpot + tresh2 < revMixpot || oldRevMixpot - tresh2 > revMixpot || resetPressed == 0) {
      revMix = ((float)mux3_3 / 1024 / 10);
      oldRevMixpot = revMixpot + tresh2 / 2;
      //Serial.println("Rev mix turn");
    }


    revSizepot = mux4_3;
    if (oldRevSizepot + tresh2 < revSizepot || oldRevSizepot - tresh2 > revSizepot || resetPressed == 0) {
      revSize = ((float)mux4_3 / 1024 - 0.01);
      oldRevSizepot = revSizepot + tresh2 / 2;
      //Serial.println("Rev size turn");
    }
  }
  firstBoot = false;
}
