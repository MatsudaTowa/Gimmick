//==================================================
//
//�Q�[�����t�F�[�h�Ɋւ��鏈��[GameFade.cpp]
// Author seiya kagaya
//
//==================================================
#include "main.h"
#include "gamefade.h"
#include "player.h"
#include "player2.h"
//#include "sound.h"

//�O���[�o���ϐ��錾
GAMEFADE g_GameFade[MAXGAMEFADE];
D3DXCOLOR g_colorGameFade[MAXGAMEFADE];
//MODE g_ModeNext;
LPDIRECT3DTEXTURE9 g_pTextureGameFade = NULL;       //�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffGameFade = NULL; //���_�o�b�t�@�ւ̃|�C���^

//int g_GameFadeCnt[MAXGAMEFADE] = {};//�Q�[����ʂւ̈ڍs���������ɐF���c�����΍�

D3DXVECTOR3 g_EscapeMove[MAXGAMEFADE];


bool g_PlayerBlack = false;
bool g_Player2Black = false;
//=============================
//�Q�[�����t�F�[�h�̏���������
//=============================
void InitGameFade(void)
{
	LPDIRECT3DDEVICE9 pDevice;  //�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4*MAXGAMEFADE,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffGameFade,
		NULL);



	//D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\ki.jpg", &g_pTextureGameFade);	//�^�C�g���w�i

	VERTEX_2D* pVtx;  //���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffGameFade->Lock(0, 0, (void**)&pVtx, 0);

	for (int FadeCnt = 0; FadeCnt < MAXGAMEFADE; FadeCnt++)
	{
		g_EscapeMove[FadeCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//�ϐ��̏�����
		g_colorGameFade[FadeCnt].a = 0.0f;

		g_GameFade[FadeCnt] = GAMEFADE_NONE;

		//g_GameFadeCnt[FadeCnt] = 0;

		if (FadeCnt == 0)
		{//�J����1�̂���
			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE/2.0f, 0.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE/2.0f, SCREEN_HEIGHT, 0.0f);
		}
		else if(FadeCnt==1)
		{//�J����2�̂���
			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(SCREEN_WIDE/2.0f, 0.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(SCREEN_WIDE/2.0f, SCREEN_HEIGHT, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);
		}




		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
		pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
		pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
		pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);

		//�e�N�X�`�����W��ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);//����
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);//�E��
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);//����
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);//�E��


		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffGameFade->Unlock();
}
//=============================
//�Q�[�����t�F�[�h�̏I������
//=============================
void UninitGameFade(void)
{
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffGameFade != NULL)
	{
		g_pVtxBuffGameFade->Release();
		g_pVtxBuffGameFade = NULL;
	}
	//�e�N�X�`���̔j��
	if (g_pTextureGameFade != NULL)
	{
		g_pTextureGameFade->Release();
		g_pTextureGameFade = NULL;
	}
}
//=============================
//�Q�[�����t�F�[�h�̍X�V����
//=============================
void UpdateGameFade(void)
{
	VERTEX_2D* pVtx;  //���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffGameFade->Lock(0, 0, (void**)&pVtx, 0);

	Player* pPlayer;
	pPlayer = GetPlayer();

	Player_2P* pPlayer2;
	pPlayer2 = GetPlayer_2P();


	for (int FadeCnt = 0; FadeCnt < MAXGAMEFADE; FadeCnt++)
	{
		if (g_GameFade[FadeCnt] != GAMEFADE_NONE)
		{
			if (g_GameFade[FadeCnt] == GAMEFADE_IN)
			{//�Q�[�����t�F�[�h�C�����

				g_colorGameFade[FadeCnt].a -= 0.03f;	//�|���S���𓧖��ɂ��Ă���

				if (g_colorGameFade[FadeCnt].a <= 0.0f)
				{
					g_colorGameFade[FadeCnt].a = 0.0f;


					g_GameFade[FadeCnt] = GAMEFADE_NONE;	//�������Ă��Ȃ����
				}
			}
			else if (g_GameFade[FadeCnt] == GAMEFADE_OUT)
			{//�Q�[�����t�F�[�h�A�E�g���
				g_colorGameFade[FadeCnt].a += 0.07f;	//�|���S����s�����ɂ��Ă���

				if (g_colorGameFade[FadeCnt].a >= 1.0f)
				{
					g_colorGameFade[FadeCnt].a = 1.0f;

				//	g_GameFadeCnt[FadeCnt]++;//���[�h�ڍs�J�E���^�[

					if (FadeCnt==0)
					{
						pPlayer->pos = g_EscapeMove[FadeCnt];
						pPlayer->PlayerState = PLAYERSTATE_1P_NOMAL;

					}
					else if(FadeCnt == 1)
					{
						pPlayer2->pos = g_EscapeMove[FadeCnt];
						pPlayer2->PlayerState = PLAYERSTATE_2P_NOMAL;

					}


					g_GameFade[FadeCnt] = GAMEFADE_IN;	//�Q�[�����t�F�[�h�C�����
				}

			//	if (g_GameFadeCnt[FadeCnt] == 1)
			//	{//�F�������c���������
			//		//���[�h�ݒ�(���̉�ʂɈڍs)
			////		Setmode(g_ModeNext);
			//		g_GameFadeCnt[FadeCnt] = 0;
			//	}
			}

			if (FadeCnt == 0)
			{//�J����1�̂���
				//���_���W�̐ݒ�
				pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
				pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, 0.0f, 0.0f);
				pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
				pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, SCREEN_HEIGHT, 0.0f);

			}
			else if (FadeCnt == 1)
			{//�J����2�̂���
				//���_���W�̐ݒ�
				pVtx[0].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, 0.0f, 0.0f);
				pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
				pVtx[2].pos = D3DXVECTOR3(SCREEN_WIDE / 2.0f, SCREEN_HEIGHT, 0.0f);
				pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);



				//test
				//���_���W�̐ݒ�
			//	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			//	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDE, 0.0f, 0.0f);
			//	pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
			//	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDE, SCREEN_HEIGHT, 0.0f);


			}
		

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorGameFade[FadeCnt].a);
			pVtx[1].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorGameFade[FadeCnt].a);
			pVtx[2].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorGameFade[FadeCnt].a);
			pVtx[3].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, g_colorGameFade[FadeCnt].a);


			pVtx += 4;
		}
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffGameFade->Unlock();
}
//=============================
//�Q�[�����t�F�[�h�̕`�揈��
//=============================
void DrawGameFade(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffGameFade, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int FadeCnt = 0; FadeCnt < MAXGAMEFADE; FadeCnt++)
	{
//		if (g_GameFade[FadeCnt] != GAMEFADE_NONE)
//		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureGameFade);//---------���������ς�

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, FadeCnt * 4, 2);
//		}
	}
}
//=============================
//�Q�[�����t�F�[�h�̐ݒ菈��
//=============================
void SetGameFade(int PlayerNum, D3DXVECTOR3 ESCAPEMOVE)
{
//	for (int FadeCnt = 0; FadeCnt < MAXGAMEFADE; FadeCnt++)
	//{
		if (g_GameFade[PlayerNum] == GAMEFADE_NONE)
		{
		//	g_colorGameFade[PlayerNum].a = 0.0f;
		//	g_GameFadeCnt[PlayerNum] = 0;
			g_colorGameFade[PlayerNum] = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);			//�����|���S��(����)�ɂ��Ă���
			g_GameFade[PlayerNum] = GAMEFADE_OUT;											//�Q�[�����t�F�[�h�A�E�g��Ԃ�
			g_EscapeMove[PlayerNum]= ESCAPEMOVE;//�ړ���

		//	g_ModeNext = mode_next;										//���̉��(���[�h)��ݒ�

		}
//	}
}
//=============================
//�Q�[�����t�F�[�h�̎擾����
//=============================
GAMEFADE GetGameFade(void)
{
	return g_GameFade[0];
}
