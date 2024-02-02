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
 86;
 -5.82449;32.05082;5.22832;,
 -7.12587;32.05082;0.15631;,
 -5.39561;0.29415;0.15631;,
 -3.80176;0.29415;4.00423;,
 0.04615;0.29415;5.59807;,
 0.04615;32.05082;7.32834;,
 -5.02585;32.05082;-4.91569;,
 -3.80176;0.29415;-3.69160;,
 3.89407;0.29415;4.00423;,
 5.11816;32.05082;5.22832;,
 0.04615;32.05082;-7.01572;,
 0.04615;0.29415;-5.28545;,
 5.48791;0.29415;0.15631;,
 7.21818;32.05082;0.15631;,
 0.04615;32.05082;-7.01572;,
 5.11834;32.05082;-4.91587;,
 3.89407;0.29415;-3.69160;,
 0.04615;0.29415;-5.28545;,
 -11.32854;34.87706;5.22832;,
 -18.13064;28.29059;5.22832;,
 -19.43202;26.10963;0.15631;,
 -12.62994;32.32843;0.15631;,
 -17.33200;28.29059;-4.91569;,
 -10.52991;34.87706;-4.91569;,
 -5.02585;34.50705;-10.29904;,
 -5.02585;31.98499;-16.97863;,
 0.04615;29.43623;-19.07866;,
 0.04615;34.50705;-12.39908;,
 0.04615;34.50705;-12.39908;,
 5.11816;31.98499;-16.97863;,
 5.11826;34.50705;-10.29913;,
 9.96775;35.08966;-4.91577;,
 16.01208;31.01736;-4.79315;,
 15.90346;27.99267;0.25610;,
 12.06770;32.18615;0.15631;,
 16.40273;30.91366;5.34280;,
 9.96768;35.08966;5.22832;,
 5.11816;33.97456;10.71394;,
 5.11816;32.14119;18.52082;,
 0.04615;32.14119;20.62085;,
 0.04615;32.90580;12.81396;,
 -5.82449;32.14119;18.52082;,
 -5.82449;33.97456;10.71394;,
 22.02443;26.14189;1.51277;,
 18.77784;27.58988;4.52649;,
 20.78028;28.42068;-1.77660;,
 21.82384;31.62562;-2.25835;,
 22.36965;30.96096;0.31790;,
 19.46057;30.08680;3.06563;,
 16.15989;34.37081;3.56765;,
 12.80598;36.71648;-3.93821;,
 17.69086;35.92393;0.78480;,
 11.17251;35.29333;2.78944;,
 10.67691;36.54249;-2.74319;,
 10.85711;35.78631;0.58064;,
 6.95424;34.86659;2.16181;,
 7.61559;34.29267;0.05846;,
 6.80535;35.14237;-3.34604;,
 0.04492;31.08936;0.23105;,
 4.39119;34.85620;18.15578;,
 1.48923;35.30177;20.11485;,
 -3.56193;34.89128;17.98616;,
 -3.12803;36.54431;15.15882;,
 0.49711;35.97527;15.79909;,
 -4.10849;36.42195;6.70137;,
 -1.45005;36.22782;6.89121;,
 4.25042;35.39638;12.08930;,
 3.13623;35.70100;7.52973;,
 -16.77137;32.10648;3.98100;,
 -22.61751;31.57443;0.27902;,
 -16.41578;35.76912;-3.10430;,
 -12.97133;36.38656;-2.84017;,
 -13.49956;36.22577;-0.02405;,
 -11.65538;35.60501;4.79959;,
 -5.42101;35.41379;2.40130;,
 -5.53473;36.47844;-2.74903;,
 -5.65387;36.26280;0.10494;,
 -6.76513;35.72516;-15.99468;,
 -1.75398;34.66499;-20.81401;,
 4.53892;34.21410;-16.71317;,
 4.28137;35.81923;-11.78741;,
 -1.77278;36.63089;-11.21728;,
 -3.67026;36.35487;-11.18217;,
 -2.61211;35.28677;-4.80888;,
 -1.05670;36.91059;-4.05785;,
 2.80352;35.19568;-5.76958;;
 
 86;
 4;0,1,2,3;,
 4;0,3,4,5;,
 4;1,6,7,2;,
 4;5,4,8,9;,
 4;6,10,11,7;,
 4;9,8,12,13;,
 4;14,15,16,17;,
 4;13,12,16,15;,
 4;18,19,20,21;,
 4;18,21,1,0;,
 4;21,20,22,23;,
 4;21,23,6,1;,
 4;24,25,26,27;,
 4;24,27,10,6;,
 4;28,26,29,30;,
 4;28,30,15,14;,
 4;31,32,33,34;,
 4;31,34,13,15;,
 4;34,33,35,36;,
 4;34,36,9,13;,
 4;37,38,39,40;,
 4;37,40,5,9;,
 4;40,39,41,42;,
 4;40,42,0,5;,
 4;33,43,44,35;,
 4;43,33,32,45;,
 4;45,46,47,43;,
 4;47,48,44,43;,
 4;48,49,35,44;,
 4;45,32,50,46;,
 4;50,51,47,46;,
 4;51,49,48,47;,
 4;49,52,36,35;,
 4;32,31,53,50;,
 4;54,52,49,51;,
 4;50,53,54,51;,
 4;52,55,9,36;,
 4;54,56,55,52;,
 4;54,53,57,56;,
 4;31,15,57,53;,
 3;56,58,55;,
 3;57,58,56;,
 3;55,58,9;,
 3;15,58,57;,
 4;38,59,60,39;,
 4;61,41,39,60;,
 4;61,62,42,41;,
 4;60,63,62,61;,
 4;62,64,0,42;,
 4;62,63,65,64;,
 4;60,59,66,63;,
 4;63,66,67,65;,
 4;59,38,37,66;,
 4;66,37,9,67;,
 3;65,58,64;,
 3;67,58,65;,
 3;58,67,9;,
 3;58,0,64;,
 4;19,68,69,20;,
 4;70,22,20,69;,
 4;70,71,23,22;,
 4;69,72,71,70;,
 4;69,68,73,72;,
 4;68,19,18,73;,
 4;18,0,74,73;,
 4;71,75,6,23;,
 4;74,76,72,73;,
 4;76,75,71,72;,
 3;76,58,75;,
 3;74,58,76;,
 3;0,58,74;,
 3;58,6,75;,
 4;25,77,78,26;,
 4;78,79,29,26;,
 4;79,80,30,29;,
 4;78,81,80,79;,
 4;78,77,82,81;,
 4;77,25,24,82;,
 4;82,83,84,81;,
 4;82,24,6,83;,
 4;84,85,80,81;,
 4;15,30,80,85;,
 3;58,15,85;,
 3;85,84,58;,
 3;84,83,58;,
 3;83,6,58;;
 
 MeshMaterialList {
  2;
  86;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  1,
  1,
  0,
  1,
  1,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  1,
  1,
  1,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  1,
  0,
  1,
  0,
  0,
  1,
  1,
  0;;
  Material {
   0.000000;0.501600;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.731200;0.458400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  122;
  -0.000011;-0.054416;-0.998518;,
  0.706059;-0.054422;-0.706059;,
  0.998518;-0.054418;0.000011;,
  0.706059;-0.054421;0.706059;,
  0.012272;-0.056134;0.998348;,
  -0.721657;-0.064752;0.689216;,
  -0.997535;-0.060560;-0.035435;,
  -0.706059;-0.054418;-0.706059;,
  -0.858081;0.167964;0.485268;,
  0.548771;-0.593162;0.589074;,
  0.632154;-0.391347;-0.668752;,
  -0.001798;-0.875104;0.483931;,
  0.000002;-0.875105;0.483933;,
  0.001802;-0.875103;0.483934;,
  0.676270;-0.718803;0.161189;,
  0.684270;-0.727284;0.053218;,
  0.684200;-0.727189;-0.055380;,
  0.034918;-0.985985;-0.163137;,
  0.002352;-0.986581;-0.163258;,
  -0.030216;-0.986129;-0.163205;,
  -0.391140;-0.812049;-0.433112;,
  -0.520638;-0.851528;-0.061938;,
  -0.568676;-0.763448;0.306195;,
  0.238496;-0.935113;0.262074;,
  0.250645;-0.967865;0.020367;,
  -0.096087;-0.994486;0.042003;,
  -0.000003;-0.999109;0.042198;,
  0.096081;-0.994487;0.042002;,
  -0.185075;-0.902416;-0.389092;,
  -0.200581;-0.979664;0.005093;,
  -0.183696;-0.898712;0.398213;,
  0.120526;-0.991935;0.039225;,
  0.007960;-0.999181;0.039685;,
  -0.104617;-0.993722;0.039639;,
  -0.371352;-0.918691;-0.134557;,
  -0.524291;-0.805245;0.276947;,
  -0.142064;-0.843257;-0.518397;,
  0.703515;-0.121764;-0.700171;,
  0.894048;-0.256636;-0.367172;,
  0.641197;0.315262;0.699626;,
  0.401781;0.671687;0.622422;,
  0.172910;0.346334;-0.922039;,
  0.363151;0.882177;0.299808;,
  -0.076977;0.953101;0.292700;,
  -0.189714;0.671699;-0.716120;,
  -0.159599;0.966192;0.202488;,
  -0.382267;0.922416;0.054956;,
  -0.361623;0.931393;0.041659;,
  -0.475971;0.865246;-0.157483;,
  -0.254081;0.878977;-0.403536;,
  0.808006;0.268070;0.524657;,
  0.092573;0.736017;0.670604;,
  -0.453198;0.719052;0.526855;,
  -0.452948;0.880797;0.137967;,
  0.104151;0.987969;0.114322;,
  -0.743400;0.533611;-0.403256;,
  0.135859;0.941940;-0.307070;,
  0.581612;0.813461;-0.003028;,
  0.428462;0.826113;-0.366002;,
  -0.587652;0.411312;0.696769;,
  -0.684575;0.419630;0.596043;,
  -0.496059;0.134006;-0.857885;,
  -0.041401;0.510127;-0.859102;,
  -0.188014;0.956589;0.222684;,
  -0.136674;0.764668;0.629764;,
  0.448720;0.744741;0.493975;,
  0.437779;0.823167;-0.361588;,
  0.370631;0.915677;0.155459;,
  -0.619861;-0.287926;-0.729980;,
  0.424273;0.048719;-0.904223;,
  0.696909;0.713456;0.072783;,
  -0.025470;0.997010;-0.072959;,
  0.130323;0.942431;0.307960;,
  -0.454454;0.888219;0.067366;,
  -0.662264;0.600324;0.448349;,
  0.541078;0.732308;0.413472;,
  -0.270424;-0.962544;-0.019475;,
  -0.216667;-0.938278;0.269612;,
  -0.254503;-0.907286;-0.334755;,
  -0.212286;-0.903414;-0.372528;,
  -0.000007;-0.909776;-0.415100;,
  0.169371;-0.896631;-0.409105;,
  0.305604;-0.952159;0.000007;,
  0.013327;-0.969561;0.244485;,
  0.651890;0.308240;0.692840;,
  0.655607;0.249298;0.712762;,
  0.686564;0.167728;0.707458;,
  0.452937;0.590392;0.668046;,
  0.350028;0.936711;0.007250;,
  0.635986;0.747440;-0.191978;,
  -0.034587;0.907280;0.419102;,
  -0.201177;0.949567;0.240520;,
  -0.420255;0.851490;0.313608;,
  -0.469661;0.669974;-0.574937;,
  0.074597;0.269398;0.960135;,
  -0.627352;0.530633;0.569964;,
  -0.819672;0.568618;0.069356;,
  0.113461;0.940837;-0.319301;,
  0.223636;0.970391;0.091262;,
  0.875988;0.478475;-0.060882;,
  0.656440;0.637357;-0.403563;,
  -0.534710;0.450785;-0.714758;,
  -0.591072;0.183645;0.785435;,
  -0.748515;-0.023956;0.662685;,
  -0.726567;-0.092405;-0.680853;,
  -0.309178;0.938522;0.153575;,
  -0.161359;0.980647;0.110884;,
  -0.042387;0.516685;0.855126;,
  0.469154;0.532346;0.704629;,
  0.428997;0.543966;-0.721153;,
  0.699646;0.649679;0.297343;,
  0.939172;0.330660;-0.092838;,
  0.853474;0.513848;0.086850;,
  0.051050;0.974765;-0.217319;,
  0.148026;0.956681;-0.250697;,
  -0.046480;0.982276;-0.181585;,
  -0.941180;0.124662;0.314069;,
  -0.878445;0.379968;0.289755;,
  -0.699922;0.534341;0.473907;,
  0.633345;0.625494;0.455667;,
  -0.677191;0.349076;0.647734;,
  -0.640990;0.388841;0.661766;;
  86;
  4;8,6,6,5;,
  4;8,5,4,4;,
  4;6,7,7,6;,
  4;4,4,3,9;,
  4;7,0,0,7;,
  4;9,3,2,2;,
  4;0,10,1,0;,
  4;2,2,1,10;,
  4;23,14,15,24;,
  4;23,24,76,77;,
  4;24,15,16,16;,
  4;24,78,79,76;,
  4;25,11,12,26;,
  4;25,26,80,79;,
  4;26,12,13,27;,
  4;26,27,81,80;,
  4;28,20,21,29;,
  4;28,29,82,10;,
  4;29,21,22,30;,
  4;29,30,9,82;,
  4;31,17,18,32;,
  4;31,32,83,9;,
  4;32,18,19,33;,
  4;32,33,77,83;,
  4;21,34,35,22;,
  4;34,21,20,36;,
  4;37,37,38,38;,
  4;84,39,85,86;,
  4;39,40,87,85;,
  4;37,41,41,37;,
  4;88,42,89,89;,
  4;42,40,39,84;,
  4;40,43,90,87;,
  4;41,44,44,41;,
  4;45,43,40,42;,
  4;88,91,45,42;,
  4;43,46,92,90;,
  4;45,47,46,43;,
  4;45,91,48,47;,
  4;44,93,48,44;,
  3;47,49,46;,
  3;48,49,47;,
  3;46,49,92;,
  3;93,49,48;,
  4;50,50,51,94;,
  4;52,95,94,51;,
  4;52,53,96,95;,
  4;51,54,53,52;,
  4;53,55,8,96;,
  4;53,54,56,97;,
  4;51,98,57,54;,
  4;54,57,58,56;,
  4;50,50,99,57;,
  4;57,99,100,58;,
  3;56,49,97;,
  3;58,49,56;,
  3;49,58,100;,
  3;49,101,55;,
  4;102,59,60,103;,
  4;61,61,104,104;,
  4;61,62,62,61;,
  4;105,63,106,105;,
  4;60,59,64,63;,
  4;59,102,107,64;,
  4;107,108,65,64;,
  4;62,66,109,62;,
  4;65,67,63,64;,
  4;67,66,106,63;,
  3;67,110,66;,
  3;65,110,67;,
  3;108,110,65;,
  3;110,109,66;,
  4;68,68,68,68;,
  4;69,69,69,69;,
  4;111,70,112,111;,
  4;113,71,114,114;,
  4;113,115,73,71;,
  4;116,116,117,116;,
  4;73,74,72,71;,
  4;73,117,118,74;,
  4;72,75,70,71;,
  4;119,112,70,75;,
  3;110,119,75;,
  3;75,72,110;,
  3;120,74,121;,
  3;74,118,121;;
 }
 MeshTextureCoords {
  86;
  0.625000;0.859610;,
  0.750000;0.859610;,
  0.750000;1.000000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.500000;0.859610;,
  0.875000;0.859610;,
  0.875000;1.000000;,
  0.375000;1.000000;,
  0.375000;0.859610;,
  1.000000;0.859610;,
  1.000000;1.000000;,
  0.250000;1.000000;,
  0.250000;0.859610;,
  0.000000;0.859610;,
  0.125000;0.859610;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.345460;0.475140;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.414550;0.475140;,
  0.000000;0.000000;,
  0.483650;0.475140;,
  0.484510;0.475990;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.553730;0.475990;,
  0.000000;0.475990;,
  0.000000;0.000000;,
  0.069220;0.475990;,
  0.061370;0.422060;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.122750;0.422060;,
  0.000000;0.000000;,
  0.184120;0.422060;,
  0.220240;0.504860;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.293660;0.504860;,
  0.000000;0.000000;,
  0.367070;0.504860;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
