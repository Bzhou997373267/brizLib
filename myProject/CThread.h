#ifdef WIN32
#include <windows.h>
typedef HANDLE THREAD_HANDLE;
#else
//#include <pthread.h>
typedef pthread_t THREAD_HANDLE;
#endif

/**������һ���̶߳���
*/
class  CThread
{
public:
	/**���캯��
	*/
	CThread();

	/**��������
	*/
	virtual ~CThread();

	/**����һ���߳�
	* @return true:�����ɹ� false:����ʧ��
	*/
	virtual bool Create();

	/**��ñ��̶߳���洢���߳̾��
	* @return ���̶߳���洢���߳̾���߳̾��
	*/
	THREAD_HANDLE GetHandle();

	/**�߳�˯�� seconds ��
	* @param seconds ˯������
	*/
	void OSSleep(int nSeconds);

	void SleepMs(int nMilliseconds);

	bool Join();

	bool IsCurrentThread();

	void ExitThread();

private:
#ifdef WIN32
	static DWORD WINAPI _ThreadEntry(LPVOID pParam);
#else
	static void* _ThreadEntry(void* pParam);
#endif

	/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
	virtual bool InitInstance();

	/**�麯�����������ʵ��
	*/
	virtual void ExitInstance();

	/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
	virtual void Run() = 0;

private:
	THREAD_HANDLE  m_hThread;  /**< �߳̾�� */
	DWORD          m_IDThread;

};

