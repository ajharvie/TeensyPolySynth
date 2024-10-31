//Multiplexer read
digitalWrite(37, 0); //A
digitalWrite(38, 0); //B
digitalWrite(39, 0); //C
delayMicroseconds(wait);
mux0_0 = analogRead(muxPots0);//filtAtt
mux0_1 = analogRead(muxPots1);//mainVol
mux0_2 = analogRead(muxPots2);//VCOCVol
mux0_3 = analogRead(muxPots3);//lfoBrate



digitalWrite(37, 1);
digitalWrite(38, 0);
digitalWrite(39, 0);
delayMicroseconds(wait);
mux1_0 = analogRead(muxPots0);//filtDec
mux1_1 = analogRead(muxPots1);//bend now portamento
mux1_2 = analogRead(muxPots2);//SubVol
mux1_3 = analogRead(muxPots3);//dlyAmt



digitalWrite(37, 0);
digitalWrite(38, 1);
digitalWrite(39, 0);
delayMicroseconds(wait);
mux2_0 = analogRead(muxPots0);//filtEnvAm
mux2_1 = analogRead(muxPots1);//shapeC
mux2_2 = analogRead(muxPots2);//cut
mux2_3 = analogRead(muxPots3);//dlyTime



digitalWrite(37, 1);
digitalWrite(38, 1);
digitalWrite(39, 0);
delayMicroseconds(wait);
mux3_0 = analogRead(muxPots0);//lfoADepth
mux3_1 = analogRead(muxPots1);//tuneB
mux3_2 = analogRead(muxPots2);//res
mux3_3 = analogRead(muxPots3);//revMix


digitalWrite(37, 0);
digitalWrite(38, 0);
digitalWrite(39, 1);
delayMicroseconds(wait);
mux4_0 = analogRead(muxPots0);//lfoARate
mux4_1 = analogRead(muxPots1);//tuneC
mux4_2 = analogRead(muxPots2);//envAtt
mux4_3 = analogRead(muxPots3);//revSize


digitalWrite(37, 1);
digitalWrite(38, 0);
digitalWrite(39, 1);
delayMicroseconds(wait);
mux5_0 = analogRead(muxPots0);//lfoAAtt
mux5_1 = analogRead(muxPots1);//crossMod
mux5_2 = analogRead(muxPots2);//envDec
mux5_3 = analogRead(muxPots3);//preset


digitalWrite(37, 0);
digitalWrite(38, 1);
digitalWrite(39, 1);
delayMicroseconds(wait);
mux6_0 = analogRead(muxPots0);//lfoADec
mux6_1 = analogRead(muxPots1);//VCOAVol
mux6_2 = analogRead(muxPots2);//envSus
mux6_3 = analogRead(muxPots3);//lfoBDepth new


digitalWrite(37, 1);
digitalWrite(38, 1);
digitalWrite(39, 1);
delayMicroseconds(wait);
mux7_0 = analogRead(muxPots0);//freed up now - no longer using lfoA sustain
mux7_1 = analogRead(muxPots1);//VCOBVol
mux7_2 = analogRead(muxPots2);//
mux7_3 = analogRead(muxPots3);//
