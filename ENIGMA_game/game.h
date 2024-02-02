//=========================================================
//
//ゲーム画面で使う変数、宣言、構造体[game.h]
// Author seiya kagaya
//
//=========================================================
#ifndef _GAME_H_

#define _GAME_H_//二重インクルード防止

#include"main.h"
#include "model.h"
#include "Actionzone.h"

//#define MAX_WORD	(8192)
//#define MAX_WORD3	(512)

#define MAX_MODEL	(256) //モデルの最大数
#define NUM_MODEL	(25) //モデルの種類
#define MAX_FIELD	(256) //床の最大数
#define MAX_WALL	(256) //壁の最大数
#define GAME_END_DELAY	(180)//余韻
#define MODEL_FILE	"data\\Model.bin" //モデルファイル
#define FIELD_FILE	"data\\Field.bin" //床ファイル
#define WALL_FILE	"data\\Wall.bin" //壁ファイル

//#define GAMETIME	(10)

//#define MAXARRANGEMENTS	(20)//モデル自体の最大数

//#define MAXENEMYMODEL	(4)//敵種類



//#define MAXARRANGEMENTSMODEL	(40)//配置物の種類

//typedef struct
//{
//	D3DXVECTOR3 POS;//出現位置
//	D3DXVECTOR3 ROT;//方向ごとの移動速度
//	int Type;//敵の種類
//	char cModelFileName[MAXENEMYMODEL][MAX_WORD3];//とりあえず20でファイル名を管理--0番目ですべて管理
//}ENEMYSET;//モデル情報(敵)
//
//
//typedef struct
//{
//	D3DXVECTOR3 POS;//出現位置
//	D3DXVECTOR3 ROT;//方向ごとの移動速度
//	int Type;//配置物の種類
//	char cModelFileName[MAXENEMYMODEL][MAX_WORD3];//とりあえず20でファイル名を管理--0番目ですべて管理
//}MODELSET;//モデル情報(配置物)
//

//=============================================
//モデル読み込みの構想体の定義
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 move;
	D3DXMATRIX mtxWorld;
	D3DCOLORVALUE Diffuse[MAX_MODEL];
	ModelType nType;
	bool bUse;
	bool bUseGame;
}ModelInfo;

//=============================================
//壁読み込みの構想体の定義
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	int nType;
	float fWide;
	float fHeight;
	bool bUse;
	bool bUseGame;
}WallInfo;

//=============================================
//床読み込みの構想体の定義
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	int nType;
	float fWide;
	float fDepth;
	bool bUse;
	bool bUseGame;
}FieldInfo;


//制限時間
//#define ENDFRAME	(6000)//6000は100秒
//#define CASTPOSY	(-8000)//はじめに配置物を下げる

//プロトタイプ宣言
void InitGame(void);
void UninitGame(void);
void UpdateGame(void);
void DrawGame(void);
void  GameClear(void);
void ReleasePause(void);
void LoadModel(void);
void LoadField(void);
void LoadWall(void);

//レイを利用した円形同士の当たり判定
bool CheckCollisionWithRay(D3DXVECTOR3 start, D3DXVECTOR3 direction, D3DXVECTOR3 move, float selfRadius, float targetRadius, D3DXVECTOR3 centerPos);

//void LoadEnemySet(void);
//void LoadMODELSet(void);

//ENEMYSET* GetEnemySet(void);//敵

//MODELSET* GetModelSet(void);//配置物



//箱型当たり判定
void BoxCollisionPlayer(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax,int PlayerIndex);

//プレイヤーとカメラの間の障害物判定
void AdjustPlayerPositionToCollision_CAMERA(D3DXVECTOR3 playerPos, int CameraIndex, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax);

//プレイヤーと注視点の間の障害物判定
void AdjustPlayerPositionToCollision_VIEWPOS(D3DXVECTOR3 playerPos, int PlayerIndex, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax);

//転移門当たり判定
void BoxCollisionGate(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 GateMin, D3DXVECTOR3 GateMax, int PlayerIndex, int GateIndex, int ParentIndex);

//行動エリア当たり判定
void SphereCollisionZone(D3DXVECTOR3 PlayerPos, int PlayerIndex, int ZoneIndex);

//プレイヤー箱型当たり判定--アイテム
void BoxCollisionItem(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 HitPos, int PlayerIndex, int ItemIndex);


//ここから下、万が一用

//箱型当たり判定--敵使用
//void BoxCollisionEnamy(int EnemyIndex, D3DXVECTOR3 EnamyMin, D3DXVECTOR3 EnamyMax, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax);

//箱型当たり判定--バレット使用
//void BoxCollisionBullet(int BulletIndex, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax, EXISTENCETYPE type);




#endif 