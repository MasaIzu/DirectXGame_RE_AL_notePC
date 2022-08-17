#pragma once
#include "WorldTransform.h"
#include "Model.h"
#include <assert.h>
#include "Input.h"
#include "DebugText.h"
#include "affin.h"

class Enemy {

public:
	/// <summary>
	/// ������
	/// <summary>
	void Initialize(Model* model, uint32_t textureHandle);

	/// <summary>
	/// �X�V
	/// <summary>
	void Move();

	/// <summary>
	/// �X�V
	/// <summary>
	void Update();

	/// <summary>
	/// �`��
	/// <summary>
	void Draw(ViewProjection& viewProjection_);

	/// <summary>
	/// �ڋ�
	/// <summary>
	void Approach();

	/// <summary>
	/// ���E
	/// <summary>
	void Leave();

	enum class Phase {
		Approach,//�ڋ߂���
		Leave,//���E����
	};

private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;
	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	//�t���O
	int back = 0;
	//�L�����N�^�[�̈ړ��̑���
	const float kEnemyCharacterSpeed = 0.2f;
	//�L�����N�^�[�̈ړ��x�N�g��
	Vector3 move = { kEnemyCharacterSpeed, 0, 0 };

	//�t�F�[�Y
	Phase phase_ = Phase::Approach;
	//�L�����N�^�[�̃t�F�[�Y�ړ��̑���
	const float kEnemyPhaseCharacterSpeed = 0.1f;
};