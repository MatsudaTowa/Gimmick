//=============================================
//
//お風呂のギミック[trap.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "trap.h"

//=============================================
//壁のテクスチャの種類
//=============================================
static const char* TRAP_TEX_NAME =
{
	"data\\TEXTURE\\trap000.png",
};

//=========================================================
//グローバル変数
//=========================================================
LPDIRECT3DTEXTURE9 g_pTextureTrap = {};//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTrap = NULL;//頂点バッファへのポリゴン
Trap g_Trap;	//ポーズ構造体の情報

//=============================================
//トラップの初期化
//=============================================
void InitTrap(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

//デバイスの取得
	pDevice = GetDevice();

	//	int nCntPause = 0;

		//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		TRAP_TEX_NAME,
		&g_pTextureTrap
	);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffTrap, NULL);

	VERTEX_2D* pVtx;//頂点情報のポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffTrap->Lock(0, 0, (void**)&pVtx, 0);
	g_Trap.pos = D3DXVECTOR3(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f, 0.0f);
	pVtx[0].pos = D3DXVECTOR3(g_Trap.pos.x - SCREEN_WIDE / 4.0f, g_Trap.pos.y - SCREEN_HEIGHT / 3.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(g_Trap.pos.x + SCREEN_WIDE / 4.0f, g_Trap.pos.y - SCREEN_HEIGHT / 3.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(g_Trap.pos.x - SCREEN_WIDE / 4.0f, g_Trap.pos.y + SCREEN_HEIGHT / 3.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(g_Trap.pos.x + SCREEN_WIDE / 4.0f, g_Trap.pos.y + SCREEN_HEIGHT / 3.0f, 0.0f);
	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 200);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 200);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 200);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 200);

	//テキスチャの座標設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	g_pVtxBuffTrap->Unlock();
}

//=============================================
//トラップの終了
//=============================================
void UninitTrap(void)
{
	//テクスチャの破棄
	if (g_pTextureTrap != NULL)
	{
		g_pTextureTrap->Release();
		g_pTextureTrap = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffTrap != NULL)
	{
		g_pVtxBuffTrap->Release();
		g_pVtxBuffTrap = NULL;
	}

}

//=============================================
//トラップの更新
//=============================================
void UpdateTrap(void)
{

}

//=============================================
//トラップの描画
//=============================================
void DrawTrap(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

//デバイスの取得
	pDevice = GetDevice();//----------------書き換え済み

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffTrap, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);//-------書き換え済み

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureTrap);//---------書き換え済み

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//プリミティブの種類//----------書き換え済み
		0,//描画する最初の頂点インデックス
		2);//描画するプリミティブ数
}
