//=========================================================
//
//簡易モーションモデル表示する処理[simple_motion_model.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "simple_motion_model.h"

//-------------------------------------------
//マクロ定義
//-------------------------------------------
#define LEVER_ACTIONZONE_RADIUS	(120.0f) //お風呂のギミック判定

//グローバル変数宣言
bool g_bKeyspawn = false; 

//モデル構造体
typedef struct
{
	const char* pFilePass;	// MODELファイルパス
	SIMPLEMOTIONMODEL MyNum;//自分番号（index）
	SIMPLEMOTIONMODEL ParentNum;//親番号(index).自分を自分と番号に
	SIMPLEMODEL SinpleModel;//posなど
} SIMPLEMODELINFO;



//-------------------------------------------
//　　"ファイルパス","自分(index)"."親(index)"
//-------------------------------------------
SIMPLEMODELINFO g_ModelInfo[SIMPLEMOTIONMODEL_MAX] =
{							//自分-----------------親
	{"data\\MODEL\\key1.x",SIMPLEMOTIONMODEL_Test1,SIMPLEMOTIONMODEL_Test1},//テストのため書き換え必須
	{"data\\MODEL\\key2.x",SIMPLEMOTIONMODEL_Test2,SIMPLEMOTIONMODEL_Test1},
	{"data\\MODEL\\leverroot.x",SIMPLEMOTIONMODEL_LEVER_RED_ROOT,SIMPLEMOTIONMODEL_LEVER_RED_ROOT},
	{"data\\MODEL\\leverroot.x",SIMPLEMOTIONMODEL_LEVER_BLUE_ROOT,SIMPLEMOTIONMODEL_LEVER_BLUE_ROOT},
	{"data\\MODEL\\leverred.x",SIMPLEMOTIONMODEL_LEVER_RED_LEVER,SIMPLEMOTIONMODEL_LEVER_RED_ROOT},
	{"data\\MODEL\\leverblue.x",SIMPLEMOTIONMODEL_LEVER_BLUE_LEVER,SIMPLEMOTIONMODEL_LEVER_BLUE_ROOT},
};

///-------------------------------------------------------------------------モデル
LPD3DXMESH g_pMeshSimpleModel[SIMPLEMOTIONMODEL_MAX] = {};//メッシュ(頂点情報)へのポインタ

LPD3DXBUFFER g_pBuffMatSimpleModel[SIMPLEMOTIONMODEL_MAX] = {};//マテリアルへのポインタ

DWORD dwNumMatSimpleModel[SIMPLEMOTIONMODEL_MAX] = {};//マテリアルの数


//=============================
//簡易モーションモデル初期化処理
//=============================
void InitSimpleModel(void)
{
	for (int SimpleModel = 0; SimpleModel < SIMPLEMOTIONMODEL_MAX; SimpleModel++)//各パーツ本体
	{
		g_ModelInfo[SimpleModel].SinpleModel.bUse = false;
		g_ModelInfo[SimpleModel].SinpleModel.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_ModelInfo[SimpleModel].SinpleModel.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}


	g_bKeyspawn = false;


	//ここから初期値セット
	SetSimpleModel(SIMPLEMOTIONMODEL_Test1, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetSimpleModel(SIMPLEMOTIONMODEL_Test2, D3DXVECTOR3(30.0f, 40.0f, 0.0f), D3DXVECTOR3(0.0f, 1.57f, 0.0f));

	//赤レバー
	SetSimpleModel(SIMPLEMOTIONMODEL_LEVER_RED_ROOT, D3DXVECTOR3(-1180.0f, 100.0f, -1000.0f), D3DXVECTOR3(0.0f, -1.57f, 0.0f));		//本体
	SetSimpleModel(SIMPLEMOTIONMODEL_LEVER_RED_LEVER, D3DXVECTOR3(0.0f, 0.0f, 8.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));		//レバー
	//レバー1のアクションゾーン設置
	SetActionZone(D3DXVECTOR3(-1180.0f, 100.0f, -1000.0f), LEVER_ACTIONZONE_RADIUS, ACTION_TYPE_LEVER_1, D3DXCOLOR(1.0f, 1.0f, 0.0f, 0.8f));

	//青レバー
	SetSimpleModel(SIMPLEMOTIONMODEL_LEVER_BLUE_ROOT, D3DXVECTOR3(-1180.0f, 100.0f, -400.0f), D3DXVECTOR3(0.0f, -1.57f, 0.0f));	//本体
	SetSimpleModel(SIMPLEMOTIONMODEL_LEVER_BLUE_LEVER, D3DXVECTOR3(0.0f, 0.0f, 8.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));		//レバー
	//レバー2のアクションゾーン設置
	SetActionZone(D3DXVECTOR3(-1180.0f, 100.0f, -400.0f), LEVER_ACTIONZONE_RADIUS, ACTION_TYPE_LEVER_2, D3DXCOLOR(1.0f, 0.0f, 0.3f, 0.8f));


}
//=============================
//簡易モーションモデル終了処理
//=============================
void UninitSimpleModel(void)
{
	for (int SimpleModel = 0; SimpleModel < SIMPLEMOTIONMODEL_MAX; SimpleModel++)
	{
		//メッシュの破棄
		if (g_pMeshSimpleModel[SimpleModel] != NULL)
		{
			g_pMeshSimpleModel[SimpleModel]->Release();
			g_pMeshSimpleModel[SimpleModel] = NULL;
		}
		//マテリアルの破棄
		if (g_pBuffMatSimpleModel[SimpleModel] != NULL)
		{
			g_pBuffMatSimpleModel[SimpleModel]->Release();
			g_pBuffMatSimpleModel[SimpleModel] = NULL;
		}
	}
}
//=============================
//簡易モーションモデル更新処理
//=============================
void UpdateSimpleModel(void)
{
	//*********ここでものに合わせて処理を追加


	//for (int SimpleModel = 0; SimpleModel < SIMPLEMOTIONMODEL_MAX; SimpleModel++)
	//{

	//}
}
//=============================
//簡易モーションモデル描画処理
//=============================
void DrawSimpleModel(void)
{

	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans, mtxParent;//計算用マトリックス

	D3DMATERIAL9 matDef;//現在のマテリアル保存用(一時退避)

	D3DXMATERIAL* pMat;//マテリアルデータへのポインタ
	
	
	for (int SimpleModel = 0; SimpleModel < SIMPLEMOTIONMODEL_MAX; SimpleModel++)
	{
		if (g_ModelInfo[SimpleModel].SinpleModel.bUse == true)
		{


			//モデルの位置
		//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&g_ModelInfo[SimpleModel].SinpleModel.mtxWorld);

			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_ModelInfo[SimpleModel].SinpleModel.rot.y, g_ModelInfo[SimpleModel].SinpleModel.rot.x, g_ModelInfo[SimpleModel].SinpleModel.rot.z);

			D3DXMatrixMultiply(&g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_ModelInfo[SimpleModel].SinpleModel.pos.x, g_ModelInfo[SimpleModel].SinpleModel.pos.y, g_ModelInfo[SimpleModel].SinpleModel.pos.z);

			D3DXMatrixMultiply(&g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &mtxTrans);

			//親子関係
			if (g_ModelInfo[SimpleModel].ParentNum == g_ModelInfo[SimpleModel].MyNum)
			{//自分が親
				//プレイヤーとかける
			//	D3DXMatrixMultiply(&g_Model.ModelParts[nCnt].mtxWorld, &g_Model.ModelParts[nCnt].mtxWorld, &g_Player.mtxWorld);
			}
			else
			{
				//自分の親のマトリックスかけてる
				D3DXMatrixMultiply(&g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &g_ModelInfo[g_ModelInfo[SimpleModel].ParentNum].SinpleModel.mtxWorld);

			}

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_ModelInfo[SimpleModel].SinpleModel.mtxWorld);

			//現在のマテリアルを取得
			pDevice->GetMaterial(&matDef);

			//マテリアルデータへのポインタを取得
			pMat = (D3DXMATERIAL*)g_pBuffMatSimpleModel[SimpleModel]->GetBufferPointer();

			for (int nCntMat = 0; nCntMat < (int)dwNumMatSimpleModel[SimpleModel]; nCntMat++)
			{
				//マテリアルの設定
				pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

				//テクスチャの設定
				pDevice->SetTexture(0, NULL);//今回は設定しない

				//モデル(パーツ)の描画
				g_pMeshSimpleModel[SimpleModel]->DrawSubset(nCntMat);

				//保存してたマテリアルを戻す
		//		pDevice->SetMaterial(&matDef);
			}

			//保存してたマテリアルを戻す
			pDevice->SetMaterial(&matDef);

			//テクスチャを戻す
			pDevice->SetTexture(0, NULL);
		}
	}
}

//=============================
//レバーON処理
//=============================
void LaverOn(void)
{
	if (g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_RED_LEVER].SinpleModel.rot.x > -1.75f)
	{
		g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_RED_LEVER].SinpleModel.rot.x -= 0.1f;
	}

	if (g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_BLUE_LEVER].SinpleModel.rot.x > -1.75f)
	{
		g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_BLUE_LEVER].SinpleModel.rot.x -= 0.1f;
	}
	if (g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_BLUE_LEVER].SinpleModel.rot.x <= -1.75f
		&& g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_BLUE_LEVER].SinpleModel.rot.x <= -1.75f
		&& g_bKeyspawn == false)
	{
		g_bKeyspawn = true;
		SpawnKey();
	}
}

//=============================
//キースポーン処理
//=============================
void SpawnKey(void)
{
	SetModel(D3DXVECTOR3(g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_BLUE_ROOT].SinpleModel.pos.x,
		20.0f,
		g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_BLUE_ROOT].SinpleModel.pos.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_KEY1);
	SetModel(D3DXVECTOR3(g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_RED_ROOT].SinpleModel.pos.x,
		20.0f,
		g_ModelInfo[SIMPLEMOTIONMODEL_LEVER_RED_ROOT].SinpleModel.pos.z),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f), MODELTYPE_KEY2);
}

//=============================
//簡易モーションモデル設定処理
//=============================
void SetSimpleModel(SIMPLEMOTIONMODEL SetUpName_Index,D3DXVECTOR3 pos,D3DXVECTOR3 rot)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//***親自身は自分の位置。子はオフセット値を記入
	
	if (g_ModelInfo[SetUpName_Index].SinpleModel.bUse == false)
	{
		g_ModelInfo[SetUpName_Index].SinpleModel.bUse = true;
		g_ModelInfo[SetUpName_Index].SinpleModel.pos = pos;
		g_ModelInfo[SetUpName_Index].SinpleModel.rot = rot;


		//Xファイルの読み込み
		D3DXLoadMeshFromX(g_ModelInfo[SetUpName_Index].pFilePass,
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_pBuffMatSimpleModel[SetUpName_Index],
			NULL,
			&dwNumMatSimpleModel[SetUpName_Index],
			&g_pMeshSimpleModel[SetUpName_Index]);
	}
	else
	{
		//エラー
	}
}

//=============================
//鍵スポーンしたか取得
//=============================
bool GetSpawnKey(void)
{
	return g_bKeyspawn;
}