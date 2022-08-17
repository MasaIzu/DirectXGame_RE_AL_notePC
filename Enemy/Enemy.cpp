#include"Enemy.h"

void Enemy::Initialize(Model* model, uint32_t textureHandle) {
	//NULL�|�C���^�`�F�b�N
	assert(model);
	model_ = model;
	textureHandle_ = textureHandle;

	//�V���O���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//���[���h�ϊ��̏�����
	worldTransform_.Initialize();

	worldTransform_.translation_ += Vector3(0, 0, 10);

	//�s��X�V
	AffinTrans::affin(worldTransform_);

	worldTransform_.TransferMatrix();
}

void Enemy::Move() {

	const float kMoveLimitX = 35;
	const float kMoveLimitY = 18;

	//�͈͂𒴂��Ȃ�����

	if (worldTransform_.translation_.x <= -kMoveLimitX) {
		move = { kEnemyCharacterSpeed, 0, 0 };
	}
	if (worldTransform_.translation_.x >= kMoveLimitX) {
		move = { -kEnemyCharacterSpeed, 0, 0 };
	}

	worldTransform_.translation_ += move;
	//�s��X�V
	AffinTrans::affin(worldTransform_);
	worldTransform_.TransferMatrix();

	switch (phase_) {
	case Phase::Approach:
	default:
		Approach();
		break;
	case Phase::Leave:
		Leave();
		break;
	}


	debugText_->SetPos(50, 180);
	debugText_->Printf(
		"translation : %f,%f,%f", worldTransform_.translation_.x,
		worldTransform_.translation_.y,
		worldTransform_.translation_.z);

}

void Enemy::Update() {

	Move();

}

void Enemy::Draw(ViewProjection& viewProjection_) {
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
}

void Enemy::Approach(){
	//�ړ��x�N�g��
	worldTransform_.translation_ += Vector3(0, 0, -kEnemyPhaseCharacterSpeed);
	//����̈ʒu�ɓ��B�����痣�E
	if (worldTransform_.translation_.z < 0.0f) {
		phase_ = Phase::Leave;
	}
}

void Enemy::Leave(){
	//�ړ�(�x�N�g�������Z)
	worldTransform_.translation_ += Vector3(0, 0, +kEnemyPhaseCharacterSpeed);
}

