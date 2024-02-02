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
 57;
 -0.08815;0.32256;-3.36801;,
 1.58404;0.11921;-7.39411;,
 -0.92423;0.11921;-8.00891;,
 -0.08815;0.32256;-3.36801;,
 2.98556;-0.91410;-4.46295;,
 -0.08815;0.32256;-3.36801;,
 1.48319;4.05102;1.51451;,
 -0.08815;0.32256;-3.36801;,
 -0.97787;4.02613;1.57074;,
 1.48319;4.05102;1.51451;,
 -0.08815;0.32256;-3.36801;,
 -2.34106;4.02613;-0.74016;,
 -0.08815;0.32256;-3.36801;,
 -3.16185;-0.91410;-4.46295;,
 -0.08815;0.32256;-3.36801;,
 -0.92423;0.11921;-8.00891;,
 -0.92423;-2.50978;-8.00891;,
 1.58404;-2.50978;-7.39411;,
 -0.08815;-2.71313;-3.36801;,
 2.98556;-0.91410;-4.46295;,
 -0.08815;-2.71313;-3.36801;,
 2.16479;-2.50978;-0.74016;,
 -0.08815;-2.71313;-3.36801;,
 -0.08814;-2.50978;1.57074;,
 -0.08815;-2.71313;-3.36801;,
 -0.08814;-2.50978;1.57074;,
 -2.34106;-2.50978;-0.74016;,
 -0.08815;-2.71313;-3.36801;,
 -3.16185;-0.91410;-4.46295;,
 -0.08815;-2.71313;-3.36801;,
 -0.92423;-2.50978;-8.00891;,
 -0.08815;-2.71313;-3.36801;,
 2.92017;-1.38503;-10.61113;,
 -0.08815;-1.38503;-12.82323;,
 4.11587;3.09110;1.53563;,
 1.57216;3.09110;5.84782;,
 -1.62923;3.47056;5.18615;,
 -3.99031;3.47056;1.18356;,
 -3.09645;-1.38503;-10.61112;,
 -3.16185;-0.91410;-4.46295;,
 -0.92423;0.11921;-8.00891;,
 -0.08815;-1.38503;-12.82323;,
 -1.74844;-1.57476;5.84782;,
 1.57216;3.09110;5.84782;,
 -4.29215;-1.57476;1.53563;,
 4.11587;3.09110;1.53563;,
 3.81403;-1.95423;1.18356;,
 2.98556;-0.91410;-4.46295;,
 1.45295;-1.95423;5.18615;,
 2.92017;-1.38503;-10.61113;,
 -0.08815;-1.38503;-12.82323;,
 -1.74844;-1.57476;5.84782;,
 -4.29215;-1.57476;1.53563;,
 -3.16185;-0.91410;-4.46295;,
 -3.09645;-1.38503;-10.61112;,
 -0.08815;-1.38503;-12.82323;,
 -0.92423;-2.50978;-8.00891;;
 
 46;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,9;,
 3;10,11,8;,
 3;12,13,11;,
 3;14,15,13;,
 3;16,17,18;,
 3;17,19,20;,
 3;19,21,22;,
 3;21,23,24;,
 3;25,26,27;,
 3;26,28,29;,
 3;28,30,31;,
 3;1,32,33;,
 3;1,33,2;,
 3;4,32,1;,
 3;4,6,34;,
 3;6,35,34;,
 3;8,36,35;,
 3;8,35,9;,
 3;11,37,36;,
 3;11,36,8;,
 3;13,37,11;,
 3;15,38,39;,
 3;40,41,38;,
 3;36,42,43;,
 3;37,44,42;,
 3;37,42,36;,
 3;39,44,37;,
 3;45,46,47;,
 3;43,48,46;,
 3;43,46,45;,
 3;42,48,43;,
 3;49,17,16;,
 3;49,16,50;,
 3;47,17,49;,
 3;46,21,19;,
 3;48,23,21;,
 3;48,21,46;,
 3;51,23,48;,
 3;52,26,25;,
 3;52,25,51;,
 3;53,26,52;,
 3;54,30,28;,
 3;54,55,56;;
 
 MeshMaterialList {
  14;
  46;
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
   0.097600;0.097600;0.097600;1.000000;;
   30.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\black_hair_background_image.jpg";
   }
  }
  Material {
   0.708800;0.693600;0.580000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   1.000000;
   0.000000;0.000000;0.000000;;
   0.190000;0.190000;0.190000;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\57583335.png";
   }
  }
  Material {
   0.442400;0.279200;0.184800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\texture_00130.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
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
    "C:\\Users\\student\\Downloads\\r00607.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.125600;0.483200;0.132000;1.000000;;
   5.000000;
   0.530000;0.530000;0.530000;;
   0.078500;0.302000;0.082500;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\metal02.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.184800;0.184800;0.184800;1.000000;;
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
    "C:\\Users\\student\\Downloads\\57583335_455x636.png";
   }
  }
  Material {
   0.558400;0.295200;0.147200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.432800;0.024800;0.075200;1.000000;;
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
    "C:\\Users\\student\\Downloads\\kuti.png";
   }
  }
 }
 MeshNormals {
  39;
  0.129363;0.918633;-0.373335;,
  -0.217894;0.965028;-0.145751;,
  0.295179;0.947113;-0.125886;,
  0.396136;0.865335;-0.307036;,
  0.151554;0.939996;-0.305678;,
  0.113771;0.987484;-0.109235;,
  -0.106921;0.926625;-0.360465;,
  -0.614912;0.700142;-0.362884;,
  0.336936;0.919639;-0.201836;,
  0.138763;0.970876;0.195308;,
  -0.103112;0.985751;0.132902;,
  -0.765138;0.604890;-0.220616;,
  0.023885;0.947047;-0.320204;,
  -0.500964;0.050592;0.863988;,
  -0.982187;0.070904;0.174018;,
  0.475314;0.856103;-0.202890;,
  0.950176;-0.077907;0.301821;,
  0.572173;-0.119919;0.811319;,
  -0.381546;0.901826;-0.202812;,
  -0.173253;-0.977504;-0.120286;,
  0.358889;-0.932860;-0.031139;,
  0.267919;-0.962054;-0.051693;,
  -0.067318;-0.990594;0.119132;,
  -0.331639;-0.941460;-0.060571;,
  0.005728;-0.998979;-0.044804;,
  0.696673;-0.711110;-0.094704;,
  -0.518626;-0.849977;-0.092560;,
  -0.572173;0.119920;0.811319;,
  -0.000000;0.000000;1.000000;,
  -0.858072;0.086656;0.506166;,
  0.979711;-0.071673;0.187160;,
  0.858071;-0.086655;0.506166;,
  0.328920;-0.930443;-0.161515;,
  -0.019963;-0.972810;-0.230742;,
  0.379651;-0.923256;-0.058854;,
  0.075426;-0.987873;0.135710;,
  -0.147657;-0.976629;0.156184;,
  -0.357325;-0.932765;0.047618;,
  -0.360643;-0.927352;-0.099778;;
  46;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,1,7;,
  3;19,20,24;,
  3;20,25,24;,
  3;25,21,24;,
  3;21,22,24;,
  3;22,23,24;,
  3;23,26,24;,
  3;26,19,24;,
  3;2,15,12;,
  3;2,12,1;,
  3;3,15,2;,
  3;3,4,8;,
  3;4,9,8;,
  3;5,10,9;,
  3;5,9,4;,
  3;6,11,10;,
  3;6,10,5;,
  3;7,11,6;,
  3;1,18,7;,
  3;1,12,18;,
  3;27,13,28;,
  3;29,14,13;,
  3;29,13,27;,
  3;7,14,11;,
  3;30,16,25;,
  3;31,17,16;,
  3;31,16,30;,
  3;13,17,28;,
  3;32,20,19;,
  3;32,19,33;,
  3;25,20,32;,
  3;34,21,25;,
  3;35,22,21;,
  3;35,21,34;,
  3;36,22,35;,
  3;37,23,22;,
  3;37,22,36;,
  3;26,23,37;,
  3;38,19,26;,
  3;38,33,19;;
 }
 MeshTextureCoords {
  57;
  0.055560;0.000000;,
  0.111110;0.166670;,
  0.000000;0.166670;,
  0.166670;0.000000;,
  0.222220;0.166670;,
  0.277780;0.000000;,
  0.333330;0.166670;,
  0.500000;0.000000;,
  0.555560;0.166670;,
  0.444440;0.166670;,
  0.611110;0.000000;,
  0.666670;0.166670;,
  0.722220;0.000000;,
  0.777780;0.166670;,
  0.833330;0.000000;,
  0.888890;0.166670;,
  0.000000;0.833330;,
  0.111110;0.833330;,
  0.055560;1.000000;,
  0.222220;0.833330;,
  0.166670;1.000000;,
  0.333330;0.833330;,
  0.277780;1.000000;,
  0.444440;0.833330;,
  0.388890;1.000000;,
  0.555560;0.833330;,
  0.666670;0.833330;,
  0.611110;1.000000;,
  0.777780;0.833330;,
  0.722220;1.000000;,
  0.888890;0.833330;,
  0.833330;1.000000;,
  0.111110;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.444440;0.333330;,
  0.555560;0.333330;,
  0.666670;0.333330;,
  0.888890;0.333330;,
  0.777780;0.333330;,
  1.000000;0.166670;,
  1.000000;0.333330;,
  0.555560;0.500000;,
  0.444440;0.500000;,
  0.666670;0.500000;,
  0.333330;0.500000;,
  0.333330;0.666670;,
  0.222220;0.666670;,
  0.444440;0.666670;,
  0.111110;0.666670;,
  0.000000;0.666670;,
  0.555560;0.666670;,
  0.666670;0.666670;,
  0.777780;0.666670;,
  0.888890;0.666670;,
  1.000000;0.666670;,
  1.000000;0.833330;;
 }
}
