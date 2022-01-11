#pragma once

#include <nori/mesh.h>

NORI_NAMESPACE_BEGIN

// ��Ҫ�ķ���: 1,�ݹ�build
// 2,���м��
// 3,���е���

struct BVHNode {
	int left;
	int right;                 // ��Ӧ�����е����
	BoundingBox3f m_bbox;
	Mesh const * mesh;         // ����BVH���� һ��ͼԪ��Ӧһ���ڵ�
};

class BVH
{
public:
	BVH();
	~BVH();
	void bulid();

private:
	std::vector<BVHNode> BVHTree;
};

inline BVH::BVH()
{
}

inline BVH::~BVH()
{
}
// ����
// ��ʼ��:����һ����ʼ�ڵ�
// �Գ�ʼ�ڵ���л���
// ��ڵ���� ���еݹ黮��
// �ҽڵ���ӽ��еݹ黮��

// ���ַ���:�������
inline void BVH::bulid(Mesh * mesh) {
	BVHNode root;
	root.m_bbox = mesh->getBoundingBox();
	root.left = -1;
	root.right = -1;
	root.mesh = mesh;

	recurseBuild(root);
	
}

inline void BVH::recurseBuild(BVHNode node) {
	for (m : node.mesh) {

	}
}

NORI_NAMESPACE_END