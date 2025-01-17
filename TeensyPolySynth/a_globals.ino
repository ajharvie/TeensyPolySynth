//to do:
//double check output levels
// need 5 successive values above threshold to change (only for small thresholds) - cutoff, tuneb, tunec

//nice ideas:
//keyboard filter tracking?
//more voices?
//noise somehow? Perhaps use glide knob in poly mode?




#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "AudioSampleScreamattack.h"   
#include "AudioSampleScreamsustain.h" 
#include "AudioSampleScreamdecay.h" 

#include <Bounce.h>

const int saveButtonPin = 31;
Bounce saveButton = Bounce(saveButtonPin, 10);

// GUItool: begin automatically generated code
AudioSynthWaveform       lfoA1;          //xy=1268,2186
AudioSynthWaveform       lfoB1;          //xy=1461.5712985992432,1589.8571491241455
AudioEffectEnvelope      lfoAenv1;       //xy=1466.4285278320312,1649.2856845855713
AudioEffectEnvelope      lfoAenv3;       //xy=1465.4285125732422,2190.857105255127
AudioEffectEnvelope      lfoAenv2;       //xy=1474.8571166992188,1930.8571090698242
AudioEffectEnvelope      lfoAenv4;       //xy=1474,2448
AudioSynthWaveform       lfoB3;          //xy=1477.5714950561523,2138.428569793701
AudioEffectEnvelope      lfoAenv5;       //xy=1480,2698
AudioSynthWaveform       lfoB2;          //xy=1485.142936706543,1878.0001420974731
AudioEffectEnvelope      lfoAenv6;       //xy=1482,2968
AudioSynthWaveform       lfoB4;          //xy=1486.8570671081543,2389.5715980529785
AudioSynthWaveform       lfoB6;          //xy=1490.9998741149902,2907.857129096985
AudioSynthWaveform       lfoB5;          //xy=1493.0000305175781,2644.142812728882
AudioMixer4              modMix1;        //xy=1513.71431350708,1497.2857398986816
AudioMixer4              modMix2;        //xy=1514,1811
AudioMixer4              modMix3;        //xy=1516,2071
AudioMixer4              modMix4;        //xy=1516,2332
AudioMixer4              modMix5;        //xy=1522,2581
AudioMixer4              modMix6;        //xy=1524,2852
AudioSynthWaveformModulated sub1;           //xy=1663,1664
AudioSynthWaveformModulated vcoA1;          //xy=1664,1571
AudioSynthWaveformModulated vcoB1;          //xy=1664,1602
AudioSynthWaveformModulated vcoC1;          //xy=1664,1633
AudioSynthWaveformModulated sub2;           //xy=1669,1922
AudioSynthWaveformModulated vcoA2;          //xy=1670,1829
AudioSynthWaveformModulated vcoB2;          //xy=1670,1860
AudioSynthWaveformModulated vcoC2;          //xy=1670,1891
AudioSynthWaveformModulated sub3;           //xy=1671,2182
AudioSynthWaveformModulated vcoA3;          //xy=1672,2089
AudioSynthWaveformModulated vcoB3;          //xy=1672,2120
AudioSynthWaveformModulated vcoC3;          //xy=1672,2151
AudioSynthWaveformModulated sub4;           //xy=1671,2443
AudioSynthWaveformModulated vcoA4;          //xy=1672,2350
AudioSynthWaveformModulated vcoB4;          //xy=1672,2381
AudioSynthWaveformModulated vcoC4;          //xy=1672,2412
AudioSynthWaveformModulated sub5;           //xy=1677,2692
AudioSynthWaveformModulated vcoA5;          //xy=1678,2599
AudioSynthWaveformModulated vcoB5;          //xy=1678,2630
AudioSynthWaveformModulated vcoC5;          //xy=1678,2661
AudioSynthWaveformModulated sub6;           //xy=1679,2963
AudioSynthWaveformModulated vcoA6;          //xy=1680,2870
AudioSynthWaveformModulated vcoB6;          //xy=1680,2901
AudioSynthWaveformModulated vcoC6;          //xy=1680,2932
AudioMixer4              voiceMix1;      //xy=1825,1616
AudioMixer4              voiceMix2;      //xy=1831,1874
AudioMixer4              voiceMix3;      //xy=1833,2134
AudioMixer4              voiceMix4;      //xy=1833,2395
AudioMixer4              voiceMix5;      //xy=1839,2644
AudioMixer4              voiceMix6;      //xy=1841,2915
AudioSynthWaveformDc     dc1;            //xy=1847,1664
AudioSynthWaveformDc     dc2;            //xy=1853,1922
AudioSynthWaveformDc     dc3;            //xy=1855,2182
AudioSynthWaveformDc     dc4;            //xy=1855,2443
AudioSynthWaveformDc     dc5;            //xy=1861,2692
AudioSynthWaveformDc     dc6;            //xy=1863,2963
AudioEffectEnvelope      filterEnv1;     //xy=1966,1653
AudioEffectEnvelope      filterEnv2;     //xy=1972,1911
AudioEffectEnvelope      filterEnv3;     //xy=1974,2171
AudioEffectEnvelope      filterEnv4;     //xy=1974,2432
AudioEffectEnvelope      filterEnv5;     //xy=1980,2681
AudioEffectEnvelope      filterEnv6;     //xy=1982,2952
AudioMixer4              filterMix1;     //xy=2138,1655
AudioMixer4              filterMix2;     //xy=2144,1913
AudioMixer4              filterMix3;     //xy=2146,2173
AudioMixer4              filterMix4;     //xy=2146,2434
AudioMixer4              filterMix5;     //xy=2152,2683
AudioMixer4              filterMix6;     //xy=2154,2954
AudioFilterStateVariable filter1;        //xy=2259,1622
AudioFilterStateVariable filter2;        //xy=2265,1880
AudioFilterStateVariable filter3;        //xy=2267,2140
AudioFilterStateVariable filter4;        //xy=2267,2401
AudioFilterStateVariable filter5;        //xy=2273,2650
AudioFilterStateVariable filter6;        //xy=2275,2921
AudioMixer4              filterMode1;    //xy=2391,1637
AudioMixer4              filterMode2;    //xy=2397,1895
AudioMixer4              filterMode3;    //xy=2399,2155
AudioMixer4              filterMode4;    //xy=2399,2416
AudioMixer4              filterMode5;    //xy=2405,2665
AudioMixer4              filterMode6;    //xy=2407,2936
AudioEffectEnvelope      env1;           //xy=2521,1637
AudioSynthWaveformDc     dc9;            //xy=2522,2341
AudioEffectEnvelope      env2;           //xy=2527,1895
AudioEffectEnvelope      env3;           //xy=2529,2155
AudioEffectEnvelope      env4;           //xy=2529,2416
AudioEffectEnvelope      env5;           //xy=2534,2665
AudioEffectEnvelope      env6;           //xy=2537,2936
AudioSynthWaveformDc     dc8;            //xy=2564,2096
AudioSynthWaveformDc     dc10;           //xy=2572,2577
AudioSynthWaveformDc     dc7;            //xy=2579,1818
AudioSynthWaveformDc     dc11;           //xy=2596,2857
AudioSynthWaveformDc     dc12;           //xy=2601,3095
AudioEffectMultiply      multiply3;      //xy=2692,2290
AudioEffectMultiply      multiply4;      //xy=2725,2533
AudioEffectMultiply      multiply1;      //xy=2735,1768
AudioEffectMultiply      multiply2;      //xy=2738,2057
AudioEffectMultiply      multiply5;      //xy=2736,2801
AudioEffectMultiply      multiply6;      //xy=2781,3047
AudioMixer4              mix1;           //xy=2863,2241
AudioMixer4              mix2;           //xy=2863,2373
AudioFilterStateVariable dlyFiltL;       //xy=2953,2459
AudioFilterStateVariable dlyFiltR;       //xy=2957,2790
AudioPlayMemory          playMem3;       //xy=2967,1959
AudioPlayMemory          playMem4;       //xy=2967,2018
AudioPlayMemory          playMem2;       //xy=2968,1897
AudioPlayMemory          playMem1;       //xy=2970,1837
AudioMixer4              finalMix;       //xy=2988,2310
AudioMixer4              shoutMixer;     //xy=3207,1924
AudioAmplifier           amp3;           //xy=3210,2124
AudioEffectDelay         dlyR;           //xy=3320,2730
AudioEffectDelay         dlyL;           //xy=3321,2496
AudioMixer4              dlyMixR;        //xy=3321,2630
AudioMixer4              dlyMixL;        //xy=3332,2392
AudioEffectFreeverbStereo reverb;         //xy=3368,2111
AudioMixer4              fxL;            //xy=3572,2241
AudioMixer4              fxR;            //xy=3572,2363
AudioAmplifier           amp2;           //xy=3743,2343
AudioAmplifier           amp1;           //xy=3746,2219
AudioOutputI2S           i2s1;           //xy=3961,2289
AudioConnection          patchCord1(lfoA1, lfoAenv1);
AudioConnection          patchCord2(lfoA1, lfoAenv2);
AudioConnection          patchCord3(lfoA1, lfoAenv3);
AudioConnection          patchCord4(lfoA1, lfoAenv4);
AudioConnection          patchCord5(lfoA1, lfoAenv5);
AudioConnection          patchCord6(lfoA1, lfoAenv6);
AudioConnection          patchCord7(lfoAenv1, 0, modMix1, 1);
AudioConnection          patchCord8(lfoAenv1, 0, vcoB1, 0);
AudioConnection          patchCord9(lfoAenv1, 0, vcoC1, 0);
AudioConnection          patchCord10(lfoAenv1, 0, sub1, 0);
AudioConnection          patchCord11(lfoAenv1, 0, filterMix1, 1);
AudioConnection          patchCord12(lfoAenv1, 0, multiply1, 1);
AudioConnection          patchCord165(lfoAenv2, 0, multiply2, 1);
AudioConnection          patchCord166(lfoAenv3, 0, multiply3, 1);
AudioConnection          patchCord167(lfoAenv4, 0, multiply4, 1);
AudioConnection          patchCord168(lfoAenv5, 0, multiply5, 1);
AudioConnection          patchCord169(lfoAenv6, 0, multiply6, 1);
AudioConnection          patchCord170(dc7, 0, multiply1, 1);
AudioConnection          patchCord171(dc8, 0, multiply2, 1);
AudioConnection          patchCord172(dc9, 0, multiply3, 1);
AudioConnection          patchCord173(dc10, 0, multiply4, 1);
AudioConnection          patchCord174(dc11, 0, multiply5, 1);
AudioConnection          patchCord175(dc12, 0, multiply6, 1);
AudioConnection          patchCord13(lfoB1, 0, vcoA1, 1);
AudioConnection          patchCord14(lfoB1, 0, vcoB1, 1);
AudioConnection          patchCord15(lfoAenv2, 0, modMix2, 1);
AudioConnection          patchCord16(lfoAenv2, 0, vcoB2, 0);
AudioConnection          patchCord17(lfoAenv2, 0, vcoC2, 0);
AudioConnection          patchCord18(lfoAenv2, 0, sub2, 0);
AudioConnection          patchCord19(lfoAenv2, 0, filterMix2, 1);
AudioConnection          patchCord20(lfoAenv3, 0, modMix3, 1);
AudioConnection          patchCord21(lfoAenv3, 0, vcoB3, 0);
AudioConnection          patchCord22(lfoAenv3, 0, vcoC3, 0);
AudioConnection          patchCord23(lfoAenv3, 0, sub3, 0);
AudioConnection          patchCord24(lfoAenv3, 0, filterMix3, 1);
AudioConnection          patchCord25(lfoAenv4, 0, modMix4, 1);
AudioConnection          patchCord26(lfoAenv4, 0, vcoB4, 0);
AudioConnection          patchCord27(lfoAenv4, 0, vcoC4, 0);
AudioConnection          patchCord28(lfoAenv4, 0, sub4, 0);
AudioConnection          patchCord29(lfoAenv4, 0, filterMix4, 1);
AudioConnection          patchCord30(lfoB2, 0, vcoA2, 1);
AudioConnection          patchCord31(lfoB2, 0, vcoB2, 1);
AudioConnection          patchCord32(lfoB3, 0, vcoA3, 1);
AudioConnection          patchCord33(lfoB3, 0, vcoB3, 1);
AudioConnection          patchCord34(lfoB4, 0, vcoA4, 1);
AudioConnection          patchCord35(lfoB4, 0, vcoB4, 1);
AudioConnection          patchCord36(lfoAenv5, 0, modMix5, 1);
AudioConnection          patchCord37(lfoAenv5, 0, vcoB5, 0);
AudioConnection          patchCord38(lfoAenv5, 0, vcoC5, 0);
AudioConnection          patchCord39(lfoAenv5, 0, sub5, 0);
AudioConnection          patchCord40(lfoAenv5, 0, filterMix5, 1);
AudioConnection          patchCord41(lfoAenv6, 0, modMix6, 1);
AudioConnection          patchCord42(lfoAenv6, 0, vcoB6, 0);
AudioConnection          patchCord43(lfoAenv6, 0, vcoC6, 0);
AudioConnection          patchCord44(lfoAenv6, 0, sub6, 0);
AudioConnection          patchCord45(lfoAenv6, 0, filterMix6, 1);
AudioConnection          patchCord46(lfoB5, 0, vcoA5, 1);
AudioConnection          patchCord47(lfoB5, 0, vcoB5, 1);
AudioConnection          patchCord48(lfoB6, 0, vcoA6, 1);
AudioConnection          patchCord49(lfoB6, 0, vcoB6, 1);
AudioConnection          patchCord50(modMix1, 0, vcoA1, 0);
AudioConnection          patchCord51(modMix2, 0, vcoA2, 0);
AudioConnection          patchCord52(modMix3, 0, vcoA3, 0);
AudioConnection          patchCord53(modMix4, 0, vcoA4, 0);
AudioConnection          patchCord54(modMix5, 0, vcoA5, 0);
AudioConnection          patchCord55(modMix6, 0, vcoA6, 0);
AudioConnection          patchCord56(sub1, 0, voiceMix1, 3);
AudioConnection          patchCord57(vcoA1, 0, voiceMix1, 0);
AudioConnection          patchCord58(vcoB1, 0, voiceMix1, 1);
AudioConnection          patchCord59(vcoC1, 0, modMix1, 0);
AudioConnection          patchCord60(vcoC1, 0, voiceMix1, 2);
AudioConnection          patchCord61(sub2, 0, voiceMix2, 3);
AudioConnection          patchCord62(vcoA2, 0, voiceMix2, 0);
AudioConnection          patchCord63(vcoB2, 0, voiceMix2, 1);
AudioConnection          patchCord64(vcoC2, 0, modMix2, 0);
AudioConnection          patchCord65(vcoC2, 0, voiceMix2, 2);
AudioConnection          patchCord66(sub3, 0, voiceMix3, 3);
AudioConnection          patchCord67(vcoA3, 0, voiceMix3, 0);
AudioConnection          patchCord68(vcoB3, 0, voiceMix3, 1);
AudioConnection          patchCord69(vcoC3, 0, modMix3, 0);
AudioConnection          patchCord70(vcoC3, 0, voiceMix3, 2);
AudioConnection          patchCord71(sub4, 0, voiceMix4, 3);
AudioConnection          patchCord72(vcoA4, 0, voiceMix4, 0);
AudioConnection          patchCord73(vcoB4, 0, voiceMix4, 1);
AudioConnection          patchCord74(vcoC4, 0, modMix4, 0);
AudioConnection          patchCord75(vcoC4, 0, voiceMix4, 2);
AudioConnection          patchCord76(sub5, 0, voiceMix5, 3);
AudioConnection          patchCord77(vcoA5, 0, voiceMix5, 0);
AudioConnection          patchCord78(vcoB5, 0, voiceMix5, 1);
AudioConnection          patchCord79(vcoC5, 0, modMix5, 0);
AudioConnection          patchCord80(vcoC5, 0, voiceMix5, 2);
AudioConnection          patchCord81(sub6, 0, voiceMix6, 3);
AudioConnection          patchCord82(vcoA6, 0, voiceMix6, 0);
AudioConnection          patchCord83(vcoB6, 0, voiceMix6, 1);
AudioConnection          patchCord84(vcoC6, 0, modMix6, 0);
AudioConnection          patchCord85(vcoC6, 0, voiceMix6, 2);
AudioConnection          patchCord86(voiceMix1, 0, filter1, 0);
AudioConnection          patchCord87(voiceMix2, 0, filter2, 0);
AudioConnection          patchCord88(voiceMix3, 0, filter3, 0);
AudioConnection          patchCord89(voiceMix4, 0, filter4, 0);
AudioConnection          patchCord90(voiceMix5, 0, filter5, 0);
AudioConnection          patchCord91(voiceMix6, 0, filter6, 0);
AudioConnection          patchCord92(dc1, filterEnv1);
AudioConnection          patchCord93(dc2, filterEnv2);
AudioConnection          patchCord94(dc3, filterEnv3);
AudioConnection          patchCord95(dc4, filterEnv4);
AudioConnection          patchCord96(dc5, filterEnv5);
AudioConnection          patchCord97(dc6, filterEnv6);
AudioConnection          patchCord98(filterEnv1, 0, filterMix1, 0);
AudioConnection          patchCord99(filterEnv2, 0, filterMix2, 0);
AudioConnection          patchCord100(filterEnv3, 0, filterMix3, 0);
AudioConnection          patchCord101(filterEnv4, 0, filterMix4, 0);
AudioConnection          patchCord102(filterEnv5, 0, filterMix5, 0);
AudioConnection          patchCord103(filterEnv6, 0, filterMix6, 0);
AudioConnection          patchCord104(filterMix1, 0, filter1, 1);
AudioConnection          patchCord105(filterMix2, 0, filter2, 1);
AudioConnection          patchCord106(filterMix3, 0, filter3, 1);
AudioConnection          patchCord107(filterMix4, 0, filter4, 1);
AudioConnection          patchCord108(filterMix5, 0, filter5, 1);
AudioConnection          patchCord109(filterMix6, 0, filter6, 1);
AudioConnection          patchCord110(filter1, 0, filterMode1, 0);
AudioConnection          patchCord111(filter1, 1, filterMode1, 1);
AudioConnection          patchCord112(filter1, 2, filterMode1, 2);
AudioConnection          patchCord113(filter2, 0, filterMode2, 0);
AudioConnection          patchCord114(filter2, 1, filterMode2, 1);
AudioConnection          patchCord115(filter2, 2, filterMode2, 2);
AudioConnection          patchCord116(filter3, 0, filterMode3, 0);
AudioConnection          patchCord117(filter3, 1, filterMode3, 1);
AudioConnection          patchCord118(filter3, 2, filterMode3, 2);
AudioConnection          patchCord119(filter4, 0, filterMode4, 0);
AudioConnection          patchCord120(filter4, 1, filterMode4, 1);
AudioConnection          patchCord121(filter4, 2, filterMode4, 2);
AudioConnection          patchCord122(filter5, 0, filterMode5, 0);
AudioConnection          patchCord123(filter5, 1, filterMode5, 1);
AudioConnection          patchCord124(filter5, 2, filterMode5, 2);
AudioConnection          patchCord125(filter6, 0, filterMode6, 0);
AudioConnection          patchCord126(filter6, 1, filterMode6, 1);
AudioConnection          patchCord127(filter6, 2, filterMode6, 2);
AudioConnection          patchCord128(filterMode1, env1);
AudioConnection          patchCord129(filterMode2, env2);
AudioConnection          patchCord130(filterMode3, env3);
AudioConnection          patchCord131(filterMode4, env4);
AudioConnection          patchCord132(filterMode5, env5);
AudioConnection          patchCord133(filterMode6, env6);
AudioConnection          patchCord134(env1, 0, multiply1, 0);
AudioConnection          patchCord135(env2, 0, multiply2, 0);
AudioConnection          patchCord136(env3, 0, multiply3, 0);
AudioConnection          patchCord137(env4, 0, multiply4, 0);
AudioConnection          patchCord138(env5, 0, multiply5, 0);
AudioConnection          patchCord139(env6, 0, multiply6, 0);
AudioConnection          patchCord159(multiply1, 0, mix1, 0);
AudioConnection          patchCord160(multiply2, 0, mix1, 1);
AudioConnection          patchCord161(multiply3, 0, mix1, 2);
AudioConnection          patchCord162(multiply4, 0, mix2, 0);
AudioConnection          patchCord163(multiply5, 0, mix2, 1);
AudioConnection          patchCord164(multiply6, 0, mix2, 2);
AudioConnection          patchCord140(mix1, 0, finalMix, 0);
AudioConnection          patchCord141(mix2, 0, finalMix, 1);
AudioConnection          patchCord142(finalMix, 0, fxL, 0);
AudioConnection          patchCord144(finalMix, 0, fxR, 0);
AudioConnection          patchCord145(finalMix, 0, dlyMixL, 0);
AudioConnection          patchCord146(finalMix, 0, dlyMixR, 0);
AudioConnection          patchCord147(dlyFiltR, 0, dlyMixR, 1);
AudioConnection          patchCord148(dlyFiltL, 0, dlyMixL, 1);
AudioConnection          patchCord149(dlyR, 0, dlyFiltR, 0);
AudioConnection          patchCord150(dlyL, 0, dlyFiltL, 0);
AudioConnection          patchCord151(dlyMixR, 0, fxR, 2);
AudioConnection          patchCord152(dlyMixR, dlyR);
AudioConnection          patchCord153(dlyMixL, 0, fxL, 2);
AudioConnection          patchCord154(dlyMixL, dlyL);
AudioConnection          patchCord155(reverb, 0, fxL, 1);
AudioConnection          patchCord156(reverb, 1, fxR, 1);
AudioConnection          patchCord157(fxL, 0, amp1, 0);
AudioConnection          patchCord158(fxR, 0, amp2, 0);
AudioConnection          patchCord178(amp1, 0, i2s1, 0);
AudioConnection          patchCord179(amp2, 0, i2s1, 1);
AudioConnection          patchCord180(playMem1, 0, shoutMixer, 0);
AudioConnection          patchCord181(playMem2, 0, shoutMixer, 1);
AudioConnection          patchCord182(playMem3, 0, shoutMixer, 2);
AudioConnection          patchCord183(playMem4, 0, shoutMixer, 3);
AudioConnection          patchCord184(shoutMixer, 0, finalMix, 2); 
AudioConnection          patchCord185(finalMix, 0, amp3, 0); 
AudioConnection          patchCord186(amp3, 0, reverb, 0); 



#include <MIDI.h>
#include <EEPROMex.h>


MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);


elapsedMillis debugTimer;

//////// Multiplexer //////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
const int muxPots0 = A3;
const int muxPots1 = A2;
const int muxPots2 = A1;
const int muxPots3 = A0;

float wait = 100; //mux read delay (micros)

//mux chip 0
int mux0_0;
int mux1_0;
int mux2_0;
int mux3_0;
int mux4_0;
int mux5_0;
int mux6_0;
int mux7_0;

//mux chip 1
int mux0_1;
int mux1_1;
int mux2_1;
int mux3_1;
int mux4_1;
int mux5_1;
int mux6_1;
int mux7_1;

//mux chip 2
int mux0_2;
int mux1_2;
int mux2_2;
int mux3_2;
int mux4_2;
int mux5_2;
int mux6_2;
int mux7_2;

//mux chip 3
int mux0_3;
int mux1_3;
int mux2_3;
int mux3_3;
int mux4_3;
int mux5_3;
int mux6_3;
int mux7_3;

int silent;
unsigned int delayFix = 3;
int shout = 0;


///// notes, frequencies, voices /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
const float noteFreqs[128] = {8.176, 8.662, 9.177, 9.723, 10.301, 10.913, 11.562, 12.25, 12.978, 13.75, 14.568, 15.434, 16.352, 17.324, 18.354, 19.445, 20.602, 21.827, 23.125, 24.5, 25.957, 27.5, 29.135, 30.868, 32.703, 34.648, 36.708, 38.891, 41.203, 43.654, 46.249, 48.999, 51.913, 55, 58.27, 61.735, 65.406, 69.296, 73.416, 77.782, 82.407, 87.307, 92.499, 97.999, 103.826, 110, 116.541, 123.471, 130.813, 138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652, 220, 233.082, 246.942, 261.626, 277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305, 440, 466.164, 493.883, 523.251, 554.365, 587.33, 622.254, 659.255, 698.456, 739.989, 783.991, 830.609, 880, 932.328, 987.767, 1046.502, 1108.731, 1174.659, 1244.508, 1318.51, 1396.913, 1479.978, 1567.982, 1661.219, 1760, 1864.655, 1975.533, 2093.005, 2217.461, 2349.318, 2489.016, 2637.02, 2793.826, 2959.955, 3135.963, 3322.438, 3520, 3729.31, 3951.066, 4186.009, 4434.922, 4698.636, 4978.032, 5274.041, 5587.652, 5919.911, 6271.927, 6644.875, 7040, 7458.62, 7902.133, 8372.018, 8869.844, 9397.273, 9956.063, 10548.08, 11175.3, 11839.82, 12543.85};

int note1freq;
int note2freq;
int note3freq;
int note4freq;
int note5freq;
int note6freq;

int voices;

//polyphony/glide

int polyMode;
int polyModesw;
int oldPolyModesw;
float glideVal;
float oldA1Freq;
float oldB1Freq;
float oldC1Freq;
float oldSub1Freq;
int glidePot;
int oldGlidePot;

//osc 1 frequencies for portamento purposes
float a1Freq;
float c1Freq;
float sub1Freq;
float a1FreqFiltered;
float b1FreqFiltered;
float c1FreqFiltered;
float sub1FreqFiltered;
//b frequencies (not needed nowadays but whatever)
float b1Freq;
float b2Freq;
float b3Freq;
float b4Freq;
float b5Freq;
float b6Freq;

//C frequencies for modulation purposes. lfo 2 matches oscC frequency when turned all the way up, for pwm fun
float c2Freq;
float c3Freq;
float c4Freq;
float c5Freq;
float c6Freq;

//glide smoothing parameters
unsigned int filterTime = 5000;
elapsedMicros sinceLastFilter;






//checks if notes are on or not
///////////////////////////////////////////////////////////////////////////////////////////////////////////
bool env1on = false;
bool env2on = false;
bool env3on = false;
bool env4on = false;
bool env5on = false;
bool env6on = false;

//int vol of vcos.
float vcoVol = 0.07;
float mainVol;


//real bending
float numSemitones;
float pitchFactor = 1;
float pitchFactorFiltered = 1;


//voice mixer
///////////////////////////////////////////////////////////////////////////////////////////////////////////
float vcoAvol = 0.5;
float vcoBvol = 0.5;
float vcoCvol = 0.5;
float Subvol = 0.5;

float crossMod;

//Tunings, octaves etc.
///////////////////////////////////////////////////////////////////////////////////////////////////////////
float octave = 1;
float octaveB = 1;
float octaveC = 1;
float tuneB = 1;
float tuneC = 1;
float tuneBFiltered = 1;
float tuneCFiltered = 1;

//vco shapes
int shapeA;
int shapeB;
int shapeC = 1;
int waveSelect;


//filter
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int cut = 2000;
float res = 1;
int filtAtt;
int filtDec;
float filtAmt;

int filterMode;
float filterExtMod;


//envelope
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int envAtt;
int envDec;
int envRel;
float envSus;

const float minTime = 5; //minimum length of any bit of adsr. prevents pops

//lfo A
///////////////////////////////////////////////////////////////////////////////////////////////////////////
float lfoAamp;
float lfoAampMin;
float lfoAfreq;
const float lfoAMaxFreq = 200.0;
int lfoAdel = 1; //weird overflow happens
int lfoAatt;
int lfoAdec = 1;
int lfoArel;
float lfoAsus = 1;

int lfoAshape;
int lfoAdest;


//tremolo
float ampMod;
float readInt = 1.0001;
unsigned long prevTime;


//lfo B
///////////////////////////////////////////////////////////////////////////////////////////////////////////
float lfoBamp;
float lfoBfreq;
const float lfoBMaxFreq = 50.0;
byte lfoBSnap = 0; // 1 if frequency matches that of oscillator C. 0 if not. Turn freq knob fully rightwards to set to C
byte lfoBSnapsw; // "switch" parlance to match how it works in the other ones. pointless really not sure why i did it lmao
byte oldlfoBSnapsw;
const int lfoBSnapKnobThresh = 1010; //knob position that's considered "fully rightwards" will have to adjust to see
int justSnapped = 1;



//delay
///////////////////////////////////////////////////////////////////////////////////////////////////////////
float outGain = 0.8;
float dlyAmt;

float dlyTimeL;
float dlyTimeR;

//reverb
///////////////////////////////////////////////////////////////////////////////////////////////////////////
float revMix;
float revSize;




//Presets
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int preset;
int resetting = 1;

bool prevBtn1;
bool prevBtn2;
bool prevBtn3;
bool prevBtn4;
bool prevBtn5;

bool presetLoaded1 = 0;
bool presetLoaded2 = 0;
bool presetLoaded3 = 0;
bool presetLoaded4 = 0;
bool presetLoaded5 = 0;




//turncheck
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int resetPressed = 1;
int savePressed = 1;

float tresh = 10;
float tresh2 = 20;
float tresh3 = 4;

int cutCount = 0;
int tuneBCount = 0;
int tuneCCount = 0;
int shapeCCount = 0;
int threshCounts = 2; //counts until new value is accepted
float tresh4 = 8; //no longer used
bool firstBoot = true;

unsigned int timer = 6; //6 ms between changing settings - needs testing
elapsedMillis sinceMeasure;


int tuneBpot;
int oldTuneBpot;
int tuneCpot;
int oldTuneCpot;

float octBsw;
float oldOctBsw;
float octCsw;
float oldOctCsw;

int shapeAsw;
int oldShapeAsw;
int shapeBsw;
int oldShapeBsw;
int shapeCpot;
int oldShapeCpot;


int crossModpot;
int oldCrossModpot;

int volApot;
int oldVolApot;
int volBpot;
int oldVolBpot;
int volCpot;
int oldVolCpot;
int volSubpot;
int oldVolSubpot;

int cutpot;
int oldCutpot;
int respot;
int oldRespot;

int filtModesw;
int oldFiltModesw;

int fAttpot;
int oldFAttpot;
int fDecpot;
int oldFDecpot;
int fAmtpot;
int oldFAmtpot;


int attpot;
int oldAttpot;
int decpot;
int oldDecpot;
float suspot;
float oldSuspot;

int lfoAmppot;
int oldLfoAmppot;
int lfoFreqpot;
int oldLfoFreqpot;
int lfoAttpot;
int oldLfoAttpot;
int lfoDecpot;
int oldLfoDecpot;
int lfoSuspot;
int oldLfoSuspot;

int lfoShapesw;
int oldLfoShapesw;
int lfoDestsw;
int oldLfoDestsw;

int lfoBAmppot;
int oldLfoBAmppot;
int lfoBFreqpot;
int oldLfoBFreqpot;

int dlyAmtpot;
int oldDlyAmtpot;
int dlyTimepot;
int oldDlyTimepot;

int revMixpot;
int oldRevMixpot;
int revSizepot;
int oldRevSizepot;



//lookup table for exponentialifying pots and that
const float expLookup1024[] = {
  0,  0.01, 0.01, 0.02, 0.03, 0.04, 0.04, 0.05,
  0.06, 0.06, 0.07, 0.08, 0.09, 0.09, 0.1,
  0.11, 0.12, 0.12, 0.13, 0.14, 0.15, 0.15,
  0.16, 0.17, 0.18, 0.19, 0.19, 0.2,  0.21,
  0.22, 0.23, 0.23, 0.24, 0.25, 0.26, 0.27,
  0.28, 0.29, 0.29, 0.3,  0.31, 0.32, 0.33,
  0.34, 0.35, 0.36, 0.37, 0.38, 0.39, 0.4,
  0.4,  0.41, 0.42, 0.43, 0.44, 0.45, 0.46,
  0.47, 0.48, 0.49, 0.5,  0.51, 0.52, 0.53,
  0.54, 0.55, 0.57, 0.58, 0.59, 0.6,  0.61,
  0.62, 0.63, 0.64, 0.65, 0.66, 0.68, 0.69,
  0.7,  0.71, 0.72, 0.73, 0.74, 0.76, 0.77,
  0.78, 0.79, 0.8,  0.82, 0.83, 0.84, 0.85,
  0.87, 0.88, 0.89, 0.91, 0.92, 0.93, 0.94,
  0.96, 0.97, 0.98, 1,  1.01, 1.02, 1.04,
  1.05, 1.07, 1.08, 1.09, 1.11, 1.12, 1.14,
  1.15, 1.17, 1.18, 1.2,  1.21, 1.23, 1.24,
  1.26, 1.27, 1.29, 1.3,  1.32, 1.33, 1.35,
  1.37, 1.38, 1.4,  1.41, 1.43, 1.45, 1.46,
  1.48, 1.5,  1.52, 1.53, 1.55, 1.57, 1.58,
  1.6,  1.62, 1.64, 1.66, 1.67, 1.69, 1.71,
  1.73, 1.75, 1.77, 1.78, 1.8,  1.82, 1.84,
  1.86, 1.88, 1.9,  1.92, 1.94, 1.96, 1.98,
  2,  2.02, 2.04, 2.06, 2.08, 2.1,  2.12,
  2.15, 2.17, 2.19, 2.21, 2.23, 2.25, 2.28,
  2.3,  2.32, 2.34, 2.37, 2.39, 2.41, 2.43,
  2.46, 2.48, 2.51, 2.53, 2.55, 2.58, 2.6,
  2.63, 2.65, 2.68, 2.7,  2.73, 2.75, 2.78,
  2.8,  2.83, 2.85, 2.88, 2.91, 2.93, 2.96,
  2.99, 3.01, 3.04, 3.07, 3.1,  3.12, 3.15,
  3.18, 3.21, 3.24, 3.27, 3.3,  3.32, 3.35,
  3.38, 3.41, 3.44, 3.47, 3.5,  3.53, 3.57,
  3.6,  3.63, 3.66, 3.69, 3.72, 3.75, 3.79,
  3.82, 3.85, 3.89, 3.92, 3.95, 3.99, 4.02,
  4.05, 4.09, 4.12, 4.16, 4.19, 4.23, 4.26,
  4.3,  4.34, 4.37, 4.41, 4.44, 4.48, 4.52,
  4.56, 4.59, 4.63, 4.67, 4.71, 4.75, 4.79,
  4.83, 4.87, 4.91, 4.95, 4.99, 5.03, 5.07,
  5.11, 5.15, 5.19, 5.23, 5.28, 5.32, 5.36,
  5.41, 5.45, 5.49, 5.54, 5.58, 5.63, 5.67,
  5.72, 5.76, 5.81, 5.86, 5.9,  5.95, 6,
  6.04, 6.09, 6.14, 6.19, 6.24, 6.29, 6.34,
  6.39, 6.44, 6.49, 6.54, 6.59, 6.64, 6.69,
  6.74, 6.8,  6.85, 6.9,  6.96, 7.01, 7.07,
  7.12, 7.18, 7.23, 7.29, 7.34, 7.4,  7.46,
  7.51, 7.57, 7.63, 7.69, 7.75, 7.81, 7.87,
  7.93, 7.99, 8.05, 8.11, 8.17, 8.24, 8.3,
  8.36, 8.43, 8.49, 8.55, 8.62, 8.68, 8.75,
  8.82, 8.88, 8.95, 9.02, 9.09, 9.15, 9.22,
  9.29, 9.36, 9.43, 9.5,  9.58, 9.65, 9.72,
  9.79, 9.87, 9.94, 10.01,  10.09,  10.16,  10.24,
  10.32,  10.39,  10.47,  10.55,  10.63,  10.71,  10.79,
  10.87,  10.95,  11.03,  11.11,  11.19,  11.28,  11.36,
  11.44,  11.53,  11.61,  11.7, 11.78,  11.87,  11.96,
  12.05,  12.14,  12.23,  12.32,  12.41,  12.5, 12.59,
  12.68,  12.77,  12.87,  12.96,  13.06,  13.15,  13.25,
  13.35,  13.44,  13.54,  13.64,  13.74,  13.84,  13.94,
  14.04,  14.14,  14.25,  14.35,  14.46,  14.56,  14.67,
  14.77,  14.88,  14.99,  15.1, 15.21,  15.32,  15.43,
  15.54,  15.65,  15.76,  15.88,  15.99,  16.11,  16.22,
  16.34,  16.46,  16.58,  16.7, 16.82,  16.94,  17.06,
  17.18,  17.31,  17.43,  17.56,  17.68,  17.81,  17.94,
  18.07,  18.2, 18.33,  18.46,  18.59,  18.72,  18.86,
  18.99,  19.13,  19.27,  19.4, 19.54,  19.68,  19.82,
  19.96,  20.11,  20.25,  20.39,  20.54,  20.69,  20.83,
  20.98,  21.13,  21.28,  21.43,  21.59,  21.74,  21.89,
  22.05,  22.21,  22.36,  22.52,  22.68,  22.84,  23.01,
  23.17,  23.33,  23.5, 23.67,  23.83,  24, 24.17,
  24.34,  24.52,  24.69,  24.86,  25.04,  25.22,  25.39,
  25.57,  25.75,  25.94,  26.12,  26.3, 26.49,  26.68,
  26.86,  27.05,  27.24,  27.44,  27.63,  27.82,  28.02,
  28.22,  28.42,  28.62,  28.82,  29.02,  29.22,  29.43,
  29.64,  29.84,  30.05,  30.27,  30.48,  30.69,  30.91,
  31.12,  31.34,  31.56,  31.78,  32.01,  32.23,  32.46,
  32.68,  32.91,  33.14,  33.38,  33.61,  33.84,  34.08,
  34.32,  34.56,  34.8, 35.05,  35.29,  35.54,  35.79,
  36.04,  36.29,  36.54,  36.8, 37.05,  37.31,  37.57,
  37.83,  38.1, 38.36,  38.63,  38.9, 39.17,  39.45,
  39.72,  40, 40.28,  40.56,  40.84,  41.12,  41.41,
  41.7, 41.99,  42.28,  42.57,  42.87,  43.17,  43.47,
  43.77,  44.08,  44.38,  44.69,  45, 45.31,  45.63,
  45.95,  46.26,  46.59,  46.91,  47.24,  47.56,  47.89,
  48.23,  48.56,  48.9, 49.24,  49.58,  49.92,  50.27,
  50.62,  50.97,  51.32,  51.68,  52.03,  52.39,  52.76,
  53.12,  53.49,  53.86,  54.23,  54.61,  54.99,  55.37,
  55.75,  56.14,  56.53,  56.92,  57.31,  57.71,  58.11,
  58.51,  58.91,  59.32,  59.73,  60.14,  60.56,  60.98,
  61.4, 61.82,  62.25,  62.68,  63.11,  63.55,  63.99,
  64.43,  64.87,  65.32,  65.77,  66.23,  66.68,  67.14,
  67.61,  68.07,  68.54,  69.01,  69.49,  69.97,  70.45,
  70.94,  71.43,  71.92,  72.41,  72.91,  73.42,  73.92,
  74.43,  74.94,  75.46,  75.98,  76.5, 77.03,  77.56,
  78.09,  78.63,  79.17,  79.72,  80.27,  80.82,  81.38,
  81.94,  82.5, 83.07,  83.64,  84.21,  84.79,  85.38,
  85.96,  86.55,  87.15,  87.75,  88.35,  88.96,  89.57,
  90.19,  90.81,  91.43,  92.06,  92.69,  93.33,  93.97,
  94.62,  95.27,  95.92,  96.58,  97.24,  97.91,  98.58,
  99.26,  99.94,  100.63, 101.32, 102.01, 102.71, 103.42,
  104.13, 104.84, 105.56, 106.29, 107.02, 107.75, 108.49,
  109.23, 109.98, 110.74, 111.5,  112.26, 113.03, 113.81,
  114.59, 115.37, 116.16, 116.96, 117.76, 118.57, 119.38,
  120.2,  121.02, 121.85, 122.69, 123.53, 124.38, 125.23,
  126.09, 126.95, 127.82, 128.7,  129.58, 130.47, 131.36,
  132.26, 133.16, 134.08, 135,  135.92, 136.85, 137.79,
  138.73, 139.68, 140.64, 141.6,  142.57, 143.55, 144.53,
  145.52, 146.51, 147.52, 148.53, 149.54, 150.56, 151.6,
  152.63, 153.68, 154.73, 155.79, 156.85, 157.93, 159.01,
  160.09, 161.19, 162.29, 163.4,  164.52, 165.64, 166.78,
  167.92, 169.07, 170.22, 171.39, 172.56, 173.74, 174.92,
  176.12, 177.32, 178.54, 179.76, 180.99, 182.22, 183.47,
  184.72, 185.99, 187.26, 188.54, 189.82, 191.12, 192.43,
  193.74, 195.07, 196.4,  197.74, 199.09, 200.45, 201.82,
  203.2,  204.59, 205.99, 207.39, 208.81, 210.24, 211.67,
  213.12, 214.57, 216.04, 217.51, 219,  220.49, 222,
  223.52, 225.04, 226.58, 228.13, 229.68, 231.25, 232.83,
  234.42, 236.02, 237.63, 239.25, 240.89, 242.53, 244.19,
  245.85, 247.53, 249.22, 250.92, 252.63, 254.36, 256.09,
  257.84, 259.6,  261.37, 263.16, 264.95, 266.76, 268.58,
  270.41, 272.26, 274.11, 275.98, 277.87, 279.76, 281.67,
  283.59, 285.53, 287.47, 289.44, 291.41, 293.4,  295.4,
  297.41, 299.44, 301.48, 303.54, 305.61, 307.7,  309.79,
  311.91, 314.03, 316.17, 318.33, 320.5,  322.69, 324.89,
  327.1,  329.33, 331.58, 333.84, 336.12, 338.41, 340.71,
  343.04, 345.38, 347.73, 350.1,  352.49, 354.89, 357.31,
  359.75, 362.2,  364.67, 367.15, 369.65, 372.17, 374.71,
  377.27, 379.84, 382.43, 385.03, 387.66, 390.3,  392.96,
  395.64, 398.33, 401.05, 403.78, 406.53, 409.3,  412.09,
  414.9,  417.73, 420.57, 423.44, 426.32, 429.23, 432.15,
  435.1,  438.06, 441.05, 444.05, 447.08, 450.12, 453.19,
  456.28, 459.38, 462.51, 465.66, 468.84, 472.03, 475.25,
  478.48, 481.74, 485.02, 488.33, 491.65, 495,  498.37,
  501.77, 505.19, 508.63, 512.09, 515.58, 519.09, 522.63,
  526.19, 529.77, 533.38, 537.01, 540.67, 544.35, 548.06,
  551.79, 555.55, 559.33, 563.14, 566.97, 570.84, 574.72,
  578.64, 582.58, 586.54, 590.54, 594.56, 598.61, 602.68,
  606.79, 610.92, 615.08, 619.26, 623.48, 627.73, 632,
  636.3,  640.64, 645,  649.39, 653.81, 658.26, 662.74,
  667.25, 671.8,  676.37, 680.97, 685.61, 690.28, 694.98,
  699.71, 704.47, 709.27, 714.09, 718.96, 723.85, 728.78,
  733.74, 738.73, 743.76, 748.82, 753.92, 759.05, 764.22,
  769.42, 774.66, 779.93, 785.24, 790.58, 795.96, 801.38,
  806.84, 812.33, 817.86, 823.42, 829.03, 834.67, 840.35,
  846.07, 851.83, 857.62, 863.46, 869.34, 875.25, 881.21,
  887.21, 893.24, 899.32, 905.44, 911.61, 917.81, 924.05,
  930.34, 936.67, 943.05, 949.46, 955.93, 962.43, 968.98,
  975.57, 982.21, 988.9,  995.62, 1002.4, 1009.22,
  1016.09,  1023
};

// ONE HUNDRED WAVEFORMS, EACH WAVIER THAN THE LAST

const int16_t wave1[257] = {
0,  906,  1106, 1407, 1634, 1909, 2148, 2411, 2657, 2912, 3162, 3415, 3666, 3916, 4168, 4416, 4669, 4916, 5171, 5418, 
5672, 5920, 6175, 6423, 6676, 6924, 7178, 7426, 7680, 7929, 8182, 8432, 8684, 8934, 9185, 9436, 9687, 9938, 10189, 
10440, 10690, 10941, 11191, 11443, 11692, 11945, 12194, 12446, 12696, 12947, 13198, 13449, 13702, 13950, 14204, 14451,
 14706, 14952, 15209, 15452, 15712, 15953, 16215, 16455, 16719, 16955, 17219, 17457, 17720, 17961, 18220, 18466, 18719,
 18971, 19214, 19479, 19708, 19989, 20202, 20501, 20694, 21012, 21185, 21524, 21677, 22033, 22172, 22541, 22671, 23043,
 23175, 23540, 23685, 24028, 24205, 24509, 24732, 24980, 25269, 25440, 25814, 25895, 26368, 26342, 26924, 26786, 27483,
 27233, 28039, 27684, 28583, 28150, 29115, 28634, 29622, 29146, 30097, 29698, 30522, 30302, 30880, 30993, 31120, 31844,
 31114, 32767, 30248, 32767, -13140, -32767, -29141, -32768, -30050, -32768, -30128, -31941, -29980, -31147, -29734,
 -30425, -29431, -29747, -29084, -29108, -28702, -28500, -28291, -27922, -27853, -27369, -27392, -26837, -26910, -26326,
 -26410, -25829, -25898, -25342, -25379, -24864, -24852, -24388, -24323, -23913, -23795, -23439, -23268, -22959, -22744,
 -22476, -22227, -21989, -21714, -21497, -21203, -21000, -20699, -20500, -20197, -19998, -19696, -19494, -19199, -18987,
 -18701, -18482, -18204, -17976, -17706, -17470, -17209, -16965, -16709, -16462, -16209, -15957, -15708, -15455, -15208,
 -14954, -14705, -14451, -14204, -13950, -13702, -13448, -13200, -12948, -12698, -12446, -12196, -11944, -11693, -11442,
 -11192, -10940, -10690, -10440, -10189, -9938, -9687, -9435, -9185, -8933, -8683, -8432, -8182, -7928, -7680, -7426, 
 -7178, -6924, -6675, -6422, -6175, -5920, -5673, -5418, -5171, -4917, -4669, -4416, -4168, -3915, -3665, -3415, -3162,
 -2912, -2656, -2412, -2148, -1910, -1635, -1407, -1106, -906, 0};
 
const int16_t wave2[257] = {
0, 1556, 1699, 2047, 2245, 2539, 2760, 3030, 3265, 3522, 3763, 4014, 4260, 4503, 4751, 4992, 5243, 5481, 5734, 5972,
 6225, 6464, 6717, 6957, 7209, 7448, 7700, 7941, 8192, 8434, 8683, 8927, 9175, 9419, 9667, 9912, 10158, 10404, 10649, 
 10895, 11140, 11387, 11630, 11878, 12122, 12370, 12613, 12860, 13105, 13352, 13597, 13843, 14090, 14334, 14582, 14825,
 15075, 15315, 15568, 15806, 16060, 16296, 16553, 16788, 17046, 17277, 17537, 17770, 18027, 18263, 18517, 18758, 19005,
 19252, 19491, 19750, 19974, 20250, 20458, 20752, 20940, 21252, 21420, 21754, 21902, 22252, 22387, 22749, 22876, 23242,
 23370, 23729, 23871, 24206, 24379, 24676, 24896, 25137, 25422, 25588, 25956, 26032, 26498, 26470, 27043, 26905, 27591,
 27342, 28135, 27783, 28669, 28240, 29189, 28715, 29686, 29218, 30151, 29760, 30565, 30353, 30912, 31029, 31140, 31863,
 31123, 32767, 30247, 32767, -12872, -32767, -29162, -32768, -30082, -32768, -30169, -31958, -30030, -31180, -29793,
 -30473, -29499, -29808, -29159, -29180, -28785, -28584, -28383, -28017, -27954, -27475, -27501, -26954, -27029, -26454,
 -26539, -25968, -26038, -25492, -25530, -25024, -25013, -24558, -24496, -24094, -23978, -23630, -23461, -23159, -22948,
 -22686, -22442, -22209, -21939, -21727, -21439, -21240, -20944, -20751, -20453, -20258, -19963, -19765, -19475, -19268,
 -18988, -18773, -18501, -18278, -18014, -17782, -17526, -17288, -17036, -16794, -16547, -16300, -16056, -15809, -15567,
 -15317, -15074, -14825, -14582, -14334, -14090, -13843, -13599, -13352, -13107, -12860, -12615, -12369, -12123, -11877,
 -11631, -11386, -11140, -10895, -10649, -10404, -10158, -9911, -9667, -9418, -9174, -8927, -8684, -8433, -8192, -7941,
 -7700, -7448, -7208, -6956, -6717, -6464, -6226, -5972, -5734, -5482, -5243, -4992, -4751, -4502, -4259, -4014, -3763,
 -3522, -3264, -3031, -2760, -2540, -2246, -2047, -1699, -1556, 0};
 
const int16_t wave3[257] = {
0, 2207, 2293, 2687, 2857, 3168, 3372, 3650, 3872, 4131, 4365, 4613, 4854, 5091, 5335, 5568, 5816, 6045, 6298, 6526, 6778,
 7008, 7260, 7491, 7741, 7972, 8223, 8455, 8704, 8939, 9185, 9423, 9667, 9905, 10148, 10388, 10629, 10870, 11110, 11351,
 11590, 11832, 12070, 12314, 12551, 12795, 13033, 13275, 13514, 13756, 13996, 14238, 14479, 14718, 14961, 15198, 15443,
 15679, 15926, 16159, 16408, 16639, 16890, 17120, 17374, 17600, 17854, 18082, 18334, 18565, 18814, 19050, 19292, 19534,
 19767, 20022, 20240, 20510, 20714, 21002, 21185, 21492, 21656, 21983, 22128, 22471, 22603, 22958, 23082, 23440, 23566,
 23917, 24056, 24384, 24554, 24844, 25060, 25295, 25575, 25735, 26098, 26170, 26629, 26598, 27163, 27023, 27699, 27451,
 28232, 27883, 28754, 28331, 29264, 28797, 29751, 29291, 30206, 29823, 30608, 30403, 30943, 31066, 31161, 31882, 31133,
 32767, 30246, 32767, -12604, -32767, -29184, -32768, -30113, -32768, -30210, -31975, -30080, -31213, -29853, -30520,
 -29567, -29868, -29235, -29252, -28868, -28667, -28474, -28112, -28054, -27581, -27611, -27072, -27149, -26582, -26669,
 -26107, -26179, -25641, -25680, -25184, -25175, -24729, -24668, -24274, -24161, -23820, -23655, -23360, -23152, -22896,
 -22656, -22429, -22164, -21957, -21674, -21480, -21190, -21001, -20709, -20519, -20229, -20036, -19752, -19550, -19275,
 -19065, -18799, -18580, -18321, -18094, -17844, -17610, -17364, -17127, -16885, -16643, -16404, -16162, -15925, -15681,
 -15442, -15198, -14961, -14718, -14479, -14237, -13998, -13757, -13516, -13275, -13034, -12794, -12552, -12313, -12071,
 -11831, -11590, -11351, -11110, -10870, -10629, -10387, -10148, -9904, -9666, -9423, -9185, -8938, -8704, -8455, -8223,
 -7972, -7740, -7490, -7260, -7008, -6779, -6526, -6298, -6046, -5816, -5568, -5335, -5090, -4853, -4613, -4365, -4131,
 -3871, -3651, -3372, -3169, -2858, -2687, -2293, -2207, 0};
 
const int16_t wave4[257] = {
0, 2857, 2887, 3327, 3468, 3798, 3983, 4269, 4480, 4740, 4966, 5212, 5448, 5678, 5919, 6144,
 6390, 6610, 6861, 7080, 7331, 7551, 7803, 8025, 8274, 8496, 8745, 8970, 9216, 9443, 9687, 9918, 10158, 10390, 10629, 10863,
 11100, 11336, 11570, 11807, 12040, 12278, 12510, 12749, 12981, 13220, 13452, 13690, 13923, 14161, 14395, 14632, 14868, 15102,
 15339, 15572, 15812, 16042, 16284, 16512, 16756, 16982, 17228, 17453, 17701, 17922, 18171, 18395, 18641, 18868, 19110, 19341,
 19578, 19815, 20043, 20293, 20507, 20771, 20970, 21252, 21431, 21732, 21892, 22213, 22354, 22690, 22818, 23167, 23287, 23639,
 23761, 24105, 24241, 24562, 24729, 25012, 25224, 25452, 25728, 25883, 26240, 26307, 26759, 26725, 27282, 27141, 27806, 27560,
 28328, 27983, 28840, 28421, 29338, 28879, 29815, 29364, 30260, 29886, 30652, 30453, 30975, 31102, 31181, 31900, 31142, 32767,
 30245, 32767, -12335, -32767, -29205, -32768, -30144, -32768, -30250, -31991, -30130, -31246, -29912, -30568, -29635, -29929,
 -29310, -29324, -28951, -28751, -28565, -28206, -28154, -27687, -27721, -27189, -27268, -26711, -26799, -26246, -26319, -25791,
 -25831, -25344, -25336, -24899, -24840, -24455, -24344, -24011, -23848, -23560, -23356, -23106, -22871, -22649, -22389, -22187,
 -21909, -21721, -21436, -21251, -20965, -20779, -20496, -20307, -20029, -19831, -19562, -19356, -19096, -18881, -18628, -18406,
 -18161, -17933, -17692, -17460, -17223, -16986, -16753, -16515, -16283, -16044, -15811, -15572, -15339, -15102, -14868, -14631,
 -14396, -14161, -13925, -13690, -13454, -13219, -12982, -12748, -12511, -12277, -12040, -11807, -11570, -11336, -11100, -10862,
 -10629, -10389, -10157, -9918, -9687, -9443, -9216, -8970, -8745, -8496, -8273, -8024, -7803, -7551, -7332, -7080, -6861, -6611,
 -6390, -6144, -5919, -5677, -5447, -5212, -4966, -4740, -4479, -4270, -3983, -3799, -3469, -3327, -2887, -2857, 0};
 
const int16_t wave5[257] = {
0, 3507, 3480, 3967, 4079, 4428, 4595, 4889, 5088, 5349, 5568, 5811, 6042, 6266, 6502, 6719, 6963, 7175, 7424, 7635, 7884, 8095,
 8346, 8558, 8806, 9021, 9267, 9484, 9728, 9948, 10189, 10413, 10650, 10876, 11110, 11339, 11571, 11802, 12031, 12262, 12490,
 12723, 12950, 13184, 13410, 13645, 13871, 14105, 14332, 14565, 14793, 15026, 15257, 15486, 15718, 15946, 16180, 16406, 16642,
 16866, 17104, 17325, 17566, 17786, 18029, 18245, 18489, 18707, 18948, 19170, 19407, 19633, 19865, 20097, 20320, 20564, 20773,
 21032, 21226, 21503, 21677, 21972, 22128, 22442, 22579, 22909, 23034, 23376, 23493, 23837, 23957, 24294, 24427, 24740, 24904,
 25180, 25388, 25610, 25881, 26030, 26382, 26445, 26890, 26853, 27401, 27259, 27914, 27669, 28425, 28083, 28925, 28512, 29413,
 28960, 29879, 29437, 30315, 29948, 30695, 30504, 31007, 31138, 31202, 31919, 31152, 32767, 30244, 32767, -12067, -32767, -29227,
 -32768, -30176, -32768, -30291, -32008, -30181, -31279, -29971, -30616, -29704, -29989, -29385, -29396, -29034, -28834, -28657,
 -28301, -28255, -27794, -27831, -27306, -27388, -26839, -26929, -26385, -26459, -25940, -25982, -25504, -25498, -25069, -25013,
 -24635, -24528, -24201, -24042, -23760, -23560, -23316, -23085, -22869, -22614, -22417, -22145, -21961, -21682, -21502, -21221,
 -21040, -20762, -20578, -20305, -20112, -19849, -19648, -19393, -19183, -18936, -18719, -18479, -18255, -18020, -17792, -17561,
 -17329, -17101, -16869, -16642, -16408, -16179, -15946, -15718, -15486, -15257, -15025, -14795, -14566, -14334, -14105, -13873,
 -13644, -13411, -13183, -12951, -12722, -12490, -12262, -12031, -11802, -11571, -11338, -11110, -10875, -10649, -10413, -10189,
 -9947, -9728, -9484, -9267, -9021, -8805, -8557, -8346, -8095, -7885, -7635, -7424, -7176, -6963, -6719, -6502, -6265, -6041,
 -5811, -5568, -5349, -5087, -4890, -4595, -4429, -4080, -3967, -3480, -3507, 0};
 
const int16_t wave6[257] = {
0, 4157, 4074, 4607, 4690, 5058, 5207, 5508, 5696, 5959, 6169, 6410, 6635, 6854, 7086, 7295, 7537, 7740, 7987, 8189, 8437, 8639,
 8888, 9092, 9339, 9545, 9789, 9999, 10240, 10453, 10690, 10908, 11141, 11361, 11592, 11815, 12042, 12267, 12491, 12718, 12940,
 13169, 13389, 13619, 13840, 14070, 14290, 14519, 14741, 14970, 15192, 15420, 15645, 15870, 16097, 16320, 16549, 16769, 17001,
 17219, 17452, 17668, 17904, 18119, 18356, 18568, 18806, 19019, 19255, 19472, 19704, 19925, 20152, 20378, 20596, 20835, 21039,
 21293, 21482, 21753, 21923, 22211, 22363, 22672, 22805, 23128, 23250, 23584, 23698, 24036, 24152, 24482, 24612, 24918, 25078,
 25347, 25552, 25767, 26034, 26178, 26523, 26582, 27021, 26981, 27520, 27378, 28022, 27777, 28521, 28182, 29010, 28603, 29487,
 29042, 29943, 29509, 30369, 30011, 30738, 30554, 31039, 31174, 31223, 31938, 31162, 32767, 30243, 32767, -11799, -32767, -29248,
 -32768, -30207, -32768, -30332, -32025, -30231, -31312, -30030, -30664, -29772, -30050, -29460, -29468, -29117, -28918, -28748,
 -28396, -28355, -27900, -27940, -27423, -27507, -26967, -27058, -26523, -26599, -26090, -26133, -25663, -25659, -25239, -25185,
 -24815, -24711, -24391, -24236, -23960, -23764, -23526, -23300, -23089, -22838, -22647, -22380, -22201, -21927, -21752, -21477,
 -21301, -21028, -20848, -20582, -20393, -20136, -19939, -19690, -19485, -19243, -19031, -18796, -18577, -18347, -18125, -17899,
 -17672, -17449, -17222, -17000, -16771, -16548, -16320, -16097, -15870, -15645, -15420, -15194, -14970, -14743, -14519, -14292,
 -14069, -13840, -13618, -13390, -13168, -12940, -12718, -12491, -12268, -12042, -11814, -11592, -11360, -11140, -10908, -10691,
 -10452, -10240, -9999, -9789, -9545, -9338, -9091, -8888, -8639, -8438, -8189, -7987, -7741, -7537, -7295, -7086, -6853, -6635,
 -6410, -6169, -5959, -5695, -5509, -5207, -5059, -4691, -4607, -4074, -4157, 0};
 
const int16_t wave7[257] = {
0, 4808, 4668, 5247, 5302, 5687, 5819, 6128, 6303, 6568, 6771, 7009, 7229, 7441, 7670, 7871, 8110, 8304, 8550, 8743, 8990, 9183,
 9431, 9626, 9871, 10069, 10312, 10513, 10752, 10958, 11192, 11404, 11633, 11847, 12073, 12291, 12513, 12733, 12952, 13174, 13391,
 13614, 13829, 14054, 14269, 14495, 14709, 14934, 15150, 15374, 15591, 15815, 16034, 16254, 16475, 16694, 16917, 17133, 17359, 17572,
 17800, 18012, 18242, 18452, 18684, 18890, 19123, 19332, 19563, 19774, 20001, 20217, 20438, 20660, 20873, 21106, 21305, 21553, 21738,
 22003, 22169, 22451, 22599, 22901, 23030, 23347, 23465, 23793, 23904, 24234, 24348, 24670, 24797, 25096, 25253, 25515, 25716, 25925,
 26187, 26325, 26665, 26720, 27151, 27109, 27640, 27496, 28130, 27886, 28618, 28282, 29096, 28693, 29562, 29123, 30007, 29582, 30424,
 30073, 30781, 30604, 31070, 31210, 31243, 31957, 31171, 32767, 30242, 32767, -11531, -32767, -29270, -32768, -30238, -32768, -30373,
 -32042, -30281, -31346, -30090, -30712, -29840, -30110, -29535, -29540, -29200, -29001, -28840, -28491, -28455, -28006, -28050, -27541,
 -27627, -27095, -27188, -26662, -26739, -26239, -26284, -25823, -25821, -25409, -25357, -24996, -24894, -24582, -24429, -24160, -23968,
 -23736, -23514, -23309, -23063, -22877, -22615, -22441, -22173, -22003, -21733, -21561, -21295, -21119, -20859, -20675, -20423, -20231,
 -19987, -19787, -19551, -19343, -19114, -18900, -18675, -18458, -18237, -18015, -17797, -17575, -17358, -17135, -16916, -16694, -16475,
 -16254, -16034, -15814, -15593, -15375, -15152, -14934, -14711, -14494, -14270, -14053, -13830, -13613, -13390, -13174, -12952, -12733,
 -12513, -12290, -12073, -11846, -11632, -11404, -11192, -10957, -10752, -10513, -10312, -10069, -9870, -9625, -9431, -9183, -8991,
 -8743, -8550, -8305, -8110, -7871, -7670, -7440, -7228, -7009, -6771, -6568, -6302, -6129, -5819, -5688, -5303, -5247, -4668, -4808, 0};
 
const int16_t wave8[257] = {
0, 5458, 5261, 5887, 5913, 6317, 6431, 6747, 6911, 7177, 7372, 7608, 7823, 8029, 8253, 8447, 8683, 8869, 9113, 9297, 9543, 9727, 9974,
 10160, 10404, 10593, 10834, 11028, 11264, 11463, 11694, 11899, 12124, 12333, 12554, 12767, 12984, 13199, 13412, 13629, 13841, 14059,
 14269, 14489, 14698, 14920, 15128, 15349, 15559, 15779, 15990, 16209, 16423, 16638, 16854, 17067, 17286, 17497, 17717, 17926, 18148,
 18355, 18579, 18785, 19011, 19213, 19440, 19644, 19870, 20076, 20298, 20509, 20725, 20941, 21149, 21377, 21571, 21814, 21994, 22254, 
 22415, 22691, 22835, 23131, 23256, 23566, 23681, 24002, 24109, 24433, 24543, 24858, 24983, 25274, 25428, 25683, 25880, 26082, 26340,
 26473, 26807, 26857, 27282, 27237, 27759, 27614, 28238, 27995, 28714, 28382, 29181, 28784, 29636, 29205, 30071, 29655, 30478, 30136,
 30824, 30654, 31102, 31247, 31264, 31976, 31181, 32767, 30241, 32767, -11263, -32767, -29291, -32768, -30270, -32768, -30414, -32059,
 -30331, -31379, -30149, -30760, -29908, -30170, -29610, -29612, -29283, -29085, -28931, -28586, -28555, -28112, -28160, -27658, -27746,
 -27223, -27318, -26801, -26880, -26389, -26434, -25983, -25982, -25579, -25530, -25176, -25077, -24772, -24623, -24360, -24172, -23946,
 -23729, -23529, -23288, -23107, -22851, -22681, -22419, -22253, -21989, -21822, -21561, -21390, -21135, -20956, -20710, -20522, -20284,
 -20089, -19858, -19655, -19431, -19222, -19003, -18790, -18575, -18358, -18145, -17928, -17717, -17498, -17285, -17067, -16854, -16638,
 -16423, -16208, -15992, -15779, -15561, -15349, -15130, -14919, -14699, -14489, -14270, -14059, -13840, -13629, -13412, -13199, -12984,
 -12766, -12554, -12332, -12123, -11899, -11694, -11462, -11264, -11028, -10834, -10593, -10403, -10159, -9974, -9727, -9544, -9297,
 -9114, -8870, -8684, -8447, -8253, -8028, -7822, -7608, -7372, -7177, -6910, -6748, -6431, -6318, -5914, -5887, -5261, -5458, 0};
 
const int16_t wave9[257] = {
0, 6108, 5855, 6527, 6524, 6947, 7043, 7367, 7519, 7787, 7974, 8207, 8417, 8617, 8837, 9023, 9257, 9434, 9677, 9851, 10096, 10271, 10516,
 10694, 10936, 11117, 11356, 11542, 11776, 11968, 12196, 12394, 12616, 12818, 13035, 13243, 13455, 13665, 13873, 14085, 14291, 14505,
 14708, 14925, 15128, 15344, 15548, 15763, 15968, 16183, 16389, 16603, 16812, 17022, 17232, 17441, 17654, 17860, 18076, 18279, 18497,
 18698, 18917, 19117, 19339, 19535, 19758, 19956, 20177, 20378, 20595, 20801, 21011, 21223, 21425, 21649, 21837, 22075, 22250, 22504,
 22660, 22931, 23070, 23360, 23482, 23786, 23896, 24210, 24315, 24631, 24739, 25047, 25168, 25452, 25603, 25850, 26044, 26240, 26493,
 26620, 26949, 26995, 27412, 27365, 27878, 27733, 28346, 28104, 28811, 28481, 29266, 28875, 29711, 29287, 30136, 29727, 30533, 30199,
 30867, 30705, 31134, 31283, 31284, 31995, 31191, 32767, 30239, 32767, -10995, -32767, -29313, -32768, -30301, -32768, -30455, -32076,
 -30381, -31412, -30208, -30807, -29976, -30231, -29686, -29684, -29366, -29168, -29022, -28681, -28656, -28218, -28269, -27775, -27866,
 -27351, -27448, -26940, -27020, -26538, -26585, -26143, -26144, -25750, -25702, -25356, -25260, -24962, -24816, -24561, -24376, -24156,
 -23943, -23749, -23513, -23337, -23086, -22921, -22664, -22503, -22245, -22083, -21827, -21661, -21412, -21237, -20996, -20814, -20582,
 -20391, -20165, -19967, -19749, -19544, -19331, -19123, -18912, -18701, -18493, -18282, -18075, -17862, -17653, -17441, -17232, -17022,
 -16812, -16603, -16391, -16184, -15970, -15764, -15549, -15344, -15129, -14924, -14709, -14504, -14291, -14085, -13873, -13665, -13455,
 -13242, -13036, -12817, -12615, -12394, -12196, -11967, -11776, -11542, -11356, -11117, -10935, -10693, -10516, -10271, -10097, -9851,
 -9677, -9435, -9257, -9023, -8837, -8616, -8416, -8207, -7974, -7787, -7518, -7368, -7043, -6948, -6525, -6527, -5855, -6108, 0};
 
const int16_t wave10[257] = {
0, 6758, 6449, 7167, 7135, 7577, 7655, 7986, 8127, 8396, 8575, 8806, 9011, 9204, 9421, 9599, 9830, 9999, 10240, 10405, 10649, 10815, 11059,
 11228, 11469, 11641, 11878, 12057, 12288, 12473, 12697, 12889, 13107, 13304, 13517, 13718, 13926, 14131, 14333, 14541, 14741, 14950,
 15148, 15360, 15557, 15769, 15967, 16178, 16377, 16588, 16788, 16997, 17200, 17406, 17611, 17815, 18023, 18224, 18434, 18632, 18845,
 19041, 19255, 19450, 19666, 19858, 20075, 20269, 20484, 20681, 20892, 21093, 21298, 21505, 21702, 21920, 22103, 22336, 22506, 22754,
 22906, 23171, 23306, 23589, 23707, 24005, 24112, 24419, 24521, 24829, 24934, 25235, 25353, 25630, 25777, 26018, 26208, 26397, 26646,
 26768, 27091, 27133, 27543, 27492, 27997, 27851, 28453, 28213, 28907, 28581, 29352, 28965, 29785, 29368, 30200, 29800, 30587, 30261,
 30911, 30755, 31166, 31319, 31305, 32013, 31200, 32767, 30238, 32767, -10726, -32767, -29334, -32768, -30332, -32768, -30495, -32093,
 -30431, -31445, -30267, -30855, -30044, -30291, -29761, -29756, -29449, -29252, -29114, -28775, -28756, -28324, -28379, -27892, -27986,
 -27480, -27577, -27079, -27160, -26688, -26736, -26303, -26306, -25920, -25874, -25537, -25443, -25153, -25010, -24761, -24580, -24366,
 -24158, -23969, -23738, -23567, -23321, -23162, -22910, -22754, -22501, -22343, -22094, -21932, -21689, -21518, -21283, -21106, -20879,
 -20693, -20473, -20279, -20066, -19867, -19658, -19456, -19250, -19044, -18842, -18635, -18433, -18226, -18022, -17815, -17611, -17406,
 -17200, -16997, -16790, -16588, -16379, -16178, -15969, -15769, -15558, -15359, -15149, -14949, -14741, -14541, -14333, -14131, -13926,
 -13717, -13517, -13303, -13106, -12889, -12698, -12472, -12288, -12057, -11878, -11641, -11468, -11227, -11059, -10815, -10650, -10405,
 -10240, -10000, -9830, -9599, -9421, -9203, -9010, -8806, -8576, -8396, -8126, -7987, -7655, -7578, -7136, -7167, -6449, -6758, 0};
 
const int16_t wave11[257] = {
0, 7408, 7042, 7807, 7746, 8206, 8266, 8606, 8734, 9005, 9177, 9405, 9605, 9792, 10004, 10175, 10404, 10563, 10803, 10959, 11202, 11358,
 11602, 11762, 12001, 12165, 12400, 12571, 12800, 12977, 13199, 13385, 13599, 13789, 13998, 14194, 14397, 14597, 14794, 14996, 15191,
 15396, 15588, 15795, 15987, 16194, 16386, 16593, 16786, 16992, 17187, 17392, 17589, 17790, 17990, 18189, 18391, 18587, 18792, 18986, 
 19193, 19384, 19593, 19783, 19994, 20181, 20392, 20581, 20791, 20983, 21188, 21384, 21585, 21786, 21978, 22191, 22370, 22597, 22762,
 23005, 23152, 23411, 23542, 23819, 23933, 24224, 24328, 24628, 24726, 25028, 25130, 25423, 25539, 25808, 25952, 26186, 26372, 26555,
 26799, 26915, 27233, 27270, 27674, 27620, 28117, 27969, 28561, 28322, 29004, 28681, 29437, 29056, 29860, 29450, 30264, 29873, 30642,
 30324, 30954, 30805, 31198, 31355, 31326, 32032, 31210, 32767, 30237, 32767, -10458, -32767, -29356, -32768, -30364, -32768, -30536,
 -32109, -30481, -31478, -30327, -30903, -30112, -30352, -29836, -29828, -29532, -29335, -29205, -28870, -28856, -28430, -28489, -28009,
 -28105, -27608, -27707, -27218, -27300, -26837, -26887, -26463, -26467, -26090, -26047, -25717, -25626, -25343, -25204, -24961, -24784,
 -24576, -24372, -24189, -23963, -23797, -23557, -23402, -23156, -23004, -22757, -22604, -22360, -22203, -21965, -21800, -21570, -21397,
 -21176, -20994, -20780, -20591, -20384, -20189, -19986, -19788, -19588, -19387, -19190, -18988, -18792, -18589, -18390, -18189, -17990,
 -17790, -17589, -17391, -17188, -16993, -16788, -16593, -16388, -16194, -15987, -15794, -15589, -15395, -15191, -14996, -14794, -14597,
 -14397, -14193, -13998, -13788, -13598, -13385, -13199, -12977, -12800, -12571, -12401, -12165, -12000, -11761, -11602, -11358, -11203,
 -10959, -10803, -10564, -10404, -10175, -10004, -9791, -9604, -9405, -9177, -9005, -8733, -8607, -8266, -8207, -7747, -7807, -7042, -7409, 0};
 
const int16_t wave12[257] = {
0, 8059, 7636, 8447, 8358, 8836, 8878, 9225, 9342, 9614, 9778, 10004, 10199, 10379, 10588, 10751, 10977, 11128, 11366, 11513, 11755, 11902,
 12144, 12296, 12534, 12689, 12923, 13086, 13312, 13482, 13701, 13880, 14090, 14275, 14479, 14670, 14868, 15063, 15254, 15452, 15641,
 15841, 16027, 16230, 16416, 16619, 16805, 17008, 17195, 17397, 17586, 17786, 17978, 18174, 18368, 18563, 18760, 18951, 19150, 19339,
 19541, 19727, 19931, 20116, 20321, 20503, 20710, 20894, 21098, 21285, 21485, 21676, 21871, 22068, 22254, 22462, 22636, 22857, 23018,
 23255, 23398, 23651, 23778, 24048, 24159, 24443, 24543, 24836, 24932, 25226, 25325, 25612, 25724, 25986, 26127, 26354, 26536, 26712,
 26952, 27063, 27375, 27408, 27804, 27748, 28236, 28087, 28669, 28431, 29100, 28780, 29523, 29146, 29934, 29532, 30328, 29945, 30696,
 30387, 30997, 30856, 31229, 31391, 31346, 32051, 31219, 32767, 30236, 32767, -10190, -32767, -29377, -32768, -30395, -32768, -30577,
 -32126, -30531, -31511, -30386, -30951, -30180, -30412, -29911, -29900, -29615, -29419, -29296, -28965, -28957, -28536, -28599, -28127,
 -28225, -27736, -27837, -27357, -27440, -26987, -27038, -26623, -26629, -26260, -26219, -25898, -25809, -25534, -25397, -25161, -24988,
 -24786, -24587, -24409, -24188, -24027, -23792, -23642, -23401, -23254, -23013, -22864, -22627, -22474, -22242, -22081, -21857, -21689,
 -21473, -21296, -21087, -20903, -20701, -20512, -20314, -20121, -19926, -19730, -19538, -19342, -19150, -18953, -18759, -18563, -18368,
 -18174, -17978, -17785, -17587, -17397, -17197, -17008, -16807, -16619, -16417, -16229, -16028, -15840, -15641, -15452, -15254, -15063,
 -14868, -14669, -14479, -14274, -14089, -13880, -13701, -13482, -13312, -13086, -12923, -12689, -12533, -12295, -12145, -11902, -11756,
 -11513, -11366, -11129, -10977, -10751, -10588, -10378, -10198, -10004, -9779, -9614, -9341, -9226, -8878, -8837, -8359, -8447, -7636, -8059, 0};
 
const int16_t wave13[257] = {
0, 8709, 8230, 9087, 8969, 9466, 9490, 9845, 9950, 10224, 10380, 10603, 10793, 10967, 11172, 11326, 11550, 11693, 11929, 12067, 12307,
 12446, 12687, 12829, 13066, 13214, 13445, 13600, 13824, 13987, 14203, 14375, 14582, 14761, 14960, 15146, 15339, 15529, 15715, 15908,
 16091, 16286, 16467, 16665, 16845, 17044, 17224, 17422, 17604, 17801, 17984, 18180, 18367, 18558, 18747, 18936, 19128, 19315, 19509,
 19692, 19889, 20070, 20268, 20449, 20649, 20826, 21027, 21206, 21405, 21587, 21782, 21968, 22158, 22349, 22531, 22733, 22902, 23118,
 23273, 23505, 23644, 23891, 24013, 24278, 24384, 24662, 24759, 25045, 25137, 25425, 25521, 25800, 25909, 26164, 26302, 26521, 26700,
 26870, 27105, 27210, 27517, 27545, 27935, 27876, 28355, 28206, 28777, 28540, 29197, 28880, 29608, 29237, 30009, 29613, 30392, 30018,
 30751, 30449, 31040, 30906, 31261, 31428, 31367, 32070, 31229, 32767, 30235, 32767, -9922, -32767, -29399, -32768, -30426, -32768,
 -30618, -32143, -30582, -31544, -30445, -30999, -30248, -30472, -29986, -29971, -29698, -29502, -29388, -29060, -29057, -28643,
 -28708, -28244, -28344, -27864, -27967, -27496, -27581, -27136, -27188, -26783, -26790, -26430, -26391, -26078, -25993, -25724,
 -25591, -25361, -25193, -24997, -24801, -24629, -24413, -24257, -24027, -23882, -23647, -23505, -23270, -23125, -22893, -22745,
 -22519, -22362, -22144, -21980, -21770, -21598, -21395, -21216, -21019, -20834, -20642, -20454, -20264, -20073, -19886, -19695,
 -19508, -19316, -19127, -18936, -18747, -18559, -18367, -18180, -17986, -17802, -17606, -17423, -17226, -17044, -16846, -16665,
 -16468, -16286, -16091, -15908, -15715, -15529, -15340, -15145, -14961, -14760, -14581, -14375, -14203, -13986, -13824, -13600,
 -13445, -13214, -13065, -12828, -12687, -12446, -12308, -12068, -11930, -11694, -11551, -11326, -11172, -10966, -10792, -10604,
 -10380, -10224, -9949, -9846, -9490, -9467, -8970, -9087, -8230, -8709, 0};
 
const int16_t wave14[257] = {
0, 9359, 8824, 9727, 9580, 10096, 10102, 10464, 10558, 10833, 10982, 11202, 11387, 11555, 11755, 11902, 12124, 12258, 12493, 12621,
 12860, 12990, 13230, 13363, 13598, 13738, 13967, 14114, 14336, 14492, 14704, 14870, 15073, 15246, 15442, 15622, 15810, 15995, 16176,
 16363, 16541, 16732, 16907, 17101, 17275, 17469, 17644, 17837, 18013, 18206, 18383, 18574, 18755, 18942, 19125, 19310, 19496, 19678,
 19867, 20046, 20237, 20413, 20606, 20781, 20976, 21148, 21344, 21518, 21712, 21889, 22079, 22260, 22444, 22631, 22807, 23005, 23168,
 23379, 23529, 23755, 23889, 24131, 24249, 24507, 24610, 24881, 24974, 25254, 25343, 25623, 25716, 25988, 26095, 26342, 26476, 26689,
 26864, 27027, 27258, 27357, 27659, 27683, 28065, 28004, 28474, 28324, 28885, 28649, 29293, 28980, 29693, 29328, 30084, 29695, 30457,
 30091, 30805, 30512, 31083, 30956, 31293, 31464, 31387, 32089, 31239, 32767, 30234, 32767, -9654, -32767, -29421, -32768, -30457,
 -32768, -30659, -32160, -30632, -31577, -30504, -31046, -30316, -30533, -30062, -30043, -29781, -29585, -29479, -29155, -29157, 
 -28749, -28818, -28361, -28464, -27992, -28096, -27635, -27721, -27286, -27339, -26943, -26952, -26601, -26564, -26258, -26176,
 -25914, -25784, -25562, -25397, -25207, -25016, -24849, -24638, -24487, -24262, -24122, -23893, -23755, -23526, -23386, -23159,
 -23016, -22795, -22643, -22431, -22272, -22068, -21900, -21702, -21528, -21337, -21156, -20969, -20787, -20602, -20416, -20234,
 -20048, -19866, -19680, -19496, -19310, -19125, -18943, -18755, -18574, -18385, -18206, -18015, -17837, -17645, -17469, -17276,
 -17100, -16908, -16731, -16541, -16364, -16176, -15995, -15811, -15621, -15442, -15245, -15072, -14870, -14705, -14491, -14336,
 -14114, -13967, -13738, -13598, -13362, -13230, -12990, -12861, -12622, -12493, -12259, -12124, -11902, -11756, -11554, -11386,
 -11203, -10982, -10833, -10557, -10465, -10102, -10097, -9581, -9727, -8824, -9359, 0};
 
const int16_t wave15[257] = {
0, 10009, 9417, 10367, 10191, 10725, 10714, 11084, 11165, 11442, 11583, 11801, 11981, 12142, 12339, 12478, 12697, 12822, 13056, 13176,
 13413, 13534, 13773, 13897, 14131, 14262, 14489, 14629, 14848, 14997, 15206, 15366, 15565, 15732, 15923, 16098, 16281, 16461, 16636,
 16819, 16991, 17177, 17347, 17536, 17704, 17894, 18063, 18252, 18422, 18610, 18782, 18969, 19144, 19326, 19504, 19684, 19865, 20042,
 20225, 20399, 20585, 20756, 20944, 21114, 21304, 21471, 21662, 21831, 22019, 22191, 22376, 22552, 22731, 22912, 23083, 23276, 23434,
 23640, 23785, 24006, 24135, 24371, 24485, 24737, 24836, 25100, 25190, 25463, 25548, 25822, 25912, 26177, 26280, 26520, 26651, 26857,
 27028, 27185, 27411, 27505, 27801, 27820, 28196, 28132, 28594, 28442, 28993, 28758, 29390, 29080, 29779, 29418, 30158, 29777, 30521,
 30164, 30860, 30575, 31126, 31007, 31325, 31500, 31408, 32108, 31248, 32767, 30233, 32767, -9386, -32767, -29442, -32768, -30489,
 -32768, -30700, -32177, -30682, -31610, -30564, -31094, -30385, -30593, -30137, -30115, -29864, -29669, -29570, -29250, -29258, -28855,
 -28928, -28478, -28583, -28120, -28226, -27774, -27861, -27435, -27490, -27103, -27113, -26771, -26736, -26439, -26359, -26105, -25978,
 -25762, -25601, -25417, -25230, -25069, -24863, -24717, -24498, -24362, -24139, -24005, -23782, -23646, -23426, -23287, -23072, -22925,
 -22718, -22563, -22365, -22202, -22009, -21840, -21654, -21479, -21297, -21119, -20940, -20759, -20582, -20402, -20225, -20043, -19864,
 -19684, -19504, -19327, -19144, -18968, -18784, -18611, -18424, -18252, -18064, -17894, -17705, -17535, -17348, -17177, -16991, -16819,
 -16636, -16461, -16282, -16097, -15923, -15731, -15564, -15366, -15206, -14996, -14848, -14629, -14490, -14262, -14130, -13896, -13773,
 -13534, -13414, -13176, -13056, -12823, -12698, -12478, -12339, -12141, -11980, -11802, -11583, -11442, -11164, -11085, -10714, -10726,
 -10192, -10367, -9417, -10010, 0};
 
const int16_t wave16[257] = {
0, 10660, 10011, 11007, 10803, 11355, 11326, 11703, 11773, 12051, 12185, 12400, 12574, 12730, 12923, 13054, 13271, 13387, 13619, 13730,
 13966, 14078, 14315, 14431, 14663, 14786, 15012, 15143, 15360, 15502, 15708, 15861, 16056, 16217, 16404, 16573, 16752, 16926, 17097,
 17275, 17441, 17623, 17786, 17971, 18134, 18319, 18482, 18667, 18831, 19015, 19181, 19363, 19533, 19710, 19883, 20058, 20233, 20405,
 20583, 20752, 20933, 21099, 21282, 21447, 21631, 21794, 21979, 22143, 22326, 22494, 22673, 22844, 23018, 23194, 23360, 23547, 23700,
 23900, 24041, 24256, 24381, 24610, 24721, 24966, 25061, 25319, 25406, 25671, 25754, 26020, 26107, 26365, 26465, 26698, 26826, 27025,
 27192, 27342, 27564, 27652, 27942, 27958, 28327, 28259, 28713, 28560, 29100, 28866, 29486, 29179, 29864, 29509, 30233, 29858, 30585,
 30236, 30914, 30637, 31170, 31057, 31356, 31536, 31429, 32126, 31258, 32767, 30232, 32767, -9117, -32767, -29464, -32768, -30520,
 -32768, -30740, -32194, -30732, -31643, -30623, -31142, -30453, -30654, -30212, -30187, -29947, -29752, -29662, -29344, -29358, -28961,
 -29038, -28596, -28703, -28249, -28356, -27912, -28001, -27585, -27641, -27262, -27275, -26941, -26908, -26619, -26542, -26295, -26172,
 -25962, -25805, -25627, -25445, -25289, -25087, -24947, -24733, -24603, -24384, -24256, -24038, -23907, -23692, -23557, -23349, -23206,
 -23005, -22855, -22662, -22504, -22317, -22152, -21972, -21801, -21625, -21452, -21278, -21102, -20931, -20755, -20583, -20407, -20233,
 -20058, -19883, -19711, -19533, -19362, -19183, -19015, -18833, -18667, -18484, -18319, -18134, -17970, -17787, -17622, -17441, -17275,
 -17097, -16927, -16753, -16572, -16404, -16216, -16055, -15861, -15708, -15501, -15360, -15143, -15012, -14786, -14663, -14430, -14316,
 -14078, -13967, -13730, -13619, -13388, -13271, -13054, -12923, -12729, -12574, -12401, -12185, -12051, -11772, -11704, -11326, -11356,
 -10804, -11007, -10011, -10660, 0};
 
const int16_t wave17[257] = {
0, 11310, 10605, 11647, 11414, 11985, 11938, 12323, 12381, 12661, 12786, 12999, 13168, 13318, 13506, 13630, 13844, 13952, 14182, 14284,
 14519, 14622, 14858, 14965, 15196, 15310, 15534, 15658, 15872, 16007, 16210, 16356, 16548, 16703, 16885, 17049, 17223, 17392, 17557,
 17730, 17891, 18068, 18226, 18406, 18563, 18744, 18901, 19081, 19240, 19419, 19580, 19757, 19922, 20094, 20261, 20432, 20602, 20769,
 20942, 21106, 21281, 21442, 21620, 21780, 21959, 22116, 22296, 22455, 22633, 22796, 22970, 23136, 23304, 23476, 23636, 23818, 23966,
 24161, 24297, 24506, 24627, 24850, 24956, 25195, 25287, 25538, 25621, 25880, 25960, 26218, 26303, 26553, 26651, 26876, 27001, 27192,
 27356, 27500, 27717, 27800, 28084, 28096, 28457, 28387, 28832, 28679, 29208, 28975, 29583, 29279, 29949, 29600, 30307, 29940, 30649,
 30309, 30969, 30700, 31213, 31107, 31388, 31572, 31449, 32145, 31268, 32767, 30231, 32767, -8849, -32767, -29485, -32768, -30551,
 -32768, -30781, -32211, -30782, -31676, -30682, -31190, -30521, -30714, -30287, -30259, -30030, -29836, -29753, -29439, -29458, -29067,
 -29147, -28713, -28823, -28377, -28486, -28051, -28141, -27734, -27792, -27422, -27437, -27111, -27081, -26799, -26725, -26485, -26365,
 -26162, -26009, -25837, -25659, -25509, -25312, -25177, -24968, -24843, -24630, -24506, -24294, -24168, -23958, -23828, -23625, -23487,
 -23292, -23147, -22959, -22806, -22624, -22464, -22289, -22123, -21953, -21785, -21616, -21445, -21279, -21108, -20941, -20771, -20601,
 -20432, -20261, -20095, -19922, -19757, -19582, -19420, -19242, -19082, -18903, -18744, -18564, -18405, -18227, -18067, -17891, -17731,
 -17557, -17393, -17224, -17048, -16886, -16702, -16547, -16356, -16210, -16006, -15872, -15658, -15534, -15310, -15195, -14964, -14858,
 -14622, -14520, -14284, -14182, -13953, -13844, -13630, -13507, -13317, -13168, -13000, -12787, -12661, -12380, -12324, -11938, -11986,
 -11415, -11647, -10605, -11310, 0};
 
const int16_t wave18[257] = {
0, 11960, 11198, 12287, 12025, 12615, 12549, 12942, 12989, 13270, 13388, 13598, 13762, 13905, 14090, 14206, 14418, 14517, 14745, 14838,
 15072, 15165, 15401, 15499, 15728, 15834, 16056, 16172, 16384, 16511, 16711, 16851, 17039, 17188, 17367, 17525, 17694, 17858, 18018,
 18186, 18341, 18514, 18666, 18841, 18993, 19169, 19320, 19496, 19649, 19824, 19979, 20151, 20310, 20478, 20640, 20805, 20970, 21132,
 21300, 21459, 21629, 21785, 21957, 22113, 22286, 22439, 22613, 22768, 22940, 23098, 23266, 23427, 23591, 23757, 23912, 24089, 24233,
 24422, 24553, 24757, 24873, 25090, 25192, 25425, 25513, 25757, 25837, 26089, 26165, 26417, 26498, 26741, 26836, 27054, 27175, 27360,
 27520, 27657, 27870, 27947, 28226, 28233, 28588, 28515, 28951, 28797, 29316, 29084, 29679, 29379, 30035, 29690, 30382, 30022, 30713,
 30382, 31023, 30763, 31256, 31157, 31420, 31609, 31470, 32164, 31277, 32767, 30230, 32767, -8581, -32767, -29507, -32768, -30583,
 -32768, -30822, -32227, -30832, -31709, -30741, -31238, -30589, -30775, -30362, -30331, -30113, -29919, -29844, -29534, -29558, -29173,
 -29257, -28830, -28942, -28505, -28615, -28190, -28282, -27884, -27942, -27582, -27598, -27281, -27253, -26980, -26908, -26676, -26559,
 -26362, -26213, -26047, -25874, -25729, -25537, -25407, -25204, -25083, -24876, -24756, -24550, -24428, -24225, -24099, -23902, -23768,
 -23579, -23438, -23256, -23107, -22931, -22776, -22607, -22446, -22280, -22117, -21954, -21788, -21627, -21461, -21300, -21134, -20970,
 -20805, -20640, -20479, -20310, -20151, -19980, -19824, -19651, -19496, -19322, -19169, -18993, -18841, -18667, -18513, -18341, -18186,
 -18018, -17859, -17695, -17524, -17367, -17187, -17038, -16851, -16712, -16511, -16384, -16172, -16056, -15834, -15728, -15498, -15401,
 -15165, -15073, -14838, -14746, -14518, -14418, -14206, -14090, -13904, -13762, -13599, -13388, -13270, -12988, -12943, -12549, -12616,
 -12026, -12287, -11198, -11960, 0};
 
const int16_t wave19[257] = {
0, 12610, 11792, 12927, 12636, 13244, 13161, 13562, 13596, 13879, 13989, 14197, 14356, 14493, 14674, 14782, 14991, 15081, 15308, 15392,
 15625, 15709, 15943, 16033, 16261, 16358, 16578, 16687, 16896, 17016, 17213, 17347, 17531, 17674, 17848, 18001, 18165, 18324, 18478,
 18642, 18792, 18959, 19105, 19276, 19422, 19594, 19739, 19911, 20058, 20228, 20378, 20546, 20699, 20862, 21018, 21179, 21339, 21496,
 21658, 21812, 21977, 22129, 22295, 22446, 22614, 22761, 22931, 23080, 23248, 23400, 23563, 23719, 23877, 24039, 24189, 24360, 24499,
 24683, 24809, 25007, 25119, 25330, 25428, 25654, 25738, 25976, 26052, 26297, 26371, 26615, 26694, 26930, 27021, 27232, 27350, 27528,
 27684, 27815, 28023, 28095, 28368, 28371, 28718, 28643, 29071, 28915, 29424, 29193, 29776, 29478, 30120, 29781, 30456, 30103, 30777,
 30454, 31078, 30825, 31299, 31208, 31452, 31645, 31490, 32183, 31287, 32767, 30229, 32767, -8313, -32767, -29528, -32768, -30614, -32768,
 -30863, -32244, -30882, -31743, -30801, -31286, -30657, -30835, -30437, -30403, -30196, -30003, -29936, -29629, -29659, -29279, -29367,
 -28947, -29062, -28633, -28745, -28329, -28422, -28033, -28093, -27742, -27760, -27451, -27425, -27160, -27091, -26866, -26752, -26562,
 -26417, -26257, -26088, -25949, -25762, -25637, -25439, -25323, -25121, -25007, -24806, -24689, -24491, -24370, -24179, -24050, -23866,
 -23730, -23553, -23409, -23239, -23088, -22924, -22768, -22608, -22450, -22292, -22131, -21975, -21815, -21658, -21498, -21338, -21179,
 -21018, -20863, -20699, -20545, -20379, -20229, -20060, -19911, -19741, -19594, -19423, -19276, -19106, -18958, -18791, -18642, -18478,
 -18324, -18166, -18000, -17848, -17673, -17530, -17347, -17213, -17016, -16896, -16687, -16579, -16358, -16260, -16032, -15944, -15709,
 -15626, -15392, -15309, -15082, -14991, -14782, -14674, -14492, -14355, -14198, -13990, -13879, -13595, -13563, -13161, -13245, -12637,
 -12927, -11792, -12611, 0};
 
const int16_t wave20[257] = {
0, 13260, 12386, 13567, 13247, 13874, 13773, 14181, 14204, 14489, 14591, 14796, 14950, 15080, 15257, 15358, 15564, 15646, 15872, 15946,
 16178, 16253, 16486, 16567, 16793, 16882, 17100, 17201, 17408, 17521, 17715, 17842, 18022, 18160, 18329, 18477, 18636, 18790, 18939,
 19097, 19242, 19404, 19545, 19712, 19851, 20019, 20159, 20325, 20467, 20633, 20777, 20940, 21088, 21246, 21397, 21553, 21707, 21860,
 22017, 22166, 22325, 22472, 22633, 22778, 22941, 23084, 23248, 23393, 23555, 23702, 23860, 24011, 24164, 24320, 24465, 24632, 24765,
 24944, 25065, 25257, 25364, 25570, 25663, 25884, 25964, 26195, 26268, 26506, 26576, 26814, 26889, 27118, 27207, 27410, 27525, 27695,
 27848, 27972, 28176, 28242, 28510, 28508, 28849, 28771, 29190, 29034, 29532, 29302, 29872, 29578, 30206, 29871, 30531, 30185, 30842,
 30527, 31132, 30888, 31342, 31258, 31484, 31681, 31511, 32202, 31296, 32767, 30228, 32767, -8045, -32767, -29550, -32768, -30645, -32768,
 -30904, -32261, -30932, -31776, -30860, -31333, -30725, -30895, -30513, -30475, -30279, -30086, -30027, -29724, -29759, -29385, -29476,
 -29064, -29181, -28761, -28875, -28468, -28562, -28183, -28244, -27902, -27921, -27622, -27598, -27341, -27274, -27057, -26946, -26763,
 -26621, -26467, -26303, -26169, -25987, -25867, -25674, -25563, -25367, -25257, -25062, -24949, -24758, -24641, -24455, -24331, -24153,
 -24021, -23851, -23711, -23546, -23400, -23242, -23091, -22936, -22783, -22630, -22474, -22323, -22168, -22016, -21861, -21707, -21553,
 -21397, -21247, -21088, -20940, -20778, -20633, -20469, -20326, -20160, -20019, -19852, -19711, -19546, -19404, -19241, -19098, -18939,
 -18790, -18637, -18476, -18330, -18159, -18021, -17842, -17715, -17521, -17408, -17201, -17101, -16882, -16793, -16566, -16486, -16253,
 -16179, -15946, -15872, -15647, -15565, -15358, -15258, -15079, -14949, -14797, -14591, -14489, -14203, -14182, -13773, -13875, -13248,
 -13567, -12386, -13261, 0};
 
const int16_t wave21[257] = {
0, 13911, 12979, 14207, 13859, 14504, 14385, 14801, 14812, 15098, 15192, 15395, 15544, 15668, 15841, 15933, 16138, 16211, 16435, 16500,
 16731, 16797, 17029, 17100, 17326, 17407, 17623, 17716, 17920, 18026, 18217, 18337, 18514, 18645, 18810, 18953, 19107, 19256, 19399,
 19553, 19692, 19850, 19985, 20147, 20281, 20444, 20578, 20740, 20876, 21037, 21175, 21334, 21477, 21630, 21776, 21927, 22076, 22223,
 22375, 22519, 22673, 22815, 22971, 23111, 23269, 23407, 23565, 23705, 23862, 24004, 24157, 24303, 24451, 24602, 24742, 24903, 25031,
 25204, 25321, 25508, 25610, 25810, 25899, 26113, 26189, 26414, 26484, 26715, 26782, 27012, 27085, 27306, 27392, 27588, 27700, 27863,
 28012, 28130, 28329, 28390, 28652, 28646, 28980, 28899, 29309, 29152, 29640, 29411, 29969, 29678, 30291, 29962, 30605, 30266, 30906,
 30600, 31187, 30950, 31385, 31308, 31515, 31717, 31532, 32221, 31306, 32767, 30227, 32767, -7777, -32767, -29571, -32768, -30677, -32768,
 -30945, -32278, -30983, -31809, -30919, -31381, -30793, -30956, -30588, -30547, -30362, -30170, -30119, -29819, -29859, -29492, -29586,
 -29182, -29301, -28889, -29005, -28607, -28702, -28332, -28395, -28062, -28083, -27792, -27770, -27521, -27458, -27247, -27140, -26963,
 -26825, -26677, -26517, -26389, -26212, -26097, -25910, -25803, -25613, -25508, -25318, -25210, -25024, -24912, -24732, -24612, -24440,
 -24313, -24148, -24013, -23854, -23713, -23559, -23413, -23264, -23115, -22968, -22817, -22671, -22521, -22375, -22225, -22075, -21927,
 -21776, -21631, -21477, -21334, -21177, -21038, -20878, -20741, -20579, -20444, -20281, -20146, -19986, -19849, -19691, -19553, -19399,
 -19256, -19108, -18952, -18811, -18644, -18513, -18337, -18217, -18025, -17920, -17716, -17623, -17407, -17325, -17099, -17029, -16797,
 -16732, -16501, -16435, -16212, -16138, -15933, -15841, -15667, -15543, -15396, -15193, -15098, -14811, -14802, -14385, -14505, -13860,
 -14207, -12979, -13911, 0};
 
const int16_t wave22[257] = {
0, 14561, 13573, 14847, 14470, 15134, 14997, 15420, 15420, 15707, 15794, 15994, 16138, 16256, 16425, 16509, 16711, 16776, 16998, 17054,
 17284, 17341, 17571, 17634, 17858, 17931, 18145, 18230, 18432, 18531, 18718, 18832, 19005, 19131, 19292, 19428, 19578, 19722, 19860,
 20009, 20142, 20295, 20424, 20582, 20710, 20869, 20997, 21155, 21285, 21442, 21574, 21728, 21865, 22014, 22154, 22301, 22444, 22587,
 22733, 22872, 23021, 23158, 23309, 23444, 23596, 23729, 23883, 24017, 24169, 24307, 24454, 24595, 24737, 24883, 25018, 25174, 25297,
 25465, 25577, 25758, 25856, 26050, 26135, 26343, 26415, 26633, 26699, 26923, 26987, 27211, 27280, 27495, 27577, 27766, 27874, 28031,
 28176, 28287, 28482, 28537, 28794, 28783, 29110, 29026, 29428, 29270, 29747, 29520, 30065, 29777, 30376, 30053, 30680, 30348, 30970,
 30672, 31241, 31013, 31429, 31359, 31547, 31753, 31552, 32239, 31316, 32767, 30226, 32767, -7508, -32767, -29593, -32768, -30708, -32768,
 -30985, -32295, -31033, -31842, -30978, -31429, -30861, -31016, -30663, -30619, -30445, -30253, -30210, -29913, -29960, -29598, -29696,
 -29299, -29420, -29018, -29134, -28746, -28842, -28482, -28546, -28222, -28244, -27962, -27942, -27701, -27641, -27437, -27333, -27163,
 -27029, -26887, -26732, -26609, -26437, -26327, -26145, -26044, -25858, -25758, -25574, -25471, -25290, -25183, -25009, -24893, -24727,
 -24604, -24445, -24315, -24161, -24025, -23877, -23735, -23591, -23448, -23306, -23160, -23020, -22875, -22733, -22588, -22444, -22301,
 -22154, -22015, -21865, -21728, -21576, -21442, -21287, -21155, -20999, -20869, -20711, -20581, -20425, -20295, -20141, -20009, -19860,
 -19722, -19579, -19427, -19292, -19130, -19004, -18832, -18719, -18530, -18432, -18230, -18145, -17931, -17858, -17633, -17572, -17341,
 -17285, -17055, -16998, -16777, -16712, -16509, -16425, -16255, -16137, -15995, -15794, -15707, -15419, -15421, -14997, -15135, -14471,
 -14847, -13573, -14561, 0};
 
const int16_t wave23[257] = {
0, 15211, 14167, 15487, 15081, 15763, 15609, 16040, 16027, 16316, 16395, 16593, 16732, 16843, 17008, 17085, 17285, 17340, 17561, 17608,
 17837, 17885, 18114, 18168, 18391, 18455, 18667, 18745, 18944, 19036, 19220, 19328, 19497, 19616, 19773, 19904, 20049, 20188, 20320,
 20464, 20592, 20741, 20864, 21017, 21140, 21294, 21416, 21570, 21694, 21846, 21973, 22123, 22254, 22398, 22533, 22674, 22813, 22950,
 23091, 23226, 23369, 23501, 23646, 23777, 23924, 24052, 24200, 24330, 24476, 24609, 24751, 24887, 25024, 25165, 25294, 25445, 25563,
 25726, 25833, 26008, 26102, 26290, 26371, 26572, 26641, 26852, 26915, 27132, 27193, 27409, 27476, 27683, 27763, 27944, 28049, 28199,
 28340, 28445, 28635, 28685, 28936, 28921, 29241, 29154, 29548, 29388, 29855, 29629, 30162, 29877, 30462, 30143, 30754, 30430, 31034,
 30745, 31296, 31076, 31472, 31409, 31579, 31790, 31573, 32258, 31325, 32767, 30225, 32767, -7240, -32767, -29614, -32768, -30739, -32768,
 -31026, -32312, -31083, -31875, -31038, -31477, -30929, -31077, -30738, -30691, -30528, -30337, -30301, -30008, -30060, -29704, -29806,
 -29416, -29540, -29146, -29264, -28885, -28983, -28631, -28696, -28382, -28406, -28132, -28115, -27882, -27824, -27628, -27527, -27363,
 -27233, -27097, -26946, -26829, -26662, -26557, -26380, -26284, -26104, -26008, -25830, -25731, -25557, -25454, -25285, -25175, -25014,
 -24896, -24742, -24617, -24468, -24337, -24194, -24058, -23919, -23781, -23644, -23503, -23368, -23228, -23091, -22952, -22812, -22674,
 -22533, -22399, -22254, -22122, -21975, -21847, -21696, -21570, -21418, -21294, -21140, -21017, -20865, -20740, -20591, -20465, -20320,
 -20188, -20050, -19903, -19773, -19615, -19496, -19328, -19220, -19035, -18944, -18745, -18668, -18455, -18390, -18167, -18115, -17885,
 -17838, -17609, -17562, -17341, -17285, -17085, -17009, -16842, -16731, -16594, -16396, -16316, -16026, -16041, -15609, -15764, -15082,
 -15487, -14167, -15212, 0};
 
const int16_t wave24[257] = {
0, 15861, 14760, 16127, 15692, 16393, 16221, 16659, 16635, 16926, 16997, 17192, 17326, 17431, 17592, 17661, 17858, 17905, 18124, 18162,
 18390, 18429, 18657, 18702, 18923, 18979, 19189, 19259, 19456, 19541, 19722, 19823, 19988, 20102, 20254, 20380, 20520, 20654, 20781,
 20920, 21042, 21186, 21304, 21452, 21569, 21719, 21835, 21984, 22103, 22251, 22372, 22517, 22643, 22782, 22911, 23048, 23181, 23314,
 23450, 23579, 23717, 23844, 23984, 24110, 24251, 24374, 24517, 24642, 24783, 24911, 25048, 25179, 25310, 25446, 25571, 25716, 25829,
 25987, 26089, 26259, 26348, 26530, 26606, 26802, 26866, 27071, 27130, 27341, 27398, 27608, 27671, 27871, 27948, 28122, 28224, 28366,
 28504, 28602, 28788, 28832, 29078, 29058, 29371, 29282, 29667, 29507, 29963, 29738, 30258, 29977, 30547, 30234, 30829, 30511, 31098,
 30818, 31350, 31138, 31515, 31459, 31611, 31826, 31593, 32277, 31335, 32767, 30224, 32767, -6972, -32767, -29636, -32768, -30771, -32768,
 -31067, -32329, -31133, -31908, -31097, -31525, -30997, -31137, -30813, -30763, -30611, -30420, -30393, -30103, -30160, -29810, -29915,
 -29533, -29659, -29274, -29394, -29024, -29123, -28781, -28847, -28542, -28567, -28302, -28287, -28062, -28007, -27818, -27720, -27563,
 -27437, -27307, -27161, -27049, -26887, -26787, -26616, -26524, -26350, -26259, -26086, -25992, -25823, -25725, -25562, -25456, -25301,
 -25187, -25039, -24919, -24776, -24649, -24512, -24380, -24247, -24113, -23982, -23846, -23716, -23581, -23450, -23315, -23181, -23048,
 -22911, -22783, -22643, -22517, -22374, -22251, -22105, -21985, -21837, -21719, -21570, -21452, -21305, -21186, -21041, -20920, -20781,
 -20654, -20521, -20379, -20255, -20101, -19987, -19823, -19722, -19540, -19456, -19259, -19190, -18979, -18923, -18701, -18657, -18429,
 -18391, -18163, -18125, -17906, -17859, -17661, -17592, -17430, -17325, -17193, -16997, -16926, -16634, -16660, -16221, -16394, -15693,
 -16127, -14760, -15862, 0};
 
const int16_t wave25[257] = {
0, 16512, 15354, 16767, 16304, 17023, 16833, 17279, 17243, 17535, 17599, 17792, 17920, 18019, 18176, 18237, 18432, 18470, 18688, 18717,
 18943, 18973, 19200, 19236, 19456, 19503, 19712, 19774, 19968, 20046, 20224, 20318, 20480, 20588, 20736, 20856, 20992, 21120, 21242,
 21376, 21492, 21632, 21744, 21888, 21999, 22144, 22255, 22399, 22513, 22655, 22771, 22911, 23032, 23167, 23290, 23422, 23550, 23678,
 23808, 23933, 24066, 24187, 24322, 24443, 24579, 24697, 24835, 24955, 25090, 25213, 25345, 25471, 25597, 25728, 25847, 25988, 26096,
 26248, 26345, 26509, 26594, 26770, 26842, 27031, 27092, 27291, 27346, 27550, 27604, 27806, 27867, 28060, 28134, 28301, 28399, 28534,
 28668, 28760, 28942, 28980, 29220, 29196, 29502, 29410, 29786, 29625, 30071, 29847, 30355, 30077, 30633, 30325, 30904, 30593, 31163,
 30891, 31405, 31201, 31558, 31510, 31643, 31862, 31614, 32296, 31345, 32767, 30223, 32767, -6704, -32767, -29658, -32768, -30802, -32768,
 -31108, -32346, -31183, -31941, -31156, -31573, -31066, -31198, -30889, -30835, -30694, -30504, -30484, -30198, -30261, -29916, -30025,
 -29651, -29779, -29402, -29524, -29163, -29263, -28930, -28998, -28702, -28729, -28473, -28460, -28243, -28190, -28009, -27914, -27764,
 -27641, -27517, -27375, -27269, -27112, -27018, -26851, -26764, -26596, -26509, -26342, -26253, -26090, -25996, -25839, -25737, -25588,
 -25479, -25337, -25221, -25083, -24961, -24830, -24703, -24575, -24446, -24320, -24189, -24064, -23935, -23808, -23679, -23549, -23422,
 -23290, -23167, -23032, -22911, -22773, -22656, -22514, -22400, -22256, -22144, -21999, -21887, -21745, -21631, -21492, -21376, -21242,
 -21120, -20992, -20855, -20736, -20587, -20479, -20318, -20224, -20045, -19968, -19774, -19712, -19503, -19455, -19235, -19200, -18973,
 -18944, -18717, -18688, -18471, -18432, -18237, -18176, -18018, -17919, -17792, -17599, -17535, -17242, -17280, -16833, -17024, -16305,
 -16767, -15354, -16512, 0};
 
const int16_t wave26[257] = {
0, 17162, 15948, 17407, 16915, 17653, 17444, 17899, 17851, 18144, 18200, 18391, 18513, 18606, 18759, 18813, 19005, 19035, 19251, 19271,
 19496, 19516, 19742, 19770, 19988, 20027, 20234, 20288, 20479, 20550, 20725, 20813, 20971, 21073, 21217, 21332, 21463, 21585, 21702,
 21831, 21942, 22077, 22183, 22323, 22428, 22568, 22674, 22814, 22922, 23059, 23170, 23305, 23420, 23551, 23669, 23796, 23918, 24041,
 24166, 24286, 24414, 24530, 24660, 24775, 24907, 25020, 25152, 25267, 25397, 25515, 25641, 25762, 25884, 26010, 26123, 26259, 26362,
 26508, 26601, 26759, 26839, 27009, 27078, 27260, 27318, 27510, 27562, 27758, 27810, 28004, 28062, 28248, 28319, 28479, 28573, 28702,
 28831, 28918, 29095, 29127, 29361, 29334, 29633, 29538, 29905, 29743, 30179, 29955, 30451, 30176, 30718, 30415, 30978, 30675, 31227,
 30963, 31459, 31264, 31601, 31560, 31674, 31898, 31635, 32315, 31354, 32767, 30221, 32767, -6436, -32767, -29679, -32768, -30833, -32768,
 -31149, -32362, -31233, -31974, -31215, -31620, -31134, -31258, -30964, -30907, -30776, -30587, -30575, -30293, -30361, -30022, -30135,
 -29768, -29899, -29530, -29653, -29301, -29403, -29079, -29149, -28861, -28891, -28643, -28632, -28423, -28373, -28199, -28108, -27964,
 -27845, -27727, -27589, -27488, -27336, -27248, -27086, -27004, -26841, -26759, -26598, -26513, -26356, -26266, -26115, -26018, -25874,
 -25771, -25634, -25522, -25390, -25273, -25147, -25025, -24902, -24779, -24657, -24531, -24412, -24288, -24166, -24043, -23917, -23796,
 -23669, -23551, -23420, -23305, -23171, -23060, -22923, -22814, -22675, -22568, -22428, -22322, -22184, -22076, -21942, -21832, -21702,
 -21586, -21463, -21331, -21217, -21072, -20971, -20813, -20726, -20550, -20480, -20288, -20234, -20027, -19987, -19769, -19743, -19516,
 -19497, -19271, -19251, -19036, -19005, -18813, -18760, -18605, -18513, -18391, -18201, -18144, -17850, -17900, -17444, -17654, -16916,
 -17407, -15948, -17162, 0};
 
const int16_t wave27[257] = {
0, 17812, 16541, 18047, 17526, 18283, 18056, 18518, 18459, 18754, 18802, 18990, 19107, 19194, 19343, 19389, 19578, 19600, 19814, 19825,
 20049, 20060, 20285, 20304, 20520, 20551, 20756, 20802, 20991, 21055, 21227, 21308, 21463, 21559, 21698, 21808, 21934, 22051, 22163,
 22287, 22392, 22522, 22623, 22758, 22857, 22993, 23093, 23228, 23331, 23464, 23569, 23699, 23809, 23935, 24047, 24170, 24286, 24405,
 24525, 24639, 24762, 24873, 24998, 25108, 25234, 25342, 25469, 25579, 25704, 25817, 25938, 26054, 26170, 26291, 26400, 26530, 26628,
 26769, 26857, 27010, 27085, 27249, 27313, 27490, 27543, 27729, 27777, 27967, 28015, 28203, 28258, 28436, 28504, 28657, 28748, 28869,
 28995, 29075, 29248, 29274, 29503, 29471, 29763, 29666, 30024, 29862, 30287, 30064, 30548, 30276, 30803, 30506, 31053, 30756, 31291,
 31036, 31514, 31326, 31644, 31610, 31706, 31934, 31655, 32334, 31364, 32767, 30220, 32767, -6168, -32767, -29701, -32768, -30865, -32768,
 -31190, -32379, -31283, -32007, -31274, -31668, -31202, -31318, -31039, -30979, -30859, -30670, -30667, -30388, -30461, -30128, -30244,
 -29885, -30018, -29658, -29783, -29440, -29543, -29229, -29300, -29021, -29052, -28813, -28804, -28603, -28556, -28389, -28301, -28164,
 -28049, -27937, -27804, -27708, -27561, -27478, -27322, -27244, -27087, -27010, -26854, -26774, -26622, -26537, -26392, -26299, -26161,
 -26062, -25931, -25824, -25698, -25585, -25465, -25347, -25230, -25111, -24995, -24874, -24760, -24641, -24525, -24406, -24286, -24170,
 -24047, -23935, -23809, -23700, -23570, -23465, -23332, -23229, -23094, -22993, -22858, -22757, -22624, -22522, -22392, -22287, -22163,
 -22052, -21934, -21807, -21699, -21558, -21462, -21308, -21228, -21055, -20992, -20802, -20756, -20551, -20520, -20303, -20285, -20060,
 -20050, -19825, -19814, -19601, -19579, -19389, -19343, -19193, -19107, -18990, -18802, -18754, -18458, -18519, -18056, -18284, -17527,
 -18047, -16541, -17812, 0};
 
const int16_t wave28[257] = {
0, 18462, 17135, 18687, 18137, 18912, 18668, 19138, 19066, 19363, 19403, 19589, 19701, 19781, 19926, 19965, 20152, 20164, 20377, 20379,
 20602, 20604, 20828, 20838, 21053, 21075, 21278, 21317, 21503, 21560, 21729, 21804, 21954, 22044, 22179, 22284, 22405, 22517, 22623,
 22742, 22842, 22968, 23063, 23193, 23287, 23418, 23512, 23643, 23740, 23868, 23968, 24094, 24198, 24319, 24426, 24543, 24655, 24768, 
 24883, 24993, 25110, 25216, 25335, 25441, 25562, 25665, 25786, 25892, 26011, 26119, 26235, 26346, 26457, 26573, 26676, 26801, 26894,
 27030, 27113, 27260, 27331, 27489, 27549, 27719, 27769, 27948, 27993, 28176, 28221, 28401, 28453, 28624, 28690, 28835, 28923, 29037,
 29159, 29233, 29401, 29422, 29645, 29609, 29894, 29794, 30144, 29980, 30395, 30173, 30644, 30376, 30889, 30596, 31127, 30838, 31355,
 31109, 31568, 31389, 31687, 31660, 31738, 31971, 31676, 32353, 31373, 32767, 30219, 32767, -5900, -32767, -29722, -32768, -30896, -32768,
 -31231, -32396, -31333, -32040, -31334, -31716, -31270, -31379, -31114, -31051, -30942, -30754, -30758, -30483, -30561, -30234, -30354,
 -30002, -30138, -29786, -29913, -29579, -29684, -29378, -29450, -29181, -29214, -28983, -28977, -28784, -28739, -28580, -28495, -28364,
 -28253, -28147, -28018, -27928, -27786, -27708, -27557, -27484, -27333, -27260, -27110, -27034, -26889, -26808, -26668, -26581, -26448,
 -26354, -26228, -26126, -26005, -25897, -25782, -25670, -25558, -25444, -25333, -25217, -25108, -24994, -24883, -24770, -24654, -24543,
 -24426, -24319, -24198, -24094, -23969, -23869, -23741, -23644, -23513, -23418, -23287, -23193, -23064, -22967, -22842, -22743, -22623,
 -22518, -22405, -22283, -22180, -22043, -21954, -21804, -21729, -21560, -21504, -21317, -21279, -21075, -21052, -20837, -20828, -20604,
 -20603, -20379, -20378, -20165, -20152, -19965, -19927, -19780, -19701, -19589, -19404, -19363, -19065, -19139, -18668, -18913, -18138,
 -18687, -17135, -18463, 0};
 
const int16_t wave29[257] = {
0, 19112, 17729, 19327, 18748, 19542, 19280, 19757, 19674, 19972, 20005, 20188, 20295, 20369, 20510, 20541, 20725, 20729, 20940, 20933,
 21155, 21148, 21370, 21372, 21585, 21599, 21800, 21831, 22015, 22065, 22230, 22299, 22446, 22530, 22661, 22759, 22876, 22983, 23084,
 23198, 23292, 23413, 23502, 23628, 23716, 23843, 23931, 24058, 24149, 24273, 24367, 24488, 24586, 24703, 24804, 24917, 25023, 25132,
 25241, 25346, 25458, 25559, 25673, 25774, 25889, 25987, 26104, 26204, 26318, 26422, 26532, 26638, 26743, 26854, 26952, 27072, 27160,
 27291, 27369, 27510, 27577, 27729, 27785, 27949, 27995, 28167, 28208, 28384, 28426, 28600, 28649, 28813, 28875, 29013, 29097, 29205,
 29323, 29390, 29554, 29569, 29787, 29746, 30024, 29921, 30263, 30098, 30502, 30282, 30741, 30475, 30974, 30687, 31202, 30920, 31419,
 31181, 31623, 31452, 31731, 31711, 31770, 32007, 31696, 32371, 31383, 32767, 30218, 32767, -5631, -32767, -29744, -32768, -30927, -32768,
 -31271, -32413, -31383, -32073, -31393, -31764, -31338, -31439, -31189, -31123, -31025, -30837, -30849, -30577, -30662, -30340, -30464,
 -30119, -30257, -29915, -30042, -29718, -29824, -29528, -29601, -29341, -29375, -29153, -29149, -28964, -28922, -28770, -28688, -28564,
 -28457, -28357, -28233, -28148, -28011, -27938, -27792, -27725, -27578, -27510, -27366, -27295, -27155, -27079, -26945, -26862, -26735,
 -26645, -26525, -26428, -26312, -26209, -26100, -25992, -25885, -25777, -25671, -25560, -25457, -25348, -25241, -25133, -25023, -24917,
 -24804, -24703, -24586, -24488, -24368, -24274, -24150, -24058, -23933, -23843, -23717, -23628, -23503, -23413, -23292, -23199, -23084,
 -22984, -22876, -22758, -22661, -22529, -22445, -22299, -22231, -22065, -22016, -21831, -21801, -21599, -21585, -21371, -21371, -21148,
 -21156, -20933, -20941, -20730, -20726, -20541, -20511, -20368, -20295, -20188, -20005, -19972, -19673, -19758, -19280, -19543, -18749, 
 -19327, -17729, -19113, 0};
 
const int16_t wave30[257] = {
0, 19763, 18322, 19967, 19360, 20172, 19892, 20377, 20282, 20581, 20606, 20787, 20889, 20957, 21094, 21116, 21299, 21294, 21503, 21487,
 21708, 21692, 21913, 21905, 22118, 22124, 22323, 22346, 22527, 22570, 22732, 22794, 22937, 23015, 23142, 23235, 23347, 23449, 23544,
 23654, 23742, 23859, 23942, 24063, 24146, 24268, 24350, 24473, 24558, 24677, 24765, 24882, 24975, 25087, 25183, 25291, 25392, 25495,
 25599, 25699, 25806, 25902, 26011, 26107, 26217, 26310, 26421, 26516, 26625, 26724, 26829, 26930, 27030, 27136, 27229, 27343, 27426,
 27551, 27625, 27761, 27823, 27969, 28021, 28178, 28220, 28386, 28424, 28593, 28632, 28798, 28844, 29001, 29060, 29191, 29272, 29373,
 29487, 29548, 29707, 29717, 29929, 29884, 30155, 30049, 30382, 30216, 30610, 30391, 30837, 30575, 31059, 30778, 31276, 31001, 31483,
 31254, 31677, 31514, 31774, 31761, 31801, 32043, 31717, 32390, 31393, 32767, 30217, 32767, -5363, -32767, -29765, -32768, -30959, -32768,
 -31312, -32430, -31434, -32106, -31452, -31812, -31406, -31500, -31264, -31195, -31108, -30921, -30941, -30672, -30762, -30447, -30574,
 -30237, -30377, -30043, -30172, -29857, -29964, -29677, -29752, -29501, -29537, -29323, -29321, -29144, -29106, -28960, -28882, -28764,
 -28661, -28567, -28447, -28368, -28236, -28168, -28028, -27965, -27824, -27761, -27622, -27556, -27421, -27350, -27222, -27143, -27022,
 -26937, -26822, -26730, -26620, -26522, -26417, -26314, -26213, -26109, -26009, -25903, -25805, -25701, -25600, -25497, -25391, -25291,
 -25183, -25087, -24975, -24882, -24767, -24678, -24559, -24473, -24352, -24268, -24146, -24063, -23943, -23858, -23742, -23654, -23544,
 -23450, -23347, -23234, -23142, -23014, -22937, -22794, -22733, -22569, -22528, -22346, -22323, -22124, -22117, -21904, -21914, -21692,
 -21709, -21488, -21504, -21295, -21299, -21116, -21094, -20956, -20889, -20787, -20607, -20581, -20281, -20378, -19892, -20173, -19361,
 -19967, -18322, -19763, 0};
 
const int16_t wave31[257] = {
0, 20413, 18916, 20607, 19971, 20802, 20504, 20996, 20890, 21191, 21208, 21386, 21483, 21544, 21677, 21692, 21872, 21859, 22067, 22041,
 22261, 22236, 22456, 22439, 22650, 22648, 22845, 22860, 23039, 23075, 23234, 23289, 23429, 23501, 23623, 23711, 23818, 23915, 24005,
 24109, 24192, 24304, 24382, 24499, 24575, 24693, 24770, 24887, 24967, 25082, 25164, 25276, 25364, 25471, 25562, 25665, 25760, 25859,
 25958, 26053, 26154, 26245, 26349, 26439, 26544, 26633, 26738, 26829, 26932, 27026, 27126, 27222, 27317, 27417, 27505, 27615, 27692,
 27812, 27881, 28011, 28068, 28209, 28256, 28408, 28446, 28605, 28640, 28802, 28837, 28997, 29040, 29189, 29246, 29369, 29447, 29540,
 29651, 29705, 29860, 29864, 30071, 30021, 30286, 30177, 30501, 30335, 30718, 30500, 30934, 30675, 31145, 30868, 31351, 31083, 31548,
 31327, 31732, 31577, 31817, 31811, 31833, 32079, 31738, 32409, 31402, 32767, 30216, 32767, -5095, -32767, -29787, -32768, -30990, -32768,
 -31353, -32447, -31484, -32139, -31511, -31859, -31474, -31560, -31340, -31267, -31191, -31004, -31032, -30767, -30862, -30553, -30683,
 -30354, -30496, -30171, -30302, -29996, -30104, -29827, -29903, -29661, -29698, -29494, -29494, -29325, -29289, -29151, -29076, -28965,
 -28865, -28777, -28662, -28588, -28461, -28398, -28263, -28205, -28070, -28011, -27878, -27816, -27688, -27621, -27498, -27424, -27309,
 -27228, -27120, -27032, -26927, -26834, -26735, -26637, -26541, -26442, -26347, -26246, -26153, -26054, -25958, -25860, -25760, -25665,
 -25562, -25471, -25364, -25277, -25166, -25083, -24968, -24888, -24771, -24693, -24575, -24498, -24383, -24304, -24192, -24110, -24005,
 -23916, -23818, -23710, -23624, -23500, -23428, -23289, -23235, -23074, -23040, -22860, -22845, -22648, -22650, -22438, -22456, -22236,
 -22262, -22042, -22067, -21860, -21873, -21692, -21678, -21543, -21483, -21386, -21208, -21191, -20889, -20997, -20504, -20803, -19972,
 -20607, -18916, -20413, 0};
 
const int16_t wave32[257] = {
0, 21063, 19510, 21247, 20582, 21431, 21116, 21616, 21497, 21800, 21809, 21985, 22077, 22132, 22261, 22268, 22445, 22423, 22630, 22595,
 22814, 22780, 22998, 22973, 23183, 23172, 23367, 23375, 23551, 23580, 23736, 23785, 23920, 23987, 24104, 24187, 24289, 24381, 24465,
 24565, 24643, 24749, 24821, 24934, 25004, 25118, 25189, 25302, 25376, 25486, 25563, 25671, 25753, 25855, 25940, 26039, 26129, 26223,
 26316, 26406, 26502, 26589, 26687, 26772, 26872, 26955, 27056, 27141, 27240, 27328, 27423, 27514, 27603, 27699, 27782, 27886, 27958,
 28073, 28137, 28261, 28314, 28449, 28492, 28637, 28671, 28824, 28855, 29010, 29043, 29195, 29235, 29378, 29431, 29547, 29622, 29708,
 29815, 29863, 30013, 30012, 30213, 30159, 30416, 30305, 30621, 30453, 30826, 30609, 31030, 30774, 31230, 30959, 31425, 31164, 31612,
 31399, 31786, 31639, 31860, 31862, 31865, 32115, 31758, 32428, 31412, 32767, 30215, 32767, -4827, -32767, -29808, -32768, -31021, -32768,
 -31394, -32464, -31534, -32173, -31571, -31907, -31542, -31620, -31415, -31339, -31274, -31088, -31124, -30862, -30963, -30659, -30793,
 -30471, -30616, -30299, -30432, -30135, -30244, -29976, -30054, -29821, -29860, -29664, -29666, -29505, -29472, -29341, -29269, -29165,
 -29069, -28987, -28876, -28808, -28686, -28628, -28498, -28445, -28315, -28262, -28134, -28077, -27954, -27892, -27775, -27706, -27596,
 -27520, -27417, -27334, -27235, -27146, -27052, -26959, -26869, -26775, -26685, -26589, -26501, -26408, -26316, -26224, -26128, -26039,
 -25940, -25855, -25753, -25671, -25565, -25487, -25377, -25303, -25190, -25118, -25005, -24933, -24822, -24749, -24642, -24566, -24465,
 -24381, -24289, -24186, -24105, -23986, -23920, -23785, -23736, -23579, -23552, -23375, -23368, -23172, -23182, -22972, -22999, -22780,
 -22815, -22596, -22630, -22424, -22446, -22268, -22262, -22131, -22076, -21985, -21810, -21800, -21496, -21617, -21116, -21432, -20583,
 -21247, -19510, -21064, 0};
 
const int16_t wave33[257] = {
0, 21713, 20103, 21887, 21193, 22061, 21727, 22235, 22105, 22409, 22411, 22584, 22671, 22719, 22845, 22844, 23019, 22988, 23193, 23149,
 23367, 23323, 23541, 23507, 23715, 23696, 23889, 23889, 24063, 24084, 24237, 24280, 24412, 24472, 24586, 24663, 24760, 24847, 24926,
 25021, 25093, 25195, 25261, 25369, 25434, 25543, 25608, 25717, 25785, 25891, 25962, 26065, 26141, 26239, 26319, 26412, 26497, 26586,
 26674, 26759, 26850, 26932, 27024, 27105, 27199, 27278, 27373, 27454, 27547, 27630, 27719, 27805, 27890, 27980, 28058, 28157, 28225,
 28334, 28393, 28512, 28560, 28689, 28728, 28867, 28897, 29043, 29071, 29219, 29248, 29394, 29431, 29566, 29616, 29725, 29796, 29876,
 29979, 30020, 30166, 30159, 30355, 30296, 30547, 30433, 30740, 30571, 30934, 30718, 31127, 30874, 31316, 31049, 31500, 31246, 31676,
 31472, 31841, 31702, 31903, 31912, 31897, 32152, 31779, 32447, 31421, 32767, 30214, 32767, -4559, -32767, -29830, -32768, -31053, -32768,
 -31435, -32480, -31584, -32206, -31630, -31955, -31610, -31681, -31490, -31411, -31357, -31171, -31215, -30957, -31063, -30765, -30903,
 -30588, -30735, -30427, -30561, -30274, -30385, -30126, -30204, -29981, -30021, -29834, -29838, -29686, -29655, -29532, -29463, -29365,
 -29273, -29197, -29091, -29028, -28911, -28858, -28734, -28685, -28561, -28512, -28390, -28337, -28221, -28163, -28052, -27987, -27883,
 -27811, -27714, -27635, -27542, -27458, -27370, -27282, -27196, -27107, -27023, -26932, -26849, -26761, -26675, -26587, -26497, -26412,
 -26319, -26239, -26141, -26065, -25963, -25892, -25786, -25717, -25609, -25543, -25434, -25369, -25262, -25195, -25092, -25021, -24926,
 -24847, -24760, -24662, -24586, -24471, -24411, -24280, -24238, -24084, -24064, -23889, -23890, -23696, -23715, -23506, -23542, -23323,
 -23368, -23150, -23194, -22989, -23020, -22844, -22845, -22718, -22670, -22584, -22411, -22409, -22104, -22236, -21727, -22062, -21194,
 -21887, -20103, -21714, 0};
 
const int16_t wave34[257] = {
0, 22363, 20697, 22527, 21804, 22691, 22339, 22855, 22713, 23019, 23012, 23183, 23265, 23307, 23428, 23420, 23592, 23553, 23756, 23703,
 23920, 23867, 24084, 24041, 24248, 24220, 24411, 24404, 24575, 24589, 24739, 24775, 24903, 24958, 25067, 25139, 25231, 25313, 25386,
 25476, 25543, 25640, 25701, 25804, 25863, 25968, 26027, 26131, 26194, 26295, 26361, 26459, 26530, 26623, 26697, 26786, 26866, 26950,
 27033, 27113, 27198, 27275, 27362, 27438, 27527, 27600, 27690, 27766, 27854, 27932, 28016, 28097, 28176, 28262, 28334, 28428, 28491,
 28595, 28649, 28762, 28806, 28929, 28963, 29096, 29123, 29262, 29286, 29428, 29454, 29592, 29626, 29754, 29802, 29903, 29971, 30043,
 30143, 30178, 30319, 30307, 30497, 30434, 30677, 30561, 30859, 30690, 31042, 30827, 31223, 30974, 31401, 31140, 31574, 31328, 31740,
 31545, 31895, 31765, 31946, 31962, 31929, 32188, 31799, 32466, 31431, 32767, 30213, 32767, -4291, -32767, -29851, -32768, -31084, -32768,
 -31476, -32497, -31634, -32239, -31689, -32003, -31678, -31741, -31565, -31483, -31440, -31255, -31306, -31052, -31163, -30871, -31012,
 -30705, -30855, -30555, -30691, -30413, -30525, -30275, -30355, -30141, -30183, -30004, -30011, -29866, -29838, -29722, -29656, -29565,
 -29477, -29407, -29305, -29248, -29136, -29088, -28969, -28925, -28807, -28762, -28646, -28598, -28487, -28434, -28328, -28268, -28170,
 -28103, -28011, -27937, -27849, -27770, -27687, -27604, -27524, -27440, -27361, -27275, -27197, -27114, -27033, -26951, -26865, -26786,
 -26697, -26623, -26530, -26460, -26362, -26296, -26195, -26132, -26028, -25968, -25864, -25804, -25702, -25640, -25542, -25477, -25386,
 -25313, -25231, -25138, -25068, -24957, -24903, -24775, -24740, -24589, -24576, -24404, -24412, -24220, -24247, -24040, -24084, -23867,
 -23921, -23704, -23757, -23554, -23593, -23420, -23429, -23306, -23264, -23183, -23013, -23019, -22712, -22856, -22339, -22692, -21805,
 -22527, -20697, -22364, 0};
 
const int16_t wave35[257] = {
0, 23014, 21291, 23167, 22416, 23321, 22951, 23474, 23321, 23628, 23614, 23782, 23859, 23895, 24012, 23996, 24166, 24118, 24319, 24258,
 24473, 24411, 24627, 24575, 24780, 24744, 24934, 24918, 25087, 25094, 25241, 25270, 25395, 25443, 25548, 25614, 25702, 25779, 25847,
 25932, 25993, 26086, 26141, 26239, 26293, 26393, 26446, 26546, 26603, 26700, 26760, 26853, 26919, 27007, 27076, 27160, 27234, 27313,
 27391, 27466, 27546, 27618, 27700, 27771, 27854, 27923, 28008, 28078, 28161, 28235, 28313, 28389, 28463, 28544, 28611, 28699, 28757,
 28855, 28905, 29012, 29052, 29169, 29199, 29325, 29348, 29481, 29502, 29637, 29660, 29790, 29822, 29943, 29987, 30081, 30146, 30211,
 30307, 30335, 30472, 30454, 30639, 30572, 30808, 30688, 30978, 30808, 31149, 30936, 31320, 31074, 31486, 31231, 31649, 31409, 31804,
 31618, 31950, 31827, 31990, 32013, 31960, 32224, 31820, 32484, 31441, 32767, 30212, 32767, -4022, -32767, -29873, -32768, -31115, -32768,
 -31516, -32514, -31684, -32272, -31748, -32051, -31747, -31802, -31640, -31555, -31523, -31338, -31398, -31146, -31264, -30977, -31122,
 -30823, -30975, -30684, -30821, -30552, -30665, -30425, -30506, -30301, -30345, -30174, -30183, -30046, -30021, -29912, -29850, -29765,
 -29681, -29617, -29520, -29468, -29361, -29318, -29204, -29166, -29053, -29013, -28902, -28859, -28753, -28705, -28605, -28549, -28457,
 -28395, -28308, -28239, -28157, -28082, -28005, -27926, -27852, -27773, -27699, -27618, -27546, -27468, -27391, -27315, -27234, -27160,
 -27076, -27007, -26919, -26854, -26761, -26701, -26604, -26547, -26448, -26393, -26293, -26239, -26142, -26085, -25992, -25933, -25847,
 -25779, -25702, -25613, -25549, -25442, -25394, -25270, -25242, -25094, -25088, -24918, -24934, -24744, -24780, -24574, -24627, -24411,
 -24474, -24258, -24320, -24119, -24166, -23996, -24013, -23894, -23858, -23782, -23615, -23628, -23320, -23475, -22951, -23322, -22417,
 -23167, -21291, -23014, 0};
 
const int16_t wave36[257] = {
0, 23664, 21884, 23807, 23027, 23950, 23563, 24094, 23928, 24237, 24215, 24381, 24452, 24482, 24596, 24572, 24739, 24682, 24882, 24812,
 25026, 24955, 25169, 25109, 25313, 25268, 25456, 25433, 25599, 25599, 25743, 25766, 25886, 25929, 26029, 26090, 26173, 26244, 26307,
 26388, 26443, 26531, 26580, 26674, 26722, 26818, 26865, 26961, 27012, 27104, 27159, 27248, 27308, 27391, 27455, 27534, 27603, 27677,
 27749, 27819, 27894, 27961, 28038, 28104, 28182, 28246, 28325, 28391, 28468, 28537, 28610, 28681, 28750, 28825, 28887, 28970, 29023,
 29116, 29161, 29263, 29298, 29408, 29435, 29555, 29574, 29700, 29718, 29845, 29865, 29989, 30017, 30131, 30172, 30259, 30321, 30379,
 30471, 30493, 30625, 30602, 30780, 30709, 30939, 30816, 31098, 30926, 31257, 31044, 31416, 31173, 31572, 31321, 31723, 31491, 31868,
 31690, 32004, 31890, 32033, 32063, 31992, 32260, 31841, 32503, 31450, 32767, 30211, 32767, -3754, -32767, -29894, -32768, -31147, -32768,
 -31557, -32531, -31734, -32305, -31808, -32099, -31815, -31862, -31715, -31627, -31606, -31422, -31489, -31241, -31364, -31083, -31232,
 -30940, -31094, -30812, -30951, -30690, -30805, -30574, -30657, -30460, -30506, -30344, -30355, -30227, -30204, -30103, -30044, -29965,
 -29885, -29827, -29734, -29688, -29585, -29548, -29440, -29406, -29298, -29263, -29158, -29119, -29020, -28975, -28882, -28831, -28744,
 -28686, -28605, -28541, -28464, -28394, -28322, -28249, -28180, -28105, -28037, -27961, -27894, -27821, -27750, -27678, -27602, -27534,
 -27455, -27391, -27308, -27248, -27160, -27105, -27013, -26962, -26867, -26818, -26722, -26674, -26581, -26531, -26442, -26388, -26307,
 -26245, -26173, -26089, -26030, -25928, -25886, -25766, -25743, -25599, -25600, -25433, -25457, -25268, -25312, -25108, -25170, -24955,
 -25027, -24812, -24883, -24683, -24740, -24572, -24596, -24481, -24452, -24381, -24216, -24237, -23927, -24095, -23563, -23951, -23028,
 -23807, -21884, -23665, 0};
 
const int16_t wave37[257] = {
0, 24314, 22478, 24447, 23638, 24580, 24175, 24713, 24536, 24846, 24817, 24980, 25046, 25070, 25179, 25148, 25313, 25247, 25446, 25366,
 25579, 25499, 25712, 25643, 25845, 25792, 25978, 25947, 26111, 26104, 26244, 26261, 26378, 26414, 26511, 26566, 26644, 26710, 26768,
 26843, 26893, 26977, 27020, 27110, 27152, 27243, 27285, 27376, 27421, 27509, 27558, 27642, 27696, 27775, 27833, 27908, 27971, 28040,
 28107, 28173, 28242, 28304, 28376, 28436, 28509, 28568, 28642, 28703, 28775, 28839, 28907, 28973, 29036, 29107, 29163, 29242, 29289,
 29377, 29417, 29513, 29543, 29648, 29671, 29784, 29800, 29919, 29933, 30054, 30071, 30187, 30213, 30319, 30358, 30437, 30495, 30547,
 30635, 30650, 30778, 30749, 30922, 30847, 31069, 30944, 31217, 31044, 31365, 31153, 31513, 31273, 31657, 31412, 31798, 31573, 31933,
 31763, 32059, 31953, 32076, 32113, 32024, 32296, 31861, 32522, 31460, 32767, 30210, 32767, -3486, -32767, -29916, -32768, -31178, -32768,
 -31598, -32548, -31784, -32338, -31867, -32146, -31883, -31923, -31791, -31699, -31689, -31505, -31580, -31336, -31464, -31189, -31342,
 -31057, -31214, -30940, -31080, -30829, -30945, -30724, -30808, -30620, -30668, -30515, -30528, -30407, -30387, -30293, -30237, -30166,
 -30089, -30037, -29949, -29908, -29810, -29778, -29675, -29646, -29544, -29513, -29414, -29380, -29286, -29246, -29158, -29112, -29031,
 -28978, -28903, -28843, -28771, -28706, -28640, -28571, -28507, -28438, -28375, -28304, -28242, -28174, -28108, -28042, -27971, -27908,
 -27833, -27775, -27696, -27642, -27559, -27510, -27422, -27376, -27286, -27243, -27152, -27109, -27021, -26976, -26892, -26844, -26768,
 -26711, -26644, -26565, -26511, -26413, -26377, -26261, -26245, -26104, -26112, -25947, -25979, -25792, -25845, -25642, -25713, -25499,
 -25580, -25366, -25446, -25248, -25313, -25148, -25180, -25069, -25046, -24980, -24818, -24846, -24535, -24714, -24175, -24581, -23639,
 -24447, -22478, -24315, 0};
 
const int16_t wave38[257] = {
0, 24964, 23072, 25087, 24249, 25210, 24787, 25333, 25144, 25456, 25419, 25579, 25640, 25658, 25763, 25723, 25886, 25812, 26009, 25920,
 26131, 26043, 26255, 26176, 26377, 26317, 26500, 26461, 26623, 26609, 26746, 26756, 26869, 26900, 26992, 27042, 27115, 27176, 27229,
 27299, 27343, 27422, 27460, 27545, 27581, 27668, 27704, 27790, 27830, 27913, 27956, 28036, 28085, 28159, 28212, 28281, 28339, 28404,
 28466, 28526, 28590, 28647, 28713, 28769, 28837, 28891, 28959, 29015, 29082, 29141, 29204, 29265, 29323, 29388, 29440, 29513, 29555,
 29638, 29672, 29763, 29789, 29888, 29906, 30014, 30025, 30138, 30149, 30263, 30276, 30386, 30408, 30507, 30543, 30615, 30670, 30714,
 30799, 30808, 30931, 30896, 31064, 30984, 31200, 31072, 31336, 31163, 31473, 31262, 31609, 31373, 31742, 31503, 31873, 31654, 31997,
 31836, 32113, 32015, 32119, 32163, 32056, 32333, 31882, 32541, 31470, 32767, 30209, 32767, -3218, -32767, -29938, -32768, -31209, -32768,
 -31639, -32565, -31835, -32371, -31926, -32194, -31951, -31983, -31866, -31770, -31772, -31588, -31672, -31431, -31564, -31296, -31451,
 -31174, -31333, -31068, -31210, -30968, -31086, -30873, -30958, -30780, -30829, -30685, -30700, -30587, -30571, -30483, -30431, -30366,
 -30294, -30248, -30163, -30128, -30035, -30008, -29910, -29886, -29790, -29764, -29671, -29641, -29552, -29517, -29435, -29393, -29318,
 -29269, -29200, -29145, -29079, -29019, -28958, -28893, -28835, -28771, -28713, -28647, -28590, -28527, -28466, -28405, -28339, -28281,
 -28212, -28160, -28085, -28037, -27958, -27914, -27831, -27791, -27705, -27668, -27581, -27545, -27461, -27422, -27342, -27300, -27229,
 -27177, -27116, -27041, -26993, -26899, -26869, -26756, -26747, -26608, -26624, -26461, -26501, -26317, -26377, -26175, -26255, -26043,
 -26132, -25921, -26010, -25813, -25887, -25723, -25764, -25657, -25640, -25580, -25419, -25456, -25143, -25334, -24787, -25211, -24250,
 -25087, -23072, -24965, 0};
 
const int16_t wave39[257] = {
0, 25615, 23666, 25727, 24861, 25840, 25399, 25952, 25752, 26065, 26020, 26178, 26234, 26245, 26347, 26299, 26459, 26377, 26572, 26474,
 26684, 26587, 26797, 26710, 26910, 26841, 27023, 26976, 27135, 27114, 27248, 27251, 27361, 27386, 27473, 27518, 27586, 27642, 27689,
 27755, 27793, 27867, 27899, 27980, 28010, 28093, 28123, 28205, 28239, 28318, 28355, 28430, 28474, 28543, 28590, 28655, 28708, 28768,
 28824, 28879, 28938, 28990, 29051, 29102, 29164, 29213, 29277, 29328, 29389, 29443, 29501, 29557, 29609, 29670, 29716, 29784, 29821,
 29898, 29928, 30013, 30035, 30128, 30142, 30243, 30251, 30357, 30364, 30471, 30482, 30584, 30604, 30696, 30728, 30793, 30845, 30882,
 30963, 30965, 31084, 31044, 31206, 31122, 31330, 31200, 31455, 31281, 31581, 31371, 31706, 31472, 31828, 31593, 31947, 31736, 32061,
 31908, 32168, 32078, 32162, 32214, 32087, 32369, 31902, 32560, 31479, 32767, 30208, 32767, -2950, -32767, -29959, -32768, -31240, -32768,
 -31680, -32582, -31885, -32404, -31985, -32242, -32019, -32043, -31941, -31842, -31855, -31672, -31763, -31526, -31665, -31402, -31561,
 -31292, -31453, -31196, -31340, -31107, -31226, -31023, -31109, -30940, -30991, -30855, -30872, -30768, -30754, -30674, -30624, -30566,
 -30498, -30458, -30378, -30348, -30260, -30238, -30145, -30126, -30035, -30014, -29927, -29901, -29819, -29788, -29712, -29674, -29605,
 -29561, -29497, -29447, -29386, -29331, -29275, -29216, -29163, -29104, -29051, -28990, -28938, -28881, -28824, -28769, -28708, -28655,
 -28590, -28544, -28474, -28431, -28357, -28319, -28240, -28206, -28124, -28093, -28011, -27980, -27900, -27867, -27792, -27756, -27689,
 -27643, -27587, -27517, -27474, -27385, -27360, -27251, -27249, -27113, -27136, -26976, -27023, -26841, -26910, -26709, -26798, -26587,
 -26685, -26475, -26573, -26378, -26460, -26299, -26348, -26244, -26234, -26179, -26021, -26065, -25751, -25953, -25399, -25841, -24862,
 -25727, -23666, -25615, 0};
 
const int16_t wave40[257] = {
0, 26265, 24259, 26367, 25472, 26469, 26010, 26572, 26359, 26674, 26622, 26777, 26828, 26833, 26930, 26875, 27033, 26941, 27135, 27028,
 27237, 27130, 27340, 27244, 27442, 27365, 27545, 27490, 27647, 27618, 27750, 27747, 27852, 27871, 27954, 27994, 28057, 28108, 28150,
 28210, 28243, 28313, 28339, 28415, 28440, 28518, 28542, 28620, 28648, 28722, 28754, 28825, 28863, 28927, 28969, 29029, 29076, 29131,
 29182, 29233, 29286, 29333, 29389, 29435, 29492, 29536, 29594, 29640, 29696, 29745, 29797, 29848, 29896, 29951, 29992, 30055, 30088,
 30159, 30184, 30264, 30281, 30368, 30378, 30473, 30477, 30576, 30580, 30680, 30687, 30783, 30799, 30884, 30914, 30971, 31020, 31050,
 31127, 31123, 31237, 31191, 31348, 31259, 31461, 31328, 31575, 31399, 31689, 31480, 31802, 31572, 31913, 31684, 32022, 31818, 32125,
 31981, 32222, 32141, 32205, 32264, 32119, 32405, 31923, 32579, 31489, 32767, 30207, 32767, -2682, -32767, -29981, -32768, -31272, -32768,
 -31721, -32598, -31935, -32437, -32045, -32290, -32087, -32104, -32016, -31914, -31938, -31755, -31854, -31621, -31765, -31508, -31671,
 -31409, -31572, -31324, -31470, -31246, -31366, -31172, -31260, -31100, -31152, -31025, -31045, -30948, -30937, -30864, -30818, -30766,
 -30702, -30668, -30592, -30568, -30485, -30468, -30381, -30366, -30281, -30264, -30183, -30162, -30085, -30059, -29988, -29956, -29892,
 -29852, -29794, -29748, -29693, -29643, -29593, -29538, -29491, -29436, -29389, -29333, -29286, -29234, -29183, -29132, -29076, -29029,
 -28969, -28928, -28863, -28825, -28755, -28723, -28649, -28621, -28543, -28518, -28440, -28415, -28340, -28313, -28242, -28211, -28150,
 -28109, -28058, -27993, -27955, -27870, -27852, -27747, -27750, -27618, -27648, -27490, -27546, -27365, -27442, -27243, -27341, -27130,
 -27238, -27029, -27136, -26942, -27034, -26875, -26931, -26832, -26828, -26778, -26622, -26674, -26358, -26573, -26010, -26470, -25473,
 -26367, -24259, -26266, 0};
 
const int16_t wave41[257] = {
0, 26915, 24853, 27007, 26083, 27099, 26622, 27191, 26967, 27283, 27223, 27376, 27422, 27420, 27514, 27451, 27606, 27506, 27698, 27582,
 27790, 27674, 27883, 27778, 27975, 27889, 28067, 28005, 28159, 28123, 28251, 28242, 28344, 28357, 28436, 28469, 28528, 28574, 28610,
 28666, 28693, 28758, 28779, 28850, 28869, 28943, 28961, 29035, 29057, 29127, 29153, 29219, 29251, 29311, 29348, 29403, 29445, 29495,
 29540, 29586, 29634, 29676, 29727, 29768, 29819, 29859, 29911, 29953, 30003, 30048, 30094, 30140, 30183, 30233, 30269, 30326, 30354,
 30420, 30440, 30514, 30527, 30608, 30614, 30702, 30702, 30795, 30796, 30889, 30893, 30981, 30995, 31072, 31099, 31149, 31194, 31218,
 31291, 31280, 31390, 31339, 31490, 31397, 31592, 31455, 31694, 31517, 31796, 31589, 31899, 31672, 31999, 31774, 32096, 31899, 32189,
 32054, 32277, 32203, 32249, 32314, 32151, 32441, 31944, 32597, 31498, 32767, 30206, 32767, -2413, -32767, -30002, -32768, -31303, -32768,
 -31761, -32615, -31985, -32470, -32104, -32338, -32155, -32164, -32091, -31986, -32021, -31839, -31946, -31715, -31865, -31614, -31781,
 -31526, -31692, -31453, -31599, -31385, -31506, -31322, -31411, -31260, -31314, -31195, -31217, -31129, -31120, -31055, -31012, -30966,
 -30906, -30878, -30807, -30788, -30710, -30698, -30616, -30607, -30527, -30515, -30439, -30422, -30352, -30330, -30265, -30237, -30179,
 -30144, -30091, -30050, -30001, -29955, -29910, -29861, -29818, -29769, -29727, -29676, -29635, -29587, -29541, -29496, -29445, -29403,
 -29348, -29312, -29251, -29219, -29154, -29128, -29058, -29035, -28963, -28943, -28869, -28850, -28780, -28758, -28692, -28667, -28610,
 -28575, -28529, -28468, -28436, -28356, -28343, -28242, -28252, -28123, -28160, -28005, -28068, -27889, -27975, -27777, -27884, -27674,
 -27791, -27583, -27699, -27507, -27607, -27451, -27515, -27419, -27422, -27377, -27224, -27283, -26966, -27192, -26622, -27100, -26084,
 -27007, -24853, -26916, 0};
 
const int16_t wave42[257] = {
0, 27565, 25447, 27647, 26694, 27729, 27234, 27811, 27575, 27893, 27825, 27975, 28016, 28008, 28098, 28027, 28180, 28071, 28262, 28136,
 28343, 28218, 28425, 28312, 28507, 28413, 28589, 28519, 28671, 28628, 28753, 28737, 28835, 28842, 28917, 28945, 28999, 29040, 29071,
 29122, 29143, 29204, 29218, 29286, 29299, 29367, 29381, 29449, 29466, 29531, 29552, 29613, 29640, 29695, 29726, 29777, 29813, 29858,
 29899, 29939, 29983, 30019, 30065, 30100, 30147, 30181, 30229, 30265, 30310, 30350, 30391, 30432, 30469, 30515, 30545, 30598, 30620,
 30681, 30696, 30764, 30772, 30848, 30849, 30931, 30928, 31015, 31011, 31097, 31099, 31179, 31190, 31261, 31284, 31327, 31369, 31385,
 31455, 31438, 31543, 31486, 31632, 31535, 31722, 31583, 31813, 31636, 31904, 31698, 31995, 31771, 32084, 31865, 32171, 31981, 32254,
 32126, 32331, 32266, 32292, 32365, 32183, 32477, 31964, 32616, 31508, 32767, 30204, 32767, -2145, -32767, -30024, -32768, -31334, -32768,
 -31802, -32632, -32035, -32503, -32163, -32385, -32223, -32225, -32167, -32058, -32104, -31922, -32037, -31810, -31966, -31720, -31890,
 -31643, -31812, -31581, -31729, -31524, -31646, -31471, -31562, -31420, -31476, -31366, -31389, -31309, -31303, -31245, -31205, -31167,
 -31110, -31088, -31021, -31008, -30935, -30928, -30851, -30847, -30772, -30765, -30695, -30683, -30618, -30601, -30542, -30518, -30465,
 -30436, -30389, -30352, -30308, -30267, -30228, -30183, -30146, -30102, -30064, -30019, -29983, -29941, -29899, -29860, -29813, -29777,
 -29726, -29696, -29640, -29614, -29553, -29532, -29467, -29450, -29382, -29368, -29299, -29285, -29219, -29203, -29143, -29123, -29071,
 -29041, -29000, -28944, -28918, -28841, -28835, -28737, -28754, -28628, -28672, -28519, -28590, -28413, -28507, -28311, -28426, -28218,
 -28344, -28137, -28262, -28072, -28180, -28027, -28099, -28007, -28016, -27976, -27826, -27893, -27574, -27812, -27234, -27730, -26695,
 -27647, -25447, -27566, 0};
 
const int16_t wave43[257] = {
0, 28215, 26040, 28287, 27305, 28359, 27846, 28430, 28183, 28502, 28426, 28574, 28610, 28596, 28681, 28603, 28753, 28636, 28825, 28690,
 28896, 28762, 28968, 28846, 29040, 28937, 29111, 29034, 29183, 29133, 29255, 29232, 29327, 29328, 29398, 29421, 29470, 29506, 29531,
 29577, 29593, 29649, 29658, 29721, 29728, 29792, 29800, 29864, 29875, 29936, 29951, 30007, 30029, 30079, 30105, 30150, 30182, 30222,
 30257, 30293, 30331, 30362, 30402, 30433, 30474, 30504, 30546, 30577, 30617, 30652, 30688, 30724, 30756, 30796, 30821, 30869, 30886,
 30942, 30952, 31015, 31018, 31088, 31085, 31161, 31154, 31234, 31227, 31306, 31304, 31378, 31386, 31449, 31470, 31505, 31544, 31553,
 31619, 31595, 31696, 31634, 31774, 31672, 31853, 31711, 31932, 31754, 32012, 31807, 32092, 31871, 32169, 31956, 32245, 32063, 32318,
 32199, 32386, 32329, 32335, 32415, 32215, 32514, 31985, 32635, 31518, 32767, 30203, 32767, -1877, -32767, -30045, -32768, -31366, -32768,
 -31843, -32649, -32085, -32536, -32222, -32433, -32291, -32285, -32242, -32130, -32187, -32006, -32128, -31905, -32066, -31826, -32000,
 -31760, -31931, -31709, -31859, -31663, -31787, -31621, -31712, -31580, -31637, -31536, -31562, -31489, -31486, -31435, -31399, -31367,
 -31314, -31298, -31236, -31228, -31160, -31158, -31087, -31087, -31018, -31015, -30951, -30944, -30884, -30872, -30818, -30799, -30752,
 -30727, -30686, -30654, -30615, -30579, -30545, -30505, -30474, -30434, -30402, -30362, -30331, -30294, -30258, -30223, -30182, -30150,
 -30105, -30080, -30029, -30008, -29952, -29937, -29876, -29865, -29801, -29793, -29728, -29721, -29659, -29649, -29593, -29578, -29531,
 -29507, -29471, -29420, -29399, -29327, -29326, -29232, -29256, -29133, -29184, -29034, -29112, -28937, -29040, -28845, -28969, -28762,
 -28897, -28691, -28826, -28637, -28754, -28603, -28682, -28595, -28610, -28575, -28427, -28502, -28182, -28431, -27846, -28360, -27306,
 -28287, -26040, -28216, 0};
 
const int16_t wave44[257] = {
0, 28866, 26634, 28927, 27917, 28988, 28458, 29050, 28790, 29111, 29028, 29173, 29204, 29183, 29265, 29179, 29326, 29200, 29388, 29244,
 29449, 29306, 29511, 29380, 29572, 29461, 29634, 29548, 29695, 29638, 29757, 29728, 29818, 29814, 29879, 29897, 29941, 29972, 29992,
 30033, 30044, 30094, 30098, 30156, 30157, 30217, 30219, 30279, 30284, 30340, 30350, 30402, 30418, 30463, 30483, 30524, 30550, 30586,
 30615, 30646, 30679, 30706, 30740, 30766, 30802, 30826, 30863, 30890, 30925, 30954, 30985, 31016, 31042, 31078, 31098, 31140, 31152,
 31202, 31208, 31265, 31264, 31328, 31321, 31390, 31379, 31453, 31442, 31515, 31510, 31576, 31581, 31637, 31655, 31683, 31719, 31721,
 31783, 31753, 31849, 31781, 31916, 31810, 31983, 31839, 32052, 31872, 32120, 31916, 32188, 31971, 32255, 32046, 32320, 32144, 32382,
 32272, 32440, 32391, 32378, 32465, 32246, 32550, 32005, 32654, 31527, 32767, 30202, 32767, -1609, -32767, -30067, -32768, -31397, -32768,
 -31884, -32666, -32135, -32570, -32282, -32481, -32359, -32345, -32317, -32202, -32270, -32089, -32220, -32000, -32166, -31932, -32110,
 -31878, -32051, -31837, -31989, -31802, -31927, -31770, -31863, -31740, -31799, -31706, -31734, -31670, -31669, -31626, -31592, -31567,
 -31518, -31508, -31450, -31448, -31385, -31388, -31322, -31327, -31264, -31266, -31207, -31204, -31151, -31143, -31095, -31081, -31039,
 -31019, -30983, -30956, -30923, -30891, -30863, -30828, -30802, -30767, -30740, -30705, -30679, -30647, -30616, -30587, -30550, -30524,
 -30483, -30464, -30418, -30402, -30351, -30341, -30285, -30280, -30220, -30218, -30158, -30156, -30099, -30094, -30043, -30034, -29992,
 -29972, -29942, -29896, -29880, -29813, -29818, -29728, -29757, -29638, -29696, -29548, -29635, -29461, -29572, -29379, -29512, -29306,
 -29450, -29245, -29389, -29201, -29327, -29179, -29266, -29182, -29203, -29174, -29029, -29111, -28789, -29051, -28458, -28989, -27918,
 -28927, -26634, -28867, 0};
 
const int16_t wave45[257] = {
0, 29516, 27228, 29567, 28528, 29618, 29070, 29669, 29398, 29721, 29629, 29772, 29798, 29771, 29849, 29755, 29900, 29765, 29951, 29799,
 30002, 29850, 30054, 29914, 30105, 29985, 30156, 30063, 30207, 30143, 30258, 30223, 30310, 30299, 30361, 30373, 30412, 30438, 30452,
 30489, 30494, 30540, 30538, 30591, 30587, 30642, 30638, 30693, 30693, 30745, 30749, 30796, 30806, 30847, 30862, 30898, 30919, 30949,
 30974, 30999, 31027, 31049, 31078, 31099, 31129, 31149, 31181, 31202, 31232, 31256, 31282, 31308, 31329, 31359, 31374, 31411, 31418,
 31463, 31464, 31515, 31510, 31568, 31556, 31620, 31605, 31672, 31658, 31724, 31715, 31775, 31777, 31826, 31840, 31861, 31893, 31888,
 31947, 31910, 32002, 31929, 32058, 31947, 32114, 31967, 32171, 31991, 32228, 32025, 32285, 32071, 32340, 32137, 32394, 32226, 32446,
 32345, 32495, 32454, 32421, 32516, 32278, 32586, 32026, 32673, 31537, 32767, 30201, 32767, -1341, -32767, -30088, -32768, -31428, -32768,
 -31925, -32683, -32185, -32603, -32341, -32529, -32428, -32406, -32392, -32274, -32353, -32173, -32311, -32095, -32267, -32038, -32219,
 -31995, -32170, -31965, -32118, -31941, -32067, -31920, -32014, -31900, -31960, -31876, -31906, -31850, -31852, -31816, -31786, -31767,
 -31722, -31718, -31665, -31668, -31610, -31618, -31557, -31567, -31510, -31516, -31463, -31465, -31417, -31414, -31372, -31362, -31326,
 -31310, -31280, -31258, -31230, -31203, -31180, -31150, -31129, -31100, -31078, -31048, -31027, -31001, -30974, -30950, -30919, -30898,
 -30862, -30848, -30806, -30797, -30750, -30746, -30694, -30694, -30639, -30643, -30587, -30591, -30539, -30540, -30493, -30490, -30452,
 -30438, -30413, -30372, -30362, -30298, -30309, -30223, -30259, -30143, -30208, -30063, -30157, -29985, -30105, -29913, -30054, -29850,
 -30003, -29799, -29952, -29766, -29901, -29755, -29850, -29770, -29797, -29773, -29630, -29721, -29397, -29670, -29070, -29619, -28529,
 -29567, -27228, -29517, 0};

const int16_t wave46[257] = {
0, 30166, 27821, 30207, 29139, 30248, 29682, 30289, 30006, 30330, 30231, 30371, 30391, 30359, 30432, 30330, 30473, 30330, 30514, 30353,
 30555, 30394, 30596, 30447, 30637, 30510, 30678, 30577, 30719, 30648, 30760, 30718, 30801, 30785, 30842, 30849, 30883, 30903, 30913,
 30944, 30944, 30985, 30977, 31026, 31016, 31067, 31057, 31108, 31102, 31149, 31147, 31190, 31195, 31231, 31241, 31272, 31287, 31313,
 31332, 31353, 31375, 31392, 31416, 31432, 31457, 31472, 31498, 31514, 31539, 31558, 31579, 31600, 31616, 31641, 31651, 31682, 31684,
 31724, 31720, 31766, 31756, 31807, 31792, 31849, 31830, 31891, 31874, 31932, 31921, 31973, 31972, 32014, 32026, 32039, 32068, 32056,
 32111, 32068, 32155, 32076, 32199, 32085, 32245, 32095, 32290, 32109, 32336, 32133, 32381, 32170, 32425, 32228, 32469, 32307, 32510,
 32417, 32549, 32516, 32464, 32566, 32310, 32622, 32047, 32692, 31547, 32767, 30200, 32767, -1073, -32767, -30110, -32768, -31460, -32768,
 -31966, -32700, -32236, -32636, -32400, -32577, -32496, -32466, -32467, -32346, -32436, -32256, -32403, -32190, -32367, -32145, -32329,
 -32112, -32290, -32093, -32248, -32079, -32207, -32069, -32165, -32059, -32122, -32046, -32079, -32030, -32036, -32006, -31980, -31967,
 -31926, -31928, -31879, -31888, -31834, -31848, -31793, -31807, -31755, -31767, -31719, -31726, -31683, -31684, -31648, -31643, -31613,
 -31602, -31577, -31560, -31538, -31516, -31498, -31472, -31457, -31432, -31416, -31391, -31375, -31354, -31333, -31314, -31287, -31272,
 -31241, -31232, -31195, -31191, -31149, -31150, -31103, -31109, -31058, -31068, -31016, -31026, -30978, -30985, -30943, -30945, -30913,
 -30904, -30884, -30848, -30843, -30784, -30801, -30718, -30761, -30647, -30720, -30577, -30679, -30510, -30637, -30446, -30597, -30394,
 -30556, -30354, -30515, -30331, -30474, -30330, -30433, -30358, -30391, -30372, -30232, -30330, -30005, -30290, -29682, -30249, -29140,
 -30207, -27821, -30167, 0};
 
const int16_t wave47[257] = {
0, 30816, 28415, 30847, 29750, 30878, 30293, 30908, 30614, 30939, 30832, 30970, 30985, 30946, 31016, 30906, 31047, 30895, 31077, 30907,
 31108, 30937, 31139, 30981, 31170, 31034, 31200, 31092, 31231, 31152, 31262, 31213, 31293, 31270, 31323, 31324, 31354, 31369, 31373,
 31400, 31394, 31431, 31417, 31461, 31446, 31492, 31476, 31523, 31511, 31554, 31546, 31584, 31584, 31615, 31619, 31646, 31656, 31676,
 31690, 31706, 31723, 31735, 31754, 31765, 31784, 31794, 31815, 31827, 31846, 31861, 31875, 31891, 31902, 31922, 31927, 31953, 31951,
 31985, 31976, 32016, 32002, 32047, 32028, 32079, 32056, 32110, 32089, 32141, 32126, 32172, 32168, 32202, 32211, 32217, 32243, 32224,
 32275, 32225, 32308, 32224, 32341, 32222, 32375, 32222, 32409, 32227, 32443, 32242, 32478, 32270, 32511, 32318, 32543, 32389, 32574,
 32490, 32604, 32579, 32508, 32616, 32342, 32658, 32067, 32710, 31556, 32767, 30199, 32767, -804, -32767, -30131, -32768, -31491, -32768,
 -32006, -32716, -32286, -32669, -32459, -32625, -32564, -32527, -32542, -32418, -32519, -32340, -32494, -32284, -32467, -32251, -32439,
 -32229, -32409, -32222, -32378, -32218, -32347, -32219, -32316, -32219, -32283, -32216, -32251, -32211, -32219, -32197, -32173, -32167,
 -32130, -32138, -32094, -32108, -32059, -32078, -32028, -32048, -32001, -32017, -31975, -31986, -31950, -31955, -31925, -31924, -31900,
 -31893, -31874, -31861, -31845, -31828, -31815, -31795, -31785, -31765, -31754, -31734, -31724, -31707, -31691, -31677, -31656, -31646,
 -31619, -31616, -31584, -31585, -31547, -31555, -31512, -31524, -31478, -31493, -31446, -31461, -31418, -31431, -31393, -31401, -31373,
 -31370, -31355, -31323, -31324, -31269, -31292, -31213, -31263, -31152, -31232, -31092, -31201, -31034, -31170, -30980, -31140, -30937,
 -31109, -30908, -31078, -30896, -31048, -30906, -31017, -30945, -30985, -30971, -30833, -30939, -30613, -30909, -30293, -30879, -29751,
 -30847, -28415, -30817, 0};
 
const int16_t wave48[257] = {
0, 31467, 29009, 31487, 30362, 31507, 30905, 31528, 31221, 31548, 31434, 31569, 31579, 31534, 31600, 31482, 31620, 31459, 31641, 31461,
 31661, 31481, 31682, 31515, 31702, 31558, 31723, 31606, 31743, 31657, 31764, 31709, 31784, 31756, 31804, 31800, 31825, 31835, 31834,
 31856, 31844, 31876, 31857, 31897, 31875, 31917, 31896, 31938, 31920, 31958, 31945, 31979, 31973, 31999, 31998, 32019, 32024, 32040,
 32048, 32059, 32071, 32078, 32091, 32097, 32112, 32117, 32132, 32139, 32153, 32163, 32172, 32183, 32189, 32204, 32203, 32225, 32217,
 32245, 32232, 32266, 32247, 32287, 32264, 32308, 32282, 32329, 32305, 32350, 32332, 32370, 32363, 32390, 32396, 32395, 32418, 32392,
 32439, 32383, 32461, 32371, 32483, 32360, 32506, 32350, 32529, 32345, 32551, 32351, 32574, 32370, 32596, 32409, 32618, 32471, 32639,
 32563, 32658, 32642, 32551, 32666, 32373, 32695, 32088, 32729, 31566, 32767, 30198, 32767, -536, -32767, -30153, -32768, -31522, -32768,
 -32047, -32733, -32336, -32702, -32519, -32672, -32632, -32587, -32618, -32490, -32602, -32423, -32585, -32379, -32567, -32357, -32549,
 -32347, -32529, -32350, -32508, -32357, -32488, -32368, -32466, -32379, -32445, -32387, -32423, -32391, -32402, -32387, -32367, -32368,
 -32334, -32348, -32308, -32328, -32284, -32308, -32263, -32288, -32247, -32267, -32231, -32247, -32216, -32226, -32202, -32206, -32187,
 -32185, -32172, -32163, -32152, -32140, -32133, -32117, -32113, -32098, -32092, -32077, -32072, -32060, -32049, -32041, -32024, -32019,
 -31998, -32000, -31973, -31979, -31946, -31959, -31921, -31939, -31897, -31918, -31875, -31897, -31858, -31876, -31843, -31857, -31834,
 -31836, -31826, -31799, -31805, -31755, -31784, -31709, -31764, -31657, -31744, -31606, -31724, -31558, -31702, -31514, -31683, -31481,
 -31662, -31462, -31642, -31460, -31621, -31482, -31601, -31533, -31579, -31570, -31435, -31548, -31220, -31529, -30905, -31508, -30363, 
 -31487, -29009, -31468, 0};
 
const int16_t wave49[257] = {
0, 32117, 29602, 32127, 30973, 32137, 31517, 32147, 31829, 32158, 32035, 32168, 32173, 32121, 32183, 32058, 32194, 32024, 32204, 32015,
 32214, 32025, 32224, 32049, 32235, 32082, 32245, 32121, 32255, 32162, 32265, 32204, 32276, 32241, 32286, 32276, 32296, 32301, 32294,
 32311, 32294, 32322, 32296, 32332, 32305, 32342, 32315, 32352, 32329, 32363, 32344, 32373, 32361, 32383, 32376, 32393, 32393, 32403,
 32407, 32413, 32419, 32421, 32429, 32430, 32439, 32439, 32450, 32452, 32460, 32465, 32469, 32475, 32475, 32485, 32480, 32496, 32483,
 32506, 32488, 32517, 32493, 32527, 32499, 32538, 32507, 32548, 32520, 32558, 32537, 32569, 32559, 32579, 32582, 32573, 32592, 32559,
 32603, 32540, 32614, 32519, 32625, 32497, 32636, 32478, 32648, 32464, 32659, 32460, 32671, 32469, 32682, 32499, 32692, 32552, 32703,
 32635, 32713, 32704, 32594, 32717, 32405, 32731, 32108, 32748, 31575, 32767, 30197, 32767, -268, -32767, -30174, -32768, -31554, -32768,
 -32088, -32750, -32386, -32735, -32578, -32720, -32700, -32648, -32693, -32562, -32685, -32507, -32677, -32474, -32668, -32463, -32658,
 -32464, -32648, -32478, -32637, -32496, -32628, -32518, -32617, -32539, -32606, -32557, -32596, -32572, -32585, -32578, -32560, -32568,
 -32538, -32558, -32523, -32548, -32509, -32538, -32499, -32528, -32492, -32518, -32487, -32507, -32483, -32497, -32478, -32487, -32474,
 -32476, -32469, -32465, -32460, -32452, -32450, -32440, -32440, -32430, -32430, -32420, -32420, -32414, -32408, -32404, -32393, -32393,
 -32376, -32384, -32361, -32374, -32345, -32364, -32330, -32353, -32316, -32343, -32305, -32332, -32297, -32322, -32293, -32312, -32294,
 -32302, -32297, -32275, -32287, -32240, -32275, -32204, -32266, -32162, -32256, -32121, -32246, -32082, -32235, -32048, -32225, -32025,
 -32215, -32016, -32205, -32025, -32195, -32058, -32184, -32120, -32173, -32169, -32036, -32158, -31828, -32148, -31517, -32138, -30974,
 -32127, -29602, -32118, 0};
 
const int16_t wave50[257] = {
0, 32767, 30196, 32767, 31584, 32767, 32129, 32767, 32437, 32767, 32637, 32767, 32767, 32709, 32767, 32634, 32767, 32589, 32767, 32569,
 32767, 32569, 32767, 32583, 32767, 32606, 32767, 32635, 32767, 32667, 32767, 32699, 32767, 32727, 32767, 32752, 32767, 32767, 32755,
 32767, 32744, 32767, 32736, 32767, 32734, 32767, 32734, 32767, 32738, 32767, 32743, 32767, 32750, 32767, 32755, 32767, 32761, 32767,
 32765, 32766, 32767, 32764, 32767, 32763, 32767, 32762, 32767, 32764, 32767, 32767, 32766, 32767, 32762, 32767, 32756, 32767, 32749,
 32767, 32744, 32767, 32739, 32767, 32735, 32767, 32733, 32767, 32736, 32767, 32743, 32767, 32754, 32767, 32767, 32751, 32767, 32727,
 32767, 32698, 32767, 32666, 32767, 32635, 32767, 32606, 32767, 32582, 32767, 32569, 32767, 32569, 32767, 32590, 32767, 32634, 32767,
 32708, 32767, 32767, 32637, 32767, 32437, 32767, 32129, 32767, 31585, 32767, 30196, 32767, 0, -32767, -30196, -32768, -31585, -32768,
 -32129, -32767, -32436, -32768, -32637, -32768, -32768, -32708, -32768, -32634, -32768, -32590, -32768, -32569, -32768, -32569, -32768,
 -32581, -32768, -32606, -32767, -32635, -32768, -32667, -32768, -32699, -32768, -32727, -32768, -32752, -32768, -32768, -32754, -32768,
 -32742, -32768, -32737, -32768, -32734, -32768, -32734, -32768, -32738, -32768, -32743, -32768, -32749, -32768, -32755, -32768, -32761,
 -32768, -32766, -32767, -32767, -32764, -32768, -32762, -32768, -32763, -32768, -32763, -32768, -32767, -32766, -32768, -32761, -32767,
 -32755, -32768, -32750, -32768, -32744, -32768, -32739, -32768, -32735, -32768, -32734, -32767, -32737, -32767, -32743, -32768, -32755,
 -32768, -32768, -32751, -32768, -32726, -32767, -32699, -32768, -32667, -32768, -32635, -32768, -32606, -32767, -32582, -32768, -32569,
 -32768, -32570, -32768, -32590, -32768, -32634, -32768, -32708, -32767, -32768, -32638, -32767, -32436, -32768, -32129, -32768, -31585,
 -32767, -30196, -32768, 0};
 
const int16_t wave51[257] = {
4, 32126, 29617, 32147, 30998, 32167, 31552, 32188, 31875, 32208, 32091, 32229, 32239, 32192, 32259, 32139, 32280, 32116, 32300, 32117,
 32321, 32137, 32341, 32171, 32362, 32214, 32382, 32263, 32403, 32315, 32423, 32367, 32444, 32415, 32464, 32460, 32485, 32495, 32493,
 32515, 32503, 32536, 32516, 32556, 32534, 32577, 32555, 32597, 32579, 32618, 32605, 32638, 32632, 32659, 32657, 32679, 32684, 32700,
 32708, 32719, 32730, 32738, 32750, 32758, 32763, 32747, 32742, 32729, 32722, 32711, 32700, 32691, 32676, 32670, 32649, 32650, 32622,
 32630, 32597, 32609, 32571, 32589, 32547, 32568, 32525, 32548, 32507, 32527, 32493, 32507, 32484, 32486, 32476, 32450, 32455, 32406,
 32435, 32357, 32415, 32305, 32394, 32254, 32374, 32206, 32353, 32161, 32333, 32128, 32312, 32108, 32292, 32108, 32271, 32131, 32251,
 32183, 32230, 32220, 32082, 32199, 31866, 32179, 31544, 32158, 30990, 32138, 29608, 32118, -4, -32126, -29617, -32148, -30999, -32168,
 -31552, -32188, -31874, -32209, -32091, -32230, -32240, -32191, -32260, -32139, -32281, -32117, -32301, -32117, -32322, -32137, -32342,
 -32169, -32363, -32214, -32382, -32263, -32404, -32315, -32424, -32367, -32445, -32415, -32465, -32460, -32486, -32496, -32492, -32516,
 -32501, -32537, -32517, -32557, -32534, -32578, -32555, -32598, -32579, -32619, -32605, -32639, -32631, -32660, -32657, -32680, -32684,
 -32701, -32709, -32720, -32730, -32738, -32751, -32757, -32764, -32748, -32743, -32728, -32723, -32711, -32700, -32692, -32675, -32670,
 -32648, -32651, -32623, -32631, -32597, -32610, -32571, -32590, -32547, -32569, -32525, -32548, -32508, -32527, -32493, -32508, -32485,
 -32487, -32477, -32450, -32456, -32405, -32435, -32358, -32415, -32306, -32395, -32254, -32375, -32206, -32353, -32161, -32334, -32128,
 -32313, -32109, -32293, -32108, -32272, -32131, -32252, -32183, -32230, -32221, -32083, -32199, -31865, -32180, -31543, -32159, -30990,
 -32138, -29608, -32119, 4};
 
const int16_t wave52[257] = {
9, 31486, 29038, 31526, 30411, 31567, 30975, 31608, 31312, 31649, 31545, 31690, 31711, 31676, 31752, 31645, 31793, 31642, 31834, 31664,
 31875, 31705, 31916, 31759, 31957, 31822, 31998, 31891, 32038, 31963, 32079, 32035, 32120, 32102, 32161, 32167, 32202, 32223, 32232,
 32264, 32262, 32305, 32295, 32346, 32335, 32387, 32375, 32428, 32420, 32469, 32466, 32510, 32514, 32551, 32559, 32592, 32606, 32633,
 32651, 32673, 32693, 32712, 32734, 32753, 32760, 32732, 32718, 32694, 32677, 32656, 32635, 32615, 32590, 32574, 32543, 32533, 32495,
 32492, 32449, 32451, 32404, 32410, 32359, 32369, 32316, 32328, 32278, 32287, 32244, 32246, 32213, 32205, 32185, 32149, 32144, 32085,
 32103, 32016, 32062, 31944, 32021, 31874, 31980, 31805, 31939, 31741, 31898, 31688, 31857, 31647, 31816, 31626, 31775, 31627, 31734,
 31657, 31693, 31673, 31528, 31632, 31295, 31591, 30958, 31550, 30395, 31509, 29020, 31468, -9, -31485, -29038, -31527, -30412, -31568,
 -30975, -31608, -31311, -31650, -31545, -31691, -31712, -31675, -31753, -31645, -31794, -31643, -31835, -31664, -31876, -31705, -31917,
 -31757, -31958, -31823, -31997, -31891, -32039, -31963, -32080, -32035, -32121, -32102, -32162, -32167, -32203, -32224, -32231, -32265,
 -32260, -32306, -32296, -32347, -32335, -32388, -32375, -32428, -32420, -32470, -32466, -32510, -32513, -32552, -32559, -32593, -32606,
 -32634, -32652, -32674, -32693, -32712, -32735, -32752, -32761, -32733, -32719, -32693, -32678, -32656, -32635, -32616, -32589, -32574,
 -32542, -32534, -32496, -32493, -32449, -32452, -32404, -32411, -32359, -32370, -32317, -32328, -32279, -32287, -32244, -32247, -32214,
 -32206, -32186, -32149, -32145, -32084, -32103, -32017, -32063, -31945, -32022, -31874, -31981, -31805, -31939, -31741, -31899, -31688,
 -31858, -31648, -31817, -31626, -31776, -31627, -31735, -31657, -31693, -31674, -31529, -31632, -31294, -31592, -30958, -31551, -30395,
 -31509, -29020, -31469, 9};
 
const int16_t wave53[257] = {
13, 30845, 28459, 30906, 29825, 30968, 30399, 31029, 30750, 31090, 30999, 31152, 31183, 31159, 31244, 31150, 31306, 31169, 31367, 31212,
 31428, 31273, 31490, 31348, 31551, 31431, 31613, 31519, 31674, 31611, 31736, 31703, 31797, 31790, 31859, 31875, 31920, 31951, 31970,
 32012, 32021, 32074, 32075, 32135, 32135, 32196, 32196, 32258, 32261, 32319, 32328, 32381, 32396, 32442, 32462, 32504, 32529, 32565,
 32594, 32626, 32657, 32686, 32717, 32748, 32756, 32717, 32693, 32659, 32631, 32600, 32569, 32539, 32504, 32477, 32436, 32416, 32368,
 32355, 32302, 32293, 32236, 32232, 32171, 32170, 32108, 32109, 32049, 32047, 31994, 31986, 31943, 31925, 31894, 31848, 31832, 31764,
 31771, 31675, 31710, 31584, 31648, 31493, 31587, 31405, 31525, 31320, 31464, 31247, 31402, 31185, 31341, 31144, 31279, 31124, 31218,
 31132, 31156, 31126, 30973, 31064, 30723, 31003, 30373, 30941, 29800, 30880, 28433, 30819, -13, -30845, -28459, -30907, -29826, -30969,
 -30399, -31029, -30749, -31091, -30999, -31153, -31184, -31158, -31245, -31150, -31307, -31170, -31368, -31212, -31429, -31273, -31491,
 -31346, -31552, -31431, -31613, -31519, -31675, -31611, -31737, -31702, -31798, -31790, -31860, -31875, -31921, -31952, -31969, -32013,
 -32019, -32074, -32076, -32136, -32135, -32197, -32196, -32259, -32261, -32320, -32328, -32382, -32395, -32443, -32462, -32505, -32529,
 -32566, -32595, -32627, -32657, -32686, -32718, -32747, -32757, -32718, -32694, -32658, -32632, -32600, -32569, -32540, -32503, -32477,
 -32435, -32417, -32369, -32356, -32302, -32294, -32236, -32233, -32171, -32171, -32108, -32109, -32050, -32047, -31994, -31987, -31944,
 -31926, -31895, -31848, -31833, -31763, -31771, -31676, -31710, -31585, -31649, -31493, -31588, -31405, -31525, -31320, -31465, -31247,
 -31403, -31186, -31342, -31144, -31280, -31124, -31219, -31132, -31156, -31127, -30974, -31064, -30722, -31004, -30372, -30942, -29800,
 -30880, -28432, -30820, 13};
 
const int16_t wave54[257] = {
18, 30204, 27880, 30286, 29238, 30368, 29822, 30450, 30187, 30532, 30453, 30614, 30655, 30642, 30737, 30655, 30818, 30696, 30900, 30759,
 30982, 30841, 31064, 30936, 31146, 31039, 31228, 31148, 31310, 31259, 31392, 31370, 31474, 31478, 31556, 31583, 31638, 31679, 31709,
 31760, 31780, 31842, 31855, 31924, 31935, 32006, 32017, 32088, 32103, 32170, 32189, 32252, 32277, 32334, 32364, 32416, 32451, 32498,
 32536, 32579, 32620, 32660, 32701, 32744, 32752, 32703, 32669, 32623, 32586, 32544, 32503, 32463, 32418, 32381, 32330, 32299, 32241,
 32217, 32155, 32135, 32068, 32053, 31983, 31971, 31899, 31889, 31820, 31808, 31744, 31726, 31673, 31644, 31603, 31547, 31521, 31443,
 31439, 31334, 31357, 31223, 31275, 31113, 31193, 31004, 31111, 30900, 31029, 30806, 30947, 30724, 30865, 30662, 30783, 30620, 30702,
 30606, 30620, 30579, 30418, 30497, 30152, 30415, 29787, 30333, 29205, 30251, 27845, 30169, -18, -30204, -27880, -30287, -29239, -30369,
 -29822, -30450, -30186, -30533, -30453, -30615, -30656, -30641, -30738, -30655, -30819, -30697, -30901, -30759, -30983, -30841, -31065,
 -30934, -31147, -31039, -31228, -31148, -31311, -31259, -31393, -31370, -31475, -31478, -31557, -31583, -31639, -31679, -31708, -31761,
 -31778, -31843, -31856, -31925, -31935, -32007, -32017, -32089, -32103, -32171, -32189, -32253, -32276, -32335, -32364, -32417, -32451,
 -32499, -32537, -32580, -32620, -32660, -32702, -32743, -32753, -32703, -32669, -32622, -32587, -32544, -32503, -32464, -32417, -32381,
 -32329, -32300, -32242, -32218, -32155, -32136, -32068, -32054, -31983, -31972, -31900, -31889, -31821, -31808, -31744, -31727, -31673,
 -31645, -31604, -31547, -31522, -31442, -31439, -31335, -31358, -31224, -31276, -31113, -31194, -31004, -31111, -30900, -31030, -30806,
 -30948, -30725, -30866, -30662, -30784, -30620, -30702, -30606, -30620, -30580, -30419, -30497, -30151, -30416, -29787, -30334, -29205,
 -30251, -27845, -30170, 18};
 
const int16_t wave55[257] = {
22, 29563, 27301, 29666, 28652, 29768, 29245, 29871, 29625, 29973, 29907, 30075, 30127, 30125, 30229, 30161, 30331, 30222, 30434, 30307,
 30536, 30409, 30639, 30524, 30741, 30647, 30843, 30776, 30946, 30907, 31048, 31038, 31151, 31166, 31253, 31291, 31356, 31406, 31447,
 31509, 31540, 31611, 31635, 31714, 31735, 31816, 31838, 31918, 31944, 32021, 32051, 32123, 32159, 32226, 32266, 32328, 32374, 32431,
 32479, 32533, 32583, 32634, 32684, 32739, 32749, 32688, 32644, 32588, 32541, 32489, 32438, 32387, 32331, 32284, 32223, 32182, 32114,
 32080, 32008, 31978, 31901, 31875, 31795, 31773, 31691, 31670, 31591, 31568, 31495, 31465, 31402, 31363, 31312, 31246, 31209, 31122,
 31107, 30994, 31005, 30862, 30902, 30732, 30800, 30604, 30697, 30479, 30595, 30365, 30493, 30263, 30390, 30180, 30288, 30117, 30185,
 30081, 30083, 30032, 29863, 29929, 29581, 29827, 29202, 29724, 28609, 29622, 27257, 29520, -22, -29563, -27301, -29667, -28653, -29769,
 -29245, -29871, -29624, -29974, -29907, -30076, -30128, -30125, -30230, -30160, -30332, -30223, -30435, -30307, -30537, -30409, -30639,
 -30522, -30742, -30647, -30843, -30776, -30947, -30907, -31049, -31038, -31152, -31166, -31254, -31291, -31356, -31407, -31446, -31510,
 -31538, -31612, -31636, -31715, -31735, -31817, -31838, -31919, -31944, -32022, -32051, -32124, -32158, -32227, -32266, -32329, -32374,
 -32432, -32480, -32534, -32583, -32634, -32685, -32738, -32750, -32689, -32645, -32587, -32542, -32489, -32437, -32388, -32330, -32284,
 -32222, -32183, -32115, -32081, -32008, -31978, -31901, -31876, -31795, -31773, -31691, -31670, -31592, -31568, -31495, -31466, -31403,
 -31364, -31312, -31246, -31210, -31121, -31107, -30995, -31005, -30863, -30903, -30732, -30801, -30604, -30697, -30479, -30596, -30366,
 -30493, -30264, -30391, -30180, -30289, -30117, -30186, -30081, -30083, -30033, -29864, -29929, -29580, -29828, -29201, -29725, -28609, 
 -29622, -27257, -29521, 22};
 
const int16_t wave56[257] = {
26, 28923, 26722, 29045, 28066, 29168, 28668, 29291, 29062, 29414, 29361, 29537, 29598, 29609, 29721, 29666, 29844, 29749, 29967, 29854,
 30090, 29977, 30213, 30112, 30336, 30255, 30459, 30404, 30581, 30555, 30704, 30706, 30827, 30853, 30950, 30998, 31073, 31134, 31186, 31257,
 31299, 31380, 31414, 31503, 31536, 31626, 31658, 31749, 31785, 31872, 31912, 31995, 32041, 32118, 32168, 32241, 32296, 32364, 32422, 32486,
 32546, 32608, 32668, 32734, 32745, 32673, 32619, 32553, 32496, 32433, 32372, 32311, 32245, 32188, 32117, 32065, 31987, 31942, 31860, 31820,
 31733, 31697, 31607, 31574, 31482, 31451, 31362, 31328, 31245, 31205, 31132, 31082, 31020, 30945, 30898, 30801, 30775, 30653, 30652, 30501,
 30529, 30351, 30406, 30203, 30283, 30059, 30160, 29925, 30038, 29802, 29914, 29697, 29792, 29613, 29669, 29555, 29546, 29485, 29309, 29362,
 29010, 29239, 28616, 29116, 28014, 28993, 26669, 28870, -26, -28922, -26722, -29046, -28067, -29169, -28668, -29291, -29061, -29415, -29361,
 -29538, -29599, -29608, -29722, -29666, -29845, -29750, -29968, -29854, -30091, -29977, -30214, -30110, -30337, -30256, -30458, -30404, -30582,
 -30555, -30705, -30706, -30828, -30853, -30951, -30998, -31074, -31135, -31185, -31258, -31297, -31381, -31415, -31504, -31536, -31627, -31658,
 -31749, -31785, -31873, -31912, -31995, -32040, -32119, -32168, -32242, -32296, -32365, -32423, -32487, -32546, -32608, -32669, -32733, -32746,
 -32674, -32620, -32552, -32497, -32433, -32372, -32311, -32244, -32188, -32116, -32066, -31988, -31943, -31860, -31820, -31733, -31697, -31607,
 -31574, -31483, -31451, -31363, -31328, -31245, -31206, -31133, -31083, -31021, -30945, -30899, -30800, -30775, -30654, -30653, -30502, -30530,
 -30351, -30407, -30203, -30283, -30059, -30161, -29925, -30038, -29803, -29915, -29697, -29793, -29613, -29670, -29555, -29546, -29485, -29310,
 -29362, -29009, -29240, -28616, -29117, -28014, -28993, -26669, -28871, 26};
 
const int16_t wave57[257] = {
31, 28282, 26142, 28425, 27479, 28569, 28091, 28712, 28500, 28855, 28815, 28999, 29070, 29092, 29214, 29171, 29357, 29275, 29500, 29402, 29644,
 29545, 29787, 29701, 29930, 29864, 30074, 30032, 30217, 30203, 30361, 30374, 30504, 30541, 30648, 30706, 30791, 30862, 30924, 31006, 31058, 31149,
 31194, 31292, 31336, 31436, 31479, 31579, 31626, 31722, 31774, 31866, 31923, 32009, 32070, 32153, 32219, 32297, 32365, 32440, 32510, 32582, 32651,
 32729, 32742, 32658, 32595, 32518, 32451, 32378, 32306, 32235, 32159, 32091, 32010, 31948, 31861, 31805, 31713, 31662, 31565, 31518, 31419, 31375,
 31274, 31231, 31133, 31088, 30995, 30945, 30861, 30801, 30729, 30644, 30586, 30480, 30443, 30312, 30300, 30141, 30156, 29971, 30013, 29803, 29869,
 29638, 29726, 29484, 29583, 29340, 29439, 29215, 29296, 29110, 29152, 29030, 29009, 28938, 28754, 28794, 28439, 28651, 28031, 28507, 27419, 28364,
 26081, 28221, -31, -28282, -26142, -28426, -27480, -28570, -28092, -28712, -28499, -28856, -28815, -28999, -29071, -29091, -29215, -29171, -29358,
 -29276, -29501, -29402, -29645, -29545, -29788, -29699, -29931, -29864, -30074, -30032, -30218, -30203, -30362, -30374, -30505, -30541, -30648,
 -30706, -30792, -30863, -30923, -31007, -31056, -31150, -31195, -31293, -31336, -31436, -31479, -31580, -31626, -31723, -31774, -31867, -31922,
 -32010, -32070, -32154, -32219, -32297, -32366, -32440, -32509, -32582, -32652, -32728, -32742, -32659, -32596, -32517, -32451, -32378, -32306,
 -32235, -32158, -32091, -32009, -31949, -31862, -31806, -31713, -31663, -31565, -31519, -31419, -31376, -31274, -31231, -31134, -31088, -30996,
 -30946, -30862, -30802, -30730, -30644, -30587, -30479, -30443, -30313, -30300, -30142, -30157, -29971, -30014, -29803, -29869, -29638, -29727,
 -29484, -29584, -29341, -29440, -29215, -29297, -29110, -29153, -29030, -29009, -28938, -28755, -28794, -28438, -28652, -28030, -28508, -27419,
 -28364, -26081, -28222, 31};
 
const int16_t wave58[257] = {
35, 27641, 25563, 27805, 26893, 27969, 27515, 28133, 27937, 28296, 28269, 28460, 28542, 28575, 28706, 28676, 28870, 28802, 29034, 28949, 29198,
 29113, 29361, 29289, 29525, 29472, 29689, 29660, 29853, 29851, 30017, 30042, 30181, 30229, 30345, 30414, 30509, 30590, 30662, 30754, 30817, 30918,
 30974, 31082, 31136, 31245, 31300, 31409, 31467, 31573, 31635, 31737, 31805, 31901, 31972, 32065, 32141, 32229, 32308, 32393, 32473, 32556, 32635,
 32724, 32738, 32643, 32570, 32483, 32405, 32322, 32240, 32159, 32073, 31995, 31904, 31831, 31734, 31667, 31566, 31504, 31398, 31340, 31231, 31176,
 31065, 31012, 30904, 30848, 30746, 30684, 30591, 30520, 30438, 30343, 30275, 30159, 30111, 29971, 29947, 29780, 29783, 29590, 29619, 29402, 29455,
 29218, 29291, 29043, 29128, 28879, 28964, 28733, 28800, 28606, 28636, 28505, 28472, 28391, 28199, 28226, 27868, 28063, 27445, 27899, 26824, 27735,
 25493, 27571, -35, -27641, -25563, -27806, -26894, -27970, -27515, -28133, -27936, -28297, -28269, -28461, -28543, -28574, -28707, -28676, -28871,
 -28803, -29034, -28949, -29199, -29113, -29362, -29287, -29526, -29472, -29689, -29660, -29854, -29851, -30018, -30042, -30182, -30229, -30346,
 -30414, -30509, -30591, -30661, -30755, -30815, -30919, -30975, -31083, -31136, -31246, -31300, -31410, -31467, -31574, -31635, -31738, -31804,
 -31902, -31972, -32066, -32141, -32230, -32309, -32394, -32473, -32556, -32636, -32723, -32739, -32644, -32571, -32482, -32406, -32322, -32240,
 -32159, -32072, -31995, -31903, -31832, -31735, -31668, -31566, -31505, -31398, -31341, -31231, -31177, -31066, -31012, -30905, -30848, -30746,
 -30685, -30592, -30521, -30439, -30343, -30275, -30158, -30111, -29972, -29948, -29781, -29784, -29590, -29620, -29402, -29455, -29218, -29292,
 -29043, -29129, -28880, -28965, -28733, -28801, -28606, -28637, -28505, -28472, -28391, -28200, -28226, -27867, -28064, -27445, -27900, -26824,
 -27735, -25493, -27572, 35};
 
const int16_t wave59[257] = {
39, 27000, 24984, 27184, 26307, 27369, 26938, 27553, 27375, 27737, 27723, 27922, 28014, 28059, 28199, 28182, 28383, 28329, 28567, 28497, 28751,
 28681, 28936, 28877, 29120, 29080, 29305, 29288, 29489, 29499, 29673, 29710, 29857, 29916, 30042, 30121, 30226, 30318, 30401, 30502, 30576, 30687,
 30754, 30871, 30936, 31055, 31121, 31239, 31308, 31424, 31497, 31608, 31687, 31793, 31875, 31978, 32064, 32162, 32251, 32346, 32436, 32530, 32618,
 32719, 32734, 32628, 32545, 32448, 32360, 32266, 32175, 32082, 31987, 31898, 31797, 31714, 31607, 31530, 31418, 31346, 31230, 31161, 31042, 30977,
 30857, 30793, 30675, 30608, 30496, 30424, 30321, 30240, 30147, 30042, 29963, 29838, 29779, 29630, 29595, 29419, 29410, 29210, 29226, 29002, 29041,
 28797, 28857, 28603, 28673, 28418, 28488, 28251, 28304, 28103, 28120, 27979, 27935, 27843, 27645, 27659, 27296, 27474, 26860, 27290, 26229, 27106, 
 24906, 26922, -39, -27000, -24984, -27185, -26308, -27370, -26938, -27553, -27374, -27738, -27723, -27923, -28015, -28058, -28199, -28182, -28384,
 -28330, -28568, -28497, -28752, -28681, -28937, -28875, -29121, -29080, -29304, -29288, -29489, -29499, -29674, -29709, -29858, -29916, -30043,
 -30121, -30227, -30319, -30400, -30503, -30574, -30687, -30754, -30872, -30936, -31056, -31121, -31240, -31308, -31425, -31497, -31609, -31686,
 -31794, -31875, -31978, -32064, -32163, -32252, -32347, -32436, -32530, -32619, -32718, -32735, -32629, -32546, -32447, -32361, -32266, -32175,
 -32083, -31986, -31898, -31796, -31715, -31608, -31531, -31418, -31347, -31230, -31162, -31042, -30978, -30857, -30793, -30676, -30608, -30496,
 -30425, -30322, -30241, -30148, -30042, -29964, -29837, -29778, -29631, -29595, -29420, -29411, -29210, -29227, -29002, -29041, -28797, -28858,
 -28603, -28674, -28419, -28489, -28251, -28305, -28103, -28120, -27979, -27935, -27844, -27646, -27659, -27295, -27475, -26859, -27291, -26229,
 -27106, -24905, -26923, 39};
 
const int16_t wave60[257] = {
44, 26360, 24405, 26564, 25720, 26769, 26361, 26974, 26812, 27179, 27177, 27384, 27486, 27542, 27691, 27687, 27896, 27855, 28100, 28044, 28305,
 28249, 28510, 28465, 28715, 28688, 28920, 28916, 29124, 29147, 29329, 29377, 29534, 29604, 29739, 29829, 29944, 30046, 30139, 30251, 30335, 30456,
 30533, 30660, 30737, 30865, 30941, 31070, 31149, 31275, 31358, 31480, 31568, 31685, 31777, 31890, 31986, 32095, 32194, 32300, 32399, 32504, 32602,
 32714, 32731, 32613, 32521, 32412, 32315, 32211, 32109, 32006, 31901, 31802, 31691, 31597, 31480, 31393, 31271, 31188, 31062, 30983, 30854, 30778,
 30648, 30573, 30446, 30368, 30246, 30164, 30050, 29959, 29856, 29741, 29651, 29517, 29447, 29289, 29242, 29058, 29037, 28829, 28832, 28601, 28627,
 28377, 28423, 28162, 28218, 27957, 28013, 27769, 27808, 27600, 27603, 27454, 27399, 27296, 27090, 27091, 26725, 26886, 26274, 26682, 25634, 26477,
 24318, 26272, -44, -26359, -24405, -26565, -25721, -26770, -26361, -26974, -26811, -27180, -27177, -27384, -27487, -27541, -27692, -27687, -27896,
 -27856, -28101, -28044, -28306, -28249, -28511, -28463, -28716, -28689, -28919, -28916, -29125, -29147, -29330, -29377, -29535, -29604, -29740,
 -29829, -29945, -30047, -30138, -30252, -30333, -30456, -30534, -30661, -30737, -30866, -30941, -31070, -31149, -31276, -31358, -31480, -31567, 
 -31686, -31777, -31891, -31986, -32096, -32194, -32300, -32399, -32504, -32602, -32713, -32731, -32614, -32522, -32411, -32316, -32211, -32109,
 -32007, -31900, -31802, -31690, -31598, -31481, -31393, -31271, -31189, -31062, -30984, -30854, -30779, -30649, -30573, -30447, -30368, -30247,
 -30165, -30051, -29960, -29857, -29741, -29652, -29516, -29446, -29290, -29243, -29059, -29038, -28829, -28833, -28601, -28627, -28377, -28423,
 -28162, -28219, -27958, -28014, -27769, -27809, -27600, -27604, -27454, -27398, -27297, -27091, -27091, -26724, -26887, -26274, -26683, -25634,
 -26477, -24318, -26273, 44};
 
const int16_t wave61[257] = {
48, 25719, 23826, 25944, 25134, 26169, 25784, 26395, 26250, 26620, 26631, 26845, 26958, 27025, 27183, 27192, 27408, 27382, 27634, 27592, 27859,
 27817, 28084, 28054, 28310, 28297, 28535, 28545, 28760, 28795, 28986, 29045, 29211, 29292, 29436, 29537, 29662, 29774, 29878, 29999, 30094, 30224,
 30313, 30450, 30537, 30675, 30762, 30900, 30991, 31126, 31220, 31351, 31450, 31577, 31679, 31802, 31909, 32028, 32136, 32253, 32362, 32478, 32585,
 32710, 32727, 32599, 32496, 32377, 32270, 32155, 32043, 31930, 31815, 31705, 31584, 31480, 31353, 31255, 31124, 31030, 30895, 30805, 30666, 30579,
 30440, 30354, 30217, 30129, 29997, 29903, 29780, 29678, 29565, 29440, 29340, 29196, 29115, 28948, 28890, 28698, 28664, 28448, 28439, 28201, 28213,
 27956, 27988, 27721, 27763, 27496, 27537, 27287, 27312, 27096, 27087, 26928, 26862, 26749, 26535, 26524, 26154, 26298, 25689, 26073, 25039, 25848,
 23730, 25623, -48, -25719, -23826, -25945, -25135, -26170, -25784, -26395, -26249, -26621, -26631, -26846, -26959, -27024, -27184, -27192, -27409,
 -27383, -27634, -27592, -27860, -27817, -28085, -28052, -28310, -28297, -28535, -28545, -28761, -28795, -28986, -29045, -29212, -29292, -29437,
 -29537, -29662, -29774, -29877, -30000, -30092, -30225, -30314, -30451, -30537, -30676, -30762, -30901, -30991, -31126, -31220, -31352, -31449,
 -31577, -31679, -31803, -31909, -32029, -32137, -32254, -32362, -32478, -32586, -32709, -32728, -32599, -32497, -32376, -32271, -32155, -32043,
 -31931, -31814, -31705, -31583, -31481, -31354, -31256, -31124, -31031, -30895, -30805, -30666, -30580, -30440, -30354, -30218, -30129, -29997,
 -29904, -29781, -29679, -29566, -29440, -29341, -29195, -29114, -28949, -28890, -28699, -28665, -28448, -28440, -28201, -28213, -27956, -27989,
 -27721, -27764, -27497, -27538, -27287, -27313, -27096, -27088, -26928, -26862, -26750, -26536, -26524, -26153, -26299, -25688, -26074, -25039,
 -25848, -23730, -25624, 48};
 
const int16_t wave62[257] = {
53, 25078, 23247, 25324, 24547, 25570, 25207, 25815, 25687, 26061, 26085, 26307, 26430, 26508, 26676, 26698, 26921, 26909, 27167, 27139, 27413,
 27385, 27659, 27642, 27904, 27905, 28150, 28173, 28396, 28443, 28642, 28713, 28888, 28980, 29134, 29244, 29379, 29502, 29616, 29747, 29853, 29993,
 30093, 30239, 30337, 30485, 30583, 30730, 30832, 30976, 31081, 31222, 31332, 31468, 31581, 31714, 31831, 31961, 32079, 32206, 32326, 32452, 32569,
 32705, 32723, 32584, 32472, 32342, 32225, 32099, 31978, 31854, 31729, 31609, 31478, 31363, 31226, 31118, 30977, 30872, 30727, 30626, 30478, 30380,
 30231, 30134, 29988, 29889, 29747, 29643, 29510, 29397, 29274, 29139, 29028, 28875, 28783, 28607, 28537, 28337, 28291, 28068, 28045, 27800, 27799,
 27536, 27554, 27280, 27308, 27034, 27062, 26805, 26816, 26593, 26571, 26403, 26325, 26202, 25980, 25956, 25583, 25710, 25103, 25465, 24444, 25219,
 23142, 24973, -53, -25078, -23247, -25325, -24548, -25571, -25208, -25815, -25686, -26062, -26085, -26308, -26431, -26508, -26677, -26697, -26922,
 -26910, -27168, -27139, -27414, -27385, -27659, -27640, -27905, -27905, -28150, -28173, -28397, -28443, -28643, -28713, -28888, -28980, -29134,
 -29244, -29380, -29502, -29615, -29748, -29851, -29994, -30094, -30240, -30337, -30485, -30583, -30731, -30832, -30977, -31081, -31223, -31331,
 -31469, -31581, -31715, -31831, -31961, -32080, -32207, -32325, -32452, -32569, -32704, -32724, -32584, -32472, -32341, -32225, -32099, -31977,
 -31855, -31728, -31609, -31477, -31364, -31227, -31118, -30977, -30873, -30727, -30627, -30478, -30381, -30232, -30134, -29989, -29889, -29747,
 -29644, -29510, -29398, -29275, -29139, -29029, -28874, -28782, -28608, -28538, -28338, -28292, -28068, -28046, -27800, -27799, -27536, -27554,
 -27281, -27309, -27035, -27063, -26805, -26817, -26593, -26571, -26403, -26325, -26203, -25981, -25956, -25582, -25711, -25103, -25466, -24444,
 -25219, -23142, -24974, 53};
 
const int16_t wave63[257] = {
57, 24437, 22668, 24703, 23961, 24970, 24631, 25236, 25125, 25502, 25539, 25769, 25902, 25992, 26168, 26203, 26434, 26435, 26700, 26687, 26967,
 26953, 27233, 27230, 27499, 27513, 27766, 27801, 28032, 28091, 28298, 28381, 28564, 28667, 28831, 28952, 29097, 29229, 29354, 29496, 29613, 29762,
 29873, 30028, 30137, 30294, 30404, 30560, 30673, 30827, 30943, 31093, 31214, 31360, 31483, 31627, 31754, 31893, 32022, 32160, 32289, 32426, 32552,
 32700, 32720, 32569, 32447, 32307, 32179, 32044, 31912, 31778, 31642, 31512, 31371, 31246, 31099, 30980, 30829, 30714, 30559, 30448, 30290, 30182,
 30023, 29915, 29758, 29649, 29497, 29383, 29239, 29116, 28983, 28838, 28717, 28554, 28450, 28266, 28185, 27976, 27918, 27687, 27652, 27400, 27386,
 27115, 27119, 26840, 26853, 26573, 26587, 26323, 26320, 26089, 26054, 25878, 25788, 25655, 25426, 25388, 25012, 25122, 24518, 24856, 23848, 24590,
 22554, 24324, -57, -24437, -22668, -24704, -23962, -24971, -24631, -25236, -25124, -25503, -25539, -25769, -25903, -25991, -26169, -26203, -26435,
 -26436, -26701, -26687, -26968, -26954, -27234, -27228, -27500, -27513, -27765, -27801, -28032, -28091, -28299, -28381, -28565, -28667, -28832, 
 -28952, -29098, -29230, -29353, -29497, -29611, -29763, -29873, -30029, -30137, -30295, -30404, -30561, -30673, -30828, -30943, -31094, -31213,
 -31361, -31483, -31627, -31754, -31894, -32023, -32160, -32289, -32426, -32553, -32699, -32720, -32570, -32448, -32306, -32180, -32044, -31912,
 -31779, -31641, -31512, -31370, -31247, -31100, -30981, -30829, -30715, -30559, -30449, -30290, -30182, -30023, -29915, -29759, -29649, -29498,
 -29384, -29240, -29117, -28983, -28838, -28717, -28553, -28450, -28267, -28185, -27977, -27919, -27687, -27653, -27400, -27386, -27115, -27120,
 -26840, -26854, -26574, -26588, -26323, -26321, -26089, -26055, -25878, -25788, -25656, -25427, -25388, -25011, -25123, -24517, -24857, -23848,
 -24590, -22554, -24325, 57};
 
const int16_t wave64[257] = {
61, 23797, 22089, 24083, 23375, 24370, 24054, 24657, 24563, 24943, 24993, 25230, 25374, 25475, 25661, 25708, 25947, 25962, 26233, 26235, 26520,
 26521, 26807, 26818, 27094, 27121, 27381, 27429, 27667, 27739, 27954, 28049, 28241, 28355, 28528, 28660, 28815, 28957, 29093, 29244, 29372, 29531,
 29652, 29817, 29938, 30104, 30224, 30391, 30514, 30678, 30804, 30965, 31096, 31252, 31386, 31539, 31676, 31826, 31965, 32113, 32252, 32400, 32535,
 32695, 32716, 32554, 32422, 32272, 32134, 31988, 31846, 31702, 31556, 31415, 31265, 31129, 30972, 30843, 30682, 30556, 30391, 30269, 30102, 29983,
 29814, 29696, 29529, 29409, 29248, 29123, 28969, 28836, 28692, 28537, 28405, 28233, 28118, 27925, 27832, 27615, 27545, 27307, 27259, 26999, 26972,
 26695, 26685, 26399, 26398, 26112, 26111, 25841, 25824, 25586, 25538, 25352, 25251, 25108, 24871, 24821, 24440, 24534, 23932, 24248, 23253, 23961,
 21967, 23675, -61, -23796, -22089, -24084, -23376, -24371, -24054, -24657, -24562, -24944, -24993, -25231, -25375, -25474, -25661, -25708, -25948,
 -25963, -26234, -26235, -26521, -26522, -26808, -26816, -27095, -27122, -27380, -27429, -27668, -27739, -27955, -28048, -28242, -28355, -28529,
 -28660, -28816, -28958, -29092, -29245, -29370, -29531, -29653, -29818, -29938, -30105, -30224, -30391, -30514, -30679, -30804, -30965, -31095,
 -31253, -31386, -31540, -31676, -31827, -31966, -32114, -32252, -32400, -32536, -32694, -32717, -32555, -32423, -32271, -32135, -31988, -31846,
 -31703, -31555, -31415, -31264, -31130, -30973, -30844, -30682, -30557, -30392, -30270, -30102, -29983, -29815, -29696, -29530, -29409, -29248,
 -29123, -28970, -28837, -28692, -28537, -28406, -28232, -28118, -27926, -27833, -27616, -27546, -27307, -27259, -26999, -26972, -26695, -26686,
 -26399, -26399, -26113, -26112, -25841, -25825, -25586, -25538, -25352, -25251, -25109, -24872, -24821, -24439, -24535, -23932, -24248, -23253,
 -23961, -21966, -23675, 61};
 
const int16_t wave65[257] = {
66, 23156, 21510, 23463, 22788, 23770, 23477, 24078, 24000, 24384, 24447, 24692, 24846, 24958, 25153, 25214, 25460, 25489, 25767, 25782, 26074,
 26089, 26382, 26407, 26689, 26730, 26996, 27057, 27303, 27387, 27611, 27717, 27918, 28043, 28225, 28368, 28533, 28685, 28831, 28992, 29131, 29300,
 29432, 29607, 29738, 29914, 30045, 30221, 30355, 30529, 30666, 30836, 30978, 31144, 31288, 31451, 31599, 31759, 31908, 32066, 32215, 32374, 32519,
 32690, 32712, 32539, 32398, 32237, 32089, 31932, 31781, 31626, 31470, 31319, 31158, 31012, 30845, 30705, 30535, 30399, 30224, 30091, 29914, 29784,
 29606, 29476, 29300, 29169, 28998, 28862, 28699, 28555, 28401, 28236, 28094, 27912, 27786, 27585, 27480, 27255, 27172, 26926, 26865, 26599, 26558,
 26274, 26250, 25958, 25944, 25651, 25636, 25359, 25329, 25082, 25022, 24827, 24714, 24561, 24316, 24253, 23869, 23946, 23347, 23639, 22658, 23332,
 21379, 23025, -66, -23156, -21510, -23464, -22789, -23771, -23477, -24078, -23999, -24385, -24447, -24693, -24847, -24958, -25154, -25213, -25461,
 -25490, -25768, -25782, -26075, -26090, -26382, -26405, -26689, -26730, -26996, -27057, -27304, -27387, -27611, -27716, -27919, -28043, -28226,
 -28368, -28533, -28686, -28830, -28993, -29129, -29300, -29433, -29608, -29738, -29915, -30045, -30222, -30355, -30529, -30666, -30837, -30977,
 -31144, -31288, -31452, -31599, -31760, -31909, -32067, -32215, -32374, -32520, -32689, -32713, -32540, -32398, -32236, -32090, -31932, -31780,
 -31627, -31469, -31319, -31157, -31013, -30846, -30706, -30535, -30399, -30224, -30092, -29914, -29784, -29606, -29476, -29301, -29169, -28998,
 -28863, -28699, -28556, -28401, -28236, -28094, -27911, -27786, -27586, -27480, -27256, -27173, -26926, -26866, -26599, -26558, -26274, -26251,
 -25959, -25944, -25652, -25637, -25359, -25330, -25082, -25022, -24827, -24714, -24562, -24317, -24253, -23868, -23947, -23346, -23640, -22658,
 -23332, -21378, -23026, 66};
 
const int16_t wave66[257] = {
70, 22515, 20931, 22843, 22202, 23171, 22900, 23498, 23438, 23826, 23901, 24154, 24317, 24441, 24645, 24719, 24973, 25015, 25300, 25330, 25628,
 25657, 25956, 25995, 26283, 26338, 26611, 26685, 26939, 27035, 27267, 27384, 27595, 27731, 27923, 28075, 28250, 28413, 28570, 28741, 28890, 29069,
 29212, 29396, 29538, 29724, 29866, 30051, 30196, 30379, 30527, 30707, 30859, 31035, 31190, 31363, 31521, 31692, 31851, 32020, 32179, 32348, 32502,
 32685, 32709, 32524, 32373, 32201, 32044, 31877, 31715, 31550, 31384, 31222, 31052, 30895, 30718, 30568, 30388, 30241, 30056, 29913, 29726, 29585,
 29397, 29257, 29071, 28929, 28748, 28602, 28428, 28274, 28109, 27935, 27782, 27591, 27454, 27244, 27127, 26894, 26799, 26545, 26472, 26198, 26144,
 25854, 25816, 25517, 25489, 25189, 25160, 24876, 24833, 24579, 24505, 24301, 24178, 24014, 23761, 23686, 23298, 23358, 22761, 23031, 22063, 22703,
 20791, 22376, -70, -22515, -20931, -22844, -22203, -23172, -22901, -23498, -23437, -23827, -23901, -24154, -24318, -24441, -24646, -24718, -24973,
 -25016, -25301, -25330, -25629, -25658, -25956, -25993, -26284, -26338, -26611, -26685, -26940, -27035, -27268, -27384, -27595, -27731, -27923,
 -28075, -28251, -28414, -28569, -28742, -28888, -29069, -29213, -29397, -29538, -29724, -29866, -30052, -30196, -30380, -30527, -30708, -30858,
 -31036, -31190, -31364, -31521, -31692, -31851, -32020, -32178, -32348, -32503, -32684, -32709, -32525, -32374, -32200, -32044, -31877, -31714,
 -31550, -31383, -31222, -31051, -30896, -30719, -30569, -30388, -30241, -30056, -29913, -29726, -29585, -29398, -29257, -29072, -28929, -28749,
 -28603, -28429, -28275, -28110, -27935, -27783, -27590, -27454, -27245, -27128, -26895, -26800, -26545, -26472, -26198, -26144, -25854, -25817,
 -25518, -25489, -25190, -25161, -24876, -24834, -24579, -24506, -24301, -24177, -24014, -23762, -23686, -23297, -23359, -22761, -23031, -22063,
 -22703, -20791, -22376, 70};
 
const int16_t wave67[257] = {
74, 21874, 20352, 22222, 21616, 22571, 22323, 22919, 22875, 23267, 23355, 23615, 23789, 23925, 24138, 24224, 24486, 24542, 24833, 24877, 25182,
 25225, 25530, 25583, 25878, 25946, 26227, 26313, 26575, 26683, 26923, 27052, 27271, 27418, 27620, 27783, 27968, 28141, 28308, 28489, 28649, 28838,
 28992, 29185, 29338, 29534, 29687, 29881, 30037, 30230, 30389, 30578, 30741, 30927, 31092, 31276, 31444, 31625, 31794, 31973, 32142, 32322, 32486,
 32680, 32705, 32509, 32348, 32166, 31999, 31821, 31649, 31474, 31298, 31126, 30945, 30778, 30591, 30431, 30240, 30083, 29888, 29734, 29538, 29386,
 29189, 29038, 28842, 28689, 28499, 28342, 28158, 27993, 27818, 27634, 27470, 27270, 27122, 26903, 26775, 26533, 26426, 26165, 26078, 25798, 25730,
 25433, 25382, 25077, 25034, 24728, 24685, 24394, 24337, 24076, 23989, 23776, 23641, 23467, 23207, 23118, 22727, 22770, 22176, 22422, 21468, 22074,
 20203, 21726, -74, -21874, -20352, -22223, -21617, -22572, -22324, -22919, -22874, -23268, -23355, -23616, -23790, -23924, -24138, -24224, -24486,
 -24543, -24834, -24877, -25183, -25226, -25531, -25581, -25879, -25946, -26226, -26313, -26575, -26683, -26924, -27052, -27272, -27418, -27620,
 -27783, -27969, -28142, -28307, -28490, -28647, -28838, -28992, -29186, -29338, -29534, -29687, -29882, -30037, -30231, -30389, -30579, -30740,
 -30928, -31092, -31276, -31444, -31625, -31794, -31974, -32141, -32322, -32486, -32679, -32706, -32510, -32349, -32165, -31999, -31821, -31649,
 -31474, -31297, -31126, -30944, -30779, -30592, -30431, -30240, -30083, -29889, -29735, -29538, -29386, -29189, -29038, -28843, -28689, -28499,
 -28342, -28159, -27994, -27819, -27634, -27471, -27269, -27122, -26904, -26775, -26534, -26427, -26165, -26079, -25798, -25730, -25433, -25382,
 -25077, -25034, -24729, -24686, -24394, -24338, -24076, -23989, -23776, -23640, -23467, -23208, -23118, -22726, -22771, -22175, -22423, -21468,
 -22074, -20203, -21727, 74};
 
const int16_t wave68[257] = {
79, 21234, 19773, 21602, 21029, 21971, 21747, 22340, 22313, 22708, 22809, 23077, 23261, 23408, 23630, 23729, 23998, 24069, 24367, 24425, 24736,
 24793, 25104, 25171, 25473, 25554, 25842, 25942, 26210, 26331, 26579, 26720, 26948, 27106, 27317, 27491, 27686, 27869, 28047, 28237, 28408, 28606,
 28771, 28975, 29139, 29343, 29507, 29712, 29879, 30081, 30250, 30450, 30623, 30819, 30994, 31188, 31366, 31557, 31736, 31926, 32105, 32296, 32469,
 32676, 32701, 32495, 32324, 32131, 31953, 31765, 31583, 31398, 31212, 31029, 30839, 30661, 30464, 30293, 30093, 29925, 29721, 29556, 29350, 29187,
 28980, 28818, 28613, 28450, 28249, 28081, 27888, 27712, 27527, 27333, 27159, 26949, 26790, 26562, 26422, 26172, 26053, 25784, 25685, 25397, 25316,
 25013, 24947, 24636, 24579, 24267, 24209, 23912, 23841, 23572, 23473, 23250, 23104, 22920, 22652, 22551, 22156, 22182, 21590, 21814, 20873, 21445,
 19615, 21077, -79, -21233, -19773, -21603, -21030, -21972, -21747, -22340, -22312, -22709, -22809, -23078, -23262, -23407, -23631, -23729, -23999,
 -24070, -24367, -24425, -24737, -24794, -25105, -25169, -25474, -25555, -25841, -25942, -26211, -26331, -26580, -26720, -26949, -27106, -27318,
 -27491, -27686, -27869, -28046, -28238, -28406, -28607, -28772, -28976, -29139, -29344, -29507, -29712, -29879, -30082, -30250, -30450, -30622,
 -30820, -30994, -31189, -31366, -31558, -31737, -31927, -32105, -32296, -32470, -32675, -32702, -32495, -32324, -32130, -31954, -31765, -31583,
 -31398, -31211, -31029, -30838, -30662, -30465, -30294, -30093, -29925, -29721, -29556, -29350, -29187, -28981, -28818, -28614, -28450, -28249,
 -28082, -27888, -27713, -27528, -27333, -27160, -26948, -26790, -26563, -26423, -26173, -26054, -25784, -25685, -25397, -25316, -25013, -24948,
 -24636, -24579, -24268, -24210, -23912, -23842, -23572, -23473, -23250, -23104, -22920, -22653, -22551, -22155, -22183, -21590, -21814, -20873,
 -21445, -19615, -21077, 79};
 
const int16_t wave69[257] = {
83, 20593, 19193, 20982, 20443, 21371, 21170, 21760, 21750, 22149, 22263, 22539, 22733, 22891, 23123, 23235, 23511, 23595, 23900, 23972, 24290,
 24361, 24679, 24760, 25068, 25163, 25457, 25570, 25846, 25979, 26236, 26388, 26625, 26794, 27014, 27198, 27403, 27597, 27785, 27986, 28167, 28375,
 28551, 28764, 28939, 29153, 29328, 29542, 29720, 29932, 30112, 30321, 30505, 30711, 30896, 31100, 31289, 31490, 31679, 31880, 32068, 32270, 32453,
 32671, 32698, 32480, 32299, 32096, 31908, 31710, 31518, 31322, 31126, 30933, 30732, 30544, 30338, 30156, 29946, 29767, 29553, 29377, 29162, 28988,
 28772, 28599, 28384, 28210, 27999, 27821, 27617, 27431, 27236, 27032, 26847, 26628, 26458, 26221, 26070, 25812, 25680, 25404, 25291, 24997, 24902,
 24592, 24513, 24195, 24124, 23806, 23734, 23430, 23345, 23069, 22956, 22725, 22567, 22373, 22097, 21983, 21585, 21594, 21005, 21205, 20278, 20816,
 19027, 20427, -83, -20593, -19193, -20983, -20444, -21372, -21170, -21760, -21749, -22150, -22263, -22539, -22734, -22891, -23123, -23234, -23512,
 -23596, -23901, -23972, -24291, -24362, -24679, -24758, -25068, -25163, -25457, -25570, -25847, -25979, -26236, -26388, -26625, -26794, -27015,
 -27198, -27404, -27597, -27784, -27987, -28165, -28376, -28552, -28765, -28939, -29154, -29328, -29543, -29720, -29932, -30112, -30322, -30504,
 -30711, -30896, -31101, -31289, -31491, -31680, -31880, -32068, -32270, -32453, -32670, -32698, -32480, -32300, -32095, -31909, -31710, -31517,
 -31322, -31125, -30933, -30731, -30545, -30339, -30156, -29946, -29768, -29553, -29378, -29162, -28989, -28772, -28599, -28385, -28210, -28000,
 -27822, -27618, -27432, -27237, -27032, -26848, -26627, -26458, -26222, -26070, -25813, -25681, -25404, -25292, -24997, -24902, -24592, -24513,
 -24196, -24125, -23807, -23735, -23430, -23346, -23069, -22956, -22725, -22567, -22373, -22098, -21983, -21584, -21595, -21004, -21206, -20278,
 -20816, -19027, -20428, 83};
 
const int16_t wave70[257] = {
88, 19952, 18614, 20361, 19856, 20771, 20593, 21181, 21188, 21590, 21717, 22000, 22205, 22375, 22615, 22740, 23024, 23122, 23433, 23520, 23843,
 23929, 24253, 24348, 24663, 24771, 25073, 25198, 25482, 25627, 25892, 26056, 26301, 26481, 26711, 26906, 27121, 27325, 27523, 27734, 27926, 28144,
 28331, 28553, 28739, 28963, 29149, 29372, 29561, 29783, 29973, 30192, 30387, 30603, 30799, 31013, 31211, 31423, 31622, 31833, 32031, 32244, 32436,
 32666, 32694, 32465, 32275, 32061, 31863, 31654, 31452, 31246, 31040, 30836, 30626, 30427, 30211, 30018, 29798, 29609, 29385, 29199, 28974, 28789,
 28563, 28379, 28155, 27970, 27750, 27561, 27347, 27151, 26945, 26731, 26536, 26307, 26126, 25880, 25717, 25451, 25307, 25023, 24898, 24596, 24488,
 24172, 24078, 23755, 23669, 23345, 23259, 22948, 22849, 22565, 22440, 22200, 22030, 21826, 21543, 21415, 21013, 21006, 20419, 20597, 19683, 20187,
 18440, 19778, -88, -19952, -18614, -20362, -19857, -20772, -20593, -21181, -21187, -21591, -21717, -22001, -22206, -22374, -22616, -22740, -23025,
 -23123, -23434, -23520, -23844, -23930, -24254, -24346, -24663, -24771, -25072, -25198, -25482, -25627, -25892, -26055, -26302, -26481, -26712,
 -26906, -27122, -27325, -27522, -27735, -27924, -28144, -28331, -28554, -28739, -28964, -29149, -29373, -29561, -29783, -29973, -30193, -30386,
 -30603, -30799, -31013, -31211, -31424, -31623, -31834, -32031, -32244, -32437, -32665, -32695, -32465, -32275, -32060, -31864, -31654, -31452,
 -31246, -31039, -30836, -30625, -30428, -30212, -30019, -29798, -29610, -29386, -29200, -28974, -28790, -28564, -28379, -28156, -27970, -27750,
 -27561, -27347, -27152, -26946, -26731, -26536, -26306, -26126, -25881, -25718, -25452, -25308, -25023, -24898, -24596, -24488, -24172, -24079,
 -23755, -23670, -23346, -23260, -22948, -22850, -22565, -22440, -22200, -22030, -21826, -21544, -21415, -21012, -21007, -20419, -20597, -19683,
 -20187, -18439, -19778, 88};
 
const int16_t wave71[257] = {
92, 19311, 18035, 19741, 19270, 20172, 20016, 20602, 20625, 21031, 21171, 21462, 21677, 21858, 22107, 22245, 22537, 22648, 22967, 23067, 23397,
 23497, 23827, 23936, 24257, 24379, 24688, 24826, 25118, 25275, 25548, 25724, 25978, 26169, 26409, 26614, 26839, 27052, 27262, 27483, 27686, 27913,
 28111, 28343, 28539, 28773, 28970, 29202, 29402, 29633, 29835, 30063, 30269, 30494, 30701, 30925, 31134, 31356, 31565, 31787, 31995, 32218, 32420,
 32661, 32691, 32450, 32250, 32026, 31818, 31599, 31386, 31170, 30953, 30740, 30519, 30310, 30084, 29881, 29651, 29451, 29218, 29021, 28786, 28591,
 28355, 28160, 27926, 27730, 27500, 27300, 27076, 26870, 26654, 26430, 26224, 25986, 25794, 25539, 25365, 25090, 24934, 24642, 24504, 24196, 24074,
 23751, 23644, 23314, 23214, 22883, 22783, 22466, 22353, 22062, 21923, 21674, 21493, 21279, 20988, 20848, 20442, 20418, 19834, 19988, 19087, 19558, 
 17852, 19128, -92, -19311, -18035, -19742, -19271, -20173, -20017, -20602, -20624, -21032, -21171, -21462, -21678, -21857, -22108, -22245, -22538,
 -22649, -22967, -23067, -23398, -23498, -23828, -23934, -24258, -24379, -24687, -24826, -25118, -25275, -25549, -25723, -25979, -26169, -26409,
 -26614, -26839, -27053, -27261, -27484, -27684, -27913, -28111, -28344, -28539, -28773, -28970, -29203, -29402, -29634, -29835, -30064, -30268,
 -30495, -30701, -30925, -31134, -31356, -31566, -31787, -31994, -32218, -32420, -32660, -32691, -32451, -32251, -32025, -31818, -31599, -31386,
 -31170, -30952, -30740, -30518, -30311, -30085, -29881, -29651, -29452, -29218, -29021, -28786, -28591, -28355, -28160, -27927, -27730, -27501,
 -27301, -27077, -26871, -26654, -26430, -26225, -25985, -25794, -25540, -25365, -25091, -24935, -24642, -24505, -24196, -24074, -23751, -23644,
 -23314, -23215, -22884, -22784, -22466, -22354, -22062, -21924, -21674, -21493, -21279, -20989, -20848, -20441, -20419, -19833, -19989, -19087,
 -19558, -17851, -19129, 92};
 
const int16_t wave72[257] = {
96, 18671, 17456, 19121, 18684, 19572, 19439, 20022, 20063, 20473, 20625, 20924, 21149, 21341, 21600, 21751, 22050, 22175, 22500, 22615, 22951,
 23065, 23402, 23524, 23852, 23987, 24303, 24454, 24753, 24923, 25204, 25391, 25655, 25857, 26106, 26321, 26556, 26780, 27000, 27231, 27445, 27682,
 27890, 28132, 28340, 28583, 28790, 29033, 29243, 29484, 29696, 29935, 30150, 30386, 30603, 30837, 31056, 31289, 31508, 31740, 31958, 32192, 32403,
 32656, 32687, 32435, 32225, 31990, 31773, 31543, 31321, 31094, 30867, 30643, 30413, 30193, 29957, 29743, 29504, 29293, 29050, 28842, 28598, 28392,
 28146, 27941, 27697, 27490, 27250, 27040, 26806, 26589, 26363, 26129, 25913, 25665, 25462, 25198, 25012, 24729, 24561, 24262, 24111, 23795, 23660,
 23331, 23209, 22873, 22759, 22422, 22308, 21984, 21857, 21558, 21407, 21149, 20957, 20732, 20433, 20280, 19871, 19830, 19248, 19380, 18492, 18929,
 17264, 18479, -96, -18670, -17456, -19122, -18685, -19573, -19440, -20022, -20062, -20474, -20625, -20924, -21150, -21341, -21600, -21750, -22050,
 -22176, -22501, -22615, -22952, -23066, -23402, -23522, -23853, -23988, -24302, -24454, -24754, -24923, -25205, -25391, -25655, -25857, -26106,
 -26321, -26557, -26781, -26999, -27232, -27443, -27682, -27891, -28133, -28340, -28583, -28790, -29033, -29243, -29485, -29696, -29935, -30149,
 -30387, -30603, -30838, -31056, -31289, -31508, -31740, -31957, -32192, -32404, -32655, -32687, -32436, -32226, -31989, -31773, -31543, -31320,
 -31094, -30866, -30643, -30412, -30194, -29958, -29744, -29504, -29294, -29050, -28843, -28598, -28392, -28147, -27941, -27698, -27490, -27251,
 -27041, -26807, -26590, -26363, -26129, -25913, -25664, -25462, -25199, -25013, -24730, -24562, -24262, -24111, -23795, -23660, -23331, -23210,
 -22874, -22760, -22423, -22309, -21984, -21858, -21558, -21407, -21149, -20956, -20732, -20434, -20280, -19870, -19831, -19248, -19380, -18492,
 -18929, -17264, -18479, 96};
 
const int16_t wave73[257] = {
101, 18030, 16877, 18501, 18097, 18972, 18863, 19443, 19500, 19914, 20079, 20385, 20621, 20824, 21092, 21256, 21563, 21702, 22033, 22162, 22505,
 22633, 22976, 23113, 23447, 23596, 23918, 24082, 24389, 24571, 24861, 25059, 25332, 25545, 25803, 26029, 26274, 26508, 26739, 26979, 27204, 27451,
 27670, 27921, 28140, 28392, 28611, 28863, 29084, 29335, 29558, 29806, 30032, 30278, 30505, 30749, 30979, 31221, 31451, 31693, 31921, 32166, 32387,
 32651, 32683, 32420, 32201, 31955, 31727, 31487, 31255, 31018, 30781, 30547, 30306, 30076, 29830, 29606, 29357, 29135, 28882, 28664, 28410, 28193,
 27938, 27721, 27468, 27250, 27001, 26780, 26536, 26308, 26072, 25828, 25601, 25344, 25130, 24857, 24660, 24369, 24188, 23881, 23717, 23395, 23246,
 22910, 22775, 22432, 22304, 21961, 21832, 21502, 21361, 21055, 20891, 20623, 20420, 20185, 19878, 19713, 19300, 19242, 18663, 18771, 17897, 18300, 
 16676, 17829, -101, -18030, -16877, -18502, -18098, -18973, -18863, -19443, -19499, -19915, -20079, -20386, -20622, -20824, -21093, -21255, -21563,
 -21703, -22034, -22162, -22506, -22634, -22976, -23111, -23447, -23596, -23918, -24082, -24390, -24571, -24861, -25059, -25332, -25545, -25804,
 -26029, -26275, -26509, -26738, -26980, -27202, -27451, -27671, -27922, -28140, -28393, -28611, -28864, -29084, -29335, -29558, -29807, -30031,
 -30278, -30505, -30750, -30979, -31222, -31451, -31694, -31921, -32166, -32387, -32650, -32684, -32421, -32201, -31954, -31728, -31487, -31254,
 -31018, -30780, -30547, -30305, -30077, -29831, -29606, -29357, -29136, -28883, -28664, -28410, -28193, -27938, -27721, -27469, -27250, -27001,
 -26780, -26536, -26309, -26072, -25828, -25602, -25343, -25130, -24858, -24660, -24370, -24189, -23881, -23718, -23395, -23246, -22910, -22775,
 -22433, -22305, -21962, -21833, -21502, -21362, -21055, -20891, -20623, -20419, -20185, -19879, -19713, -19299, -19243, -18662, -18772, -17897,
 -18300, -16676, -17830, 101};
 
const int16_t wave74[257] = {
105, 17389, 16298, 17880, 17511, 18372, 18286, 18864, 18938, 19355, 19533, 19847, 20093, 20308, 20585, 20761, 21076, 21228, 21567, 21710, 22059,
 22201, 22550, 22701, 23042, 23204, 23534, 23710, 24025, 24219, 24517, 24727, 25008, 25232, 25500, 25737, 25992, 26236, 26477, 26728, 26963, 27220,
 27450, 27711, 27940, 28202, 28432, 28693, 28925, 29186, 29419, 29677, 29914, 30170, 30407, 30662, 30901, 31154, 31394, 31647, 31884, 32140, 32370,
 32646, 32680, 32405, 32176, 31920, 31682, 31432, 31189, 30942, 30695, 30450, 30200, 29959, 29703, 29468, 29209, 28977, 28715, 28485, 28222, 27994,
 27729, 27502, 27239, 27010, 26751, 26519, 26265, 26027, 25781, 25527, 25290, 25023, 24798, 24516, 24307, 24008, 23815, 23501, 23324, 22994, 22832,
 22490, 22340, 21992, 21849, 21500, 21357, 21020, 20865, 20551, 20374, 20098, 19883, 19638, 19324, 19145, 18729, 18654, 18077, 18163, 17302, 17671,
 16088, 17180, -105, -17389, -16298, -17881, -17512, -18373, -18286, -18864, -18937, -19356, -19533, -19847, -20094, -20307, -20585, -20761, -21076,
 -21229, -21567, -21710, -22060, -22202, -22551, -22699, -23042, -23204, -23533, -23710, -24025, -24219, -24517, -24727, -25009, -25232, -25501,
 -25737, -25992, -26237, -26476, -26729, -26961, -27220, -27450, -27712, -27940, -28203, -28432, -28694, -28925, -29186, -29419, -29678, -29913,
 -30170, -30407, -30662, -30901, -31155, -31394, -31647, -31884, -32140, -32371, -32645, -32680, -32406, -32177, -31919, -31683, -31432, -31189,
 -30942, -30694, -30450, -30199, -29960, -29704, -29469, -29209, -28978, -28715, -28486, -28222, -27994, -27730, -27502, -27240, -27010, -26752,
 -26520, -26266, -26028, -25781, -25527, -25290, -25022, -24798, -24517, -24308, -24009, -23816, -23501, -23324, -22994, -22832, -22490, -22341,
 -21992, -21850, -21501, -21358, -21020, -20866, -20551, -20374, -20098, -19882, -19638, -19325, -19145, -18728, -18655, -18077, -18163, -17302,
 -17671, -16088, -17180, 105};
 
const int16_t wave75[257] = {
110, 16749, 15719, 17260, 16925, 17773, 17709, 18285, 18376, 18796, 18988, 19309, 19565, 19791, 20077, 20267, 20589, 20755, 21100, 21258, 21613,
 21770, 22125, 22289, 22637, 22812, 23149, 23339, 23661, 23867, 24173, 24395, 24685, 24920, 25198, 25445, 25710, 25964, 26216, 26476, 26722, 26989,
 27230, 27500, 27741, 28012, 28253, 28524, 28767, 29037, 29281, 29549, 29796, 30062, 30310, 30574, 30824, 31087, 31337, 31600, 31848, 32114, 32354,
 32642, 32676, 32391, 32152, 31885, 31637, 31376, 31124, 30866, 30609, 30354, 30093, 29842, 29576, 29331, 29062, 28820, 28547, 28307, 28034, 27795,
 27521, 27283, 27010, 26771, 26502, 26259, 25995, 25747, 25490, 25227, 24978, 24703, 24466, 24176, 23955, 23647, 23442, 23120, 22931, 22594, 22418,
 22069, 21906, 21551, 21395, 21039, 20882, 20538, 20370, 20048, 19858, 19573, 19346, 19091, 18769, 18578, 18158, 18066, 17492, 17554, 16707, 17042,
 15501, 16531, -110, -16748, -15719, -17261, -16926, -17774, -17710, -18285, -18375, -18797, -18988, -19309, -19566, -19791, -20078, -20266, -20589,
 -20756, -21101, -21258, -21614, -21770, -22125, -22287, -22637, -22813, -23148, -23339, -23661, -23867, -24174, -24395, -24686, -24920, -25198,
 -25445, -25710, -25965, -26215, -26477, -26720, -26989, -27230, -27501, -27741, -28013, -28253, -28524, -28767, -29037, -29281, -29549, -29795,
 -30062, -30310, -30575, -30824, -31088, -31337, -31601, -31847, -32114, -32354, -32641, -32677, -32391, -32152, -31884, -31638, -31376, -31123,
 -30866, -30608, -30354, -30092, -29843, -29577, -29332, -29062, -28820, -28548, -28308, -28034, -27795, -27521, -27283, -27011, -26771, -26502,
 -26260, -25996, -25748, -25490, -25227, -24979, -24702, -24466, -24177, -23955, -23648, -23443, -23120, -22931, -22594, -22418, -22069, -21907,
 -21552, -21395, -21040, -20883, -20538, -20371, -20048, -19858, -19573, -19346, -19091, -18770, -18578, -18157, -18067, -17491, -17555, -16707,
 -17042, -15500, -16531, 110};
 
const int16_t wave76[257] = {
114, 16108, 15140, 16640, 16338, 17173, 17132, 17705, 17813, 18237, 18442, 18770, 19036, 19274, 19569, 19772, 20101, 20282, 20633, 20805, 21166,
 21338, 21699, 21877, 22231, 22420, 22764, 22967, 23296, 23515, 23829, 24063, 24362, 24608, 24895, 25152, 25427, 25692, 25954, 26224, 26481, 26757,
 27009, 27289, 27541, 27822, 28073, 28354, 28608, 28887, 29142, 29420, 29678, 29953, 30212, 30486, 30746, 31020, 31279, 31553, 31811, 32088, 32337,
 32637, 32672, 32376, 32127, 31850, 31592, 31320, 31058, 30789, 30523, 30257, 29986, 29725, 29449, 29194, 28915, 28662, 28379, 28129, 27845, 27596,
 27312, 27063, 26781, 26531, 26252, 25999, 25725, 25466, 25198, 24926, 24666, 24382, 24134, 23835, 23602, 23286, 23069, 22739, 22537, 22193, 22004,
 21648, 21472, 21110, 20940, 20577, 20406, 20055, 19874, 19545, 19342, 19047, 18809, 18543, 18214, 18010, 17586, 17477, 16906, 16945, 16112, 16413,
 14913, 15881, -114, -16107, -15140, -16641, -16339, -17174, -17133, -17705, -17812, -18238, -18442, -18771, -19037, -19274, -19570, -19771, -20102,
 -20283, -20634, -20805, -21167, -21338, -21699, -21875, -22232, -22421, -22763, -22967, -23297, -23514, -23830, -24062, -24362, -24608, -24895,
 -25152, -25428, -25692, -25953, -26225, -26479, -26757, -27010, -27290, -27541, -27822, -28073, -28354, -28608, -28888, -29142, -29420, -29677,
 -29954, -30212, -30487, -30746, -31020, -31280, -31554, -31810, -32088, -32337, -32636, -32673, -32376, -32127, -31849, -31592, -31320, -31057,
 -30789, -30522, -30257, -29985, -29726, -29450, -29194, -28915, -28662, -28380, -28129, -27845, -27596, -27312, -27063, -26782, -26531, -26252,
 -25999, -25725, -25467, -25199, -24926, -24667, -24381, -24133, -23836, -23602, -23287, -23069, -22739, -22538, -22193, -22004, -21648, -21472,
 -21111, -20940, -20578, -20407, -20055, -19875, -19545, -19342, -19047, -18809, -18543, -18215, -18010, -17585, -17478, -16905, -16946, -16112,
 -16413, -14912, -15882, 114};
 
const int16_t wave77[257] = {
118, 15467, 14561, 16019, 15752, 16573, 16555, 17126, 17251, 17678, 17896, 18232, 18508, 18758, 19062, 19277, 19614, 19808, 20167, 20353, 20720,
 20906, 21273, 21465, 21826, 22028, 22380, 22595, 22932, 23163, 23485, 23731, 24038, 24295, 24592, 24860, 25145, 25420, 25692, 25973, 26240, 26526,
 26789, 27079, 27341, 27632, 27894, 28184, 28449, 28738, 29004, 29291, 29560, 29845, 30114, 30399, 30669, 30953, 31222, 31507, 31774, 32062, 32320,
 32632, 32669, 32361, 32102, 31815, 31547, 31265, 30992, 30713, 30437, 30160, 29880, 29608, 29322, 29056, 28767, 28504, 28212, 27950, 27657, 27397,
 27104, 26844, 26552, 26291, 26002, 25738, 25454, 25185, 24907, 24625, 24355, 24061, 23802, 23494, 23250, 22925, 22696, 22359, 22144, 21793, 21590,
 21228, 21037, 20670, 20485, 20116, 19931, 19573, 19378, 19041, 18825, 18522, 18272, 17996, 17660, 17442, 17015, 16889, 16321, 16337, 15517, 15784,
 14325, 15232, -118, -15466, -14561, -16020, -15753, -16574, -16556, -17126, -17250, -17679, -17896, -18232, -18509, -18757, -19062, -19277, -19615,
 -19809, -20167, -20353, -20721, -20906, -21274, -21463, -21827, -22029, -22378, -22595, -22932, -23162, -23486, -23730, -24039, -24295, -24592,
 -24860, -25145, -25420, -25691, -25974, -26238, -26526, -26789, -27080, -27341, -27632, -27894, -28184, -28449, -28739, -29004, -29291, -29559,
 -29846, -30114, -30399, -30669, -30953, -31223, -31507, -31773, -32062, -32321, -32631, -32669, -32361, -32103, -31814, -31547, -31265, -30992,
 -30713, -30436, -30160, -29879, -29609, -29323, -29057, -28767, -28504, -28212, -27951, -27657, -27397, -27104, -26844, -26553, -26291, -26003,
 -25739, -25455, -25186, -24908, -24625, -24355, -24060, -23801, -23495, -23250, -22926, -22696, -22359, -22144, -21793, -21590, -21228, -21038,
 -20670, -20485, -20117, -19932, -19573, -19379, -19041, -18825, -18522, -18272, -17996, -17661, -17442, -17014, -16890, -16320, -16337, -15517,
 -15784, -14324, -15232, 118};
 
const int16_t wave78[257] = {
123, 14826, 13982, 15399, 15165, 15973, 15979, 16547, 16688, 17119, 17350, 17693, 17980, 18241, 18554, 18782, 19127, 19335, 19700, 19900, 20274,
 20474, 20847, 21054, 21421, 21637, 21995, 22223, 22568, 22811, 23142, 23399, 23715, 23983, 24289, 24568, 24863, 25148, 25431, 25721, 25999, 26295,
 26569, 26868, 27141, 27441, 27715, 28014, 28290, 28589, 28865, 29162, 29442, 29737, 30016, 30311, 30591, 30885, 31165, 31460, 31737, 32036, 32304,
 32627, 32665, 32346, 32078, 31780, 31501, 31209, 30926, 30637, 30351, 30064, 29773, 29491, 29195, 28919, 28620, 28346, 28044, 27772, 27469, 27198,
 26895, 26624, 26323, 26051, 25753, 25478, 25184, 24904, 24616, 24324, 24043, 23740, 23470, 23153, 22897, 22565, 22323, 21978, 21750, 21392, 21176,
 20807, 20603, 20229, 20030, 19655, 19455, 19091, 18882, 18538, 18309, 17996, 17735, 17449, 17105, 16875, 16444, 16301, 15735, 15728, 14922, 15155,
 13737, 14582, -123, -14826, -13982, -15400, -15166, -15974, -15979, -16547, -16687, -17120, -17350, -17694, -17981, -18240, -18555, -18782, -19128,
 -19336, -19700, -19900, -20275, -20474, -20848, -21052, -21421, -21637, -21994, -22223, -22568, -22810, -23142, -23398, -23716, -23983, -24290,
 -24568, -24863, -25148, -25430, -25722, -25997, -26295, -26569, -26869, -27141, -27442, -27715, -28015, -28290, -28589, -28865, -29163, -29441,
 -29737, -30016, -30311, -30591, -30886, -31166, -31461, -31737, -32036, -32304, -32626, -32666, -32346, -32078, -31779, -31502, -31209, -30926,
 -30637, -30350, -30064, -29772, -29492, -29196, -28919, -28620, -28346, -28045, -27772, -27469, -27198, -26895, -26624, -26324, -26051, -25753,
 -25478, -25184, -24905, -24617, -24324, -24044, -23739, -23469, -23154, -22897, -22566, -22323, -21978, -21751, -21392, -21176, -20807, -20603,
 -20229, -20030, -19656, -19456, -19091, -18883, -18538, -18309, -17996, -17735, -17449, -17106, -16875, -16443, -16302, -15734, -15729, -14922,
 -15155, -13736, -14583, 123};
 
const int16_t wave79[257] = {
127, 14186, 13403, 14779, 14579, 15373, 15402, 15967, 16126, 16561, 16804, 17155, 17452, 17724, 18047, 18288, 18640, 18862, 19233, 19448, 19828,
 20042, 20422, 20642, 21016, 21245, 21610, 21851, 22203, 22459, 22798, 23066, 23392, 23671, 23986, 24275, 24580, 24876, 25169, 25469, 25758, 26064,
 26348, 26657, 26942, 27251, 27535, 27845, 28131, 28440, 28727, 29034, 29323, 29629, 29918, 30223, 30514, 30818, 31108, 31413, 31700, 32010, 32287,
 32622, 32661, 32331, 32053, 31744, 31456, 31153, 30861, 30561, 30265, 29967, 29667, 29374, 29068, 28781, 28473, 28188, 27876, 27593, 27281, 26999,
 26687, 26405, 26094, 25811, 25503, 25218, 24914, 24623, 24325, 24023, 23732, 23419, 23138, 22812, 22545, 22204, 21950, 21598, 21357, 20992, 20762,
 20387, 20168, 19788, 19575, 19194, 18980, 18609, 18386, 18034, 17793, 17471, 17199, 16902, 16550, 16307, 15873, 15713, 15150, 15120, 14327, 14526,
 13149, 13933, -127, -14185, -13403, -14780, -14580, -15374, -15402, -15967, -16125, -16562, -16804, -17156, -17453, -17724, -18047, -18287, -18640,
 -18863, -19234, -19448, -19829, -20042, -20422, -20640, -21016, -21246, -21609, -21851, -22204, -22458, -22798, -23066, -23392, -23671, -23987,
 -24275, -24581, -24876, -25168, -25470, -25756, -26064, -26349, -26658, -26942, -27252, -27535, -27845, -28131, -28440, -28727, -29034, -29322,
 -29629, -29918, -30224, -30514, -30819, -31108, -31414, -31700, -32010, -32288, -32621, -32662, -32331, -32053, -31743, -31457, -31153, -30860,
 -30561, -30264, -29967, -29666, -29375, -29069, -28782, -28473, -28188, -27877, -27594, -27281, -26999, -26687, -26405, -26095, -25811, -25503,
 -25218, -24914, -24624, -24326, -24023, -23732, -23418, -23137, -22813, -22545, -22205, -21950, -21598, -21357, -20992, -20762, -20387, -20169,
 -19789, -19575, -19195, -18981, -18609, -18387, -18034, -17792, -17471, -17198, -16902, -16551, -16307, -15872, -15714, -15149, -15120, -14327,
 -14526, -13149, -13933, 127};
 
const int16_t wave80[257] = {
131, 13545, 12824, 14159, 13993, 14774, 14825, 15388, 15563, 16002, 16258, 16617, 16924, 17207, 17539, 17793, 18153, 18388, 18767, 18995, 19382,
 19610, 19996, 20230, 20610, 20853, 21225, 21479, 21839, 22107, 22454, 22734, 23069, 23359, 23684, 23983, 24298, 24603, 24908, 25218, 25518, 25833,
 26128, 26447, 26742, 27061, 27356, 27675, 27972, 28290, 28588, 28905, 29205, 29520, 29820, 30135, 30436, 30751, 31051, 31367, 31664, 31984, 32271,
 32617, 32658, 32316, 32028, 31709, 31411, 31098, 30795, 30485, 30178, 29871, 29560, 29257, 28941, 28644, 28326, 28030, 27709, 27415, 27093, 26801,
 26478, 26186, 25865, 25571, 25253, 24957, 24643, 24342, 24034, 23722, 23420, 23098, 22806, 22471, 22192, 21843, 21577, 21217, 20963, 20591, 20348,
 19966, 19734, 19347, 19120, 18732, 18504, 18127, 17890, 17531, 17276, 16945, 16662, 16355, 15995, 15740, 15302, 15125, 14564, 14511, 13731, 13897,
 12561, 13283, -131, -13544, -12824, -14160, -13994, -14775, -14826, -15388, -15562, -16003, -16258, -16617, -16925, -17207, -17539, -17792, -18153,
 -18389, -18767, -18995, -19383, -19610, -19996, -20228, -20611, -20854, -21224, -21479, -21840, -22106, -22455, -22734, -23069, -23359, -23684,
 -23983, -24298, -24604, -24907, -25219, -25516, -25833, -26129, -26448, -26742, -27061, -27356, -27675, -27972, -28291, -28588, -28905, -29204,
 -29521, -29820, -30136, -30436, -30751, -31051, -31367, -31663, -31984, -32271, -32616, -32658, -32317, -32029, -31708, -31411, -31098, -30794,
 -30485, -30177, -29871, -29559, -29258, -28942, -28644, -28326, -28030, -27709, -27415, -27093, -26800, -26478, -26186, -25866, -25571, -25254,
 -24958, -24644, -24343, -24034, -23722, -23421, -23097, -22805, -22472, -22192, -21844, -21577, -21217, -20964, -20591, -20348, -19966, -19734,
 -19348, -19120, -18733, -18505, -18127, -17891, -17531, -17276, -16945, -16661, -16355, -15996, -15740, -15301, -15126, -14563, -14512, -13731,
 -13897, -12561, -13284, 131};
 
const int16_t wave81[257] = {
136, 12904, 12245, 13538, 13406, 14174, 14248, 14809, 15001, 15443, 15712, 16078, 16396, 16691, 17031, 17298, 17666, 17915, 18300, 18543, 18935,
 19178, 19570, 19818, 20205, 20461, 20841, 21107, 21475, 21755, 22110, 22402, 22745, 23046, 23381, 23691, 24016, 24331, 24646, 24966, 25277, 25602,
 25908, 26236, 26542, 26871, 27177, 27505, 27813, 28141, 28450, 28776, 29087, 29412, 29723, 30048, 30359, 30684, 30994, 31320, 31627, 31958, 32254,
 32612, 32654, 32301, 32004, 31674, 31366, 31042, 30729, 30409, 30092, 29774, 29454, 29140, 28814, 28506, 28178, 27872, 27541, 27237, 26905, 26602,
 26270, 25966, 25636, 25331, 25004, 24697, 24373, 24062, 23743, 23421, 23109, 22777, 22474, 22130, 21840, 21482, 21204, 20836, 20570, 20191, 19934,
 19546, 19299, 18907, 18665, 18271, 18029, 17645, 17394, 17027, 16760, 16420, 16125, 15808, 15441, 15172, 14730, 14537, 13979, 13903, 13136, 13268,
 11974, 12634, -136, -12903, -12245, -13539, -13407, -14175, -14249, -14809, -15000, -15444, -15712, -16079, -16397, -16690, -17032, -17298, -17666,
 -17916, -18300, -18543, -18936, -19178, -19571, -19816, -20206, -20462, -20839, -21107, -21475, -21754, -22111, -22401, -22746, -23046, -23381,
 -23691, -24016, -24332, -24645, -24967, -25275, -25601, -25908, -26237, -26542, -26871, -27177, -27505, -27813, -28142, -28450, -28776, -29086,
 -29413, -29723, -30048, -30359, -30684, -30994, -31321, -31626, -31958, -32255, -32611, -32655, -32302, -32004, -31673, -31366, -31042, -30729,
 -30409, -30091, -29774, -29453, -29141, -28815, -28507, -28178, -27872, -27542, -27237, -26905, -26601, -26270, -25966, -25637, -25331, -25004,
 -24697, -24373, -24063, -23743, -23421, -23109, -22776, -22473, -22131, -21840, -21483, -21204, -20836, -20570, -20191, -19934, -19546, -19300,
 -18907, -18665, -18272, -18030, -17645, -17395, -17027, -16760, -16420, -16124, -15808, -15442, -15172, -14729, -14538, -13978, -13903, -13136,
 -13268, -11973, -12634, 136};
 
const int16_t wave82[257] = {
140, 12263, 11665, 12918, 12820, 13574, 13671, 14229, 14438, 14884, 15166, 15540, 15868, 16174, 16524, 16804, 17179, 17441, 17833, 18090, 18489,
 18746, 19145, 19407, 19800, 20070, 20456, 20735, 21111, 21403, 21767, 22070, 22422, 22734, 23078, 23398, 23733, 24059, 24384, 24715, 25036, 25371,
 25688, 26025, 26342, 26681, 26998, 27335, 27654, 27992, 28311, 28647, 28969, 29304, 29625, 29960, 30281, 30617, 30937, 31274, 31590, 31932, 32238,
 32607, 32651, 32286, 31979, 31639, 31321, 30987, 30664, 30333, 30006, 29678, 29347, 29023, 28688, 28369, 28031, 27714, 27373, 27058, 26717, 26403,
 26061, 25747, 25407, 25091, 24754, 24437, 24102, 23781, 23452, 23120, 22797, 22456, 22142, 21789, 21487, 21122, 20831, 20456, 20176, 19790, 19520,
 19125, 18865, 18466, 18210, 17810, 17554, 17163, 16898, 16524, 16243, 15895, 15588, 15261, 14886, 14604, 14159, 13949, 13393, 13294, 12541, 12639,
 11386, 11984, -140, -12263, -11665, -12919, -12821, -13575, -13672, -14229, -14437, -14885, -15166, -15540, -15869, -16174, -16524, -16803, -17179,
 -17442, -17834, -18090, -18490, -18746, -19145, -19405, -19800, -20070, -20455, -20735, -21111, -21402, -21767, -22069, -22422, -22734, -23078,
 -23398, -23734, -24060, -24383, -24716, -25034, -25370, -25688, -26026, -26342, -26681, -26998, -27336, -27654, -27992, -28311, -28648, -28968,
 -29304, -29625, -29960, -30281, -30617, -30937, -31274, -31589, -31932, -32238, -32606, -32651, -32287, -31980, -31638, -31321, -30987, -30663,
 -30333, -30005, -29678, -29346, -29024, -28689, -28369, -28031, -27715, -27374, -27059, -26717, -26403, -26061, -25747, -25408, -25091, -24755,
 -24437, -24103, -23782, -23452, -23120, -22797, -22455, -22141, -21790, -21487, -21123, -20831, -20456, -20177, -19790, -19520, -19125, -18865,
 -18467, -18211, -17811, -17555, -17163, -16899, -16524, -16243, -15895, -15587, -15261, -14887, -14604, -14158, -13950, -13392, -13295, -12541,
 -12639, -11385, -11985, 140};
 
const int16_t wave83[257] = {
145, 11623, 11086, 12298, 12233, 12974, 13095, 13650, 13876, 14325, 14620, 15002, 15340, 15657, 16016, 16309, 16691, 16968, 17367, 17638, 18043,
 18314, 18719, 18995, 19395, 19678, 20071, 20364, 20746, 21051, 21423, 21738, 22099, 22422, 22775, 23106, 23451, 23787, 24123, 24463, 24795, 25139,
 25467, 25815, 26143, 26490, 26818, 27166, 27496, 27843, 28173, 28519, 28851, 29196, 29527, 29872, 30204, 30549, 30879, 31227, 31553, 31906, 32221,
 32603, 32647, 32272, 31955, 31604, 31275, 30931, 30598, 30257, 29920, 29581, 29241, 28906, 28561, 28231, 27884, 27556, 27206, 26880, 26529, 26204,
 25853, 25527, 25178, 24852, 24504, 24176, 23832, 23500, 23161, 22819, 22486, 22135, 21810, 21448, 21135, 20761, 20458, 20075, 19783, 19390, 19106,
 18705, 18430, 18025, 17755, 17349, 17078, 16681, 16402, 16020, 15727, 15369, 15051, 14714, 14331, 14037, 13588, 13361, 12808, 12686, 11946, 12010,
 10798, 11335, -145, -11622, -11086, -12299, -12234, -12975, -13095, -13650, -13875, -14326, -14620, -15002, -15341, -15657, -16017, -16308, -16692,
 -16969, -17367, -17638, -18044, -18314, -18719, -18993, -19395, -19679, -20070, -20364, -20747, -21050, -21423, -21737, -22099, -22422, -22776,
 -23106, -23451, -23787, -24122, -24464, -24793, -25139, -25468, -25816, -26143, -26491, -26818, -27166, -27496, -27843, -28173, -28519, -28850,
 -29196, -29527, -29873, -30204, -30550, -30880, -31227, -31553, -31906, -32222, -32602, -32647, -32272, -31955, -31603, -31276, -30931, -30597,
 -30257, -29919, -29581, -29240, -28907, -28562, -28232, -27884, -27557, -27206, -26880, -26529, -26204, -25853, -25527, -25179, -24852, -24505,
 -24177, -23832, -23501, -23161, -22819, -22486, -22134, -21809, -21449, -21135, -20762, -20458, -20075, -19783, -19390, -19106, -18705, -18431,
 -18026, -17756, -17350, -17079, -16681, -16403, -16020, -15727, -15369, -15051, -14714, -14332, -14037, -13587, -13362, -12807, -12686, -11946,
 -12010, -10797, -11335, 145};
 
const int16_t wave84[257] = {
149, 10982, 10507, 11677, 11647, 12374, 12518, 13071, 13313, 13766, 14074, 14463, 14812, 15141, 15509, 15814, 16204, 16495, 16900, 17185, 17597,
 17882, 18293, 18583, 18990, 19286, 19687, 19992, 20382, 20699, 21079, 21406, 21775, 22109, 22472, 22814, 23169, 23515, 23861, 24211, 24554, 24908,
 25247, 25604, 25943, 26300, 26639, 26996, 27337, 27694, 28034, 28390, 28733, 29088, 29429, 29785, 30126, 30482, 30822, 31180, 31516, 31880, 32205,
 32598, 32643, 32257, 31930, 31569, 31230, 30875, 30532, 30181, 29834, 29485, 29134, 28789, 28434, 28094, 27736, 27398, 27038, 26701, 26341, 26005,
 25644, 25308, 24949, 24612, 24255, 23916, 23562, 23219, 22870, 22518, 22174, 21814, 21478, 21107, 20782, 20400, 20085, 19695, 19389, 18989, 18692,
 18284, 17996, 17585, 17300, 16888, 16603, 16199, 15906, 15517, 15211, 14844, 14514, 14167, 13777, 13469, 13017, 12773, 12222, 12077, 11351, 11381,
 10210, 10685, -149, -10981, -10507, -11678, -11648, -12375, -12518, -13071, -13312, -13767, -14074, -14464, -14813, -15140, -15509, -15814, -16205,
 -16496, -16900, -17185, -17598, -17882, -18294, -18581, -18990, -19287, -19685, -19992, -20382, -20698, -21079, -21405, -21776, -22109, -22473,
 -22814, -23169, -23515, -23860, -24212, -24552, -24908, -25247, -25605, -25943, -26301, -26639, -26996, -27337, -27694, -28034, -28390, -28732,
 -29088, -29429, -29785, -30126, -30483, -30823, -31181, -31516, -31880, -32205, -32597, -32644, -32257, -31930, -31568, -31231, -30875, -30532,
 -30181, -29833, -29485, -29133, -28790, -28435, -28094, -27736, -27399, -27039, -26702, -26341, -26005, -25644, -25308, -24950, -24612, -24255,
 -23916, -23562, -23220, -22870, -22518, -22174, -21813, -21477, -21108, -20782, -20401, -20085, -19695, -19390, -18989, -18692, -18284, -17996,
 -17585, -17301, -16889, -16604, -16199, -15907, -15517, -15210, -14844, -14514, -14167, -13778, -13469, -13016, -12774, -12221, -12078, -11351,
 -11381, -10209, -10686, 149};
 
const int16_t wave85[257] = {
153, 10341, 9928, 11057, 11061, 11775, 11941, 12492, 12751, 13208, 13528, 13925, 14284, 14624, 15001, 15320, 15717, 16021, 16433, 16733, 17151,
 17450, 17868, 18171, 18584, 18894, 19302, 19620, 20018, 20347, 20735, 21073, 21452, 21797, 22170, 22522, 22887, 23243, 23600, 23960, 24313, 24677,
 25027, 25393, 25743, 26110, 26460, 26826, 27178, 27544, 27896, 28261, 28614, 28979, 29331, 29697, 30049, 30415, 30765, 31134, 31480, 31854, 32188,
 32593, 32640, 32242, 31905, 31533, 31185, 30820, 30467, 30105, 29748, 29388, 29028, 28672, 28307, 27957, 27589, 27241, 26870, 26523, 26153, 25806,
 25436, 25089, 24720, 24372, 24005, 23656, 23291, 22938, 22579, 22217, 21862, 21493, 21146, 20767, 20430, 20039, 19712, 19314, 18996, 18589, 18278,
 17864, 17562, 17144, 16846, 16426, 16127, 15717, 15411, 15014, 14694, 14318, 13978, 13620, 13222, 12902, 12446, 12185, 11637, 11469, 10756, 10752,
 9622, 10036, -153, -10340, -9928, -11058, -11062, -11776, -11942, -12492, -12750, -13209, -13528, -13925, -14285, -14624, -15001, -15319, -15717,
 -16022, -16434, -16733, -17152, -17450, -17868, -18169, -18585, -18895, -19300, -19620, -20018, -20346, -20736, -21073, -21453, -21797, -22170, 
 -22522, -22887, -23243, -23599, -23961, -24311, -24677, -25027, -25394, -25743, -26110, -26460, -26826, -27178, -27545, -27896, -28261, -28613,
 -28980, -29331, -29697, -30049, -30415, -30765, -31134, -31479, -31854, -32188, -32592, -32640, -32242, -31906, -31532, -31185, -30820, -30466,
 -30105, -29747, -29388, -29027, -28673, -28308, -27957, -27589, -27241, -26871, -26523, -26153, -25806, -25436, -25089, -24721, -24372, -24006,
 -23656, -23292, -22939, -22579, -22217, -21863, -21492, -21145, -20768, -20430, -20040, -19712, -19314, -18996, -18589, -18278, -17864, -17562,
 -17145, -16846, -16427, -16128, -15717, -15412, -15014, -14694, -14318, -13977, -13620, -13223, -12902, -12445, -12186, -11636, -11469, -10756,
 -10752, -9622, -10036, 153};
 
const int16_t wave86[257] = {
158, 9700, 9349, 10437, 10474, 11175, 11364, 11912, 12188, 12649, 12982, 13387, 13755, 14107, 14493, 14825, 15230, 15548, 15967, 16280, 16705,
 17018, 17442, 17760, 18179, 18503, 18917, 19248, 19654, 19995, 20392, 20741, 21129, 21485, 21867, 22229, 22604, 22971, 23338, 23708, 24072, 24446,
 24807, 25183, 25543, 25920, 26281, 26656, 27019, 27395, 27757, 28132, 28496, 28871, 29233, 29609, 29971, 30348, 30708, 31087, 31443, 31828, 32172,
 32588, 32636, 32227, 31881, 31498, 31140, 30764, 30401, 30029, 29662, 29292, 28921, 28555, 28180, 27819, 27442, 27083, 26703, 26345, 25965, 25607,
 25227, 24869, 24491, 24132, 23755, 23395, 23021, 22657, 22287, 21916, 21551, 21172, 20814, 20426, 20077, 19679, 19339, 18933, 18602, 18188, 17864,
 17443, 17127, 16703, 16391, 15965, 15652, 15234, 14915, 14510, 14178, 13793, 13441, 13073, 12667, 12334, 11875, 11597, 11051, 10860, 10161, 10123,
 9034, 9386, -158, -9700, -9349, -10438, -10475, -11176, -11365, -11912, -12187, -12650, -12982, -13387, -13756, -14107, -14494, -14824, -15230,
 -15549, -15967, -16280, -16706, -17018, -17442, -17758, -18179, -18503, -18916, -19248, -19654, -19994, -20392, -20741, -21129, -21485, -21867,
 -22229, -22604, -22971, -23337, -23709, -24070, -24446, -24807, -25184, -25543, -25920, -26281, -26657, -27019, -27395, -27757, -28133, -28495,
 -28871, -29233, -29609, -29971, -30348, -30708, -31087, -31442, -31828, -32172, -32587, -32636, -32227, -31881, -31497, -31140, -30764, -30400,
 -30028, -29661, -29292, -28920, -28556, -28181, -27819, -27442, -27083, -26703, -26345, -25965, -25607, -25227, -24869, -24492, -24132, -23756,
 -23396, -23021, -22658, -22288, -21916, -21551, -21171, -20813, -20427, -20077, -19680, -19339, -18933, -18603, -18188, -17864, -17443, -17127,
 -16704, -16391, -15966, -15653, -15234, -14916, -14510, -14178, -13793, -13440, -13072, -12668, -12334, -11874, -11598, -11050, -10861, -10161,
 -10123, -9034, -9387, 158};
 
const int16_t wave87[257] = {
162, 9060, 8770, 9817, 9888, 10575, 10787, 11333, 11626, 12090, 12436, 12848, 13227, 13590, 13986, 14330, 14743, 15075, 15500, 15828, 16258, 16586,
 17016, 17348, 17774, 18111, 18532, 18876, 19289, 19643, 20048, 20409, 20806, 21173, 21564, 21937, 22322, 22699, 23077, 23456, 23831, 24215, 24586,
 24972, 25344, 25730, 26101, 26487, 26860, 27246, 27619, 28004, 28378, 28763, 29136, 29521, 29894, 30281, 30651, 31040, 31406, 31802, 32155, 32583,
 32632, 32212, 31856, 31463, 31095, 30708, 30335, 29953, 29576, 29195, 28815, 28438, 28053, 27682, 27295, 26925, 26535, 26166, 25777, 25408, 25019,
 24650, 24262, 23892, 23506, 23135, 22751, 22377, 21996, 21615, 21239, 20851, 20482, 20085, 19725, 19318, 18966, 18553, 18209, 17788, 17450, 17023,
 16693, 16262, 15936, 15504, 15176, 14752, 14419, 14007, 13662, 13267, 12904, 12526, 12112, 11767, 11303, 11009, 10466, 10252, 9566, 9494, 8447,
 8737, -162, -9059, -8770, -9818, -9889, -10576, -10788, -11333, -11625, -12091, -12436, -12849, -13228, -13590, -13986, -14329, -14743, -15076,
 -15500, -15828, -16259, -16586, -17016, -17346, -17774, -18112, -18531, -18876, -19290, -19642, -20048, -20408, -20806, -21173, -21564, -21937,
 -22322, -22699, -23076, -23457, -23829, -24214, -24587, -24973, -25344, -25730, -26101, -26487, -26860, -27246, -27619, -28004, -28377, -28763,
 -29136, -29522, -29894, -30281, -30651, -31041, -31405, -31802, -32155, -32582, -32633, -32212, -31856, -31462, -31095, -30708, -30334, -29952,
 -29575, -29195, -28814, -28439, -28054, -27682, -27295, -26925, -26536, -26166, -25777, -25408, -25019, -24650, -24263, -23892, -23506, -23135,
 -22751, -22378, -21997, -21615, -21240, -20850, -20481, -20086, -19725, -19319, -18966, -18553, -18209, -17788, -17450, -17023, -16693, -16263,
 -15936, -15505, -15177, -14752, -14420, -14007, -13661, -13267, -12903, -12525, -12113, -11767, -11302, -11010, -10465, -10252, -9566, -9494,
 -8446, -8737, 162};
 
const int16_t wave88[257] = {
166, 8419, 8191, 9196, 9302, 9975, 10211, 10754, 11064, 11531, 11890, 12310, 12699, 13074, 13478, 13835, 14256, 14601, 15033, 15376, 15812, 16154,
 16590, 16936, 17369, 17719, 18148, 18504, 18925, 19291, 19704, 20077, 20482, 20860, 21261, 21645, 22040, 22426, 22815, 23205, 23591, 23984, 24366,
 24761, 25144, 25539, 25922, 26317, 26701, 27097, 27480, 27875, 28260, 28655, 29038, 29434, 29816, 30213, 30594, 30994, 31369, 31776, 32138, 32578,
 32629, 32197, 31831, 31428, 31049, 30653, 30269, 29877, 29489, 29098, 28708, 28321, 27926, 27544, 27147, 26767, 26367, 25988, 25589, 25210, 24810,
 24431, 24032, 23652, 23256, 22875, 22480, 22096, 21705, 21314, 20928, 20530, 20149, 19744, 19372, 18957, 18593, 18172, 17816, 17387, 17037, 16602,
 16258, 15822, 15481, 15043, 14701, 14270, 13923, 13503, 13145, 12742, 12367, 11979, 11558, 11199, 10732, 10421, 9880, 9643, 8970, 8865, 7859, 8088,
 -166, -8418, -8191, -9197, -9303, -9976, -10211, -10754, -11063, -11532, -11890, -12310, -12700, -13073, -13478, -13835, -14256, -14602, -15033,
 -15376, -15813, -16155, -16591, -16934, -17369, -17720, -18146, -18504, -18925, -19290, -19704, -20076, -20483, -20860, -21262, -21645, -22040,
 -22427, -22814, -23206, -23589, -23983, -24366, -24762, -25144, -25540, -25922, -26317, -26701, -27097, -27480, -27875, -28259, -28655, -29038,
 -29434, -29816, -30214, -30594, -30994, -31369, -31776, -32139, -32577, -32629, -32198, -31832, -31427, -31050, -30653, -30269, -29876, -29488,
 -29098, -28707, -28322, -27927, -27545, -27147, -26767, -26368, -25988, -25589, -25209, -24810, -24431, -24033, -23652, -23257, -22875, -22481,
 -22097, -21705, -21314, -20928, -20529, -20149, -19745, -19372, -18958, -18593, -18172, -17816, -17387, -17037, -16602, -16259, -15822, -15481,
 -15044, -14702, -14270, -13924, -13503, -13145, -12742, -12366, -11978, -11559, -11199, -10731, -10422, -9879, -9643, -8970, -8865, -7858, -8088, 166};
 
const int16_t wave89[257] = {
171, 7778, 7612, 8576, 8715, 9376, 9634, 10174, 10501, 10972, 11344, 11772, 12171, 12557, 12971, 13341, 13769, 14128, 14566, 14923, 15366, 15722,
 16165, 16524, 16963, 17327, 17763, 18132, 18561, 18939, 19360, 19745, 20159, 20548, 20959, 21352, 21757, 22154, 22553, 22953, 23350, 23753, 24146,
 24550, 24944, 25349, 25743, 26147, 26542, 26947, 27342, 27746, 28142, 28546, 28940, 29346, 29739, 30146, 30537, 30947, 31333, 31750, 32122, 32573,
 32625, 32182, 31807, 31393, 31004, 30597, 30204, 29801, 29403, 29002, 28602, 28204, 27799, 27407, 27000, 26609, 26199, 25809, 25401, 25011, 24602,
 24211, 23803, 23412, 23006, 22615, 22210, 21815, 21414, 21013, 20616, 20209, 19817, 19403, 19020, 18596, 18220, 17792, 17422, 16987, 16623, 16182,
 15824, 15381, 15026, 14581, 14226, 13788, 13427, 13000, 12629, 12217, 11830, 11432, 11003, 10631, 10161, 9833, 9295, 9035, 8375, 8236, 7271, 7438,
 -171, -7777, -7612, -8577, -8716, -9377, -9635, -10174, -10500, -10973, -11344, -11772, -12172, -12557, -12971, -13340, -13769, -14129, -14567,
 -14923, -15367, -15723, -16165, -16522, -16964, -17328, -17761, -18132, -18561, -18938, -19361, -19744, -20159, -20548, -20959, -21352, -21758,
 -22155, -22552, -22954, -23348, -23752, -24146, -24551, -24944, -25349, -25743, -26147, -26542, -26948, -27342, -27746, -28141, -28547, -28940,
 -29346, -29739, -30146, -30537, -30947, -31332, -31750, -32122, -32572, -32625, -32183, -31807, -31392, -31004, -30597, -30203, -29800, -29402,
 -29002, -28601, -28205, -27800, -27407, -27000, -26609, -26200, -25810, -25401, -25010, -24602, -24211, -23804, -23412, -23007, -22615, -22210,
 -21816, -21414, -21013, -20616, -20208, -19817, -19404, -19020, -18597, -18220, -17792, -17422, -16987, -16623, -16182, -15824, -15382, -15026,
 -14582, -14227, -13788, -13428, -13000, -12628, -12217, -11829, -11431, -11004, -10631, -10160, -9834, -9294, -9035, -8375, -8236, -7270, -7438, 171};
 
const int16_t wave90[257] = {
175, 7137, 7033, 7956, 8129, 8776, 9057, 9595, 9939, 10413, 10798, 11233, 11643, 12040, 12463, 12846, 13281, 13655, 14100, 14471, 14920, 15290, 15739,
 16113, 16558, 16936, 17378, 17761, 18197, 18587, 19017, 19413, 19836, 20236, 20656, 21060, 21475, 21882, 22292, 22701, 23109, 23521, 23926, 24340,
 24744, 25159, 25564, 25977, 26384, 26798, 27203, 27617, 28024, 28438, 28842, 29258, 29661, 30079, 30479, 30900, 31296, 31724, 32105, 32569, 32621,
 32168, 31782, 31358, 30959, 30541, 30138, 29725, 29317, 28905, 28495, 28087, 27672, 27269, 26853, 26451, 26032, 25631, 25213, 24812, 24393, 23992,
 23574, 23173, 22757, 22354, 21940, 21534, 21123, 20712, 20305, 19888, 19485, 19062, 18667, 18236, 17847, 17411, 17029, 16586, 16209, 15761, 15389,
 14940, 14571, 14120, 13750, 13306, 12931, 12496, 12113, 11691, 11293, 10885, 10448, 10064, 9590, 9245, 8709, 8426, 7780, 7607, 6683, 6789, -175,
 -7137, -7033, -7957, -8130, -8777, -9058, -9595, -9938, -10414, -10798, -11234, -11644, -12040, -12463, -12845, -13282, -13656, -14100, -14471,
 -14921, -15291, -15739, -16111, -16558, -16936, -17377, -17761, -18197, -18586, -19017, -19412, -19836, -20236, -20656, -21060, -21475, -21882,
 -22291, -22702, -23107, -23521, -23926, -24341, -24744, -25159, -25564, -25978, -26384, -26798, -27203, -27618, -28023, -28438, -28842, -29258,
 -29661, -30079, -30480, -30901, -31295, -31724, -32106, -32568, -32622, -32168, -31782, -31357, -30959, -30541, -30137, -29724, -29316, -28905,
 -28494, -28088, -27673, -27270, -26853, -26451, -26033, -25631, -25213, -24811, -24393, -23992, -23575, -23173, -22757, -22354, -21940, -21535,
 -21123, -20712, -20305, -19887, -19485, -19063, -18667, -18237, -17847, -17411, -17029, -16586, -16209, -15761, -15390, -14941, -14571, -14121,
 -13751, -13306, -12932, -12496, -12112, -11691, -11293, -10884, -10449, -10064, -9589, -9246, -8708, -8426, -7780, -7607, -6682, -6789, 175};
 
const int16_t wave91[257] = {
180, 6497, 6454, 7336, 7542, 8176, 8480, 9016, 9376, 9855, 10252, 10695, 11115, 11523, 11955, 12351, 12794, 13181, 13633, 14018, 14474, 14858, 15313,
 15701, 16153, 16544, 16993, 17389, 17832, 18235, 18673, 19080, 19513, 19924, 20353, 20768, 21193, 21610, 22030, 22450, 22868, 23290, 23705, 24129,
 24545, 24969, 25384, 25808, 26225, 26649, 27065, 27489, 27905, 28330, 28744, 29170, 29584, 30012, 30422, 30854, 31259, 31698, 32089, 32564, 32618,
 32153, 31758, 31322, 30914, 30486, 30072, 29649, 29231, 28809, 28389, 27970, 27545, 27132, 26706, 26293, 25864, 25453, 25025, 24613, 24185, 23772,
 23345, 22933, 22507, 22094, 21669, 21253, 20832, 20411, 19993, 19567, 19153, 18721, 18315, 17875, 17474, 17030, 16635, 16186, 15795, 15341, 14955,
 14499, 14116, 13659, 13275, 12824, 12435, 11993, 11596, 11166, 10757, 10338, 9893, 9496, 9019, 8657, 8124, 7818, 7185, 6978, 6095, 6139, -180,
 -6496, -6454, -7337, -7543, -8177, -8481, -9016, -9375, -9856, -10252, -10695, -11116, -11523, -11956, -12350, -12794, -13182, -13633, -14018,
 -14475, -14859, -15313, -15699, -16153, -16545, -16992, -17389, -17833, -18234, -18673, -19080, -19513, -19924, -20353, -20768, -21193, -21610,
 -22029, -22451, -22866, -23290, -23706, -24130, -24545, -24969, -25384, -25808, -26225, -26649, -27065, -27489, -27904, -28330, -28744, -29171,
 -29584, -30012, -30422, -30854, -31258, -31698, -32089, -32563, -32618, -32153, -31758, -31321, -30914, -30486, -30071, -29648, -29230, -28809,
 -28388, -27971, -27546, -27132, -26706, -26293, -25865, -25453, -25025, -24612, -24185, -23772, -23346, -22933, -22508, -22094, -21669, -21254,
 -20832, -20411, -19993, -19566, -19153, -18722, -18315, -17876, -17474, -17030, -16635, -16186, -15795, -15341, -14955, -14500, -14116, -13660,
 -13276, -12824, -12436, -11993, -11596, -11166, -10756, -10337, -9894, -9496, -9018, -8658, -8123, -7818, -7185, -6978, -6095, -6139, 180};
 
const int16_t wave92[257] = {
184, 5856, 5875, 6715, 6956, 7576, 7903, 8436, 8814, 9296, 9706, 10157, 10587, 11007, 11448, 11857, 12307, 12708, 13166, 13566, 14027, 14426, 14888,
 15289, 15748, 16152, 16609, 17017, 17468, 17883, 18329, 18748, 19189, 19611, 20050, 20475, 20910, 21338, 21769, 22198, 22627, 23059, 23485, 23918,
 24345, 24779, 25205, 25638, 26066, 26500, 26926, 27360, 27787, 28222, 28647, 29083, 29506, 29945, 30365, 30807, 31222, 31672, 32072, 32559, 32614,
 32138, 31733, 31287, 30869, 30430, 30007, 29572, 29145, 28712, 28282, 27853, 27418, 26995, 26558, 26135, 25696, 25274, 24836, 24414, 23976, 23553,
 23116, 22693, 22257, 21834, 21399, 20973, 20541, 20110, 19681, 19246, 18821, 18380, 17962, 17514, 17101, 16650, 16242, 15785, 15381, 14920, 14521,
 14059, 13661, 13198, 12799, 12342, 11939, 11490, 11080, 10640, 10220, 9790, 9339, 8929, 8447, 8068, 7538, 7209, 6590, 6349, 5508, 5490, -184, -5855,
 -5875, -6716, -6957, -7577, -7904, -8436, -8813, -9297, -9706, -10157, -10588, -11007, -11448, -11856, -12307, -12709, -13167, -13566, -14028, -14427,
 -14888, -15287, -15748, -16153, -16607, -17017, -17468, -17882, -18329, -18747, -19189, -19611, -20050, -20475, -20911, -21338, -21768, -22199, -22625,
 -23058, -23485, -23919, -24345, -24779, -25205, -25638, -26066, -26500, -26926, -27360, -27786, -28222, -28647, -29083, -29506, -29945, -30365, -30807,
 -31221, -31672, -32072, -32558, -32614, -32138, -31733, -31286, -30869, -30430, -30006, -29572, -29144, -28712, -28281, -27854, -27419, -26995, -26558,
 -26135, -25697, -25274, -24836, -24413, -23976, -23553, -23117, -22693, -22258, -21834, -21399, -20974, -20541, -20110, -19682, -19245, -18820, -18381,
 -17962, -17515, -17101, -16650, -16242, -15785, -15381, -14920, -14521, -14060, -13661, -13199, -12800, -12342, -11940, -11490, -11079, -10640, -10219,
 -9790, -9340, -8929, -8446, -8069, -7537, -7209, -6590, -6349, -5507, -5490, 184};
 
const int16_t wave93[257] = {
188, 5215, 5296, 6095, 6370, 6976, 7327, 7857, 8251, 8737, 9160, 9618, 10059, 10490, 10940, 11362, 11820, 12235, 12700, 13113, 13581, 13994, 14462,
 14877, 15343, 15760, 16224, 16645, 17104, 17531, 17985, 18416, 18866, 19299, 19747, 20183, 20628, 21066, 21507, 21946, 22386, 22828, 23265, 23708,
 24145, 24588, 25026, 25468, 25907, 26351, 26788, 27231, 27669, 28114, 28549, 28995, 29429, 29877, 30308, 30760, 31185, 31646, 32056, 32554, 32610,
 32123, 31708, 31252, 30823, 30374, 29941, 29496, 29059, 28616, 28176, 27736, 27291, 26857, 26411, 25977, 25529, 25096, 24648, 24215, 23768, 23334,
 22887, 22453, 22008, 21573, 21129, 20692, 20250, 19809, 19370, 18925, 18489, 18039, 17610, 17153, 16728, 16269, 15848, 15385, 14967, 14500, 14086,
 13618, 13206, 12737, 12324, 11860, 11443, 10986, 10564, 10115, 9683, 9243, 8784, 8361, 7876, 7480, 6953, 6601, 5995, 5720, 4920, 4840, -188, -5214,
 -5296, -6096, -6371, -6977, -7327, -7857, -8250, -8738, -9160, -9619, -10060, -10490, -10940, -11361, -11820, -12236, -12700, -13113, -13582, -13995,
 -14462, -14875, -15343, -15761, -16222, -16645, -17104, -17530, -17985, -18415, -18866, -19299, -19748, -20183, -20628, -21066, -21506, -21947, -22384,
 -22827, -23265, -23709, -24145, -24589, -25026, -25468, -25907, -26351, -26788, -27231, -27668, -28114, -28549, -28995, -29429, -29878, -30308, -30761,
 -31185, -31646, -32056, -32553, -32611, -32123, -31708, -31251, -30824, -30374, -29940, -29496, -29058, -28616, -28175, -27737, -27292, -26857, -26411,
 -25977, -25530, -25096, -24648, -24214, -23768, -23334, -22888, -22453, -22008, -21573, -21129, -20693, -20250, -19809, -19370, -18924, -18488, -18040,
 -17610, -17154, -16728, -16269, -15848, -15385, -14967, -14500, -14086, -13619, -13206, -12738, -12325, -11860, -11444, -10986, -10563, -10115, -9682,
 -9243, -8785, -8361, -7875, -7481, -6952, -6601, -5995, -5720, -4919, -4840, 188};
 
const int16_t wave94[257] = {
193, 4574, 4716, 5475, 5783, 6377, 6750, 7278, 7689, 8178, 8614, 9080, 9531, 9973, 10433, 10867, 11333, 11761, 12233, 12661, 13135, 13562, 14036, 14466,
 14937, 15369, 15839, 16273, 16740, 17179, 17642, 18084, 18543, 18987, 19445, 19891, 20346, 20794, 21245, 21695, 22145, 22597, 23045, 23497, 23945, 24398,
 24847, 25298, 25748, 26201, 26649, 27102, 27551, 28005, 28451, 28907, 29351, 29810, 30251, 30714, 31149, 31620, 32039, 32549, 32607, 32108, 31684, 31217,
 30778, 30319, 29875, 29420, 28973, 28519, 28069, 27619, 27165, 26720, 26264, 25819, 25361, 24917, 24460, 24016, 23559, 23114, 22658, 22213, 21758, 21313,
 20858, 20411, 19959, 19508, 19058, 18604, 18157, 17698, 17257, 16793, 16355, 15889, 15455, 14984, 14553, 14079, 13652, 13177, 12751, 12275, 11849, 11378,
 10947, 10483, 10047, 9590, 9146, 8696, 8229, 7793, 7305, 6892, 6367, 5992, 5400, 5091, 4332, 4191, -193, -4574, -4716, -5476, -5784, -6378, -6751, -7278,
 -7688, -8179, -8614, -9080, -9532, -9973, -10433, -10866, -11333, -11762, -12233, -12661, -13136, -13563, -14036, -14464, -14937, -15369, -15838, -16273,
 -16740, -17178, -17642, -18083, -18543, -18987, -19445, -19891, -20346, -20794, -21244, -21696, -22143, -22596, -23045, -23498, -23945, -24398, -24847,
 -25299, -25748, -26201, -26649, -27103, -27550, -28005, -28451, -28907, -29351, -29810, -30251, -30714, -31148, -31620, -32039, -32548, -32607, -32108,
 -31684, -31216, -30778, -30319, -29874, -29420, -28972, -28519, -28068, -27620, -27166, -26720, -26264, -25820, -25362, -24918, -24460, -24016, -23559,
 -23114, -22659, -22213, -21759, -21313, -20858, -20412, -19959, -19508, -19058, -18603, -18156, -17699, -17257, -16794, -16355, -15889, -15455, -14984,
 -14553, -14079, -13652, -13178, -12752, -12276, -11850, -11378, -10948, -10483, -10046, -9590, -9145, -8696, -8230, -7793, -7304, -6893, -6366, -5992,
 -5400, -5091, -4331, -4191, 193};
 
const int16_t wave95[257] = {
197, 3934, 4137, 4854, 5197, 5777, 6173, 6699, 7126, 7619, 8068, 8542, 9003, 9457, 9925, 10373, 10846, 11288, 11766, 12208, 12689, 13130, 13611, 14054,
 14532, 14977, 15455, 15901, 16375, 16827, 17298, 17752, 18219, 18674, 19142, 19599, 20064, 20522, 20984, 21443, 21904, 22366, 22824, 23286, 23746, 24208,
 24667, 25129, 25589, 26052, 26511, 26974, 27433, 27897, 28353, 28820, 29274, 29743, 30194, 30667, 31112, 31594, 32023, 32544, 32603, 32093, 31659, 31182,
 30733, 30263, 29810, 29344, 28887, 28423, 27963, 27502, 27038, 26582, 26116, 25662, 25193, 24739, 24272, 23817, 23351, 22895, 22429, 21973, 21508, 21053,
 20588, 20130, 19668, 19207, 18747, 18283, 17825, 17358, 16905, 16432, 15982, 15508, 15061, 14584, 14139, 13659, 13217, 12737, 12297, 11814, 11373, 10896,
 10452, 9979, 9531, 9064, 8609, 8149, 7675, 7226, 6734, 6304, 5782, 5384, 4805, 4462, 3744, 3541, -197, -3933, -4137, -4855, -5198, -5778, -6174, -6699,
 -7125, -7620, -8068, -8542, -9004, -9457, -9925, -10372, -10846, -11289, -11767, -12208, -12690, -13131, -13611, -14052, -14532, -14978, -15453, -15901,
 -16375, -16826, -17298, -17751, -18220, -18674, -19142, -19599, -20064, -20522, -20983, -21444, -21902, -22365, -22824, -23287, -23746, -24208, -24667,
 -25129, -25589, -26052, -26511, -26974, -27432, -27897, -28353, -28820, -29274, -29743, -30194, -30667, -31111, -31594, -32023, -32543, -32603, -32093,
 -31659, -31181, -30733, -30263, -29809, -29344, -28886, -28423, -27962, -27503, -27039, -26582, -26116, -25662, -25194, -24739, -24272, -23817, -23351,
 -22895, -22430, -21973, -21509, -21053, -20588, -20131, -19668, -19207, -18747, -18282, -17824, -17359, -16905, -16433, -15982, -15508, -15061, -14584,
 -14139, -13659, -13217, -12738, -12297, -11815, -11374, -10896, -10453, -9979, -9530, -9064, -8608, -8149, -7676, -7226, -6733, -6305, -5781, -5384,
 -4805, -4462, -3743, -3541, 197};
 
const int16_t wave96[257] = {
201, 3293, 3558, 4234, 4611, 5177, 5596, 6119, 6564, 7060, 7522, 8003, 8474, 8940, 9417, 9878, 10359, 10814, 11300, 11756, 12243, 12698, 13185, 13642,
 14127, 14585, 15070, 15529, 16011, 16475, 16954, 17420, 17896, 18362, 18839, 19306, 19781, 20249, 20722, 21192, 21664, 22135, 22604, 23076, 23546, 24018,
 24488, 24959, 25430, 25903, 26372, 26845, 27315, 27789, 28255, 28732, 29196, 29676, 30137, 30621, 31075, 31568, 32006, 32539, 32600, 32078, 31634, 31147,
 30688, 30208, 29744, 29268, 28800, 28326, 27856, 27385, 26911, 26445, 25969, 25504, 25026, 24561, 24084, 23619, 23142, 22676, 22200, 21733, 21259, 20792,
 20317, 19849, 19376, 18906, 18435, 17962, 17493, 17017, 16552, 16071, 15609, 15127, 14668, 14183, 13725, 13238, 12783, 12296, 11842, 11353, 10898, 10413,
 9956, 9476, 9014, 8539, 8072, 7602, 7120, 6658, 6163, 5716, 5196, 4775, 4209, 3833, 3156, 2892, -201, -3292, -3558, -4235, -4612, -5178, -5597, -6119,
 -6563, -7061, -7522, -8003, -8475, -8940, -9417, -9877, -10359, -10815, -11300, -11756, -12244, -12699, -13185, -13640, -14127, -14586, -15068, -15529,
 -16011, -16474, -16954, -17419, -17896, -18362, -18839, -19306, -19781, -20250, -20721, -21193, -21662, -22134, -22604, -23077, -23546, -24018, -24488,
 -24959, -25430, -25903, -26372, -26845, -27314, -27789, -28255, -28732, -29196, -29676, -30137, -30621, -31074, -31568, -32006, -32538, -32600, -32079,
 -31635, -31146, -30688, -30208, -29743, -29267, -28799, -28326, -27855, -27386, -26912, -26445, -25969, -25504, -25027, -24561, -24084, -23618, -23142,
 -22676, -22201, -21733, -21260, -20792, -20318, -19850, -19376, -18906, -18435, -17961, -17492, -17018, -16552, -16072, -15609, -15127, -14668, -14183,
 -13725, -13238, -12783, -12297, -11842, -11354, -10899, -10413, -9957, -9476, -9014, -8539, -8071, -7601, -7121, -6658, -6162, -5717, -5195, -4775,
 -4209, -3833, -3155, -2892, 201};
 
const int16_t wave97[257] = {
206, 2652, 2979, 3614, 4024, 4577, 5019, 5540, 6001, 6502, 6976, 7465, 7946, 8423, 8910, 9383, 9871, 10341, 10833, 11303, 11797, 12266, 12759, 13230,
 13722, 14193, 14685, 15158, 15647, 16123, 16610, 17087, 17573, 18050, 18536, 19014, 19499, 19977, 20461, 20940, 21423, 21903, 22384, 22865, 23346, 23828,
 24309, 24789, 25272, 25754, 26234, 26716, 27196, 27681, 28157, 28644, 29119, 29609, 30079, 30574, 31038, 31542, 31990, 32535, 32596, 32064, 31610, 31111,
 30643, 30152, 29678, 29192, 28714, 28230, 27750, 27268, 26784, 26307, 25822, 25346, 24858, 24382, 23896, 23420, 22934, 22456, 21971, 21494, 21009, 20532,
 20047, 19568, 19085, 18605, 18124, 17641, 17161, 16676, 16200, 15710, 15236, 14747, 14274, 13783, 13311, 12818, 12348, 11855, 11387, 10892, 10422, 9931,
 9460, 8972, 8498, 8013, 7536, 7055, 6565, 6091, 5592, 5128, 4611, 4167, 3614, 3204, 2568, 2242, -206, -2651, -2979, -3615, -4025, -4578, -5020, -5540,
 -6000, -6503, -6976, -7465, -7947, -8423, -8910, -9382, -9871, -10342, -10833, -11303, -11798, -12267, -12759, -13228, -13722, -14194, -14683, -15158,
 -15647, -16122, -16610, -17087, -17573, -18050, -18536, -19014, -19499, -19977, -20460, -20941, -21421, -21903, -22384, -22866, -23346, -23828, -24309,
 -24789, -25272, -25754, -26234, -26716, -27195, -27681, -28157, -28644, -29119, -29609, -30079, -30574, -31037, -31542, -31990, -32534, -32596, -32064,
 -31610, -31110, -30643, -30152, -29677, -29191, -28713, -28230, -27749, -27269, -26785, -26307, -25822, -25346, -24859, -24382, -23896, -23419, -22934,
 -22456, -21972, -21494, -21010, -20532, -20047, -19569, -19085, -18605, -18124, -17640, -17160, -16677, -16200, -15711, -15236, -14747, -14274, -13783,
 -13311, -12818, -12348, -11856, -11387, -10893, -10423, -9931, -9461, -8972, -8497, -8013, -7535, -7054, -6566, -6091, -5591, -5129, -4610, -4167,
 -3614, -3204, -2568, -2242, 206};
 
const int16_t wave98[257] = {
210, 2011, 2400, 2994, 3438, 3978, 4443, 4961, 5439, 5943, 6430, 6927, 7418, 7906, 8402, 8888, 9384, 9868, 10366, 10851, 11350, 11834, 12333, 12819,
 13316, 13802, 14300, 14786, 15283, 15771, 16267, 16755, 17250, 17738, 18234, 18722, 19217, 19705, 20199, 20688, 21182, 21672, 22164, 22654, 23146, 23637,
 24130, 24619, 25113, 25604, 26095, 26587, 27078, 27572, 28060, 28556, 29041, 29541, 30022, 30527, 31002, 31516, 31973, 32530, 32592, 32049, 31585, 31076,
 30597, 30096, 29612, 29116, 28628, 28133, 27643, 27151, 26657, 26170, 25675, 25188, 24690, 24204, 23708, 23221, 22725, 22237, 21742, 21254, 20759, 20272,
 19777, 19288, 18794, 18304, 17812, 17320, 16829, 16335, 15847, 15350, 14863, 14366, 13881, 13382, 12897, 12397, 11914, 11414, 10932, 10430, 9947, 9449,
 8964, 8469, 7982, 7488, 6999, 6508, 6010, 5523, 5020, 4540, 4025, 3558, 3019, 2575, 1981, 1593, -210, -2011, -2400, -2995, -3439, -3979, -4444, -4961,
 -5438, -5944, -6430, -6927, -7419, -7906, -8402, -8887, -9384, -9869, -10366, -10851, -11351, -11835, -12333, -12817, -13316, -13802, -14299, -14786,
 -15283, -15770, -16267, -16754, -17250, -17738, -18234, -18722, -19217, -19705, -20198, -20689, -21180, -21671, -22164, -22655, -23146, -23637, -24130,
 -24620, -25113, -25604, -26095, -26588, -27077, -27572, -28060, -28556, -29041, -29541, -30022, -30527, -31001, -31516, -31973, -32529, -32592, -32049,
 -31585, -31075, -30597, -30096, -29611, -29115, -28627, -28133, -27642, -27152, -26658, -26170, -25675, -25188, -24691, -24204, -23708, -23220, -22725,
 -22237, -21743, -21254, -20760, -20272, -19777, -19289, -18794, -18304, -17812, -17319, -16828, -16336, -15847, -15351, -14863, -14366, -13881, -13382,
 -12897, -12397, -11914, -11415, -10932, -10431, -9948, -9449, -8965, -8469, -7981, -7488, -6998, -6507, -6011, -5523, -5019, -4541, -4024, -3558, -3019,
 -2575, -1980, -1593, 210};
 
const int16_t wave99[257] = {
215, 1371, 1821, 2373, 2851, 3378, 3866, 4381, 4876, 5384, 5884, 6388, 6890, 7390, 7895, 8394, 8897, 9394, 9900, 10398, 10904, 11402, 11908, 12407, 12911,
 13410, 13916, 14414, 14918, 15419, 15923, 16423, 16926, 17425, 17931, 18429, 18934, 19433, 19938, 20437, 20941, 21441, 21943, 22444, 22947, 23447, 23950,
 24450, 24954, 25455, 25957, 26459, 26960, 27464, 27962, 28469, 28964, 29474, 29965, 30481, 30965, 31490, 31957, 32525, 32589, 32034, 31561, 31041, 30552,
 30041, 29547, 29040, 28542, 28037, 27537, 27034, 26530, 26032, 25527, 25030, 24523, 24025, 23520, 23022, 22517, 22017, 21513, 21014, 20510, 20011, 19506,
 19007, 18503, 18003, 17501, 16999, 16497, 15994, 15495, 14989, 14490, 13986, 13487, 12982, 12483, 11977, 11479, 10974, 10477, 9969, 9471, 8967, 8468,
 7965, 7465, 6962, 6462, 5961, 5456, 4956, 4449, 3952, 3440, 2950, 2424, 1946, 1393, 943, -215, -1370, -1821, -2374, -2852, -3379, -3867, -4381, -4875,
 -5385, -5884, -6388, -6891, -7390, -7895, -8393, -8897, -9395, -9900, -10398, -10905, -11403, -11908, -12405, -12911, -13411, -13914, -14414, -14918,
 -15418, -15923, -16422, -16926, -17425, -17931, -18429, -18934, -19433, -19937, -20438, -20939, -21440, -21943, -22445, -22947, -23447, -23950, -24450,
 -24954, -25455, -25957, -26459, -26959, -27464, -27962, -28469, -28964, -29474, -29965, -30481, -30964, -31490, -31957, -32524, -32589, -32034, -31561,
 -31040, -30552, -30041, -29546, -29039, -28541, -28037, -27536, -27035, -26531, -26032, -25527, -25030, -24524, -24025, -23520, -23021, -22517, -22017,
 -21514, -21014, -20511, -20011, -19506, -19008, -18503, -18003, -17501, -16998, -16496, -15995, -15495, -14990, -14490, -13986, -13487, -12982, -12483,
 -11977, -11479, -10975, -10477, -9970, -9472, -8967, -8469, -7965, -7464, -6962, -6461, -5960, -5457, -4956, -4448, -3953, -3439, -2950, -2424, -1946,
 -1392, -943, 215};
 
const int16_t wave100[257] = {
219, 730, 1242, 1753, 2265, 2778, 3289, 3802, 4314, 4825, 5338, 5850, 6362, 6873, 7387, 7899, 8410, 8921, 9433, 9946, 10458, 10970, 11482, 11995, 12506,
 13018, 13531, 14042, 14554, 15067, 15579, 16091, 16603, 17113, 17628, 18137, 18652, 19161, 19676, 20185, 20700, 21210, 21723, 22233, 22747, 23257, 23771,
 24280, 24795, 25306, 25818, 26330, 26842, 27356, 27864, 28381, 28886, 29407, 29908, 30434, 30928, 31464, 31940, 32520, 32585, 32019, 31536, 31006, 30507,
 29985, 29481, 28964, 28456, 27940, 27430, 26917, 26403, 25895, 25380, 24872, 24355, 23847, 23332, 22823, 22308, 21798, 21284, 20774, 20260, 19751, 19236,
 18726, 18212, 17702, 17189, 16678, 16165, 15653, 15142, 14628, 14117, 13605, 13094, 12581, 12069, 11556, 11045, 10533, 10022, 9508, 8996, 8485, 7972,
 7462, 6949, 6437, 5925, 5414, 4901, 4388, 3878, 3364, 2854, 2341, 1829, 1317, 805, 294, -219, -729, -1242, -1754, -2266, -2779, -3290, -3802, -4313, -4826,
 -5338, -5850, -6363, -6873, -7387, -7898, -8410, -8922, -9433, -9946, -10459, -10971, -11482, -11993, -12506, -13019, -13529, -14042, -14554, -15066,
 -15579, -16090, -16603, -17113, -17628, -18137, -18652, -19161, -19675, -20186, -20698, -21209, -21723, -22234, -22747, -23257, -23771, -24280, -24795,
 -25306, -25818, -26330, -26841, -27356, -27864, -28381, -28886, -29407, -29908, -30434, -30927, -31464, -31940, -32519, -32585, -32019, -31536, -31005,
 -30507, -29985, -29480, -28963, -28455, -27940, -27429, -26918, -26404, -25895, -25380, -24872, -24356, -23847, -23332, -22822, -22308, -21798, -21285,
 -20774, -20261, -19751, -19236, -18727, -18212, -17702, -17189, -16677, -16164, -15654, -15142, -14629, -14117, -13605, -13094, -12581, -12069, -11556,
 -11045, -10534, -10022, -9509, -8997, -8485, -7973, -7462, -6948, -6437, -5924, -5413, -4902, -4388, -3877, -3365, -2853, -2341, -1829, -1317, -804, -294, 219};
