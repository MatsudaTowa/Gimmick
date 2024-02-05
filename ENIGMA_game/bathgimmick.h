//=============================================
//
//お風呂のギミック[bathgimmick.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _BATHGIMMICK_H_ //定義されてなかったら
#define _BATHGIMMICK_H_ //２種インクルード防止

#include "main.h"
//=============================================
//マクロ定義
//=============================================
#define BATHWATER_WIDE	(30)
#define BATHWATER_DEPTH	(60)
#define SPAWN_STEAM		(20) //湯気が出るカウント
#define USE_STEAM		(20) //一回のスポーンで湯気が出る数
#define RUNWATER_SPEED	(0.5f) //流れるスピード

//=============================================
//お風呂のお湯の構想体の定義
//=============================================
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	int nSteamSpawnCnt; //湯気がスポーンするまでカウントする
	float fWide;
	float fDepth;
	bool bUse;
	bool bRun; //お湯を流すか
}BathWater;

//=========================================================
//プロトタイプ宣言
//=========================================================
void InitBathGimmick(void);
void UninitBathGimmick(void);
void UpdateBathGimmick(void);
void DrawBathGimmick(void);
void SetBathWater(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWide, float fDepth);
void RunWater(int nPlayer);
BathWater* GetBathGimmickPos(void);

#endif // _POLYGON_H_ //定義されてなかったら