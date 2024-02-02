//==================================================
//
//ゲーム内フェードに関する処理[GameFade.cpp]
// Author seiya kagaya
//
//==================================================
#include "main.h"
#include "gamefade.h"
#include "player.h"
#include "player2.h"
//#include "sound.h"

//グローバル変数宣言
GAMEFADE g_GameFade[MAXGAMEFADE];
D3DXCOLOR g_colorGameFade[MAXGAMEFADE];
//MODE g_ModeNext;
LPDIRECT3DTEXTURE9 g_pTextureGameFade = NULL;       //テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffGameFade = NULL; //頂点バッファへのポインタ

//int g_GameFadeCnt[MAXGAMEFADE] = {};//ゲーム画面への移行時かすかに色が残る問題を対策

D3DXVECTOR3 g_EscapeMove[MAXGAMEFADE];


bool g_PlayerBlack = false;
bool g_Player2Black = false;
//=============================
//ゲーム内フェードの初期化処理
//=============================
void InitGameFade(void)
{
	LPDIRECT3DDEVICE9 pDevice;  //デバイスへのポインタ

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4*MAXGAMEFADE,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffGameFade,
		NULL);



	//D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\ki.jpg", &g_pTextureGameFade);	//タイトル背景

	VERTEX_2D* pVtx;  //頂点情報のポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffGameFade->Lock(0, 0, (void**)&pVtx, 0);

	for (int FadeCnt = 0; FadeCnt < MAXGAMEFADE; FadeCnt++)
	{
		g_EscapeMove[FadeCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//変数の初期化
		g_colorGameFade[FadeCnt].a = 0.0f;

		g_GameFade[FadeCnt] = GAMEFADE_NONE;

		//g_GameFadeCnt[FadeCnt] = 0;

		if (FadeCnt == 0)
		{//カメラ1のいち
			//頂点座標の設定
			pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE/2.0f, 0.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE/2.0f, SCREEN_HEIGHT, 0.0f);
		}
		else if(FadeCnt==1)
		{//カメラ2のいち
			//頂点座標の設定
			pVtx[0].pos = D3DXVECTOR3(SCREEN_WIDE/2.0f, 0.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(SCREEN_WIDE/2.0f, SCREEN_HEIGHT, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);
		}




		//rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
		pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
		pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
		pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

		//テクスチャ座標を設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//左上
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//右上
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//左下
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//右下


		pVtx += 4;
	}
	//頂点バッファのアンロック
	g_pVtxBuffGameFade->Unlock();
}
//=============================
//ゲーム内フェードの終了処理
//=============================
void UninitGameFade(void)
{
	//頂点バッファの破棄
	if (g_pVtxBuffGameFade != NULL)
	{
		g_pVtxBuffGameFade->Release();
		g_pVtxBuffGameFade = NULL;
	}
	//テクスチャの破棄
	if (g_pTextureGameFade != NULL)
	{
		g_pTextureGameFade->Release();
		g_pTextureGameFade = NULL;
	}
}
//=============================
//ゲーム内フェードの更新処理
//=============================
void UpdateGameFade(void)
{
	VERTEX_2D* pVtx;  //頂点情報のポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffGameFade->Lock(0, 0, (void**)&pVtx, 0);

	Player* pPlayer;
	pPlayer = GetPlayer();

	Player_2P* pPlayer2;
	pPlayer2 = GetPlayer_2P();


	for (int FadeCnt = 0; FadeCnt < MAXGAMEFADE; FadeCnt++)
	{
		if (g_GameFade[FadeCnt] != GAMEFADE_NONE)
		{
			if (g_GameFade[FadeCnt] == GAMEFADE_IN)
			{//ゲーム内フェードイン状態

				g_colorGameFade[FadeCnt].a -= 0.03f;	//ポリゴンを透明にしていく

				if (g_colorGameFade[FadeCnt].a <= 0.0f)
				{
					g_colorGameFade[FadeCnt].a = 0.0f;


					g_GameFade[FadeCnt] = GAMEFADE_NONE;	//何もしていない状態
				}
			}
			else if (g_GameFade[FadeCnt] == GAMEFADE_OUT)
			{//ゲーム内フェードアウト状態
				g_colorGameFade[FadeCnt].a += 0.07f;	//ポリゴンを不透明にしていく

				if (g_colorGameFade[FadeCnt].a >= 1.0f)
				{
					g_colorGameFade[FadeCnt].a = 1.0f;

				//	g_GameFadeCnt[FadeCnt]++;//モード移行カウンター

					if (FadeCnt==0)
					{
						pPlayer->pos = g_EscapeMove[FadeCnt];
						pPlayer->PlayerState = PLAYERSTATE_1P_NOMAL;

					}
					else if(FadeCnt == 1)
					{
						pPlayer2->pos = g_EscapeMove[FadeCnt];
						pPlayer2->PlayerState = PLAYERSTATE_2P_NOMAL;

					}


					g_GameFade[FadeCnt] = GAMEFADE_IN;	//ゲーム内フェードイン状態
				}

			//	if (g_GameFadeCnt[FadeCnt] == 1)
			//	{//色が薄く残る問題を解決
			//		//モード設定(次の画面に移行)
			////		Setmode(g_ModeNext);
			//		g_GameFadeCnt[FadeCnt] = 0;
			//	}
			}

			if (FadeCnt == 0)
			{//カメラ1のいち
				//頂点座標の設定
				pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, 0.0f, 0.0f);
				pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
				pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, SCREEN_HEIGHT, 0.0f);

			}
			else if (FadeCnt == 1)
			{//カメラ2のいち
				//頂点座標の設定
				pVtx[0].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, 0.0f, 0.0f);
				pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
				pVtx[2].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, SCREEN_HEIGHT, 0.0f);
				pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);



				//test
				//頂点座標の設定
			//	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
			//	pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
			//	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);


			}
		

			//頂点カラーの設定
			pVtx[0].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorGameFade[FadeCnt].a);
			pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorGameFade[FadeCnt].a);
			pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorGameFade[FadeCnt].a);
			pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorGameFade[FadeCnt].a);


			pVtx += 4;
		}
	}
	//頂点バッファのアンロック
	g_pVtxBuffGameFade->Unlock();
}
//=============================
//ゲーム内フェードの描画処理
//=============================
void DrawGameFade(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffGameFade, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int FadeCnt = 0; FadeCnt < MAXGAMEFADE; FadeCnt++)
	{
//		if (g_GameFade[FadeCnt] != GAMEFADE_NONE)
//		{
			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureGameFade);//---------書き換え済み

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, FadeCnt * 4, 2);
//		}
	}
}
//=============================
//ゲーム内フェードの設定処理
//=============================
void SetGameFade(int PlayerNum, D3DXVECTOR3 ESCAPEMOVE)
{
//	for (int FadeCnt = 0; FadeCnt < MAXGAMEFADE; FadeCnt++)
	//{
		if (g_GameFade[PlayerNum] == GAMEFADE_NONE)
		{
		//	g_colorGameFade[PlayerNum].a = 0.0f;
		//	g_GameFadeCnt[PlayerNum] = 0;
			g_colorGameFade[PlayerNum] = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);			//黒いポリゴン(透明)にしておく
			g_GameFade[PlayerNum] = GAMEFADE_OUT;											//ゲーム内フェードアウト状態に
			g_EscapeMove[PlayerNum]= ESCAPEMOVE;//移動量

		//	g_ModeNext = mode_next;										//次の画面(モード)を設定

		}
//	}
}
//=============================
//ゲーム内フェードの取得処理
//=============================
GAMEFADE GetGameFade(void)
{
	return g_GameFade[0];
}
