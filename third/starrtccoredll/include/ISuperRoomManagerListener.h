#pragma once
#include "CIMMessage.h"
class ISuperRoomManagerListener
{
public:
	/**
	 * �����û��������
	 * @param meetingID ����ID
	 * @param userID �¼�����ID
	 */
	virtual void onJoined(string meetID, string userID) = 0;

	/**
	 * �����뿪����
	 * @param meetingID ����ID
	 * @param userID �뿪��ID
	 */
	virtual void onLeft(string meetingID, string userID) = 0;

	/**
	 * һЩ�쳣�������ĳ��������յ��ûص��������Ͽ�����
	 * @param id 
	 * @param error ������Ϣ
	 */
	virtual void onError(string id, string error) = 0;


	/**
	 * �����ҳ�Ա���仯
	 * @param number �仯��Ļ�������
	 */
	virtual void onMembersUpdated(int number) = 0;

	/**
	 * �Լ����߳�������
	 */
	virtual void onSelfKicked() = 0;

	/**
	 * �Լ�������
	 */
	virtual void onSelfMuted(int seconds) = 0;

	/**
	 * �����ߵ�����ǿ��ֹͣ
	 * @param liveID ֱ��ID
	 */
	virtual void onCommandToStopPlay(string liveID) = 0;

	/**
	 * �յ���Ϣ
	 * @param message
	 */
	virtual void onReceivedMessage(CIMMessage* pMessage) = 0;

	/**
	 * �յ�˽����Ϣ
	 * @param message
	 */
	virtual void onReceivePrivateMessage(CIMMessage* pMessage) = 0;
	virtual int getRealtimeData(string strUserId, uint8_t* data, int len) = 0;
	/**
	 * �յ���Ƶ����
	 * @param upId
	 * @param w ���
	 * @param h �߶�
	 * @param videoData ����
	 * @param videoDataLen ���ݳ���
	 */
	virtual int getVideoRaw(string strUserId, int w, int h, uint8_t* videoData, int videoDataLen) = 0;
};