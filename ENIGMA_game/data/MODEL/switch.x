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
 70;
 -10.30377;15.98120;-2.17541;,
 10.30377;15.98120;-2.17541;,
 10.30377;-15.98120;-2.17541;,
 -10.30377;-15.98120;-2.17541;,
 10.30377;15.98120;-2.17541;,
 10.30377;15.98120;2.58018;,
 10.30377;-15.98120;2.58018;,
 10.30377;-15.98120;-2.17541;,
 10.30377;15.98120;2.58018;,
 -10.30377;15.98120;2.58018;,
 -10.30377;-15.98120;2.58018;,
 10.30377;-15.98120;2.58018;,
 -10.30377;15.98120;2.58018;,
 -10.30377;15.98120;-2.17541;,
 -10.30377;-15.98120;-2.17541;,
 -10.30377;-15.98120;2.58018;,
 10.30377;15.98120;-2.17541;,
 -10.30377;15.98120;-2.17541;,
 -10.30377;-15.98120;-2.17541;,
 10.30377;-15.98120;-2.17541;,
 0.00000;-6.64328;-7.15466;,
 3.32164;-5.75325;-7.15466;,
 3.32164;-5.75326;-1.65900;,
 0.00000;-6.64329;-1.65901;,
 5.75325;-3.32164;-7.15466;,
 5.75325;-3.32164;-1.65901;,
 6.64328;0.00000;-7.15466;,
 6.64328;-0.00000;-1.65900;,
 5.75325;3.32164;-7.15466;,
 5.75325;3.32164;-1.65900;,
 3.32164;5.75326;-7.15466;,
 3.32164;5.75325;-1.65901;,
 0.00000;6.64329;-7.15466;,
 0.00000;6.64328;-1.65900;,
 -3.32164;5.75326;-7.15466;,
 -3.32164;5.75325;-1.65901;,
 -5.75325;3.32164;-7.15466;,
 -5.75325;3.32164;-1.65900;,
 -6.64328;0.00000;-7.15466;,
 -6.64328;0.00000;-1.65900;,
 -5.75326;-3.32164;-7.15466;,
 -5.75326;-3.32164;-1.65900;,
 -3.32165;-5.75325;-7.15466;,
 -3.32165;-5.75325;-1.65900;,
 0.00000;-6.64328;-7.15466;,
 0.00000;-6.64329;-1.65901;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;0.00000;-7.15466;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;,
 0.00000;-0.00000;-1.65901;;
 
 42;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,5,16,17;,
 4;18,19,6,15;,
 4;20,21,22,23;,
 4;21,24,25,22;,
 4;24,26,27,25;,
 4;26,28,29,27;,
 4;28,30,31,29;,
 4;30,32,33,31;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 3;46,21,20;,
 3;47,24,21;,
 3;48,26,24;,
 3;49,28,26;,
 3;50,30,28;,
 3;51,32,30;,
 3;52,34,32;,
 3;53,36,34;,
 3;54,38,36;,
 3;55,40,38;,
 3;56,42,40;,
 3;57,44,42;,
 3;58,23,22;,
 3;59,22,25;,
 3;60,25,27;,
 3;61,27,29;,
 3;62,29,31;,
 3;63,31,33;,
 3;64,33,35;,
 3;65,35,37;,
 3;66,37,39;,
 3;67,39,41;,
 3;68,41,43;,
 3;69,43,45;;
 
 MeshMaterialList {
  2;
  42;
  1,
  1,
  1,
  1,
  1,
  1,
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
   0.800000;0.000000;0.028235;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  39;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  -0.000000;-1.000000;-0.000000;,
  0.500000;-0.866026;-0.000000;,
  0.866026;-0.500000;-0.000000;,
  1.000000;0.000000;-0.000000;,
  0.866026;0.500000;0.000000;,
  0.500000;0.866026;0.000000;,
  0.000000;1.000000;0.000000;,
  -0.500000;0.866026;0.000000;,
  -0.866025;0.500000;0.000000;,
  -1.000000;0.000001;0.000000;,
  -0.866026;-0.499999;-0.000000;,
  -0.500000;-0.866025;-0.000000;,
  0.000000;0.000000;1.000000;,
  -0.000000;-0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  -0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;-0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  -0.000000;0.000000;1.000000;,
  -0.000000;-0.000000;1.000000;,
  -0.000000;-0.000000;1.000000;,
  -0.000000;0.000000;1.000000;,
  0.000000;-0.000000;1.000000;,
  -0.000000;-0.000000;1.000000;,
  -0.000000;-0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;1.000000;;
  42;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;7,8,8,7;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;10,11,11,10;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,7,7,18;,
  3;6,20,21;,
  3;6,22,20;,
  3;6,23,22;,
  3;6,21,23;,
  3;6,21,21;,
  3;6,21,21;,
  3;6,21,21;,
  3;6,21,21;,
  3;6,24,21;,
  3;6,25,24;,
  3;6,26,25;,
  3;6,21,26;,
  3;19,27,28;,
  3;19,28,29;,
  3;19,29,30;,
  3;19,30,31;,
  3;19,31,32;,
  3;19,32,33;,
  3;19,33,34;,
  3;19,34,35;,
  3;19,35,36;,
  3;19,36,37;,
  3;19,37,38;,
  3;19,38,27;;
 }
 MeshTextureCoords {
  70;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.083333;0.000000;,
  0.083333;1.000000;,
  0.000000;1.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.416667;0.000000;,
  0.416667;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.583333;0.000000;,
  0.583333;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  0.916667;0.000000;,
  0.916667;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.041667;0.000000;,
  0.125000;0.000000;,
  0.208333;0.000000;,
  0.291667;0.000000;,
  0.375000;0.000000;,
  0.458333;0.000000;,
  0.541667;0.000000;,
  0.625000;0.000000;,
  0.708333;0.000000;,
  0.791667;0.000000;,
  0.875000;0.000000;,
  0.958333;0.000000;,
  0.041667;1.000000;,
  0.125000;1.000000;,
  0.208333;1.000000;,
  0.291667;1.000000;,
  0.375000;1.000000;,
  0.458333;1.000000;,
  0.541667;1.000000;,
  0.625000;1.000000;,
  0.708333;1.000000;,
  0.791667;1.000000;,
  0.875000;1.000000;,
  0.958333;1.000000;;
 }
}