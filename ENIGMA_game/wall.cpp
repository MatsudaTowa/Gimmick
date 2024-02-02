//=========================================================
//
//�ǂ�\�����鏈��[wall.cpp]
// Author seiya kagaya
//
//=========================================================
#include "main.h"
#include "wall.h"

//�O���[�o���ϐ��錾
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffWall = NULL; //���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureWall[TEXNUM] = {};       //�e�N�X�`���ւ̃|�C���^



//D3DXVECTOR3 g_Wall[nWall].posWall;	//�ʒu
//D3DXVECTOR3 g_Wall[nWall].rotWall;	//����
//D3DXMATRIX g_Wall[nWall].mtxWorldWall;//���[���h�}�g���b�N�X


WALL g_Wall[NUMWALL];//���쒆�@�\����



//=============================
//�ǂ̏���������
//=============================
void InitWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Block003.jpg", &g_pTextureWall[0]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Block002.jpg", &g_pTextureWall[1]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Block001.jpg", &g_pTextureWall[2]);
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Block004.jpg", &g_pTextureWall[3]);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * NUMWALL, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &g_pVtxBuffWall, NULL);

		VERTEX_3D* pVtx;//���_���ւ̃|�C���^

		//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
		g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (int nWall = 0; nWall < NUMWALL; nWall++)
	{
		//g_Wall[nWall].g_Wall[nWall].posWall
		//g_Wall[nWall].rotWall
		g_Wall[nWall].bUse = false;

		g_Wall[nWall].posWall = D3DXVECTOR3(0.0f, 0.0f, 50.0f);//�ʒu
		g_Wall[nWall].rotWall = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//����

		//g_Wall[nWall].mtxWorldWall= D3DXMATRIX(0.0f,0.0f,0.0f);//���[���h�}�g���b�N�X



		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-WALLSIZE, 100.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(WALLSIZE, 100.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-WALLSIZE, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(WALLSIZE, 0.0f, 0.0f);

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
	g_pVtxBuffWall->Unlock();

//	SetWall(D3DXVECTOR3(0.0f, 0.0f, WALLSIZE), 0.0f, 0, 0, WALLTYPE_test0);//�e�X�g�d�l
//	SetWall(D3DXVECTOR3(0.0f, 0.0f, -WALLSIZE), 3.14f, 0, 0, WALLTYPE_test0);//�e�X�g�d�l
//	SetWall(D3DXVECTOR3(WALLSIZE, 0.0f, 0.0f), 1.57f, 0, 0, WALLTYPE_test1);
//	SetWall(D3DXVECTOR3(-WALLSIZE, 0.0f, 0.0f),-1.57f, 0, 0, WALLTYPE_test3);

}
//=============================
//�ǂ̏I������
//=============================
void UninitWall(void)
{
	for (int nWall = 0; nWall < TEXNUM; nWall++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureWall[nWall] != NULL)
		{
			g_pTextureWall[nWall]->Release();
			g_pTextureWall[nWall] = NULL;
		}
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffWall != NULL)
	{
		g_pVtxBuffWall->Release();
		g_pVtxBuffWall = NULL;
	}
}
//=============================
//�ǂ̍X�V����
//=============================
void UpdateWall(void)
{
	//�����Ȃ�
}
//=============================
//�ǂ̕`�揈��
//=============================
void DrawWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X

	for (int nWall = 0; nWall < NUMWALL; nWall++)
	{
		if (g_Wall[nWall].bUse == true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_Wall[nWall].mtxWorldWall);

			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Wall[nWall].rotWall.y, g_Wall[nWall].rotWall.x, g_Wall[nWall].rotWall.z);

			D3DXMatrixMultiply(&g_Wall[nWall].mtxWorldWall, &g_Wall[nWall].mtxWorldWall, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_Wall[nWall].posWall.x, g_Wall[nWall].posWall.y, g_Wall[nWall].posWall.z);

			D3DXMatrixMultiply(&g_Wall[nWall].mtxWorldWall, &g_Wall[nWall].mtxWorldWall, &mtxTrans);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_Wall[nWall].mtxWorldWall);

			//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffWall, 0, sizeof(VERTEX_3D));

			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);


			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureWall[g_Wall[nWall].WallType]);

			//�ǂ̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
				0,//�`�悷��ŏ��̒��_�C���f�b�N�X
				2);//�`�悷��v���~�e�B�u��
		}
	}
}
//=============================
//�ǂ̐ݒ菈��
//=============================
void SetWall(D3DXVECTOR3 Pos, float angle, int Width, int height, WALLTYPE TestType)
{
	VERTEX_3D* pVtx;//���_���ւ̃|�C���^

//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (int nWall = 0; nWall < NUMWALL; nWall++)
	{
		if (g_Wall[nWall].bUse == false)
		{
			g_Wall[nWall].posWall = Pos;//�ʒu
			g_Wall[nWall].rotWall = D3DXVECTOR3(0.0f, angle, 0.0f);	//����

			//���A������ق�

			g_Wall[nWall].WallType = TestType;
			g_Wall[nWall].bUse = true;
			break;
		}
		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffWall->Unlock();


}
//=============================
//�ǂ̏��擾����
//=============================
WALL* GetWall(void)
{
	return &g_Wall[0];
}