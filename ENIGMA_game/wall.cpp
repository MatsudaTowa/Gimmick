//=========================================================
//
//壁を表示する処理[wall.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "wall.h"

//グローバル変数宣言
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffWall = NULL; //頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureWall[TEXNUM] = {};       //テクスチャへのポインタ



//D3DXVECTOR3 g_Wall[nWall].posWall;	//位置
//D3DXVECTOR3 g_Wall[nWall].rotWall;	//向き
//D3DXMATRIX g_Wall[nWall].mtxWorldWall;//ワールドマトリックス


WALL g_Wall[NUMWALL];//制作中　構造体



//=============================
//壁の初期化処理
//=============================
void InitWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Block003.jpg", &g_pTextureWall[0]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Block002.jpg", &g_pTextureWall[1]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Block001.jpg", &g_pTextureWall[2]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Block004.jpg", &g_pTextureWall[3]);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUMWALL, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffWall, NULL);

		VERTEX_3D* pVtx;//頂点情報へのポインタ

		//頂点バッファをロックし、頂点情報へのポインタを取得
		g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (int nWall = 0; nWall < NUMWALL; nWall++)
	{
		//g_Wall[nWall].g_Wall[nWall].posWall
		//g_Wall[nWall].rotWall
		g_Wall[nWall].bUse = false;

		g_Wall[nWall].posWall = D3DXVECTOR3(0.0f, 0.0f, 50.0f);//位置
		g_Wall[nWall].rotWall = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//向き

		//g_Wall[nWall].mtxWorldWall= D3DXMATRIX(0.0f,0.0f,0.0f);//ワールドマトリックス



		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(-WALLSIZE, 100.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(WALLSIZE, 100.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-WALLSIZE, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(WALLSIZE, 0.0f, 0.0f);

		//法線ベクトルの設定
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//テクスチャ座標を設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//左上
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//右上
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//左下
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//右下

		pVtx += 4;
	}
	//頂点バッファのアンロック
	g_pVtxBuffWall->Unlock();

//	SetWall(D3DXVECTOR3(0.0f, 0.0f, WALLSIZE), 0.0f, 0, 0, WALLTYPE_test0);//テスト仕様
//	SetWall(D3DXVECTOR3(0.0f, 0.0f, -WALLSIZE), 3.14f, 0, 0, WALLTYPE_test0);//テスト仕様
//	SetWall(D3DXVECTOR3(WALLSIZE, 0.0f, 0.0f), 1.57f, 0, 0, WALLTYPE_test1);
//	SetWall(D3DXVECTOR3(-WALLSIZE, 0.0f, 0.0f),-1.57f, 0, 0, WALLTYPE_test3);

}
//=============================
//壁の終了処理
//=============================
void UninitWall(void)
{
	for (int nWall = 0; nWall < TEXNUM; nWall++)
	{
		//テクスチャの破棄
		if (g_pTextureWall[nWall] != NULL)
		{
			g_pTextureWall[nWall]->Release();
			g_pTextureWall[nWall] = NULL;
		}
	}
	//頂点バッファの破棄
	if (g_pVtxBuffWall != NULL)
	{
		g_pVtxBuffWall->Release();
		g_pVtxBuffWall = NULL;
	}
}
//=============================
//壁の更新処理
//=============================
void UpdateWall(void)
{
	//何もなし
}
//=============================
//壁の描画処理
//=============================
void DrawWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;//計算用マトリックス

	for (int nWall = 0; nWall < NUMWALL; nWall++)
	{
		if (g_Wall[nWall].bUse == true)
		{
			//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&g_Wall[nWall].mtxWorldWall);

			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Wall[nWall].rotWall.y, g_Wall[nWall].rotWall.x, g_Wall[nWall].rotWall.z);

			D3DXMatrixMultiply(&g_Wall[nWall].mtxWorldWall, &g_Wall[nWall].mtxWorldWall, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_Wall[nWall].posWall.x, g_Wall[nWall].posWall.y, g_Wall[nWall].posWall.z);

			D3DXMatrixMultiply(&g_Wall[nWall].mtxWorldWall, &g_Wall[nWall].mtxWorldWall, &mtxTrans);

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_Wall[nWall].mtxWorldWall);

			//頂点バッファをデータストリームに設定
			pDevice->SetStreamSource(0, g_pVtxBuffWall, 0, sizeof(VERTEX_3D));

			//頂点フォーマットの設定
			pDevice->SetFVF(FVF_VERTEX_3D);


			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureWall[g_Wall[nWall].WallType]);

			//壁の描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//プリミティブの種類
				0,//描画する最初の頂点インデックス
				2);//描画するプリミティブ数
		}
	}
}
//=============================
//壁の設定処理
//=============================
void SetWall(D3DXVECTOR3 Pos, float angle, int Width, int height, WALLTYPE TestType)
{
	VERTEX_3D* pVtx;//頂点情報へのポインタ

//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (int nWall = 0; nWall < NUMWALL; nWall++)
	{
		if (g_Wall[nWall].bUse == false)
		{
			g_Wall[nWall].posWall = Pos;//位置
			g_Wall[nWall].rotWall = D3DXVECTOR3(0.0f, angle, 0.0f);	//向き

			//幅、高さ後ほど

			g_Wall[nWall].WallType = TestType;
			g_Wall[nWall].bUse = true;
			break;
		}
		pVtx += 4;
	}
	//頂点バッファのアンロック
	g_pVtxBuffWall->Unlock();


}
//=============================
//壁の情報取得処理
//=============================
WALL* GetWall(void)
{
	return &g_Wall[0];
}