//============================================================================================
//
//タイトル表示する処理[screenui.cpp]
// Author seiya kagaya
//
//============================================================================================
#include "screenui.h"


//#include "player.h"
#//include "input.h"
//#include "fade.h"
//#include "sound.h"




//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureScreenUI[NUM_UI] = {};//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffScreenUI = NULL;//頂点バッファへのポリゴン
ScreenUI g_ScreenUI[NUM_UI];//タイトルの情報
//D3DXCOLOR g_colorfade[NUM_UI];
SCREENUISTATE g_ScreenUIState;//フェード時の識別

//=============================
//タイトル画面の初期化処理
//=============================
void InitScreenUI(void)
{
	int nCntScreenUI = 0;

	g_ScreenUIState = SCREENUI_MAX;

	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

	//デバイスの取得
	pDevice = GetDevice();

	VERTEX_2D* pVtx;//頂点情報のポインタ

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\blood.jpg", &g_pTextureScreenUI[0]);	//とりま血
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Watch.png", &g_pTextureScreenUI[1]);	//ゲームの名前

			//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 12, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffScreenUI, NULL);

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffScreenUI->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntScreenUI = 0; nCntScreenUI < NUM_UI; nCntScreenUI++)
	{
			//g_colorfade[nCntScreenUI].a = 0.0f;

		g_ScreenUI[nCntScreenUI].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//rhwの設定
		pVtx[0].rhw = 1.0f;//値は固定
		pVtx[1].rhw = 1.0f;//値は固定
		pVtx[2].rhw = 1.0f;//値は固定
		pVtx[3].rhw = 1.0f;//値は固定]

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//頂点座標の更新-----------------------------------
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//テクスチャ座標を設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//左上
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//右上
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//左下
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//右下

		pVtx += 4;
	}

	//頂点バッファをアンロックする
	g_pVtxBuffScreenUI->Unlock();

	//PlaySound(SOUND_LABEL_BGM000);
}
//=============================
//タイトル画面の終了処理
//=============================
void UninitScreenUI(void)
{
	//StopSound(SOUND_LABEL_BGM000);

	int nCntScreenUI = 0;

	for (nCntScreenUI = 0; nCntScreenUI < NUM_UI; nCntScreenUI++)
	{
		//テクスチャの破棄
		if (g_pTextureScreenUI[nCntScreenUI] != NULL)
		{
			g_pTextureScreenUI[nCntScreenUI]->Release();
			g_pTextureScreenUI[nCntScreenUI] = NULL;
		}
	}
	//頂点バッファの破棄
	if (g_pVtxBuffScreenUI != NULL)
	{
		g_pVtxBuffScreenUI->Release();
		g_pVtxBuffScreenUI = NULL;
	}
}
//=============================
//タイトル画面の更新処理
//=============================
void UpdateScreenUI(void)
{
	int nCntScreenUI = 0;

	VERTEX_2D* pVtx;//頂点情報のポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffScreenUI->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntScreenUI = 0; nCntScreenUI < NUM_UI; nCntScreenUI++)
	{
		if (nCntScreenUI == SCREENUI_1)
		{//
			g_ScreenUI[nCntScreenUI].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);

			//頂点座標の更新-----------------------------------
			pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);

			//頂点カラーの設定
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);

		}
		else if (nCntScreenUI == SCREENUI_WATCH)
		{//時計のとき
			g_ScreenUI[nCntScreenUI].pos = D3DXVECTOR3((SCREEN_WIDE / 2.0f)-90.0f, SCREEN_HEIGHT -700.0f, 0.0f);

			//頂点座標の更新-----------------------------------
			pVtx[0].pos = D3DXVECTOR3(g_ScreenUI[nCntScreenUI].pos.x - 20.0f, g_ScreenUI[nCntScreenUI].pos.y - 20.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_ScreenUI[nCntScreenUI].pos.x + 20.0f, g_ScreenUI[nCntScreenUI].pos.y - 20.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_ScreenUI[nCntScreenUI].pos.x - 20.0f, g_ScreenUI[nCntScreenUI].pos.y + 20.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_ScreenUI[nCntScreenUI].pos.x + 20.0f, g_ScreenUI[nCntScreenUI].pos.y + 20.0f, 0.0f);

			//頂点カラーの設定
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		}


		//テクスチャ座標を設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//左上
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//右上
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//左下
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//右下

		pVtx += 4;
	}
	//頂点バッファをアンロックする
	g_pVtxBuffScreenUI->Unlock();
}
//=============================
//タイトル画面の描画処理
//=============================
void DrawScreenUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

	//デバイスの取得
	pDevice = GetDevice();//----------------書き換え済み

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffScreenUI, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);//-------書き換え済み

	int nCntScreenUI = 0;

	for (nCntScreenUI = 0; nCntScreenUI < NUM_UI; nCntScreenUI++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureScreenUI[nCntScreenUI]);//---------書き換え済み

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//プリミティブの種類//----------書き換え済み
			nCntScreenUI * 4,//描画する最初の頂点インデックス
			2);//描画するプリミティブ数
	}
}
