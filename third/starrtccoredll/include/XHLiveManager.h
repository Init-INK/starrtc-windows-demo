#pragma once
#include "CLiveManager.h"
#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif



class MATH_API XHLiveManager
{
public:
	XHLiveManager(ILiveManagerListener* pLiveListener);
	virtual ~XHLiveManager();
	static void addChatroomGetListListener(IChatroomGetListListener* pChatroomGetListListener);
	static void getLiveList(string strUserId, string listType);


	/**
	 * ����ý�����ͣ���Ƶ����Ƶ���Զ��򿪣�Ҳ���Ե�����һ����
	 * @param mediaTypeEnum 
	 */
	void setRtcMediaType(LIVE_MEDIA_TYPE mediaTypeEnum);

	/**
	 * ����ֱ��
	 */
	string createLive(string strName, int chatroomType, int channelType);

	/**
	 * ������ʼֱ��
	 * @param liveID ֱ��ID
	 */
	bool startLive(string liveID);

	/**
	 * ���ڹۿ�ֱ��
	 * @param liveID ֱ��ID
	 */
	bool watchLive(string liveID);

	/**
	 * ������������
	 * @param toID ������ID
	 */
	void applyToBroadcaster(string toID);

	/**
	 * ����ͬ������
	 * @param toID ���������ߵ�ID
	 */
	void agreeApplyToBroadcaster(string toID);

	/**
	 * �����ܾ�����
	 * @param toID ���������ߵ�ID
	 */
	void refuseApplyToBroadcaster(string toID);

	/**
	 * ������Ո����
	 * @param toID �������˵�ID
	 */
	void inviteToBroadcaster(string toID);

	/**
	 * ����ͬ������
	 * @param toID ������ID
	 */
	void agreeInviteToBroadcaster(string toID);

	/**
	 * ���ھܾ�����
	 * @param toID ������ID
	 */
	void refuseInviteToBroadcaster(string toID);

	/**
	 * ��������������
	 * @param toID ������ID
	 */
	void commandToAudience(string toID);

	/**
	 * �뿪ֱ��
	 * @param callback ����ص�
	 */
	void leaveLive();

	/**
	 * �л��ɴ�ͼ
	 * @param userID �л��ɴ�ͼ������ID
	 */
	void changeToBig(string userID);

	/**
	 * �л���Сͼ
	 * @param userID �л���Сͼ������ID
	 */
	void changeToSmall(string userID);

	/**
	 * ��̬������Ƶ��ֱ�������п���ʱ������Ƶ��ֱ��������״̬�Զ����á�
	 */
	void setAudioEnable(bool bEnable);

	/**
	 * ��̬������Ƶ��ֱ�������п���ʱ������Ƶ��ֱ��������״̬�Զ����á�
	 */
	void setVideoEnable(bool bEnable);

	/**
	 * ���ͻ�����Ϣ
	 * @param message ���͵���Ϣ����
	 * @param callback ����ص�
	 * @return ���ط��͵���Ϣ����
	 */
	CIMMessage* sendMessage(string strMessage);

	/**
	 * ���ͻ���˽����Ϣ
	 * ˽����Ϣֻ��Ŀ���û������յ�
	 * @param toID Ŀ���û�ID
	 * @param message ���͵���Ϣ����
	 * @return ���ط��͵���Ϣ����
	 */
	CIMMessage* sendPrivateMessage(string toID, string strMessage);

	/**
	 * �Ի����е�ĳ�˽���
	 * @param meetingID ����ID
	 * @param memberID ��������ID
	 * @param muteSeconds ����ʱ��
	 * @param callback ����ص�
	 */
	bool muteMember(string liveId, string memberID, int muteSeconds);

	/**
	 * ���������ĳ�˵Ľ���
	 * @param meetingID ����ID
	 * @param memberID ��������ID
	 */
	bool unMuteMember(string liveId, string memberID);

	/**
	 * �ӻ������߳��û�
	 * @param meetingID ����ID
	 * @param memberID ������ID
	 */
	bool kickMember(string liveId, string memberID);

	/**
	 * ���浽�б�
	 * @param userId
	 * @param type
	 * @param liveId
	 * @param data
	 */
	bool saveToList(string userId, int type, string liveId, string data);

	/**
	 * ���б�ɾ��
	 * @param userId �û�ID
	 * @param type ����
	 * @param liveId liveID
	 */
	void deleteFromList(string userId, int type, string liveId);

	/**
	 * ����RTMP��
	 * @param rtmpurl ���͵�ַ
	 */
	void pushRtmp(string rtmpurl);

	/**
	 * ֹͣ����RTMP��
	 */
	void stopPushRtmp();

	/*
	 * ��ѯ��������
	 */
	bool getOnlineNumber(string strLiveId);

	void insertAudioRaw(uint8_t* audioData, int dataLen);
	void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);
	void querySoundData(uint8_t** pData, int* nLength);
	void insertRealtimeData(uint8_t* realtimeData, int dataLen);
private:
	CLiveManager* m_pLiveManager;
};

