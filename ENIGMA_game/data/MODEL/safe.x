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
 76;
 -33.96114;51.11845;-31.49157;,
 -29.54807;51.11845;-31.49157;,
 -29.54807;46.97684;-31.49157;,
 -33.96114;46.97684;-31.49157;,
 24.60893;51.11845;-31.49157;,
 24.60893;46.97684;-31.49157;,
 34.15058;51.11845;-31.49157;,
 34.15058;46.97684;-31.49157;,
 -29.54807;4.10994;-31.49157;,
 -33.96114;4.10994;-31.49157;,
 -29.54807;46.97684;-31.49157;,
 24.60893;46.97684;-31.49157;,
 24.60893;4.10994;-31.49157;,
 -29.54807;4.10994;-31.49157;,
 34.15058;4.10994;-31.49157;,
 24.60893;4.10994;-31.49157;,
 -29.54807;-0.03166;-31.49157;,
 -33.96114;-0.03166;-31.49157;,
 24.60893;-0.03166;-31.49157;,
 34.15058;-0.03166;-31.49157;,
 34.15058;51.11845;-31.49157;,
 34.15058;51.11845;31.49157;,
 34.15058;46.97684;31.49157;,
 34.15058;46.97684;-31.49157;,
 34.15058;4.10994;31.49157;,
 34.15058;4.10994;-31.49157;,
 34.15058;-0.03166;31.49157;,
 34.15058;-0.03166;-31.49157;,
 34.15058;51.11845;31.49157;,
 24.60893;51.11845;31.49157;,
 24.60893;46.97684;31.49157;,
 34.15058;46.97684;31.49157;,
 -29.54807;51.11845;31.49157;,
 -29.54807;46.97684;31.49157;,
 -33.96114;51.11845;31.49157;,
 -33.96114;46.97684;31.49157;,
 24.60893;4.10994;31.49157;,
 34.15058;4.10994;31.49157;,
 -29.54807;4.10994;31.49157;,
 -33.96114;4.10994;31.49157;,
 24.60893;-0.03166;31.49157;,
 34.15058;-0.03166;31.49157;,
 -29.54807;-0.03166;31.49157;,
 -33.96114;-0.03166;31.49157;,
 -33.96114;51.11845;31.49157;,
 -33.96114;51.11845;-31.49157;,
 -33.96114;46.97684;-31.49157;,
 -33.96114;46.97684;31.49157;,
 -33.96114;4.10994;-31.49157;,
 -33.96114;4.10994;31.49157;,
 -33.96114;-0.03166;-31.49157;,
 -33.96114;-0.03166;31.49157;,
 -29.54807;51.11845;31.49157;,
 -29.54807;51.11845;-31.49157;,
 -33.96114;51.11845;-31.49157;,
 24.60893;51.11845;31.49157;,
 24.60893;51.11845;-31.49157;,
 34.15058;51.11845;-31.49157;,
 -33.96114;-0.03166;-31.49157;,
 -29.54807;-0.03166;-31.49157;,
 -29.54807;-0.03166;31.49157;,
 24.60893;-0.03166;-31.49157;,
 24.60893;-0.03166;31.49157;,
 34.15058;-0.03166;-31.49157;,
 29.51654;12.80648;-28.64968;,
 30.84642;10.50307;-28.64968;,
 30.84642;17.79722;-35.48373;,
 29.51654;18.94893;-33.48890;,
 28.18666;10.50308;-28.64968;,
 28.18666;17.79722;-35.48373;,
 30.84642;32.38553;-35.48373;,
 29.51654;31.23383;-33.48890;,
 28.18666;32.38553;-35.48373;,
 30.84642;39.67968;-28.64968;,
 29.51654;37.37628;-28.64968;,
 28.18666;39.67969;-28.64968;;
 
 39;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;3,2,8,9;,
 4;10,11,12,13;,
 4;5,7,14,15;,
 4;9,8,16,17;,
 4;8,15,18,16;,
 4;15,14,19,18;,
 4;20,21,22,23;,
 4;23,22,24,25;,
 4;25,24,26,27;,
 4;28,29,30,31;,
 4;29,32,33,30;,
 4;32,34,35,33;,
 4;31,30,36,37;,
 4;30,33,38,36;,
 4;33,35,39,38;,
 4;37,36,40,41;,
 4;36,38,42,40;,
 4;38,39,43,42;,
 4;44,45,46,47;,
 4;47,46,48,49;,
 4;49,48,50,51;,
 4;44,52,53,54;,
 4;52,55,56,53;,
 4;55,21,57,56;,
 4;58,59,60,51;,
 4;59,61,62,60;,
 4;61,63,26,62;,
 4;64,65,66,67;,
 4;65,68,69,66;,
 4;68,64,67,69;,
 4;67,66,70,71;,
 4;66,69,72,70;,
 4;69,67,71,72;,
 4;71,70,73,74;,
 4;70,72,75,73;,
 4;72,71,74,75;;
 
 MeshMaterialList {
  2;
  39;
  0,
  0,
  0,
  0,
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
  0;;
  Material {
   0.401569;0.316863;0.232157;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.536471;0.536471;0.536471;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\safe001.png";
   }
  }
 }
 MeshNormals {
  18;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.817207;0.378003;0.435071;,
  -0.000001;-0.683717;-0.729747;,
  0.841351;0.192834;0.504920;,
  -0.000001;-0.367595;-0.929986;,
  0.841350;-0.192834;0.504920;,
  0.000001;0.367595;-0.929986;,
  0.817206;-0.378003;0.435072;,
  0.000001;0.683716;-0.729748;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.817206;0.378003;0.435072;,
  -0.841351;0.192834;0.504920;,
  -0.841351;-0.192834;0.504920;,
  -0.817206;-0.378003;0.435072;;
  39;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;12,12,12,12;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;13,13,13,13;,
  4;13,13,13,13;,
  4;3,3,5,5;,
  4;4,4,6,6;,
  4;14,14,15,15;,
  4;5,5,7,7;,
  4;6,6,8,8;,
  4;15,15,16,16;,
  4;7,7,9,9;,
  4;8,8,10,10;,
  4;16,16,17,17;;
 }
 MeshTextureCoords {
  76;
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.000000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  -0.010216;-1.041723;,
  1.018767;-1.041723;,
  1.018767;0.019187;,
  -0.010216;0.019187;,
  1.000000;0.666670;,
  0.666670;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.000000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  0.666670;0.666670;,
  1.000000;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  0.703200;0.120910;,
  0.731700;0.099470;,
  0.641450;0.099470;,
  0.627200;0.120910;,
  0.731700;0.142340;,
  0.641450;0.142340;,
  0.460950;0.099470;,
  0.475200;0.120910;,
  0.460950;0.142340;,
  0.370700;0.099470;,
  0.399200;0.120910;,
  0.370700;0.142340;;
 }
}
