//=========================================================
//
//壁を表示する処理[wall.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "stage.h"

//グローバル変数宣言
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStage = NULL; //頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureStage[STAGETEXNUM] = {};       //テクスチャへのポインタ



//D3DXVECTOR3 g_Stage[nWall].posStage;	//位置
//D3DXVECTOR3 g_Stage[nWall].rotStage;	//向き
//D3DXMATRIX g_Stage[nWall].mtxWorldStage;//ワールドマトリックス


STAGE g_Stage[NUMSTAGE];//制作中　構造体



//=============================
//壁の初期化処理
//=============================
void InitStage(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\blood.jpg", &g_pTextureStage[0]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\map001.jpg", &g_pTextureStage[1]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\ki.jpg", &g_pTextureStage[2]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\title000.png", &g_pTextureStage[3]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\safe000.jpg", &g_pTextureStage[4]);
	//ここにテクスチャを追加したらヘッダにも増やすこと!!!!//

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUMSTAGE, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffStage, NULL);

		VERTEX_3D* pVtx;//頂点情報へのポインタ

		//頂点バッファをロックし、頂点情報へのポインタを取得
		g_pVtxBuffStage->Lock(0, 0, (void**)&pVtx, 0);

	for (int nWall = 0; nWall < NUMSTAGE; nWall++)
	{
		//g_Stage[nWall].g_Stage[nWall].posStage
		//g_Stage[nWall].rotStage
		g_Stage[nWall].bUse = false;

		g_Stage[nWall].posStage = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//位置
		g_Stage[nWall].rotStage = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//向き
		g_Stage[nWall].MaxPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//最大
		g_Stage[nWall].MinPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//最小
		g_Stage[nWall].bCollision = false;
		g_Stage[nWall].TexType = TEXTYPE_00;
		//g_Stage[nWall].mtxWorldStage= D3DXMATRIX(0.0f,0.0f,0.0f);//ワールドマトリックス



		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(-STAGESIZE, 100.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(STAGESIZE, 100.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-STAGESIZE, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(STAGESIZE, 0.0f, 0.0f);

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
	g_pVtxBuffStage->Unlock();

	//地下室
	SetStage(D3DXVECTOR3(-0900.0f, 0000.0f, +0110.0f), D3DXVECTOR3(0.00f, +0.00f, 0.00f), 0600.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(-0400.0f, 0000.0f, -0030.0f), D3DXVECTOR3(0.00f, +1.57f, 0.00f), 0200.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(-0150.0f, 0000.0f, -0230.0f), D3DXVECTOR3(0.00f, +0.00f, 0.00f), 0250.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(+0030.0f, 0000.0f, -0800.0f), D3DXVECTOR3(0.00f, +1.57f, 0.00f), 0700.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(-1200.0f, 0000.0f, -0600.0f), D3DXVECTOR3(0.00f, -1.57f, 0.00f), 0700.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(-0140.0f, 0000.0f, -1230.0f), D3DXVECTOR3(0.00f, +3.14f, 0.00f), 0180.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(-0320.0f, 0000.0f, -1330.0f), D3DXVECTOR3(0.00f, +1.57f, 0.00f), 0100.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(-1050.0f, 0000.0f, -1230.0f), D3DXVECTOR3(0.00f, +3.14f, 0.00f), 0170.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(-0880.0f, 0000.0f, -1330.0f), D3DXVECTOR3(0.00f, -1.57f, 0.00f), 0100.0f, 0300.0f, TEXTYPE_00);//テスト仕様

	//リビング
	//床
	SetStage(D3DXVECTOR3(+3100.0f, 0100.0f, -1500.0f), D3DXVECTOR3(1.57f, 0.00f, 0.00f), 0800.0f, 0300.0f, TEXTYPE_00);//テスト仕様入ってすぐ
	SetStage(D3DXVECTOR3(+2900.0f, 0100.0f, -1900.0f), D3DXVECTOR3(1.57f, 0.00f, 0.00f), 0200.0f, 0100.0f, TEXTYPE_00);//テスト仕様通路
	SetStage(D3DXVECTOR3(+3200.0f, 0100.0f, -2300.0f), D3DXVECTOR3(1.57f, 0.00f, 0.00f), 0500.0f, 0300.0f, TEXTYPE_00);//テスト仕様テレビのとこ
	//壁
	SetStage(D3DXVECTOR3(+2900.0f, 0100.0f, -1440.0f), D3DXVECTOR3(0.00f, +0.00f, 0.00f), 0200.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(+3300.0f, 0100.0f, -1300.0f), D3DXVECTOR3(0.00f, +0.00f, 0.00f), 0200.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(+3500.0f, 0100.0f, -1550.0f), D3DXVECTOR3(0.00f, +1.57f, 0.00f), 0250.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(+3500.0f, 0100.0f, -1800.0f), D3DXVECTOR3(0.00f, +3.14f, 0.00f), 0100.0f, 0300.0f, TEXTYPE_00);//テスト仕様スポーン位置近階段左
	SetStage(D3DXVECTOR3(+3100.0f, 0100.0f, -1340.0f), D3DXVECTOR3(0.00f, -1.57f, 0.00f), 0100.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(+3100.0f, 0100.0f, -1900.0f), D3DXVECTOR3(0.00f, +1.57f, 0.00f), 0100.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(+3200.0f, 0100.0f, -1800.0f), D3DXVECTOR3(0.00f, +3.14f, 0.00f), 0100.0f, 0300.0f, TEXTYPE_00);//テスト仕様
	SetStage(D3DXVECTOR3(+2700.0f, 0100.0f, -2000.0f), D3DXVECTOR3(0.00f, -1.57f, 0.00f), 0600.0f, 0300.0f, TEXTYPE_00);//テスト仕様入って右
	SetStage(D3DXVECTOR3(+3400.0f, 0100.0f, -2000.0f), D3DXVECTOR3(0.00f, +0.00f, 0.00f), 0300.0f, 0300.0f, TEXTYPE_00);//テスト仕様スポーン位置近階段左

}
//=============================
//壁の終了処理
//=============================
void UninitStage(void)
{
	for (int nWall = 0; nWall < STAGETEXNUM; nWall++)
	{
		//テクスチャの破棄
		if (g_pTextureStage[nWall] != NULL)
		{
			g_pTextureStage[nWall]->Release();
			g_pTextureStage[nWall] = NULL;
		}
	}
	//頂点バッファの破棄
	if (g_pVtxBuffStage != NULL)
	{
		g_pVtxBuffStage->Release();
		g_pVtxBuffStage = NULL;
	}
}
//=============================
//壁の更新処理
//=============================
void UpdateStage(void)
{
	//何もなし
}
//=============================
//壁の描画処理
//=============================
void DrawStage(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;//計算用マトリックス

	for (int nWall = 0; nWall < NUMSTAGE; nWall++)
	{
		if (g_Stage[nWall].bUse == true)
		{
			//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&g_Stage[nWall].mtxWorldStage);

			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Stage[nWall].rotStage.y, g_Stage[nWall].rotStage.x, g_Stage[nWall].rotStage.z);

			D3DXMatrixMultiply(&g_Stage[nWall].mtxWorldStage, &g_Stage[nWall].mtxWorldStage, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_Stage[nWall].posStage.x, g_Stage[nWall].posStage.y, g_Stage[nWall].posStage.z);

			D3DXMatrixMultiply(&g_Stage[nWall].mtxWorldStage, &g_Stage[nWall].mtxWorldStage, &mtxTrans);

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_Stage[nWall].mtxWorldStage);

			//頂点バッファをデータストリームに設定
			pDevice->SetStreamSource(0, g_pVtxBuffStage, 0, sizeof(VERTEX_3D));

			//頂点フォーマットの設定
			pDevice->SetFVF(FVF_VERTEX_3D);


			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureStage[g_Stage[nWall].TexType]);

			//壁の描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//プリミティブの種類
				nWall * 4,//描画する最初の頂点インデックス
				2);//描画するプリミティブ数
		}
	}
}
//=============================
//壁の設定処理
//=============================
void SetStage(D3DXVECTOR3 Pos, D3DXVECTOR3 Rot, float bes, float ver, TEXTYPE TexType)
{
	VERTEX_3D* pVtx;//頂点情報へのポインタ

//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffStage->Lock(0, 0, (void**)&pVtx, 0);

	for (int nWall = 0; nWall < NUMSTAGE; nWall++)
	{
		if (g_Stage[nWall].bUse == false)
		{
			g_Stage[nWall].posStage = Pos;//位置
			g_Stage[nWall].rotStage = Rot;	//向き
			g_Stage[nWall].TexType = TexType;
			g_Stage[nWall].bUse = true;
			g_Stage[nWall].bCollision = true;

			//頂点座標の設定
			pVtx[0].pos = D3DXVECTOR3(-bes, ver, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(bes, ver, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(-bes, -ver, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(bes, -ver, 0.0f);

			g_Stage[nWall].MinPos = D3DXVECTOR3(-bes, -ver, -1.0f);
			g_Stage[nWall].MaxPos = D3DXVECTOR3(bes, ver, 1.0f);

			break;
		}
		pVtx += 4;
	}
	//頂点バッファのアンロック
	g_pVtxBuffStage->Unlock();


}
//=============================
//壁の情報取得処理
//=============================
STAGE* GetStage(void)
{
	return &g_Stage[0];
}