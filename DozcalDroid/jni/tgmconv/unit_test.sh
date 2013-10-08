#!/bin/bash
# +AMDG

echo -e "Tm to s:"
echo -e "0.17361111 \n`./tgmconv -k8 -os -iTm 1 | dec -k8`";
echo -e "s to Tm:"
echo -e "5;915343X1 \n`./tgmconv -k8 -oTm -is 1`";
echo -e "5 min to 3^Tm:"
echo -e "1 \n`./tgmconv -k8 -o3^Tm -imin 5`";
echo -e "3_Tm to ms:"
echo -e "0.1004693929 \n`./tgmconv -kX -oms -i3_Tm 1 | dec -k10`";
echo -e "ms to 3_Tm:"
echo -e "9;E53326X4 \n`./tgmconv -k8 -ims -o3_Tm 1`";
echo -e "G to m/s2:"
echo -e "9.8100494007 \n`./tgmconv -kX -iG -o m/s2 1 | dec -k10`";
echo -e "G to ft/s2:"
echo -e "32.18520142 \n`./tgmconv -k8 -iG -oft/s2 1 | dec -k8`";
echo -e "m/s2 TO G:"
echo -e "0;12819015 \n`./tgmconv -k8 -oG -im/s2 1`";
echo -e "ft/s2 TO G:"
echo -e "0;04583309 \n`./tgmconv -k8 -oG -ift/s2 1`";
echo -e "Gf to m:"
echo -e "0.2956829126 \n`./tgmconv -kX -iGf -om 1 | dec -k10`";
echo -e "Gf to ft:"
echo -e "0.9700882959 \n`./tgmconv -kX -iGf -oft 1 | dec -k10`";
echo -e "Gf to in:"
echo -e "11.6410595508 \n`./tgmconv -kX -iGf -oin 1 | dec -k10`";
echo -e "2_Gf to mm:"
echo -e "2.0533535596 \n`./tgmconv -kX -i2_Gf -omm 1 | dec -k10`";
echo -e "6_Gf to m:"
echo -e "0.9902360916e-7 \n`./tgmconv -kX -i6_Gf -om -e 1 | dec -k10 -e`"
echo -e "4^Gf to km:"
echo -e "6.1312808754 \n`./tgmconv -kX -i4^Gf -okm 1 | dec -k10`";
echo -e "4^Gf to mi:"
echo -e "3.8098013075 \n`./tgmconv -kX -i4^Gf -omi 1 | dec -k10`";
echo -e "m to Gf:"
echo -e "3;4701219X \n`./tgmconv -k8 -im -oGf 1`";
echo -e "ft to Gf:"
echo -e "1;045345X0 \n`./tgmconv -k8 -ift -oGf 1`";
echo -e "in to Gf:"
echo -e "0;1045345X \n`./tgmconv -k8 -iin -oGf 1`";
echo -e "mm to 2_Gf:"
echo -e "0;5X16727E \n`./tgmconv -k8 -imm -o2_Gf 1`";
echo -e "um to 6_Gf:"
echo -e "X;12247357 \n`./tgmconv -k8 -ium -o6_Gf 1`";
echo -e "km to Gf:"
echo -e "1E5X;00233X8 \n`./tgmconv -k7 -ikm -oGf 1`";
echo -e "mi to 3^Gf:"
echo -e "3;1969786 \n`./tgmconv -k7 -imi -o3^Gf 1`";
echo -e "Vl to m/s:"
echo -e "1.7031335765 \n`./tgmconv -kX -iVl -om/s 1 | dec -k10`";
echo -e "Vl to ft/s:"
echo -e "5.5877085843 \n`./tgmconv -kX -iVl -oft/s 1 | dec -k10`";
echo -e "m/s to Vl:"
echo -e "0;7067255X \n`./tgmconv -k8 -im/s -oVl 1`";
echo -e "ft/s to Vl:"
echo -e "2;1930041E \n`./tgmconv -k8 -ift/s -o1_Vl 1`";
echo -e "km/hr to Vl:"
echo -e "0;1E5X \n`./tgmconv -k4 -ikm/hr -oVl 1`";
echo -e "Vl to km/hr:"
echo -e "6.131 \n`./tgmconv -k3 -okm/hr -iVl 1 | dec -k3`";
echo -e "Sf to m2:"
echo -e "8.7428384796e-2 \n`./tgmconv -kX -iSf -om2 1 | dec -ek10`";
echo -e "Sf to ft2:"
echo -e "0.9410713018 \n`./tgmconv -kX -iSf -oft2 1 | dec -k10`";
echo -e "4^Sf to acre:"
echo -e "0.4479810495 \n`./tgmconv -kX -i4^Sf -oacre 1 | dec -k10`";
echo -e "4^Sf to ha:"
echo -e "0.1812914987 \n`./tgmconv -kX -i4^Sf -oha 1 | dec -k10`";
echo -e "6^Sf to km2:"
echo -e "0.2610597581 \n`./tgmconv -kX -i6^Sf -okm2 1 | dec -k10`";
echo -e "6^Sf to mi2:"
echo -e "0.1007957361 \n`./tgmconv -kX -i6^Sf -omi2 1 | dec -k10`";
echo -e "4_Sf to mm2:"
echo -e "4.2162608409 \n`./tgmconv -kX -i4_Sf -omm2 1 | dec -k10`";
echo -e "m2 to Sf:"
echo -e "E;5308E881 \n`./tgmconv -k8 -oSf -im2 1`";
echo -e "ft2 to Sf:"
echo -e "1;09025668 \n`./tgmconv -k8 -oSf -ift2 1`";
echo -e "acre to 4^Sf:"
echo -e "2;29538098 \n`./tgmconv -k8 -o4^Sf -iacre 1`";
echo -e "ha to 4^Sf:"
echo -e "5;62373E49 \n`./tgmconv -k8 -o4^Sf -iha 1`";
echo -e "km2 to 6^Sf:"
echo -e "3;9E7210XE \n`./tgmconv -k8 -o6^Sf -ikm2 1`";
echo -e "mi2 to 6^Sf:"
echo -e "9;E076EX30 \n`./tgmconv -k8 -o6^Sf -imi2 1`";
echo -e "mm2 to 5^Sf:"
echo -e "2;X1X127X9 \n`./tgmconv -k8 -o5_Sf -imm2 1`";
echo -e "Vm to m3:"
echo -e "2.5851079459e-2 \n`./tgmconv -k10 -iVm -om3 1 | dec -ek12`";
echo -e "Vm to L:"
echo -e "25.8503556494 \n`./tgmconv -kX -iVm -oL 1 | dec -k10`";
echo -e "Vm to ft3:"
echo -e "0.9129222555 \n`./tgmconv -kX -iVm -oft3 1 | dec -k10`";
echo -e "Vm to yd3:"
echo -e "0.033811935389 \n`./tgmconv -k12 -iVm -oyd3 1 | dec -k12`";
echo -e "Vm to gali:"
echo -e "5.6864459111 \n`./tgmconv -kX -iVm -ogali 1 | dec -k10`";
echo -e "Vm to galc:"
echo -e "6.8290818133 \n`./tgmconv -kX -iVm -ogalc 1 | dec -k10`";
echo -e "2_Vm to pti:"
echo -e "0.3159136617 \n`./tgmconv -kX -i2_Vm -opti 1 | dec -k10`";
echo -e "2_Vm to ptc:"
echo -e "0.3793934341 \n`./tgmconv -kX -i2_Vm -optc 1 | dec -k10`";
echo -e "4_Vm to mL:"
echo -e "1.2466413797 \n`./tgmconv -kX -i4_Vm -omL 1 | dec -k10`";
echo -e "m3 to 1^Vm:"
echo -e "3;28244X22 \n`./tgmconv -k8 -im3 -o1^Vm 1`";
echo -e "L to 2_Vm:"
echo -e "5;6X1X4457 \n`./tgmconv -k8 -iL -o2_Vm 1`";
echo -e "ft3 to Vm:"
echo -e "1;1189X583 \n`./tgmconv -k8 -ift3 -oVm 1`";
echo -e "yd3 to 1^Vm:"
echo -e "2;56XX2696 \n`./tgmconv -k8 -iyd3 -o1^Vm 1`";
echo -e "gali to 1_Vm:"
echo -e "2;13X69515 \n`./tgmconv -k8 -igali -o1_Vm 1`";
echo -e "galc to 1_Vm:"
echo -e "1;91051389 \n`./tgmconv -k8 -igalc -o1_Vm 1`";
echo -e "pti to 2_Vm:"
echo -e "3;1E9X22E1 \n`./tgmconv -k8 -ipti -o2_Vm 1`";
echo -e "ptc to 2_Vm:"
echo -e "2;77677E72 \n`./tgmconv -k8 -iptc -o2_Vm 1`";
echo -e "mL to 5_Vm:"
echo -e "9;7615XXEX \n`./tgmconv -k8 -imL -o5_Vm 1`";
echo -e "Mz to kg:"
echo -e "25.8503556494 \n`./tgmconv -kX -iMz -okg 1 | dec -k10`";
echo -e "Mz to lb:"
echo -e "56.9902828681 \n`./tgmconv -kX -iMz -olb 1 | dec -k10`";
echo -e "2^Mz to t:"
echo -e "3.7224512135 \n`./tgmconv -kX -i2^Mz -ot 1 | dec -k10`";
echo -e "3_Mz to oz:"
echo -e "0.5276878043 \n`./tgmconv -kX -i3_Mz -ooz 1 | dec -k10`";
echo -e "4_Mz to g:"
echo -e "1.2466413797 \n`./tgmconv -kX -i4_Mz -og 1 | dec -k10`";
echo -e "kg to 2_Mz:"
echo -e "5;6X1X4457 \n`./tgmconv -k8 -ikg -o2_Mz 1`";
echo -e "lb to 2_Mz:"
echo -e "2;63X2748X \n`./tgmconv -k8 -ilb -o2_Mz 1`";
echo -e "t to 1^Mz:"
echo -e "3;28263384 \n`./tgmconv -k8 -it -o1^Mz 1`";
echo -e "oz to 3_Mz:"
echo -e "1;X8X7E668 \n`./tgmconv -k8 -ioz -o3_Mz 1`";
echo -e "g to 5_Mz:"
echo -e "9;7615XXEX \n`./tgmconv -k8 -ig -o5_Mz 1`";
echo -e "Dz to kg/m3:"
echo -e "999.9720008 \n`./tgmconv -k7 -iDz -okg/m3 1 | dec -k7`";
echo -e "kh/dm3 to Dz:"
echo -e "1;00006E73 \n`./tgmconv -k8 -ikg/dm3 -oDz 1`";
echo -e "Vv to m2/s2:"
echo -e "2.9006639794 \n`./tgmconv -kX -iVv -om2/s2 1 | dec -k10`";
echo -e "Vl2 to m2/s2:"
echo -e "2.9006639794 \n`./tgmconv -kX -iVl2 -om2/s2 1 | dec -k10`";
echo -e "m2/s2 to Vv:"
echo -e "0;417885E7 \n`./tgmconv -k8 -im2/s2 -oVv 1`";
echo -e "m2/s2 to Vl2:"
echo -e "0;417885E7 \n`./tgmconv -k8 -im2/s2 -oVl2 1`";
echo -e "Mv to kh*m/s:"
echo -e "44.0266086711 \n`./tgmconv -kX -iMv -okg*m/s 1 | dec -k10`";
echo -e "Mz*Vl to kh*m/s:"
echo -e "44.0266086711 \n`./tgmconv -kX -iMz*Vl -okg*m/s 1 | dec -k10`";
echo -e "Mv to lb*ft/s:"
echo -e "318.4450928058 \n`./tgmconv -kX -iMv -olb*ft/s 1 | dec -k10`";
echo -e "Mz*Vl to lb*ft/s:"
echo -e "318.4450928058 \n`./tgmconv -kX -iMz*Vl -olb*ft/s 1 | dec -k10`";
echo -e "kg*m/s to 2_Mv:"
echo -e "3;32EX3114 \n`./tgmconv -k8 -ikg*m/s -o2_Mv 1`";
echo -e "lb*ft/s to 3_Mv:"
echo -e "5;5149196E \n`./tgmconv -k8 -ilb*ft/s -o3_Mv 1`";
echo -e "Mg to N:"
echo -e "253.5932659458 \n`./tgmconv -kX -iMg -oN 1 | dec -k10`";
echo -e "253.5932659458 \n`./tgmconv -kX -iMz*G -oN 1 | dec -k10`";
echo -e "Mg to kgf:"
echo -e "25.8593164787 \n`./tgmconv -kX -iMg -okgf 1 | dec -k10`";
echo -e "Mg to lbf:"
echo -e "57.0100381234 \n`./tgmconv -kX -iMg -olbf 1 | dec -k10`";
echo -e "N to 3_Mg:"
echo -e "6;9928453X \n`./tgmconv -k8 -iN -o3_Mg 1`";
echo -e "kgf to 2_Mg:"
echo -e "5;69X64071 \n`./tgmconv -k8 -ikgf -o2_Mg 1`";
echo -e "lbf to 2_Mg:"
echo -e "2;63885635 \n`./tgmconv -k8 -ilbf -o2_Mg 1`";
echo -e "Tz to N/m:"
echo -e "857.652759595 \n`./tgmconv -kX -iTz -oN/m 1 | dec -k10`";
echo -e "857.652759595 \n`./tgmconv -kX -iMg/Gf -oN/m 1 | dec -k10`";
echo -e "4_Tz to dyn/cm:"
echo -e "41.360569039 \n`./tgmconv -k9 -i4_Tz -odyn/cm 1 | dec -k9`";
echo -e "41.360569039 \n`./tgmconv -k9 -i4_Mg/Gf -odyn/cm 1 | dec -k9`";
echo -e "N/m to 3_Tz:"
echo -e "2;0216E099 \n`./tgmconv -k8 -iN/m -o3_Tz 1`";
echo -e "2;0216E099 \n`./tgmconv -k8 -iN/m -o3_Mg/Gf 1`";
echo -e "dyn/cm to 6_Tz:"
echo -e "3;59411896 \n`./tgmconv -k8 -idyn/cm -o6_Tz 1`";
echo -e "3;59411896 \n`./tgmconv -k8 -idyn/cm -o6_Mg/Gf 1`";
echo -e "Pm to N/m2:"
echo -e "2900.582763 \n`./tgmconv -k6 -iPm -oN/m2 1 | dec -k6`";
echo -e "2900.582763 \n`./tgmconv -k6 -iMg/Sf -oN/m2 1 | dec -k6`";
echo -e "Pm to lbf/in2:"
echo -e "0.4206939918 \n`./tgmconv -kX -iPm -olbf/in2 1 | dec -k10`";
echo -e "Pm to mmHg:"
echo -e "21.76 \n`./tgmconv -k8 -iPm -ommHg 1 | dec -k8`";
echo -e "Pm to inHg:"
echo -e "0.85669 \n`./tgmconv -k5 -iPm -oinHg 1 | dec -k5`";
echo -e "4^Pm to N/m2:"
echo -e "60.1464841756e6 \n`./tgmconv -kX -i4^Pm -oN/m2 1 | dec -ek10`";
echo -e "60.1464841756e6 \n`./tgmconv -kX -i4^Mg/Sf -oN/m2 1 | dec -ek10`";
echo -e "4^Pm to ton/in2:"
echo -e "3.8944243812 \n`./tgmconv -kX -i4^Pm -otoni/in2 1 | dec -k10`";
echo -e "Atz to N/m2:"
echo -e "1.015204e5 \n`./tgmconv -k6 -iAtz -oN/m2 1 | dec -ek6`";
echo -e "N/m2 to 4_Pm:"
echo -e "7;19539173 \n`./tgmconv -k8 -iN/m2 -o4_Pm 1`";
echo -e "7;19539173 \n`./tgmconv -k8 -iN/m2 -o4_Mg/Sf 1`";
echo -e "lbf/in2 to Pm:"
echo -e "2;4635E97X \n`./tgmconv -k8 -ilbf/in2 -oPm 1`";
echo -e "mmHg to 2_Pm:"
echo -e "6;75 \n`./tgmconv -k8 -immHg -o2_Pm 1`";
echo -e "inHg to Pm:"
echo -e "1;2011 \n`./tgmconv -k5 -iinHg -oPm 1`";
echo -e "MeN/m2 to 2^Pm:"
echo -e "2;4891242X \n`./tgmconv -k8 -iMeN/m2 -o2^Pm 1`";
echo -e "toni/in2 to 3^Pm:"
echo -e "3;0E8650E6 \n`./tgmconv -k8 -itoni/in2 -o3^Pm 1`";
echo -e "atm to Atz:"
echo -e "0;EE88 \n`./tgmconv -k8 -iatm -oAtz 1`";
echo -e "Wg to J:"
echo -e "74.9831954874 \n`./tgmconv -kX -iWg -oJ 1 | dec -k10`";
echo -e "74.9831954874 \n`./tgmconv -kX -iMg/Gf -oJ 1 | dec -k10`";
echo -e "Wg to ft-lbf:"
echo -e "55.3047707318 \n`./tgmconv -kX -iWg -oft*lbf 1 | dec -k10`";
echo -e "55.3047707318 \n`./tgmconv -kX -iMg/Gf -oft*lbf 1 | dec -k10`";
echo -e "Wg to cal(15):"
echo -e "17.9149911570 \n`./tgmconv -kX -iWg -ocal 1 | dec -k10`";
echo -e "Wg to btu:"
echo -e "0.0711051221 \n`./tgmconv -kX -iWg -obtu 1 | dec -k10`";
echo -e "5^Wg to kW*hr:"
echo -e "5.1828384721 \n`./tgmconv -kX -i5^Wg -okW*hr 1 | dec -k10`";
echo -e "ePl to J:"
echo -e "1.3959244694e-16 \n`./tgmconv -ek10 -iePl -oJ 1 | dec -ek10`";
echo -e "J to 2_Wg:"
echo -e "1;E0660616 \n`./tgmconv -k8 -iJ -o2_Wg 1`";
echo -e "ft*lbf to 2_Wg:"
echo -e "2;72E352X2 \n`./tgmconv -k8 -ift*lbf -o2_Wg 1`";
echo -e "cal to 2_Wg:"
echo -e "8;05571XXX \n`./tgmconv -k8 -ical -o2_Wg 1`";
echo -e "btu to Wg:"
echo -e "12;0920688X \n`./tgmconv -k8 -ibtu -oWg 1`";
echo -e "kW*hr to 4^Wg:"
echo -e "2;394X9107 \n`./tgmconv -k8 -ikW*hr -o4^Wg 1`";
echo -e "fJ to ePl:"
echo -e "7;1E6X8767 \n`./tgmconv -k8 -ifJ -oePl 1`";
echo -e "Pv to J/s (W):"
echo -e "431.9032060077 \n`./tgmconv -kX -oJ/s -iPv 1 | dec -k10`";
echo -e "431.9032060077 \n`./tgmconv -kX -oJ/s -iWg/Tm 1 | dec -k10`";
echo -e "Pv to ft*lbf/s:"
echo -e "318.5554794154 \n`./tgmconv -kX -oft*lbf/s -iPv 1 | dec -k10`";
echo -e "318.5554794154 \n`./tgmconv -kX -oft*lbf/s -iWg/Tm 1 | dec -k10`";
echo -e "Pv to hp:"
echo -e "0.5789587212 \n`./tgmconv -kX -ohp -iPv 1 | dec -k10`";
echo -e "0.5789587212 \n`./tgmconv -kX -ohp -iWg/Tm 1 | dec -k10`";
echo -e "W to 3_Pv:"
echo -e "4;00167091 \n`./tgmconv -k8 -o3_Pv -iW 1`";
echo -e "4;00167091 \n`./tgmconv -k8 -o3_Wg/Tm -iW 1`";
echo -e "ft*lbf/s to 3_Pv:"
echo -e "5;51161XX3 \n`./tgmconv -k8 -o3_Pv -ift*lbf/s 1`";
echo -e "5;51161XX3 \n`./tgmconv -k8 -o3_Wg/Tm -ift*lbf/s 1`";
echo -e "hp to Pv:"
echo -e "1;88880371 \n`./tgmconv -k8 -oPv -ihp 1`";
echo -e "Vsd to N*s/m2:"
echo -e "503.5733963715 \n`./tgmconv -kX -oN*s/m2 -iVsd 1 | dec -k10`";
echo -e "503.5733963715 \n`./tgmconv -kX -oN*s/m2 -iMg*Tm/Sf 1 | dec -k10`";
echo -e "Vsn to m2/s:"
echo -e "0.50358749643 \n`./tgmconv -k11 -om2/s -iVsn 1 | dec -k11`";
echo -e "0.50358749643 \n`./tgmconv -k11 -om2/s -iSf/Tm 1 | dec -k11`";
echo -e "N*s/m2 to 3_Vsd:"
echo -e "3;52171036 \n`./tgmconv -k8 -o3_Vsd -iN*s/m2 1`";
echo -e "3;52171036 \n`./tgmconv -k8 -o3_Mg*Tm/Sf -iN*s/m2 1`";
echo -e "m2/s to Vsn:"
echo -e "1;E9E46851 \n`./tgmconv -k8 -oVsn -im2/s 1`";
echo -e "1;E9E46851 \n`./tgmconv -k8 -oSf/Tm -im2/s 1`";
echo -e "rGf (rad) to deg:"
echo -e "57.2957795131 \n`./tgmconv -kX -irGf -odeg 1 | dec -k10`";
echo -e "57.2957795131 \n`./tgmconv -kX -irad -odeg 1 | dec -k10`";
echo -e "deg to 2_rGf (2_rad):"
echo -e "2;61XE303X \n`./tgmconv -k8 -ideg -o2_rGf 1`";
echo -e "0;0261XE303X \n`./tgmconv -kX -ideg -orad 1`";
echo -e "rVl to rad/s:"
echo -e "5.76 \n`./tgmconv -irVl -orad/s 1 | dec`";
echo -e "5.76 \n`./tgmconv -irGf/Tm -orad/s 1 | dec`";
echo -e "rad/s to 1_rVl:"
echo -e "2;1 \n`./tgmconv -irad/s -o1_rVl 1`";
echo -e "2;1 \n`./tgmconv -irad/s -o1_rGf/Tm 1`";
echo -e "rG to rad/s2:"
echo -e "33.1776 \n`./tgmconv -irG -orad/s2 1 | dec`";
echo -e "33.1776 \n`./tgmconv -irGf/Tm2 -orad/s2 1 | dec`";
echo -e "rad/s2 to 2_rG:"
echo -e "4;41 \n`./tgmconv -irad/s2 -o2_rG 1`";
echo -e "4;41 \n`./tgmconv -irad/s2 -o2_rGf/Tm2 1`";
echo -e "Fq to Hz:"
echo -e "5.76 \n`./tgmconv -iFq -oHz 1 | dec`";
echo -e "Fq to RPM:"
echo -e "345.6 \n`./tgmconv -iFq -oRPM 1 | dec`";
echo -e "3^Fq to kHz:"
echo -e "9.95328 \n`./tgmconv -k5 -i3^Fq -okHz 1 | dec -k5`";
echo -e "Hz to 1_Fq:"
echo -e "2;1 \n`./tgmconv -iHz -o1_Fq 1`";
echo -e "RPM to 3_Fq:"
echo -e "5 \n`./tgmconv -iRPM -o3_Fq 1`";
echo -e "X kHz to 3^Fq:"
echo -e "1;00814 \n`./tgmconv -k5 -ikHz -o3^Fq X`";
echo -e "RMv to kg*m2/s:"
echo -e "13.0179158832 \n`./tgmconv -kX -iRMv -okg*m2/s 1 | dec -k10`";
echo -e "13.0179158832 \n`./tgmconv -kX -iMv*rGf -okg*m2/s 1 | dec -k10`";
echo -e "kg*m2/s to 2_RMv:"
echo -e "E;08X6E6E6 \n`./tgmconv -k8 -ikg*m2/s -o2_RMv 1`";
echo -e "RMg to N*m:"
echo -e "74.9831954874 \n`./tgmconv -kX -iRMg -oN*m 1 | dec -k10`";
echo -e "74.9831954874 \n`./tgmconv -kX -iMg*rGf -oN*m 1 | dec -k10`";
echo -e "N*m to 2_RMg:"
echo -e "1;E0660616 \n`./tgmconv -k8 -iN*m -o2_RMg 1`";
echo -e "1;E0660616 \n`./tgmconv -k8 -iN*m -o2_Mg*rGf 1`";
echo -e "QMz to kg*m2:"
echo -e "2.2600548408 \n`./tgmconv -kX -iQMz -okg*m2 1 | dec -k10`";
echo -e "2.2600548408 \n`./tgmconv -kX -iRMg/rG -okg*m2 1 | dec -k10`";
echo -e "kg*m2 to 1_QMz:"
echo -e "5;386EE970 \n`./tgmconv -k8 -ikg*m2 -o1_QMz 1`";
echo -e "5;386EE970 \n`./tgmconv -k8 -ikg*m2 -o1_RMg/rG 1`";
echo -e "Kr to amp:"
echo -e "0.4957220687 \n`./tgmconv -kX -iKr -oA 1 | dec -k10`";
echo -e "5_Kr to uA:"
echo -e "1.9921958137 \n`./tgmconv -kX -i5_Kr -ouA 1 | dec -k10`";
echo -e "4^Kr to kA:"
echo -e "10.2792928167 \n`./tgmconv -kX -i4^Kr -okA 1 | dec -k10`";
echo -e "A to Kr:"
echo -e "2;0259X834 \n`./tgmconv -k8 -iA -oKr 1`";
echo -e "uA to 6_Kr:"
echo -e "6;03474748 \n`./tgmconv -k8 -iuA -o6_Kr 1`";
echo -e "kA to 3^Kr:"
echo -e "1;2013142X \n`./tgmconv -k8 -ikA -o3^Kr 1`";
echo -e "Kn to At:"
echo -e "0.4957220687 \n`./tgmconv -kX -oAt -iKn 1 | dec -k10`";
echo -e "At to Kn:"
echo -e "2;0259X834 \n`./tgmconv -k8 -iAt -oKn 1`";
echo -e "Pl to V:"
echo -e "871.2607996978 \n`./tgmconv -kX -iPl -oV 1 | dec -k10`";
echo -e "1^Pl to kV:"
echo -e "10.4551295964 \n`./tgmconv -kX -i1^Pl -okV 1 | dec -k10`";
echo -e "2^Pl to kV:"
echo -e "125.4615551565 \n`./tgmconv -kX -i2^Pl -okV 1 | dec -k10`";
echo -e "1_Pl to V:"
echo -e "72.6050666415 \n`./tgmconv -kX -i1_Pl -oV 1 | dec -k10`";
echo -e "2_Pl to V:"
echo -e "6.0504222201 \n`./tgmconv -kX -i2_Pl -oV 1 | dec -k10`";
echo -e "3_Pl to V:"
echo -e "0.5042018517 \n`./tgmconv -kX -i3_Pl -oV 1 | dec -k10`";
echo -e "6_Pl to mV:"
echo -e "0.2917834790 \n`./tgmconv -kX -i6_Pl -omV 1 | dec -k10`";
echo -e "8_Pl to uV:"
echo -e "2.0262741596 \n`./tgmconv -kX -i8_Pl -ouV 1 | dec -k10`";
echo -e "Og to ohm:"
echo -e "1757.55903297 \n`./tgmconv -k8 -iOg -oohm 1 | dec -k8`";
echo -e "1757.55903297 \n`./tgmconv -k8 -iPl/Kr -oohm 1 | dec -k8`";
echo -e "3^Og to Meohm:"
echo -e "3.0370620090 \n`./tgmconv -kX -i3^Og -oMeohm 1 | dec -k10`";
echo -e "3.0370620090 \n`./tgmconv -kX -i3^Pl/Kr -oMeohm 1 | dec -k10`";
echo -e "3_Og to ohm:"
echo -e "1.0171059219 \n`./tgmconv -kX -i3_Og -oohm 1 | dec -k10`";
echo -e "kohm to 1_Og:"
echo -e "6;9E222121 \n`./tgmconv -k8 -ikohm -o1_Og 1`";
echo -e "6;9E222121 \n`./tgmconv -k8 -ikohm -o1_Pl/Kr 1`";
echo -e "Meohm to 2^Og:"
echo -e "3;E4E7992X \n`./tgmconv -k8 -iMeohm -o2^Og 1`";
echo -e "ohm to 3_Og:"
echo -e "0;E96E3105 \n`./tgmconv -k8 -iohm -o3_Og 1`";
echo -e "Go to umho:"
echo -e "568.9709314098 \n`./tgmconv -kX -iGo -oumho 1 | dec -k10`";
echo -e "568.9709314098 \n`./tgmconv -kX -iKr/Pl -ouS 1 | dec -k10`";
echo -e "3^Go to mho:"
echo -e "0.9831817695 \n`./tgmconv -kX -i3^Go -omho 1 | dec -k10`";
echo -e "0.9831817695 \n`./tgmconv -kX -i3^Kr/Pl -oS 1 | dec -k10`";
echo -e "mmho to Go:"
echo -e "1;91108E1X \n`./tgmconv -k8 -immho -oGo 1`";
echo -e "1;91108E1X \n`./tgmconv -k8 -imS -oKr/Pl 1`";
echo -e "mho to 3^Go:"
echo -e "1;02568601 \n`./tgmconv -k8 -imho -o3^Go 1`";
echo -e "1;02568601 \n`./tgmconv -k8 -iS -o3^Kr/Pl 1`";
echo -e "Quel to mC:"
echo -e "86.0628591502 \n`./tgmconv -kX -iQl -omC 1 | dec -k10`";
echo -e "86.0628591502 \n`./tgmconv -kX -iKr*Tm -omC 1 | dec -k10`";
echo -e "1^Ql to C:"
echo -e "1.0327543098 \n`./tgmconv -kX -i1^Ql -oC 1 | dec -k10`";
echo -e "1.0327543098 \n`./tgmconv -kX -i1^Kr*Tm -oC 1 | dec -k10`";
echo -e "mC to 2_Ql:"
echo -e "1;80E34748 \n`./tgmconv -k8 -imC -o2_Ql 1`";
echo -e "1;80E34748 \n`./tgmconv -k8 -imC -o2_Kr*Tm 1`";
echo -e "C to 1^Ql:"
echo -e "0;E7524207 \n`./tgmconv -k8 -iC -o1^Ql 1`";
echo -e "0;E7524207 \n`./tgmconv -k8 -iC -o1^Kr*Tm 1`";
echo -e "Kp to uF:"
echo -e "98.7796755920 \n`./tgmconv -kX -iKp -ouF 1 | dec -k10`";
echo -e "98.7796755920 \n`./tgmconv -kX -iQl/Pl -ouF 1 | dec -k10`";
echo -e "1_Kp to uF:"
echo -e "8.2316396327 \n`./tgmconv -kX -i1_Kp -ouF 1 | dec -k10`";
echo -e "8.2316396327 \n`./tgmconv -kX -i1_Ql/Pl -ouF 1 | dec -k10`";
echo -e "5_Kp to nF:"
echo -e "0.3969733619 \n`./tgmconv -kX -i5_Kp -onF 1 | dec -k10`";
echo -e "0.3969733619 \n`./tgmconv -kX -i5_Ql/Pl -onF 1 | dec -k10`";
echo -e "8_Kp to pF:"
echo -e "0.2297299548 \n`./tgmconv -kX -i8_Kp -opF 1 | dec -k10`";
echo -e "0.2297299548 \n`./tgmconv -kX -i8_Ql/Pl -opF 1 | dec -k10`";
echo -e "F to 3^Kp:"
echo -e "5;X3765921 \n`./tgmconv -k8 -iF -o3^Kp 1`";
echo -e "5;X3765921 \n`./tgmconv -k8 -iF -o3^Ql/Pl 1`";
echo -e "uF to 2_Kp:"
echo -e "1;55E088XE \n`./tgmconv -k8 -iuF -o2_Kp 1`";
echo -e "1;55E088XE \n`./tgmconv -k8 -iuF -o2_Ql/Pl 1`";
echo -e "nF to 5_Kp:"
echo -e "2;628E2XEX \n`./tgmconv -k8 -inF -o5_Kp 1`";
echo -e "2;628E2XEX \n`./tgmconv -k8 -inF -o5_Ql/Pl 1`";
echo -e "pF to 8_Kp:"
echo -e "4;429X5EE8 \n`./tgmconv -k8 -ipF -o8_Kp 1`";
echo -e "4;429X5EE8 \n`./tgmconv -k8 -ipF -o8_Ql/Pl 1`";
echo -e "Mt to uF/m:"
echo -e "334.0729930165 \n`./tgmconv -kX -iMt -ouF/m 1 | dec -k10`";
echo -e "334.0729930165 \n`./tgmconv -kX -iMb*Vv-1 -ouF/m 1 | dec -k10`";
echo -e "uF/m to 3_Mt:"
echo -e "5;20X15093 \n`./tgmconv -k8 -o3_Mt -iuF/m 1`";
echo -e "5;20X15093 \n`./tgmconv -k8 -o3_Mb*Vv-1 -iuF/m 1`";
echo -e "Fm to Wb:"
echo -e "151.2605555031 \n`./tgmconv -kX -iFm -oWb 1 | dec -k10`";
echo -e "151.2605555031 \n`./tgmconv -kX -iMb*Kr*Gf -oWb 1 | dec -k10`";
echo -e "6_Fm to uWb:"
echo -e "50.6568539895 \n`./tgmconv -kX -i6_Fm -ouWb 1 | dec -k10`";
echo -e "50.6568539895 \n`./tgmconv -kX -i6_Mb*Kr*Gf -ouWb 1 | dec -k10`";
echo -e "Wb to 2_Fm:"
echo -e "0;E5107E98 \n`./tgmconv -k8 -iWb -o2_Fm 1`";
echo -e "0;E5107E98 \n`./tgmconv -k8 -iWb -o2_Mb*Kr*Gf 1`";
echo -e "100 uWb to 6_Fm:"
echo -e "1;E8322E0E \n`./tgmconv -k8 -iuWb -o6_Fm 84`";
echo -e "1;E8322E0E \n`./tgmconv -k8 -iuWb -o6_Mb*Kr*Gf 84`";
echo -e "Fz to T:"
echo -e "1730.1080862416 \n`./tgmconv -kX -iFz -oT 1 | dec -k10`";
echo -e "1730.1080862416 \n`./tgmconv -kX -iFm/Sf -oT 1 | dec -k10`";
echo -e "3_Fz to T:"
echo -e "1.0012199573 \n`./tgmconv -kX -i3_Fz -oT 1 | dec -k10`";
echo -e "1.0012199573 \n`./tgmconv -kX -i3_Fm/Sf -oT 1 | dec -k10`";
echo -e "8_Fz to uT:"
echo -e "4.0236784550 \n`./tgmconv -kX -i8_Fz -ouT 1 | dec -k10`";
echo -e "4.0236784550 \n`./tgmconv -kX -i8_Fm/Sf -ouT 1 | dec -k10`";
echo -e "T to 3_Fz:"
echo -e "0;EE9X8980 \n`./tgmconv -k8 -iT -o3_Fz 1`";
echo -e "0;EE9X8980 \n`./tgmconv -k8 -iWb/m2 -o3_Fm/Gf2 1`";
echo -e "mT to 6_Fz:"
echo -e "1;88641939 \n`./tgmconv -k8 -imT -o6_Fz 1`";
echo -e "uT to 9_Fz:";
echo -e "2;E955E053 \n`./tgmconv -k8 -iuT -o9_Fz 1`";
echo -e "2;E955E053 \n`./tgmconv -k8 -iuT -o9_Fm/Sf 1`";
echo -e "Gn to H:"
echo -e "305.1317765583 \n`./tgmconv -kX -iGn -oH 1 | dec -k10`";
echo -e "305.1317765583 \n`./tgmconv -kX -iMb*Gf -oH 1 | dec -k10`";
echo -e "6_Gn to mH:"
echo -e "0.1021880146 \n`./tgmconv -kX -i6_Gn -omH 1 | dec -k10`";
echo -e "0.1021880146 \n`./tgmconv -kX -i6_Mb*Gf -omH 1 | dec -k10`";
echo -e "H to 3_Gn:"
echo -e "5;7E5X7271 \n`./tgmconv -k8 -iH -o3_Gn 1`";
echo -e "5;7E5X7271 \n`./tgmconv -k8 -iH -o3_Mb*Gf 1`";
echo -e "mH to 6_Gn:"
echo -e "9;95200E47 \n`./tgmconv -k8 -imH -o6_Gn 1`";
echo -e "9;95200E47 \n`./tgmconv -k8 -imH -o6_Mb*Gf 1`";
echo -e "Lk to At/Wb:"
echo -e "0.0032772725649 \n`./tgmconv -k13 -iLk -oAt/Wb 1 | dec -k13`";
echo -e "0.0032772725649 \n`./tgmconv -k13 -iKn/Fm -oAt/Wb 1 | dec -k13`";
echo -e "At/Wb to 2^Lk:"
echo -e "2;1516E863 \n`./tgmconv -k8 -iAt/Wb -o2^Lk 1`";
echo -e "2;1516E863 \n`./tgmconv -k8 -iAt/Wb -o2^Kn/Fm 1`";
echo -e "Mb to H/m:"
echo -e "1031.9560704 \n`./tgmconv -k7 -iMb -oH/m 1 | dec -k7`";
echo -e "H/m to 3_Mb:"
echo -e "1;811628 \n`./tgmconv -k8 -iH/m -o3_Mb 1`";
echo -e "Pz to kW/m2:"
echo -e "4.9400798953 \n`./tgmconv -kX -iPz -okW/m2 1 | dec -k10`";
echo -e "4.9400798953 \n`./tgmconv -kX -iPv/Sf -okW/m2 1 | dec -k10`";
echo -e "kW/m2 to 1_Pz:"
echo -e "2;51960515 \n`./tgmconv -k8 -ikW/m2 -o1_Pz 1`";
echo -e "2;51960515 \n`./tgmconv -k8 -ikW/m2 -o1_Pv/Sf 1`";
echo -e "Lp to lm:"
echo -e "1.1795967512 \n`./tgmconv -kX -iLp -olm 1 | dec -k10`";
echo -e "lm to 1_Lp:"
echo -e "X;20XX7E81 \n`./tgmconv -k8 -ilm -o 1_Lp 1`";
echo -e "Ld to lm/m2:"
echo -e "13.4921485051 \n`./tgmconv -kX -iLd -olm/m2 1 | dec -k10`";
echo -e "13.4921485051 \n`./tgmconv -kX -iLp/Sf -olm/m2 1 | dec -k10`";
echo -e "lm/m2 to 2_Ld:"
echo -e "X;80X88694 \n`./tgmconv -k8 -ilm/m2 -o2_Ld 1`";
echo -e "X;80X88694 \n`./tgmconv -k8 -ilm/m2 -o2_Lp/Sf 1`";
echo -e "Sz to m2/lm*s:"
echo -e "0.4269149571 \n`./tgmconv -kX -om2/lm*s -iSz 1 | dec -k10`";
echo -e "0.4269149571 \n`./tgmconv -kX -om2/lm*s -iLd*Tm-1 1 | dec -k10`";
echo -e "m2/lm*s to Sz:"
echo -e "2;41378995 \n`./tgmconv -k8 -im2/lm*s -oSz 1`";
echo -e "2;41378995 \n`./tgmconv -k8 -im2/lm*s -oLd*Tm-1 1`";
echo -e "QLd to cd:"
echo -e "1.1795967512 \n`./tgmconv -iQLd -ocd -kX 1 | dec -k10`";
echo -e "cd to 1_QLd:"
echo -e "X;20XX7E81 \n`./tgmconv -k8 -icd -o1_QLd 1`";
echo -e "2^Cg to K:"
echo -e "0.1 \n`./tgmconv -i2^Cg -oK 1 | dec`";
echo -e "K to 2^Cg:"
echo -e "X \n`./tgmconv -o2^Cg -iK 1`";
echo -e "Ck to kJ/K:"
echo -e "107.9758015019 \n`./tgmconv -kX -iCk -okJ/K 1 | dec -k10`";
echo -e "107.9758015019 \n`./tgmconv -kX -iWg/Cg -okJ/K 1 | dec -k10`";
echo -e "5_Ck to J/K:"
echo -e "0.4339305294 \n`./tgmconv -kX -i5_Ck -oJ/K 1 | dec -k10`";
echo -e "0.4339305294 \n`./tgmconv -kX -i5_Wg/Cg -oJ/K 1 | dec -k10`";
echo -e "kJ/K to 2_Ck:"
echo -e "1;40062430 \n`./tgmconv -k8 -ikJ/K -o2_Ck 1`";
echo -e "1;40062430 \n`./tgmconv -k8 -ikJ/K -o2_Wg/Cg 1`";
echo -e "J/K to 5_Ck:"
echo -e "2;37X254E5 \n`./tgmconv -k8 -iJ/K -o5_Ck 1`";
echo -e "2;37X254E5 \n`./tgmconv -k8 -iJ/K -o5_Wg/Cg 1`";
echo -e "Csp to kJ/K*kg:"
echo -e "4.1769561304 \n`./tgmconv -kX -okJ/K*kg -iCsp 1 | dec -k10`";
echo -e "4.1769561304 \n`./tgmconv -kX -okJ/K*kg -iWg/Cg*Mz 1 | dec -k10`";
echo -e "4_Csp to J/K*kg:"
echo -e "0.2014349986 \n`./tgmconv -kX -oJ/K*kg -i4_Csp 1 | dec -k10`";
echo -e "0.2014349986 \n`./tgmconv -kX -oJ/K*kg -i4_Wg/Cg*Mz 1 | dec -k10`";
echo -e "kJ/K*kg to 1_Csp:"
echo -e "2;X5846983 \n`./tgmconv -k8 -ikJ/K*kg -o1_Csp 1`";
echo -e "2;X5846983 \n`./tgmconv -k8 -ikJ/K*kg -o1_Wg/Cg*Mz 1`";
echo -e "J/K*kg to 4_Csp:"
echo -e "4;E6X54908 \n`./tgmconv -k8 -iJ/K*kg -o4_Csp 1`";
echo -e "4;E6X54908 \n`./tgmconv -k8 -iJ/K*kg -o4_Wg/Cg*Mz 1`";
echo -e "Cdu to MeW/m*K:"
echo -e "2.1034039851 \n`./tgmconv -kX -oMeW/m*K -iCdu 1 | dec -k10`";
echo -e "2.1034039851 \n`./tgmconv -kX -oMeW/m*K -iWg*Gf/Sf*Cg 1 | dec -k10`";
echo -e "4_Cdu to W/m*K:"
echo -e "101.4373063783 \n`./tgmconv -kX -oW/m*K -i4_Cdu 1 | dec -k10`";
echo -e "101.4373063783 \n`./tgmconv -kX -oW/m*K -i4_Wg*Gf/Sf*Cg 1 | dec -k10`";
echo -e "kW/m*K to 4_Cdu:"
echo -e "9;X3719E98 \n`./tgmconv -k8 -ikW/m*K -o4_Cdu 1`";
echo -e "9;X3719E98 \n`./tgmconv -k8 -ikW/m*K -o4_Wg*Gf/Sf*Cg 1`";
echo -e "W/m*K to 2_Cdu:"
echo -e "1;50508E14 \n`./tgmconv -k8 -iW/m*K -o6_Cdu 1`";
echo -e "1;50508E14 \n`./tgmconv -k8 -iW/m*K -o6_Wg*Gf/Sf*Cg 1`";
echo -e "Tgr to m*K/m:"
echo -e "2.3486120262 \n`./tgmconv -kX -iTgr -omK/m 1 | dec -k10`";
echo -e "2.3486120262 \n`./tgmconv -kX -iCg/Gf -omK/m 1 | dec -k10`";
echo -e "2^Tgr to K/m:"
echo -e "0.3382001318 \n`./tgmconv -kX -i2^Tgr -oK/m 1 | dec -k10`";
echo -e "0.3382001318 \n`./tgmconv -kX -i2^Cg/Gf -oK/m 1 | dec -k10`";
echo -e "4^Tgr to K/m:"
echo -e "48.7008189752 \n`./tgmconv -kX -i4^Tgr -oK/m 1 | dec -k10`";
echo -e "48.7008189752 \n`./tgmconv -kX -i4^Cg/Gf -oK/m 1 | dec -k10`";
echo -e "K/m to 2^Tgr:"
echo -e "2;E5949856 \n`./tgmconv -k8 -iK/m -o2^Tgr 1`";
echo -e "2;E5949856 \n`./tgmconv -k8 -iK/m -o2^Cg/Gf 1`";
echo -e "K/cm to 4^Tgr:"
echo -e "2;078240X6 \n`./tgmconv -k8 -iK/cm -o4^Tgr 1`";
echo -e "2;078240X6 \n`./tgmconv -k8 -iK/cm -o4^Cg/Gf 1`";
echo -e "K/mm to 5^Tgr:"
echo -e "1;8649E489 \n`./tgmconv -k8 -iK/mm -o5^Tgr 1`";
echo -e "1;8649E489 \n`./tgmconv -k8 -iK/mm -o5^Cg/Gf 1`";
echo -e "Wsp to J/kg:"
echo -e "2.9006639794 \n`./tgmconv -kX -iWsp -o J/kg 1 | dec -k10`";
echo -e "2.9006639794 \n`./tgmconv -kX -iWg/Mz -o J/kg 1 | dec -k10`";
echo -e "4^Wsp to kJ/kg:"
echo -e "60.1481682772 \n`./tgmconv -kX -i4^Wsp -okJ/kg 1 | dec -k10`";
echo -e "60.1481682772 \n`./tgmconv -kX -i4^Wg/Mz -okJ/kg 1 | dec -k10`";
echo -e "6^Wsp to kJ/g:"
echo -e "8.6613362319 \n`./tgmconv -kX -i6^Wsp -okJ/g 1 | dec -k10`";
echo -e "8.6613362319 \n`./tgmconv -kX -i6^Wg/Mz -okJ/g 1 | dec -k10`";
echo -e "J/kg to 1_Wsp:"
echo -e "4;17885166 \n`./tgmconv -k8 -iJ/kg -o1_Wsp 1`";
echo -e "4;17885166 \n`./tgmconv -k8 -iJ/kg -o1_Wg/Mz 1`";
echo -e "kJ/kg to 2^Wsp:"
echo -e "2;488E980X \n`./tgmconv -k8 -ikJ/kg -o2^Wsp 1`";
echo -e "2;488E980X \n`./tgmconv -k8 -ikJ/kg -o2^Wg/Mz 1`";
echo -e "kJ/g to 5^Wsp:"
echo -e "1;476107X1 \n`./tgmconv -k8 -ikJ/g -o5^Wsp 1`";
echo -e "1;476107X1 \n`./tgmconv -k8 -ikJ/g -o5^Wg/Mz 1`";
echo -e "Fl to m3/s:"
echo -e "0.1489022177 \n`./tgmconv -kX -iFl -om3/s 1 | dec -k10`";
echo -e "0.1489022177 \n`./tgmconv -kX -iVm/Tm -om3/s 1 | dec -k10`";
echo -e "Fl to L/s:"
echo -e "148.89804854 \n`./tgmconv -k8 -iFl -oL/s 1 | dec -k8`";
echo -e "148.89804854 \n`./tgmconv -k8 -iVm/Tm -oL/s 1 | dec -k8`";
echo -e "Fl to ft3/s:"
echo -e "5.2584321917 \n`./tgmconv -kX -iFl -oft3/s 1 | dec -k10`";
echo -e "5.2584321917 \n`./tgmconv -kX -iVm/Tm -oft3/s 1 | dec -k10`";
echo -e "Fl to m3/min:"
echo -e "8.9341330612 \n`./tgmconv -kX -iFl -om3/min 1 | dec -k10`";
echo -e "8.9341330612 \n`./tgmconv -kX -iVm/Tm -om3/min 1 | dec -k10`";
echo -e "2_Fl to ft3/min:"
echo -e "2.1910134132 \n`./tgmconv -kX -i2_Fl -oft3/min 1 | dec -k10`";
echo -e "2.1910134132 \n`./tgmconv -kX -i2_Vm/Tm -oft3/min 1 | dec -k10`";
echo -e "2_Fl to gali/min:"
echo -e "13.6474701869 \n`./tgmconv -kX -i2_Fl -ogali/min 1 | dec -k10`"; 
echo -e "13.6474701869 \n`./tgmconv -kX -i2_Vm/Tm -ogali/min 1 | dec -k10`"; 
echo -e "2_Fl to galc/min:"
echo -e "16.3897963520 \n`./tgmconv -kX -i2_Fl -ogalc/min 1 | dec -k10`"; 
echo -e "16.3897963520 \n`./tgmconv -kX -i2_Vm/Tm -ogalc/min 1 | dec -k10`"; 
echo -e "m3/s to Fl:"
echo -e "6.870E2126 \n`./tgmconv -k8 -im3/s -oFl 1`";
echo -e "6.870E2126 \n`./tgmconv -k8 -im3/s -oVm/Tm 1`";
echo -e "L/s to 3_Fl:"
echo -e "E;731X7139 \n`./tgmconv -k8 -iL/s -o3_Fl 1`";
echo -e "E;731X7139 \n`./tgmconv -k8 -iL/s -o3_Vm/Tm 1`";
echo -e "ft3/s to Fl:"
echo -e "0;2347469X \n`./tgmconv -k8 -ift3/s -oFl 1`";
echo -e "0;2347469X \n`./tgmconv -k8 -ift3/s -oVm/Tm 1`";
echo -e "m3/min to 1_Fl:"
echo -e "1;414EX02E \n`./tgmconv -k8 -im3/min -o1_Fl 1`";
echo -e "1;414EX02E \n`./tgmconv -k8 -im3/min -o1_Vm/Tm 1`";
echo -e "ft3/min to 3_Flo:"
echo -e "5;58814451 \n`./tgmconv -k8 -ift3/min -o3_Fl 1`";
echo -e "5;58814451 \n`./tgmconv -k8 -ift3/min -o3_Vm/Tm 1`";
echo -e "gali/min to 4_Flo:"
echo -e "X;6749E590 \n`./tgmconv -k8 -igali/min -o4_Fl 1`";
echo -e "X;6749E590 \n`./tgmconv -k8 -igali/min -o4_Vm/Tm 1`";
echo -e "galc/min to 4_Flo:"
echo -e "8;95216679 \n`./tgmconv -k8 -igalc/min -o4_Fl 1`";
echo -e "8;95216679 \n`./tgmconv -k8 -igalc/min -o4_Vm/Tm 1`";
echo -e "Vsp to m3/kg:"
echo -e "1.000028e-03 \n`./tgmconv -ek6 -iVsp -om3/kg 1 | dec -ek6`";
echo -e "1.000028e-03 \n`./tgmconv -ek6 -iVm/Mz -om3/kg 1 | dec -ek6`";
echo -e "m3/kg to 2^Vsp:"
echo -e "6;E3E7E74E \n`./tgmconv -k8 -im3/kg -o2^Vsp 1`";
echo -e "6;E3E7E74E \n`./tgmconv -k8 -im3/kg -o2^Vm/Mz 1`";
echo -e "Ag to kg*m2/s:"
echo -e "13.0179158832 \n`./tgmconv -kX -iAg -okg*m2/s 1 | dec -k10`";
echo -e "13.0179158832 \n`./tgmconv -kX -iMv*Gf -okg*m2/s 1 | dec -k10`";
echo -e "kg*m2/s to 2_Ag:"
echo -e "E;08X6E6E6 \n`./tgmconv -k8 -ikg*m2/s -o2_Ag 1`";
echo -e "E;08X6E6E6 \n`./tgmconv -k8 -ikg*m2/s -o2_Mv*Gf 1`";
echo -e "RQl to C*m:"
echo -e "2.5447316859e-02 \n`./tgmconv -ek10 -iRQl -oC*m 1 | dec -ek10`";
echo -e "2.5447316859e-02 \n`./tgmconv -ek10 -iQl*Gf -oC*m 1 | dec -ek10`";
echo -e "C*m to 1^RQl:"
echo -e "3;3368EE86 \n`./tgmconv -k8 -iC*m -o1^RQl 1`";
echo -e "3;3368EE86 \n`./tgmconv -k8 -iC*m -o1^Ql*Gf 1`";
echo -e "Ry to ohm*m2/m:"
echo -e "519.6801739150 \n`./tgmconv -kX -iRy -oohm*m2/m 1 | dec -k10`";
echo -e "519.6801739150 \n`./tgmconv -kX -iOg*Sf/Gf -oohm*m2/m 1 | dec -k10`";
echo -e "4_Ry to ohm*cm2/cm:"
echo -e "2.5061736782 \n`./tgmconv -kX -i4_Ry -oohm*cm2/cm 1 | dec -k10`";
echo -e "2.5061736782 \n`./tgmconv -kX -i4_Og*Sf/Gf -oohm*cm2/cm 1 | dec -k10`";
echo -e "ohm*m2/m to 3_Ry:"
echo -e "3;3X998926 \n`./tgmconv -k8 -iohm*m2/m -o3_Ry 1`";
echo -e "3;3X998926 \n`./tgmconv -k8 -iohm*m2/m -o3_Og*Sf/Gf 1`";
echo -e "ohm*cm2/cm to 5_Ry:"
echo -e "4;955E7418 \n`./tgmconv -k8 -iohm*cm2/cm -o5_Ry 1`";
echo -e "4;955E7418 \n`./tgmconv -k8 -iohm*cm2/cm -o5_Og*Sf/Gf 1`";
echo -e "Edu to mho*m/m2:"
echo -e "0.00192426044 \n`./tgmconv -k11 -iEdu -omho*m/m2 1 | dec -k11`";
echo -e "0.00192426044 \n`./tgmconv -k11 -iGo*Gf/Sf -oS*m/m2 1 | dec -k11`";
echo -e "0.00192426044 \n`./tgmconv -k11 -iGo*Gf/Sf -oohm-1*m/m2 1 | dec -k11`";
echo -e "4^Edu to mho*cm/cm2:"
echo -e "0.3990146448 \n`./tgmconv -kX -i4^Edu -omho*cm/cm2 1 | dec -k10`";
echo -e "0.3990146448 \n`./tgmconv -kX -i4^Go*Gf/Sf -oS*cm/cm2 1 | dec -k10`";
echo -e "0.3990146448 \n`./tgmconv -kX -i4^Go*Gf/Sf -oohm-1*cm/cm2 1 | dec -k10`";
echo -e "mho*m/m2 to 2^Edu:"
echo -e "3;7381E410 \n`./tgmconv -k8 -imho*m/m2 -o2^Edu 1`";
echo -e "3;7381E410 \n`./tgmconv -k8 -iS*m/m2 -o2^Edu 1`";
echo -e "3;7381E410 \n`./tgmconv -k8 -iohm-1*m/m2 -o2^Go*Gf/Sf 1`";
echo -e "mho*cm/cm2 to 4^Edu:"
echo -e "2;60180261 \n`./tgmconv -k8 -imho*cm/cm2 -o4^Edu 1`";
echo -e "2;60180261 \n`./tgmconv -k8 -iS*cm/cm2 -o4^Go*Gf/Sf 1`";
echo -e "2;60180261 \n`./tgmconv -k8 -iohm-1*cm/cm2 -o4^Go*Gf/Sf 1`";
echo -e "Im to m2/V*s:"
echo -e "0.000577998570 \n`./tgmconv -k10 -iIm -om2/V*s 1 | dec -k12`";
echo -e "0.000577998570 \n`./tgmconv -k10 -iVl/Egr -om2/V*s 1 | dec -k12`";
echo -e "Im to cm2/V*s:"
echo -e "5.7799857012 \n`./tgmconv -kX -iIm -ocm2/V*s 1 | dec -k10`";
echo -e "5.7799857012 \n`./tgmconv -kX -iVl/Egr -ocm2/V*s 1 | dec -k10`";
echo -e "m2/V*s to 3^Im:"
echo -e "1;00213693 \n`./tgmconv -k8 -im2/V*s -o3^Im 1`";
echo -e "1;00213693 \n`./tgmconv -k8 -im2/V*s -o3^Vl/Egr 1`";
echo -e "cm2/V*s to 1_Im:"
echo -e "2;0XE6760E \n`./tgmconv -k8 -icm2/V*s -o1_Im 1`";
echo -e "2;0XE6760E \n`./tgmconv -k8 -icm2/V*s -o1_Vl/Egr 1`";
echo -e "Qz to C/m2:"
echo -e "0.9843812093 \n`./tgmconv -kX -iQz -oC/m2 1 | dec -k10`";
echo -e "0.9843812093 \n`./tgmconv -kX -iQl/Sf -oC/m2 1 | dec -k10`";
echo -e "C/m2 to Qz:"
echo -e "1;02350153 \n`./tgmconv -k8 -iC/m2 -oQz 1`";
echo -e "1;02350153 \n`./tgmconv -k8 -iC/m2 -oQl/Sf 1`";
echo -e "Dp to kg/C:"
echo -e "300.365987195 \n`./tgmconv -k9 -iDp -okg/C 1 | dec -k9`";
echo -e "300.365987195 \n`./tgmconv -k9 -iMz/Ql -okg/C 1 | dec -k9`";
echo -e "6_Dp to g/C:"
echo -e "1.0059196138 \n`./tgmconv -kX -i6_Dp -og/C 1 | dec -k10`";
echo -e "1.0059196138 \n`./tgmconv -kX -i6_Mz/Ql -og/C 1 | dec -k10`";
echo -e "kg/C to 3_Dp:"
echo -e "5;90519E05 \n`./tgmconv -k8 -ikg/C -o3_Dp 1`";
echo -e "5;90519E05 \n`./tgmconv -k8 -ikg/C -o3_Mz/Ql 1`";
echo -e "g/C to 6_Dp:"
echo -e "0;EE19E819 \n`./tgmconv -k8 -ig/C -o6_Dp 1`";
echo -e "0;EE19E819 \n`./tgmconv -k8 -ig/C -o6_Mz/Ql 1`";
echo -e "Egr to kV/m:"
echo -e "2.9466051727 \n`./tgmconv -kX -iEgr -okV/m 1 | dec -k10`";
echo -e "2.9466051727 \n`./tgmconv -kX -iPl/Gf -okV/m 1 | dec -k10`";
echo -e "4_Egr to V/m:"
echo -e "0.1421009489 \n`./tgmconv -kX -i4_Egr -oV/m 1 | dec -k10`";
echo -e "0.1421009489 \n`./tgmconv -kX -i4_Pl/Gf -oV/m 1 | dec -k10`";
echo -e "kV/m to 1_Egr:"
echo -e "4;0X530174 \n`./tgmconv -k8 -ikV/m -o1_Egr 1`";
echo -e "4;0X530174 \n`./tgmconv -k8 -ikV/m -o1_Pl/Gf 1`";
echo -e "V/m to 4_Egr:"
echo -e "7;05445283 \n`./tgmconv -k8 -iV/m -o4_Egr 1`";
echo -e "7;05445283 \n`./tgmconv -k8 -iV/m -o4_Pl/Gf 1`";
echo -e "RFm to Wb*m:"
echo -e "44.7251616108 \n`./tgmconv -kX -iRFm -oWb*m 1 | dec -k10`";
echo -e "44.7251616108 \n`./tgmconv -kX -iFm*Gf -oWb*m 1 | dec -k10`";
echo -e "Wb*m to 2_RFm:"
echo -e "3;2776E581 \n`./tgmconv -k8 -iWb*m -o2_RFm 1`";
echo -e "3;2776E581 \n`./tgmconv -k8 -iWb*m -o2_Fm*Gf 1`";
echo -e "Mgr to At/m:"
echo -e "1.6765326896 \n`./tgmconv -kX -iMgr -oAt/m 1 | dec -k10`";
echo -e "1.6765326896 \n`./tgmconv -kX -iKn/Gf -oAt/m 1 | dec -k10`";
echo -e "At/m to 1_Mgr:"
echo -e "7;1X847356 \n`./tgmconv -k8 -iAt/m -o1_Mgr 1`";
echo -e "7;1X847356 \n`./tgmconv -k8 -iAt/m -o1_Kn/Gf 1`";
echo -e "Lq to lum*s:"
echo -e "0.2047911026 \n`./tgmconv -kX -iLq -olm*s 1 | dec -k10`";
echo -e "0.2047911026 \n`./tgmconv -kX -iLp*Tm -olm*s 1 | dec -k10`";
echo -e "lum*s to Lq:"
echo -e "4;X71X4954 \n`./tgmconv -k8 -ilm*s -oLq 1`";
echo -e "4;X71X4954 \n`./tgmconv -k8 -ilm*s -oLp*Tm 1`";
echo -e "PGf to diopt:"
echo -e "3.3820013177 \n`./tgmconv -kX -iPGf -odiopt 1 | dec -k10`";
echo -e "3.3820013177 \n`./tgmconv -kX -iGf-1 -om-1 1 | dec -k10`";
echo -e "diopt to 1_PGf:"
echo -e "3;66E34543 \n`./tgmconv -k8 -idiopt -o1_PGf 1`";
echo -e "Lf to lm/W:"
echo -e "2.7311599794e-03 \n`./tgmconv -ekX -iLf -olm/W 1 | dec -ek10`";
echo -e "2.7311599794e-03 \n`./tgmconv -ekX -iLp/Pv -olm/W 1 | dec -ek10`";
echo -e "5^Lf to lm/W:"
echo -e "679.6 \n`./tgmconv -kX -i5^Lf -olm/W 1 | dec -k10`";
echo -e "679.6 \n`./tgmconv -kX -i5^Lp/Pv -olm/W 1 | dec -k10`";
echo -e "lm/W to 2^Lf:"
echo -e "2;6618X247 \n`./tgmconv -k8 -ilm/W -o2^Lf 1`";
echo -e "2;6618X247 \n`./tgmconv -k8 -ilm/W -o2^Lp/Pv 1`";
echo -e "Osp to rad*m2/kg:"
echo -e "0.0033820960138 \n`./tgmconv -k11 -iOsp -orad*m2/kg 1 | dec -k13`";
echo -e "0.0033820960138 \n`./tgmconv -k11 -irGf/Gf*Dz -orad*m2/kg 1 | dec -k13`";
echo -e "Osp to rad*dm2/kg:"
echo -e "0.33820960138 \n`./tgmconv -kE -iOsp -orad*dm2/kg 1 | dec -k11`";
echo -e "0.33820960138 \n`./tgmconv -kE -irGf/Gf*Dz -orad*dm2/kg 1 | dec -k11`";
echo -e "rad*m2/kg to 2^Osp:"
echo -e "2;07811925 \n`./tgmconv -k8 -irad*m2/kg -o2^Osp 1`";
echo -e "2;07811925 \n`./tgmconv -k8 -irad*m2/kg -o2^rGf/Gf*Dz 1`";
echo -e "rad*dm2/kg to Osp:"
echo -e "2;E5931131 \n`./tgmconv -k8 -irad*dm2/kg -oOsp 1`";
echo -e "2;E5931131 \n`./tgmconv -k8 -irad*dm2/kg -orGf/Gf*Dz 1`";
echo -e "Mlz to kmol:"
echo -e "25.8503556494 \n`./tgmconv -kX -iMlz -okmol 1 | dec -k10`";
echo -e "4_Mlz to mol:"
echo -e "1.2466413797 \n`./tgmconv -kX -i4_Mlz -omol 1 | dec -k10`";
echo -e "kmol to 2_Mlz:"
echo -e "5;6X1X4457 \n`./tgmconv -k8 -ikmol -o2_Mlz 1`";
echo -e "mol to 5_Mlz:"
echo -e "9;7615XXEX \n`./tgmconv -k8 -imol -o5_Mlz 1`";
echo -e "Slz to mm2/mol:"
echo -e "3.3820960138 \n`./tgmconv -kX -iSlz -omm2/mol 1 | dec -k10`";
echo -e "3.3820960138 \n`./tgmconv -kX -iVlz/Gf -omm2/mol 1 | dec -k10`";
echo -e "2^Slz to cm2/mol:"
echo -e "4.8702182598 \n`./tgmconv -kX -i2^Slz -ocm2/mol 1 | dec -k10`";
echo -e "4.8702182598 \n`./tgmconv -kX -i2^Vlz/Gf -ocm2/mol 1 | dec -k10`";
echo -e "4^Slz to dm3/mol*cm:"
echo -e "0.7013114294 \n`./tgmconv -kX -i4^Slz -odm3/mol*cm 1 | dec -k10`";
echo -e "0.7013114294 \n`./tgmconv -kX -i4^Vlz/Gf -odm3/mol*cm 1 | dec -k10`";
echo -e "6^Slz to m2/mol:"
echo -e "10.0988845836 \n`./tgmconv -kX -i6^Slz -om2/mol 1 | dec -k10`";
echo -e "10.0988845836 \n`./tgmconv -kX -i6^Vlz/Gf -om2/mol 1 | dec -k10`";
echo -e "mm2/mol to 1_Slz:"
echo -e "3;66E13886 \n`./tgmconv -k8 -imm2/mol -o1_Slz 1`";
echo -e "cm2/mol to 1^Slz:"
echo -e "2;56986E07 \n`./tgmconv -k8 -icm2/mol -o1^Slz 1`";
echo -e "dm3/mol*cm to 4^Slz:"
echo -e "1;513E5688 \n`./tgmconv -k8 -idm3/mol*cm -o4^Slz 1`";
echo -e "1;513E5688 \n`./tgmconv -k8 -idm3/mol*cm -o4^Vlz/Gf 1`";
echo -e "m2/mol to 5^Slz:"
echo -e "1;23136773 \n`./tgmconv -k8 -im2/mol -o5^Slz 1`";
echo -e "1;23136773 \n`./tgmconv -k8 -im2/mol -o5^Vlz/Gf 1`";
echo -e "Vlz to cm3/mol:"
echo -e "1.000028 \n`./tgmconv -k6 -iVlz -ocm3/mol 1 | dec -k6`";
echo -e "1.000028 \n`./tgmconv -k6 -iVm/Mlz -ocm3/mol 1 | dec -k6`";
echo -e "6^Vlz to m3/mol:"
echo -e "2.9860676076 \n`./tgmconv -kX -i6^Vlz -om3/mol 1 | dec -k10`";
echo -e "2.9860676076 \n`./tgmconv -kX -i6^Vm/Mlz -om3/mol 1 | dec -k10`";
echo -e "cm3/mol to Vlz:"
echo -e "0;EEEE5049 \n`./tgmconv -k8 -icm3/mol -oVlz 1`";
echo -e "0;EEEE5049 \n`./tgmconv -k8 -icm3/mol -oVm/Mlz 1`";
echo -e "m3/mol to 5^Vlz:"
echo -e "4;0283 \n`./tgmconv -im3/mol -o5^Vlz 1`";
echo -e "4;0283 \n`./tgmconv -im3/mol -o5^Vm/Mlz 1`";
echo -e "Mlv to mol/dm3:"
echo -e "999.9720007840 \n`./tgmconv -kX -iMlv -omol/dm3 1 | dec -k10`";
echo -e "999.9720007840 \n`./tgmconv -kX -iMlz/Vm -omol/dm3 1 | dec -k10`";
echo -e "mol/dm3 to 3_Mlv:"
echo -e "1;88X0989E \n`./tgmconv -k8 -imol/dm3 -o3_Mlv 1`";
echo -e "1;88X0989E \n`./tgmconv -k8 -imol/dm3 -o3_Mlz/Vm 1`";
echo -e "Mlm to mol/kg:"
echo -e "1000.0 \n`./tgmconv -iMlm -omol/kg 1 | dec`";
echo -e "1000.0 \n`./tgmconv -iMlz/Mz -omol/kg 1 | dec`";
echo -e "mol/kg to 3_Mlm:"
echo -e "1;889E9843 \n`./tgmconv -imol/kg -o3_Mlm -k8 1`";
echo -e "1;889E9843 \n`./tgmconv -imol/kg -o3_Mlz/Mz -k8 1`";
echo -e "Wlz to J/kmol:"
echo -e "2.9006639794 \n`./tgmconv -kX -iWlz -o J/kmol 1 | dec -k10`";
echo -e "2.9006639794 \n`./tgmconv -kX -iWg/Mlz -o J/kmol 1 | dec -k10`";
echo -e "4^Wlz to J/mol:"
echo -e "60.1481682772 \n`./tgmconv -kX -i4^Wlz -oJ/mol 1 | dec -k10`";
echo -e "60.1481682772 \n`./tgmconv -kX -i4^Wg/Mlz -oJ/mol 1 | dec -k10`";
echo -e "6^Wlz to kJ/mol:"
echo -e "8.6613362319 \n`./tgmconv -kX -i6^Wlz -okJ/mol 1 | dec -k10`";
echo -e "8.6613362319 \n`./tgmconv -kX -i6^Wg/Mlz -okJ/mol 1 | dec -k10`";
echo -e "J/kmol to 1_Wlz:"
echo -e "4.17885167 \n`./tgmconv -k8 -iJ/kmol -o1_Wlz 1`";
echo -e "4.17885167 \n`./tgmconv -k8 -iJ/kmol -o1_Wg/Mlz 1`";
echo -e "J/mol to 2^Wlz:"
echo -e "2;488E980X \n`./tgmconv -k8 -iJ/mol -o2^Wlz 1`";
echo -e "2;488E980X \n`./tgmconv -k8 -iJ/mol -o2^Wg/Mlz 1`";
echo -e "kJ/mol to 5^Wlz:"
echo -e "1;476107X1 \n`./tgmconv -k8 -ikJ/mol -o5^Wlz 1`";
echo -e "1;476107X1 \n`./tgmconv -k8 -ikJ/mol -o5^Wg/Mlz 1`";
echo -e "Eul to S*cm2/kmol:"
echo -e "0.01924314319 \n`./tgmconv -kE -iEul -oS*cm2/kmol 1 | dec -k11`";
echo -e "0.01924314319 \n`./tgmconv -kE -iGo*Sf/Mlz -oS*cm2/kmol 1 | dec -k11`";
echo -e "4^Eul to S*cm2/mol:"
echo -e "0.3990258172 \n`./tgmconv -kX -i4^Eul -oS*cm2/mol 1 | dec -k10`";
echo -e "0.3990258172 \n`./tgmconv -kX -i4^Go*Sf/Mlz -oS*cm2/mol 1 | dec -k10`";
echo -e "8^Eul to S*m2/mol:"
echo -e "0.8274199345 \n`./tgmconv -kX -i8^Eul -oS*m2/mol 1 | dec -k10`";
echo -e "0.8274199345 \n`./tgmconv -kX -i8^Go*Sf/Mlz -oS*m2/mol 1 | dec -k10`";
echo -e "S*cm2/kmol to 1^Eul:"
echo -e "4;3E722778 \n`./tgmconv -k8 -iS*cm2/kmol -o1^Eul 1`";
echo -e "4;3E722778 \n`./tgmconv -k8 -iS*cm2/kmol -o1^Go*Sf/Mlz 1`";
echo -e "S*cm2/mol to 4^Eul:"
echo -e "2;60X668E8 \n`./tgmconv -k8 -iS*cm2/mol -o4^Eul 1`";
echo -e "2;60X668E8 \n`./tgmconv -k8 -iS*cm2/mol -o4^Go*Sf/Mlz 1`";
echo -e "S*m2/mol to 8^Eul:"
echo -e "1;26050507 \n`./tgmconv -k8 -iS*m2/mol -o8^Eul 1`";
echo -e "1;26050507 \n`./tgmconv -k8 -iS*m2/mol -o8^Go*Sf/Mlz 1`";
echo -e "Clz to J/K*mol:"
echo -e "4.1769561304 \n`./tgmconv -kX -iClz -oJ/K*mol 1 | dec -k10`";
echo -e "4.1769561304 \n`./tgmconv -kX -iWg/Cg*Mlz -oJ/K*mol 1 | dec -k10`";
echo -e "J/K*mol to 1_Clz:"
echo -e "2;X5846983 \n`./tgmconv -k8 -iJ/K*mol -o1_Clz 1`";
echo -e "2;X5846983 \n`./tgmconv -k8 -iJ/K*mol -o1_Wg/Cg*Mlz 1`";
echo -e "Olz to rad*mm2/mol:"
echo -e "3.3820960138 \n`./tgmconv -kX -iOlz -orad*mm2/mol 1 | dec -k10`";
echo -e "3.3820960138 \n`./tgmconv -kX -irGf*Vlz/Gf -orad*mm2/mol 1 | dec -k10`";
echo -e "6^Olz to rad*m2/mol:"
echo -e "10.0988845836 \n`./tgmconv -kX -i6^Olz -orad*m2/mol 1 | dec -k10`";
echo -e "10.0988845836 \n`./tgmconv -kX -i6^rGf*Vlz/Gf -orad*m2/mol 1 | dec -k10`";
echo -e "rad*mm2/mol to 1_Olz:"
echo -e "3;66E13886 \n`./tgmconv -k8 -irad*mm2/mol -o1_Olz 1`";
echo -e "3;66E13886 \n`./tgmconv -k8 -irad*mm2/mol -o1_rGf*Vlz/Gf 1`";
echo -e "rad*m2/mol to 5^Olz:"
echo -e "1;23136773 \n`./tgmconv -k8 -irad*m2/mol -o5^Olz 1`";
echo -e "1;23136773 \n`./tgmconv -k8 -irad*m2/mol -o5^rGf*Vlz/Gf 1`";
echo -e "Bq and Ci:"
echo -e "3.7e10 \n`./tgmconv -ek8 -iCi -os-1 1 | dec -ek8`";
echo -e "37 \n`./tgmconv -iCi -oGBq 1 | dec`";
echo -e "3.7 \n`./tgmconv -imCi -oGBq 84 | dec`";
echo -e "2.7e-11 \n`./tgmconv -e -iBq -oCi 1 | dec -e`";
echo -e "1;2E330765e9 \n`./tgmconv -ek8 -iCi -oTm-1 1`";
echo -e "1;2E330765e9 \n`doz 3.7e10 | ./tgmconv -iBq -oTm-1 -ek8`";
echo -e "1 \n`./tgmconv -iTm-1 -oCi \"1;2E330765e9\"`";
echo -e "3.7e10 \n`./tgmconv -ek8 -iTm-1 -oBq \"1;2E330765e9\" | dec -ek8`";
echo -e "Tmb to 2_Vm:"
echo -e "3 \n`./tgmconv -iTmb -o2_Vm 1`";
echo -e "Tmb to pti:"
echo -e "0.94774 \n`./tgmconv -iTmb -opti -k5 1 | dec -k5`";
echo -e "Tmb to ptc:"
echo -e "1.13818 \n`./tgmconv -iTmb -optc -k5 1 | dec -k5`";
echo -e "Tmb to L:"
echo -e "0.538549 \n`./tgmconv -iTmb -oL -k6 1 | dec -k6`";
echo -e "Qrt to 2_Vm:"
echo -e "6 \n`./tgmconv -iQrt -o2_Vm 1`";
echo -e "Qrt to pti:"
echo -e "1.89548 \n`./tgmconv -iQrt -opti -k5 1 | dec -k5`";
echo -e "Qrt to ptc:"
echo -e "2.27636 \n`./tgmconv -iQrt -optc -k5 1 | dec -k5`";
echo -e "Qrt to L:"
echo -e "1.077098 \n`./tgmconv -iQrt -oL -k6 1 | dec -k6`";
echo -e "Glv to 1_Vm:"
echo -e "2 \n`./tgmconv -iGlv -o1_Vm 1`";
echo -e "Glv to pti:"
echo -e "7.58192 \n`./tgmconv -iGlv -opti -k5 1 | dec -k5`";
echo -e "Glv to ptc:"
echo -e "9.10544 \n`./tgmconv -iGlv -optc -k5 1 | dec -k5`";
echo -e "Glv to L:"
echo -e "4.308392 \n`./tgmconv -iGlv -oL -k6 1 | dec -k6`";
echo -e "Oum to 3_Mz:"
echo -e "2 \n`./tgmconv -iOum  -o3_Mz 1`";
echo -e "28 \n`./tgmconv -iOum -o3_Mz 14`";
echo -e "Oum to 2_Mz:"
echo -e "6 \n`./tgmconv -iOum -o2_Mz 30`";
echo -e "Oum to 1_Mz:"
echo -e "3 \n`./tgmconv -iOum -o1_Mz 160`";
echo -e "Oum to Mz:"
echo -e "2 \n`./tgmconv -iOum -oMz 1000`";
echo -e "Oum to oz:"
echo -e "1.0553756 \n`./tgmconv -iOum -ooz -k7 1 | dec -k7`";
echo -e "Oum to lb:"
echo -e "1.0553756 \n`./tgmconv -iOum -olb -k7 14 | dec -k7`";
echo -e "Oum to kg:"
echo -e "1.077098 \n`./tgmconv -iOum -okg -k6 30 | dec -k6`";
echo -e "Oum to st:"
echo -e "1.01768 \n`./tgmconv -iOum -ost -k5 160 | dec -k5`";
echo -e "Oum to cwt:"
echo -e "1.01768 \n`./tgmconv -iOum -ocw -k5 1000 | dec -k5`";
echo -e "ePl to 25_Wg:"
echo -e "4;169150 \n`./tgmconv -iePl -o15_Wg -k6 1`";
echo -e "ePl to eV:"
echo -e "871.2608 \n`./tgmconv -iePl -oeV 1 | dec`";
echo -e "ePl to J:"
echo -e "1.3959244694e-16 \n`./tgmconv -iePl -oJ -ekX 1 | dec -ek10`";
echo -e "3^ePl to MeeV:"
echo -e "1.505538662 \n`./tgmconv -i3^ePl -oMeeV -kX 1 | dec -k10`";
echo -e "3^ePl to J:"
echo -e "2.4121574831e-13 \n`./tgmconv -i3^ePl -oJ -ekX 1 | dec -ek10`";
echo -e "MeeV to 2^ePl:"
echo -e "7;E79187E2 \n`./tgmconv -iMeeV -o2^ePl -k8 1`";
echo -e "Me to faraday:"
echo -e "25850.36 \n`./tgmconv -iMe -ofaraday -k8 1 | dec -k8`";
echo -e "Me to 9^Ql:"
echo -e "5;749690 \n`./tgmconv -iMe -o9^Ql -k8 1`";
echo -e "Me to C:"
echo -e "2.493358e09 \n`./tgmconv -iMe -oC -ek8 1 | dec -ek8`";
echo -e "degC to Do:"
echo -e "150 \n`doz 20.4 | ./tgmconv -idegC -oDo `";
echo -e "269 \n`doz 36.9 | ./tgmconv -idegC -oDo`";
echo -e "6E4;6 \n`doz 100.05 | ./tgmconv -idegC -oDo`";
echo -e "6E4 \n`doz 100 | ./tgmconv -idegC -oDo`";
echo -e "Do to degC:"
echo -e "100 \n`./tgmconv -iDo -odegC \"6E4;6\" | dec`";
echo -e "dK to 2^Cg:"
echo -e "2731.5 \n`./tgmconv -i2^Cg -odK \"16E7;6\" | dec`";
echo -e "273.15 \n`./tgmconv -i2^Cg -oK \"16E7;6\" | dec`";

exit;
