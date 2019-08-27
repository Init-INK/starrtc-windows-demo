#pragma once
class ILoginListener
{
public:
	/**
	 * msgServer����,������������̵߳���
	 */
	virtual int msgErr(char* errString) = 0;

	/**
	 * ���Զ�κ��Բ������ӵ�msgServer�����û���������stop��ص�
	 */
	virtual int stop() = 0;

	/**
	 * msgServer��������״̬
	 */
	virtual int online(int maxContentLen) = 0;

	/**
	 * msgServer�ж�״̬
	 */
	virtual int offline() = 0;
};
