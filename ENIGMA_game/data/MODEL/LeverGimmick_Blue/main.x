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
 112;
 -16.79849;16.79849;19.72517;,
 -10.07910;16.79849;19.72517;,
 -10.07910;16.79849;2.92668;,
 -16.79849;16.79849;2.92668;,
 -3.35970;16.79849;19.72517;,
 -3.35970;16.79849;2.92668;,
 3.35970;16.79849;19.72517;,
 3.35970;16.79849;2.92668;,
 10.07910;16.79849;19.72517;,
 10.07910;16.79849;2.92668;,
 16.79849;16.79849;19.72517;,
 16.79849;16.79849;2.92668;,
 -10.07910;16.79849;-4.44988;,
 -16.79849;16.79849;-4.44988;,
 3.35970;16.79849;-4.44988;,
 -3.35970;16.79849;-4.44988;,
 16.79849;16.79849;-4.44988;,
 10.07910;16.79849;-4.44988;,
 -16.79849;-16.79849;2.92668;,
 -10.07910;-16.79849;2.92668;,
 -10.07910;-16.79849;19.72517;,
 -16.79849;-16.79849;19.72517;,
 -3.35970;-16.79849;2.92668;,
 -3.35970;-16.79849;19.72517;,
 3.35970;-16.79849;2.92668;,
 3.35970;-16.79849;19.72517;,
 10.07910;-16.79849;2.92668;,
 10.07910;-16.79849;19.72517;,
 16.79849;-16.79849;2.92668;,
 16.79849;-16.79849;19.72517;,
 -16.79849;-16.79849;-4.44988;,
 -10.07910;-16.79849;-4.44988;,
 -3.35970;-16.79849;-4.44988;,
 3.35970;-16.79849;-4.44988;,
 10.07910;-16.79849;-4.44988;,
 16.79849;-16.79849;-4.44988;,
 -3.35970;5.90735;-12.41443;,
 -3.35970;16.79849;-4.44988;,
 3.35970;16.79849;-4.44988;,
 3.35970;5.90735;-12.41443;,
 -3.35970;5.90735;5.41872;,
 3.35970;5.90735;5.41872;,
 -10.07910;5.90735;5.41872;,
 10.07910;5.90735;5.41872;,
 -10.07910;5.90735;-12.41443;,
 -10.07910;16.79849;-4.44988;,
 10.07910;16.79849;-4.44988;,
 10.07910;5.90735;-12.41443;,
 -16.79849;5.90735;-12.41443;,
 -16.79849;16.79849;-4.44988;,
 16.79849;16.79849;-4.44988;,
 16.79849;5.90735;-12.41443;,
 -16.79849;5.90735;-12.41443;,
 -16.79849;5.90735;5.41872;,
 -16.79849;16.79849;2.92668;,
 -16.79849;16.79849;-4.44988;,
 16.79849;5.90735;-12.41443;,
 16.79849;16.79849;-4.44988;,
 16.79849;16.79849;2.92668;,
 16.79849;5.90735;5.41872;,
 -16.79849;5.90735;19.72517;,
 16.79849;5.90735;19.72517;,
 -16.79849;5.90735;19.72517;,
 -10.07910;5.90735;19.72517;,
 -10.07910;16.79849;19.72517;,
 -16.79849;16.79849;19.72517;,
 16.79849;5.90735;19.72517;,
 16.79849;16.79849;19.72517;,
 10.07910;16.79849;19.72517;,
 10.07910;5.90735;19.72517;,
 -3.35970;5.90735;19.72517;,
 -3.35970;16.79849;19.72517;,
 3.35970;16.79849;19.72517;,
 3.35970;5.90735;19.72517;,
 -3.35970;-4.35724;-12.41443;,
 3.35970;-4.35724;-12.41443;,
 3.35970;-16.79849;-4.44988;,
 -3.35970;-16.79849;-4.44988;,
 -3.35970;-4.35724;5.41872;,
 3.35970;-4.35724;5.41872;,
 -10.07910;-4.35724;5.41872;,
 10.07910;-4.35724;5.41872;,
 -10.07910;-16.79849;-4.44988;,
 -10.07910;-4.35724;-12.41443;,
 10.07910;-4.35724;-12.41443;,
 10.07910;-16.79849;-4.44988;,
 -16.79849;-16.79849;-4.44988;,
 -16.79849;-4.35724;-12.41443;,
 16.79849;-4.35724;-12.41443;,
 16.79849;-16.79849;-4.44988;,
 -16.79849;-4.35724;-12.41443;,
 -16.79849;-16.79849;-4.44988;,
 -16.79849;-16.79849;2.92668;,
 -16.79849;-4.35724;5.41872;,
 16.79849;-4.35724;-12.41443;,
 16.79849;-4.35724;5.41872;,
 16.79849;-16.79849;2.92668;,
 16.79849;-16.79849;-4.44988;,
 -16.79849;-4.35724;19.72517;,
 16.79849;-4.35724;19.72517;,
 -16.79849;-4.35724;19.72517;,
 -16.79849;-16.79849;19.72517;,
 -10.07910;-16.79849;19.72517;,
 -10.07910;-4.35724;19.72517;,
 16.79849;-4.35724;19.72517;,
 10.07910;-4.35724;19.72517;,
 10.07910;-16.79849;19.72517;,
 16.79849;-16.79849;19.72517;,
 -3.35970;-16.79849;19.72517;,
 -3.35970;-4.35724;19.72517;,
 3.35970;-4.35724;19.72517;,
 3.35970;-16.79849;19.72517;;
 
 70;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;3,2,12,13;,
 4;5,7,14,15;,
 4;9,11,16,17;,
 4;18,19,20,21;,
 4;19,22,23,20;,
 4;22,24,25,23;,
 4;24,26,27,25;,
 4;26,28,29,27;,
 4;30,31,19,18;,
 4;32,33,24,22;,
 4;34,35,28,26;,
 4;36,37,38,39;,
 4;36,40,5,37;,
 4;39,38,7,41;,
 4;40,42,2,5;,
 4;41,7,9,43;,
 4;42,44,45,2;,
 4;43,9,46,47;,
 4;44,48,49,45;,
 4;47,46,50,51;,
 4;52,53,54,55;,
 4;56,57,58,59;,
 4;53,60,0,54;,
 4;59,58,10,61;,
 4;62,63,64,65;,
 4;66,67,68,69;,
 4;63,70,71,64;,
 4;69,68,72,73;,
 4;70,73,72,71;,
 4;74,36,39,75;,
 4;74,75,76,77;,
 4;74,77,22,78;,
 4;74,78,40,36;,
 4;75,39,41,79;,
 4;75,79,24,76;,
 4;78,22,19,80;,
 4;78,80,42,40;,
 4;79,41,43,81;,
 4;79,81,26,24;,
 4;80,19,82,83;,
 4;80,83,44,42;,
 4;81,43,47,84;,
 4;81,84,85,26;,
 4;83,82,86,87;,
 4;83,87,48,44;,
 4;84,47,51,88;,
 4;84,88,89,85;,
 4;90,91,92,93;,
 4;90,93,53,52;,
 4;94,56,59,95;,
 4;94,95,96,97;,
 4;93,92,21,98;,
 4;93,98,60,53;,
 4;95,59,61,99;,
 4;95,99,29,96;,
 4;100,101,102,103;,
 4;100,103,63,62;,
 4;104,66,69,105;,
 4;104,105,106,107;,
 4;103,102,108,109;,
 4;103,109,70,63;,
 4;105,69,73,110;,
 4;105,110,111,106;,
 4;109,108,111,110;,
 4;109,110,73,70;;
 
 MeshMaterialList {
  2;
  70;
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
   0.351373;0.351373;0.351373;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.047059;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  17;
  0.000000;0.891709;-0.452610;,
  0.000000;0.891709;-0.452610;,
  0.000000;-0.877256;-0.480023;,
  0.000000;-0.877256;-0.480023;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.310490;-0.950577;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.112234;-0.993682;,
  0.000000;0.310490;-0.950577;,
  0.000000;0.000000;1.000000;,
  0.000000;-0.280886;-0.959741;,
  0.000000;0.098683;-0.995119;,
  0.000000;-0.280886;-0.959741;,
  0.000000;-0.223049;-0.974807;,
  0.000000;0.196403;-0.980523;;
  70;
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,0,0;,
  4;4,4,1,1;,
  4;4,4,0,0;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;2,2,5,5;,
  4;3,3,5,5;,
  4;2,2,5,5;,
  4;6,1,1,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,15,15;,
  4;9,15,15,9;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;10,10,0,0;,
  4;10,0,0,10;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;12,6,6,12;,
  4;12,12,3,3;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;13,16,16,13;,
  4;13,13,9,9;,
  4;13,9,9,13;,
  4;13,13,16,16;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;14,2,2,14;,
  4;14,14,10,10;,
  4;14,10,10,14;,
  4;14,14,2,2;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;;
 }
 MeshTextureCoords {
  112;
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.500000;,
  0.000000;0.500000;,
  0.400000;0.000000;,
  0.400000;0.500000;,
  0.600000;0.000000;,
  0.600000;0.500000;,
  0.800000;0.000000;,
  0.800000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.200000;1.000000;,
  0.000000;1.000000;,
  0.600000;1.000000;,
  0.400000;1.000000;,
  1.000000;1.000000;,
  0.800000;1.000000;,
  0.000000;0.500000;,
  0.200000;0.500000;,
  0.200000;1.000000;,
  0.000000;1.000000;,
  0.400000;0.500000;,
  0.400000;1.000000;,
  0.600000;0.500000;,
  0.600000;1.000000;,
  0.800000;0.500000;,
  0.800000;1.000000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.400000;0.000000;,
  0.600000;0.000000;,
  0.800000;0.000000;,
  1.000000;0.000000;,
  0.400000;0.278939;,
  0.400000;0.000000;,
  0.600000;0.000000;,
  0.600000;0.278939;,
  0.400000;0.500000;,
  0.600000;0.500000;,
  0.200000;0.500000;,
  0.800000;0.500000;,
  0.200000;0.278939;,
  0.200000;0.000000;,
  0.800000;0.000000;,
  0.800000;0.278939;,
  0.000000;0.278939;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.278939;,
  1.000000;0.278939;,
  0.500000;0.278939;,
  0.500000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.278939;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.278939;,
  0.000000;0.278939;,
  1.000000;0.278939;,
  1.000000;0.278939;,
  0.800000;0.278939;,
  0.800000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.278939;,
  0.000000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.278939;,
  0.600000;0.278939;,
  0.600000;0.000000;,
  0.400000;0.000000;,
  0.400000;0.278939;,
  0.400000;0.674922;,
  0.600000;0.674922;,
  0.600000;1.000000;,
  0.400000;1.000000;,
  0.400000;0.500000;,
  0.600000;0.500000;,
  0.200000;0.500000;,
  0.800000;0.500000;,
  0.200000;1.000000;,
  0.200000;0.674922;,
  0.800000;0.674922;,
  0.800000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.674922;,
  1.000000;0.674922;,
  1.000000;1.000000;,
  1.000000;0.674922;,
  1.000000;1.000000;,
  0.500000;1.000000;,
  0.500000;0.674922;,
  0.000000;0.674922;,
  0.500000;0.674922;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.674922;,
  1.000000;0.674922;,
  1.000000;0.674922;,
  1.000000;1.000000;,
  0.800000;1.000000;,
  0.800000;0.674922;,
  0.000000;0.674922;,
  0.200000;0.674922;,
  0.200000;1.000000;,
  0.000000;1.000000;,
  0.600000;1.000000;,
  0.600000;0.674922;,
  0.400000;0.674922;,
  0.400000;1.000000;;
 }
}