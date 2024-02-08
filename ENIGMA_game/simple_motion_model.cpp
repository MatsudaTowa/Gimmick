//=========================================================
//
//�ȈՃ��[�V�������f���\�����鏈��[simple_motion_model.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "simple_motion_model.h"

//�O���[�o���ϐ��錾


//���f���\����
typedef struct
{
	const char* pFilePass;	// MODEL�t�@�C���p�X
	SIMPLEMOTIONMODEL MyNum;//�����ԍ��iindex�j
	SIMPLEMOTIONMODEL ParentNum;//�e�ԍ�(index).�����������Ɣԍ���
	SIMPLEMODEL SinpleModel;//pos�Ȃ�
} SIMPLEMODELINFO;



//-------------------------------------------
//�@�@"�t�@�C���p�X","����(index)"."�e(index)"
//-------------------------------------------
SIMPLEMODELINFO g_ModelInfo[SIMPLEMOTIONMODEL_MAX] =
{							//����-----------------�e
	{"data\\MODEL\\key1.x",SIMPLEMOTIONMODEL_Test1,SIMPLEMOTIONMODEL_Test1},//�e�X�g�̂��ߏ��������K�{
	{"data\\MODEL\\key2.x",SIMPLEMOTIONMODEL_Test2,SIMPLEMOTIONMODEL_Test1},
};





///-------------------------------------------------------------------------���f��
LPD3DXMESH g_pMeshSimpleModel[SIMPLEMOTIONMODEL_MAX] = {};//���b�V��(���_���)�ւ̃|�C���^

LPD3DXBUFFER g_pBuffMatSimpleModel[SIMPLEMOTIONMODEL_MAX] = {};//�}�e���A���ւ̃|�C���^

DWORD dwNumMatSimpleModel[SIMPLEMOTIONMODEL_MAX] = {};//�}�e���A���̐�


//=============================
//�ȈՃ��[�V�������f������������
//=============================
void InitSimpleModel(void)
{
	for (int SimpleModel = 0; SimpleModel < SIMPLEMOTIONMODEL_MAX; SimpleModel++)//�e�p�[�c�{��
	{
		g_ModelInfo[SimpleModel].SinpleModel.bUse = false;
		g_ModelInfo[SimpleModel].SinpleModel.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_ModelInfo[SimpleModel].SinpleModel.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}





	//�������珉���l�Z�b�g
	SetSimpleModel(SIMPLEMOTIONMODEL_Test1, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetSimpleModel(SIMPLEMOTIONMODEL_Test2, D3DXVECTOR3(30.0f, 40.0f, 0.0f), D3DXVECTOR3(0.0f, 1.57f, 0.0f));


}
//=============================
//�ȈՃ��[�V�������f���I������
//=============================
void UninitSimpleModel(void)
{
	for (int SimpleModel = 0; SimpleModel < SIMPLEMOTIONMODEL_MAX; SimpleModel++)
	{
		//���b�V���̔j��
		if (g_pMeshSimpleModel[SimpleModel] != NULL)
		{
			g_pMeshSimpleModel[SimpleModel]->Release();
			g_pMeshSimpleModel[SimpleModel] = NULL;
		}
		//�}�e���A���̔j��
		if (g_pBuffMatSimpleModel[SimpleModel] != NULL)
		{
			g_pBuffMatSimpleModel[SimpleModel]->Release();
			g_pBuffMatSimpleModel[SimpleModel] = NULL;
		}
	}
}
//=============================
//�ȈՃ��[�V�������f���X�V����
//=============================
void UpdateSimpleModel(void)
{
	//*********�����ł��̂ɍ��킹�ď�����ǉ�


	//for (int SimpleModel = 0; SimpleModel < SIMPLEMOTIONMODEL_MAX; SimpleModel++)
	//{

	//}
}
//=============================
//�ȈՃ��[�V�������f���`�揈��
//=============================
void DrawSimpleModel(void)
{

	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans, mtxParent;//�v�Z�p�}�g���b�N�X

	D3DMATERIAL9 matDef;//���݂̃}�e���A���ۑ��p(�ꎞ�ޔ�)

	D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^
	
	
	for (int SimpleModel = 0; SimpleModel < SIMPLEMOTIONMODEL_MAX; SimpleModel++)
	{
		//���f���̈ʒu
	//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_ModelInfo[SimpleModel].SinpleModel.mtxWorld);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_ModelInfo[SimpleModel].SinpleModel.rot.y, g_ModelInfo[SimpleModel].SinpleModel.rot.x, g_ModelInfo[SimpleModel].SinpleModel.rot.z);

		D3DXMatrixMultiply(&g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_ModelInfo[SimpleModel].SinpleModel.pos.x, g_ModelInfo[SimpleModel].SinpleModel.pos.y, g_ModelInfo[SimpleModel].SinpleModel.pos.z);

		D3DXMatrixMultiply(&g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &mtxTrans);

		//�e�q�֌W
		if (g_ModelInfo[SimpleModel].ParentNum == g_ModelInfo[SimpleModel].MyNum)
		{//�������e
			//�v���C���[�Ƃ�����
		//	D3DXMatrixMultiply(&g_Model.ModelParts[nCnt].mtxWorld, &g_Model.ModelParts[nCnt].mtxWorld, &g_Player.mtxWorld);
		}
		else
		{
			//�����̐e�̃}�g���b�N�X�����Ă�
			D3DXMatrixMultiply(&g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &g_ModelInfo[SimpleModel].SinpleModel.mtxWorld, &g_ModelInfo[g_ModelInfo[SimpleModel].ParentNum].SinpleModel.mtxWorld);

		}

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_ModelInfo[SimpleModel].SinpleModel.mtxWorld);

		//���݂̃}�e���A�����擾
		pDevice->GetMaterial(&matDef);

		//�}�e���A���f�[�^�ւ̃|�C���^���擾
		pMat = (D3DXMATERIAL*)g_pBuffMatSimpleModel[SimpleModel]->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)dwNumMatSimpleModel[SimpleModel]; nCntMat++)
		{
			//�}�e���A���̐ݒ�
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, NULL);//����͐ݒ肵�Ȃ�

			//���f��(�p�[�c)�̕`��
			g_pMeshSimpleModel[SimpleModel]->DrawSubset(nCntMat);

			//�ۑ����Ă��}�e���A����߂�
			pDevice->SetMaterial(&matDef);
		}
	}
}
//=============================
//�ȈՃ��[�V�������f���ݒ菈��
//=============================
void SetSimpleModel(SIMPLEMOTIONMODEL SetUpName_Index,D3DXVECTOR3 pos,D3DXVECTOR3 rot)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//***�e���g�͎����̈ʒu�B�q�̓I�t�Z�b�g�l���L��
	
	if (g_ModelInfo[SetUpName_Index].SinpleModel.bUse == false)
	{
		g_ModelInfo[SetUpName_Index].SinpleModel.bUse = true;
		g_ModelInfo[SetUpName_Index].SinpleModel.pos = pos;
		g_ModelInfo[SetUpName_Index].SinpleModel.rot = rot;


		//X�t�@�C���̓ǂݍ���
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
		//�G���[
	}
}