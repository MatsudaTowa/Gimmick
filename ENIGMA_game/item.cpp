//=========================================================
//
//アイテムを表示する処理[billboard.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "item.h"
//#include "sound.h"
#include "input.h"
//#include "shadow.h"
#include "player.h"
#include "particle.h"


//グローバル変数宣言
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItem = NULL; //頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureItem[ITEMTYPE_MAX] = {};       //テクスチャへのポインタ



//D3DXVECTOR3 g_Item[nItem].posItem;	//位置
//D3DXVECTOR3 g_Item[nItem].rotItem;	//向き
//D3DXMATRIX g_Item[nItem].mtxWorldItem;//ワールドマトリックス


ITEM g_Item[NUMITEM];//制作中　構造体
//
//ITEMCNT g_ItemCnt_1P[ITEMTYPE_MAX];//アイテムカウンター
//
//ITEMCNT g_ItemCnt_2P[ITEMTYPE_MAX];//アイテムカウンター

int g_nldShadow4 = -1;

//=============================
//アイテムの初期化処理
//=============================
void InitItem(void)
{
	////アイテムカウンター
	//for (int n = 0; n < ITEMTYPE_MAX; n++)
	//{
	//	g_ItemCnt_1P[n].ItemCnt = 0;
	//	g_ItemCnt_2P[n].ItemCnt = 0;
	//}

	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item000.png", &g_pTextureItem[0]);//御札
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item001.png", &g_pTextureItem[1]);//回復
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item002.png", &g_pTextureItem[2]);//鍵だし
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item003.png", &g_pTextureItem[3]);//身代わり
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\item004.png", &g_pTextureItem[4]);//式神

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUMITEM, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffItem, NULL);

	VERTEX_3D* pVtx;//頂点情報へのポインタ
	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffItem->Lock(0, 0, (void**)&pVtx, 0);

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		//g_Item[nItem].g_Item[nItem].posItem
		//g_Item[nItem].rotItem
		//g_Item[nItem].

		g_Item[nItem].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//位置
		g_Item[nItem].bGetNO = false;
		g_Item[nItem].nStayGetCnt = 0;
		//g_Item[nItem].rotItem = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//向き

		//g_Item[nItem].mtxWorldItem= D3DXMATRIX(0.0f,0.0f,0.0f);//ワールドマトリックス
		g_Item[nItem].bUse = false;
		g_Item[nItem].nfloatCnt = 0;
		g_Item[nItem].move = D3DXVECTOR3(0.2f, 0.1f, 1.0f) * ITEMMOVESPEED_LOCK;
		g_Item[nItem].bRetentionl = false;

		//影設定
		g_Item[nItem].nShadowNum = -1;

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(-ITEMSIZE, ITEMSIZE, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(ITEMSIZE, ITEMSIZE, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-ITEMSIZE, -ITEMSIZE, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(ITEMSIZE, -ITEMSIZE, 0.0f);

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
	g_pVtxBuffItem->Unlock();





}
//=============================
//アイテムの終了処理
//=============================
void UninitItem(void)
{
	//StopSound(SOUND_LABEL_SE_SHOT);
	//StopSound(SOUND_LABEL_SE_EXPLOSIONBOMB);
	//テクスチャの破棄
	for (int i = 0; i < ITEMTYPE_MAX; i++)
	{
		if (g_pTextureItem[i] != NULL)
		{
			g_pTextureItem[i]->Release();
			g_pTextureItem[i] = NULL;
		}
	}
	//頂点バッファの破棄
	if (g_pVtxBuffItem != NULL)
	{
		g_pVtxBuffItem->Release();
		g_pVtxBuffItem = NULL;
	}
}
//=============================
//アイテムの更新処理
//=============================
void UpdateItem(void)
{

	VERTEX_3D* pVtx;//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffItem->Lock(0, 0, (void**)&pVtx, 0);

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		if (g_Item[nItem].bUse == true)
		{
			if (g_Item[nItem].bGetNO == true)
			{
				if (g_Item[nItem].nStayGetCnt > 0)
				{
					g_Item[nItem].nStayGetCnt--;
				}

				if (g_Item[nItem].nStayGetCnt <= 0)
				{
					g_Item[nItem].bGetNO = false;
				}
			}


			//g_Item[nItem].oldPos = g_Item[nItem].pos;
			//位置を更新
			g_Item[nItem].pos += g_Item[nItem].move;



		
			
			//-------------------------------------------------------------ふわふわ浮遊
			g_Item[nItem].nfloatCnt++;
			
			if (g_Item[nItem].nfloatCnt > 50)
			{
				if (g_Item[nItem].bfloatRot==false)
				{//下降に切り替え
					g_Item[nItem].nfloatCnt = 0;
					g_Item[nItem].bfloatRot = true;
				}
				else if (g_Item[nItem].bfloatRot == true)
				{//上昇に切り替え
					g_Item[nItem].nfloatCnt = 0;
					g_Item[nItem].bfloatRot = false;

					if (g_Item[nItem].pos.y <= ITEMSIZE)
					{//下限に接触
						g_Item[nItem].pos.y = ITEMSIZE + 0.1f;
						g_Item[nItem].bRetentionl = true;
					}
					else
					{//滞留解除

						g_Item[nItem].bRetentionl = false;
					}
				}
			}
			if (g_Item[nItem].bRetentionl == true)
			{//滞留状態
				if (g_Item[nItem].bfloatRot == true)
				{//下降
					g_Item[nItem].pos.y -= 0.5f;
					
					if (g_Item[nItem].pos.y <= ITEMSIZE)
					{//下限に接触
						g_Item[nItem].pos.y = ITEMSIZE + 0.1f;
					}
				}
				else if (g_Item[nItem].bfloatRot == false)
				{//上昇
					g_Item[nItem].pos.y += 0.5f;
				}
			}
			else
			{//滞留じゃない
				//重力
				if (g_Item[nItem].pos.y > ITEMSIZE)
				{//空中(地上ではない)の時
					//重力
					g_Item[nItem].move.y -= (GRAVITY * 0.29f);
				}
				else
				{//地上
					g_Item[nItem].bRetentionl = true;//滞留状態に移行
					g_Item[nItem].pos.y = ITEMSIZE +0.1f;
				}
			}
			//-------------------------------------------------------------ふわふわ浮遊ここまで

			//移動量を更新(疑似慣性で減衰)
			g_Item[nItem].move.x += (0.0f - g_Item[nItem].move.x) * DAMPING_RATIO;
			g_Item[nItem].move.y += (0.0f - g_Item[nItem].move.y) * DAMPING_RATIO;
			g_Item[nItem].move.z += (0.0f - g_Item[nItem].move.z) * DAMPING_RATIO;



			if (g_Item[nItem].ItemType == ITEMTYPE_OHUDA)//御札
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.04f));
			}
			else if (g_Item[nItem].ItemType == ITEMTYPE_KAIHUKU)//回復アイテム
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(0.0f, 1.0f, 0.0f, 0.04f));
			}
			else if (g_Item[nItem].ItemType == ITEMTYPE_EMA)//絵馬(鍵だし??)
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.04f));
			}
			else if (g_Item[nItem].ItemType == ITEMTYPE_WARANINGYO)//身代わり人形
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(1.0f, 0.0f, 1.0f, 0.04f));
			}
			else if (g_Item[nItem].ItemType == ITEMTYPE_SIKIGAMI)//式神
			{
				SetParticle(g_Item[nItem].pos, 30.0f, 12, PARTICLETYPE_ITEM, D3DXCOLOR(1.0f, 1.0f, 0.0f, 0.04f));
			}



			




			//SetPositionShadow(g_Item[nItem].nShadowNum, g_Item[nItem].pos, SHADOWSIZE_ITEM);

			//--------------------------------寿命
			//g_Item[nItem].nLife--;

			//if (g_Item[nItem].nLife < 0)
			//{
			//	//SetExplosion(g_Item[nItem].pos);
			//	g_Item[nItem].bUse = false;
			//	EndProcessShadow(g_Item[nItem].nShadowNum);

			//}
			//--------------------------------寿命

			if (g_Item[nItem].pos.y < 0.0f)
			{

				//EndProcessShadow(g_Item[nItem].nShadowNum);
				//g_Item[nItem].bUse = false;
			}



		}
		pVtx += 4;
	}
	//頂点バッファのアンロック
	g_pVtxBuffItem->Unlock();

}
//=============================
//アイテムの描画処理
//=============================
void DrawItem(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX  mtxTrans;//計算用マトリックス
	D3DXMATRIX mtxView;//ビューマトリックスの取得

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		if (g_Item[nItem].bUse == true)
		{
			//ライトを無効にする
			pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

			////Zの比較変更
			//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
			////Zバッファに書き込まない
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);




			//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&g_Item[nItem].mtxWorldItem);

			//向きを反映
			//D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Item[nItem].rotItem.y, g_Item[nItem].rotItem.x, g_Item[nItem].rotItem.z);

			//D3DXMatrixMultiply(&g_Item[nItem].mtxWorldItem, &g_Item[nItem].mtxWorldItem, &mtxRot);

					//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_Item[nItem].pos.x, g_Item[nItem].pos.y, g_Item[nItem].pos.z);

			D3DXMatrixMultiply(&g_Item[nItem].mtxWorldItem, &g_Item[nItem].mtxWorldItem, &mtxTrans);



			//ビューマトリックスを取得
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);

			//ポリゴンをカメラに対して正面に向ける
			D3DXMatrixInverse(&g_Item[nItem].mtxWorldItem, NULL, &mtxView);//逆行鉄を求める

			g_Item[nItem].mtxWorldItem._41 = 0.0f;
			g_Item[nItem].mtxWorldItem._42 = 0.0f;
			g_Item[nItem].mtxWorldItem._43 = 0.0f;


			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_Item[nItem].pos.x, g_Item[nItem].pos.y, g_Item[nItem].pos.z);

			D3DXMatrixMultiply(&g_Item[nItem].mtxWorldItem, &g_Item[nItem].mtxWorldItem, &mtxTrans);

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_Item[nItem].mtxWorldItem);

			//頂点バッファをデータストリームに設定
			pDevice->SetStreamSource(0, g_pVtxBuffItem, 0, sizeof(VERTEX_3D));

			//頂点フォーマットの設定
			pDevice->SetFVF(FVF_VERTEX_3D);


			//テクスチャの設定
			pDevice->SetTexture(0, g_pTextureItem[g_Item[nItem].ItemType]);

			////アルファブレンディングを加算合成に設定
			//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);


			//アイテムの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//プリミティブの種類
				nItem * 4,//描画する最初の頂点インデックス
				2);//描画するプリミティブ数


			////アルファブレンディングをもとに戻す
			//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);


			//ライトを有効にする
			pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

			////Zの比較変更
			//pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			////Zバッファに書き込まない
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

			
			//テクスチャを戻す
			pDevice->SetTexture(0, NULL);
		}
	}
}
//=============================
//アイテムの取得処理
//=============================
ITEM* GetItem(void)
{
	return &g_Item[0];
}

////=============================
////アイテムカウントの取得処理
////=============================
//ITEMCNT* GetItemCnt_1P(void)
//{
//	return &g_ItemCnt_1P[0];
//}
////=============================
////アイテムカウントの取得処理
////=============================
//ITEMCNT* GetItemCnt_2P(void)
//{
//	return &g_ItemCnt_2P[0];
//}

//=============================
//アイテムの設定処理
//=============================
void SetItem(D3DXVECTOR3 Pos, D3DXVECTOR3 Rot, ITEMTYPE Type)
{
	VERTEX_3D* pVtx;//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffItem->Lock(0, 0, (void**)&pVtx, 0);

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		if (g_Item[nItem].bUse == false)
		{

			g_Item[nItem].pos = Pos;//位置

			g_Item[nItem].move = Rot;
			g_Item[nItem].move *= ITEMMOVESPEED_LOCK;
				
			// 幅、高さ後ほど
			g_Item[nItem].ItemType = Type;
			g_Item[nItem].bUse = true;
			//g_Item[nItem].nLife = 200;
			break;
		}
		pVtx += 4;
	}
	//頂点バッファのアンロック
	g_pVtxBuffItem->Unlock();
}


//=============================
//アイテムの取得制限付き設定処理
//=============================
void SetItem2(D3DXVECTOR3 Pos, D3DXVECTOR3 Rot, ITEMTYPE Type, int NoGetCnt)
{
	VERTEX_3D* pVtx;//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffItem->Lock(0, 0, (void**)&pVtx, 0);

	for (int nItem = 0; nItem < NUMITEM; nItem++)
	{
		if (g_Item[nItem].bUse == false)
		{

			g_Item[nItem].pos = Pos;//位置

			g_Item[nItem].move = Rot;
			g_Item[nItem].move *= ITEMMOVESPEED_LOCK;

			// 幅、高さ後ほど
			g_Item[nItem].ItemType = Type;
			g_Item[nItem].bUse = true;
			g_Item[nItem].bGetNO = true;
			g_Item[nItem].nStayGetCnt = NoGetCnt;



			break;
		}
		pVtx += 4;
	}
	//頂点バッファのアンロック
	g_pVtxBuffItem->Unlock();
}