xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 79;
 -0.22925;-3.73239;-0.90374;,
 -0.22925;0.46752;-2.71322;,
 -1.92247;0.20998;-2.37914;,
 -0.22925;-3.73239;-0.90374;,
 -2.62383;-0.28541;0.09075;,
 -0.22925;-3.73239;-0.90374;,
 -1.76938;-4.03195;1.77538;,
 -0.22925;-3.73239;-0.90374;,
 -0.22925;-4.03195;2.88511;,
 -0.22925;-3.73239;-0.90374;,
 1.31090;-4.03195;1.77538;,
 -0.22925;-3.73239;-0.90374;,
 2.16533;-0.28541;0.09075;,
 -0.22925;-3.73239;-0.90374;,
 1.46398;0.20998;-2.37914;,
 -0.22925;-3.73239;-0.90374;,
 -0.22925;0.46752;-2.71322;,
 -0.22925;-1.96638;-7.90461;,
 -3.07504;-1.96638;-5.85411;,
 -3.19811;-0.91463;-0.39379;,
 -2.32854;-0.35623;3.25802;,
 -0.22925;-0.35623;4.79381;,
 1.87006;-0.35623;3.25802;,
 2.73962;-0.91463;-0.39379;,
 2.61655;-1.96638;-5.85411;,
 -0.22925;-1.96638;-7.90461;,
 -0.22925;-3.24298;-10.05084;,
 -3.94746;-3.24298;-7.37170;,
 -5.01120;-3.24298;-0.90374;,
 -3.94746;-3.24298;5.59562;,
 -0.22925;-3.24298;6.98187;,
 3.48898;-3.24298;5.59562;,
 4.56505;-3.24298;-0.90374;,
 3.48898;-3.24298;-7.37170;,
 -0.22925;-3.24298;-10.05084;,
 -0.22871;-4.74734;-9.77892;,
 -3.90773;-4.74734;-7.34736;,
 -4.99612;-4.74734;-0.94761;,
 -3.90773;-4.74734;5.48087;,
 -0.22871;-4.74734;6.94986;,
 3.45029;-4.74734;5.48087;,
 4.54996;-4.74734;-0.94761;,
 3.45029;-4.74734;-7.34736;,
 -0.22871;-4.74734;-9.77892;,
 -0.22833;-4.74066;-8.78423;,
 -3.39806;-4.74066;-6.50031;,
 -4.30486;-4.74066;-0.98649;,
 -3.39806;-4.74066;4.55411;,
 -0.22833;-4.74066;5.73585;,
 2.94138;-4.74066;4.55411;,
 3.85873;-4.74066;-0.98649;,
 2.94138;-4.74066;-6.50031;,
 -0.22833;-4.74066;-8.78423;,
 -0.22833;-4.71449;-6.95462;,
 -2.65433;-4.71449;-5.20659;,
 -3.65922;-4.71449;-0.98649;,
 -2.65433;-4.71449;3.23362;,
 -0.22833;-4.71449;5.00841;,
 2.19766;-4.71449;3.23362;,
 3.20254;-4.71449;-0.98649;,
 2.19766;-4.71449;-5.20659;,
 -0.22833;-4.71449;-6.95462;,
 -0.22833;-4.72983;-4.21642;,
 -1.54128;-4.72983;-3.27039;,
 -2.08511;-4.72983;-0.98649;,
 -1.54128;-4.72983;1.29742;,
 -0.22833;-4.72983;2.24343;,
 1.08460;-4.72983;1.29742;,
 1.62845;-4.72983;-0.98649;,
 1.08460;-4.72983;-3.27039;,
 -0.22833;-4.72983;-4.21642;,
 -0.22833;-4.73937;-0.98649;,
 -0.22833;-4.73937;-0.98649;,
 -0.22833;-4.73937;-0.98649;,
 -0.22833;-4.73937;-0.98649;,
 -0.22833;-4.73937;-0.98649;,
 -0.22833;-4.73937;-0.98649;,
 -0.22833;-4.73937;-0.98649;,
 -0.22833;-4.73937;-0.98649;;
 
 64;
 3;0,1,2;,
 3;3,2,4;,
 3;5,4,6;,
 3;7,6,8;,
 3;9,8,10;,
 3;11,10,12;,
 3;13,12,14;,
 3;15,14,16;,
 4;1,17,18,2;,
 4;2,18,19,4;,
 4;4,19,20,6;,
 4;6,20,21,8;,
 4;8,21,22,10;,
 4;10,22,23,12;,
 4;12,23,24,14;,
 4;14,24,25,16;,
 4;17,26,27,18;,
 4;18,27,28,19;,
 4;19,28,29,20;,
 4;20,29,30,21;,
 4;21,30,31,22;,
 4;22,31,32,23;,
 4;23,32,33,24;,
 4;24,33,34,25;,
 4;26,35,36,27;,
 4;27,36,37,28;,
 4;28,37,38,29;,
 4;29,38,39,30;,
 4;30,39,40,31;,
 4;31,40,41,32;,
 4;32,41,42,33;,
 4;33,42,43,34;,
 4;35,44,45,36;,
 4;36,45,46,37;,
 4;37,46,47,38;,
 4;38,47,48,39;,
 4;39,48,49,40;,
 4;40,49,50,41;,
 4;41,50,51,42;,
 4;42,51,52,43;,
 4;44,53,54,45;,
 4;45,54,55,46;,
 4;46,55,56,47;,
 4;47,56,57,48;,
 4;48,57,58,49;,
 4;49,58,59,50;,
 4;50,59,60,51;,
 4;51,60,61,52;,
 4;53,62,63,54;,
 4;54,63,64,55;,
 4;55,64,65,56;,
 4;56,65,66,57;,
 4;57,66,67,58;,
 4;58,67,68,59;,
 4;59,68,69,60;,
 4;60,69,70,61;,
 3;62,71,63;,
 3;63,72,64;,
 3;64,73,65;,
 3;65,74,66;,
 3;66,75,67;,
 3;67,76,68;,
 3;68,77,69;,
 3;69,78,70;;
 
 MeshMaterialList {
  8;
  64;
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4;;
  Material {
   0.752800;0.602400;0.445600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.718431;0.718431;0.718431;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.771765;0.771765;0.771765;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.163200;0.401600;0.586400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.298039;0.235294;0.476863;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\Welcome2P.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\skirt001.png";
   }
  }
  Material {
   0.690400;0.636800;0.125600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  81;
  0.398418;0.640328;0.656691;,
  0.000000;0.395677;0.918390;,
  0.527136;0.487015;0.696379;,
  0.675428;0.674084;0.299012;,
  0.577222;0.768844;0.275125;,
  -0.000000;0.996889;0.078818;,
  -0.097728;0.994447;0.039030;,
  -0.675429;0.674082;0.299012;,
  -0.527137;0.487017;0.696378;,
  -0.000001;0.876908;-0.480659;,
  -0.550290;0.779170;-0.300124;,
  -0.775249;0.630583;-0.036795;,
  0.455670;0.779041;-0.430651;,
  0.542138;0.385383;-0.746704;,
  -0.455671;0.779040;-0.430652;,
  -0.249671;0.968329;-0.001624;,
  0.549782;0.779465;-0.300291;,
  -0.000001;0.859453;-0.511215;,
  -0.786242;0.398177;-0.472524;,
  -0.949436;0.313950;-0.002688;,
  -0.750837;0.341189;0.565539;,
  0.000001;0.347619;0.937636;,
  0.750243;0.341604;0.566076;,
  0.949074;0.315041;-0.002759;,
  0.785521;0.398800;-0.473197;,
  -0.565872;-0.086843;-0.819906;,
  -0.843008;-0.056376;-0.534938;,
  -0.999757;-0.022053;-0.000395;,
  -0.774644;-0.044207;0.630850;,
  0.000003;-0.053709;0.998557;,
  0.774093;-0.043897;0.631549;,
  0.999763;-0.021753;-0.000399;,
  0.842547;-0.055948;-0.535710;,
  -0.000001;-0.999948;0.010205;,
  0.014605;-0.999867;0.007288;,
  0.021898;-0.999760;0.000014;,
  0.014432;-0.999847;-0.009856;,
  0.000002;-0.999882;-0.015360;,
  -0.014348;-0.999849;-0.009838;,
  -0.021734;-0.999764;0.000015;,
  -0.014524;-0.999868;0.007280;,
  -0.000000;-0.999991;0.004350;,
  0.007613;-0.999965;0.003363;,
  0.012081;-0.999927;0.000005;,
  0.007984;-0.999950;-0.006042;,
  -0.000000;-0.999953;-0.009717;,
  -0.007894;-0.999951;-0.006027;,
  -0.011901;-0.999929;0.000005;,
  -0.007523;-0.999966;0.003349;,
  0.000000;-0.999991;-0.004278;,
  -0.005262;-0.999982;-0.003025;,
  -0.007441;-0.999972;-0.000000;,
  -0.005262;-0.999982;0.003015;,
  0.000000;-0.999991;0.004258;,
  0.005262;-0.999982;0.003015;,
  0.007441;-0.999972;-0.000000;,
  0.005262;-0.999982;-0.003025;,
  0.000000;-1.000000;0.000000;,
  -0.497660;0.836044;0.231008;,
  -0.056700;0.995285;0.078691;,
  -0.775666;0.397378;0.490340;,
  -0.000001;0.892818;-0.450417;,
  -0.525341;0.802909;-0.281700;,
  -0.741242;0.663700;-0.100311;,
  0.249664;0.968331;-0.001625;,
  -0.542134;0.385383;-0.746706;,
  0.741240;0.663703;-0.100309;,
  0.774435;0.631578;-0.036879;,
  0.525339;0.802910;-0.281699;,
  -0.625404;0.653139;0.426942;,
  -0.000001;0.691184;0.722679;,
  0.624736;0.653637;0.427157;,
  0.565892;-0.086449;-0.819934;,
  -0.000001;-0.999981;0.006109;,
  0.007093;-0.999967;0.003889;,
  0.009892;-0.999951;0.000020;,
  0.006006;-0.999975;-0.003687;,
  0.000004;-0.999984;-0.005724;,
  -0.006017;-0.999975;-0.003680;,
  -0.009923;-0.999951;0.000020;,
  -0.007110;-0.999967;0.003902;;
  64;
  3;0,1,2;,
  3;0,2,3;,
  3;0,3,4;,
  3;58,59,5;,
  3;0,5,6;,
  3;60,60,7;,
  3;58,7,8;,
  3;0,8,1;,
  4;61,9,10,62;,
  4;62,10,11,63;,
  4;3,64,12,4;,
  4;13,12,13,13;,
  4;65,65,14,65;,
  4;6,14,15,7;,
  4;66,67,16,68;,
  4;68,16,9,61;,
  4;9,17,18,10;,
  4;10,18,19,11;,
  4;11,19,20,69;,
  4;69,20,21,70;,
  4;70,21,22,71;,
  4;71,22,23,67;,
  4;67,23,24,16;,
  4;16,24,17,9;,
  4;25,25,26,18;,
  4;18,26,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;22,30,31,23;,
  4;23,31,32,24;,
  4;24,32,72,72;,
  4;73,33,34,74;,
  4;74,34,35,75;,
  4;75,35,36,76;,
  4;76,36,37,77;,
  4;77,37,38,78;,
  4;78,38,39,79;,
  4;79,39,40,80;,
  4;80,40,33,73;,
  4;33,41,42,34;,
  4;34,42,43,35;,
  4;35,43,44,36;,
  4;36,44,45,37;,
  4;37,45,46,38;,
  4;38,46,47,39;,
  4;39,47,48,40;,
  4;40,48,41,33;,
  4;41,49,50,42;,
  4;42,50,51,43;,
  4;43,51,52,44;,
  4;44,52,53,45;,
  4;45,53,54,46;,
  4;46,54,55,47;,
  4;47,55,56,48;,
  4;48,56,49,41;,
  3;49,57,50;,
  3;50,57,51;,
  3;51,57,52;,
  3;52,57,53;,
  3;53,57,54;,
  3;54,57,55;,
  3;55,57,56;,
  3;56,57,49;;
 }
 MeshTextureCoords {
  79;
  0.062500;0.000000;,
  0.000000;0.125000;,
  0.125000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.000000;0.250000;,
  0.125000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.000000;0.375000;,
  0.125000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.625000;,
  0.125000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.000000;0.750000;,
  0.125000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.000000;0.875000;,
  0.125000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
