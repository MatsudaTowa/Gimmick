//=============================================
//
//敵の方向示すUI[AngleUI.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "angleUI.h"
#include "enemy.h"
#include "player.h"
#include "player2.h"
#include "camera.h"

//=============================================
//壁のテクスチャの種類
//=============================================
static const char* AngleUI_TEX_NAME =
{
	"data\\TEXTURE\\AngleCursor.png",
};

//=========================================================
//グローバル変数
//=========================================================
LPDIRECT3DTEXTURE9 g_pTextureEyeAngleUI = {};//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffEyeAngleUI = NULL;//頂点バッファへのポリゴン
AngleUI g_AngleUI[NUM_ANGLEUI];	//ポーズ構造体の情報

//=============================================
//トラップの初期化
//=============================================
void InitAngleUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

//デバイスの取得
	pDevice = GetDevice();

	//	int nCntPause = 0;

		//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		AngleUI_TEX_NAME,
		&g_pTextureEyeAngleUI
	);


	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_ANGLEUI, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffEyeAngleUI, NULL);

	VERTEX_2D* pVtx;//頂点情報のポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffEyeAngleUI->Lock(0, 0, (void**)&pVtx, 0);
	for (int nCntTrap = 0; nCntTrap < NUM_ANGLEUI; nCntTrap++)
	{
		g_AngleUI[nCntTrap].bUse = true;
		//対角線の長さを算出
		g_AngleUI[nCntTrap].fLength = sqrtf(SCREEN_WIDE / 4.0f * SCREEN_WIDE / 4.0f + SCREEN_HEIGHT / 3.0f * SCREEN_HEIGHT / 3.0f) * 0.5f;

		//対角線の角度を算出
		g_AngleUI[nCntTrap].fAngle = atan2f(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f);


		if (nCntTrap == 0)
		{
			g_AngleUI[nCntTrap].fAlpha = 0.5f;
			g_AngleUI[nCntTrap].pos = D3DXVECTOR3(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f, 0.0f);
			g_AngleUI[nCntTrap].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[0].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x - SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y - SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x + SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y - SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x - SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y + SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x + SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y + SCREEN_HEIGHT / 3.5f, 0.0f);
		}
		else if (nCntTrap == 1)
		{
			g_AngleUI[nCntTrap].fAlpha = 0.5f;
			g_AngleUI[nCntTrap].pos = D3DXVECTOR3(SCREEN_WIDE / 1.35f, SCREEN_HEIGHT / 3.0f, 0.0f);
			pVtx[0].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x - SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y - SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x + SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y - SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x - SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y + SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x + SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y + SCREEN_HEIGHT / 3.5f, 0.0f);
		}
		//rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nCntTrap].fAlpha);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nCntTrap].fAlpha);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nCntTrap].fAlpha);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nCntTrap].fAlpha);

		//テキスチャの座標設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}

	g_pVtxBuffEyeAngleUI->Unlock();
}

//=============================================
//トラップの終了
//=============================================
void UninitAngleUI(void)
{
	//テクスチャの破棄
	if (g_pTextureEyeAngleUI != NULL)
	{
		g_pTextureEyeAngleUI->Release();
		g_pTextureEyeAngleUI = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffEyeAngleUI != NULL)
	{
		g_pVtxBuffEyeAngleUI->Release();
		g_pVtxBuffEyeAngleUI = NULL;
	}

}

//=============================================
//トラップの更新
//=============================================
void UpdateAngleUI(void)
{
	ENEMYMODEL* pEnemy = GetEnemy();
	Player* pPlayer = GetPlayer();
	Player_2P* pPlayer_2P = GetPlayer_2P();
	Camera* pCamera = GetCamera();

	VERTEX_2D* pVtx;//頂点情報のポインタ

//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffEyeAngleUI->Lock(0, 0, (void**)&pVtx, 0);
	for (int nCntTrap = 0; nCntTrap < NUM_ANGLEUI; nCntTrap++)
	{
		float fAngleEnemy = pPlayer->rot.y - pCamera[0].rot.y - (1.0f * D3DX_PI);
		
		//対角線の長さを算出
		g_AngleUI[nCntTrap].fLength = sqrtf(SCREEN_WIDE / 4.0f * SCREEN_WIDE / 4.0f + SCREEN_HEIGHT / 3.0f * SCREEN_HEIGHT / 3.0f) * 0.5f;

		//対角線の角度を算出
		g_AngleUI[nCntTrap].fAngle = atan2f(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f);

		g_AngleUI[nCntTrap].rot.z = fAngleEnemy;

		if (g_AngleUI[nCntTrap].rot.z < -D3DX_PI)
		{
			g_AngleUI[nCntTrap].rot.z = D3DX_PI;
		}
		else if (g_AngleUI[nCntTrap].rot.z > D3DX_PI)
		{
			g_AngleUI[nCntTrap].rot.z = -D3DX_PI;
		}
		if (nCntTrap == 0)
		{
			g_AngleUI[nCntTrap].fAlpha = 0.5f;
			g_AngleUI[nCntTrap].pos = D3DXVECTOR3(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f, 0.0f);
			pVtx[0].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(-g_AngleUI[nCntTrap].rot.z - (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[0].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(-g_AngleUI[nCntTrap].rot.z - (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[1].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(-g_AngleUI[nCntTrap].rot.z + (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[1].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(-g_AngleUI[nCntTrap].rot.z + (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[2].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(-g_AngleUI[nCntTrap].rot.z - g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[2].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(-g_AngleUI[nCntTrap].rot.z - g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[3].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(-g_AngleUI[nCntTrap].rot.z + g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[3].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(-g_AngleUI[nCntTrap].rot.z + g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
		}
		else if (nCntTrap == 1)
		{
			g_AngleUI[nCntTrap].fAlpha = 0.5f;
			g_AngleUI[nCntTrap].pos = D3DXVECTOR3(SCREEN_WIDE / 1.35f, SCREEN_HEIGHT / 3.0f, 0.0f);
			pVtx[0].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(g_AngleUI[nCntTrap].rot.z - (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[0].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(g_AngleUI[nCntTrap].rot.z - (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[1].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(g_AngleUI[nCntTrap].rot.z + (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[1].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(g_AngleUI[nCntTrap].rot.z + (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[2].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(g_AngleUI[nCntTrap].rot.z - g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[2].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(g_AngleUI[nCntTrap].rot.z - g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[3].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(g_AngleUI[nCntTrap].rot.z + g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[3].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(g_AngleUI[nCntTrap].rot.z + g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
		}

		pVtx += 4;
	}
	g_pVtxBuffEyeAngleUI->Unlock();

}

//=============================================
//トラップの描画
//=============================================
void DrawAngleUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ

//デバイスの取得
	pDevice = GetDevice();//----------------書き換え済み

	for (int nCntTrap = 0; nCntTrap < NUM_ANGLEUI; nCntTrap++)
	{
		if (g_AngleUI[nCntTrap].bUse == true)
		{
			//頂点バッファをデータストリームに設定
			pDevice->SetStreamSource(0, g_pVtxBuffEyeAngleUI, 0, sizeof(VERTEX_2D));

			//頂点フォーマットの設定
			pDevice->SetFVF(FVF_VERTEX_2D);//-------書き換え済み

			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureEyeAngleUI);//---------書き換え済み

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//プリミティブの種類//----------書き換え済み
				4 * nCntTrap,//描画する最初の頂点インデックス
				2);//描画するプリミティブ数

			//テクスチャを戻す
			pDevice->SetTexture(0, NULL);
		}
	}
}

//=============================================
//トラップの設定
//=============================================
void SetAngleUI(int nPlayer)
{
	if (g_AngleUI[nPlayer].bUse == false)
	{
		g_AngleUI[nPlayer].fAlpha = 0.7f;
		g_AngleUI[nPlayer].bUse = true;
		int nVtx = nPlayer * 4;
		VERTEX_2D* pVtx;//頂点情報のポインタ

		//頂点バッファをロックし、頂点情報へのポインタを取得
		g_pVtxBuffEyeAngleUI->Lock(0, 0, (void**)&pVtx, 0);
		//頂点カラーの設定
		pVtx[nVtx].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nPlayer].fAlpha);
		pVtx[nVtx + 1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nPlayer].fAlpha);
		pVtx[nVtx + 2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nPlayer].fAlpha);
		pVtx[nVtx + 3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nPlayer].fAlpha);
		g_pVtxBuffEyeAngleUI->Unlock();

	}
}
