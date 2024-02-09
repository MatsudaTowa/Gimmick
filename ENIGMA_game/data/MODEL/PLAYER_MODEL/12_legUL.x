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
 82;
 0.15264;0.11530;0.39763;,
 0.15264;0.11530;-2.16821;,
 -1.63472;0.11530;-1.41670;,
 -2.37507;0.11530;0.39763;,
 -1.63472;0.11530;2.21195;,
 0.15264;0.11530;2.96346;,
 1.94000;0.11530;2.21195;,
 2.68035;0.11530;0.39763;,
 1.94000;0.11530;-1.41670;,
 0.15264;0.00737;-2.41367;,
 -1.80572;0.00737;-1.59027;,
 -2.61690;0.00737;0.39763;,
 -1.80572;0.00737;2.38552;,
 0.15264;0.00737;3.20892;,
 2.11101;0.00737;2.38552;,
 2.92219;0.00737;0.39763;,
 2.11101;0.00737;-1.59027;,
 0.15264;-0.29993;-2.62177;,
 -1.95070;-0.29993;-1.73741;,
 -2.82193;-0.29993;0.39763;,
 -1.95070;-0.29993;2.53266;,
 0.15264;-0.29993;3.41703;,
 2.25599;-0.29993;2.53266;,
 3.12721;-0.29993;0.39763;,
 2.25599;-0.29993;-1.73741;,
 0.15264;-0.75986;-2.76083;,
 -2.04755;-0.75986;-1.83573;,
 -2.95891;-0.75986;0.39763;,
 -2.04755;-0.75986;2.63099;,
 0.15264;-0.75986;3.55609;,
 2.35283;-0.75986;2.63099;,
 3.26419;-0.75986;0.39763;,
 2.35283;-0.75986;-1.83573;,
 0.15264;-1.30235;-2.80965;,
 -2.08158;-1.30235;-1.87027;,
 -3.00701;-1.30235;0.39763;,
 -2.08158;-1.30235;2.66552;,
 0.15264;-1.30235;3.60491;,
 2.38686;-1.30235;2.66552;,
 3.31230;-1.30235;0.39763;,
 2.38686;-1.30235;-1.87027;,
 0.15264;-12.64362;-2.80965;,
 -2.08158;-12.64362;-1.87027;,
 -3.00701;-12.64362;0.39763;,
 -2.08158;-12.64362;2.66552;,
 0.15264;-12.64362;3.60491;,
 2.38686;-12.64362;2.66552;,
 3.31230;-12.64362;0.39763;,
 2.38686;-12.64362;-1.87027;,
 0.15264;-13.18614;-2.76083;,
 -2.04755;-13.18614;-1.83573;,
 -2.95891;-13.18614;0.39763;,
 -2.04755;-13.18614;2.63099;,
 0.15264;-13.18614;3.55609;,
 2.35283;-13.18614;2.63099;,
 3.26419;-13.18614;0.39763;,
 2.35283;-13.18614;-1.83573;,
 0.15264;-13.64605;-2.62177;,
 -1.95070;-13.64605;-1.73741;,
 -2.82193;-13.64605;0.39763;,
 -1.95070;-13.64605;2.53266;,
 0.15264;-13.64605;3.41703;,
 2.25599;-13.64605;2.53266;,
 3.12721;-13.64605;0.39763;,
 2.25599;-13.64605;-1.73741;,
 0.15264;-13.95334;-2.41367;,
 -1.80572;-13.95334;-1.59027;,
 -2.61690;-13.95334;0.39763;,
 -1.80572;-13.95334;2.38552;,
 0.15264;-13.95334;3.20892;,
 2.11101;-13.95334;2.38552;,
 2.92219;-13.95334;0.39763;,
 2.11101;-13.95334;-1.59027;,
 0.15264;-14.06128;-2.16821;,
 -1.63472;-14.06128;-1.41670;,
 -2.37507;-14.06128;0.39763;,
 -1.63472;-14.06128;2.21195;,
 0.15264;-14.06128;2.96346;,
 1.94000;-14.06128;2.21195;,
 2.68035;-14.06128;0.39763;,
 1.94000;-14.06128;-1.41670;,
 0.15264;-14.06128;0.39763;;
 
 88;
 3;0,1,2;,
 3;0,2,3;,
 3;0,3,4;,
 3;0,4,5;,
 3;0,5,6;,
 3;0,6,7;,
 3;0,7,8;,
 3;0,8,1;,
 4;1,9,10,2;,
 4;2,10,11,3;,
 4;3,11,12,4;,
 4;4,12,13,5;,
 4;5,13,14,6;,
 4;6,14,15,7;,
 4;7,15,16,8;,
 4;8,16,9,1;,
 4;9,17,18,10;,
 4;10,18,19,11;,
 4;11,19,20,12;,
 4;12,20,21,13;,
 4;13,21,22,14;,
 4;14,22,23,15;,
 4;15,23,24,16;,
 4;16,24,17,9;,
 4;17,25,26,18;,
 4;18,26,27,19;,
 4;19,27,28,20;,
 4;20,28,29,21;,
 4;21,29,30,22;,
 4;22,30,31,23;,
 4;23,31,32,24;,
 4;24,32,25,17;,
 4;25,33,34,26;,
 4;26,34,35,27;,
 4;27,35,36,28;,
 4;28,36,37,29;,
 4;29,37,38,30;,
 4;30,38,39,31;,
 4;31,39,40,32;,
 4;32,40,33,25;,
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
 4;49,57,58,50;,
 4;50,58,59,51;,
 4;51,59,60,52;,
 4;52,60,61,53;,
 4;53,61,62,54;,
 4;54,62,63,55;,
 4;55,63,64,56;,
 4;56,64,57,49;,
 4;57,65,66,58;,
 4;58,66,67,59;,
 4;59,67,68,60;,
 4;60,68,69,61;,
 4;61,69,70,62;,
 4;62,70,71,63;,
 4;63,71,72,64;,
 4;64,72,65,57;,
 4;65,73,74,66;,
 4;66,74,75,67;,
 4;67,75,76,68;,
 4;68,76,77,69;,
 4;69,77,78,70;,
 4;70,78,79,71;,
 4;71,79,80,72;,
 4;72,80,73,65;,
 3;73,81,74;,
 3;74,81,75;,
 3;75,81,76;,
 3;76,81,77;,
 3;77,81,78;,
 3;78,81,79;,
 3;79,81,80;,
 3;80,81,73;;
 
 MeshMaterialList {
  7;
  88;
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
  0;;
  Material {
   0.752800;0.602400;0.445600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.178824;0.178824;0.178824;1.000000;;
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
   0.476863;0.075294;0.059608;1.000000;;
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
    "C:\\Users\\student\\Downloads\\Welcome.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\skirt.png";
   }
  }
 }
 MeshNormals {
  82;
  0.000000;1.000000;0.000000;,
  -0.000000;0.978933;-0.204182;,
  -0.146373;0.978646;-0.144319;,
  -0.206917;0.978359;0.000000;,
  -0.146373;0.978645;0.144319;,
  0.000000;0.978933;0.204184;,
  0.146371;0.978646;0.144319;,
  0.206914;0.978359;0.000000;,
  0.146371;0.978646;-0.144318;,
  -0.000000;0.772087;-0.635517;,
  -0.453991;0.770003;-0.448316;,
  -0.640530;0.767933;0.000000;,
  -0.453992;0.770003;0.448317;,
  -0.000000;0.772086;0.635518;,
  0.453992;0.770002;0.448317;,
  0.640531;0.767932;0.000000;,
  0.453991;0.770003;-0.448316;,
  0.000000;0.431158;-0.902277;,
  -0.642470;0.428603;-0.635241;,
  -0.904686;0.426078;0.000000;,
  -0.642470;0.428603;0.635241;,
  0.000000;0.431159;0.902276;,
  0.642472;0.428600;0.635242;,
  0.904689;0.426072;0.000000;,
  0.642472;0.428600;-0.635242;,
  0.000000;0.190798;-0.981629;,
  -0.698026;0.189435;-0.690561;,
  -0.982152;0.188091;0.000000;,
  -0.698026;0.189434;0.690561;,
  0.000000;0.190796;0.981630;,
  0.698026;0.189434;0.690561;,
  0.982152;0.188091;0.000000;,
  0.698026;0.189435;-0.690561;,
  0.000000;0.044885;-0.998992;,
  -0.710137;0.044553;-0.702653;,
  -0.999022;0.044226;0.000000;,
  -0.710137;0.044552;0.702653;,
  0.000000;0.044883;0.998992;,
  0.710137;0.044553;0.702653;,
  0.999021;0.044228;0.000000;,
  0.710137;0.044554;-0.702653;,
  0.000000;-0.044882;-0.998992;,
  -0.710137;-0.044551;-0.702653;,
  -0.999022;-0.044224;0.000000;,
  -0.710137;-0.044550;0.702653;,
  0.000000;-0.044880;0.998992;,
  0.710137;-0.044551;0.702653;,
  0.999022;-0.044226;0.000000;,
  0.710137;-0.044552;-0.702653;,
  0.000000;-0.190801;-0.981629;,
  -0.698025;-0.189438;-0.690561;,
  -0.982151;-0.188094;0.000000;,
  -0.698025;-0.189437;0.690561;,
  0.000000;-0.190799;0.981629;,
  0.698026;-0.189437;0.690561;,
  0.982151;-0.188094;0.000000;,
  0.698025;-0.189438;-0.690560;,
  0.000000;-0.431176;-0.902268;,
  -0.642464;-0.428621;-0.635235;,
  -0.904678;-0.426096;0.000000;,
  -0.642464;-0.428621;0.635235;,
  0.000000;-0.431176;0.902268;,
  0.642466;-0.428617;0.635236;,
  0.904681;-0.426090;0.000000;,
  0.642466;-0.428617;-0.635236;,
  -0.000000;-0.772068;-0.635540;,
  -0.454008;-0.769984;-0.448332;,
  -0.640553;-0.767914;0.000000;,
  -0.454008;-0.769983;0.448333;,
  -0.000000;-0.772067;0.635541;,
  0.454008;-0.769983;0.448333;,
  0.640554;-0.767913;0.000000;,
  0.454008;-0.769983;-0.448333;,
  -0.000000;-0.978925;-0.204222;,
  -0.146401;-0.978637;-0.144347;,
  -0.206957;-0.978350;-0.000000;,
  -0.146402;-0.978637;0.144348;,
  -0.000000;-0.978924;0.204223;,
  0.146400;-0.978637;0.144347;,
  0.206954;-0.978351;0.000000;,
  0.146400;-0.978637;-0.144346;,
  0.000000;-1.000000;-0.000000;;
  88;
  3;0,1,2;,
  3;0,2,3;,
  3;0,3,4;,
  3;0,4,5;,
  3;0,5,6;,
  3;0,6,7;,
  3;0,7,8;,
  3;0,8,1;,
  4;1,9,10,2;,
  4;2,10,11,3;,
  4;3,11,12,4;,
  4;4,12,13,5;,
  4;5,13,14,6;,
  4;6,14,15,7;,
  4;7,15,16,8;,
  4;8,16,9,1;,
  4;9,17,18,10;,
  4;10,18,19,11;,
  4;11,19,20,12;,
  4;12,20,21,13;,
  4;13,21,22,14;,
  4;14,22,23,15;,
  4;15,23,24,16;,
  4;16,24,17,9;,
  4;17,25,26,18;,
  4;18,26,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;22,30,31,23;,
  4;23,31,32,24;,
  4;24,32,25,17;,
  4;25,33,34,26;,
  4;26,34,35,27;,
  4;27,35,36,28;,
  4;28,36,37,29;,
  4;29,37,38,30;,
  4;30,38,39,31;,
  4;31,39,40,32;,
  4;32,40,33,25;,
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
  4;49,57,58,50;,
  4;50,58,59,51;,
  4;51,59,60,52;,
  4;52,60,61,53;,
  4;53,61,62,54;,
  4;54,62,63,55;,
  4;55,63,64,56;,
  4;56,64,57,49;,
  4;57,65,66,58;,
  4;58,66,67,59;,
  4;59,67,68,60;,
  4;60,68,69,61;,
  4;61,69,70,62;,
  4;62,70,71,63;,
  4;63,71,72,64;,
  4;64,72,65,57;,
  4;65,73,74,66;,
  4;66,74,75,67;,
  4;67,75,76,68;,
  4;68,76,77,69;,
  4;69,77,78,70;,
  4;70,78,79,71;,
  4;71,79,80,72;,
  4;72,80,73,65;,
  3;73,81,74;,
  3;74,81,75;,
  3;75,81,76;,
  3;76,81,77;,
  3;77,81,78;,
  3;78,81,79;,
  3;79,81,80;,
  3;80,81,73;;
 }
 MeshTextureCoords {
  82;
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