//============================================================================================
//
//アイテムUI表示する処理[result.cpp]
// Author seiya kagaya
//
//============================================================================================
#include "item.h"
#include "itemUI.h"
#include "game.h"


//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureItem_UI[2] = {};//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItem_UI = NULL;//頂点バッファへのポリゴン


ITEM_UI g_ItemUI[MAXITEMUI];


//=============================
//アイテムUIの初期化処理
//=============================
void InitItem_UI(void)
{
	

	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

	//デバイスの取得
	pDevice = GetDevice();

	int nCntItem_UI;

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\frame.png", &g_pTextureItem_UI[0]);//--------書き換え済み
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\frameselect.png", &g_pTextureItem_UI[1]);//--------書き換え済み


	
	//アイテムUIの情報の初期化(いわゆる初期地点)
	for (nCntItem_UI = 0; nCntItem_UI < MAXITEMUI; nCntItem_UI++)
	{
		g_ItemUI[nCntItem_UI].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_ItemUI[nCntItem_UI].bUse = false;//使用していない状態にする
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAXITEMUI, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffItem_UI, NULL);

	VERTEX_2D* pVtx;//頂点情報のポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffItem_UI->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntItem_UI = 0; nCntItem_UI < MAXITEMUI; nCntItem_UI++)
	{
		//頂点座標の更新-----------------------------------
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//rhwの設定
		pVtx[0].rhw = 1.0f;//値は固定
		pVtx[1].rhw = 1.0f;//値は固定
		pVtx[2].rhw = 1.0f;//値は固定
		pVtx[3].rhw = 1.0f;//値は固定

		//頂点カラーの設定
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 225, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

		//テクスチャ座標を設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//左上
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//右上
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//左下
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//右下

		pVtx += 4;//頂点のポインタを4つ分進める
	}
	//頂点バッファをアンロックする
	g_pVtxBuffItem_UI->Unlock();

	//表示場所の設定
	for (int SetCnt = 0; SetCnt <= ITEMTYPE_MAX; SetCnt++)
	{
		SetItem_UI(D3DXVECTOR3(ITEMUISIZE + 10.0f + (ITEMUISIZE*2.1f * SetCnt), 460.0f, 0),ITEM_UI_TYPE_FRAME);
	}

	SetItem_UI(D3DXVECTOR3(ITEMUISIZE + 10.0f, 460.0f, 0), ITEM_UI_TYPE_POINTER);





}
//=============================
//アイテムUIの終了処理
//=============================
void UninitItem_UI(void)
{
	for (int i = 0; i < 2; i++)
	{


		//テクスチャの破棄
		if (g_pTextureItem_UI[i] != NULL)
		{
			g_pTextureItem_UI[i]->Release();
			g_pTextureItem_UI[i] = NULL;
		}
	}
	//頂点バッファの破棄
	if (g_pVtxBuffItem_UI != NULL)
	{
		g_pVtxBuffItem_UI->Release();
		g_pVtxBuffItem_UI = NULL;
	}
}
//=============================
//アイテムUIの更新処理
//=============================
void UpdateItem_UI(void)
{
	//VERTEX_2D* pVtx;//頂点情報のポインタ

	////頂点バッファをロックし、頂点情報へのポインタを取得
	//g_pVtxBuffItem_UI->Lock(0, 0, (void**)&pVtx, 0);

	//for (int nCntItem_UI = 0; nCntItem_UI < ITEMTYPE_MAX; nCntItem_UI++)
	//{
	//
	//	pVtx += 4;//頂点のポインタを4つ分進める
	//}
	////頂点バッファをアンロックする
	//g_pVtxBuffItem_UI->Unlock();
}
//=============================
//アイテムUIの描画処理
//=============================
void DrawItem_UI(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

	int nCntItem_UI = 0;
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffItem_UI, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);//-------書き換え済み
	for (nCntItem_UI = 0; nCntItem_UI < MAXITEMUI; nCntItem_UI++)
	{
		if (g_ItemUI[nCntItem_UI].bUse == true)
		{//アイテムUIが使用されている
			
			//列挙をintに
			int EscapeNum = static_cast<int>(g_ItemUI[nCntItem_UI].UItype);

			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureItem_UI[EscapeNum]);//---------書き換え済み


					//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//プリミティブの種類
				nCntItem_UI * 4,//描画する最初の頂点インデックス
				2);//描画するプリミティブ数
		}
	}
}
//=============================
//アイテムUIの設定処理
//=============================
void SetItem_UI(D3DXVECTOR3 pos, ITEM_UI_TYPE ItemUIType)
{//他のところでも呼ぶ可能性があるのでこのままのほうが便利

	VERTEX_2D* pVtx;//頂点情報のポインタ
	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffItem_UI->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntItem_UI = 0; nCntItem_UI < MAXITEMUI; nCntItem_UI++)
	{
		if (g_ItemUI[nCntItem_UI].bUse == false)
		{//アイテムUIが使用されていない

			g_ItemUI[nCntItem_UI].bUse = true;//使用してるにする

			g_ItemUI[nCntItem_UI].pos = pos;
			g_ItemUI[nCntItem_UI].UItype = ItemUIType;


			//頂点座標の更新-----------------------------------
			pVtx[0].pos = D3DXVECTOR3(g_ItemUI[nCntItem_UI].pos.x - ITEMUISIZE, g_ItemUI[nCntItem_UI].pos.y - ITEMUISIZE, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_ItemUI[nCntItem_UI].pos.x + ITEMUISIZE, g_ItemUI[nCntItem_UI].pos.y - ITEMUISIZE, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_ItemUI[nCntItem_UI].pos.x - ITEMUISIZE, g_ItemUI[nCntItem_UI].pos.y + ITEMUISIZE, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_ItemUI[nCntItem_UI].pos.x + ITEMUISIZE, g_ItemUI[nCntItem_UI].pos.y + ITEMUISIZE, 0.0f);



			//頂点カラーの設定
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 200);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 200);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 225, 200);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 200);

			break;
		}
		pVtx += 4;//ポインタを４つ進める
	}
	//頂点バッファをアンロックする
	g_pVtxBuffItem_UI->Unlock();
}
