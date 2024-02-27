//=========================================================
//
//���j���[��ʂ̏����֌W[menu.cpp]
// Author kaito hondo
//
//=========================================================
#include "main.h"
#include "Tutorial.h"
#include "input.h"
#include "game.h"
#include "menu.h"
#include "fade.h"
#include "Film.h"
#include "MenuFrame.h"

#define NUM_MENUUI (4)//���j���[�̕\���|���S���̐�
#define NUM_SELECTUI	(3)//�I�����̐�
#define MAX_WIDE				(216)//����
#define MAX_HEIGH				(30)//�c��

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureMenu[NUM_MENUUI] = {};//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffMenu = NULL;//���_�o�b�t�@�ւ̃|���S��
MENU g_aMenu[NUM_MENUUI];	//���j���[�\���̂̏��

int g_Menu = 0;//���j���[���

//=============================
//���j���[����������
//=============================
void InitMenu(void)
{
	//InitMenuFrame();

	//// �w�i�̏���������
	//InitFILM();

	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	int nCntMenu = 0;

	//���j���[���̏�����
	g_Menu = START_MENU_GAME;

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Menuframe001.png", &g_pTextureMenu[0]);//--------���������ς�//�Ƃ肠����
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Menu000.png", &g_pTextureMenu[1]);//--------���������ς�
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Menu001.png", &g_pTextureMenu[2]);//--------���������ς�
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Menu002.png", &g_pTextureMenu[3]);//--------���������ς�

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * NUM_MENUUI, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &g_pVtxBuffMenu, NULL);

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffMenu->Lock(0, 0, (void**)&pVtx, 0);

	int nCountMenu = 0;

	for (nCountMenu = 0; nCountMenu < NUM_MENUUI; nCountMenu++)
	{
		g_aMenu[nCountMenu].pos = D3DXVECTOR3(SCREEN_WIDE / 2, SCREEN_HEIGHT / 2, 0.0f);

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - MAX_WIDE, g_aMenu[nCountMenu].pos.y - MAX_HEIGH, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + MAX_WIDE, g_aMenu[nCountMenu].pos.y - MAX_HEIGH, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - MAX_WIDE, g_aMenu[nCountMenu].pos.y + MAX_HEIGH, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + MAX_WIDE, g_aMenu[nCountMenu].pos.y + MAX_HEIGH, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 55, 55, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 55, 55, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 55, 55, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 55, 55, 255);

		//�e�L�X�`���̍��W�ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffMenu->Unlock();
}
//=============================
//���j���[�I������
//=============================
void UninitMenu(void)
{
	//UninitMenuFrame();

	//// �w�i�̏I������
	//UninitFILM();

	int nCountMenu = 0;

	for (nCountMenu = 0; nCountMenu < NUM_MENUUI; nCountMenu++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureMenu[nCountMenu] != NULL)
		{
			g_pTextureMenu[nCountMenu]->Release();
			g_pTextureMenu[nCountMenu] = NULL;
		}
		//���_�o�b�t�@�̔j��
		if (g_pVtxBuffMenu != NULL)
		{
			g_pVtxBuffMenu->Release();
			g_pVtxBuffMenu = NULL;
		}
	}
}
//=============================
//���j���[�X�V����
//=============================
void UpdateMenu(void)
{
	//UpdateMenuFrame();

	//UpdateFILM();

	XINPUT_STATE joykeystate;

	VERTEX_2D* pVtx;//���_���̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffMenu->Lock(0, 0, (void**)&pVtx, 0);

	int nCountMenu = 0;

	DWORD dwResult = XInputGetState(0, &joykeystate);

	if (dwResult == ERROR_SUCCESS)
	{
		if (GetkeyboardTrigger(DIK_W) == true || GetJoypadTrigger(JOYKEY_UP, 0) == true || GetJoypadTrigger(JOYKEY_UP, 1) == true || joykeystate.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || GetkeyboardTrigger(DIK_UP))
		{//W�������ꂽ(��)
			if (g_Menu > START_MENU_GAME)
			{//�Q�[���X�^�[�g�ɓ��B����܂ł̓}�C�i�X����
				g_Menu--;
			}
			else
			{//�Q�[���X�^�[�g��艺�ɍs�����Ƃ������ԉ�(�^�C�g��)�ɖ߂�
				g_Menu = START_MENU_TITLE;
			}

		}
		else if (GetkeyboardTrigger(DIK_S) == true || GetJoypadTrigger(JOYKEY_DOWN, 0) == true || GetJoypadTrigger(JOYKEY_DOWN, 1) == true || joykeystate.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || GetkeyboardTrigger(DIK_DOWN))
		{//S�������ꂽ(��)
			if (g_Menu < START_MENU_TITLE)
			{//�^�C�g���ɓ��B����܂Ńv���X����
				g_Menu++;
			}
			else
			{//�^�C�g������ɍs�����Ƃ������ԏ�(�Q�[���X�^�[�g)�ɖ߂�
				g_Menu = START_MENU_GAME;
			}
		}
	}
	else
	{//�R���g���[���[���Ȃ������Ƃ�
		if (GetkeyboardTrigger(DIK_W) == true || GetkeyboardTrigger(DIK_UP))
		{//W�������ꂽ(��)
			if (g_Menu > START_MENU_GAME)
			{
				g_Menu--;
			}
			else
			{//�Q�[���X�^�[�g��艺�ɍs�����Ƃ������ԉ�(�^�C�g��)�ɖ߂�
				g_Menu = START_MENU_TITLE;
			}
		}
		else if (GetkeyboardTrigger(DIK_S) == true || GetkeyboardTrigger(DIK_DOWN))
		{//S�������ꂽ(��)
			if (g_Menu < START_MENU_TITLE)
			{
				g_Menu++;
			}
			else
			{//�^�C�g������ɍs�����Ƃ������ԏ�(�Q�[���X�^�[�g)�ɖ߂�
				g_Menu = START_MENU_GAME;
			}
		}
	}

	for (nCountMenu = 0; nCountMenu < NUM_MENUUI; nCountMenu++)
	{

		//���_�J���[�̐ݒ�--�S��
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 240);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 240);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 240);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 240);

		if (nCountMenu == 0)
		{
			g_aMenu[nCountMenu].pos = D3DXVECTOR3(SCREEN_WIDE / 2, SCREEN_HEIGHT / 2, 0.0f);

			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - (SCREEN_WIDE / 2), g_aMenu[nCountMenu].pos.y - (SCREEN_HEIGHT / 2), 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + (SCREEN_WIDE / 2), g_aMenu[nCountMenu].pos.y - (SCREEN_HEIGHT / 2), 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - (SCREEN_WIDE / 2), g_aMenu[nCountMenu].pos.y + (SCREEN_HEIGHT / 2), 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + (SCREEN_WIDE / 2), g_aMenu[nCountMenu].pos.y + (SCREEN_HEIGHT / 2), 0.0f);
		}
		else if (nCountMenu == START_MENU_GAME)
		{
			g_aMenu[nCountMenu].pos = D3DXVECTOR3(SCREEN_WIDE / 4, SCREEN_HEIGHT / 3.0f, 0.0f);// �����ŕ����̈ʒu�ς���

			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y - (MAX_HEIGH * 1), 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y - (MAX_HEIGH * 1), 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y + (MAX_HEIGH * 1), 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y + (MAX_HEIGH * 1), 0.0f);
		}
		else if (nCountMenu == START_MENU_TUTORIAL)
		{
			g_aMenu[nCountMenu].pos = D3DXVECTOR3(SCREEN_WIDE / 4, SCREEN_HEIGHT / 1.75f, 0.0f);

			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y - (MAX_HEIGH * 1), 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y - (MAX_HEIGH * 1), 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y + (MAX_HEIGH * 1), 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y + (MAX_HEIGH * 1), 0.0f);
		}
		else if (nCountMenu == START_MENU_TITLE)
		{
			g_aMenu[nCountMenu].pos = D3DXVECTOR3(SCREEN_WIDE / 4, SCREEN_HEIGHT / 1.23f, 0.0f);

			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y - (MAX_HEIGH * 1), 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y - (MAX_HEIGH * 1), 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x - (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y + (MAX_HEIGH * 1), 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aMenu[nCountMenu].pos.x + (MAX_WIDE * 1), g_aMenu[nCountMenu].pos.y + (MAX_HEIGH * 1), 0.0f);
		}

		if (nCountMenu == g_Menu)
		{//�Ώۂ̂Ƃ�
			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 55, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 55, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 55, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 55, 255, 255);
		}

		//����L�[(ENTER)�������ꂽ���ǂ���
		if (GetkeyboardTrigger(DIK_SPACE) || GetJoypadTrigger(JOYKEY_A, 0) || GetJoypadTrigger(JOYKEY_A, 1) || GetkeyboardTrigger(DIK_RETURN))
		{
			if (g_Menu == START_MENU_GAME)
			{
				SetFade(MODE_GAME);
			}
			else if (g_Menu == START_MENU_TUTORIAL)
			{
				SetFade(MODE_TUTORIAL);
			}
			else if (g_Menu == START_MENU_TITLE)
			{
				SetFade(MODE_TITLE);
			}
		}
		pVtx += 4;
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffMenu->Unlock();
}
//=============================
//���j���[�`�揈��
//=============================
void DrawMenu(void)
{

	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();//----------------���������ς�

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffMenu, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);//-------���������ς�

	int nCountMenu = 0;

	for (nCountMenu = 0; nCountMenu < NUM_MENUUI; nCountMenu++)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureMenu[nCountMenu]);//---------���������ς�

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��//----------���������ς�
			nCountMenu * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
			2);//�`�悷��v���~�e�B�u��
	}

	//DrawMenuFrame();

	//// �w�i�̕`�揈��
	//DrawFILM();
}

int GetMenu(void)
{
	return g_Menu;
}
