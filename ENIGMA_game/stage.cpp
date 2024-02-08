//=========================================================
//
//�ǂ�\�����鏈��[wall.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "stage.h"

//�O���[�o���ϐ��錾
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStage = NULL; //���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureStage[STAGETEXNUM] = {};       //�e�N�X�`���ւ̃|�C���^



//D3DXVECTOR3 g_Stage[nWall].posStage;	//�ʒu
//D3DXVECTOR3 g_Stage[nWall].rotStage;	//����
//D3DXMATRIX g_Stage[nWall].mtxWorldStage;//���[���h�}�g���b�N�X


STAGE g_Stage[NUMSTAGE];//���쒆�@�\����



//=============================
//�ǂ̏���������
//=============================
void InitStage(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\blood.jpg", &g_pTextureStage[0]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\map001.jpg", &g_pTextureStage[1]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\ki.jpg", &g_pTextureStage[2]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\title000.png", &g_pTextureStage[3]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\safe000.jpg", &g_pTextureStage[4]);
	//�����Ƀe�N�X�`����ǉ�������w�b�_�ɂ����₷����!!!!//

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUMSTAGE, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffStage, NULL);

		VERTEX_3D* pVtx;//���_���ւ̃|�C���^

		//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
		g_pVtxBuffStage->Lock(0, 0, (void**)&pVtx, 0);

	for (int nWall = 0; nWall < NUMSTAGE; nWall++)
	{
		//g_Stage[nWall].g_Stage[nWall].posStage
		//g_Stage[nWall].rotStage
		g_Stage[nWall].bUse = false;

		g_Stage[nWall].posStage = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�ʒu
		g_Stage[nWall].rotStage = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//����
		g_Stage[nWall].MaxPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�ő�
		g_Stage[nWall].MinPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�ŏ�
		g_Stage[nWall].bCollision = false;
		g_Stage[nWall].TexType = TEXTYPE_00;
		//g_Stage[nWall].mtxWorldStage= D3DXMATRIX(0.0f,0.0f,0.0f);//���[���h�}�g���b�N�X



		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-STAGESIZE, 100.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(STAGESIZE, 100.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-STAGESIZE, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(STAGESIZE, 0.0f, 0.0f);

		//�@���x�N�g���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W��ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��

		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffStage->Unlock();

	//SetStage(D3DXVECTOR3(0.0f, 50.0f, 100.0f), 0.0f, 50.0f, 50.0f,  TEXTYPE_00);//�e�X�g�d�l
	//SetStage(D3DXVECTOR3(-100.0f, 50.0f, 100.0f), 0.0f, 50.0f, 50.0f, TEXTYPE_01);//�e�X�g�d�l
	//SetStage(D3DXVECTOR3(-200.0f, 50.0f, 100.0f), 0.0f, 50.0f, 50.0f, TEXTYPE_03);//�e�X�g�d�l
	SetStage(D3DXVECTOR3(-900.0f, 0.0f, 110.0f), 0.0f, 600.0f, 300.0f, TEXTYPE_00);//�e�X�g�d�l
	SetStage(D3DXVECTOR3(-400.0f, 0.0f, -30.0f), 1.57f, 200.0f, 300.0f, TEXTYPE_01);//�e�X�g�d�l
	SetStage(D3DXVECTOR3(-150.0f, 0.0f, -230.0f), 0.0f, 250.0f, 300.0f, TEXTYPE_00);//�e�X�g�d�l
	SetStage(D3DXVECTOR3(30.0f, 0.0f, -800.0f), 1.57f, 700.0f, 300.0f, TEXTYPE_00);//�e�X�g�d�l
	SetStage(D3DXVECTOR3(-1200.0f, 0.0f, -600.0f), -1.57f, 700.0f, 300.0f, TEXTYPE_00);//�e�X�g�d�l
	SetStage(D3DXVECTOR3(-600.0f, 0.0f, -1280.0f), 3.14f, 700.0f, 300.0f, TEXTYPE_00);//�e�X�g�d�l


}
//=============================
//�ǂ̏I������
//=============================
void UninitStage(void)
{
	for (int nWall = 0; nWall < STAGETEXNUM; nWall++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureStage[nWall] != NULL)
		{
			g_pTextureStage[nWall]->Release();
			g_pTextureStage[nWall] = NULL;
		}
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffStage != NULL)
	{
		g_pVtxBuffStage->Release();
		g_pVtxBuffStage = NULL;
	}
}
//=============================
//�ǂ̍X�V����
//=============================
void UpdateStage(void)
{
	//�����Ȃ�
}
//=============================
//�ǂ̕`�揈��
//=============================
void DrawStage(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X

	for (int nWall = 0; nWall < NUMSTAGE; nWall++)
	{
		if (g_Stage[nWall].bUse == true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_Stage[nWall].mtxWorldStage);

			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Stage[nWall].rotStage.y, g_Stage[nWall].rotStage.x, g_Stage[nWall].rotStage.z);

			D3DXMatrixMultiply(&g_Stage[nWall].mtxWorldStage, &g_Stage[nWall].mtxWorldStage, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_Stage[nWall].posStage.x, g_Stage[nWall].posStage.y, g_Stage[nWall].posStage.z);

			D3DXMatrixMultiply(&g_Stage[nWall].mtxWorldStage, &g_Stage[nWall].mtxWorldStage, &mtxTrans);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_Stage[nWall].mtxWorldStage);

			//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffStage, 0, sizeof(VERTEX_3D));

			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);


			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureStage[g_Stage[nWall].TexType]);

			//�ǂ̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
				nWall * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
				2);//�`�悷��v���~�e�B�u��
		}
	}
}
//=============================
//�ǂ̐ݒ菈��
//=============================
void SetStage(D3DXVECTOR3 Pos, float angle, float bes, float ver, TEXTYPE TexType)
{
	VERTEX_3D* pVtx;//���_���ւ̃|�C���^

//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffStage->Lock(0, 0, (void**)&pVtx, 0);

	for (int nWall = 0; nWall < NUMSTAGE; nWall++)
	{
		if (g_Stage[nWall].bUse == false)
		{
			g_Stage[nWall].posStage = Pos;//�ʒu
			g_Stage[nWall].rotStage = D3DXVECTOR3(0.0f, angle, 0.0f);	//����
			//g_Stage[nWall].StageType = StageType;
			g_Stage[nWall].TexType = TexType;
			g_Stage[nWall].bUse = true;
			g_Stage[nWall].bCollision = true;

			/*switch (g_Stage[nWall].StageType)
			{
			case STAGETYPE_WALL:*/
				//���_���W�̐ݒ�
				pVtx[0].pos = D3DXVECTOR3(-bes, ver, 0.0f);
				pVtx[1].pos = D3DXVECTOR3(bes, ver, 0.0f);
				pVtx[2].pos = D3DXVECTOR3(-bes, -ver, 0.0f);
				pVtx[3].pos = D3DXVECTOR3(bes, -ver, 0.0f);

				g_Stage[nWall].MinPos = D3DXVECTOR3(-bes, -ver, -1.0f);
				g_Stage[nWall].MaxPos = D3DXVECTOR3(bes, ver, 1.0f);

			//	break;
			//case STAGETYPE_FLOOR:
			//	//���_���W�̐ݒ�
			//	pVtx[0].pos = D3DXVECTOR3(-bes, 0.0f, ver);
			//	pVtx[1].pos = D3DXVECTOR3(bes, 0.0f, ver);
			//	pVtx[2].pos = D3DXVECTOR3(-bes, 0.0f, -ver);
			//	pVtx[3].pos = D3DXVECTOR3(bes, 0.0f, -ver);

			//	g_Stage[nWall].MinPos = D3DXVECTOR3(-bes, -1.0f, -ver);
			//	g_Stage[nWall].MaxPos = D3DXVECTOR3(bes, 1.0f, ver);

			//	break;
			//default:
			//	break;
			//}
			break;
		}
		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffStage->Unlock();


}
//=============================
//�ǂ̏��擾����
//=============================
STAGE* GetStage(void)
{
	return &g_Stage[0];
}