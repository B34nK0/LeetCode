//���������򷽡�������������������
struct OrderBook {
	Limit* buyTree;
	Limit* sellTree;
	Limit* lowestSell;
	Limit* highestBuy;
};

//�������ڵ��¼��ǰ�۸�λ�Լ���������
//�ڵ��ϼ�¼��ǰ��λ�Ķ������У�ʱ�����ȣ�
struct Limit {
	int limitPrice;
	int size;
	Limit* parent;
	Limit* leftChild;
	Limit* rightChild;
	Order* headOrder;
	Order* tailOrder;
};

//����ֻ��Ψһ��ʶid�����׷����������۸�
//�����б�ʽ�洢����
//
struct Order {
	int orderId;
	bool buyOrSell;
	int num;
	int limitPrice;
	Order* nextOrder;
	Order* prevOrder;
	Limit* parentLimit;
};