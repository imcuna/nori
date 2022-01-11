#pragma once

#include <nori/mesh.h>

NORI_NAMESPACE_BEGIN

// ��Ҫ�ķ���: 1,�ݹ�build
// 2,���м��
// 3,���е���


// ���ݽṹ�޸�
// ��α��浱ǰ�ڵ������mesh?
// �½�һ��Mesh̫����
// 1,��mesh��������(�������ƿ��ŵĲ��� ֻ��Ҫ�ҵ���λ�� Ȼ��� ����С/��ķ�����/�ұ߾����� )
// 2,����ÿ�ε�begin and end ��ȷ����ǰ��Χ�ж�Ӧ��meshes
// ����һ�� ��Ҫ����ľ��ǵ�ǰmesh��Ӧ��BBox
// 
// ���ڻ��м��:
// node����Ҫ����: ��ǰbBox,��ڵ��ڶ����е�λ��,�ҽڵ��ڶ����е�λ�� �����Ҷ�ڵ� ��ôӦ�û�Ҫ���浱ǰ�ڵ������������
// ���м�����ڷ�Ҷ�ڵ�ʱ ����Ҫ��ǰbbox mesh��Ϣ!!!!!
struct BVHNode {
	int left;
	int right;                 // ��Ӧ�����е����
	BoundingBox3f m_bbox;
	int meshIdx;         // ����BVH���� һ��ͼԪ��Ӧһ���ڵ�
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
// 1,�ҵ������
// 2,
inline void BVH::recurseBuild(BVHNode node) {
	auto nodeBox = node.mesh->getBoundingBox();
	int longestAxis = nodeBox.getLargestAxis();
	auto bboxCenter = nodeBox.getCenter();

	Mesh leftMesh = Mesh();
	Mesh rightMesh = Mesh();
	for (uint32_t idx = 0; idx < node.mesh->getTriangleCount(); ++idx) {
		auto curBbox = node.mesh->getBoundingBox(idx);
		if (bboxCenter[longestAxis] <= curBbox.getCenter()[longestAxis]) {
			leftMesh.addChild()
		}
		
	}
}

NORI_NAMESPACE_END