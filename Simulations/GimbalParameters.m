clc
clear all
%Inercias Tilting [kg*m2]
ITx=0.00016769;  
ITy=0.00017817;
ITz=0.00011559;
%Inercias Panning [kg*m2]
IPx=0.00261671;
IPy=0.00247003;
IPz=0.00046644;
%Coeficientes de friccion viscosa [Nm/rad/s]
KTvf=0.0052;
KPvf=0.0052;
%Coeficientes de friccion Coulomb [sin unidades]
KTcf=0.0036;
KPcf=0.0036;
%Control Tilting
cT=500;
rhoT=70;
epsilonT=0.001;
%Control Panning
cP=500;
rhoP=50;
epsilonP=0.001;
%Motor Tilt
R=19.8;
KM=0.0114;%Nm/A
KE=0.0001246;%V/rad/s
L=0.00025;
J=0.000000065;