//=============================================
//
//�G�̕�������UI[AngleUI.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "angleUI.h"
#include "enemy.h"
#include "player.h"
#include "player2.h"
#include "camera.h"

//=============================================
//�ǂ̃e�N�X�`���̎��
//=============================================
static const char* AngleUI_TEX_NAME =
{
	"data\\TEXTURE\\AngleCursor.png",
};

//=========================================================
//�O���[�o���ϐ�
//=========================================================
LPDIRECT3DTEXTURE9 g_pTextureEyeAngleUI = {};//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffEyeAngleUI = NULL;//���_�o�b�t�@�ւ̃|���S��
AngleUI g_AngleUI[NUM_ANGLEUI];	//�|�[�Y�\���̂̏��

//=============================================
//�g���b�v�̏�����
//=============================================
void InitAngleUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//	int nCntPause = 0;

		//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		AngleUI_TEX_NAME,
		&g_pTextureEyeAngleUI
	);


	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_ANGLEUI, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffEyeAngleUI, NULL);

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffEyeAngleUI->Lock(0, 0, (void**)&pVtx, 0);
	for (int nCntTrap = 0; nCntTrap < NUM_ANGLEUI; nCntTrap++)
	{
		g_AngleUI[nCntTrap].bUse = true;
		//�Ίp���̒������Z�o
		g_AngleUI[nCntTrap].fLength = sqrtf(SCREEN_WIDE / 4.0f * SCREEN_WIDE / 4.0f + SCREEN_HEIGHT / 3.0f * SCREEN_HEIGHT / 3.0f) * 0.5f;

		//�Ίp���̊p�x���Z�o
		g_AngleUI[nCntTrap].fAngle = atan2f(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f);


		if (nCntTrap == 0)
		{
			g_AngleUI[nCntTrap].fAlpha = 0.5f;
			g_AngleUI[nCntTrap].pos = D3DXVECTOR3(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f, 0.0f);
			g_AngleUI[nCntTrap].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[0].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x - SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y - SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x + SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y - SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x - SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y + SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x + SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y + SCREEN_HEIGHT / 3.5f, 0.0f);
		}
		else if (nCntTrap == 1)
		{
			g_AngleUI[nCntTrap].fAlpha = 0.5f;
			g_AngleUI[nCntTrap].pos = D3DXVECTOR3(SCREEN_WIDE / 1.35f, SCREEN_HEIGHT / 3.0f, 0.0f);
			pVtx[0].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x - SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y - SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x + SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y - SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x - SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y + SCREEN_HEIGHT / 3.5f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_AngleUI[nCntTrap].pos.x + SCREEN_WIDE / 4.0f, g_AngleUI[nCntTrap].pos.y + SCREEN_HEIGHT / 3.5f, 0.0f);
		}
		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nCntTrap].fAlpha);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nCntTrap].fAlpha);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nCntTrap].fAlpha);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nCntTrap].fAlpha);

		//�e�L�X�`���̍��W�ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}

	g_pVtxBuffEyeAngleUI->Unlock();
}

//=============================================
//�g���b�v�̏I��
//=============================================
void UninitAngleUI(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureEyeAngleUI != NULL)
	{
		g_pTextureEyeAngleUI->Release();
		g_pTextureEyeAngleUI = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffEyeAngleUI != NULL)
	{
		g_pVtxBuffEyeAngleUI->Release();
		g_pVtxBuffEyeAngleUI = NULL;
	}

}

//=============================================
//�g���b�v�̍X�V
//=============================================
void UpdateAngleUI(void)
{
	ENEMYMODEL* pEnemy = GetEnemy();
	Player* pPlayer = GetPlayer();
	Player_2P* pPlayer_2P = GetPlayer_2P();
	Camera* pCamera = GetCamera();

	VERTEX_2D* pVtx;//���_���̃|�C���^

//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffEyeAngleUI->Lock(0, 0, (void**)&pVtx, 0);
	for (int nCntTrap = 0; nCntTrap < NUM_ANGLEUI; nCntTrap++)
	{
		float fAngleEnemy = pPlayer->rot.y - pCamera[0].rot.y - (1.0f * D3DX_PI);
		
		//�Ίp���̒������Z�o
		g_AngleUI[nCntTrap].fLength = sqrtf(SCREEN_WIDE / 4.0f * SCREEN_WIDE / 4.0f + SCREEN_HEIGHT / 3.0f * SCREEN_HEIGHT / 3.0f) * 0.5f;

		//�Ίp���̊p�x���Z�o
		g_AngleUI[nCntTrap].fAngle = atan2f(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f);

		g_AngleUI[nCntTrap].rot.z = fAngleEnemy;

		if (g_AngleUI[nCntTrap].rot.z < -D3DX_PI)
		{
			g_AngleUI[nCntTrap].rot.z = D3DX_PI;
		}
		else if (g_AngleUI[nCntTrap].rot.z > D3DX_PI)
		{
			g_AngleUI[nCntTrap].rot.z = -D3DX_PI;
		}
		if (nCntTrap == 0)
		{
			g_AngleUI[nCntTrap].fAlpha = 0.5f;
			g_AngleUI[nCntTrap].pos = D3DXVECTOR3(SCREEN_WIDE / 4.0f, SCREEN_HEIGHT / 3.0f, 0.0f);
			pVtx[0].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(-g_AngleUI[nCntTrap].rot.z - (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[0].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(-g_AngleUI[nCntTrap].rot.z - (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[1].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(-g_AngleUI[nCntTrap].rot.z + (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[1].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(-g_AngleUI[nCntTrap].rot.z + (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[2].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(-g_AngleUI[nCntTrap].rot.z - g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[2].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(-g_AngleUI[nCntTrap].rot.z - g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[3].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(-g_AngleUI[nCntTrap].rot.z + g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[3].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(-g_AngleUI[nCntTrap].rot.z + g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
		}
		else if (nCntTrap == 1)
		{
			g_AngleUI[nCntTrap].fAlpha = 0.5f;
			g_AngleUI[nCntTrap].pos = D3DXVECTOR3(SCREEN_WIDE / 1.35f, SCREEN_HEIGHT / 3.0f, 0.0f);
			pVtx[0].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(g_AngleUI[nCntTrap].rot.z - (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[0].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(g_AngleUI[nCntTrap].rot.z - (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[1].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(g_AngleUI[nCntTrap].rot.z + (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[1].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(g_AngleUI[nCntTrap].rot.z + (D3DX_PI - g_AngleUI[nCntTrap].fAngle)) * g_AngleUI[nCntTrap].fLength;
			pVtx[2].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(g_AngleUI[nCntTrap].rot.z - g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[2].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(g_AngleUI[nCntTrap].rot.z - g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[3].pos.x = g_AngleUI[nCntTrap].pos.x + sinf(g_AngleUI[nCntTrap].rot.z + g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
			pVtx[3].pos.y = g_AngleUI[nCntTrap].pos.y + cosf(g_AngleUI[nCntTrap].rot.z + g_AngleUI[nCntTrap].fAngle) * g_AngleUI[nCntTrap].fLength;
		}

		pVtx += 4;
	}
	g_pVtxBuffEyeAngleUI->Unlock();

}

//=============================================
//�g���b�v�̕`��
//=============================================
void DrawAngleUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

//�f�o�C�X�̎擾
	pDevice = GetDevice();//----------------���������ς�

	for (int nCntTrap = 0; nCntTrap < NUM_ANGLEUI; nCntTrap++)
	{
		if (g_AngleUI[nCntTrap].bUse == true)
		{
			//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffEyeAngleUI, 0, sizeof(VERTEX_2D));

			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_2D);//-------���������ς�

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureEyeAngleUI);//---------���������ς�

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��//----------���������ς�
				4 * nCntTrap,//�`�悷��ŏ��̒��_�C���f�b�N�X
				2);//�`�悷��v���~�e�B�u��

			//�e�N�X�`����߂�
			pDevice->SetTexture(0, NULL);
		}
	}
}

//=============================================
//�g���b�v�̐ݒ�
//=============================================
void SetAngleUI(int nPlayer)
{
	if (g_AngleUI[nPlayer].bUse == false)
	{
		g_AngleUI[nPlayer].fAlpha = 0.7f;
		g_AngleUI[nPlayer].bUse = true;
		int nVtx = nPlayer * 4;
		VERTEX_2D* pVtx;//���_���̃|�C���^

		//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
		g_pVtxBuffEyeAngleUI->Lock(0, 0, (void**)&pVtx, 0);
		//���_�J���[�̐ݒ�
		pVtx[nVtx].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nPlayer].fAlpha);
		pVtx[nVtx + 1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nPlayer].fAlpha);
		pVtx[nVtx + 2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nPlayer].fAlpha);
		pVtx[nVtx + 3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, g_AngleUI[nPlayer].fAlpha);
		g_pVtxBuffEyeAngleUI->Unlock();

	}
}
