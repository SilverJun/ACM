//#pragma once
//template <typename T>
//class Singleton
//{
//private:
//	static auto_ptr<T> pSingleton; //static 맴버함수에서 참조가능하도록 정적선언
//
//public:
//	static GetInstance();        //반환값을 객체의 주소로 하여 인터페이스 함수를 통해 외부에서 데이터 조작을 가능하게함.
//	static void Destroy();
//};
//
//template <typename T>
//Singleton<T>::GetInstance()
//{
//	if (pSingleton == nullptr)        //싱글턴이므로 단 하나만 존재해야함
//	{
//		pSingleton = new Singleton<T>;
//		std::cout << "싱글턴 동적할당" << std::endl;
//	}
//	return pSingleton.get();
//}
//
//template <typename T>
//void Singleton<T>::Destroy()        //사용을 다 한 뒤 해제를 해주는 함수 필요
//{
//	if (pSingleton != nullptr)
//	{
//		delete pSingleton;
//		pSingleton = nullptr;
//	}
//}

#pragma once
template <typename T>
class Singleton
{
public:
	static T* GetInstance()
	{
		call_once(m_onceFlag, [] 
			{
				m_pInstance.reset(new T);
				std::cout <<"싱글턴 동적할당" << std::endl;
			}
		);
		return m_pInstance.get();
	}

private:
	static std::shared_ptr<T> Singleton<T>::m_pInstance;
	static std::once_flag m_onceFlag;
};

template <typename T> std::shared_ptr<T> Singleton<T>::m_pInstance = nullptr;

template <typename T> std::once_flag Singleton<T>::m_onceFlag;


//#pragma once
//template <class T>
//class Singleton
//{
//public:
//	static T *ms_pSingleton;
//
//public:
//	Singleton()
//	{
//		unsigned __int64 ulOffset = (unsigned __int64)((T*)(1)) - (unsigned __int64)((Singleton<T>*)(T*)1);
//
//		ms_pSingleton = (T*)((unsigned __int64)this + ulOffset);
//	}
//
//	virtual ~Singleton()
//	{
//		ms_pSingleton = 0;
//	}
//
//	static T* GetSingleton()
//	{
//		return(ms_pSingleton);
//	}
//};
//
//template <class T> T* Singleton<T>::ms_pSingleton = 0;
