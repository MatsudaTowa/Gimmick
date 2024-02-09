//=========================================================
//
//�G���A�ɂ���ē]�ڂ����鏈��[transfergate.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "transfergate.h"
//#include "player.h"
//#include "player2.h"
#include "line.h"


//�O���[�o���ϐ��錾
LPD3DXMESH g_pMeshGate[MAXGATE] = {};//���b�V��(���_���)�ւ̃|�C���^

LPD3DXBUFFER g_pBuffMatGate[MAXGATE] = {};//�}�e���A���ւ̃|�C���^
DWORD g_dwNumMatGate = 0;//�}�e���A���̐�

TRANSFERGATE g_TransferGate[MAXGATE];




//=============================
// �]�ږ叉��������
//=============================
void InitTransferGate(void)
{    // �ϐ��̏�����
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





//---------------------���W------------------------�ŏ�--------------------�ő�---------�����̔ԍ�----�]�ڐ�̔ԍ�--�F--�����]�ڂ��ǂ���---------�s���{�^���œ]�ڂ��ǂ���
// �y�A�łQ���ƂɋL��--�F�͒P�F��(�����F�𑼂̂Ɏg�p������)
    //
    //---****���l--�s���{�^���]�ڂ́A�]�ʕ���(TRANS_ANGLE�`)���uTRANS_ANGLE_MAX�v�ɂł��Ȃ��B�������w�肷��ׂ�
    //

    //-----��{�̓{�^���ňړ����݂�Ȃňړ��ɂȂ邩��

    //---�ʉߕ���
    SetTransferGate(D3DXVECTOR3(100.0f, 0.0f, 0.0f), D3DXVECTOR3(-50.0f, 0.0f, -60.0f), D3DXVECTOR3(50.0f, 100.0f, 60.0f), 0, 1, TRANS_ANGLE_MIN_X, D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.7f),false,true);
    SetTransferGate(D3DXVECTOR3(-50.0f, 0.0f, -1000.0f), D3DXVECTOR3(-50.0f, 0.0f, -60.0f), D3DXVECTOR3(50.0f, 100.0f, 60.0f), 1, 0, TRANS_ANGLE_MIN_X, D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.7f),false, true);

    ////--�o�������w��
    //SetTransferGate(D3DXVECTOR3(200.0f, 100.0f, -300.0f), D3DXVECTOR3(-100.0f, 0.0f, -60.0f), D3DXVECTOR3(100.0f, 100.0f, 60.0f), 2, 3, TRANS_ANGLE_MAX_Z, D3DXCOLOR(1.0f, 1.0f, 0.0f, 0.7f),false, true);
    //SetTransferGate(D3DXVECTOR3(200.0f, 0.0f, 300.0f), D3DXVECTOR3(-100.0f, 0.0f, -60.0f), D3DXVECTOR3(100.0f, 100.0f, 60.0f), 3, 2, TRANS_ANGLE_MIN_Z, D3DXCOLOR(1.0f, 1.0f, 0.0f, 0.7f), false, true);
    

    ////---�ʉߕ���
    //SetTransferGate(D3DXVECTOR3(-2000.0f, 0.0f, -700.0f), D3DXVECTOR3(-100.0f, 0.0f, -60.0f), D3DXVECTOR3(100.0f, 100.0f, 60.0f), 4, 5, TRANS_ANGLE_MIN_X, D3DXCOLOR(1.0f, 0.0f, 1.0f, 0.7f), true, true);
    //SetTransferGate(D3DXVECTOR3(-2000.0f, 0.0f, 700.0f), D3DXVECTOR3(-100.0f, 0.0f, -60.0f), D3DXVECTOR3(100.0f, 100.0f, 60.0f), 5, 4, TRANS_ANGLE_MAX_Z, D3DXCOLOR(1.0f, 0.0f, 1.0f, 0.7f), true, true);



    

}

//=============================
// �]�ږ�I������
//=============================
void UninitTransferGate(void)
{
    for (int nCntGate = 0; nCntGate < MAXGATE; nCntGate++)
    {
        //���b�V���̔j��
        if (g_pMeshGate[nCntGate] != NULL)
        {
            g_pMeshGate[nCntGate]->Release();
            g_pMeshGate[nCntGate] = NULL;
        }
        //�}�e���A���̔j��
        if (g_pBuffMatGate[nCntGate] != NULL)
        {
            g_pBuffMatGate[nCntGate]->Release();
            g_pBuffMatGate[nCntGate] = NULL;
        }
    }
}

//=============================
// �]�ږ�X�V����
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
            ////���C���̈ʒu
            //// �㉺�̕�
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMax.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMax.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //// ���ʂ̕�
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMin.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMax.z), D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMax.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //// ���̑��̕�
            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMin.x, TransferGateMin.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));

            //SetLine(D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMin.x, TransferGateMax.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
            //SetLine(D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMin.z), D3DXVECTOR3(TransferGateMax.x, TransferGateMin.y, TransferGateMax.z), D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
        
#endif






        
        }
    }
}

//=============================
// �]�ږ�`�揈��
//=============================
void DrawTransferGate(void)
{
    LPDIRECT3DDEVICE9 pDevice = GetDevice();

    D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X

    D3DMATERIAL9 matDef;//���݂̃}�e���A���ۑ��p(�ꎞ�ޔ�)

    D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^

    for (int nCntGate = 0; nCntGate < MAXGATE; nCntGate++)
    {
        if (g_TransferGate[nCntGate].bUse == true)
        {
            ////���C�g�𖳌��ɂ���
            //pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

            ////Z�̔�r�ύX
            //pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
            ////Z�o�b�t�@�ɏ������܂Ȃ�
            //pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);



            //���[���h�}�g���b�N�X�̏�����
            D3DXMatrixIdentity(&g_TransferGate[nCntGate].mtxWorld);

            // ���f���̃T�C�Y��ύX
            D3DXMatrixScaling(&g_TransferGate[nCntGate].mtxWorld, g_TransferGate[nCntGate].SizeMag.x, g_TransferGate[nCntGate].SizeMag.y, g_TransferGate[nCntGate].SizeMag.z);

            ////�����𔽉f
            //D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Player.rot.y, g_Player.rot.x, g_Player.rot.z);

            //D3DXMatrixMultiply(&g_Player.mtxWorld, &g_Player.mtxWorld, &mtxRot);

            //�ʒu�𔽉f
            D3DXMatrixTranslation(&mtxTrans, g_TransferGate[nCntGate].pos.x, g_TransferGate[nCntGate].pos.y, g_TransferGate[nCntGate].pos.z);

            D3DXMatrixMultiply(&g_TransferGate[nCntGate].mtxWorld, &g_TransferGate[nCntGate].mtxWorld, &mtxTrans);

            //���[���h�}�g���b�N�X�̐ݒ�
            pDevice->SetTransform(D3DTS_WORLD, &g_TransferGate[nCntGate].mtxWorld);

            //���݂̃}�e���A�����擾
            pDevice->GetMaterial(&matDef);

            //�}�e���A���f�[�^�ւ̃|�C���^���擾
            pMat = (D3DXMATERIAL*)g_pBuffMatGate[nCntGate]->GetBufferPointer();

            for (int nCntMat = 0; nCntMat < (int)g_dwNumMatGate; nCntMat++)
            {
                //�}�e���A���̐ݒ�
                pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

                //�e�N�X�`���̐ݒ�
                pDevice->SetTexture(0, NULL);//����͐ݒ肵�Ȃ�

                //���f��(�p�[�c)�̕`��
                g_pMeshGate[nCntMat]->DrawSubset(nCntMat);

                //�ۑ����Ă��}�e���A����߂�
                pDevice->SetMaterial(&matDef);


                // �}�e���A���̐ݒ�
                pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

                // �f�B�t���[�Y�J���[��ύX�i��: �Ԃ��F�j
                pMat[nCntMat].MatD3D.Diffuse = D3DXCOLOR(g_TransferGate[nCntGate].GateColor.r * g_TransferGate[nCntGate].SizeMag.x, g_TransferGate[nCntGate].GateColor.g * g_TransferGate[nCntGate].SizeMag.x, g_TransferGate[nCntGate].GateColor.b * g_TransferGate[nCntGate].SizeMag.x, g_TransferGate[nCntGate].GateColor.a);
          
                ////���C�g��L���ɂ���
                //pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

                ////Z�̔�r�ύX
                //pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
                ////Z�o�b�t�@�ɏ������܂Ȃ�
                //pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
            }
        }
    }




}
//=============================
// �]�ږ�擾����
//=============================
TRANSFERGATE* GetTransferGate(void)
{
    return &g_TransferGate[0];
}
//=============================
// �]�ږ�ݒ菈��
//=============================
//-----------------------------�������W-----------------�ŏ�----------------�ő�---------�����̔ԍ�----�]�ڐ�̔ԍ�--�����]�ڂ��ǂ���--�s���{�^���œ]�ڂ��ǂ���
void SetTransferGate(D3DXVECTOR3 Pos, D3DXVECTOR3 GateMin, D3DXVECTOR3 GateMax, int nGateIndex, int nParentIndex, TRANSANGLE ParentTransAngle, D3DXCOLOR GateColor, bool bCompulsionTrans, bool bActionTrans)
{    
    //�f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice = GetDevice();//----------------���������ς�

    for (int nCntGate = 0; nCntGate < MAXGATE; nCntGate++)
    {
        if (g_TransferGate[nCntGate].bUse == false)
        {
            g_TransferGate[nCntGate].pos = Pos;
            g_TransferGate[nCntGate].GateMin = GateMin;
            g_TransferGate[nCntGate].GateMax = GateMax;
            g_TransferGate[nCntGate].GateColor = GateColor;
            g_TransferGate[nCntGate].bActiomTrans = bActionTrans;

            //�T�C�Y�ϓ�
             g_TransferGate[nCntGate].SizeMag.x = g_TransferGate[nCntGate].GateMax.x / 10.0f;
             g_TransferGate[nCntGate].SizeMag.y = g_TransferGate[nCntGate].GateMax.y / 20.0f;
             g_TransferGate[nCntGate].SizeMag.z = g_TransferGate[nCntGate].GateMax.z / 10.0f;



            g_TransferGate[nCntGate].nGateIndex = nGateIndex;//�����̔ԍ�
            g_TransferGate[nCntGate].nParentIndex = nParentIndex;//�]�ڐ�̔ԍ�
            g_TransferGate[nCntGate].ParentTransAngle = ParentTransAngle;//�]�ڐ�]�ڕ���
            g_TransferGate[nCntGate].bCompulsionTrans = bCompulsionTrans;//�����]�ڂ�

            g_TransferGate[nCntGate].bPossibility = true;//---------------------------------�Ƃ肠����
            g_TransferGate[nCntGate].bUse = true;


            //�t�@�C���̓ǂݍ���
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

