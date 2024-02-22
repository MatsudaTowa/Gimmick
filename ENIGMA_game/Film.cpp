//==============================
//
// フィルム動かす[Film.cpp]
// Author:Kaito Hondo
//
//==============================

#include "main.h"
#include "Film.h"

// マクロ定義
#define NUM_FILM	(3)// 背景の数

// グローバル変数
LPDIRECT3DTEXTURE9 g_apTextureFILM[NUM_FILM] = {};	// テクスチャ（３枚分）へのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffFILM = NULL;	// 頂点バッファへのポインタ
float g_aPosTexV[NUM_FILM];						// テクスチャ座標の開始位置（V値）

// 背景の初期化処理
void InitFILM(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntFILM;

	// デバイスの取得
	pDevice = GetDevice();

	// テクスチャ３枚分の読み込み
	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, FILM_TEXTURE, &g_apTextureFILM[0]);
	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, FILM_TEXTURE2, &g_apTextureFILM[1]);
	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, FILM_TEXTURE3, &g_apTextureFILM[2]);

	// テクスチャ座標の開始位置（V値）の初期化
	for (nCntFILM = 0; nCntFILM < NUM_FILM; nCntFILM++)
	{
		g_aPosTexV[nCntFILM] = 0.0f;
	}

	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_FILM, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffFILM, NULL);

	VERTEX_2D* pVtx;

	// 頂点バッファをロックし、頂点データへのポインタを獲得
	g_pVtxBuffFILM->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntFILM = 0; nCntFILM < NUM_FILM; nCntFILM++)
	{
		// 頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);

		// rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// 頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(255, 255, 255, 255);
		pVtx[1].col = D3DXCOLOR(255, 255, 255, 255);
		pVtx[2].col = D3DXCOLOR(255, 255, 255, 255);
		pVtx[3].col = D3DXCOLOR(255, 255, 255, 255);

		// テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, g_aPosTexV[nCntFILM]);
		pVtx[1].tex = D3DXVECTOR2(1.0f, g_aPosTexV[nCntFILM]);
		pVtx[2].tex = D3DXVECTOR2(0.0f, g_aPosTexV[nCntFILM] + 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, g_aPosTexV[nCntFILM] + 1.0f);

		pVtx += 4;// 頂点データのポインタを４つ分進める
	}

	// 頂点バッファをアンロックする
	g_pVtxBuffFILM->Unlock();
}

// 背景の終了処理
void UninitFILM(void)
{
	int nCount;

	// テクスチャの破棄
	for (nCount = 0; nCount < NUM_FILM; nCount++)
	{

		if (g_apTextureFILM[nCount] != NULL)
		{
			g_apTextureFILM[nCount]->Release();
			g_apTextureFILM[nCount] = NULL;
		}
	}
	// 頂点バッファの破棄
	if (g_pVtxBuffFILM != NULL)
	{
		g_pVtxBuffFILM->Release();
		g_pVtxBuffFILM = NULL;
	}
}

// 背景の更新処理
void UpdateFILM(void)
{
	int nCntFILM;
	VERTEX_2D* pVtx;

	// 頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffFILM->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntFILM = 0; nCntFILM < NUM_FILM; nCntFILM++)
	{
		g_aPosTexV[nCntFILM] += -0.009f;

		pVtx[0].tex = D3DXVECTOR2(0.0f, g_aPosTexV[nCntFILM]);
		pVtx[1].tex = D3DXVECTOR2(1.0f, g_aPosTexV[nCntFILM]);
		pVtx[2].tex = D3DXVECTOR2(0.0f, g_aPosTexV[nCntFILM] + 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, g_aPosTexV[nCntFILM] + 1.0f);

		pVtx += 4;
	}

	// 頂点バッファをアンロック
	g_pVtxBuffFILM->Unlock();
}

// 背景の描画処理
void DrawFILM(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntFILM;

	// デバイスの取得
	pDevice = GetDevice();

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffFILM, 0, sizeof(VERTEX_2D));
	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (nCntFILM = 0; nCntFILM < NUM_FILM; nCntFILM++)
	{
		// テクスチャの設定
		pDevice->SetTexture(0, g_apTextureFILM[nCntFILM]);

		// ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntFILM * 4, 2);

	}
}