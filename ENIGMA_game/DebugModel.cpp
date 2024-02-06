//=========================================================
//
//DEBUGモデル処理[DebugModel.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "DebugModel.h"
#include "player.h"
#include "player2.h"
#include "camera.h"
#include "input.h"
#include "text.h"
#include "model.h"
//#include "line.h"
//using namespace __unnamed_enum_0153_1;


//グローバル変数宣言
LPD3DXMESH g_pMeshDebugModel[MAXDEBUGMODEL] = {};//メッシュ(頂点情報)へのポインタ

LPD3DXBUFFER g_pBuffMatDebugModel[MAXDEBUGMODEL] = {};//マテリアルへのポインタ
DWORD g_dwNumMatDebugModel = 0;//マテリアルの数

DEBUGMODEL g_DebugModel[MAXDEBUGMODEL];

//生きてるモデル数
int g_NUM_Model = -1;

//削除モデルの座標
D3DXVECTOR3 g_DelModelPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

//セレクト番号
int g_SelectNum = 0;

//=============================
// デバッグモデル初期化処理
//=============================
void InitDebugModel(void)
{    
    g_NUM_Model = -1;
    g_SelectNum = 0;


    //削除モデルの座標
    g_DelModelPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    
    // 変数の初期化
    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
    {
        g_DebugModel[nCntZone].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
        g_DebugModel[nCntZone].ZoneMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
        g_DebugModel[nCntZone].ZoneMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
        g_DebugModel[nCntZone].nZoneIndex = -1;
        //   g_DebugModel[nCntZone].nParentIndex = -1;
      //  g_DebugModel[nCntZone].ActionType = ACTION_TYPE_MAX;
       // g_DebugModel[nCntZone].bPossibility = false;
        g_DebugModel[nCntZone].bUse = false;
    }



    //-----------------------------半径---------行動タイプ-------色
// ペアで２つごとに記入--色は単色で(合成色を他のに使用したい)

    //これで１ペア
    SetDebugModelSphere( 2, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f),false);//注視点1
    SetDebugModelSphere( 2, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f),false);//注視点2


    SetDebugModelSphere( 4,  D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f),false);//カメラ1
    SetDebugModelSphere( 4, D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f),false);//カメラ2

   

    //四角
    //--------------------------最小最大------------色
  // SetDebugModelBOX(D3DXVECTOR3(-10.0f, 0.0f, -10.0f), D3DXVECTOR3(10.0f, 1000.0f, 10.0f), D3DXCOLOR(5.0f, 0.0f, 0.0f, 5.0f));
    SetDebugModelSphere(40, D3DXCOLOR(0.0f, 5.0f, 5.0f, 0.5f), true);
     SetDebugModelSphere(50, D3DXCOLOR(0.0f, 5.0f, 5.0f, 0.2f),false);//根本



    //これで１ペア
    //SetDebugModel(D3DXVECTOR3(2000.0f, 0.0f, -700.0f), D3DXVECTOR3(-50.0f, 0.0f, -50.0f), D3DXVECTOR3(50.0f, 100.0f, 50.0f), 0, 1, ACTION_TYPE_MAX);
    //SetDebugModel(D3DXVECTOR3(2000.0f, 0.0f, 700.0f), D3DXVECTOR3(-50.0f, 0.0f, -50.0f), D3DXVECTOR3(50.0f, 100.0f, 50.0f), 1, 0, ACTION_TYPE_MAX);


   // SetDebugModel(D3DXVECTOR3(200.0f, 100.0f, -300.0f), D3DXVECTOR3(-50.0f, 0.0f, -50.0f), D3DXVECTOR3(50.0f, 100.0f, 50.0f), 2, 3, ACTION_TYPE_MAX_Z);
   // SetDebugModel(D3DXVECTOR3(200.0f, 50.0f, 300.0f), D3DXVECTOR3(-50.0f, 0.0f, -50.0f), D3DXVECTOR3(50.0f, 100.0f, 50.0f), 3, 2, TRANS_ANGLE_MIN_Z);

    MAPOBJECT* pMapObject;
    pMapObject = GetMapObject();

    for (int i = 0; i < MAX_MODEL; i++)
    {
        if (pMapObject[i].bUse == true)
        {
            g_NUM_Model++;
        }
    }

}

//=============================
// デバッグモデル終了処理
//=============================
void UninitDebugModel(void)
{
    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
    {
        //メッシュの破棄
        if (g_pMeshDebugModel[nCntZone] != NULL)
        {
            g_pMeshDebugModel[nCntZone]->Release();
            g_pMeshDebugModel[nCntZone] = NULL;
        }
        //マテリアルの破棄
        if (g_pBuffMatDebugModel[nCntZone] != NULL)
        {
            g_pBuffMatDebugModel[nCntZone]->Release();
            g_pBuffMatDebugModel[nCntZone] = NULL;
        }
    }
}

//=============================
// デバッグモデル更新処理
//=============================
void UpdateDebugModel(void)
{
    Camera* pCamera;
    pCamera = GetCamera();

    View* pViewMtx = GetView();

    View2* pViewMtx2 = GetView_2P();

    MAPOBJECT* pMapObject;
    pMapObject = GetMapObject();

    if (GetkeyboardTrigger(DIK_2) == true)
    {//2がおされた
        g_SelectNum++;
        if (g_SelectNum > g_NUM_Model)
        {
            g_SelectNum = 0;
        }
    }
    else if (GetkeyboardTrigger(DIK_1) == true)
    {//1がおされた
        g_SelectNum--;
        if (g_SelectNum < 0)
        {
            g_SelectNum = g_NUM_Model;
        }
    }
    else if (GetkeyboardTrigger(DIK_DELETE) == true)
    {//Deleteがおされた
        pMapObject[g_SelectNum].bUse = false;
        g_NUM_Model--;
    }

    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
    {
        if (g_DebugModel[nCntZone].bUse == true)
        {
            if (nCntZone == 0)
            {//注視点1
                g_DebugModel[nCntZone].pos = D3DXVECTOR3(pViewMtx[1].ViewPosMtx._41, pViewMtx[1].ViewPosMtx._42, pViewMtx[1].ViewPosMtx._43);
            }
            else if(nCntZone == 1)
            {//注視点2
                g_DebugModel[nCntZone].pos = D3DXVECTOR3(pViewMtx2[1].ViewPosMtx._41, pViewMtx2[1].ViewPosMtx._42, pViewMtx2[1].ViewPosMtx._43);
            }
            else if (nCntZone == 2)
            {//カメラ1
                g_DebugModel[nCntZone].pos = pCamera[0].posV;
            }
            else if (nCntZone == 3)
            {//カメラ2
                g_DebugModel[nCntZone].pos = pCamera[1].posV;
            }

            else if (nCntZone == 4)
            {//削除ピン

                if (pMapObject[g_SelectNum].bUse == true)
                {
                    g_DebugModel[nCntZone].pos = pMapObject[g_SelectNum].pos;
                }

               
            }

            else if (nCntZone == 5)
            {//削除ピン

                if (pMapObject[g_SelectNum].bUse == true)
                {
                    g_DebugModel[nCntZone].pos = pMapObject[g_SelectNum].pos;
                }


            }




          







        //    D3DXVECTOR3 DebugModelMin = g_DebugModel[nCntZone].pos + g_DebugModel[nCntZone].ZoneMin;
        //    D3DXVECTOR3 DebugModelMax = g_DebugModel[nCntZone].pos + g_DebugModel[nCntZone].ZoneMax;

        //    //ラインの位置
        //    // 上下の辺
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMax.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMax.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    // 側面の辺
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMax.z), D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMax.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    // その他の辺
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));









        }
    }
}

//=============================
// デバッグモデル描画処理
//=============================
void DrawDebugModel(void)
{
    LPDIRECT3DDEVICE9 pDevice = GetDevice();

    D3DXMATRIX mtxRot, mtxTrans;//計算用マトリックス

    D3DMATERIAL9 matDef;//現在のマテリアル保存用(一時退避)

    D3DXMATERIAL* pMat;//マテリアルデータへのポインタ

    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
    {
        if (g_DebugModel[nCntZone].bUse == true)
        {


            //ワールドマトリックスの初期化
            D3DXMatrixIdentity(&g_DebugModel[nCntZone].mtxWorld);

            // モデルのサイズを変更
            D3DXMatrixScaling(&g_DebugModel[nCntZone].mtxWorld, g_DebugModel[nCntZone].SizeMag.x, g_DebugModel[nCntZone].SizeMag.y, g_DebugModel[nCntZone].SizeMag.z);

            ////向きを反映
            //D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Player.rot.y, g_Player.rot.x, g_Player.rot.z);

            //D3DXMatrixMultiply(&g_Player.mtxWorld, &g_Player.mtxWorld, &mtxRot);

            //位置を反映
            D3DXMatrixTranslation(&mtxTrans, g_DebugModel[nCntZone].pos.x, g_DebugModel[nCntZone].pos.y, g_DebugModel[nCntZone].pos.z);

            D3DXMatrixMultiply(&g_DebugModel[nCntZone].mtxWorld, &g_DebugModel[nCntZone].mtxWorld, &mtxTrans);

            //ワールドマトリックスの設定
            pDevice->SetTransform(D3DTS_WORLD, &g_DebugModel[nCntZone].mtxWorld);

            //現在のマテリアルを取得
            pDevice->GetMaterial(&matDef);

            //マテリアルデータへのポインタを取得
            pMat = (D3DXMATERIAL*)g_pBuffMatDebugModel[nCntZone]->GetBufferPointer();

            for (int nCntMat = 0; nCntMat < (int)g_dwNumMatDebugModel; nCntMat++)
            {
                //マテリアルの設定
                pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

                //テクスチャの設定
                pDevice->SetTexture(0, NULL);//今回は設定しない

                //モデル(パーツ)の描画
                g_pMeshDebugModel[nCntMat]->DrawSubset(nCntMat);

                //保存してたマテリアルを戻す
                pDevice->SetMaterial(&matDef);


                // マテリアルの設定
                pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

                // ディフューズカラーを変更（例: 赤い色）
                pMat[nCntMat].MatD3D.Diffuse = D3DXCOLOR(g_DebugModel[nCntZone].ZoneColor.r * g_DebugModel[nCntZone].SizeMag.x, g_DebugModel[nCntZone].ZoneColor.g * g_DebugModel[nCntZone].SizeMag.x, g_DebugModel[nCntZone].ZoneColor.b * g_DebugModel[nCntZone].SizeMag.x, g_DebugModel[nCntZone].ZoneColor.a);




            }
        }
    }




}
//=============================


//=============================
//設置用コメント
//=============================
void DrawDebugDelC0mment(void)
{

    DrawTextSet(D3DXVECTOR3(550.0f, 570.0f, 0.0f), 20, FONT_SOUKOUMINCHO, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), "1,2でモデル切り替え、\nDeleteでモデル削除" );
    DrawTextSet(D3DXVECTOR3(550.0f, 630.0f, 0.0f), 20, FONT_SOUKOUMINCHO, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), "モデル%d/%d", g_SelectNum, g_NUM_Model);
}


//=============================
// デバッグモデル設定処理
//=============================
//----------------------------半径---------行動タイプ-------色
void SetDebugModelSphere(float Radius,D3DXCOLOR ZoneColor,bool Beacon)
{
    //デバイスの取得
    LPDIRECT3DDEVICE9 pDevice = GetDevice();//----------------書き換え済み

    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
    {
        if (g_DebugModel[nCntZone].bUse == false)
        {
           // g_DebugModel[nCntZone].pos = Pos;
            g_DebugModel[nCntZone].Radius = Radius;

            g_DebugModel[nCntZone].ZoneMin = D3DXVECTOR3(-Radius, -Radius, -Radius);
            g_DebugModel[nCntZone].ZoneMax = D3DXVECTOR3(Radius, Radius, Radius);
            g_DebugModel[nCntZone].ZoneColor = ZoneColor;
            g_DebugModel[nCntZone].EscapeZoneColor = ZoneColor;

            if (Beacon == false)
            {
                //サイズ変動
                g_DebugModel[nCntZone].SizeMag.x = g_DebugModel[nCntZone].ZoneMax.x / 10.0f;
                g_DebugModel[nCntZone].SizeMag.y = g_DebugModel[nCntZone].ZoneMax.y / 10.0f;
                g_DebugModel[nCntZone].SizeMag.z = g_DebugModel[nCntZone].ZoneMax.z / 10.0f;
            }
            else
            {
                //サイズ変動
                g_DebugModel[nCntZone].SizeMag.x = g_DebugModel[nCntZone].ZoneMax.x / 20.0f;
                g_DebugModel[nCntZone].SizeMag.y = g_DebugModel[nCntZone].ZoneMax.y;
                g_DebugModel[nCntZone].SizeMag.z = g_DebugModel[nCntZone].ZoneMax.z / 20.0f;
            }



        //    g_DebugModel[nCntZone].ActionType = ActionType;//転移先転移方向
        //   g_DebugModel[nCntZone].bPossibility = true;
            g_DebugModel[nCntZone].bUse = true;


            //ファイルの読み込み
            D3DXLoadMeshFromX("data\\MODEL\\DebugModel\\SPHERE.x",
                D3DXMESH_SYSTEMMEM,
                pDevice,
                NULL,
                &g_pBuffMatDebugModel[nCntZone],
                NULL,
                &g_dwNumMatDebugModel,
                &g_pMeshDebugModel[nCntZone]);


            break;
        }
    }
}
////=============================
////四角
////=============================
//////-----------------------------------最小最大------------色
//void SetDebugModelBOX(D3DXVECTOR3 Min, D3DXVECTOR3 Max, D3DXCOLOR ZoneColor)
//{
//    //デバイスの取得
//    LPDIRECT3DDEVICE9 pDevice = GetDevice();//----------------書き換え済み
//
//    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
//    {
//        if (g_DebugModel[nCntZone].bUse == false)
//        {
//            // g_DebugModel[nCntZone].pos = Pos;
//         //   g_DebugModel[nCntZone].Radius = Radius;
//
//            g_DebugModel[nCntZone].ZoneMin = Min;
//            g_DebugModel[nCntZone].ZoneMax = Max;
//            g_DebugModel[nCntZone].ZoneColor = ZoneColor;
//            g_DebugModel[nCntZone].EscapeZoneColor = ZoneColor;
//
//            //サイズ変動
//            g_DebugModel[nCntZone].SizeMag.x = g_DebugModel[nCntZone].ZoneMax.x;
//            g_DebugModel[nCntZone].SizeMag.y = g_DebugModel[nCntZone].ZoneMax.y;
//            g_DebugModel[nCntZone].SizeMag.z = g_DebugModel[nCntZone].ZoneMax.z;
//
//
//            //    g_DebugModel[nCntZone].ActionType = ActionType;//転移先転移方向
//            //   g_DebugModel[nCntZone].bPossibility = true;
//            g_DebugModel[nCntZone].bUse = true;
//
//
//            //ファイルの読み込み
//            D3DXLoadMeshFromX("data\\MODEL\\DebugModel\\BOX.x",
//                D3DXMESH_SYSTEMMEM,
//                pDevice,
//                NULL,
//                &g_pBuffMatDebugModel[nCntZone],
//                NULL,
//                &g_dwNumMatDebugModel,
//                &g_pMeshDebugModel[nCntZone]);
//
//
//            break;
//        }
//    }
//}
