//=========================================================
//
//DEBUG���f������[DebugModel.cpp]
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


//�O���[�o���ϐ��錾
LPD3DXMESH g_pMeshDebugModel[MAXDEBUGMODEL] = {};//���b�V��(���_���)�ւ̃|�C���^

LPD3DXBUFFER g_pBuffMatDebugModel[MAXDEBUGMODEL] = {};//�}�e���A���ւ̃|�C���^
DWORD g_dwNumMatDebugModel = 0;//�}�e���A���̐�

DEBUGMODEL g_DebugModel[MAXDEBUGMODEL];

//�����Ă郂�f����
int g_NUM_Model = -1;

//�폜���f���̍��W
D3DXVECTOR3 g_DelModelPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

//�Z���N�g�ԍ�
int g_SelectNum = 0;

//=============================
// �f�o�b�O���f������������
//=============================
void InitDebugModel(void)
{    
    g_NUM_Model = -1;
    g_SelectNum = 0;


    //�폜���f���̍��W
    g_DelModelPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    
    // �ϐ��̏�����
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



    //-----------------------------���a---------�s���^�C�v-------�F
// �y�A�łQ���ƂɋL��--�F�͒P�F��(�����F�𑼂̂Ɏg�p������)

    //����łP�y�A
    SetDebugModelSphere( 2, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f),false);//�����_1
    SetDebugModelSphere( 2, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f),false);//�����_2


    SetDebugModelSphere( 4,  D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f),false);//�J����1
    SetDebugModelSphere( 4, D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f),false);//�J����2

   

    //�l�p
    //--------------------------�ŏ��ő�------------�F
  // SetDebugModelBOX(D3DXVECTOR3(-10.0f, 0.0f, -10.0f), D3DXVECTOR3(10.0f, 1000.0f, 10.0f), D3DXCOLOR(5.0f, 0.0f, 0.0f, 5.0f));
    SetDebugModelSphere(40, D3DXCOLOR(0.0f, 5.0f, 5.0f, 0.5f), true);
     SetDebugModelSphere(50, D3DXCOLOR(0.0f, 5.0f, 5.0f, 0.2f),false);//���{



    //����łP�y�A
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
// �f�o�b�O���f���I������
//=============================
void UninitDebugModel(void)
{
    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
    {
        //���b�V���̔j��
        if (g_pMeshDebugModel[nCntZone] != NULL)
        {
            g_pMeshDebugModel[nCntZone]->Release();
            g_pMeshDebugModel[nCntZone] = NULL;
        }
        //�}�e���A���̔j��
        if (g_pBuffMatDebugModel[nCntZone] != NULL)
        {
            g_pBuffMatDebugModel[nCntZone]->Release();
            g_pBuffMatDebugModel[nCntZone] = NULL;
        }
    }
}

//=============================
// �f�o�b�O���f���X�V����
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
    {//2�������ꂽ
        g_SelectNum++;
        if (g_SelectNum > g_NUM_Model)
        {
            g_SelectNum = 0;
        }
    }
    else if (GetkeyboardTrigger(DIK_1) == true)
    {//1�������ꂽ
        g_SelectNum--;
        if (g_SelectNum < 0)
        {
            g_SelectNum = g_NUM_Model;
        }
    }
    else if (GetkeyboardTrigger(DIK_DELETE) == true)
    {//Delete�������ꂽ
        pMapObject[g_SelectNum].bUse = false;
        g_NUM_Model--;
    }

    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
    {
        if (g_DebugModel[nCntZone].bUse == true)
        {
            if (nCntZone == 0)
            {//�����_1
                g_DebugModel[nCntZone].pos = D3DXVECTOR3(pViewMtx[1].ViewPosMtx._41, pViewMtx[1].ViewPosMtx._42, pViewMtx[1].ViewPosMtx._43);
            }
            else if(nCntZone == 1)
            {//�����_2
                g_DebugModel[nCntZone].pos = D3DXVECTOR3(pViewMtx2[1].ViewPosMtx._41, pViewMtx2[1].ViewPosMtx._42, pViewMtx2[1].ViewPosMtx._43);
            }
            else if (nCntZone == 2)
            {//�J����1
                g_DebugModel[nCntZone].pos = pCamera[0].posV;
            }
            else if (nCntZone == 3)
            {//�J����2
                g_DebugModel[nCntZone].pos = pCamera[1].posV;
            }

            else if (nCntZone == 4)
            {//�폜�s��

                if (pMapObject[g_SelectNum].bUse == true)
                {
                    g_DebugModel[nCntZone].pos = pMapObject[g_SelectNum].pos;
                }

               
            }

            else if (nCntZone == 5)
            {//�폜�s��

                if (pMapObject[g_SelectNum].bUse == true)
                {
                    g_DebugModel[nCntZone].pos = pMapObject[g_SelectNum].pos;
                }


            }




          







        //    D3DXVECTOR3 DebugModelMin = g_DebugModel[nCntZone].pos + g_DebugModel[nCntZone].ZoneMin;
        //    D3DXVECTOR3 DebugModelMax = g_DebugModel[nCntZone].pos + g_DebugModel[nCntZone].ZoneMax;

        //    //���C���̈ʒu
        //    // �㉺�̕�
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMax.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMax.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    // ���ʂ̕�
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMax.z), D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMax.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    // ���̑��̕�
        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMin.x, DebugModelMin.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

        //    SetLine(D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMin.x, DebugModelMax.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        //    SetLine(D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMin.z), D3DXVECTOR3(DebugModelMax.x, DebugModelMin.y, DebugModelMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));









        }
    }
}

//=============================
// �f�o�b�O���f���`�揈��
//=============================
void DrawDebugModel(void)
{
    LPDIRECT3DDEVICE9 pDevice = GetDevice();

    D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X

    D3DMATERIAL9 matDef;//���݂̃}�e���A���ۑ��p(�ꎞ�ޔ�)

    D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^

    for (int nCntZone = 0; nCntZone < MAXDEBUGMODEL; nCntZone++)
    {
        if (g_DebugModel[nCntZone].bUse == true)
        {


            //���[���h�}�g���b�N�X�̏�����
            D3DXMatrixIdentity(&g_DebugModel[nCntZone].mtxWorld);

            // ���f���̃T�C�Y��ύX
            D3DXMatrixScaling(&g_DebugModel[nCntZone].mtxWorld, g_DebugModel[nCntZone].SizeMag.x, g_DebugModel[nCntZone].SizeMag.y, g_DebugModel[nCntZone].SizeMag.z);

            ////�����𔽉f
            //D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Player.rot.y, g_Player.rot.x, g_Player.rot.z);

            //D3DXMatrixMultiply(&g_Player.mtxWorld, &g_Player.mtxWorld, &mtxRot);

            //�ʒu�𔽉f
            D3DXMatrixTranslation(&mtxTrans, g_DebugModel[nCntZone].pos.x, g_DebugModel[nCntZone].pos.y, g_DebugModel[nCntZone].pos.z);

            D3DXMatrixMultiply(&g_DebugModel[nCntZone].mtxWorld, &g_DebugModel[nCntZone].mtxWorld, &mtxTrans);

            //���[���h�}�g���b�N�X�̐ݒ�
            pDevice->SetTransform(D3DTS_WORLD, &g_DebugModel[nCntZone].mtxWorld);

            //���݂̃}�e���A�����擾
            pDevice->GetMaterial(&matDef);

            //�}�e���A���f�[�^�ւ̃|�C���^���擾
            pMat = (D3DXMATERIAL*)g_pBuffMatDebugModel[nCntZone]->GetBufferPointer();

            for (int nCntMat = 0; nCntMat < (int)g_dwNumMatDebugModel; nCntMat++)
            {
                //�}�e���A���̐ݒ�
                pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

                //�e�N�X�`���̐ݒ�
                pDevice->SetTexture(0, NULL);//����͐ݒ肵�Ȃ�

                //���f��(�p�[�c)�̕`��
                g_pMeshDebugModel[nCntMat]->DrawSubset(nCntMat);

                //�ۑ����Ă��}�e���A����߂�
                pDevice->SetMaterial(&matDef);


                // �}�e���A���̐ݒ�
                pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

                // �f�B�t���[�Y�J���[��ύX�i��: �Ԃ��F�j
                pMat[nCntMat].MatD3D.Diffuse = D3DXCOLOR(g_DebugModel[nCntZone].ZoneColor.r * g_DebugModel[nCntZone].SizeMag.x, g_DebugModel[nCntZone].ZoneColor.g * g_DebugModel[nCntZone].SizeMag.x, g_DebugModel[nCntZone].ZoneColor.b * g_DebugModel[nCntZone].SizeMag.x, g_DebugModel[nCntZone].ZoneColor.a);




            }
        }
    }




}
//=============================


//=============================
//�ݒu�p�R�����g
//=============================
void DrawDebugDelC0mment(void)
{

    DrawTextSet(D3DXVECTOR3(550.0f, 570.0f, 0.0f), 20, FONT_SOUKOUMINCHO, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), "1,2�Ń��f���؂�ւ��A\nDelete�Ń��f���폜" );
    DrawTextSet(D3DXVECTOR3(550.0f, 630.0f, 0.0f), 20, FONT_SOUKOUMINCHO, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), "���f��%d/%d", g_SelectNum, g_NUM_Model);
}


//=============================
// �f�o�b�O���f���ݒ菈��
//=============================
//----------------------------���a---------�s���^�C�v-------�F
void SetDebugModelSphere(float Radius,D3DXCOLOR ZoneColor,bool Beacon)
{
    //�f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice = GetDevice();//----------------���������ς�

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
                //�T�C�Y�ϓ�
                g_DebugModel[nCntZone].SizeMag.x = g_DebugModel[nCntZone].ZoneMax.x / 10.0f;
                g_DebugModel[nCntZone].SizeMag.y = g_DebugModel[nCntZone].ZoneMax.y / 10.0f;
                g_DebugModel[nCntZone].SizeMag.z = g_DebugModel[nCntZone].ZoneMax.z / 10.0f;
            }
            else
            {
                //�T�C�Y�ϓ�
                g_DebugModel[nCntZone].SizeMag.x = g_DebugModel[nCntZone].ZoneMax.x / 20.0f;
                g_DebugModel[nCntZone].SizeMag.y = g_DebugModel[nCntZone].ZoneMax.y;
                g_DebugModel[nCntZone].SizeMag.z = g_DebugModel[nCntZone].ZoneMax.z / 20.0f;
            }



        //    g_DebugModel[nCntZone].ActionType = ActionType;//�]�ڐ�]�ڕ���
        //   g_DebugModel[nCntZone].bPossibility = true;
            g_DebugModel[nCntZone].bUse = true;


            //�t�@�C���̓ǂݍ���
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
////�l�p
////=============================
//////-----------------------------------�ŏ��ő�------------�F
//void SetDebugModelBOX(D3DXVECTOR3 Min, D3DXVECTOR3 Max, D3DXCOLOR ZoneColor)
//{
//    //�f�o�C�X�̎擾
//    LPDIRECT3DDEVICE9 pDevice = GetDevice();//----------------���������ς�
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
//            //�T�C�Y�ϓ�
//            g_DebugModel[nCntZone].SizeMag.x = g_DebugModel[nCntZone].ZoneMax.x;
//            g_DebugModel[nCntZone].SizeMag.y = g_DebugModel[nCntZone].ZoneMax.y;
//            g_DebugModel[nCntZone].SizeMag.z = g_DebugModel[nCntZone].ZoneMax.z;
//
//
//            //    g_DebugModel[nCntZone].ActionType = ActionType;//�]�ڐ�]�ڕ���
//            //   g_DebugModel[nCntZone].bPossibility = true;
//            g_DebugModel[nCntZone].bUse = true;
//
//
//            //�t�@�C���̓ǂݍ���
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
