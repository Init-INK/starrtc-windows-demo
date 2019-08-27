#pragma once
#include "ISuperRoomManagerListener.h"
#include "CUserManager.h"
#include "CChatroomManager.h"
#include "ISrcManagerListener.h"
#include "IVdnManagerListener.h"
#include "CSrcManager.h"
#include "CVdnManager.h"
#include <map>
class CSuperRoomManager : public IChatroomManagerListener, public ISrcManagerListener, public IVdnManagerListener
{
public:
	CSuperRoomManager(CUserManager* pUserManager, ISuperRoomManagerListener* pListener);
	virtual ~CSuperRoomManager();
public:
	static void addChatroomGetListListener(IChatroomGetListListener* pChatroomGetListListener);
	static void getSuperRoomList(CUserManager* pUserManager, string strUserId, string listType);

	/**
	 * ����ý�����ͣ���Ƶ����Ƶ���Զ��򿪣�Ҳ���Ե�����һ����
	 * @param mediaTypeEnum
	 */
	void setRtcMediaType(int mediaTypeEnum);

	/**
	 * ����ֱ��
	 * @param superRoomItem XHSuperRoomItem ����ָ��ֱ�������ֺ�����
	 */
	bool createSuperRoom(string strName, int chatroomType, int channelType);

	/**
	 * ���볬��������
	 * @param roomID ֱ��ID
	 * @param callback ����ص�
	 */
	bool joinSuperRoom(string strChatRoomId, string strChannelId);

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
	bool muteMember(string strChatRoomId, string memberID, int muteSeconds);

	/**
	 * ���������ĳ�˵Ľ���
	 * @param meetingID ����ID
	 * @param memberID ��������ID
	 */
	bool unMuteMember(string strChatRoomId, string memberID);

	/**
	 * �ӻ������߳��û�
	 * @param meetingID ����ID
	 * @param memberID ������ID
	 */
	bool kickMember(string strChatRoomId, string memberID);

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
	bool saveToList(string strRoomId, int listType, string data);
	/**
	 * ���б�ɾ��
	 * @param userId �û�ID
	 * @param type ����
	 * @param strChatroomId chatRoom ID
	 */
	void deleteFromList(string userId, int type, string strChatroomId);

	bool closeChatroom();

	bool closeLive();

	bool close();
public:
	/**
	 * �����ҳ�Ա���仯
	 * @param number
	 */
	virtual void onMembersUpdated(int number);

	/**
	 * �Լ����߳�������
	 */
	virtual void onSelfKicked();

	/**
	 * �Լ�������
	 */
	virtual void onSelfMuted(int seconds);

	/**
	 * �������ѹر�
	 */
	virtual void onClosed();

	/**
	 * �յ���Ϣ
	 * @param message
	 */
	virtual void onReceivedMessage(CIMMessage* pMessage);

	/**
	 * �յ�˽����Ϣ
	 * @param message
	 */
	virtual void onReceivePrivateMessage(CIMMessage* pMessage);

public:
	//vdn
	virtual int uploaderAddVdn(char* upUserId, int upId);
	virtual int uploaderRemoveVdn(char* upUserId, int upId);
	virtual int getRealtimeDataVdn(int upId, uint8_t* data, int len);
	virtual int getVideoRawVdn(int upId, int w, int h, uint8_t* videoData, int videoDataLen);

	virtual int downloadChannelClosed();
	virtual int downloadChannelLeave();
	virtual int downloadNetworkUnnormal();
	virtual int queryVDNChannelOnlineNumberFin(char* channelId, int totalOnlineNum);

public:
	//src
	virtual int uploaderAddSrc(char* upUserId, int upId);
	virtual int uploaderRemoveSrc(char* upUserId, int upId);
	virtual int getRealtimeDataSrc(int upId, uint8_t* data, int len);
	virtual int getVideoRawSrc(int upId, int w, int h, uint8_t* videoData, int videoDataLen);

	virtual int deleteChannel(char* channelId);
	virtual int stopOK();
	virtual int srcError(char* errString);

public:
	ISuperRoomManagerListener* m_pListener;
	CUserManager* m_pUserManager;
	CChatroomManager* m_pChatroomManager;
	CSrcManager* m_pSrcManager;
	CVdnManager* m_pVdnManager;
	map<int, StarLiveUserInfo> m_StarLiveSrcUserInfo;
	map<int, StarLiveUserInfo> m_StarLiveVdnUserInfo;
};

