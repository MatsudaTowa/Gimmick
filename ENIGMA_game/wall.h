//=========================================================
//
//壁で使う変数、宣言、構造体[wall.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _WALL_H

#define _WALL_H_//二重インクルード防止

#include"main.h"

#define NUMWALL	(64)//壁の数
#define TEXNUM	(4)//テクスチャの数

#define WALLSIZE	(3000.0f)

//壁の向いてる方向構造体
typedef enum
{
	WALLTYPE_test0 = 0,
	WALLTYPE_test1,
	WALLTYPE_test2,
	WALLTYPE_test3,
}WALLTYPE;


//壁の構造体
typedef struct
{
	D3DXVECTOR3 posWall;	//位置
	D3DXVECTOR3 rotWall;	//向き
	D3DXMATRIX mtxWorldWall;//ワールドマトリックス

	WALLTYPE WallType;//壁の向き

	bool bUse;
}WALL;




void InitWall(void);
void UninitWall(void);
void UpdateWall(void);
void DrawWall(void);
WALL* GetWall(void);

//壁の設定
void SetWall(D3DXVECTOR3 Pos,float angle,int Width,int height, WALLTYPE testType);


#endif