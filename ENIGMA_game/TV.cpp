//=============================================
//
//テレビのギミック[TV.h]
//Auther Matsuda Towa
//
//=============================================
#include "TV.h"
#include "input.h"

//=============================================
//グローバル変数
//=============================================
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTV = NULL;
LPDIRECT3DTEXTURE9 g_pTextureTV = {}; //テクスチャポインタ
//D3DXVECTOR3 g_movefield; //移動量
D3DXMATRIX	g_mtxWorldTV;
TV_VISION g_TV_VISION;

//=============================================
//初期化処理
//=============================================
void InitTV(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bathwater.jpg",
		&g_pTextureTV
	);

	//お湯の初期設定
	g_TV_VISION.pos = D3DXVECTOR3(0.0f, 30.0f, 0.0f);
	g_TV_VISION.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_TV_VISION.fWide = TVVISION_WIDE;
	g_TV_VISION.fHeight = TVVISION_HEIGHT;
	g_TV_VISION.bUse = false;
	g_TV_VISION.bOn = false;

	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffTV, NULL);

	VERTEX_3D* pVtx;

	//頂点バッファをロックし頂点情報へのポインタを取得
	g_pVtxBuffTV->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(g_TV_VISION.pos.x - g_TV_VISION.fWide, g_TV_VISION.pos.y + g_TV_VISION.fHeight, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(g_TV_VISION.pos.x + g_TV_VISION.fWide, g_TV_VISION.pos.y + g_TV_VISION.fHeight, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(g_TV_VISION.pos.x - g_TV_VISION.fWide, g_TV_VISION.pos.y - g_TV_VISION.fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(g_TV_VISION.pos.x + g_TV_VISION.fWide, g_TV_VISION.pos.y - g_TV_VISION.fHeight, 0.0f);

	//法線ベクトルの設定
	pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//テクスチャの座標指定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	g_pVtxBuffTV->Unlock();
}

//=============================================
//終了処理
//=============================================
void UninitTV(void)
{
	//テクスチャの破棄
	if (g_pTextureTV != NULL)
	{
		g_pTextureTV->Release();
		g_pTextureTV = NULL;
	}

	//頂点バッファの破棄
	if (g_pVtxBuffTV != NULL)
	{
		g_pVtxBuffTV->Release();
		g_pVtxBuffTV = NULL;
	}
}

//=============================================
//更新処理
//=============================================
void UpdateTV(void)
{
}

//=============================================
//描画処理
//=============================================
void DrawTV(void)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans; //計算用マトリックス

	if (g_TV_VISION.bUse == true&&g_TV_VISION.bOn == true)
	{
		//マトリックスの初期化
		D3DXMatrixIdentity(&g_mtxWorldTV);

		//向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_TV_VISION.rot.y, g_TV_VISION.rot.x, g_TV_VISION.rot.z);

		D3DXMatrixMultiply(&g_mtxWorldTV, &g_mtxWorldTV, &mtxRot);

		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, g_TV_VISION.pos.x, g_TV_VISION.pos.y, g_TV_VISION.pos.z);

		D3DXMatrixMultiply(&g_mtxWorldTV, &g_mtxWorldTV, &mtxTrans);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldTV);

		//頂点バッファをデータストリームに設定
		pDevice->SetStreamSource(0, g_pVtxBuffTV, 0, sizeof(VERTEX_3D));

		//頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_3D);

		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureTV);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);


		//テクスチャを戻す
		pDevice->SetTexture(0, NULL);
	}
}

//=============================================
//テレビの操作処理
//=============================================
void TVController(void)
{
	g_TV_VISION.bOn = g_TV_VISION.bOn ? false : true;
}

//=============================================
//テレビの画面セット処理
//=============================================
void SetTVVision(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWide, float fHeight)
{
	if (g_TV_VISION.bUse == false)
	{
		g_TV_VISION.pos = pos;
		g_TV_VISION.rot = rot;
		g_TV_VISION.fWide = fWide;
		g_TV_VISION.fHeight = fHeight;
		g_TV_VISION.bUse = true;
		g_TV_VISION.bOn = true;
	}
}

//=============================================
//チャンネル切り替え
//=============================================
void SelectChannel(int nSelectChannel)
{
}

//=============================================
//テレビの情報取得
//=============================================
TV_VISION* GetTVPos(void)
{
	return &g_TV_VISION;
}
