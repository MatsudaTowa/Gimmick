//============================================================================================
//
//ゲーム画面を制御する処理[game.cpp]
// Author seiya kagaya
//
//============================================================================================
#include "game.h"
#include "input.h"
#include "fade.h"
//#include "sound.h"
#include "pause.h"

#include "camera.h"
#include "light.h"
#include "stage.h"
#include "model.h"
#include "player.h"
#include "player2.h"
#include "moneybox.h"
#include "moneyboxdigit.h"
#include "bathgimmick.h"
#include "steam.h"
#include "password.h"

#include "shadow.h"
#include "meshfield.h"
#include "sky.h"
#include "line.h"
#include "transfergate.h"
#include "gamefade.h"
#include "limittime.h"
#include "screenui.h"
#include "speechbubble.h"
#include "text.h"
#include"DebugModel.h"
#include "item.h"
#include "particle.h"
#include"itemUI.h"
//仮
#include "Model_Set_Save_Lode.h"




#include <stdio.h>//ヘッダーファイルをインクルード
#include <string.h>//文字列を扱う変数

	//グローバル変数
	LPDIRECT3DTEXTURE9 g_pTextureGame = NULL;//テクスチャへのポインタ
	LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffGame = NULL;//頂点バッファへのポリゴン
	ModelInfo g_aModelInfo[MAX_MODEL];
	WallInfo g_aWallInfo[MAX_WALL];
	FieldInfo g_aFieldInfo[MAX_FIELD];
	int g_nUseModel; //モデルの使用数読み込み
	int g_nUseWall; //壁の使用数読み込み
	int g_nUseField; //床の使用数読み込み

	//制限時間代入
	int g_EndFlame = 600;	//-----limittime.hのマクロも変える

	int g_nLoopCnt = 0;




	int g_EndGameFrame = GAME_END_DELAY;//ゲーム終了まで3秒

	bool g_bPause = false;
	bool g_ClearFlag = false;
	bool g_MoneyboxPlayer = false; //どっちのプレイヤーが操作してるか false:1P,true2P
	bool g_bClearMoneybox = false;



	//ゲームループを一度でもしたか
	bool GameLoopSave = false;

//=============================
//ゲーム画面の初期化処理
//=============================
void InitGame(void)
{









	g_EndGameFrame = GAME_END_DELAY;//クリアからゲーム終了までの余韻

	InitPause();
	
	g_nLoopCnt = 0;//ゲームループリセット

	g_bPause = false;//ポーズ解除

	g_MoneyboxPlayer = false; //ギミック起動解除

	g_bClearMoneybox = false; //ギミッククリアしてないにする

	g_ClearFlag = false;//クリアしてないにする

	InitLight();
	InitCamera();

	InitItem();
	InitItem_UI();

	InitModel();
	LoadModel();
	InitStage();


	InitShadow();
	InitMoneybox();
	InitMoneyboxDigit();
	InitPassword();
	InitBathGimmick();
	InitSteam();

	InitPlayer();
	InitPlayer_2P();

	InitSky();


	InitTransferGate();
	InitActionZone();
	InitGameFade();
	InitScreenUI();
	InitSpeechBubble();
	InitParticle();


	//----------------------------制限時間
	NowTime* pNowTime;
	pNowTime = GetNowTime();
	pNowTime->NowTime = g_EndFlame;//とりま60秒
	InitLimitTime();
	//-----------------------------

	////仮配置置き場
	////---------------------------------------------------------------------------------------------
	////仮

	////地下室モデル配置
	//{
	//	SetModel(D3DXVECTOR3(-600.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_CUBE);

	//	SetModel(D3DXVECTOR3(-600.0f, 0.0f, 100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_DOOR);
	//	SetModel(D3DXVECTOR3(20.0f, 0.0f, -950.0f), D3DXVECTOR3(0.0f, D3DX_PI * 0.5, 0.0f), MODELTYPE_DOOR);

	//	for (int nCntCARDBOARD_T = 0; nCntCARDBOARD_T < 7; nCntCARDBOARD_T++)
	//	{
	//		for (int nCntCARDBOARD_Y = 0; nCntCARDBOARD_Y < 3; nCntCARDBOARD_Y++)
	//		{
	//			SetModel(D3DXVECTOR3(-440.0f - (nCntCARDBOARD_T * 60.0f), 0.0f + (nCntCARDBOARD_Y * 50.0f), -200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_CARDBOARD);
	//		}
	//	}

	//	for (int nCntMETASHE_T = 0; nCntMETASHE_T < 2; nCntMETASHE_T++)
	//	{
	//		for (int nCntMETASHE_Y = 0; nCntMETASHE_Y < 3; nCntMETASHE_Y++)
	//		{
	//			SetModel(D3DXVECTOR3(-1000.0f + (nCntMETASHE_Y * 300.0f), 0.0f + (nCntMETASHE_T * 110.0f), -600.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_METARSHELF);
	//			SetModel(D3DXVECTOR3(-1000.0f + (nCntMETASHE_Y * 300.0f), 0.0f + (nCntMETASHE_T * 110.0f), -820.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_METARSHELF);
	//		}
	//	}

	//	SetModel(D3DXVECTOR3(-600.0f, 0.0f, -1200.0f), D3DXVECTOR3(0.0f, D3DX_PI, 0.0f), MODELTYPE_GARAGE);

	//	for (int nCntT = 0; nCntT < 3; nCntT++)
	//	{
	//		for (int nCntY = 0; nCntY < 3; nCntY++)
	//		{
	//			SetModel(D3DXVECTOR3(0.0f, 0.0f + (nCntT * 50.0f), -1200.0f + (nCntY * 60.0f)), D3DXVECTOR3(0.0f, D3DX_PI * 0.5, 0.0f), MODELTYPE_CARDBOARD);
	//		}
	//	}

	//	for (int nCntT = 0; nCntT < 3; nCntT++)
	//	{
	//		for (int nCntY = 0; nCntY < 3; nCntY++)
	//		{
	//			SetModel(D3DXVECTOR3(0.0f, 0.0f + (nCntT * 50.0f), -800.0f + (nCntY * 60.0f)), D3DXVECTOR3(0.0f, D3DX_PI * 0.5, 0.0f), MODELTYPE_CARDBOARD);
	//		}
	//	}
	//}

	////十字路モデル配置
	//{
	//	SetModel(D3DXVECTOR3(-600.0f, 0.0f, -2000.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_CUBE);

	//	SetModel(D3DXVECTOR3(400.0f, 0.0f, -2900.0f), D3DXVECTOR3(0.0f, D3DX_PI * 0.5, 0.0f), MODELTYPE_DOOR);
	//	SetModel(D3DXVECTOR3(-600.0f, 0.0f, -1900.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_DOOR);
	//	SetModel(D3DXVECTOR3(-600.0f, 0.0f, -3900.0f), D3DXVECTOR3(0.0f, D3DX_PI, 0.0f), MODELTYPE_DOOR);
	//	SetModel(D3DXVECTOR3(-1600.0f, 0.0f, -2900.0f), D3DXVECTOR3(0.0f, D3DX_PI * -0.5, 0.0f), MODELTYPE_DOOR);
	//}

	
	InitMeshField();//------------------------デバッグ
#if _DEBUG
	if (GameLoopSave == false)
	{
	}


	InitLine();


#endif


	//デバッグ-------------------
	InitModel_SSL();
	Model_DebugLoad();
	Model_DebugSet();

	//新規モデル置き場
	NewSet_Debug_Model();


	//デバッグモデル
	InitDebugModel();

	//-------------------あたり判定再計算
	ExclusionCollision();
}
//=============================
//ゲーム画面の終了処理
//=============================
void UninitGame(void)
{
	//StopSound();

	//振動ストップ
	VibrationLeft(0);
	VibrationRight(0);
	UninitPause();

	UninitLight();
	UninitCamera();
	UninitModel();
	UninitStage();
	UninitPlayer();
	UninitPlayer_2P();
	UninitShadow();
	UninitMoneybox();
	UninitMoneyboxDigit();
	UninitPassword();
	UninitBathGimmick();
	UninitSteam();

	UninitSky();


	UninitTransferGate();
	UninitActionZone();
	UninitGameFade();
	UninitLimitTime();
	UninitScreenUI();
	UninitSpeechBubble();
	UninitParticle();
	UninitItem();
	UninitItem_UI();

	UninitMeshField();
#if _DEBUG

	UninitLine();
	UninitDebugModel();
#endif

}
//=============================
//ゲーム画面の更新処理
//=============================
void UpdateGame(void)
{
	//制限時間の取得
	NowTime* pNowtime;

	//現在の残り時間を取得
	pNowtime = GetNowTime();

	g_bClearMoneybox = GetClearMoneyBox(); //金庫クリア確認
	

	Player* pPlayer;
	pPlayer = GetPlayer();

	Player_2P* pPlayer2;
	pPlayer2 = GetPlayer_2P();

	bool bPlayer1inOK = false;
	bool bPlayer2inOK = false;

	if (GetkeyboardTrigger(DIK_P) == true)
	{//Pキー(ポーズ)が押された
		g_bPause = g_bPause ? false : true;
	}
	if (GetJoypadTrigger(JOYKEY_B, 0) == true && pPlayer2->bMoneyBoxGimmick != true)
	{//他のプレイヤーが金庫に触れてないときのみ
		pPlayer->bMoneyBoxGimmick = pPlayer->bMoneyBoxGimmick ? false : true;
		if (pPlayer->bMoneyBoxGimmick == true)
		{
			g_MoneyboxPlayer = false;
		}
	}
	else if (GetJoypadTrigger(JOYKEY_B, 1) == true && pPlayer->bMoneyBoxGimmick != true)
	{
		pPlayer2->bMoneyBoxGimmick = pPlayer2->bMoneyBoxGimmick ? false : true;
		if (pPlayer2->bMoneyBoxGimmick == true)
		{
			g_MoneyboxPlayer = true;
		}
	}

	if (g_bPause == false)
	{//ポーズ中でなければ

		SubLimitTime();
		UpdateLimitTime();



		//--------------------------------------------------------------------------------クリア、敗北条件
		if (GetkeyboardPress(DIK_O) == true)//トリガー
		{//oが押された(デバッグ用)

			if (GameLoopSave == false)
			{
#if _DEBUG
				Model_DebugSave();
				GameLoopSave++;
#endif
			}

			//モード設定(フェードの後リザルト画面に移行)
			SetFade(MODE_RESULT);
		}
		if (g_ClearFlag == true)
		{
	
			if (g_EndGameFrame > 0)
			{//Clear余韻用
				g_EndGameFrame--;
			}
			else
			{//余韻がたった
				//モード設定(フェードの後リザルト画面に移行)
				SetFade(MODE_RESULT);
			}
		}


		
		//------------------------------------ゲームオーバー条件変更
		if (pNowtime->NowTime <= 0 || pPlayer->bUse == false || pPlayer2->bUse == false)
		{//ゲームオーバー
			
		 //振動ストップ
			VibrationLeft(0);
			VibrationRight(0);

			if (g_EndGameFrame > 0)
			{//余韻用
				g_EndGameFrame--;
			}
			else
			{//余韻がたった

				//モード設定(フェードの後リザルト画面に移行)
				SetFade(MODE_RESULT);
			}
		}
		//--------------------------------------------------------------------------------クリア、敗北条件ここまで
	


		g_nLoopCnt++;//出現タイミングで使用
		
		UpdateGameFade();
		
		UpdateSky();

		UpdateLight();
		UpdateCamera();
		UpdateModel();
		UpdateStage();

		UpdateMeshField();

		
		UpdateItem();



		//--------------------プレイヤー
		if (pPlayer->bMoneyBoxGimmick != true)
		{//ギミックを操作していたらプレイヤーを止める(仮) ※ギミック中用のモーション出来たらそれに切り替え
			UpdatePlayer();
			bPlayer1inOK = true;
		}
		if (pPlayer2->bMoneyBoxGimmick != true)
		{//ギミックを操作していたらプレイヤーを止める(仮) ※ギミック中用のモーション出来たらそれに切り替え
			UpdatePlayer_2P();
			bPlayer2inOK = true;
		}
		//--------------------



		UpdateItem_UI(bPlayer1inOK, bPlayer2inOK);//入力受付可能かどうか






		if ((pPlayer->bMoneyBoxGimmick == true || pPlayer2->bMoneyBoxGimmick == true))
		{
			SetMonetbox(g_MoneyboxPlayer);
			if (g_bClearMoneybox == false)
			{
				UpdateMoneybox();
				UpdateMoneyboxDigit();
				UpdatePassword();
			}
		}

		UpdateBathGimmick();
		UpdateSteam();

		UpdateTransferGate();
		UpdateActionZone();

		UpdateShadow();
#if _DEBUG
		UpdateLine();
#endif
		UpdateScreenUI();
		UpdateSpeechBubble();
		UpdateModel();
		UpdateDebugModel();
		UpdateParticle();

	}
	else
	{//ポーズ中
		UpdatePause();
	}
}
//=============================
//ゲーム画面の描画処理
//=============================
void DrawGame(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	Camera* pCamera;

	//先頭を受け取るため0番目を取得
	pCamera = GetCamera();

	Player* pPlayer;
	pPlayer = GetPlayer();

	Player_2P* pPlayer2;
	pPlayer2 = GetPlayer_2P();

	for (int nCnt = 0; nCnt < MAXCAMERA; nCnt++)
	{


		//// バックバッファクリア
		//pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0);

		// バッファのクリア(バックバッファ、Zバッファ)
		pDevice->Clear(
			0,
			nullptr,
			D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
			D3DCOLOR_XRGB(0, 0, 0),
			1.0f,
			0);

		DrawMeshField();
#if _DEBUG

#endif
		DrawSky();

		DrawShadow();
		if ((pPlayer->bMoneyBoxGimmick == true || pPlayer2->bMoneyBoxGimmick == true))
		{
			DrawMoneybox();
			DrawMoneyboxDigit();
			DrawPassword();

		}
		DrawBathGimmick();
		DrawSteam();
		DrawModel();
		DrawStage();
		DrawPlayer();
		DrawPlayer_2P();



		DrawTransferGate();

		DrawActionZone();


#if _DEBUG
		DrawLine();
		DrawDebugModel();
#endif
		//αテストを有効
		pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ALPHAREF, 0);//基準値
		pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);//比較方法(よりも大きい)--これでアルファ値が0より大きいときに描画（Zバッファにも書かれない ）

		DrawItem();

		DrawParticle();
		DrawSpeechBubble();
		//αテストを無効
		pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

		SetCamera(nCnt);

		DrawCamera();
	
		//ビューポートの設定
		pDevice->SetViewport(&pCamera[nCnt].viewport);



	}

	//ビューポートをもとに戻す
	//ビューポートの設定
	//pDevice->SetViewport(&g_fullScreen_Viewport);

	//全画面ビューポート
	D3DVIEWPORT9 FullViewport = GetViewPort();
	//ビューポートをもとに戻す
	pDevice->SetViewport(&FullViewport);//ビューポートの設定

	//------------------------------------------Debug用
	ACTIONZONE* pActionZone;
	pActionZone = GetActionZone();

	for (int nCntZone = 0; nCntZone < MAXZONE; nCntZone++)
	{
		if (pActionZone[nCntZone].bUse == true)
		{
			pActionZone[nCntZone].ZoneColor = pActionZone[nCntZone].EscapeZoneColor;
		}
	}

	DrawGameFade();

	DrawLimitTime();
	DrawScreenUI();

	DrawItem_UI();

	DrawTextSet(D3DXVECTOR3(550.0f, 660.0f, 0.0f), 20, FONT_AKABARASINDELERA, D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), "Oキーでリザルト＆モデル配置をセーブ！");
	DrawTextSet(D3DXVECTOR3(550.0f, 680.0f, 0.0f), 20, FONT_AKABARASINDELERA, D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), "事故防止のためゲームループ後は無効！");
	DrawTextSet(D3DXVECTOR3(550.0f, 700.0f, 0.0f), 20, FONT_AKABARASINDELERA, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f), "Xボタンでとりあえずアイテム出現");



	if (g_bPause == true)
	{
		DrawPause();
	}

	DrawDebugDelC0mment();
}
//===================================
//Clear専用処理
//===================================
void GameClear(void)
{
}
//===================================
//ポーズ解除処理
//===================================
void ReleasePause(void)
{
	g_bPause = false;
}

//===================================
//モデル読み込み処理
//===================================
void LoadModel(void)
{
	//ファイルの読み込み
	FILE* pFile = fopen(MODEL_FILE, "rb");

	if (pFile != NULL)
	{
		//敵の使用してる数の読み込み
		fread(&g_nUseModel, sizeof(int), 1, pFile);

		//敵の使用数分、敵の読み込み
		fread(&g_aModelInfo[0], sizeof(ModelInfo), g_nUseModel, pFile);

		//ファイルを閉じる
		fclose(pFile);

	}

	else
	{
		return;
	}

	for (int nCnt = 0; nCnt < g_nUseModel; nCnt++)
	{
		SetModel(g_aModelInfo[nCnt].pos, g_aModelInfo[nCnt].rot, g_aModelInfo[nCnt].nType);
	}
}

//===================================
//床読み込み処理処理
//===================================
void LoadField(void)
{
	//ファイルの読み込み
	FILE* pFile = fopen(FIELD_FILE, "rb");

	if (pFile != NULL)
	{
		//敵の使用してる数の読み込み
		fread(&g_nUseField, sizeof(int), 1, pFile);

		//敵の使用数分、敵の読み込み
		fread(&g_aFieldInfo[0], sizeof(FieldInfo), g_nUseField, pFile);

		//ファイルを閉じる
		fclose(pFile);

	}

	else
	{
		return;
	}

	for (int nCnt = 0; nCnt < g_nUseField; nCnt++)
	{
		//SetField(g_aFieldInfo[nCnt].pos, g_aFieldInfo[nCnt].rot, g_aFieldInfo[nCnt].fWide, g_aFieldInfo[nCnt].fDepth, g_aFieldInfo[nCnt].nType);
	}
}

//===================================
//壁読み込み処理処理
//===================================
void LoadWall(void)
{
	//ファイルの読み込み
	FILE* pFile = fopen(WALL_FILE, "rb");

	if (pFile != NULL)
	{
		//敵の使用してる数の読み込み
		fread(&g_nUseWall, sizeof(int), 1, pFile);

		//敵の使用数分、敵の読み込み
		fread(&g_aWallInfo[0], sizeof(ModelInfo), g_nUseWall, pFile);

		//ファイルを閉じる
		fclose(pFile);

	}

	else
	{
		return;
	}

	for (int nCnt = 0; nCnt < g_nUseWall; nCnt++)
	{
		//SetWall(g_aWallInfo[nCnt].pos, g_aWallInfo[nCnt].rot, g_aWallInfo[nCnt].fWide, g_aWallInfo[nCnt].fHeight, g_aModelInfo[nCnt].nType);
	}
}



//===================================
//レイを利用した円形での当たり判定
//===================================
bool CheckCollisionWithRay(D3DXVECTOR3 start, D3DXVECTOR3 direction, D3DXVECTOR3 move, float selfRadius, float targetRadius, D3DXVECTOR3 centerPos)
{
// レイと球の衝突判定を行う関数
// 引数:
//   start: レイの始点
//   direction: レイの方向ベクトル (正規化されていることを想定)
//   move: 移動オブジェクトの移動ベクトル
//   selfRadius: 自分の半径
//   targetRadius: 相手の半径
//   center: 球の中心座標
// 戻り値:
//   衝突があれば true, なければ false


	// レイの始点を自分の半径を相手の方向に向けた地点に設定
	D3DXVECTOR3 adjustedStart;
	D3DXVec3Normalize(&adjustedStart, &move);
	adjustedStart *= selfRadius;
	adjustedStart += start;

	// 移動オブジェクトが進むレイの始点から終点までのベクトルを計算
	D3DXVECTOR3 end = adjustedStart + direction * D3DXVec3Length(&move);

	// レイの始点から球の中心へのベクトルを計算
	D3DXVECTOR3 v = centerPos - adjustedStart;

	// レイの方向ベクトルと球に対する最も近い点を計算
	float t = D3DXVec3Dot(&v, &direction);
	D3DXVECTOR3 closestPoint;

	// レイが球の手前から始まる場合
	if (t < 0.0f)
	{
		closestPoint = adjustedStart;
	}
	// レイが球の奥から始まる場合
	else if (t > D3DXVec3Length(&move))
	{
		closestPoint = end;
	}
	// レイが球と交差する場合
	else
	{
		closestPoint = adjustedStart + direction * t;
	}

	// 最も近い点と球の中心との距離の二乗を計算
	D3DXVECTOR3 Escape = centerPos - closestPoint;

	float distanceSquared = D3DXVec3LengthSq(&Escape);


	float radiusSquared = (selfRadius + targetRadius) * (selfRadius + targetRadius);

	// 距離の二乗が半径の二乗以下ならば当たり
	return distanceSquared <= radiusSquared;
}



//===================================
//プレイヤー箱型当たり判定
//===================================
void BoxCollisionPlayer(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax,int PlayerIndex)
{//当たり判定
	//LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//1Pのとき
	if (PlayerIndex == 1)
	{
		Player* pPlayer;
		pPlayer = GetPlayer();

		//---------------------------------------X方向
		if (PlayerMin.z < HitMax.z &&
			PlayerMax.z > HitMin.z &&
			PlayerMax.x - pPlayer->pos.x + pPlayer->oldPos.x <= HitMin.x &&
			PlayerMax.x > HitMin.x &&
			PlayerMin.y < HitMax.y &&
			PlayerMax.y > HitMin.y)
		{
			pPlayer->move.x = 0.0f;
			pPlayer->pos.x = HitMin.x + (PlayerMin.x - pPlayer->pos.x) - 0.1f;
		}

		if (PlayerMin.z < HitMax.z &&
			PlayerMax.z > HitMin.z &&
			PlayerMin.x - pPlayer->pos.x + pPlayer->oldPos.x >= HitMax.x &&
			PlayerMin.x < HitMax.x &&
			PlayerMin.y < HitMax.y &&
			PlayerMax.y > HitMin.y)
		{
			pPlayer->move.x = 0.0f;
			pPlayer->pos.x = HitMax.x + (PlayerMax.x - pPlayer->pos.x) + 0.1f;
		}

		//---------------------------------------Z方向
		if (PlayerMin.x < HitMax.x &&
			PlayerMax.x > HitMin.x &&
			PlayerMin.z - pPlayer->pos.z + pPlayer->oldPos.z >= HitMax.z &&
			PlayerMin.z < HitMax.z &&
			PlayerMin.y < HitMax.y &&
			PlayerMax.y > HitMin.y)
		{
			pPlayer->move.z = 0.0f;
			pPlayer->pos.z = HitMax.z - (PlayerMin.z - pPlayer->pos.z) + 0.1f;
		}

		if (PlayerMin.x < HitMax.x &&
			PlayerMax.x > HitMin.x &&
			PlayerMax.z - pPlayer->pos.z + pPlayer->oldPos.z <= HitMin.z &&
			PlayerMax.z > HitMin.z &&
			PlayerMin.y < HitMax.y &&
			PlayerMax.y > HitMin.y)
		{
			pPlayer->move.z = 0.0f;
			pPlayer->pos.z = HitMin.z - (PlayerMax.z - pPlayer->pos.z) - 0.1f;
		}

		//------------------------------------Y方向
		if (PlayerMin.x < HitMax.x &&
			PlayerMax.x > HitMin.x &&
			PlayerMin.z < HitMax.z &&
			PlayerMax.z > HitMin.z &&
			PlayerMin.y - pPlayer->pos.y + pPlayer->oldPos.y >= HitMax.y &&
			PlayerMin.y < HitMax.y)
		{
			pPlayer->move.y = 0.0f;
			pPlayer->pos.y = HitMax.y + (PlayerMin.y - pPlayer->pos.y);

			if (pPlayer->NowMotionDOWN == MOTIONTYPE_1P_JUMP)
			{
				pPlayer->NowMotionDOWN = MOTIONTYPE_1P_RANDING;
			}
			else if (pPlayer->NowMotionDOWN == MOTIONTYPE_1P_MOVE)
			{
				pPlayer->NowMotionDOWN = MOTIONTYPE_1P_MOVE;
			}

			pPlayer->bLandingNow = true;
		}
	}
	else if (PlayerIndex==2)
	{//2Pの時
		Player_2P* pPlayer2;
		pPlayer2 = GetPlayer_2P();

		//---------------------------------------X方向
		if (PlayerMin.z < HitMax.z &&
			PlayerMax.z > HitMin.z &&
			PlayerMax.x - pPlayer2->pos.x + pPlayer2->oldPos.x <= HitMin.x &&
			PlayerMax.x > HitMin.x &&
			PlayerMin.y < HitMax.y &&
			PlayerMax.y > HitMin.y)
		{
			pPlayer2->move.x = 0.0f;
			pPlayer2->pos.x = HitMin.x + (PlayerMin.x - pPlayer2->pos.x) - 0.1f;
		}

		if (PlayerMin.z < HitMax.z &&
			PlayerMax.z > HitMin.z &&
			PlayerMin.x - pPlayer2->pos.x + pPlayer2->oldPos.x >= HitMax.x &&
			PlayerMin.x < HitMax.x &&
			PlayerMin.y < HitMax.y &&
			PlayerMax.y > HitMin.y)
		{
			pPlayer2->move.x = 0.0f;
			pPlayer2->pos.x = HitMax.x + (PlayerMax.x - pPlayer2->pos.x) + 0.1f;
		}

		//---------------------------------------Z方向
		if (PlayerMin.x < HitMax.x &&
			PlayerMax.x > HitMin.x &&
			PlayerMin.z - pPlayer2->pos.z + pPlayer2->oldPos.z >= HitMax.z &&
			PlayerMin.z < HitMax.z &&
			PlayerMin.y < HitMax.y &&
			PlayerMax.y > HitMin.y)
		{
			pPlayer2->move.z = 0.0f;
			pPlayer2->pos.z = HitMax.z - (PlayerMin.z - pPlayer2->pos.z) + 0.1f;
		}

		if (PlayerMin.x < HitMax.x &&
			PlayerMax.x > HitMin.x &&
			PlayerMax.z - pPlayer2->pos.z + pPlayer2->oldPos.z <= HitMin.z &&
			PlayerMax.z > HitMin.z &&
			PlayerMin.y < HitMax.y &&
			PlayerMax.y > HitMin.y)
		{
			pPlayer2->move.z = 0.0f;
			pPlayer2->pos.z = HitMin.z - (PlayerMax.z - pPlayer2->pos.z) - 0.1f;
		}

		//------------------------------------Y方向
		if (PlayerMin.x < HitMax.x &&
			PlayerMax.x > HitMin.x &&
			PlayerMin.z < HitMax.z &&
			PlayerMax.z > HitMin.z &&
			PlayerMin.y - pPlayer2->pos.y + pPlayer2->oldPos.y >= HitMax.y &&
			PlayerMin.y < HitMax.y)
		{
			pPlayer2->move.y = 0.0f;
			pPlayer2->pos.y = HitMax.y + (PlayerMin.y - pPlayer2->pos.y);

			if (pPlayer2->NowMotionDOWN == MOTIONTYPE_2P_JUMP)
			{
				pPlayer2->NowMotionDOWN = MOTIONTYPE_2P_RANDING;
			}
			else if (pPlayer2->NowMotionDOWN == MOTIONTYPE_2P_MOVE)
			{
				pPlayer2->NowMotionDOWN = MOTIONTYPE_2P_MOVE;
			}

			pPlayer2->bLandingNow = true;
		}
	}


#if _DEBUG
	// 上下の辺
	SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
																														
	SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
																														
	// 側面の辺																											
	SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
																														
	SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
																														
																														
	// その他の辺																									   
	SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	SetLine(D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
																														
	SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
#endif

}

////===================================
////カメラ箱型当たり判定---モデル
////===================================
//void BoxCollisionCamera(D3DXVECTOR3 CameraMin, D3DXVECTOR3 CameraMax, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax, int CameraIndex)
//{//当たり判定
//	//LPDIRECT3DDEVICE9 pDevice = GetDevice();
//
//
//		Camera* pCamera;
//		pCamera = GetCamera();
//
//		//---------------------------------------X方向
//		if (CameraMin.z < HitMax.z &&
//			CameraMax.z > HitMin.z &&
//			CameraMax.x - pCamera[CameraIndex].posV.x +pCamera[CameraIndex].OldPosV.x <= HitMin.x &&
//			CameraMax.x > HitMin.x &&
//			CameraMin.y < HitMax.y &&
//			CameraMax.y > HitMin.y)
//		{
//			pCamera[CameraIndex].move.x = 0.0f;
////			pCamera[CameraIndex].posV.x = HitMin.x + (CameraMin.x - pCamera[CameraIndex].posV.x) - 0.1f;
//		}
//
//		if (CameraMin.z < HitMax.z &&
//			CameraMax.z > HitMin.z &&
//			CameraMin.x - pCamera[CameraIndex].posV.x +pCamera[CameraIndex].OldPosV.x >= HitMax.x &&
//			CameraMin.x < HitMax.x &&
//			CameraMin.y < HitMax.y &&
//			CameraMax.y > HitMin.y)
//		{
//			pCamera[CameraIndex].move.x = 0.0f;
////			pCamera[CameraIndex].posV.x = HitMax.x + (CameraMax.x - pCamera[CameraIndex].posV.x) + 0.1f;
//		}
//
//		//---------------------------------------Z方向
//		if (CameraMin.x < HitMax.x &&
//			CameraMax.x > HitMin.x &&
//			CameraMin.z - pCamera[CameraIndex].posV.z +pCamera[CameraIndex].OldPosV.z >= HitMax.z &&
//			CameraMin.z < HitMax.z &&
//			CameraMin.y < HitMax.y &&
//			CameraMax.y > HitMin.y)
//		{
//			pCamera[CameraIndex].move.z = 0.0f;
////			pCamera[CameraIndex].posV.z = HitMax.z - (CameraMin.z - pCamera[CameraIndex].posV.z) + 0.1f;
//		}
//
//		if (CameraMin.x < HitMax.x &&
//			CameraMax.x > HitMin.x &&
//			CameraMax.z - pCamera[CameraIndex].posV.z +pCamera[CameraIndex].OldPosV.z <= HitMin.z &&
//			CameraMax.z > HitMin.z &&
//			CameraMin.y < HitMax.y &&
//			CameraMax.y > HitMin.y)
//		{
//			pCamera[CameraIndex].move.z = 0.0f;
////			pCamera[CameraIndex].posV.z = HitMin.z - (CameraMax.z - pCamera[CameraIndex].posV.z) - 0.1f;
//		}
//
//		//------------------------------------Y方向
//		if (CameraMin.x < HitMax.x &&
//			CameraMax.x > HitMin.x &&
//			CameraMin.z < HitMax.z &&
//			CameraMax.z > HitMin.z &&
//			CameraMin.y - pCamera[CameraIndex].posV.y +pCamera[CameraIndex].OldPosV.y >= HitMax.y &&
//			CameraMin.y < HitMax.y)
//		{
//			pCamera[CameraIndex].move.y = 0.0f;
////			pCamera[CameraIndex].posV.y = HitMax.y + (CameraMin.y - pCamera[CameraIndex].posV.y);
//
//		}
//	
//
//
//	//// 上下の辺
//	//SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//																													
//	//SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//																													
//	//// 側面の辺																											
//	//SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//																													
//	//SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//																													
//	//																													
//	//// その他の辺																									   
//	//SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//SetLine(D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//																													
//	//SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//	//SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
//
//}











//===================================
//プレイヤーとカメラの間の障害物判定
//===================================
void AdjustPlayerPositionToCollision_CAMERA(D3DXVECTOR3 playerPos, int CameraIndex,D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax)
{
	Camera* pCamera;
	pCamera = GetCamera();

	// カメラとプレイヤーの直線上での当たり判定
	D3DXVECTOR3 direction = pCamera[CameraIndex].posV - playerPos;//現在のプレイヤーとカメラの距離
	D3DXVECTOR3 normalizedDir;
	D3DXVec3Normalize(&normalizedDir, &direction);

	// 当たり判定の結果を保存する変数
	bool collision = false;
	float collisionDistance = 0.0f;//衝突した距離

	// プレイヤーからカメラに向かう方向にレイを飛ばして、障害物との当たり判定を行う
	// （ここでは単純に箱型当たり判定を使用していますが、実際のゲームにおいてはより高度なアルゴリズムを使用することが一般的です）
	while (collision==false)
	{
		D3DXVECTOR3 rayPos = playerPos + normalizedDir * collisionDistance;

		if (rayPos.x < HitMax.x && rayPos.x > HitMin.x &&
			rayPos.y < HitMax.y && rayPos.y > HitMin.y &&
			rayPos.z < HitMax.z && rayPos.z > HitMin.z)
		{
			// 衝突が検知された場合、collisionDistanceを調整して再度判定
			collision = true;
		}

		// レイの移動距離を増やして再度判定
		collisionDistance += 0.5f;

		// レイが一定距離(カメラとプレイヤーの距離)以上伸びた場合、無限ループを防ぐために抜ける
		if (CAMERALENGTH < collisionDistance)
		{
			break;
		}
	}

	// 衝突時にカメラの位置を調整
	if (collision==true)
	{
		pCamera[CameraIndex].posV -= (normalizedDir * 0.98f);
		pCamera[CameraIndex].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pCamera[CameraIndex].CameraLength = collisionDistance-3.0f;
	}
}
//===================================
//プレイヤーと注視点の間の障害物判定
//===================================
void AdjustPlayerPositionToCollision_VIEWPOS(D3DXVECTOR3 playerPos, int PlayerIndex, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax)
{
	Player* pPlayer;
	pPlayer = GetPlayer();
	Player_2P* pPlayer2;
	pPlayer2 = GetPlayer_2P();

	View* pViewMtx = GetView();

	View2* pViewMtx2 = GetView_2P();

	HitMin -= D3DXVECTOR3(1.5f, 0.0f, 1.5f);
	HitMax += D3DXVECTOR3(1.5f, 0.0f, 1.5f);


	if (PlayerIndex == 0)
	{
		// 注視点とプレイヤーの直線上での当たり判定
		D3DXVECTOR3 direction = D3DXVECTOR3(pViewMtx[1].ViewPosMtx._41, pViewMtx[1].ViewPosMtx._42, pViewMtx[1].ViewPosMtx._43) - playerPos;//方角制定
		D3DXVECTOR3 normalizedDir;
		D3DXVec3Normalize(&normalizedDir, &direction);

		// 当たり判定の結果を保存する変数
		bool collision = false;
		float collisionDistance = 0.0f;//衝突した距離

		while (collision == false)
		{
			D3DXVECTOR3 rayPos = playerPos + normalizedDir * collisionDistance;

			if (rayPos.x < HitMax.x && rayPos.x > HitMin.x &&
				rayPos.y < HitMax.y && rayPos.y > HitMin.y &&
				rayPos.z < HitMax.z && rayPos.z > HitMin.z)
			{
				// 衝突が検知された場合、collisionDistanceを調整して再度判定
				collision = true;
			}

			// レイの移動距離を増やして再度判定
			collisionDistance += 0.5f;

			// レイが一定距離(カメラとプレイヤーの距離)以上伸びた場合、無限ループを防ぐために抜ける
			if (VIEWPOS.x < collisionDistance)
			{
				pViewMtx[1].ViewPos = VIEWPOS;
				break;
			}
		}

		// 衝突時にカメラの位置を調整
		if (collision == true)
		{
			pViewMtx[1].ViewPosMtx._41 -= (normalizedDir.x* collisionDistance * 0.8f);
			//pViewMtx[1].ViewPosMtx._42 -= (normalizedDir.y);
			pViewMtx[1].ViewPosMtx._43 -= (normalizedDir.z * collisionDistance * 0.8f);
		}
	}
	else if (PlayerIndex == 2)
	{
		// 注視点とプレイヤーの直線上での当たり判定
		D3DXVECTOR3 direction = D3DXVECTOR3(pViewMtx2[1].ViewPosMtx._41, pViewMtx2[1].ViewPosMtx._42, pViewMtx2[1].ViewPosMtx._43) - playerPos;//方角制定
		D3DXVECTOR3 normalizedDir;
		D3DXVec3Normalize(&normalizedDir, &direction);

		// 当たり判定の結果を保存する変数
		bool collision = false;
		float collisionDistance = 0.0f;//衝突した距離

		while (collision == false)
		{
			D3DXVECTOR3 rayPos = playerPos + normalizedDir * collisionDistance;

			if (rayPos.x < HitMax.x && rayPos.x > HitMin.x &&
				rayPos.y < HitMax.y && rayPos.y > HitMin.y &&
				rayPos.z < HitMax.z && rayPos.z > HitMin.z)
			{
				// 衝突が検知された場合、collisionDistanceを調整して再度判定
				collision = true;
			}

			// レイの移動距離を増やして再度判定
			collisionDistance += 0.5f;

			// レイが一定距離(カメラとプレイヤーの距離)以上伸びた場合、無限ループを防ぐために抜ける
			if (VIEWPOS.x < collisionDistance)
			{
				pViewMtx2[1].ViewPos = VIEWPOS;
				break;
			}
		}

		// 衝突時にカメラの位置を調整
		if (collision == true)
		{
			pViewMtx2[1].ViewPosMtx._41 -= (normalizedDir.x * collisionDistance * 0.8f);
			//pViewMtx[1].ViewPosMtx._42 -= (normalizedDir.y);
			pViewMtx2[1].ViewPosMtx._43 -= (normalizedDir.z * collisionDistance * 0.8f);
		}
	}
}





















//===================================
//転移門当たり判定
//===================================
void BoxCollisionGate(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 GateMin, D3DXVECTOR3 GateMax, int PlayerIndex, int GateIndex, int ParentIndex)
{//当たり判定
//	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	Camera* pCamera;
	pCamera = GetCamera();



	TRANSFERGATE* pTransferGate;
	pTransferGate = GetTransferGate();

	//転移先
	D3DXVECTOR3 ParentGateMin = D3DXVECTOR3(pTransferGate[ParentIndex].pos + pTransferGate[ParentIndex].GateMin);
	D3DXVECTOR3 ParentGateMax = D3DXVECTOR3(pTransferGate[ParentIndex].pos + pTransferGate[ParentIndex].GateMax);

	//移動量避難
	D3DXVECTOR3 ESCAPEMOVE = D3DXVECTOR3(0.0f, 0.0f, 0.0f);



	float PlayerCenterCorre = 45.0f;


	if (pTransferGate[ParentIndex].bActiomTrans == false)
	{//アクショントランスじゃない時

		//1Pのとき
		if (PlayerIndex == 0)
		{
			//接触したか
			bool bHit = false;

			Player* pPlayer;
			pPlayer = GetPlayer();



			if (pPlayer->bAction == true)
			{
			}


			//---------------------------------------X方向
			if (PlayerMin.z < GateMax.z &&
				PlayerMax.z > GateMin.z &&
				PlayerMax.x - pPlayer->pos.x + pPlayer->oldPos.x <= GateMin.x &&
				PlayerMax.x > GateMin.x &&
				PlayerMin.y < GateMax.y &&
				PlayerMax.y > GateMin.y)
			{
				bHit = true;

				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX)
				{//初期値の時--進行方向に転移

					ESCAPEMOVE.x = ParentGateMax.x + (PlayerMax.x - pPlayer->pos.x) + 0.1f;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
					ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

					pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
			}
			else if (PlayerMin.z < GateMax.z &&
				PlayerMax.z > GateMin.z &&
				PlayerMin.x - pPlayer->pos.x + pPlayer->oldPos.x >= GateMax.x &&
				PlayerMin.x < GateMax.x &&
				PlayerMin.y < GateMax.y &&
				PlayerMax.y > GateMin.y)
			{
				bHit = true;

				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX)
				{//初期値の時--進行方向に転移

					ESCAPEMOVE.x = ParentGateMin.x + (PlayerMin.x - pPlayer->pos.x) - 0.1f;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
					ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

					pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
			}
			//---------------------------------------Z方向
			else if (PlayerMin.x < GateMax.x &&
				PlayerMax.x > GateMin.x &&
				PlayerMin.z - pPlayer->pos.z + pPlayer->oldPos.z >= GateMax.z &&
				PlayerMin.z < GateMax.z &&
				PlayerMin.y < GateMax.y &&
				PlayerMax.y > GateMin.y)
			{
				bHit = true;

				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX)
				{//初期値の時--進行方向に転移

					ESCAPEMOVE.z = ParentGateMin.z - (PlayerMax.z - pPlayer->pos.z) - 0.1f;
					ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

					pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
			}
			else  if (PlayerMin.x < GateMax.x &&
				PlayerMax.x > GateMin.x &&
				PlayerMax.z - pPlayer->pos.z + pPlayer->oldPos.z <= GateMin.z &&
				PlayerMax.z > GateMin.z &&
				PlayerMin.y < GateMax.y &&
				PlayerMax.y > GateMin.y)
			{
				bHit = true;

				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX)
				{//初期値の時--進行方向に転移
					ESCAPEMOVE.z = ParentGateMax.z - (PlayerMin.z - pPlayer->pos.z) + 0.1f;
					ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

					pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
			}

			////------------------------------------Y方向
			//if (PlayerMin.x < GateMax.x &&
			//	PlayerMax.x > GateMin.x &&
			//	PlayerMin.z < GateMax.z &&
			//	PlayerMax.z > GateMin.z &&
			//	PlayerMin.y - pPlayer->pos.y + pPlayer->oldPos.y >= GateMax.y &&
			//	PlayerMin.y < GateMax.y)
			//{
			//	pPlayer->move.y = 0.0f;
			//	pPlayer->pos.y = GateMax.y + (PlayerMin.y - pPlayer->pos.y);

			//	if (pPlayer->NowMotionDOWN == MOTIONTYPE_1P_JUMP)
			//	{
			//		pPlayer->NowMotionDOWN = MOTIONTYPE_1P_RANDING;
			//	}
			//	else if (pPlayer->NowMotionDOWN == MOTIONTYPE_1P_MOVE)
			//	{
			//		pPlayer->NowMotionDOWN = MOTIONTYPE_1P_MOVE;
			//	}

			//	pPlayer->bLandingNow = true;
			//}

			if (bHit == true)
			{//接触判定時

				pPlayer->PlayerState = PLAYERSTATE_1P_TELEPOR;


				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX_X)
				{//+X

					ESCAPEMOVE.x = ParentGateMax.x + (PlayerMax.x - pPlayer->pos.x) + 11.1f;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
					ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

					pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

				}
				else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MIN_X)
				{//-X

					ESCAPEMOVE.x = ParentGateMin.x + (PlayerMin.x - pPlayer->pos.x) - 11.1f;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
					ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

					pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

				}
				else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX_Z)
				{//+Z

					ESCAPEMOVE.z = ParentGateMax.z - (PlayerMin.z - pPlayer->pos.z) + 11.1f;

					ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

					pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

					//pCamera->rot.y = 0.0f;
				}
				else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MIN_Z)
				{//-Z

					ESCAPEMOVE.z = ParentGateMin.z - (PlayerMax.z - pPlayer->pos.z) - 11.1f;
					ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

					pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

					//pCamera->rot.y = 3.14f;
				}

				SetGameFade(0, ESCAPEMOVE);

				if (pTransferGate[ParentIndex].bCompulsionTrans == true)
				{//プレイヤー２も転移
					SetGameFade(1, ESCAPEMOVE);
				}




			}



		}
		else if (PlayerIndex == 1)
		{//2Pの時
			Player_2P* pPlayer2;
			pPlayer2 = GetPlayer_2P();

			//接触したか
			bool bHit = false;

			//---------------------------------------X方向

			if (PlayerMin.z < GateMax.z &&
				PlayerMax.z > GateMin.z &&
				PlayerMax.x - pPlayer2->pos.x + pPlayer2->oldPos.x <= GateMin.x &&
				PlayerMax.x > GateMin.x &&
				PlayerMin.y < GateMax.y &&
				PlayerMax.y > GateMin.y)
			{
				bHit = true;

				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX)
				{//初期値の時--進行方向に転移

					ESCAPEMOVE.x = ParentGateMax.x + (PlayerMax.x - pPlayer2->pos.x) + 0.1f;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
					ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;
					pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
			}
			else if (PlayerMin.z < GateMax.z &&
				PlayerMax.z > GateMin.z &&
				PlayerMin.x - pPlayer2->pos.x + pPlayer2->oldPos.x >= GateMax.x &&
				PlayerMin.x < GateMax.x &&
				PlayerMin.y < GateMax.y &&
				PlayerMax.y > GateMin.y)
			{

				bHit = true;

				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX)
				{//初期値の時--進行方向に転移
					ESCAPEMOVE.x = ParentGateMin.x + (PlayerMin.x - pPlayer2->pos.x) - 0.1f;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
					ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

					pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
			}
			//---------------------------------------Z方向
			else if (PlayerMin.x < GateMax.x &&
				PlayerMax.x > GateMin.x &&
				PlayerMin.z - pPlayer2->pos.z + pPlayer2->oldPos.z >= GateMax.z &&
				PlayerMin.z < GateMax.z &&
				PlayerMin.y < GateMax.y &&
				PlayerMax.y > GateMin.y)
			{
				bHit = true;

				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX)
				{//初期値の時--進行方向に転移
					ESCAPEMOVE.z = ParentGateMin.z - (PlayerMax.z - pPlayer2->pos.z) - 0.1f;
					ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

					pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
			}
			else if (PlayerMin.x < GateMax.x &&
				PlayerMax.x > GateMin.x &&
				PlayerMax.z - pPlayer2->pos.z + pPlayer2->oldPos.z <= GateMin.z &&
				PlayerMax.z > GateMin.z &&
				PlayerMin.y < GateMax.y &&
				PlayerMax.y > GateMin.y)
			{
				bHit = true;

				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX)
				{//初期値の時--進行方向に転移
					ESCAPEMOVE.z = ParentGateMax.z - (PlayerMin.z - pPlayer2->pos.z) + 0.1f;
					ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

					pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
			}

			//------------------------------------Y方向
			/*if (PlayerMin.x < GateMax.x &&
				PlayerMax.x > GateMin.x &&
				PlayerMin.z < GateMax.z &&
				PlayerMax.z > GateMin.z &&
				PlayerMin.y - pPlayer2->pos.y + pPlayer2->oldPos.y >= GateMax.y &&
				PlayerMin.y < GateMax.y)
			{
				pPlayer2->move.y = 0.0f;
				pPlayer2->pos.y = GateMax.y + (PlayerMin.y - pPlayer2->pos.y);

				if (pPlayer2->NowMotionDOWN == MOTIONTYPE_2P_JUMP)
				{
					pPlayer2->NowMotionDOWN = MOTIONTYPE_2P_RANDING;
				}
				else if (pPlayer2->NowMotionDOWN == MOTIONTYPE_2P_MOVE)
				{
					pPlayer2->NowMotionDOWN = MOTIONTYPE_2P_MOVE;
				}

				pPlayer2->bLandingNow = true;
			}*/

			if (bHit == true)
			{//接触判定時

				pPlayer2->PlayerState = PLAYERSTATE_2P_TELEPOR;



				if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX_X)
				{//+X
					ESCAPEMOVE.x = ParentGateMax.x + (PlayerMax.x - pPlayer2->pos.x) + 11.1f;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
					ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

					pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
				else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MIN_X)
				{//-X
					ESCAPEMOVE.x = ParentGateMin.x + (PlayerMin.x - pPlayer2->pos.x) - 11.1f;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
					ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

					pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				}
				else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX_Z)
				{//+Z
					ESCAPEMOVE.z = ParentGateMax.z - (PlayerMin.z - pPlayer2->pos.z) + 11.1f;
					ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

					pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

					//pCamera->rot.y = 0.0f;
				}
				else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MIN_Z)
				{//-Z
					ESCAPEMOVE.z = ParentGateMin.z - (PlayerMax.z - pPlayer2->pos.z) - 11.1f;
					ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
					ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

					pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

					//pCamera->rot.y = 3.14f;
				}


				SetGameFade(1, ESCAPEMOVE);

				if (pTransferGate[ParentIndex].bCompulsionTrans == true)
				{//プレイヤー1も転移
					SetGameFade(0, ESCAPEMOVE);
				}
			}


		}
	}
	else if (pTransferGate[ParentIndex].bActiomTrans == true)
	{//アクションで転移

	//1Pのとき
		if (PlayerIndex == 0)
		{
			//接触したか
			bool bHit = false;

			Player* pPlayer;
			pPlayer = GetPlayer();



			if (GateMin.x<=pPlayer->pos.x&&pPlayer->pos.x<=GateMax.x)
			{
				if (GateMin.y <=( pPlayer->pos.y + PlayerCenterCorre) && (pPlayer->pos.y + PlayerCenterCorre) <= GateMax.y)
				{
					if (GateMin.z <= pPlayer->pos.z && pPlayer->pos.z <= GateMax.z)
					{
						bHit = true;
					}
				}
			}
	
			if (bHit == true)
			{//接触判定時

				if (pPlayer->bAction == true)
				{

					pPlayer->PlayerState = PLAYERSTATE_1P_TELEPOR;


					if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX_X)
					{//+X

						ESCAPEMOVE.x = ParentGateMax.x + (PlayerMax.x - pPlayer->pos.x) + 11.1f;
						ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
						ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

						pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

					}
					else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MIN_X)
					{//-X

						ESCAPEMOVE.x = ParentGateMin.x + (PlayerMin.x - pPlayer->pos.x) - 11.1f;
						ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
						ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

						pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

					}
					else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX_Z)
					{//+Z

						ESCAPEMOVE.z = ParentGateMax.z - (PlayerMin.z - pPlayer->pos.z) + 11.1f;

						ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
						ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

						pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

						//pCamera->rot.y = 0.0f;
					}
					else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MIN_Z)
					{//-Z

						ESCAPEMOVE.z = ParentGateMin.z - (PlayerMax.z - pPlayer->pos.z) - 11.1f;
						ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
						ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

						pPlayer->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

						//pCamera->rot.y = 3.14f;
					}

					SetGameFade(0, ESCAPEMOVE);

					if (pTransferGate[ParentIndex].bCompulsionTrans == true)
					{//プレイヤー２も転移
						SetGameFade(1, ESCAPEMOVE);
					}
				}
			}
		}
		else if (PlayerIndex == 1)
		{//2Pの時
			Player_2P* pPlayer2;
			pPlayer2 = GetPlayer_2P();

			//接触したか
			bool bHit = false;


			if (GateMin.x <= pPlayer2->pos.x && pPlayer2->pos.x <= GateMax.x)
			{
				if (GateMin.y <= (pPlayer2->pos.y + PlayerCenterCorre) && (pPlayer2->pos.y + PlayerCenterCorre) <= GateMax.y)
				{
					if (GateMin.z <= pPlayer2->pos.z && pPlayer2->pos.z <= GateMax.z)
					{
						bHit = true;
					}
				}
			}

			

			if (bHit == true)
			{//接触判定時

				if (pPlayer2->bAction == true)
				{
					pPlayer2->PlayerState = PLAYERSTATE_2P_TELEPOR;



					if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX_X)
					{//+X
						ESCAPEMOVE.x = ParentGateMax.x + (PlayerMax.x - pPlayer2->pos.x) + 11.1f;
						ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
						ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

						pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					}
					else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MIN_X)
					{//-X
						ESCAPEMOVE.x = ParentGateMin.x + (PlayerMin.x - pPlayer2->pos.x) - 11.1f;
						ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;
						ESCAPEMOVE.z = pTransferGate[ParentIndex].pos.z;

						pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
					}
					else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MAX_Z)
					{//+Z
						ESCAPEMOVE.z = ParentGateMax.z - (PlayerMin.z - pPlayer2->pos.z) + 11.1f;
						ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
						ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

						pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

						//pCamera->rot.y = 0.0f;
					}
					else if (pTransferGate[GateIndex].ParentTransAngle == TRANS_ANGLE_MIN_Z)
					{//-Z
						ESCAPEMOVE.z = ParentGateMin.z - (PlayerMax.z - pPlayer2->pos.z) - 11.1f;
						ESCAPEMOVE.x = pTransferGate[ParentIndex].pos.x;
						ESCAPEMOVE.y = pTransferGate[ParentIndex].pos.y;

						pPlayer2->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

						//pCamera->rot.y = 3.14f;
					}


					SetGameFade(1, ESCAPEMOVE);

					if (pTransferGate[ParentIndex].bCompulsionTrans == true)
					{//プレイヤー1も転移
						SetGameFade(0, ESCAPEMOVE);
					}
				}
			}


		}


	}





	////// 上下の辺
	////SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	////SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));

	////SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	////SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));

	////// 側面の辺																											
	////SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	////SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));

	////SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	////SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));


	////// その他の辺																									   
	////SetLine(D3DXVECTOR3(HitMin.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	////SetLine(D3DXVECTOR3(HitMax.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));

	////SetLine(D3DXVECTOR3(HitMin.x, HitMax.y, HitMin.z), D3DXVECTOR3(HitMin.x, HitMax.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
	////SetLine(D3DXVECTOR3(HitMax.x, HitMin.y, HitMin.z), D3DXVECTOR3(HitMax.x, HitMin.y, HitMax.z), D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));

}

//===================================
//行動エリア円形当たり判定(アクションゾーン)
//===================================
void SphereCollisionZone(D3DXVECTOR3 PlayerPos, int PlayerIndex, int ZoneIndex)
{//当たり判定
//	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	Camera* pCamera;
	pCamera = GetCamera();
	
		Player* pPlayer;
	pPlayer = GetPlayer();

	Player_2P* pPlayer2;
	pPlayer2 = GetPlayer_2P();


	ACTIONZONE* pActionZone;
	pActionZone = GetActionZone();


	float PlayerCenterCorre = 45.0f;

		//接触したか
		bool bIn = false;

		//プレイヤーのposとエリアのposの差分を計算
		
		//差分ベクトル格納
		D3DXVECTOR3 diff;
		//1Pのとき
		if (PlayerIndex == 0)
		{
			PlayerPos.y += PlayerCenterCorre;//中心位置補正

			//差分ベクトルを計算
			diff = PlayerPos - pActionZone[ZoneIndex].pos;

		}
		else if (PlayerIndex == 1)
		{//2Pの時
			PlayerPos.y += PlayerCenterCorre;//中心位置補正

			//差分ベクトルを計算
			diff = PlayerPos - pActionZone[ZoneIndex].pos;
		}



		//各要素を二乗して入れる
		float squaredLength = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;

		//平方根を取る（直線差分）
		float distance = sqrt(squaredLength);

		if (distance < pActionZone[ZoneIndex].Radius)
		{//差分の距離が半径より短い==円の中にいる時
			bIn = true;//接触判定
		}

		if (bIn == true)
		{//接触判定時
			SetSpeechBubble(pActionZone[ZoneIndex].pos, ZoneIndex, 0);
		}
		else
		{
			SetSpeechBubble(pActionZone[ZoneIndex].pos, ZoneIndex, 1);
		}


	//1Pのとき
	if (PlayerIndex == 0)
	{
		//範囲内でアクションの種別ごとに動作
		
		if (bIn == true)
		{//接触判定時
			
			//pActionZone[ZoneIndex].ZoneColor = D3DXCOLOR(1.0f, 5.0f, 2.0f,0.2f);
			pActionZone[ZoneIndex].bDrawOk = false;
		}
		else
		{
			pActionZone[ZoneIndex].bDrawOk = true;
		}

		if (pPlayer->bAction == true)
		{//アクション

			//動作ごとに分岐
			if (pActionZone[ZoneIndex].ActionType==ACTION_TYPE_MAX)
			{//

			}
			if (pActionZone[ZoneIndex].ActionType == ACTION_TYPE_BATH && bIn == true)
			{//お風呂のギミック（1P）
				if (GetJoypadTrigger(JOYKEY_X, 0) == true)
				{//お風呂のギミック作動
					RunWater(0);
				}
			}
			if (pActionZone[ZoneIndex].ActionType == ACTION_TYPE_BUTTON_1 && bIn == true)
			{
				if (GetJoypadTrigger(JOYKEY_X, 0) == true)
				{//地下室のギミック作動
					//ボタン1起動
					SetSteam(pActionZone[ZoneIndex].pos, D3DXVECTOR3(0.0f, 20.0f, 0.0f));

				}
			}
			if (pActionZone[ZoneIndex].ActionType == ACTION_TYPE_BUTTON_2 && bIn == true)
			{
				if (GetJoypadTrigger(JOYKEY_X, 0) == true)
				{//地下室のギミック作動
					//ボタン2起動
					SetSteam(pActionZone[ZoneIndex].pos, D3DXVECTOR3(0.0f, 20.0f, 0.0f));
				}
			}
			if (pActionZone[ZoneIndex].ActionType == ACTION_TYPE_TOILET && bIn == true)
			{
				if (GetJoypadTrigger(JOYKEY_X, 0) == true)
				{//地下室のギミック作動
					//ボタン2起動
					SetItem(pActionZone[ZoneIndex].pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), ITEMTYPE_SIKIGAMI);
				}
			}
		}
	}
	else if (PlayerIndex == 1)
	{//2Pの時
		if (bIn == true)
		{//接触判定時

			pActionZone[ZoneIndex].ZoneColor = D3DXCOLOR(2.0f, 1.0f, 2.0f, 0.2f);
		}

		if (pPlayer2->bAction == true)
		{//アクション
			//動作ごとに分岐
			if (pActionZone[ZoneIndex].ActionType == ACTION_TYPE_MAX)
			{//

			}
			if (pActionZone[ZoneIndex].ActionType == ACTION_TYPE_BATH && bIn == true)
			{//お風呂のギミック（2P）
				if (GetJoypadTrigger(JOYKEY_X, 1) == true)
				{//お風呂のギミック作動
					RunWater(1);
				}
			}
			if (pActionZone[ZoneIndex].ActionType == ACTION_TYPE_BUTTON_1 && bIn == true)
			{
				if (GetJoypadTrigger(JOYKEY_X, 1) == true)
				{
					//ボタン1起動
					SetSteam(pActionZone[ZoneIndex].pos, D3DXVECTOR3(0.0f,20.0f,0.0f));
				}
			}
			if (pActionZone[ZoneIndex].ActionType == ACTION_TYPE_BUTTON_2 && bIn == true)
			{
				if (GetJoypadTrigger(JOYKEY_X, 1) == true)
				{
					//ボタン2起動
					SetSteam(pActionZone[ZoneIndex].pos, D3DXVECTOR3(0.0f, 20.0f, 0.0f));
				}
			}
		}
	}
}


//===================================
//プレイヤー箱型当たり判定--アイテム
//===================================
void BoxCollisionItem(D3DXVECTOR3 PlayerMin, D3DXVECTOR3 PlayerMax, D3DXVECTOR3 HitPos, int PlayerIndex,int ItemIndex)
{//当たり判定
	//LPDIRECT3DDEVICE9 pDevice = GetDevice();
	ITEM* pItem;
	pItem = GetItem();



	bool bGet = false;

	if (HitPos.x >= PlayerMin.x && HitPos.x <= PlayerMax.x)
	{
		if (HitPos.y >= PlayerMin.y && HitPos.y <= PlayerMax.y)
		{
			if (HitPos.z >= PlayerMin.z && HitPos.z <= PlayerMax.z)
			{
				bGet = true;

			}
		}
	}

	//1Pのとき
	if (PlayerIndex == 1)
	{
		//Player* pPlayer;
		//pPlayer = GetPlayer();
		if (bGet == true)
		{
			GetItem(ItemIndex,1);
		}
	}
	else if (PlayerIndex == 2)
	{//2Pの時
		Player_2P* pPlayer2;
		pPlayer2 = GetPlayer_2P();
		if (bGet == true)
		{
			GetItem(ItemIndex, 2);
	//		pItemCnt_2P[pItem[ItemIndex].ItemType].ItemCnt++;
	//		pItem[ItemIndex].bUse = false;
		}
	}
}









































//ここから先、万が一ように、バレット、敵　の当たり判定を残してある------------------------------------------------------------


//
////===================================
////箱型当たり判定--敵使用
////===================================
//void BoxCollisionEnamy(int EnemyIndex, D3DXVECTOR3 EnamyMin, D3DXVECTOR3 EnamyMax, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax)
//{
//	LPDIRECT3DDEVICE9 pDevice = GetDevice();
//
//	Enemy* pEnemy;
//	pEnemy = GetEnemy();
//
//	if (pEnemy[EnemyIndex].pos.x >= HitMin.x && pEnemy[EnemyIndex].pos.x <= HitMax.x)
//	{
//		if (pEnemy[EnemyIndex].pos.y >= HitMin.y && pEnemy[EnemyIndex].pos.y <= HitMax.y)
//		{
//			if (pEnemy[EnemyIndex].pos.z >= HitMin.z && pEnemy[EnemyIndex].pos.z <= HitMax.z)
//			{//範囲内に入った
//
//				//時間がなくて下記を修正できないので簡素的当たり判定
//				pEnemy[EnemyIndex].move =D3DXVECTOR3( 0.0f,0.0f,0.0f);
//				pEnemy[EnemyIndex].pos = pEnemy[EnemyIndex].oldPos;
//
//
//				//何故かうまく行かないが、めちゃ時間無いので、ここは簡素に上記の判定のみにする。次回までに修正
//
//
//				////---------------------------------------X方向
//				//if (EnamyMin.z < HitMax.z &&
//				//	EnamyMax.z > HitMin.z &&
//				//	EnamyMax.x - pEnemy[EnemyIndex].pos.x + pEnemy[EnemyIndex].oldPos.x <= HitMin.x &&
//				//	EnamyMax.x > HitMin.x &&
//				//	EnamyMin.y < HitMax.y &&
//				//	EnamyMax.y > HitMin.y)
//				//{
//				//	pEnemy[EnemyIndex].move.x = 0.0f;
//				//	pEnemy[EnemyIndex].pos.x = HitMin.x + (EnamyMin.x - pEnemy[EnemyIndex].pos.x) - 0.1f;
//				//}
//
//				//if (EnamyMin.z < HitMax.z &&
//				//	EnamyMax.z > HitMin.z &&
//				//	EnamyMin.x - pEnemy[EnemyIndex].pos.x + pEnemy[EnemyIndex].oldPos.x >= HitMax.x &&
//				//	EnamyMin.y < HitMax.y &&
//				//	EnamyMax.y > HitMin.y)
//				//{
//				//	pEnemy[EnemyIndex].move.x = 0.0f;
//				//	pEnemy[EnemyIndex].pos.x = HitMax.x + (EnamyMax.x - pEnemy[EnemyIndex].pos.x) + 0.1f;
//				//}
//
//				////---------------------------------------Z方向
//				//if (EnamyMin.x < HitMax.x &&
//				//	EnamyMax.x > HitMin.x &&
//				//	EnamyMin.z - pEnemy[EnemyIndex].pos.z + pEnemy[EnemyIndex].oldPos.z >= HitMax.z &&
//				//	EnamyMin.z < HitMax.z &&
//				//	EnamyMin.y < HitMax.y &&
//				//	EnamyMax.y > HitMin.y)
//				//{
//				//	pEnemy[EnemyIndex].move.z = 0.0f;
//				//	pEnemy[EnemyIndex].pos.z = HitMax.z - (EnamyMin.z - pEnemy[EnemyIndex].pos.z) + 0.1f;
//				//}
//
//				//if (EnamyMin.x < HitMax.x &&
//				//	EnamyMax.x > HitMin.x &&
//				//	EnamyMax.z - pEnemy[EnemyIndex].pos.z + pEnemy[EnemyIndex].oldPos.z <= HitMin.z &&
//				//	EnamyMax.z > HitMin.z &&
//				//	EnamyMin.y < HitMax.y &&
//				//	EnamyMax.y > HitMin.y)
//				//{
//				//	pEnemy[EnemyIndex].move.z = 0.0f;
//				//	pEnemy[EnemyIndex].pos.z = HitMin.z - (EnamyMax.z - pEnemy[EnemyIndex].pos.z) - 0.1f;
//				//}
//
//				////------------------------------------Y方向
//				//if (EnamyMin.x < HitMax.x &&
//				//	EnamyMax.x > HitMin.x &&
//				//	EnamyMin.z < HitMax.z &&
//				//	EnamyMax.z > HitMin.z &&
//				//	EnamyMin.y - pEnemy[EnemyIndex].pos.y + pEnemy[EnemyIndex].oldPos.y >= HitMax.y &&
//				//	EnamyMin.y < HitMax.y)
//				//{
//				//	pEnemy[EnemyIndex].move.y = 0.0f;
//				//	pEnemy[EnemyIndex].pos.y = HitMax.y + (EnamyMin.y + pEnemy[EnemyIndex].pos.y )+2.0f;
//				//}
//			}
//		}
//	}
//}




//
////===================================
////箱型当たり判定-バレット使用
////===================================
//void BoxCollisionBullet(int BulletIndex, D3DXVECTOR3 HitMin, D3DXVECTOR3 HitMax, EXISTENCETYPE type)
//{
//	LPDIRECT3DDEVICE9 pDevice = GetDevice();
//
//	HP* pHp;
//	pHp = GetHP();
//
//
//	BULLET* pBulletI;
//	pBulletI = GetBullet();
//
//	bool bHit=false;
//
//	if (pBulletI[BulletIndex].pos.x>= HitMin.x&& pBulletI[BulletIndex].pos.x <= HitMax.x)
//	{
//		if (pBulletI[BulletIndex].pos.y >= HitMin.y && pBulletI[BulletIndex].pos.y <= HitMax.y)
//		{
//			if (pBulletI[BulletIndex].pos.z >= HitMin.z && pBulletI[BulletIndex].pos.z <= HitMax.z)
//			{
//				bHit = true;
//			}
//		}
//
//	}
//
//	if (bHit == true)
//	{
//		EndProcessShadow(pBulletI[BulletIndex].nShadowNum);
//		SetExplosion(pBulletI[BulletIndex].pos,EXPLOSIONTYPE_BULLET);
//
//
//	//	EndProcessShadow(g_Bullet[nBullet].nShadowNum);
//	//	SetExplosion(g_Bullet[nBullet].pos);
//		//g_Bullet[nBullet].bUse = false;
//
//
//		pBulletI[BulletIndex].bUse = false;
//
//		if (type == EXISTENCETYPE_PLAYER)
//		{
//			HitBullet_tPlayer();
//
//			pHp[HPTYPE_PLAYER].HPstate = HPSTATE_DAMAGE;
//			pHp[HPTYPE_PLAYER].nParCnt = 5;
//		}
//	}
//
//}
