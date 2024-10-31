/////////// WRITE PRESETS ///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


if (saveButton.update()){
  if(saveButton.fallingEdge()){
    savePressed = 0;
  }
  else{
    savePressed = 1;
  }
}
else{
  savePressed = 1;
}
  

///////// PRESET 1 ////////////////////////////////////////////////////////////////
if (savePressed == 0 && prevBtn1 == 0 && preset == 1) {
  //write params
  EEPROM.updateInt(0, polyMode);
  EEPROM.updateFloat(5, octaveB);
  EEPROM.updateFloat(10, octaveC);
  EEPROM.updateInt(15, shapeA);
  EEPROM.updateInt(20, shapeB);
  EEPROM.updateInt(25, shapeC);
  EEPROM.updateFloat(30, tuneB);
  EEPROM.updateFloat(35, tuneC);
  EEPROM.updateFloat(40, crossMod);
  EEPROM.updateFloat(45, vcoAvol);
  EEPROM.updateFloat(50, vcoBvol);
  EEPROM.updateFloat(55, vcoCvol);
  EEPROM.updateFloat(60, Subvol);
  EEPROM.updateInt(65, cut);
  EEPROM.updateFloat(70, res);
  EEPROM.updateInt(75, filtAtt);
  EEPROM.updateInt(80, filtDec);
  EEPROM.updateFloat(85, filtAmt);
  EEPROM.updateInt(90, filterMode);
  EEPROM.updateInt(95, envAtt);
  EEPROM.updateInt(100, envDec);
  EEPROM.updateInt(105, envRel);  
  EEPROM.updateFloat(110, envSus);  
  EEPROM.updateFloat(115, lfoAamp);
  EEPROM.updateFloat(120, lfoAfreq);
  EEPROM.updateInt(125, lfoAdel);
  EEPROM.updateInt(130, lfoAatt);
  EEPROM.updateInt(135, lfoAdec);
  EEPROM.updateInt(140, lfoArel);
  EEPROM.updateFloat(145, glideVal); 
  EEPROM.updateFloat(150, lfoBamp);
  EEPROM.updateFloat(155, lfoBfreq);
  EEPROM.updateFloat(160, dlyAmt);
  EEPROM.updateFloat(165, dlyTimeL);
  EEPROM.updateByte(170, lfoBSnap);  
  EEPROM.updateFloat(175, revMix);
  EEPROM.updateFloat(180, revSize);
  EEPROM.updateFloat(185, lfoAdest);
  EEPROM.updateFloat(190, lfoAshape);

 for (int i = 0; i <= 3; i++) { //flash the lights a bit. for fun
    digitalWrite(33, 0);
    delay(100);
    digitalWrite(33, 1);
    delay(100);
  }

  prevBtn1 = 1;

} else if (savePressed == 1 && preset == 1) {
  prevBtn1 = 0;
}

///////  PRESET 2 ///////////////////////////////////////////////////
if (savePressed == 0 && prevBtn2 == 0 && preset == 2) {
  //write params
  EEPROM.updateInt(200, polyMode);
  EEPROM.updateFloat(205, octaveB);
  EEPROM.updateFloat(210, octaveC);
  EEPROM.updateInt(215, shapeA);
  EEPROM.updateInt(220, shapeB);
  EEPROM.updateInt(225, shapeC);
  EEPROM.updateFloat(230, tuneB);
  EEPROM.updateFloat(235, tuneC);
  EEPROM.updateFloat(240, crossMod);
  EEPROM.updateFloat(245, vcoAvol);
  EEPROM.updateFloat(250, vcoBvol);
  EEPROM.updateFloat(255, vcoCvol);
  EEPROM.updateFloat(260, Subvol);
  EEPROM.updateInt(265, cut);
  EEPROM.updateFloat(270, res);
  EEPROM.updateInt(275, filtAtt);
  EEPROM.updateInt(280, filtDec);
  EEPROM.updateFloat(285, filtAmt);
  EEPROM.updateInt(290, filterMode);
  EEPROM.updateInt(295, envAtt);
  EEPROM.updateInt(300, envDec);
  EEPROM.updateInt(305, envRel);
  EEPROM.updateFloat(310, envSus);
  EEPROM.updateFloat(315, lfoAamp);
  EEPROM.updateFloat(320, lfoAfreq);
  EEPROM.updateInt(325, lfoAdel);
  EEPROM.updateInt(330, lfoAatt);
  EEPROM.updateInt(335, lfoAdec);
  EEPROM.updateInt(340, lfoArel);
  EEPROM.updateFloat(345, glideVal); 
  EEPROM.updateFloat(350, lfoBamp);
  EEPROM.updateFloat(355, lfoBfreq);
  EEPROM.updateFloat(360, dlyAmt);
  EEPROM.updateFloat(365, dlyTimeL);
  EEPROM.updateByte(370, lfoBSnap); 
  EEPROM.updateFloat(375, revMix);
  EEPROM.updateFloat(380, revSize);
  EEPROM.updateFloat(385, lfoAdest);
  EEPROM.updateFloat(390, lfoAshape);

  prevBtn2 = 1;
  
  for (int i = 0; i <= 3; i++) { //flash the lights a bit. for fun
    digitalWrite(34, 0);
    delay(100);
    digitalWrite(34, 1);
    delay(100);
  }

} else if (savePressed == 1 && preset == 2) {
  prevBtn2 = 0;
}


///////// PRESET 3 ////////////////////////////////////////////////////////////////
if (savePressed == 0 && prevBtn3 == 0 && preset == 3) {
  //write params
  EEPROM.updateInt(400, polyMode);
  EEPROM.updateFloat(405, octaveB);
  EEPROM.updateFloat(410, octaveC);
  EEPROM.updateInt(415, shapeA);
  EEPROM.updateInt(420, shapeB);
  EEPROM.updateInt(425, shapeC);
  EEPROM.updateFloat(430, tuneB);
  EEPROM.updateFloat(435, tuneC);
  EEPROM.updateFloat(440, crossMod);
  EEPROM.updateFloat(445, vcoAvol);
  EEPROM.updateFloat(450, vcoBvol);
  EEPROM.updateFloat(455, vcoCvol);
  EEPROM.updateFloat(460, Subvol);
  EEPROM.updateInt(465, cut);
  EEPROM.updateFloat(470, res);
  EEPROM.updateInt(475, filtAtt);
  EEPROM.updateInt(480, filtDec);
  EEPROM.updateFloat(485, filtAmt);
  EEPROM.updateInt(490, filterMode);
  EEPROM.updateInt(495, envAtt);
  EEPROM.updateInt(500, envDec);
  EEPROM.updateInt(505, envRel);
  EEPROM.updateFloat(510, envSus);
  EEPROM.updateFloat(515, lfoAamp);
  EEPROM.updateFloat(520, lfoAfreq);
  EEPROM.updateInt(525, lfoAdel);
  EEPROM.updateInt(530, lfoAatt);
  EEPROM.updateInt(535, lfoAdec);
  EEPROM.updateInt(540, lfoArel);
  EEPROM.updateFloat(545, glideVal); 
  EEPROM.updateFloat(550, lfoBamp);
  EEPROM.updateFloat(555, lfoBfreq);
  EEPROM.updateFloat(560, dlyAmt);
  EEPROM.updateFloat(565, dlyTimeL);
  EEPROM.updateByte(570, lfoBSnap);
  EEPROM.updateFloat(575, revMix);
  EEPROM.updateFloat(580, revSize);
  EEPROM.updateFloat(585, lfoAdest);
  EEPROM.updateFloat(590, lfoAshape);
  
  prevBtn3 = 1;

  for (int i = 0; i <= 3; i++) { //flash the lights a bit. for fun
    digitalWrite(35, 0);
    delay(100);
    digitalWrite(35, 1);
    delay(100);
  }

} else if (savePressed == 1 && preset == 3) {
  prevBtn3 = 0;
}


///////// PRESET 4 ////////////////////////////////////////////////////////////////
if (savePressed == 0 && prevBtn4 == 0 && preset == 4) {
  //write params
  EEPROM.updateInt(600, polyMode);
  EEPROM.updateFloat(605, octaveB);
  EEPROM.updateFloat(610, octaveC);
  EEPROM.updateInt(615, shapeA);
  EEPROM.updateInt(620, shapeB);
  EEPROM.updateInt(625, shapeC);
  EEPROM.updateFloat(630, tuneB);
  EEPROM.updateFloat(635, tuneC);
  EEPROM.updateFloat(640, crossMod);
  EEPROM.updateFloat(645, vcoAvol);
  EEPROM.updateFloat(650, vcoBvol);
  EEPROM.updateFloat(655, vcoCvol);
  EEPROM.updateFloat(660, Subvol);
  EEPROM.updateInt(665, cut);
  EEPROM.updateFloat(670, res);
  EEPROM.updateInt(675, filtAtt);
  EEPROM.updateInt(680, filtDec);
  EEPROM.updateFloat(685, filtAmt);
  EEPROM.updateInt(690, filterMode);
  EEPROM.updateInt(695, envAtt);
  EEPROM.updateInt(700, envDec);
  EEPROM.updateInt(705, envRel);
  EEPROM.updateFloat(710, envSus);
  EEPROM.updateFloat(715, lfoAamp);
  EEPROM.updateFloat(720, lfoAfreq);
  EEPROM.updateInt(725, lfoAdel);
  EEPROM.updateInt(730, lfoAatt);
  EEPROM.updateInt(735, lfoAdec);
  EEPROM.updateInt(740, lfoArel);
  EEPROM.updateFloat(745, glideVal);  
  EEPROM.updateFloat(750, lfoBamp);
  EEPROM.updateFloat(755, lfoBfreq);
  EEPROM.updateFloat(760, dlyAmt);
  EEPROM.updateFloat(765, dlyTimeL);
  EEPROM.updateByte(770, lfoBSnap);  
  EEPROM.updateFloat(775, revMix);  
  EEPROM.updateFloat(780, revSize);
  EEPROM.updateFloat(785, lfoAdest);
  EEPROM.updateFloat(790, lfoAshape);


  prevBtn4 = 1;
  for (int i = 0; i <= 3; i++) { //flash the lights a bit. for fun
    digitalWrite(36, 0);
    delay(100);
    digitalWrite(36, 1);
    delay(100);
  }

} else if (savePressed == 1 && preset == 4) {
  prevBtn4 = 0;
}




///////// PRESET 5 ////////////////////////////////////////////////////////////////
if (savePressed == 0 && prevBtn5 == 0 && preset == 5) {
  //write params
  EEPROM.updateInt(800, polyMode);
  EEPROM.updateFloat(805, octaveB);
  EEPROM.updateFloat(810, octaveC);
  EEPROM.updateInt(815, shapeA);
  EEPROM.updateInt(820, shapeB);
  EEPROM.updateInt(825, shapeC);
  EEPROM.updateFloat(830, tuneB);
  EEPROM.updateFloat(835, tuneC);
  EEPROM.updateFloat(840, crossMod);
  EEPROM.updateFloat(845, vcoAvol);
  EEPROM.updateFloat(850, vcoBvol);
  EEPROM.updateFloat(855, vcoCvol);
  EEPROM.updateFloat(860, Subvol);
  EEPROM.updateInt(865, cut);
  EEPROM.updateFloat(870, res);
  EEPROM.updateInt(875, filtAtt);
  EEPROM.updateInt(880, filtDec);
  EEPROM.updateFloat(885, filtAmt);
  EEPROM.updateInt(890, filterMode);
  EEPROM.updateInt(895, envAtt);
  EEPROM.updateInt(900, envDec);
  EEPROM.updateInt(905, envRel);
  EEPROM.updateFloat(910, envSus);
  EEPROM.updateFloat(915, lfoAamp);
  EEPROM.updateFloat(920, lfoAfreq);
  EEPROM.updateInt(925, lfoAdel);
  EEPROM.updateInt(930, lfoAatt);
  EEPROM.updateInt(935, lfoAdec);
  EEPROM.updateInt(940, lfoArel);
  EEPROM.updateFloat(945, glideVal); 
  EEPROM.updateFloat(950, lfoBamp);
  EEPROM.updateFloat(955, lfoBfreq);
  EEPROM.updateFloat(960, dlyAmt);
  EEPROM.updateFloat(965, dlyTimeL);
  EEPROM.updateByte(970, lfoBSnap);  
  EEPROM.updateFloat(975, revMix);
  EEPROM.updateFloat(980, revSize);
  EEPROM.updateFloat(985, lfoAdest);
  EEPROM.updateFloat(990, lfoAshape);

  prevBtn5 = 1;
  for (int i = 0; i <= 3; i++) { //flash the lights a bit. for fun
    digitalWrite(18, 0);
    delay(100);
    digitalWrite(18, 1);
    delay(100);
  }

} else if (savePressed == 1 && preset == 5) {
  prevBtn5 = 0;
}





/////////// READ PRESETS ///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

/////////// PRESET 1 ////////////////////////////////////////////////////
if (preset == 1 && presetLoaded1 == 0) {
  //read params
  polyMode = EEPROM.readInt(0);
  octaveB = EEPROM.readFloat(5);
  octaveC = EEPROM.readFloat(10);
  shapeA = EEPROM.readInt(15);
  shapeB = EEPROM.readInt(20);
  shapeC = EEPROM.readInt(25);
  tuneB = EEPROM.readFloat(30);
  tuneC = EEPROM.readFloat(35);
  crossMod = EEPROM.readFloat(40);
  vcoAvol = EEPROM.readFloat(45);
  vcoBvol = EEPROM.readFloat(50);
  vcoCvol = EEPROM.readFloat(55);
  Subvol = EEPROM.readFloat(60);
  cut = EEPROM.readInt(65);
  res = EEPROM.readFloat(70);
  filtAtt = EEPROM.readInt(75);
  filtDec = EEPROM.readInt(80);
  filtAmt = EEPROM.readFloat(85);
  filterMode = EEPROM.readInt(90);
  envAtt = EEPROM.readInt(95);
  envDec = EEPROM.readInt(100);
  envRel = EEPROM.readInt(105);
  envSus = EEPROM.readFloat(110);
  lfoAamp = EEPROM.readFloat(115);
  lfoAfreq = EEPROM.readFloat(120);
  lfoAdel = EEPROM.readInt(125);
  lfoAatt = EEPROM.readInt(130);
  lfoAdec = EEPROM.readInt(135);
  lfoArel = EEPROM.readInt(140);
  lfoAsus = EEPROM.readFloat(145);
  glideVal = EEPROM.readFloat(145);
  lfoBamp = EEPROM.readFloat(150);
  lfoBfreq = EEPROM.readFloat(155);
  dlyAmt = EEPROM.readFloat(160);
  dlyTimeL = EEPROM.readFloat(165);
  dlyTimeR = 2*dlyTimeL;
  lfoBSnap = EEPROM.readByte(170);
  revMix = EEPROM.readFloat(175);
  revSize = EEPROM.readFloat(180);
  lfoAdest = EEPROM.readFloat(185);
  lfoAshape = EEPROM.readFloat(190);

  presetLoaded1 = 1;
  digitalWrite(33, 1);
  digitalWrite(34, 0);
  digitalWrite(35, 0);
  digitalWrite(36, 0);
  digitalWrite(18, 0);

} else if (preset != 1) {
  presetLoaded1 = 0;
}


/////////// PRESET 2 ////////////////////////////////////////////////////
if (preset == 2 && presetLoaded2 == 0) {
  //read params
  polyMode = EEPROM.readInt(200);
  octaveB = EEPROM.readFloat(205);
  octaveC = EEPROM.readFloat(210);
  shapeA = EEPROM.readInt(215);
  shapeB = EEPROM.readInt(220);
  shapeC = EEPROM.readInt(225);
  tuneB = EEPROM.readFloat(230);
  tuneC = EEPROM.readFloat(235);
  crossMod = EEPROM.readFloat(240);
  vcoAvol = EEPROM.readFloat(245);
  vcoBvol = EEPROM.readFloat(250);
  vcoCvol = EEPROM.readFloat(255);
  Subvol = EEPROM.readFloat(260);
  cut = EEPROM.readInt(265);
  res = EEPROM.readFloat(270);
  filtAtt = EEPROM.readInt(275);
  filtDec = EEPROM.readInt(280);
  filtAmt = EEPROM.readFloat(285);
  filterMode = EEPROM.readInt(290);
  envAtt = EEPROM.readInt(295);
  envDec = EEPROM.readInt(300);
  envRel = EEPROM.readInt(305);
  envSus = EEPROM.readFloat(310);
  lfoAamp = EEPROM.readFloat(315);
  lfoAfreq = EEPROM.readFloat(320);
  lfoAdel = EEPROM.readInt(325);
  lfoAatt = EEPROM.readInt(330);
  lfoAdec = EEPROM.readInt(335);
  lfoArel = EEPROM.readInt(340);
  glideVal = EEPROM.readFloat(345);
  lfoBamp = EEPROM.readFloat(350);
  lfoBfreq = EEPROM.readFloat(355);
  dlyAmt = EEPROM.readFloat(360);
  dlyTimeL = EEPROM.readFloat(365);
  dlyTimeR = 2*dlyTimeL;
  lfoBSnap = EEPROM.readByte(370);
  revMix = EEPROM.readFloat(375);
  revSize = EEPROM.readFloat(380);
  lfoAdest = EEPROM.readFloat(385);
  lfoAshape = EEPROM.readFloat(390);

  presetLoaded2 = 2;

  digitalWrite(33, 0);
  digitalWrite(34, 1);
  digitalWrite(35, 0);
  digitalWrite(36, 0);
  digitalWrite(18, 0);

} else if (preset != 2) {
  presetLoaded2 = 0;
}



/////////// PRESET 3 ////////////////////////////////////////////////////
if (preset == 3 && presetLoaded3 == 0) {
  //read params
  polyMode = EEPROM.readInt(400);
  octaveB = EEPROM.readFloat(405);
  octaveC = EEPROM.readFloat(410);
  shapeA = EEPROM.readInt(415);
  shapeB = EEPROM.readInt(420);
  shapeC = EEPROM.readInt(425);
  tuneB = EEPROM.readFloat(430);
  tuneC = EEPROM.readFloat(435);
  crossMod = EEPROM.readFloat(440);
  vcoAvol = EEPROM.readFloat(445);
  vcoBvol = EEPROM.readFloat(450);
  vcoCvol = EEPROM.readFloat(455);
  Subvol = EEPROM.readFloat(460);
  cut = EEPROM.readInt(465);
  res = EEPROM.readFloat(470);
  filtAtt = EEPROM.readInt(475);
  filtDec = EEPROM.readInt(480);
  filtAmt = EEPROM.readFloat(485);
  filterMode = EEPROM.readInt(490);
  envAtt = EEPROM.readInt(495);
  envDec = EEPROM.readInt(500);
  envRel = EEPROM.readInt(505);
  envSus = EEPROM.readFloat(510);
  lfoAamp = EEPROM.readFloat(515);
  lfoAfreq = EEPROM.readFloat(520);
  lfoAdel = EEPROM.readInt(525);
  lfoAatt = EEPROM.readInt(530);
  lfoAdec = EEPROM.readInt(535);
  lfoArel = EEPROM.readInt(540);
  glideVal = EEPROM.readFloat(545); 
  lfoBamp = EEPROM.readFloat(550);
  lfoBfreq = EEPROM.readFloat(555);
  dlyAmt = EEPROM.readFloat(560);
  dlyTimeL = EEPROM.readFloat(565);
  dlyTimeR = 2*dlyTimeL;
  lfoBSnap = EEPROM.readByte(570); 
  revMix = EEPROM.readFloat(575);
  revSize = EEPROM.readFloat(580);
  lfoAdest = EEPROM.readFloat(585);
  lfoAshape = EEPROM.readFloat(590);

  presetLoaded3 = 1;
  
  digitalWrite(33, 0);
  digitalWrite(34, 0);
  digitalWrite(35, 1);
  digitalWrite(36, 0);
  digitalWrite(18, 0);

} else if (preset != 3) {
  presetLoaded3 = 0;
}


/////////// PRESET 4 ////////////////////////////////////////////////////
if (preset == 4 && presetLoaded4 == 0) {
  //read params
  polyMode = EEPROM.readInt(600);
  octaveB = EEPROM.readFloat(605);
  octaveC = EEPROM.readFloat(610);
  shapeA = EEPROM.readInt(615);
  shapeB = EEPROM.readInt(620);
  shapeC = EEPROM.readInt(625);
  tuneB = EEPROM.readFloat(630);
  tuneC = EEPROM.readFloat(635);
  crossMod = EEPROM.readFloat(640);
  vcoAvol = EEPROM.readFloat(645);
  vcoBvol = EEPROM.readFloat(650);
  vcoCvol = EEPROM.readFloat(655);
  Subvol = EEPROM.readFloat(660);
  cut = EEPROM.readInt(665);
  res = EEPROM.readFloat(670);
  filtAtt = EEPROM.readInt(675);
  filtDec = EEPROM.readInt(680);
  filtAmt = EEPROM.readFloat(685);
  filterMode = EEPROM.readInt(690);
  envAtt = EEPROM.readInt(695);
  envDec = EEPROM.readInt(700);
  envRel = EEPROM.readInt(705);
  envSus = EEPROM.readFloat(710);
  lfoAamp = EEPROM.readFloat(715);
  lfoAfreq = EEPROM.readFloat(720);
  lfoAdel = EEPROM.readInt(725);
  lfoAatt = EEPROM.readInt(730);
  lfoAdec = EEPROM.readInt(735);
  lfoArel = EEPROM.readInt(740);
  glideVal = EEPROM.readFloat(745);
  lfoBamp = EEPROM.readFloat(750);
  lfoBfreq = EEPROM.readFloat(755);
  dlyAmt = EEPROM.readFloat(760);
  dlyTimeL = EEPROM.readFloat(765);
  dlyTimeR = 2*dlyTimeL;
  lfoBSnap = EEPROM.readByte(770); 
  revMix = EEPROM.readFloat(775);
  revSize = EEPROM.readFloat(780);
  lfoAdest = EEPROM.readFloat(785);
  lfoAshape = EEPROM.readFloat(790);

  presetLoaded4 = 1;

  digitalWrite(33, 0);
  digitalWrite(34, 0);
  digitalWrite(35, 0);
  digitalWrite(36, 1);
  digitalWrite(18, 0);

} else if (preset != 4) {
  presetLoaded4 = 0;
}


/////////// PRESET 5 ////////////////////////////////////////////////////
if (preset == 5 && presetLoaded5 == 0) {
  //read params
  polyMode = EEPROM.readInt(800);
  octaveB = EEPROM.readFloat(805);
  octaveC = EEPROM.readFloat(810);
  shapeA = EEPROM.readInt(815);
  shapeB = EEPROM.readInt(820);
  shapeC = EEPROM.readInt(825);
  tuneB = EEPROM.readFloat(830);
  tuneC = EEPROM.readFloat(835);
  crossMod = EEPROM.readFloat(840);
  vcoAvol = EEPROM.readFloat(845);
  vcoBvol = EEPROM.readFloat(850);
  vcoCvol = EEPROM.readFloat(855);
  Subvol = EEPROM.readFloat(860);
  cut = EEPROM.readInt(865);
  res = EEPROM.readFloat(870);
  filtAtt = EEPROM.readInt(875);
  filtDec = EEPROM.readInt(880);
  filtAmt = EEPROM.readFloat(885);
  filterMode = EEPROM.readInt(890);
  envAtt = EEPROM.readInt(895);
  envDec = EEPROM.readInt(900);
  envRel = EEPROM.readInt(905);
  envSus = EEPROM.readFloat(910);
  lfoAamp = EEPROM.readFloat(915);
  lfoAfreq = EEPROM.readFloat(920);
  lfoAdel = EEPROM.readInt(925);
  lfoAatt = EEPROM.readInt(930);
  lfoAdec = EEPROM.readInt(935);
  lfoArel = EEPROM.readInt(940);
  glideVal = EEPROM.readFloat(945); 
  lfoBamp = EEPROM.readFloat(950);
  lfoBfreq = EEPROM.readFloat(955);
  dlyAmt = EEPROM.readFloat(960);
  dlyTimeL = EEPROM.readFloat(965);
  dlyTimeR = 2*dlyTimeL;
  lfoBSnap = EEPROM.readByte(970); 
  revMix = EEPROM.readFloat(975);
  revSize = EEPROM.readFloat(980);
  lfoAdest = EEPROM.readFloat(985);
  lfoAshape = EEPROM.readFloat(990);

  presetLoaded5 = 1;

  digitalWrite(33, 0);
  digitalWrite(34, 0);
  digitalWrite(35, 0);
  digitalWrite(36, 0);
  digitalWrite(18, 1);

} else if (preset != 5) {
  presetLoaded5 = 0;
}

}
