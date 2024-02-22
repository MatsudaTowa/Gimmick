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
 60;
 -8.06973;19.11574;-2.87398;,
 -3.33333;20.25693;-4.30463;,
 -3.33333;3.70346;-4.30463;,
 -8.06973;8.68794;-2.87398;,
 3.33333;20.25693;-4.30463;,
 3.33333;3.70346;-4.30463;,
 8.06973;19.11574;-2.87398;,
 8.06973;8.68794;-2.87398;,
 8.06973;19.11574;-2.87398;,
 10.00000;19.11574;-1.43488;,
 10.00000;8.68794;-1.43488;,
 8.06973;8.68794;-2.87398;,
 10.00000;19.11574;1.43488;,
 10.00000;8.68794;1.43488;,
 8.06973;19.11574;2.87398;,
 8.06973;8.68794;2.87398;,
 8.06973;19.11574;2.87398;,
 3.33333;20.25693;4.30463;,
 3.33333;3.70346;4.30463;,
 8.06973;8.68794;2.87398;,
 -3.33333;20.25693;4.30463;,
 -3.33333;3.70346;4.30463;,
 -8.06973;19.11574;2.87398;,
 -8.06973;8.68794;2.87398;,
 -8.06973;19.11574;2.87398;,
 -10.00000;19.11574;1.43488;,
 -10.00000;8.68794;1.43488;,
 -8.06973;8.68794;2.87398;,
 -10.00000;19.11574;-1.43488;,
 -10.00000;8.68794;-1.43488;,
 -8.06973;19.11574;-2.87398;,
 -8.06973;8.68794;-2.87398;,
 -3.33333;20.25693;4.30463;,
 -3.33333;22.42384;1.43488;,
 -10.00000;19.11574;1.43488;,
 3.33333;20.25693;4.30463;,
 3.33333;22.42384;1.43488;,
 10.00000;19.11574;1.43488;,
 -3.33333;22.42384;-1.43488;,
 -10.00000;19.11574;-1.43488;,
 3.33333;22.42384;-1.43488;,
 10.00000;19.11574;-1.43488;,
 -3.33333;20.25693;-4.30463;,
 -8.06973;19.11574;-2.87398;,
 3.33333;20.25693;-4.30463;,
 8.06973;19.11574;-2.87398;,
 -10.00000;8.68794;1.43488;,
 -3.33333;0.00981;1.43488;,
 -3.33333;3.70346;4.30463;,
 3.33333;0.00981;1.43488;,
 3.33333;3.70346;4.30463;,
 10.00000;8.68794;1.43488;,
 -10.00000;8.68794;-1.43488;,
 -3.33333;0.00981;-1.43488;,
 3.33333;0.00981;-1.43488;,
 10.00000;8.68794;-1.43488;,
 -8.06973;8.68794;-2.87398;,
 -3.33333;3.70346;-4.30463;,
 3.33333;3.70346;-4.30463;,
 8.06973;8.68794;-2.87398;;
 
 30;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;16,17,18,19;,
 4;17,20,21,18;,
 4;20,22,23,21;,
 4;24,25,26,27;,
 4;25,28,29,26;,
 4;28,30,31,29;,
 4;24,32,33,34;,
 4;32,35,36,33;,
 4;35,14,37,36;,
 4;34,33,38,39;,
 4;33,36,40,38;,
 4;36,37,41,40;,
 4;39,38,42,43;,
 4;38,40,44,42;,
 4;40,41,45,44;,
 4;46,47,48,27;,
 4;47,49,50,48;,
 4;49,51,15,50;,
 4;52,53,47,46;,
 4;53,54,49,47;,
 4;54,55,51,49;,
 4;56,57,53,52;,
 4;57,58,54,53;,
 4;58,59,55,54;;
 
 MeshMaterialList {
  2;
  30;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.373333;0.373333;0.373333;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.483137;0.335686;0.238431;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  34;
  -0.459923;0.278475;-0.843162;,
  -0.185753;0.441166;-0.877991;,
  0.185753;0.441166;-0.877991;,
  -0.518396;-0.152978;-0.841346;,
  -0.243126;-0.286428;-0.926741;,
  0.243126;-0.286428;-0.926741;,
  0.459923;0.278475;-0.843162;,
  0.786918;0.304020;-0.536966;,
  0.749210;0.514674;0.416887;,
  0.518396;-0.152978;-0.841346;,
  0.856960;-0.300201;-0.418927;,
  0.856960;-0.300201;0.418927;,
  0.459923;0.278475;0.843162;,
  0.185753;0.441166;0.877991;,
  -0.185753;0.441166;0.877991;,
  0.518396;-0.152978;0.841346;,
  0.243126;-0.286428;0.926741;,
  -0.243126;-0.286428;0.926741;,
  -0.459923;0.278475;0.843162;,
  -0.749210;0.514674;0.416887;,
  -0.786918;0.304020;-0.536966;,
  -0.518396;-0.152978;0.841346;,
  -0.856960;-0.300201;0.418927;,
  -0.856960;-0.300201;-0.418927;,
  -0.217645;0.926726;0.306285;,
  0.217645;0.926726;0.306285;,
  -0.217645;0.926726;-0.306285;,
  0.217645;0.926726;-0.306285;,
  -0.418651;-0.797254;0.434877;,
  0.418651;-0.797254;0.434877;,
  -0.418651;-0.797254;-0.434877;,
  0.418651;-0.797254;-0.434876;,
  -0.444500;0.895779;0.000000;,
  0.444500;0.895779;0.000000;;
  30;
  4;0,1,4,3;,
  4;1,2,5,4;,
  4;2,6,9,5;,
  4;6,7,10,9;,
  4;7,8,11,10;,
  4;8,12,15,11;,
  4;12,13,16,15;,
  4;13,14,17,16;,
  4;14,18,21,17;,
  4;18,19,22,21;,
  4;19,20,23,22;,
  4;20,0,3,23;,
  4;18,14,24,19;,
  4;14,13,25,24;,
  4;13,12,8,25;,
  4;19,24,26,32;,
  4;24,25,27,26;,
  4;25,8,33,27;,
  4;20,26,1,0;,
  4;26,27,2,1;,
  4;27,7,6,2;,
  4;22,28,17,21;,
  4;28,29,16,17;,
  4;29,11,15,16;,
  4;23,30,28,22;,
  4;30,31,29,28;,
  4;31,10,11,29;,
  4;3,4,30,23;,
  4;4,5,31,30;,
  4;5,9,10,31;;
 }
 MeshTextureCoords {
  60;
  0.000000;0.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.000000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.000000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.000000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.000000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;0.333333;,
  0.000000;0.333333;,
  0.666667;0.000000;,
  0.666667;0.333333;,
  1.000000;0.333333;,
  0.333333;0.666667;,
  0.000000;0.666667;,
  0.666667;0.666667;,
  1.000000;0.666667;,
  0.333333;1.000000;,
  0.000000;1.000000;,
  0.666667;1.000000;,
  1.000000;1.000000;,
  0.000000;0.666667;,
  0.333333;0.666667;,
  0.333333;1.000000;,
  0.666667;0.666667;,
  0.666667;1.000000;,
  1.000000;0.666667;,
  0.000000;0.333333;,
  0.333333;0.333333;,
  0.666667;0.333333;,
  1.000000;0.333333;,
  0.000000;0.000000;,
  0.333333;0.000000;,
  0.666667;0.000000;,
  1.000000;0.000000;;
 }
}
