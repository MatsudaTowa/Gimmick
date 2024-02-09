//=========================================================
//
//エリアによって転移させる処理[transfergate.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "transfergate.h"
//#include "player.h"
//#include "player2.h"
#include "line.h"


//グローバル変数宣言
LPD3DXMESH g_pMeshGate[MAXGATE] = {};//メッシュ(頂点情報)へのポインタ

LPD3DXBUFFER g_pBuffMatGate[MAXGATE] = {};//マテリアルへのポインタ
DWORD g_dwNumMatGate = 0;//マテリアルの数

TRANSFERGATE g_TransferGate[MAXGATE];




//=============================
// 転移門初期化処理
//=============================
void InitTransferGate(void)
{    // 変数の初期化
    for (int nCntGate = 0; nCntGate < MAXGATE; nCntGate++)
    {
        g_TransferGate[nCntGate].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
        g_TransferGate[nCntGate].GateMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
        g_TransferGate[nCntGate].GateMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
        g_TransferGate[nCntGate].nGateIndex = -1;
        g_TransferGate[nCntGate].nParentIndex = -1;
        g_TransferGate[nCntGate].ParentTransAngle = TRANS_ANGLE_MAX;
        g_TransferGate[nCntGate].bCompulsionTrans = false;
        g_TransferGate[nCntGate].bPossibility = false;
        g_TransferGate[nCntGate].bUse = false;
        g_TransferGate[nCntGate].bActiomTrans = false;
    }





//---------------------座標------------------------最小--------------------最大---------自分の番号----転移先の番号--色--強制転移かどうか---------行動ボタンで転移かどうか
// ペアで２つごとに記入--色は単色で(合成色を他のに使用したい)
    //
    //---****備考--行動ボタン転移は、転位方向(TRANS_ANGLE～)を「TRANS_ANGLE_MAX」にできない。方向を指定するべし
    //

    //-----基本はボタンで移動かつみんなで移動になるかも

    //---通過方向
    SetTransferGate(D3DXVECTOR3(100.0f, 0.0f, 0.0f), D3DXVECTOR3(-50.0f, 0.0f, -60.0f), D3DXVECTOR3(50.0f, 100.0f, 60.0f), 0, 1, TRANS_ANGLE_MIN_X, D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.7f),false,true);
    SetTransferGate(D3DXVECTOR3(-50.0f, 0.0f, -1000.0f), D3DXVECTOR3(-50.0f, 0.0f, -60.0f), D3DXVECTOR3(50.0f, 100.0f, 60.0f), 1, 0, TRANS_ANGLE_MIN_X, D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.7f),false, true);

    ////--出現方向指定
    //SetTransferGate(D3DXVECTOR3(200.0f, 100.0f, -300.0f), D3DXVECTOR3(-100.0f, 0.0f, -60.0f), D3DXVECTOR3(100.0f, 100.0f, 60.0f), 2, 3, TRANS_ANGLE_MAX_Z, D3DXCOLOR(1.0f, 1.0f, 0.0f, 0.7f),false, true);
    //SetTransferGate(D3DXVECTOR3(200.0f, 0.0f, 300.0f), D3DXVECTOR3(-100.0f, 0.0f, -60.0f), D3DXVECTOR3(100.0f, 100.0f, 60.0f), 3, 2, TRANS_ANGLE_MIN_Z, D3DXCOLOR(1.0f, 1.0f, 0.0f, 0.7f), false, true);
    

    ////---通過方向
    //SetTransferGate(D3DXVECTOR3(-2000.0f, 0.0f, -700.0f), D3DXVECTOR3(-100.0f, 0.0f, -60.0f), D3DXVECTOR3(100.0f, 100.0f, 60.0f), 4, 5, TRANS_ANGLE_MIN_X, D3DXCOLOR(1.0f, 0.0f, 1.0f, 0.7f), true, true);
    //SetTransferGate(D3DXVECTOR3(-2000.0f, 0.0f, 700.0f), D3DXVECTOR3(-100.0f, 0.0f, -60.0f), D3DXVECTOR3(100.0f, 100.0f, 60.0f), 5, 4, TRANS_ANGLE_MAX_Z, D3DXCOLOR(1.0f, 0.0f, 1.0f, 0.7f), true, true);



    

}

//=============================
// 転移門終了処理
//=============================
void UninitTransferGate(void)
{
    for (int nCntGate = 0; nCntGate < MAXGATE; nCntGate++)
    {
        //メッシュの破棄
        if (g_pMeshGate[nCntGate] != NULL)
        {
            g_pMeshGate[nCntGate]->Release();
            g_pMeshGate[nCntGate] = NULL;
        }
        //マテリアルの破棄
        if (g_pBuffMatGate[nCntGate] != NULL)
        {
            g_pBuffMatGate[nCntGate]->Release();
            g_pBuffMatGate[nCntGate] = NULL;
        }
    }
}

//=============================
// 転移門更新処理
//=============================
void UpdateTransferGate(void)
{
    for (int nCntGate = 0; nCntGate < MAXGATE; nCntGate++)
    {
        if (g_TransferGate[nCntGate].bUse == true)
        {
            D3DXVECTOR3 TransferGateMin = g_TransferGate[nCntGate].pos + g_TransferGate[nCntGate].GateMin;
            D3DXVECTOR3 TransferGateMax = g_TransferGate[nCntGate].pos + g_TransferGate[nCntGate].GateMax;
   
#if _DEBUG
            ////ラインの位置
            //// 上下の辺
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMax.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMax.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //// 側面の辺
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMax.z), D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMax.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //// その他の辺
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        
#endif






        
        }
    }
}

//=============================
// 転移門描画処理
//=============================
void DrawTransferGate(void)
{
    LPDIRECT3DDEVICE9 pDevice = GetDevice();

    D3DXMATRIX mtxRot, mtxTrans;//計算用マトリックス

    D3DMATERIAL9 matDef;//現在のマテリアル保存用(一時退避)

    D3DXMATERIAL* pMat;//マテリアルデータへのポインタ

    for (int nCntGate = 0; nCntGate < MAXGATE; nCntGate++)
    {
        if (g_TransferGate[nCntGate].bUse == true)
        {
            ////ライトを無効にする
            //pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

            ////Zの比較変更
            //pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
            ////Zバッファに書き込まない
            //pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);



            //ワールドマトリックスの初期化
            D3DXMatrixIdentity(&g_TransferGate[nCntGate].mtxWorld);

            // モデルのサイズを変更
            D3DXMatrixScaling(&g_TransferGate[nCntGate].mtxWorld, g_TransferGate[nCntGate].SizeMag.x, g_TransferGate[nCntGate].SizeMag.y, g_TransferGate[nCntGate].SizeMag.z);

            ////向きを反映
            //D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Player.rot.y, g_Player.rot.x, g_Player.rot.z);

            //D3DXMatrixMultiply(&g_Player.mtxWorld, &g_Player.mtxWorld, &mtxRot);

            //位置を反映
            D3DXMatrixTranslation(&mtxTrans, g_TransferGate[nCntGate].pos.x, g_TransferGate[nCntGate].pos.y, g_TransferGate[nCntGate].pos.z);

            D3DXMatrixMultiply(&g_TransferGate[nCntGate].mtxWorld, &g_TransferGate[nCntGate].mtxWorld, &mtxTrans);

            //ワールドマトリックスの設定
            pDevice->SetTransform(D3DTS_WORLD, &g_TransferGate[nCntGate].mtxWorld);

            //現在のマテリアルを取得
            pDevice->GetMaterial(&matDef);

            //マテリアルデータへのポインタを取得
            pMat = (D3DXMATERIAL*)g_pBuffMatGate[nCntGate]->GetBufferPointer();

            for (int nCntMat = 0; nCntMat < (int)g_dwNumMatGate; nCntMat++)
            {
                //マテリアルの設定
                pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

                //テクスチャの設定
                pDevice->SetTexture(0, NULL);//今回は設定しない

                //モデル(パーツ)の描画
                g_pMeshGate[nCntMat]->DrawSubset(nCntMat);

                //保存してたマテリアルを戻す
                pDevice->SetMaterial(&matDef);


                // マテリアルの設定
                pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

                // ディフューズカラーを変更（例: 赤い色）
                pMat[nCntMat].MatD3D.Diffuse = D3DXCOLOR(g_TransferGate[nCntGate].GateColor.r * g_TransferGate[nCntGate].SizeMag.x, g_TransferGate[nCntGate].GateColor.g * g_TransferGate[nCntGate].SizeMag.x, g_TransferGate[nCntGate].GateColor.b * g_TransferGate[nCntGate].SizeMag.x, g_TransferGate[nCntGate].GateColor.a);
          
                ////ライトを有効にする
                //pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

                ////Zの比較変更
                //pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
                ////Zバッファに書き込まない
                //pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
            }
        }
    }




}
//=============================
// 転移門取得処理
//=============================
TRANSFERGATE* GetTransferGate(void)
{
    return &g_TransferGate[0];
}
//=============================
// 転移門設定処理
//=============================
//-----------------------------自分座標-----------------最小----------------最大---------自分の番号----転移先の番号--矯正転移かどうか--行動ボタンで転移かどうか
void SetTransferGate(D3DXVECTOR3 Pos, D3DXVECTOR3 GateMin, D3DXVECTOR3 GateMax, int nGateIndex, int nParentIndex, TRANSANGLE ParentTransAngle, D3DXCOLOR GateColor, bool bCompulsionTrans, bool bActionTrans)
{    
    //デバイスの取得
    LPDIRECT3DDEVICE9 pDevice = GetDevice();//----------------書き換え済み

    for (int nCntGate = 0; nCntGate < MAXGATE; nCntGate++)
    {
        if (g_TransferGate[nCntGate].bUse == false)
        {
            g_TransferGate[nCntGate].pos = Pos;
            g_TransferGate[nCntGate].GateMin = GateMin;
            g_TransferGate[nCntGate].GateMax = GateMax;
            g_TransferGate[nCntGate].GateColor = GateColor;
            g_TransferGate[nCntGate].bActiomTrans = bActionTrans;

            //サイズ変動
             g_TransferGate[nCntGate].SizeMag.x = g_TransferGate[nCntGate].GateMax.x / 10.0f;
             g_TransferGate[nCntGate].SizeMag.y = g_TransferGate[nCntGate].GateMax.y / 20.0f;
             g_TransferGate[nCntGate].SizeMag.z = g_TransferGate[nCntGate].GateMax.z / 10.0f;



            g_TransferGate[nCntGate].nGateIndex = nGateIndex;//自分の番号
            g_TransferGate[nCntGate].nParentIndex = nParentIndex;//転移先の番号
            g_TransferGate[nCntGate].ParentTransAngle = ParentTransAngle;//転移先転移方向
            g_TransferGate[nCntGate].bCompulsionTrans = bCompulsionTrans;//矯正転移か

            g_TransferGate[nCntGate].bPossibility = true;//---------------------------------とりあえず
            g_TransferGate[nCntGate].bUse = true;


            //ファイルの読み込み
            D3DXLoadMeshFromX("data\\MODEL\\DebugModel\\BOX.x",
                D3DXMESH_SYSTEMMEM,
                pDevice,
                NULL,
                &g_pBuffMatGate[nCntGate],
                NULL,
                &g_dwNumMatGate,
                &g_pMeshGate[nCntGate]);


            break;
        }
    }
}

