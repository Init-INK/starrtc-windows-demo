#pragma once

#include "ISuperRoomManagerListener.h"
#include "IChatroomGetListListener.h"
#include "CIMMessage.h"
#include "CSuperRoomManager.h"
#include <string>
using namespace std;
#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif

class MATH_API XHSuperRoomManager
{
public:
	XHSuperRoomManager(ISuperRoomManagerListener* pListener);
	virtual ~XHSuperRoomManager();
public:
	static void addChatroomGetListListener(IChatroomGetListListener* pChatroomGetListListener);
	static void getSuperRoomList(string strUserId, string listType);

	/**
	 * ����ý�����ͣ���Ƶ����Ƶ���Զ��򿪣�Ҳ���Ե�����һ����
	 * @param mediaTypeEnum 
	 */
	void setRtcMediaType(LIVE_MEDIA_TYPE mediaTypeEnum);

	/**
	 * ���������Խ�������
	 * @param chatroomType chatroom����
	 * @param channelType channelType����
	 */
	string createSuperRoom(string strName, int chatroomType, int channelType);

	/**
	 * ���볬��������
	 * @param roomID ֱ��ID
	 * @param callback ����ص�
	 */
	bool joinSuperRoom(string roomID);

	/**
	 *  ֹͣ����
	 *  @param callback ����ص�
	 */
	void layDownMic();

	/**
	 * ���뷢��
	 * @param callback ����ص�
	 */
	bool pickUpMic();

	/**
	 * �뿪������
	 * @param callback ����ص�
	 */
	void leaveSuperRoom();

	/**
	* ��������������
	* @param toID ������ID
	*/
	void commandToAudience(string toID);

	/**
	 * �л��ɴ�ͼ
	 * @param strUserID �л��ɴ�ͼ���û�ID
	 */
	bool changeToBig(string strUserID);

	/**
	 * �л���Сͼ
	 * @param userID �л���Сͼ���û�ID
	 */
	bool changeToSmall(string strUserID);

	/**
	* ��̬������Ƶ��ֱ�������п���ʱ������Ƶ��ֱ��������״̬�Զ����á�
	*/
	void setAudioEnable(bool enable);

	/**
	 * ��̬������Ƶ��ֱ�������п���ʱ������Ƶ��ֱ��������״̬�Զ����á�
	 */
	void setVideoEnable(bool enable);

	/**
	 * ���ͳ����Խ���Ϣ
	 * @param message ���͵���Ϣ����
	 * @param callback ����ص�
	 * @return ���ط��͵���Ϣ����
	 */
	CIMMessage* sendMessage(string strMessage);

	/**
	 * ���ͳ����Խ�˽����Ϣ
	 * ˽����Ϣֻ��Ŀ���û������յ�
	 * @param toID Ŀ���û�ID
	 * @param message ���͵���Ϣ����
	 * @return ���ط��͵���Ϣ����
	 */
	CIMMessage* sendPrivateMessage(string toID, string strMessage);

	/**
	 * �Ի����е�ĳ�˽���
	 * @param strSuperRoomId ����ID
	 * @param memberID ��������ID
	 * @param muteSeconds ����ʱ��
	 * @param callback ����ص�
	 */
	bool muteMember(string strSuperRoomId, string memberID, int muteSeconds);

	/**
	 * ��������Խ���ĳ�˵Ľ���
	 * @param meetingID ����ID
	 * @param memberID ��������ID
	 */
	bool unMuteMember(string strSuperRoomId, string memberID);

	/**
	 * �ӳ����Խ��߳��û�
	 * @param meetingID ����ID
	 * @param memberID ������ID
	 */
	bool kickMember(string strSuperRoomId, string memberID);

	/**
	 * ���浽�б�
	 * @param userId
	 * @param type
	 * @param meetingId
	 * @param data
	 */
	bool saveToList(string userId, int type, string meetingId, string data);

	/**
	 * ����RTMP��
	 * @param rtmpurl ���͵�ַ
	 */
	void pushRtmp(string rtmpurl);

	/**
	 * ֹͣ����RTMP��
	 */
	void stopPushRtmp();

	void insertAudioRaw(uint8_t* audioData, int dataLen);
	void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);
	void querySoundData(uint8_t** pData, int* nLength);
	void insertRealtimeData(uint8_t* realtimeData, int dataLen);

	/*
	 * ��ѯ��������
	 */
	bool getOnlineNumber(string strLiveId);
private:
	CSuperRoomManager* m_pSuperRoomManager;
};

